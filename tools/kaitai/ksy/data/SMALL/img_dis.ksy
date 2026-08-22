meta:
  id: image_dis
  file-extension: DIS
  endian: le
  bit-endian: le
  
seq:
  - id: tims
    type: tim
    repeat: eos
  
types:
  tim:
    seq:
      - id: magic
        contents: [0x10, 0, 0, 0]
      - id: mode
        type: b3
      - id: has_clut
        type: b1
      - id: reserved
        type: b28
      - id: clut
        type: clut
        if: has_clut
      - id: img_len
        type: u4
      - id: rect
        type: rect
      - id: bytes
        size: img_len - 12
      
  clut:
    seq:
      - id: len
        type: u4
      - id: rect
        type: rect
      - id: colors
        type: bgr5551
        repeat: expr
        repeat-expr: (len - 12) / 2
        
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