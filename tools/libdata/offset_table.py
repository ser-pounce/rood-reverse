"""
Builds a binary blob consisting of a table of offsets followed by
the data blocks they point to.

Layout:
  - `num_blocks` 2-byte offsets (each = byte_offset / 2, relative to the
    start of the table).
  - The first offset is also implicitly the item count.
  - `blocks` are emitted as-is, encoding / padding etc. are the 
    responsibility of the caller.
"""

import struct
from typing import List


def build_offset_table(blocks: List[bytes]) -> bytes:
    offsets = []
    pos = len(blocks) * 2
    for block in blocks:
        offsets.append(pos // 2)
        pos += len(block)

    return struct.pack(f"<{len(blocks)}h", *offsets) + b"".join(blocks)
