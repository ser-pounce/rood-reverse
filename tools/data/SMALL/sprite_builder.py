#!/usr/bin/env python3
"""
Sprite Builder Tool

Creates binary framebuffer data from a sequence of indexed PNG images.
Converts images back to the PlayStation's native BGR1555 format.
"""

import os
import struct
import sys
import logging
from pathlib import Path
from typing import List, Tuple, Set, Dict, Any
import png

logger = logging.getLogger(__name__)

def init_logging(debug: bool = False) -> None:
    """Initialize logging with appropriate level and format."""
    level = logging.DEBUG if debug else logging.WARNING
    logging.basicConfig(
        level=level,
        format='%(message)s',  # Keep it clean for build output
    )


class Color:
    """Utility class for color format conversions."""
    
    @staticmethod
    def rgba8888_to_bgr1555(r: int, g: int, b: int, a: int) -> int:
        """Convert RGBA8888 format to BGR1555, handling PlayStation transparency."""
        # Convert 8-bit to 5-bit color values
        r5 = (r >> 3) & 0x1F
        g5 = (g >> 3) & 0x1F
        b5 = (b >> 3) & 0x1F
        
        # If pixel is fully transparent (a = 0), return 0x0000
        if a == 0:
            return 0x0000
        
        # Combine components into BGR1555 format
        # Format: 0BBBBBGGGGGRRRRR
        return (b5 << 10) | (g5 << 5) | r5


class ImageData:
    """Container for parsed PNG image data."""
    
    def __init__(self, indices: List[int], palette: List[Tuple[int, int, int, int]]):
        self.indices = indices
        self.palette = palette
        
    @property
    def width(self) -> int:
        return len(self.indices[0]) if self.indices else 0
        
    @property
    def height(self) -> int:
        return len(self.indices)


class BlockExtractor:
    """Extracts and manages 8x16 pixel blocks from image data."""
    
    BLOCK_WIDTH = 8
    BLOCK_HEIGHT = 16
    
    def __init__(self):
        self.unique_blocks = []  # List of unique blocks
        self.block_map = {}  # Maps block signature to index
    
    def extract_blocks(self, image_data: ImageData) -> List[int]:
        """Extract blocks from image data and return their indices."""
        block_indices = []
        
        for start_y in range(0, image_data.height, self.BLOCK_HEIGHT):
            for start_x in range(0, image_data.width, self.BLOCK_WIDTH):
                block = []
                
                # Extract block pixels
                for y in range(self.BLOCK_HEIGHT):
                    for x in range(self.BLOCK_WIDTH):
                        img_x = start_x + x
                        img_y = start_y + y
                        
                        # If we're beyond image bounds, pad with 0
                        if img_y >= image_data.height or img_x >= image_data.width:
                            block.append(0)
                        else:
                            block.append(image_data.indices[img_y][img_x])
                
                # Get or create block index
                block_index = self._add_block(block)
                block_indices.append(block_index)
        
        return block_indices
    
    def _add_block(self, block: List[int]) -> int:
        """Add a block and return its index, reusing existing blocks if possible."""
        block_signature = tuple(block)
        
        # Check if we've seen this block before
        if block_signature in self.block_map:
            return self.block_map[block_signature]
        
        # Add new block
        block_index = len(self.unique_blocks)
        self.unique_blocks.append(block)
        self.block_map[block_signature] = block_index
        
        return block_index


class PaletteManager:
    """Manages palette conversion and deduplication."""
    
    def __init__(self):
        self.unique_palettes = []  # List of BGR1555 format palettes
        self.palette_map = {}  # Maps palette signature to index
    
    def add_palette(self, rgba_palette: List[Tuple[int, int, int, int]]) -> int:
        """Convert and add a palette, returning its index."""
        # Convert to BGR1555 format
        bgr_palette = [
            Color.rgba8888_to_bgr1555(r, g, b, a)
            for r, g, b, a in rgba_palette
        ]
        
        # Create palette signature for deduplication
        palette_signature = tuple(bgr_palette)
        
        # Check if we've seen this palette before
        if palette_signature in self.palette_map:
            return self.palette_map[palette_signature]
        
        # Add new palette
        palette_index = len(self.unique_palettes)
        self.unique_palettes.append(bgr_palette)
        self.palette_map[palette_signature] = palette_index
        
        return palette_index


class SpriteBuilder:
    """Main sprite building orchestrator."""
    
    def __init__(self, input_dir: Path, output_path: Path):
        self.input_dir = input_dir
        self.output_path = output_path
        self.palette_manager = PaletteManager()
        self.block_extractor = BlockExtractor()
        self.sprite_blocks = []  # List of block indices for each sprite
    
    def build_sprite_data(self) -> None:
        """Process all sprites and build binary data."""
        # Get sorted list of PNG files
        png_files = sorted(
            [f for f in self.input_dir.iterdir() if f.suffix.lower() == '.png'],
            key=lambda f: int(f.stem)
        ) if self.input_dir.exists() else []
        
        if png_files:
            self._process_sprites(png_files)
            self._write_binary()  # Write the processed data
        else:
            self._write_empty_file()
        
    def _write_empty_file(self) -> None:
        """Create an empty but valid sprite file with just a header."""
        logger.debug("Creating empty sprite file (no sprites/CLUTs)")
        
        with open(self.output_path, "wb") as f:
            # Write header with 0 blocks and 0 CLUT chunks
            f.write(struct.pack("<I", 0))  # No blocks
            f.write(struct.pack("<I", 0))  # No CLUT chunks
            
        logger.debug(f"Empty file written to: {self.output_path}")
        logger.debug(f"File size: {self.output_path.stat().st_size} bytes")
        
    def _process_sprites(self, png_files: List[Path]) -> None:
        """Process all sprites in sequence."""
        logger.debug("=== SPRITE PROCESSING ===")
        logger.debug(f"Found {len(png_files)} PNG files")
        
        # Process each sprite
        for png_file in png_files:
            logger.debug(f"\nProcessing {png_file.name}")
            image_data = self._load_png(png_file)
            
            # Extract blocks
            block_indices = self.block_extractor.extract_blocks(image_data)
            self.sprite_blocks.append(block_indices)
            
            # Add palette
            palette_index = self.palette_manager.add_palette(image_data.palette)
            logger.debug(f"- Dimensions: {image_data.width}x{image_data.height}")
            logger.debug(f"- Blocks extracted: {len(block_indices)}")
            logger.debug(f"- Using palette index: {palette_index}")
            logger.debug(f"- Block indices: {block_indices}")
    
    def _load_png(self, file_path: Path) -> ImageData:
        """Load and parse PNG file."""
        with open(file_path, "rb") as f:
            reader = png.Reader(file=f)
            w, h, pixels, meta = reader.read()
            
            if not meta.get('palette'):
                raise ValueError(f"{file_path}: Not an indexed PNG file")
            
            # Get palette and pixel data
            palette = meta['palette']
            pixel_rows = list(pixels)
            
            return ImageData(pixel_rows, palette)
    
    def _write_binary(self) -> None:
        """Write binary data in the required format."""
        logger.debug("\n=== BINARY OUTPUT ===")
        
        # Calculate sizes
        num_unique_blocks = len(self.block_extractor.unique_blocks)
        num_palettes = len(self.palette_manager.unique_palettes)
        num_clut_chunks = num_palettes * 16  # Each CLUT is 16 chunks
        
        logger.debug(f"Total unique blocks: {num_unique_blocks}")
        logger.debug(f"Total block references: {sum(len(blocks) for blocks in self.sprite_blocks)}")
        logger.debug(f"Total palettes: {num_palettes}")
        logger.debug(f"Total CLUT chunks: {num_clut_chunks}")
        
        # Create binary data
        with open(self.output_path, "wb") as f:
            # Write header
            f.write(struct.pack("<I", num_unique_blocks))
            f.write(struct.pack("<I", num_clut_chunks))
            
            # Write blocks
            for block in self.block_extractor.unique_blocks:
                f.write(bytes(block))
            
            # Write CLUTs
            for palette in self.palette_manager.unique_palettes:
                # Ensure palette has exactly 256 entries
                palette = list(palette)
                if len(palette) > 256:
                    palette = palette[:256]
                elif len(palette) < 256:
                    palette.extend([0] * (256 - len(palette)))
                
                # Write palette entries
                for color in palette:
                    f.write(struct.pack("<H", color))
        
        logger.debug(f"\nBinary file written to: {self.output_path}")
        logger.debug(f"File size: {self.output_path.stat().st_size} bytes")


def build_sprites(input_dir: Path, output_path: Path, debug: bool = False) -> None:
    """Build sprites from input directory and write to output path.
    
    Args:
        input_dir: Directory containing numbered PNG files
        output_path: Path to write the binary sprite data
        debug: Enable debug logging if True
    
    Raises:
        ValueError: If input directory doesn't exist or output path is invalid
    """
    init_logging(debug)
    
    if not input_dir.is_dir():
        raise ValueError(f"Input directory not found: {input_dir}")
    
    builder = SpriteBuilder(input_dir, output_path)
    builder.build_sprite_data()


def main() -> None:
    """Command-line entry point."""
    import argparse
    
    parser = argparse.ArgumentParser(description="Build sprite data from PNG files")
    parser.add_argument("input_dir", type=Path, help="Directory containing numbered PNG files")
    parser.add_argument("output_file", type=Path, help="Output binary file path")
    parser.add_argument("--debug", action="store_true", help="Enable debug output")
    
    args = parser.parse_args()
    
    try:
        build_sprites(args.input_dir, args.output_file, args.debug)
    except Exception as e:
        logger.error(f"Error during build: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()
