meta:
  id: help_hf1
  file-extension: HF1
  endian: le
  imports: [/img]

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
    type: img::clut
    size: 32
    repeat: expr
    repeat-expr: num_cluts
    doc: |
      Cluts can be interpreted either as 16 or 256 colors,
      depending on how the HF0 data accesses them, but they
      are always counted as 16-color blocks here.
