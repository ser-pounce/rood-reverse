meta:
  id: help_hf1
  file-extension: HF1
  endian: le
  bit-endian: le

seq:
  - id: num_blocks
    type: u4
  - id: num_cluts
    type: u4
  - id: blocks
    size: 128
    repeat: expr
    repeat-expr: num_blocks
  - id: cluts
    type: clut
    repeat: expr
    repeat-expr: num_cluts
    doc: |
      Cluts can be interpreted either as 16 or 256 colors,
      depending on how the HF0 data accesses them, but they
      are ways described here as 16-color blocks.
    
types:
  clut:
    seq:
      - id: color
        type: bgr5551
        repeat: expr
        repeat-expr: 16
        
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
