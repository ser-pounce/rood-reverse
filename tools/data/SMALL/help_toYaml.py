import struct
import sys
import yaml
from typing import Dict, List, Tuple, Any
from tools.etc.vsString import decode


class BinaryParser:
    
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


def parse_file(filename: str) -> Dict[str, Any]:
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
        sys.exit(1)


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: <filename> <output.yaml>", file=sys.stderr)
        sys.exit(1)
    
    output = parse_file(sys.argv[1])
    with open(sys.argv[2], "w") as f:
        yaml.dump(output, f, default_flow_style=False, sort_keys=False, allow_unicode=True)