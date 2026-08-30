meta:
  id: mcdata_bin
  file-extension: BIN
  imports: [/img]
  
seq:
  - id: cluts
    type: img::clut
    size: 512
    repeat: expr
    repeat-expr: 2
  - id: unk400
    size: 32
    repeat: expr
    repeat-expr: 7
  - id: unk4e0
    size: 128
    repeat: expr
    repeat-expr: 7
  - id: unk860
    size: 128
    repeat: expr
    repeat-expr: 7
