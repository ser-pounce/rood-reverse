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
  - id: icon_palettes
    size: 32
    repeat: expr
    repeat-expr: 7
  - id: icon_bitmaps
    size: 128
    repeat: expr
    repeat-expr: 7
  - id: pocketstation_icons
    size: 128
    repeat: expr
    repeat-expr: 7
