meta:
  id: img
  endian: le
  bit-endian: le

types:
  clut:
    seq:
      - id: colors
        type: rgb5
        repeat: eos

  rgb5:
    seq:
      - id: r
        type: b5
      - id: g
        type: b5
      - id: b
        type: b5
      - id: stp
        type: b1
    instances:
      raw:
        value: r + (g << 5) + (b << 10) + (stp.to_i << 15)
      r8:
        value: r << 3
      g8:
        value: g << 3
      b8:
        value: b << 3
      a8:
        value: '(stp and (r == 0 and g == 0 and b == 0)) ? 0 : 255'

  rgb5_array:
    seq:
      - id: colors
        type: rgb5
        repeat: eos

  rle_rgb5:
    seq:
      - id: raw_indices
        size-eos: true
        process: tools.libdata.rle.rle_decompressor(0x80008000)
        type: rgb5_array

  rgba16_header:
    seq:
      - id: w
        type: u2
      - id: h
        type: u2
      - id: colors
        type: rgb5
        repeat: eos

  cluts_indices:
    params:
      - id: mode
        type: u4
      - id: num_cluts
        type: u4
      - id: cluts_after
        type: bool
    seq:
      - id: cluts_b
        type: clut
        size: 'mode == 0 ? 32 : 512'
        repeat: expr
        repeat-expr: num_cluts
        if: not cluts_after
      - id: indices
        type: indices(mode)
        size: '_io.size - (mode == 0 ? 32 : 512) * num_cluts'
      - id: cluts_a
        type: clut
        size: 'mode == 0 ? 32 : 512'
        repeat: expr
        repeat-expr: num_cluts
        if: cluts_after
    instances:
      cluts:
        value: 'cluts_after ? cluts_a : cluts_b'

  rect:
    seq:
      - id: x
        type: s2
      - id: y
        type: s2
      - id: w
        type: s2
      - id: h
        type: s2

  tim:
    seq:
      - id: magic
        type: u4
      - id: mode
        type: b3
      - id: has_clut
        type: b1
      - id: reserved
        type: b28
      - id: clut
        type: clutsection
        if: has_clut
      - id: indices_len
        type: u4
      - id: rect
        type: rect
      - id: indices
        type: indices(mode)
        size: indices_len - 12

  clutsection:
    seq:
      - id: len
        type: u4
      - id: rect
        type: rect
      - id: clut
        type: clut
        size: len - 12

  indices:
    params:
      - id: mode
        type: u4
    seq:
      - id: indices
        type:
          switch-on: mode
          cases:
            0: b4
            1: u1
            2: rgb5
        repeat: eos
