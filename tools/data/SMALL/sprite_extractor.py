#!/usr/bin/env python3
"""
Sprite Extractor Tool

Extracts sprites from binary framebuffer data and converts them to indexed PNG images.
Supports BGR1555 color format conversion and YAML-based sprite definitions.
"""

import os
import struct
import sys
import logging
from pathlib import Path
from typing import List, Tuple, Set, Dict, Any
import yaml
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
    def bgr1555_to_rgba8888(color16: int) -> Tuple[int, int, int, int]:
        """Convert BGR1555 format to RGBA8888, handling PlayStation transparency."""
        # Extract color components
        b = (color16 >> 10) & 0x1F
        g = (color16 >> 5) & 0x1F
        r = (color16 >> 0) & 0x1F
        
        # Convert 5-bit to 8-bit color values
        r8 = r << 3
        g8 = g << 3
        b8 = b << 3
        
        # Handle transparency according to PlayStation rules
        # When pixel value is 0x0000 (STP=0, R=0, G=0, B=0), it's transparent
        if color16 == 0x0000:
            alpha = 0  # Fully transparent
        else:
            alpha = 255  # Opaque (assuming non-transparent primitives)
        
        return (r8, g8, b8, alpha)


class FramebufferData:
    """Container for parsed framebuffer data."""
    
    def __init__(self, blocks: List[List[int]], cluts: List[List[Tuple[int, int, int, int]]]):
        self.blocks = blocks
        self.cluts = cluts  # RGBA palettes with transparency
    
    @property
    def num_blocks(self) -> int:
        return len(self.blocks)
    
    @property
    def num_cluts(self) -> int:
        return len(self.cluts)


class SpriteConfig:
    """Configuration for a single sprite."""
    
    def __init__(self, sprite_data: Dict[str, Any]):
        self.width = sprite_data["w"]
        self.height = sprite_data["h"]
        self.clut_x = sprite_data["clutX"]
        self.clut_y = sprite_data["clutY"]
        self.block_ids = sprite_data["sprites"]
    
    @property
    def signature(self) -> Tuple:
        """Create a unique signature for deduplication."""
        return (
            tuple(self.block_ids),
            self.width,
            self.height,
            self.clut_x,
            self.clut_y,
        )


class FramebufferParser:
    """Parser for binary framebuffer data."""
    
    BLOCK_SIZE = 128  # bytes
    BLOCK_DIMENSIONS = (8, 16)  # width, height in pixels
    CLUT_SIZE = 512  # bytes (256 entries * 2 bytes each)
    CLUT_ENTRIES = 256
    
    @classmethod
    def parse(cls, data: bytes) -> FramebufferData:
        """Parse blocks and CLUTs from binary data."""
        if len(data) < 8:
            raise ValueError("Invalid data: too short for header")
        
        num_blocks = struct.unpack_from("<I", data, 0)[0]
        num_clut_chunks = struct.unpack_from("<I", data, 4)[0]
        
        blocks = cls._extract_blocks(data, num_blocks)
        cluts = cls._extract_cluts(data, num_blocks, num_clut_chunks)
        
        return FramebufferData(blocks, cluts)
    
    @classmethod
    def _extract_blocks(cls, data: bytes, num_blocks: int) -> List[List[int]]:
        """Extract sprite blocks from binary data."""
        blocks = []
        for i in range(num_blocks):
            start = 8 + i * cls.BLOCK_SIZE
            end = start + cls.BLOCK_SIZE
            if end > len(data):
                raise ValueError(f"Block {i} extends beyond data boundary")
            blocks.append(list(data[start:end]))
        return blocks
    
    @classmethod
    def _extract_cluts(cls, data: bytes, num_blocks: int, num_clut_chunks: int) -> List[List[Tuple[int, int, int, int]]]:
        """Extract and convert CLUTs from binary data to RGBA palettes."""
        num_cluts = num_clut_chunks // 16
        cluts = []
        
        for i in range(num_cluts):
            start = 8 + num_blocks * cls.BLOCK_SIZE + i * cls.CLUT_SIZE
            end = start + cls.CLUT_SIZE
            if end > len(data):
                raise ValueError(f"CLUT {i} extends beyond data boundary")
            
            clut_bytes = data[start:end]
            clut16 = list(struct.unpack_from(f"<{cls.CLUT_ENTRIES}H", clut_bytes, 0))
            
            # Convert BGR1555 to RGBA8888 palette with transparency
            palette = [Color.bgr1555_to_rgba8888(color16) for color16 in clut16]
            cluts.append(palette)
        
        return cluts


class SpriteRenderer:
    """Renders sprites to PNG images."""
    
    def __init__(self, framebuffer_data: FramebufferData):
        self.framebuffer_data = framebuffer_data
    
    def render_sprite(self, sprite_config: SpriteConfig, output_path: Path) -> None:
        """Render a single sprite to an indexed PNG file."""
        pixel_data = self._generate_pixel_data(sprite_config)
        palette = self.framebuffer_data.cluts[sprite_config.clut_y]
        
        # Convert to row format for pypng
        rows = [
            pixel_data[y * sprite_config.width:(y + 1) * sprite_config.width]
            for y in range(sprite_config.height)
        ]
        
        # Write indexed PNG with transparency support
        output_path.parent.mkdir(parents=True, exist_ok=True)
        with open(output_path, "wb") as f:
            png.Writer(
                width=sprite_config.width,
                height=sprite_config.height,
                palette=palette
            ).write(f, rows)
        
        logger.debug(f"Rendered sprite: {output_path}")
    
    def _generate_pixel_data(self, sprite_config: SpriteConfig) -> List[int]:
        """Generate pixel index data for the sprite."""
        block_w, block_h = FramebufferParser.BLOCK_DIMENSIONS
        blocks_per_row = (sprite_config.width + block_w - 1) // block_w
        
        # Initialize pixel data
        pixel_data = [0] * (sprite_config.width * sprite_config.height)
        
        # Process each block
        for block_idx, block_id in enumerate(sprite_config.block_ids):
            if block_id >= len(self.framebuffer_data.blocks):
                raise ValueError(f"Block ID {block_id} out of range")
            
            block = self.framebuffer_data.blocks[block_id]
            
            # Calculate block position in sprite
            grid_x = (block_idx % blocks_per_row) * block_w
            grid_y = (block_idx // blocks_per_row) * block_h
            
            # Copy block pixels to sprite
            for y in range(block_h):
                for x in range(block_w):
                    dst_x, dst_y = grid_x + x, grid_y + y
                    if dst_x >= sprite_config.width or dst_y >= sprite_config.height:
                        continue
                    
                    pixel_index = block[y * block_w + x]
                    color_index = (pixel_index + sprite_config.clut_x) % 256
                    pixel_data[dst_y * sprite_config.width + dst_x] = color_index
        
        return pixel_data


class SpriteExtractor:
    """Main sprite extraction orchestrator."""
    
    def __init__(self, binary_path: Path, yaml_path: Path, output_dir: Path):
        self.binary_path = binary_path
        self.yaml_path = yaml_path
        self.output_dir = output_dir
        self.framebuffer_data = None
        self.sprite_configs = []
    
    def extract_sprites(self) -> None:
        """Extract all sprites from the input files."""
        self._load_data()
        self._analyze_reconstruction_data()
        self._extract_unique_sprites()
    
    def _load_data(self) -> None:
        """Load and parse input data."""
        with open(self.binary_path, "rb") as f:
            binary_data = f.read()
        
        with open(self.yaml_path, "r", encoding="utf-8") as f:
            yaml_data = yaml.safe_load(f)
        
        self.framebuffer_data = FramebufferParser.parse(binary_data)
        self.sprite_configs = [
            SpriteConfig(sprite_data) for sprite_data in yaml_data["sprites"]
        ]
    
    def _analyze_reconstruction_data(self) -> None:
        """Print information needed to test reconstruction assumptions."""
        logger.debug("=== RECONSTRUCTION ANALYSIS ===")
        logger.debug(f"Total sprites in YAML: {len(self.sprite_configs)}")
        logger.debug(f"Total blocks in binary: {self.framebuffer_data.num_blocks}")
        logger.debug(f"Total CLUTs in binary: {self.framebuffer_data.num_cluts}")
        
        # Test linear block assumption
        logger.debug("\n--- BLOCK USAGE PATTERN ---")
        all_block_sequences = []
        for idx, sprite_config in enumerate(self.sprite_configs):
            blocks = sprite_config.block_ids
            all_block_sequences.extend(blocks)
            logger.debug(f"Sprite {idx}: blocks {blocks} (clutY={sprite_config.clut_y})")
        
        logger.debug(f"\nAll blocks used in order: {all_block_sequences[:20]}{'...' if len(all_block_sequences) > 20 else ''}")
        
        # Check if blocks are monotonic except for duplicates
        unique_blocks_seen = set()
        expected_next = 0
        monotonic = True
        for block_id in all_block_sequences:
            if block_id not in unique_blocks_seen:
                if block_id != expected_next:
                    monotonic = False
                    break
                unique_blocks_seen.add(block_id)
                expected_next += 1
        
        logger.debug(f"Blocks follow monotonic pattern: {monotonic}")
        logger.debug(f"Highest block ID used: {max(all_block_sequences) if all_block_sequences else 'None'}")
        
        # Analyze CLUT usage and potential duplicates
        logger.debug("\n--- CLUT ANALYSIS ---")
        clut_usage = {}
        for idx, sprite_config in enumerate(self.sprite_configs):
            clut_id = sprite_config.clut_y
            if clut_id not in clut_usage:
                clut_usage[clut_id] = []
            clut_usage[clut_id].append(idx)
        
        for clut_id in sorted(clut_usage.keys()):
            sprites = clut_usage[clut_id]
            logger.debug(f"CLUT {clut_id} used by sprites: {sprites}")
        
        # Count unique sprites that will be dumped
        unique_sprites = []
        seen_signatures = set()
        for idx, sprite_config in enumerate(self.sprite_configs):
            if sprite_config.signature not in seen_signatures:
                seen_signatures.add(sprite_config.signature)
                unique_sprites.append(idx)
        
        logger.debug(f"\nUnique sprites to be dumped: {len(unique_sprites)}")
        logger.debug(f"Duplicate sprites removed: {len(self.sprite_configs) - len(unique_sprites)}")
        logger.debug(f"Unique sprite indices: {unique_sprites}")
    
    def _extract_unique_sprites(self) -> None:
        """Extract only unique sprites to avoid duplicates."""
        unique_sprites = []
        seen_signatures = set()
        
        for idx, sprite_config in enumerate(self.sprite_configs):
            if sprite_config.signature not in seen_signatures:
                seen_signatures.add(sprite_config.signature)
                unique_sprites.append((idx, sprite_config))
        
        renderer = SpriteRenderer(self.framebuffer_data)
        for original_idx, sprite_config in unique_sprites:
            output_path = self.output_dir / f"{original_idx}.png"
            renderer.render_sprite(sprite_config, output_path)


def extract_sprites(binary_path: Path, yaml_path: Path, output_dir: Path, debug: bool = False) -> None:
    """Extract sprites from binary data and configuration file.
    
    Args:
        binary_path: Path to the binary file containing sprite data
        yaml_path: Path to the YAML configuration file
        output_dir: Directory to write extracted PNG files
        debug: Enable debug logging if True
        
    Raises:
        ValueError: If input files don't exist or are invalid
    """
    init_logging(debug)
    
    if not binary_path.exists():
        raise ValueError(f"Binary file not found: {binary_path}")
    
    if not yaml_path.exists():
        raise ValueError(f"YAML file not found: {yaml_path}")
    
    extractor = SpriteExtractor(binary_path, yaml_path, output_dir)
    extractor.extract_sprites()


def main() -> None:
    """Command-line entry point."""
    import argparse
    
    parser = argparse.ArgumentParser(description="Extract sprites from binary data")
    parser.add_argument("binary_file", type=Path, help="Binary file containing sprite data")
    parser.add_argument("yaml_file", type=Path, help="YAML configuration file")
    parser.add_argument("output_dir", type=Path, help="Output directory for PNG files")
    parser.add_argument("--debug", action="store_true", help="Enable debug output")
    
    args = parser.parse_args()
    
    try:
        extract_sprites(args.binary_file, args.yaml_file, args.output_dir, args.debug)
    except Exception as e:
        logger.error(f"Error during extraction: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()