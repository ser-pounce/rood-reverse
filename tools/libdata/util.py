import struct


def align(data: bytes, alignment: int = 4) -> bytes:
    return data + b"\0" * (-len(data) % alignment)


def build_offset_table(blocks: list[bytes], offset: int = 0) -> bytes:
    offsets = []
    pos = offset + len(blocks) * 2
    for block in blocks:
        offsets.append(pos // 2)
        pos += len(block)

    return struct.pack(f"<{len(blocks)}H", *offsets) + b"".join(blocks)