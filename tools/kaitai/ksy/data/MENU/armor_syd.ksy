meta:
  id: armor_syd
  file-extension: SYD
  endian: le

seq:
  - id: combinations_offset
    type: u4
  - id: materials_offset
    type: u4
  - id: info_offset
    type: u4

instances:
    
  combinations:
    pos: combinations_offset
    type: combination_row
    repeat: expr
    repeat-expr: 65

  materialcombinations:
    pos: materials_offset
    type: materials_table
    
  info:
    pos: info_offset
    type: info
    size: 8
    repeat: expr
    repeat-expr: 81

types:
  combination_row:
    seq:
      - id: data
        type: u1
        repeat: expr
        repeat-expr: 65
        
  materials_table:
    seq:
      - id: materials
        type: outer_material_row
        repeat: expr
        repeat-expr: 8
        
  outer_material_row:
    seq:
    - id: armor
      type: armor_row
      repeat: expr
      repeat-expr: 4
        
  armor_row:
    seq:
      - id: materials
        type: material_row
        repeat: expr
        repeat-expr: 8

  material_row:
    seq:
      - id: armor
        type: u1
        repeat: expr
        repeat-expr: 4
        enum: materials
        
  info:
    seq:
      - id: subid
        type: u1
      - id: wepid
        type: u1
      - id: category
        type: u1
      - id: gemslots
        type: u1
      - id: strength
        type: s1
      - id: intelligence
        type: s1
      - id: agility
        type: s1

enums:
  materials:
    1: wood
    2: leather
    3: bronze
    4: iron
    5: hagane
    6: silver
    7: damascus
