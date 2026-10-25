meta:
  id: system_dat
  file-extension: DAT
  endian: le
  imports: [/img]

seq:
  - id: offsets
    type: u4
    repeat: expr
    repeat-expr: 8

instances:
  ui_tex0:
    pos: offsets[0]
    type: image
  ui_tex1:
    pos: offsets[1]
    type: image
  clut0:
    pos: offsets[2]
    type: clut(32) # Bad data for w
  grid0:
    pos: offsets[3]
    type: image
  grid1:
    pos: offsets[4]
    type: image
  base_effect:
    pos: offsets[5]
    type: image
  clut1:
    pos: offsets[6]
    type: clut(0)
  font:
    pos: offsets[7]
    type: font

types:
  image:
    seq:
      - id: header
        type: img::rect
      - id: pixels
        size: header.w * header.h * 2
        type: img::indices(0)
        
  clut:
    params:
      - id: max_size
        type: s4     # 0 = no limit
    seq:
      - id: w
        type: s2
      - id: h
        type: s2
      - id: pixels
        size: len_pixels
        type: img::clut
    instances:
      len_pixels:
        value: '(max_size > 0 and max_size < w * h * 2) ? max_size : w * h * 2'

  font:
    seq:
      - id: table0
        size: 0x7000
        type: img::indices(0)
  # Tables 1 & 2 are mostly empty in the western releases,
  # but they contain cluts used for everything else
      - id: table1
        size: 0x7000
        type: img::indices(0)
      - id: table2
        size: 0x4f00
        type: img::indices(0)
