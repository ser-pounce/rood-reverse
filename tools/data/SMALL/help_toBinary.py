import struct
import sys
import yaml
from typing import Dict, List, Any
from tools.etc.vsString import encode


def get_default_animation() -> Dict[str, Any]:
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
    data = bytearray()
    
    animation = sprite_data.get("animation", get_default_animation())
    data.extend(pack_animation(animation))
    
    clut_packed = (sprite_data["clutY"] * 16) | (sprite_data["clutX"])
    
    count = len(sprite_data["sprites"])
    
    data.extend(struct.pack("<hhhhhhh",
                           sprite_data["x"],
                           sprite_data["y"],
                           sprite_data["w"],
                           sprite_data["h"],
                           count,
                           sprite_data["colors"],
                           clut_packed))
    
    texUV = sprite_data["sprites"]
    data.extend(struct.pack("<" + "h" * len(texUV), *texUV))
    
    return bytes(data)


def pack_line(line_data: Dict[str, Any]) -> bytes:
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
    padding_needed = (4 - (len(data) % 4)) % 4
    return data + b'\x00' * padding_needed


def build_strings_block(strings: List[str]) -> bytes:
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
    data = bytearray()
    
    num_lines = len(lines)
    data.extend(struct.pack("<H", num_lines))
    
    for line in lines:
        data.extend(pack_line(line))
    
    return align_to_4_bytes(bytes(data))


def yaml_to_binary(yaml_filename: str, binary_filename: str) -> None:
    try:
        with open(yaml_filename, 'r', encoding='utf-8') as f:
            yaml_data = yaml.safe_load(f)
        
        if not all(key in yaml_data for key in ["strings", "sprites", "lines"]):
            raise ValueError("YAML must contain 'strings', 'sprites', and 'lines' sections")
        
        strings_block = build_strings_block(yaml_data["strings"])
        sprites_block = build_sprites_block(yaml_data["sprites"])
        lines_block = build_lines_block(yaml_data["lines"])
        empty_block = b''
        
        blocks = [strings_block, sprites_block, lines_block, empty_block]
        block_sizes = [len(block) for block in blocks]
        
        with open(binary_filename, 'wb') as f:
            f.write(struct.pack("<IIII", *block_sizes))
            
            for block in blocks:
                f.write(block)
        
    except (IOError, yaml.YAMLError, ValueError, struct.error) as e:
        sys.exit(1)


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: <input.yaml> <output.bin>", file=sys.stderr)
        sys.exit(1)
    
    yaml_to_binary(sys.argv[1], sys.argv[2])