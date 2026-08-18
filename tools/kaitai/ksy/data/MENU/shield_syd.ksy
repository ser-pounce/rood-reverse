meta:
  id: shield_syd
  file-extension: SYD
  imports: [/syd]

seq:
  - id: offsets
    type: syd::offsets

instances:
  combinations:
    pos: offsets.combinations
    type: syd::square_array(17)

  materialcombinations:
    pos: offsets.materials
    type: syd::material_row(8)
    repeat: expr
    repeat-expr: 8

  info:
    pos: offsets.info
    type: syd::armor_info
    repeat: expr
    repeat-expr: 17
