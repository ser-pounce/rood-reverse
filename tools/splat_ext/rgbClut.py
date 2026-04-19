import struct
import sys
import zlib
from pathlib import Path
from typing import Any

import png
from tools.splat_ext.img import PSXSegImg

Rgba    = tuple[int, int, int, int]
Palette = list[Rgba]


# ---------------------------------------------------------------------------
# PNG chunk helpers
# ---------------------------------------------------------------------------

def crc32_chunk(chunk_type: bytes, data: bytes) -> int:
    """Calculate CRC for a PNG chunk."""
    return zlib.crc32(chunk_type + data) & 0xFFFFFFFF


def make_splt_chunk(palette_name: str, palette_entries: Palette) -> bytes:
    """
    Create an sPLT (suggested palette) chunk.

    Alpha encodes the STP bit: a=255 -> STP=1, a=0 -> STP=0.
    Returns a complete chunk including length, type, data, and CRC.
    """
    data = palette_name.encode('latin-1') + b'\x00'  # null-terminated name
    data += b'\x08'  # sample depth: 8-bit per channel
    for r, g, b, a in palette_entries:
        data += bytes([r, g, b, a])

    chunk_type = b'sPLT'
    crc = crc32_chunk(chunk_type, data)
    return struct.pack('>I', len(data)) + chunk_type + data + struct.pack('>I', crc)


def inject_splt_before_iend(png_path: Path, splt_chunks: list[bytes]) -> None:
    """
    Insert sPLT chunks into a PNG file before the IEND chunk.

    Args:
        png_path:    path to PNG file
        splt_chunks: complete chunks (length + type + data + CRC)
    """
    with open(png_path, 'r+b') as f:
        data = f.read()

        # PNG chunk layout: 4-byte length | 4-byte type | <data> | 4-byte CRC
        # IEND has 0-length data, so the last 12 bytes are:
        #   data[-12:-8]  = length (\x00\x00\x00\x00)
        #   data[ -8: -4] = type   (b'IEND')
        #   data[ -4:   ] = CRC
        if data[-8:-4] != b'IEND':
            raise ValueError('PNG file does not end with IEND chunk')

        insert_pos = len(data) - 12
        for chunk in splt_chunks:
            data = data[:insert_pos] + chunk + data[insert_pos:]
            insert_pos += len(chunk)

        f.seek(0)
        f.write(data)
        f.truncate()


def read_splt_chunks(png_path: Path) -> list[tuple[str, Palette]]:
    """
    Parse sPLT chunks from a PNG file.

    Returns (name, palette) pairs in chunk order. The name determines layout:
      'clut_before' -> this CLUT precedes the pixel data in the binary
      'clut_after'  -> this CLUT follows the pixel data in the binary
    Only 8-bit-depth sPLT chunks are supported (sample depth == 8).
    """
    with open(png_path, 'rb') as f:
        data = f.read()

    chunks: list[tuple[str, Palette]] = []
    pos = 8  # skip PNG signature
    while pos < len(data):
        length     = struct.unpack_from('>I', data, pos)[0]
        chunk_type = data[pos + 4:pos + 8]
        chunk_data = data[pos + 8:pos + 8 + length]
        pos += 12 + length  # length + type + data + CRC

        if chunk_type != b'sPLT':
            continue

        null_idx     = chunk_data.index(b'\x00')
        name         = chunk_data[:null_idx].decode('latin-1')
        sample_depth = chunk_data[null_idx + 1]
        if sample_depth != 8:
            raise ValueError(f'Unsupported sPLT sample depth: {sample_depth} (only 8 supported)')

        entries_data = chunk_data[null_idx + 2:]  # RGBA tuples, 4 bytes each
        palette: Palette = [
            (entries_data[i], entries_data[i + 1], entries_data[i + 2], entries_data[i + 3])
            for i in range(0, len(entries_data), 4)
        ]
        chunks.append((name, palette))

    return chunks


# ---------------------------------------------------------------------------
# PSX 5551 colour conversion
# ---------------------------------------------------------------------------

def psx5551_to_rgba(entry_bytes: int) -> Rgba:
    """
    Decode a PSX 16-bit 5551 word to an RGBA tuple.

    Bit 15 is the STP flag, stored as alpha uniformly for all colours:
      bit15=0 -> a=0   (STP off; transparent if black)
      bit15=1 -> a=255 (STP on;  opaque if black)
    PLTE uses fully opaque colours for viewer compatibility; sPLT is authoritative.
    """
    r = ((entry_bytes >> 0)  & 0x1F) << 3
    g = ((entry_bytes >> 5)  & 0x1F) << 3
    b = ((entry_bytes >> 10) & 0x1F) << 3
    a = 255 if (entry_bytes >> 15) & 1 else 0
    return r, g, b, a


def rgba_to_psx5551(r: int, g: int, b: int, a: int = 255) -> bytes:
    """
    Convert an 8-bit RGBA value to a PSX 16-bit 5551 little-endian word.

    Alpha encodes the STP bit uniformly for all colours:
      a=255 -> bit15=1 (STP on)
      a=0   -> bit15=0 (STP off)
    """
    r5  = (r >> 3) & 0x1F
    g5  = (g >> 3) & 0x1F
    b5  = (b >> 3) & 0x1F
    stp = 1 if a == 255 else 0
    return struct.pack('<H', r5 | (g5 << 5) | (b5 << 10) | (stp << 15))


# ---------------------------------------------------------------------------
# PSX indexed image encode / decode
# ---------------------------------------------------------------------------

def parse_cluts(rom_bytes: bytes, offset: int, count: int, clut_entries: int) -> list[Palette]:
    """Parse `count` CLUTs of `clut_entries` PSX 5551 words each from `rom_bytes`."""
    data    = rom_bytes[offset:offset + count * clut_entries * 2]
    entries = [psx5551_to_rgba(e) for e, in struct.iter_unpack('<H', data)]
    return [entries[i * clut_entries:(i + 1) * clut_entries] for i in range(count)]


def unpack_pixels(pixel_data: bytes, bitdepth: int, n_pixels: int) -> bytes:
    """Unpack raw pixel index bytes into one index per byte."""
    if bitdepth == 4:
        return bytes(
            nibble
            for b in pixel_data
            for nibble in [b & 0x0F, (b >> 4) & 0x0F]
        )[:n_pixels]
    else:
        return bytes(pixel_data)


def pack_pixels(pixels: list[int], bitdepth: int) -> bytearray:
    """Pack one-index-per-element pixel list into raw bytes."""
    if bitdepth == 4:
        return bytearray(
            (pixels[i] & 0x0F) | ((pixels[i + 1] & 0x0F) << 4)
            for i in range(0, len(pixels), 2)
        )
    else:
        return bytearray(pixels)


def encode_cluts(clut_list: list[Palette]) -> bytearray:
    """Encode a list of palettes as PSX 5551 words."""
    out = bytearray()
    for palette in clut_list:
        for r, g, b, a in palette:
            out += rgba_to_psx5551(r, g, b, a)
    return out


def plte_from_clut(clut: Palette) -> Palette:
    """
    Derive a viewer-friendly PLTE palette from a CLUT.

    Non-black entries are fully opaque; black entries preserve their alpha
    so transparent black renders correctly in PNG viewers.
    """
    return [(r, g, b, 255 if (r, g, b) != (0, 0, 0) else a) for r, g, b, a in clut]


def decode_image(
    rom_bytes:    bytes,
    rom_start:    int,
    width:        int,
    height:       int,
    bitdepth:     int,
    cluts_before: int,
    cluts_after:  int,
) -> tuple[bytes, list[Palette], list[Palette]]:
    """
    Decode a PSX indexed image from rom_bytes.

    Returns (pixels, cluts_before, cluts_after) where pixels is one byte per
    index and each palette is a list of RGBA tuples.
    """
    clut_entries      = 1 << bitdepth
    n_pixels          = width * height
    pixel_bytes       = (n_pixels + (1 if bitdepth == 4 else 0)) // (8 // bitdepth)
    clut_bytes_before = cluts_before * clut_entries * 2
    clut_bytes_after  = cluts_after  * clut_entries * 2
    clut_bytes_total  = clut_bytes_before + clut_bytes_after

    if len(rom_bytes) - rom_start < pixel_bytes + clut_bytes_total:
        raise ValueError(
            f'Not enough data: expected {pixel_bytes + clut_bytes_total} bytes, '
            f'got {len(rom_bytes) - rom_start}'
        )

    before_offset = rom_start
    pixel_offset  = rom_start + clut_bytes_before
    after_offset  = pixel_offset + pixel_bytes

    pixels       = unpack_pixels(rom_bytes[pixel_offset:pixel_offset + pixel_bytes], bitdepth, n_pixels)
    before_cluts = parse_cluts(rom_bytes, before_offset, cluts_before, clut_entries)
    after_cluts  = parse_cluts(rom_bytes, after_offset,  cluts_after,  clut_entries)

    return pixels, before_cluts, after_cluts


def encode_image(
    pixels:       bytes,
    cluts_before: list[Palette],
    cluts_after:  list[Palette],
    bitdepth:     int,
) -> bytearray:
    """
    Encode pixels and CLUTs into a PSX binary blob.

    Layout: [cluts_before] [pixels] [cluts_after]
    """
    clut_bytes_before = encode_cluts(cluts_before)
    clut_bytes_after  = encode_cluts(cluts_after)
    packed            = pack_pixels(list(pixels), bitdepth)
    return bytearray(clut_bytes_before) + packed + bytearray(clut_bytes_after)


def write_png(
    output_path:  Path,
    pixels:       bytes,
    width:        int,
    height:       int,
    bitdepth:     int,
    cluts_before: list[Palette],
    cluts_after:  list[Palette],
    plte_clut:    int = 0,
) -> None:
    """
    Write an indexed PNG with PLTE and sPLT chunks encoding all CLUTs.

    PLTE is a viewer-friendly copy of the CLUT at index plte_clut in the
    combined list (cluts_before + cluts_after). Black transparency is
    preserved; all other entries are fully opaque. sPLT chunks named
    'clut_before'/'clut_after' are authoritative for re-encoding.
    """
    all_cluts = cluts_before + cluts_after

    if all_cluts:
        if plte_clut >= len(all_cluts):
            raise ValueError(f'plte_clut={plte_clut} out of range (have {len(all_cluts)} CLUTs)')
        img = png.Writer(width=width, height=height, bitdepth=bitdepth,
                         palette=plte_from_clut(all_cluts[plte_clut]))
        with open(output_path, 'wb') as f:
            img.write_array(f, pixels)
        splt_chunks = (
            [make_splt_chunk('clut_before', clut) for clut in cluts_before] +
            [make_splt_chunk('clut_after',  clut) for clut in cluts_after]
        )
        inject_splt_before_iend(output_path, splt_chunks)
    else:
        # No CLUT: write indexed PNG with a grayscale palette so bitdepth is preserved
        # and round-trip is exact (index N -> grey value N * 255 // (n_colours - 1))
        n_colours = 1 << bitdepth
        scale     = 255 // (n_colours - 1)
        grey_palette: Palette = [(i * scale, i * scale, i * scale, 255) for i in range(n_colours)]
        img = png.Writer(width=width, height=height, bitdepth=bitdepth, palette=grey_palette)
        with open(output_path, 'wb') as f:
            img.write_array(f, pixels)


def read_png(png_path: Path) -> tuple[bytes, int, int, int, list[Palette], list[Palette]]:
    """
    Read an indexed PNG produced by write_png.

    Returns (pixels, width, height, bitdepth, cluts_before, cluts_after).
    sPLT chunks are authoritative; PLTE is ignored.
    """
    reader = png.Reader(filename=str(png_path))
    width, height, rows, info = reader.read()

    bitdepth: int = info.get('bitdepth')
    if bitdepth not in (4, 8):
        raise ValueError(f'Expected 4-bit or 8-bit indexed PNG, got bitdepth={bitdepth}')

    pixels       = bytes(idx for row in rows for idx in row)
    splt_chunks  = read_splt_chunks(png_path)
    cluts_before = [pal for name, pal in splt_chunks if name == 'clut_before']
    cluts_after  = [pal for name, pal in splt_chunks if name == 'clut_after']

    return pixels, width, height, bitdepth, cluts_before, cluts_after



# ---------------------------------------------------------------------------
# Splat segment
# ---------------------------------------------------------------------------

class PSXSegRgbClut(PSXSegImg):

    cluts_before: int
    cluts_after:  int
    bitdepth:     int
    clut_entries: int
    plte_clut:    int

    def __init__(self, **kwargs: Any) -> None:
        super().__init__(**kwargs)

        if len(kwargs['yaml']) < 5:
            raise ValueError('PSXSegRgbClut requires width and height')

        if isinstance(kwargs['yaml'], dict):
            has_before = 'cluts_before' in kwargs['yaml']
            has_after  = 'cluts_after'  in kwargs['yaml']

            self.cluts_before = int(kwargs['yaml'].get('cluts_before', 0))
            self.cluts_after  = int(kwargs['yaml'].get('cluts_after',  0))
            self.bitdepth     = int(kwargs['yaml'].get('bitdepth', 4))
            self.plte_clut    = int(kwargs['yaml'].get('plte_clut', 0))
        else:
            # List-style YAML: clut count parameters must use dict-style
            self.cluts_before = 1
            self.cluts_after  = 0
            self.bitdepth     = 4
            self.plte_clut    = 0

        if self.bitdepth not in (4, 8):
            raise ValueError(f'PSXSegRgbClut: bitdepth must be 4 or 8, got {self.bitdepth}')
        self.clut_entries = 1 << self.bitdepth  # 4-bit -> 16, 8-bit -> 256

    def split(self, rom_bytes: bytes) -> None:
        pixels, before_cluts, after_cluts = decode_image(
            rom_bytes, self.rom_start, self.width, self.height,
            self.bitdepth, self.cluts_before, self.cluts_after,
        )
        png_path = self.make_path()
        write_png(png_path, pixels, self.width, self.height,
                  self.bitdepth, before_cluts, after_cluts, self.plte_clut)




# ---------------------------------------------------------------------------
# CLI re-encoder
# ---------------------------------------------------------------------------

if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('input',  type=Path, help='Input PNG file')
    parser.add_argument('output', type=Path, help='Output file')
    parser.add_argument('--dat',  action='store_true', help='Write a .dat text file instead of a .o object file')
    args = parser.parse_args()

    pixels, width, height, bitdepth, cluts_before, cluts_after = read_png(args.input)

    packed            = pack_pixels(list(pixels), bitdepth)
    clut_bytes_before = encode_cluts(cluts_before)
    clut_bytes_after  = encode_cluts(cluts_after)

    binary        = bytes(clut_bytes_before + packed + clut_bytes_after)
    symbol_name   = args.input.name.split('.')[0]
    symbol_offset = len(clut_bytes_before)  # pixel data starts after any leading CLUTs

    if args.dat:
        with open(args.output, 'w') as h:
            for byte in binary:
                h.write(f'0x{byte:02X},')
    else:
        if cluts_before:
            symbols = [(f'{symbol_name}_clut', 0), (symbol_name, symbol_offset)]
        elif cluts_after:
            symbols = [(symbol_name, 0), (f'{symbol_name}_clut', len(packed))]
        else:
            symbols = [(symbol_name, 0)]

        PSXSegRgbClut.write_object_file(
            binary,
            args.output,
            symbols,
            *PSXSegRgbClut.objcopy_from_env(),
        )
