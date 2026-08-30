import struct


def rle_decompress(data: bytes, fill_value: int = 0) -> bytes:
    words      = []
    pos        = 0
    data_words = len(data) // 4

    while pos < data_words:
        control, = struct.unpack_from('<I', data, pos * 4)
        pos += 1

        fill_count = control & 0xFFFF
        words.extend([fill_value] * fill_count)

        literal_count = control >> 16
        if literal_count:
            words.extend(struct.unpack_from(f'<{literal_count}I', data, pos * 4))
            pos += literal_count

    return struct.pack(f'<{len(words)}I', *words)


def rle_compress(words: bytes, fill_value: int = 0) -> bytes:
    assert len(words) % 4 == 0
    count = len(words) // 4
    values = struct.unpack(f'<{count}I', words) if count else ()

    MAX_RUN = 0xFFFF
    output = []
    pos = 0

    while pos < count:
        fill_start = pos
        while pos < count and values[pos] == fill_value and pos - fill_start < MAX_RUN:
            pos += 1
        fill_count = pos - fill_start

        literal_start = pos
        while pos < count and values[pos] != fill_value and pos - literal_start < MAX_RUN:
            pos += 1
        literal_count = pos - literal_start

        control = (literal_count << 16) | fill_count
        output.append(control)
        output.extend(values[literal_start:pos])

    return struct.pack(f'<{len(output)}I', *output)


class RleDecompressor:
    def __init__(self, fill_value: int = 0) -> None:
        self.fill_value = fill_value

    def decode(self, data: bytes) -> bytes:
        return rle_decompress(data, self.fill_value)
