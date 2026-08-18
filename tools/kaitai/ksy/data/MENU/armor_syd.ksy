meta:
  id: armor_syd
  file-extension: SYD
  imports: [/syd]

seq:
  - id: offsets
    type: syd::offsets

instances:
  combinations:
    pos: offsets.combinations
    type: syd::square_array(65)

  materialcombinations:
    pos: offsets.materials
    type: syd::materials_table(8, 4)
    
  info:
    pos: offsets.info
    type: syd::armor_info
    repeat: expr
    repeat-expr: 81
