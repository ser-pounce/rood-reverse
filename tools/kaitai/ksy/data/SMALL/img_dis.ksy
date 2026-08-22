meta:
  id: image_dis
  file-extension: DIS
  endian: le
  bit-endian: le
  imports: [/img]
  
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
        type: clutsection
        if: has_clut
      - id: indices_len
        type: u4
      - id: rect
        type: img::rect
      - id: indices
        type: indices(mode)
        size: indices_len - 12
      
  clutsection:
    seq:
      - id: len
        type: u4
      - id: rect
        type: img::rect
      - id: clut
        type: img::clut
        size: len - 12
        
  indices:
    params:
      - id: mode
        type: u4
    seq:
      - id: index
        type:
          switch-on: mode
          cases:
            0: b4
            1: u1
            2: img::bgr5551
        repeat: eos
