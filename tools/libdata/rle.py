import struct

def rle_decompress(data: bytes) -> bytes:
    words      = []
    pos        = 0
    data_words = len(data) // 4

    while pos < data_words:
        control, = struct.unpack_from('<I', data, pos * 4)
        pos += 1

        zero_count = control & 0xFFFF
        words.extend([0] * zero_count)

        literal_count = control >> 16
        if literal_count:
            words.extend(struct.unpack_from(f'<{literal_count}I', data, pos * 4))
            pos += literal_count

    return struct.pack(f'<{len(words)}I', *words)


def rle_compress(words: bytes) -> bytes:
    assert len(words) % 4 == 0
    count = len(words) // 4
    values = struct.unpack(f'<{count}I', words) if count else ()

    MAX_RUN = 0xFFFF  # zero_count and literal_count are each 16 bits
    output = []
    pos = 0

    while pos < count:
        zero_start = pos
        while pos < count and values[pos] == 0 and pos - zero_start < MAX_RUN:
            pos += 1
        zero_count = pos - zero_start

        literal_start = pos
        while pos < count and values[pos] != 0 and pos - literal_start < MAX_RUN:
            pos += 1
        literal_count = pos - literal_start

        control = (literal_count << 16) | zero_count
        output.append(control)
        output.extend(values[literal_start:pos])

    return struct.pack(f'<{len(output)}I', *output)


class RleDecompressor:
    def decode(self, data: bytes) -> bytes:
        return rle_decompress(data)
