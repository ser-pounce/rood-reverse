"""
Shared constants and utilities for Vagrant Story ARM file processing.
"""
import struct

# Format constants
ROOM_NAME_SIZE = 0x20
VERTEX_FORMAT = '<hhhH'
POLY3_FORMAT = '<BBBB'
POLY4_FORMAT = '<BBBB'
LINE_FORMAT = '<BBH'
POINT_FORMAT = '<BBBB'
ROOM_HEADER_FORMAT = '<IIHH'
ROOM_FOOTER_FORMAT = '<HH'

# Section keywords for OBJ parsing
SECTION_KEYWORDS = {
    'triangles': 'triangles',
    'quads': 'quads',
    'floor lines': 'floor',
    'wall lines': 'wall',
}

def clamp_byte(value):
    """Clamp a value to byte range (0-255)."""
    return int(value) & 0xFF

def pack_collection(buffer, items, pack_format, transform=None):
    """
    Pack a collection of items into a buffer with count prefix.
    
    Args:
        buffer: bytearray to append to
        items: collection of items to pack
        pack_format: struct format string for each item
        transform: optional function to transform each item before packing
    """
    buffer += struct.pack("<I", len(items))
    for item in items:
        data = transform(item) if transform else item
        buffer += struct.pack(pack_format, *data)
    return buffer

def read_struct(fmt, f):
    """Read and unpack a struct from file."""
    size = struct.calcsize(fmt)
    data = f.read(size)
    if len(data) != size:
        raise EOFError("Unexpected EOF while reading structure.")
    return struct.unpack(fmt, data)

def read_bytes(f, length):
    """Read exact number of bytes from file."""
    data = f.read(length)
    if len(data) != length:
        raise EOFError("Unexpected EOF while reading bytes.")
    return data