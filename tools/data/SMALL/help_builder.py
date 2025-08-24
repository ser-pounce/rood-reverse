#!/usr/bin/env python3
"""
Help File Builder

Creates HF0 and HF1 files from:
1. YAML containing text content, sprite positions and animations
2. PNG files containing the actual sprite images

This is the reverse of help_dumper.py.
"""

import os
import struct
import sys
import yaml
import logging
import png
from pathlib import Path
from typing import Dict, List, Tuple, Any
from tools.etc.vsString import encode

logger = logging.getLogger(__name__)

def init_logging(debug: bool = False) -> None:
    """Initialize logging with appropriate level and format."""
    level = logging.DEBUG if debug else logging.WARNING
    logging.basicConfig(
        level=level,
        format='%(message)s'  # Keep it clean for build output
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
    
    def __init__(self, indices: List[List[int]], palette: List[Tuple[int, int, int, int]]):
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

# YAML to Binary conversion

def get_default_animation() -> Dict[str, Any]:
    """Return default animation data structure."""
    return {
        "enabled": 0,
        "frameMask": "0000000000000000",
        "frameDuration": 0,
        "repeat": 0,
        "currentFrame": 0,
        "timer": 0,
        "isActive": 0
    }

def pack_animation(animation_data: Dict[str, Any]) -> bytes:
    """Pack animation data into binary format."""
    state_bits = int(animation_data["frameMask"], 2)
    return struct.pack("<hHhhhhhxx",
                       animation_data["enabled"],
                       state_bits,
                       animation_data["frameDuration"],
                       animation_data["repeat"],
                       animation_data["currentFrame"],
                       animation_data["timer"],
                       animation_data["isActive"])

def pack_sprite(sprite_data: Dict[str, Any]) -> bytes:
    """Pack sprite metadata into binary format."""
    data = bytearray()
    
    # Pack animation data
    animation = sprite_data.get("animation", get_default_animation())
    data.extend(pack_animation(animation))
    
    # Pack sprite metadata
    clut_packed = (sprite_data["clutY"] * 16) | (sprite_data["clutX"])
    count = len(sprite_data["sprites"])
    
    data.extend(struct.pack("<hhhhhhh",
                           sprite_data["x"],
                           sprite_data["y"],
                           sprite_data["w"],
                           sprite_data["h"],
                           count,
                           256,  # colors - always 256 for indexed PNGs
                           clut_packed))
    
    # Pack sprite references
    texUV = sprite_data["sprites"]
    data.extend(struct.pack("<" + "h" * len(texUV), *texUV))
    
    return bytes(data)

def pack_line(line_data: Dict[str, Any]) -> bytes:
    """Pack line data into binary format."""
    data = bytearray()
    
    animation = line_data.get("animation", get_default_animation())
    data.extend(pack_animation(animation))
    
    data.extend(struct.pack("<hhhh",
                           line_data["x0"],
                           line_data["y0"],
                           line_data["x1"],
                           line_data["y1"]))
    
    color = line_data["color"]
    data.extend(struct.pack("<BBBx",
                           color["r"],
                           color["g"],
                           color["b"]))
    
    return bytes(data)

def align_to_4_bytes(data: bytes) -> bytes:
    """Align data to 4-byte boundary by adding padding."""
    padding_needed = (4 - (len(data) % 4)) % 4
    return data + b'\x00' * padding_needed

def build_strings_block(strings: List[str]) -> bytes:
    """Build strings block in binary format."""
    data = bytearray()
    
    num_strings = len(strings)
    data.extend(struct.pack("<H", num_strings))
    
    string_data = bytearray()
    offsets = []
    
    for string in strings:
        encoded_string = encode(string, padding=0x00)
        offsets.append(len(string_data))
        string_data.extend(encoded_string)
    
    header_size = 2 + (num_strings * 2)
    
    for offset in offsets:
        adjusted_offset = (header_size + offset) // 2
        data.extend(struct.pack("<H", adjusted_offset))
    
    data.extend(string_data)
    
    return align_to_4_bytes(bytes(data))

def build_sprites_block(sprites: List[Dict[str, Any]]) -> bytes:
    """Build sprites block in binary format."""
    data = bytearray()
    
    num_sprites = len(sprites)
    data.extend(struct.pack("<H", num_sprites))
    
    sprite_data = bytearray()
    offsets = []
    
    for sprite in sprites:
        offsets.append(len(sprite_data))
        sprite_data.extend(pack_sprite(sprite))
    
    header_size = 2 + (num_sprites * 2)
    
    for offset in offsets:
        adjusted_offset = (header_size + offset) // 2
        data.extend(struct.pack("<H", adjusted_offset))
    
    data.extend(sprite_data)
    
    return align_to_4_bytes(bytes(data))

def build_lines_block(lines: List[Dict[str, Any]]) -> bytes:
    """Build lines block in binary format."""
    data = bytearray()
    
    num_lines = len(lines)
    data.extend(struct.pack("<H", num_lines))
    
    for line in lines:
        data.extend(pack_line(line))
    
    return align_to_4_bytes(bytes(data))

class HelpBuilder:
    """Main class for building HF0 and HF1 files."""
    
    def __init__(self, yaml_path: Path, output_dir: Path):
        self.yaml_path = yaml_path
        self.output_dir = output_dir
        self.sprites_dir = yaml_path.parent
        # Extract HELP## from parent directory name (handles test_HELP01, HELP01, etc.)
        self.help_name = next((part for part in yaml_path.parent.name.split('_') if part.startswith("HELP")), "")
        if not self.help_name:
            raise ValueError(f"Could not find HELP name in path: {yaml_path}")
        self.palette_manager = PaletteManager()
        self.block_extractor = BlockExtractor()
        self.sprite_blocks = []
        self.processed_sprites = {}  # Maps PNG file to processed data
    
    def build(self) -> None:
        """Build HF0 and HF1 files from YAML and PNG files."""
        # Load YAML data
        with open(self.yaml_path, "r", encoding="utf-8") as f:
            self.yaml_data = yaml.safe_load(f)
        
        # Process sprites first to build HF1 data
        self._process_sprites()
        
        # Build and write HF0 file
        self._write_hf0_file()
        
        # Build and write HF1 file
        self._write_hf1_file()
    
    def _process_sprites(self) -> None:
        """Process all sprite PNG files referenced in YAML."""
        logger.debug("=== PROCESSING SPRITES ===")
        
        # Keep track of processed PNGs to avoid duplicates
        processed_pngs = set()
        
        for sprite in self.yaml_data["sprites"]:
            png_file = sprite.get("file")
            if not png_file:
                continue
            
            if png_file not in processed_pngs:
                png_path = self.sprites_dir / png_file
                logger.debug(f"\nProcessing {png_file}")
                
                # Load and process PNG
                image_data = self._load_png(png_path)
                
                # Extract blocks
                block_indices = self.block_extractor.extract_blocks(image_data)
                
                # Add palette
                clut_y = self.palette_manager.add_palette(image_data.palette)
                
                # Store processed data
                self.processed_sprites[png_file] = {
                    "w": image_data.width,
                    "h": image_data.height,
                    "sprites": block_indices,
                    "clutX": 0,  # We maintain palette offset of 0 for simplicity
                    "clutY": clut_y
                }
                
                processed_pngs.add(png_file)
    
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
    
    def _write_hf0_file(self) -> None:
        """Write HF0 file with text, layout and sprite metadata."""
        logger.debug("\n=== WRITING HF0 FILE ===")
        
        # Create expanded sprite data for HF0
        expanded_sprites = []
        for sprite in self.yaml_data["sprites"]:
            png_data = self.processed_sprites[sprite["file"]]
            expanded_sprite = {
                "x": sprite["x"],
                "y": sprite["y"],
                "w": png_data["w"],
                "h": png_data["h"],
                "sprites": png_data["sprites"],
                "clutX": png_data["clutX"],
                "clutY": png_data["clutY"]
            }
            if "animation" in sprite:
                expanded_sprite["animation"] = sprite["animation"]
            expanded_sprites.append(expanded_sprite)
        
        output_path = self.output_dir / f"{self.help_name}.HF0"
        
        try:
            # Build blocks
            strings_block = build_strings_block(self.yaml_data["strings"])
            sprites_block = build_sprites_block(expanded_sprites)
            lines_block = build_lines_block(self.yaml_data["lines"])
            empty_block = b''
            
            blocks = [strings_block, sprites_block, lines_block, empty_block]
            block_sizes = [len(block) for block in blocks]
            
            # Write file
            with open(output_path, "wb") as f:
                f.write(struct.pack("<IIII", *block_sizes))
                for block in blocks:
                    f.write(block)
            
            logger.debug(f"HF0 file written to: {output_path}")
            
        except Exception as e:
            logger.error(f"Error writing HF0 file: {e}")
            raise
    
    def _write_hf1_file(self) -> None:
        """Write HF1 file with sprite image data."""
        logger.debug("\n=== WRITING HF1 FILE ===")
        
        output_path = self.output_dir / f"{self.help_name}.HF1"
        
        try:
            # Calculate sizes
            num_unique_blocks = len(self.block_extractor.unique_blocks)
            num_palettes = len(self.palette_manager.unique_palettes)
            num_clut_chunks = num_palettes * 16  # Each CLUT is 16 chunks
            
            logger.debug(f"Total unique blocks: {num_unique_blocks}")
            logger.debug(f"Total palettes: {num_palettes}")
            logger.debug(f"Total CLUT chunks: {num_clut_chunks}")
            
            # Write file
            with open(output_path, "wb") as f:
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
            
            logger.debug(f"HF1 file written to: {output_path}")
            
        except Exception as e:
            logger.error(f"Error writing HF1 file: {e}")
            raise

def main() -> None:
    """Command-line entry point."""
    import argparse
    
    parser = argparse.ArgumentParser(
        description="Build HF0 and HF1 files from YAML and PNG files"
    )
    parser.add_argument(
        "yaml_file",
        type=Path,
        help="Input YAML file containing help data"
    )
    parser.add_argument(
        "output_dir",
        type=Path,
        help="Output directory for HF0 and HF1 files"
    )
    parser.add_argument(
        "--debug",
        action="store_true",
        help="Enable debug output"
    )
    
    args = parser.parse_args()
    
    try:
        # Set up logging
        init_logging(args.debug)
        
        # Create output directory
        args.output_dir.mkdir(parents=True, exist_ok=True)
        
        # Build help files
        builder = HelpBuilder(args.yaml_file, args.output_dir)
        builder.build()
        
    except Exception as e:
        logger.error(f"Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
