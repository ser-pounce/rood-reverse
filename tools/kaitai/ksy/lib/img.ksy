meta:
  id: img
  endian: le
  bit-endian: le

types:
  clut:
    seq:
      - id: colors
        type: bgr5551
        repeat: eos

  bgr5551:
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
      r8:
        value: r << 3
      g8:
        value: g << 3
      b8:
        value: b << 3
      a8:
        value: '(stp or r != 0 or g != 0 or b != 0) ? 255 : 0'

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
