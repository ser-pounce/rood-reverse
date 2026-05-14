"""
tools/etc/psx_img.py — Shared PSX image utilities.

Covers:
  - PSX RGBA5551 colour conversion
  - Palette encode / decode
  - PNG sPLT chunk helpers
  - 4bpp / 8bpp / 16bpp PNG read & write
"""

import struct
import zlib
from pathlib import Path


Rgba    = tuple[int, int, int, int]
Palette = list[Rgba]

# Sentinel sPLT chunk name that marks a PNG as 16bpp true-colour (no CLUT).
_SENTINEL_16BPP = 'tim_16bpp'


# ---------------------------------------------------------------------------
# PSX RGBA5551 colour conversion
# ---------------------------------------------------------------------------

def psx5551_to_rgba(val: int) -> Rgba:
    """
    Decode a PSX 16-bit 5551 word to an RGBA tuple.
    Bit 15 is the STP flag: 0 -> a=0, 1 -> a=255.
    The PS1 GPU expands 5-bit channels by shifting left 3; low bits are zero.
    """
    r = ((val >>  0) & 0x1F) << 3
    g = ((val >>  5) & 0x1F) << 3
    b = ((val >> 10) & 0x1F) << 3
    a = 255 if (val >> 15) & 1 else 0
    return r, g, b, a


def rgba_to_psx5551(r: int, g: int, b: int, a: int = 255) -> int:
    """
    Convert an 8-bit RGBA value to a PSX 16-bit 5551 word.
    Alpha encodes the STP bit: a=255 -> bit15=1, a=0 -> bit15=0.
    """
    r5  = (r >> 3) & 0x1F
    g5  = (g >> 3) & 0x1F
    b5  = (b >> 3) & 0x1F
    stp = 1 if a == 255 else 0
    return r5 | (g5 << 5) | (b5 << 10) | (stp << 15)


# ---------------------------------------------------------------------------
# Palette encode / decode
# ---------------------------------------------------------------------------

def parse_cluts(rom_bytes: bytes, offset: int, count: int, clut_entries: int) -> list[Palette]:
    """Parse `count` CLUTs of `clut_entries` PSX 5551 words each from `rom_bytes`."""
    data    = rom_bytes[offset:offset + count * clut_entries * 2]
    entries = [psx5551_to_rgba(e) for e, in struct.iter_unpack('<H', data)]
    return [entries[i * clut_entries:(i + 1) * clut_entries] for i in range(count)]


def encode_cluts(clut_list: list[Palette]) -> bytearray:
    """Encode a list of palettes as PSX 5551 little-endian u16 words."""
    out = bytearray()
    for palette in clut_list:
        for r, g, b, a in palette:
            out += struct.pack('<H', rgba_to_psx5551(r, g, b, a))
    return out


def plte_from_clut(clut: Palette) -> Palette:
    """
    Derive a viewer-friendly PLTE palette from a CLUT.
    Non-black entries are fully opaque; black entries preserve their alpha
    so transparent black renders correctly in PNG viewers.
    """
    return [(r, g, b, 255) if (r, g, b) != (0, 0, 0) else (r, g, b, a)
            for r, g, b, a in clut]


# ---------------------------------------------------------------------------
# PNG sPLT chunk helpers
# ---------------------------------------------------------------------------

def crc32_chunk(chunk_type: bytes, data: bytes) -> int:
    """Calculate CRC for a PNG chunk."""
    return zlib.crc32(chunk_type + data) & 0xFFFFFFFF


def make_splt_chunk(palette_name: str, palette_entries: Palette) -> bytes:
    """
    Create an sPLT chunk encoding RGBA tuples at 8-bit sample depth.
    Alpha encodes the STP bit: a=255 -> STP=1, a=0 -> STP=0.
    Returns a complete chunk including length, type, data, and CRC.
    Passing an empty palette_entries list produces a zero-entry sentinel chunk.
    """
    data  = palette_name.encode('latin-1') + b'\x00'  # null-terminated name
    data += b'\x08'                                    # sample depth: 8-bit
    for r, g, b, a in palette_entries:
        data += bytes([r, g, b, a])

    chunk_type = b'sPLT'
    crc        = crc32_chunk(chunk_type, data)
    return struct.pack('>I', len(data)) + chunk_type + data + struct.pack('>I', crc)


def make_text_chunk(keyword: str, text: str) -> bytes:
    """
    Create a PNG tEXt chunk (uncompressed Latin-1 keyword/value pair).
    Returns a complete chunk including length, type, data, and CRC.
    """
    chunk_data = keyword.encode('latin-1') + b'\x00' + text.encode('latin-1')
    chunk_type = b'tEXt'
    crc        = crc32_chunk(chunk_type, chunk_data)
    return struct.pack('>I', len(chunk_data)) + chunk_type + chunk_data + struct.pack('>I', crc)


def read_text_chunks(png_bytes: bytes) -> dict[str, str]:
    """
    Parse all tEXt chunks from raw PNG bytes.
    Returns a dict mapping keyword -> value (Latin-1 strings).
    """
    result: dict[str, str] = {}
    pos = 8  # skip PNG signature
    while pos < len(png_bytes):
        length     = struct.unpack_from('>I', png_bytes, pos)[0]
        chunk_type = png_bytes[pos + 4:pos + 8]
        chunk_data = png_bytes[pos + 8:pos + 8 + length]
        pos += 12 + length

        if chunk_type != b'tEXt':
            continue

        null_idx         = chunk_data.index(b'\x00')
        keyword          = chunk_data[:null_idx].decode('latin-1')
        value            = chunk_data[null_idx + 1:].decode('latin-1')
        result[keyword]  = value

    return result


def inject_chunks_before_iend(png_path: Path, chunks: list[bytes]) -> None:
    """
    Insert arbitrary pre-built PNG chunks into a file before the IEND chunk.

    Args:
        png_path: path to PNG file (modified in place)
        chunks:   complete chunks (length + type + data + CRC)
    """
    with open(png_path, 'r+b') as f:
        data = f.read()

    if data[-8:-4] != b'IEND':
        raise ValueError('PNG file does not end with IEND chunk')

    insert_pos = len(data) - 12
    for chunk in chunks:
        data = data[:insert_pos] + chunk + data[insert_pos:]
        insert_pos += len(chunk)

    with open(png_path, 'wb') as f:
        f.write(data)


# ---------------------------------------------------------------------------
# Pixel packing / unpacking
# ---------------------------------------------------------------------------

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
    
def decode_16bpp_pixels(data: bytes, width: int, height: int) -> bytes:
    """Decode packed PSX RGBA5551 words to flat RGBA8888 bytes.

    Returns width * height * 4 bytes, suitable for write_png's 16bpp path.
    Alpha is always 255 (the STP bit is discarded).
    """
    n_pixels = width * height
    words    = struct.unpack_from(f'<{n_pixels}H', data)
    out      = bytearray(n_pixels * 4)
    for i, word in enumerate(words):
        r, g, b, _ = psx5551_to_rgba(word)
        out[i * 4:i * 4 + 4] = (r, g, b, 255)
    return bytes(out)


def pack_pixels(pixels: list[int], bitdepth: int) -> bytearray:
    """Pack one-index-per-element pixel list into raw bytes."""
    if bitdepth == 4:
        return bytearray(
            (pixels[i] & 0x0F) | ((pixels[i + 1] & 0x0F) << 4)
            for i in range(0, len(pixels), 2)
        )
    else:
        return bytearray(pixels)


# ---------------------------------------------------------------------------
# Image encode / decode
# ---------------------------------------------------------------------------

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
    return bytearray(encode_cluts(cluts_before)) + pack_pixels(list(pixels), bitdepth) + bytearray(encode_cluts(cluts_after))


# ---------------------------------------------------------------------------
# PNG read / write
# ---------------------------------------------------------------------------

def write_png(
    output_path:  Path,
    pixels:       bytes,
    width:        int,
    height:       int,
    bitdepth:     int,
    cluts_before: list[Palette],
    cluts_after:  list[Palette],
    plte_clut:    int = 0,
    img_rect:     tuple[int, int, int, int] | None = None,
    clut_rect:    tuple[int, int, int, int] | None = None,
) -> None:
    """
    Write a PNG file from PSX image data.

    For 4bpp / 8bpp images: writes an indexed PNG with PLTE and sPLT chunks.
      PLTE is a viewer-friendly copy of the CLUT at index plte_clut in the
      combined list (cluts_before + cluts_after). sPLT chunks named
      'clut_before'/'clut_after' are authoritative for re-encoding.

    For 16bpp images: `pixels` must be a flat sequence of (R, G, B, A) bytes,
      i.e. width * height * 4 bytes of RGBA8888. A true-colour RGBA PNG is
      written, and a zero-entry sentinel sPLT chunk named 'tim_16bpp' is
      injected so read_png can identify this as 16bpp unambiguously.
      cluts_before / cluts_after are ignored for 16bpp.

    img_rect:  (x, y, w, h) VRAM rectangle from the TIM image block, stored as
               the tEXt keyword 'tim_img_rect' with value 'x,y,w,h'.
               w is in VRAM words, exactly as it appears in the binary.
    clut_rect: (x, y, w, h) VRAM rectangle from the TIM CLUT block, stored as
               the tEXt keyword 'tim_clut_rect' with value 'x,y,w,h'.
               Omitted when there is no CLUT.
    Both rects are optional; when absent pack_tim.py falls back to zeros.
    """
    import png as png_lib

    if bitdepth == 16:
        # True-colour RGBA path.
        n_pixels = width * height
        if len(pixels) != n_pixels * 4:
            raise ValueError(
                f'16bpp pixels must be width*height*4 bytes, '
                f'got {len(pixels)} (expected {n_pixels * 4})'
            )
        rows = [
            list(pixels[y * width * 4:(y + 1) * width * 4])
            for y in range(height)
        ]
        writer = png_lib.Writer(width=width, height=height, alpha=True, greyscale=False, bitdepth=8)
        with open(output_path, 'wb') as f:
            writer.write(f, rows)
        extra_chunks: list[bytes] = [make_splt_chunk(_SENTINEL_16BPP, [])]
        if img_rect is not None:
            extra_chunks.append(make_text_chunk('tim_img_rect', ','.join(map(str, img_rect))))
        inject_chunks_before_iend(output_path, extra_chunks)
        return

    # Indexed (4bpp / 8bpp) path.
    all_cluts = cluts_before + cluts_after

    if all_cluts:
        if plte_clut >= len(all_cluts):
            raise ValueError(f'plte_clut={plte_clut} out of range (have {len(all_cluts)} CLUTs)')
        img = png_lib.Writer(width=width, height=height, bitdepth=bitdepth,
                             palette=plte_from_clut(all_cluts[plte_clut]))
        with open(output_path, 'wb') as f:
            img.write_array(f, pixels)
        extra_chunks = (
            [make_splt_chunk('clut_before', clut) for clut in cluts_before] +
            [make_splt_chunk('clut_after',  clut) for clut in cluts_after]
        )
        if img_rect is not None:
            extra_chunks.append(make_text_chunk('tim_img_rect', ','.join(map(str, img_rect))))
        if clut_rect is not None:
            extra_chunks.append(make_text_chunk('tim_clut_rect', ','.join(map(str, clut_rect))))
        inject_chunks_before_iend(output_path, extra_chunks)
    else:
        n_colours    = 1 << bitdepth
        scale        = 255 // (n_colours - 1)
        grey_palette = [(i * scale, i * scale, i * scale, 255) for i in range(n_colours)]
        img = png_lib.Writer(width=width, height=height, bitdepth=bitdepth, palette=grey_palette)
        with open(output_path, 'wb') as f:
            img.write_array(f, pixels)
        if img_rect is not None:
            inject_chunks_before_iend(output_path, [make_text_chunk('tim_img_rect', ','.join(map(str, img_rect)))])


def _parse_tim_rect(value: str) -> tuple[int, int, int, int] | None:
    if not value:
        return None
    parts = value.split(',')
    if len(parts) != 4:
        return None
    try:
        return tuple(int(p.strip()) for p in parts)
    except ValueError:
        return None


def read_png(png_path: Path) -> tuple[bytes, int, int, int, list[Palette], list[Palette], tuple[int, int, int, int] | None, tuple[int, int, int, int] | None]:
    """
    Read a PNG produced by write_png.

    For indexed (4bpp / 8bpp) images:
      Returns (pixels, width, height, bitdepth, cluts_before, cluts_after, img_rect, clut_rect).
      sPLT chunks named 'clut_before' / 'clut_after' are authoritative;
      PLTE is ignored.

    For 16bpp true-colour images (identified by the 'tim_16bpp' sentinel sPLT):
      Returns (pixels, width, height, 16, [], [], img_rect, clut_rect) where pixels is a flat
      RGBA8888 byte string of length width * height * 4.

    img_rect and clut_rect are the VRAM rectangles as (x, y, w, h) tuples or None if not stored.
    """
    import png as png_lib

    png_bytes = png_path.read_bytes()
    text_dict = read_text_chunks(png_bytes)

    # Peek at sPLT chunks first to detect 16bpp before we attempt an indexed read.
    splt_chunks = read_splt_chunks(png_path)
    splt_names  = {name for name, _ in splt_chunks}

    if _SENTINEL_16BPP in splt_names:
        # True-colour path: read raw RGBA rows.
        reader = png_lib.Reader(bytes=png_bytes)
        width, height, rows, info = reader.read()

        if not info.get('alpha'):
            raise ValueError(f'Expected RGBA PNG for 16bpp image: {png_path}')

        img_rect = _parse_tim_rect(text_dict.get('tim_img_rect'))
        clut_rect = _parse_tim_rect(text_dict.get('tim_clut_rect'))

        pixels = bytes(v for row in rows for v in row)
        return pixels, width, height, 16, [], [], img_rect, clut_rect

    # Indexed path — unchanged behaviour.
    reader = png_lib.Reader(bytes=png_bytes)
    width, height, rows, info = reader.read()

    bitdepth: int = info.get('bitdepth')
    if bitdepth not in (4, 8):
        raise ValueError(
            f'Expected 4-bit or 8-bit indexed PNG (or a 16bpp PNG with the '
            f"'{_SENTINEL_16BPP}' sPLT sentinel), got bitdepth={bitdepth}: {png_path}"
        )

    img_rect = _parse_tim_rect(text_dict.get('tim_img_rect'))
    clut_rect = _parse_tim_rect(text_dict.get('tim_clut_rect'))

    pixels       = bytes(idx for row in rows for idx in row)
    cluts_before = [pal for name, pal in splt_chunks if name == 'clut_before']
    cluts_after  = [pal for name, pal in splt_chunks if name == 'clut_after']

    return pixels, width, height, bitdepth, cluts_before, cluts_after, img_rect, clut_rect


# ---------------------------------------------------------------------------
# sPLT chunk helpers
# ---------------------------------------------------------------------------

def read_splt_chunks(png_path: Path) -> list[tuple[str, Palette]]:
    """
    Parse sPLT chunks from a PNG file.

    Returns (name, palette) pairs in chunk order. The name determines layout:
      'clut_before' -> this CLUT precedes the pixel data in the binary
      'clut_after'  -> this CLUT follows the pixel data in the binary
      'tim_16bpp'   -> sentinel: image is 16bpp true-colour (no CLUT, no entries)
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
        pos += 12 + length

        if chunk_type != b'sPLT':
            continue

        null_idx     = chunk_data.index(b'\x00')
        name         = chunk_data[:null_idx].decode('latin-1')
        sample_depth = chunk_data[null_idx + 1]
        if sample_depth != 8:
            raise ValueError(f'Unsupported sPLT sample depth: {sample_depth} (only 8 supported)')

        entries_data = chunk_data[null_idx + 2:]
        palette: Palette = [
            (entries_data[i], entries_data[i + 1], entries_data[i + 2], entries_data[i + 3])
            for i in range(0, len(entries_data), 4)
        ]
        chunks.append((name, palette))

    return chunks
