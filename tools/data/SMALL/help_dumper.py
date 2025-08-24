#!/usr/bin/env python3
"""
Help File Dumper

Combines functionality of help_toYaml.py and sprite_extractor.py to:
1. Parse HF0 files containing text, layout and sprite metadata
2. Parse HF1 files containing the actual sprite data
3. Extract sprites to PNG files
4. Output a combined YAML representation
"""

import struct
import sys
import yaml
import logging
import os
from pathlib import Path
from typing import Dict, List, Tuple, Any, Set
import png
from tools.etc.vsString import decode

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
            alpha = 255  # Opaque
        
        return (r8, g8, b8, alpha)

class BinaryParser:
    """Parser for binary data with struct unpacking helpers."""
    
    def __init__(self, data: bytes):
        self.data = data
    
    def unpack_at(self, fmt: str, offset: int) -> Tuple:
        return struct.unpack_from(fmt, self.data, offset)
    
    def parse_header_and_offsets(self, offset: int) -> List[int]:
        count = self.unpack_at("<H", offset)[0]
        return [
            self.unpack_at("<H", offset + (i + 1) * 2)[0] * 2
            for i in range(count)
        ]

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
        # Store original data for YAML reconstruction
        self.original_data = sprite_data
    
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

# HF0 File Parsing Functions

def parse_animation(parser: BinaryParser, offset: int) -> Dict[str, Any] | None:
    fields = parser.unpack_at("<hHhhhhh", offset)
    
    if all(field == 0 for field in fields):
        return None
    
    return {
        "enabled": fields[0],
        "frameMask": format(fields[1], "016b"),
        "frameDuration": fields[2],
        "repeat": fields[3],
        "currentFrame": fields[4],
        "timer": fields[5],
        "isActive": fields[6],
    }

def parse_sprite(parser: BinaryParser, offset: int) -> Dict[str, Any]:
    animation = parse_animation(parser, offset)
    offset += 16

    x, y, w, h, count, colors, clut_packed = parser.unpack_at("<hhhhhhh", offset)
    offset += 14

    sprites = list(parser.unpack_at("<" + "h" * count, offset))

    clut_x = clut_packed % 16
    clut_y = clut_packed // 16

    result = {
        "x": x,
        "y": y,
        "w": w,
        "h": h,
        "colors": colors,
        "clutX": clut_x,
        "clutY": clut_y,
        "sprites": sprites,
    }
    
    if animation is not None:
        result["animation"] = animation
    
    return result

def parse_line(parser: BinaryParser, offset: int) -> Dict[str, Any]:
    animation = parse_animation(parser, offset)
    offset += 16

    x0, y0, x1, y1 = parser.unpack_at("<hhhh", offset)
    offset += 8

    r, g, b = parser.unpack_at("<BBB", offset)

    result = {
        "x0": x0,
        "y0": y0,
        "x1": x1,
        "y1": y1,
        "color": {"r": r, "g": g, "b": b},
    }
    
    if animation is not None:
        result["animation"] = animation
    
    return result

def parse_strings_block(block_data: bytes) -> List[str]:
    parser = BinaryParser(block_data)
    offsets = parser.parse_header_and_offsets(0)
    
    strings = []
    for offset in offsets:
        result = decode(block_data[offset:])
        strings.append(result)
    
    return strings

def parse_sprites_block(block_data: bytes) -> List[Dict[str, Any]]:
    parser = BinaryParser(block_data)
    offsets = parser.parse_header_and_offsets(0)
    
    sprites = []
    for offset in offsets:
        sprite = parse_sprite(parser, offset)
        sprites.append(sprite)
    
    return sprites

def parse_lines_block(block_data: bytes) -> List[Dict[str, Any]]:
    parser = BinaryParser(block_data)
    num_lines = parser.unpack_at("<H", 0)[0]
    
    lines = []
    offset = 2
    for _ in range(num_lines):
        line = parse_line(parser, offset)
        lines.append(line)
        offset += 28
    
    return lines

def read_file_blocks(filename: str) -> List[bytes]:
    with open(filename, "rb") as f:
        data = f.read()

    block_sizes = struct.unpack_from("<IIII", data, 0)
    
    blocks = []
    offset = 16
    for size in block_sizes:
        blocks.append(data[offset:offset + size])
        offset += size
    
    return blocks

def parse_hf0_file(filename: str) -> Dict[str, Any]:
    try:
        blocks = read_file_blocks(filename)
        
        if len(blocks) < 3:
            raise ValueError("File must contain at least 3 blocks")
        
        strings = parse_strings_block(blocks[0])
        sprites = parse_sprites_block(blocks[1])
        lines = parse_lines_block(blocks[2])
        
        output = {
            "strings": strings,
            "sprites": sprites,
            "lines": lines,
        }
        
        return output
        
    except (IOError, struct.error, ValueError) as e:
        logger.error(f"Error parsing HF0 file: {e}")
        raise

# HF1 File Parsing and Sprite Extraction

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

def process_help_files(hf0_path: Path, hf1_path: Path, output_dir: Path, debug: bool = False) -> None:
    """Process HF0 and HF1 files to extract sprites and generate YAML."""
    init_logging(debug)
    
    try:
        # Parse HF0 file first to get sprite metadata
        logger.debug(f"Parsing HF0 file: {hf0_path}")
        hf0_data = parse_hf0_file(str(hf0_path))
        
        # Parse HF1 file to get sprite data
        logger.debug(f"Parsing HF1 file: {hf1_path}")
        with open(hf1_path, "rb") as f:
            hf1_data = f.read()
        framebuffer_data = FramebufferParser.parse(hf1_data)
        
        # Convert sprite metadata to configs
        sprite_configs = [SpriteConfig(sprite_data) for sprite_data in hf0_data["sprites"]]
        
        # Set up renderer
        renderer = SpriteRenderer(framebuffer_data)
        
        # Create sprites directory
        # Using output_dir directly for sprites
        
        # Track unique sprites to avoid duplicates
        seen_signatures = set()
        sprite_files = {}  # Maps original index to PNG filename
        
        # Extract unique sprites
        logger.debug("Extracting unique sprites...")
        for idx, sprite_config in enumerate(sprite_configs):
            if sprite_config.signature not in seen_signatures:
                seen_signatures.add(sprite_config.signature)
                output_path = output_dir / f"sprite_{idx}.png"
                renderer.render_sprite(sprite_config, output_path)
                sprite_files[idx] = output_path.name
            else:
                # For duplicates, reference the first occurrence
                for prev_idx, prev_config in enumerate(sprite_configs[:idx]):
                    if prev_config.signature == sprite_config.signature:
                        sprite_files[idx] = sprite_files[prev_idx]
                        break
        
        # Create simplified sprite entries with just position, animation and PNG reference
        simplified_sprites = []
        for idx, sprite in enumerate(hf0_data["sprites"]):
            simplified_sprite = {
                "x": sprite["x"],
                "y": sprite["y"],
                "file": sprite_files[idx]
            }
            if "animation" in sprite:
                simplified_sprite["animation"] = sprite["animation"]
            simplified_sprites.append(simplified_sprite)
        
        # Replace full sprite data with simplified version
        hf0_data["sprites"] = simplified_sprites
        
        # Write combined YAML output
        yaml_path = output_dir / "help_data.yaml"
        logger.debug(f"Writing YAML data to: {yaml_path}")
        with open(yaml_path, "w", encoding="utf-8") as f:
            yaml.dump(hf0_data, f, default_flow_style=False, sort_keys=False, allow_unicode=True)
        
        # Print summary
        logger.info(f"Processed {len(sprite_configs)} sprites ({len(seen_signatures)} unique)")
        logger.info(f"Output written to: {output_dir}")
        
    except Exception as e:
        logger.error(f"Error processing help files: {e}")
        raise

def main() -> None:
    """Command-line entry point."""
    import argparse
    
    parser = argparse.ArgumentParser(description="Process HF0/HF1 files and extract sprites")
    parser.add_argument("hf0_file", type=Path, help="Input HF0 file")
    parser.add_argument("hf1_file", type=Path, help="Input HF1 file")
    parser.add_argument("output_dir", type=Path, help="Output directory")
    parser.add_argument("--debug", action="store_true", help="Enable debug output")
    
    args = parser.parse_args()
    
    try:
        process_help_files(args.hf0_file, args.hf1_file, args.output_dir, args.debug)
    except Exception as e:
        logger.error(str(e))
        sys.exit(1)

if __name__ == "__main__":
    main()
