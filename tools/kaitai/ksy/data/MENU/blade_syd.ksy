meta:
  id: blade_syd
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
    repeat-expr: 96

  materialcombinations:
    pos: materials_offset
    type: materials_table
    
  info:
    pos: info_offset
    type: info
    repeat: expr
    repeat-expr: 96

types:
  combination_row:
    seq:
      - id: data
        type: u1
        repeat: expr
        repeat-expr: 96
        
  materials_table:
    seq:
      - id: materials
        type: outer_material_row
        repeat: expr
        repeat-expr: 5
        
  outer_material_row:
    seq:
    - id: weapons
      type: weapon_row
      repeat: expr
      repeat-expr: 10
        
  weapon_row:
    seq:
      - id: materials
        type: material_row
        repeat: expr
        repeat-expr: 5

  material_row:
    seq:
      - id: weapons
        type: u1
        repeat: expr
        repeat-expr: 10
        enum: materials
        
  info:
    seq:
      - id: subid
        type: u1
      - id: wepid
        type: u1
      - id: category
        type: u1
      - id: damagetype
        type: u1
      - id: costtype
        type: u1
      - id: cost
        type: u1
      - id: unk6
        type: u1
      - id: unk7
        type: u1
      - id: strength
        type: s1
      - id: intelligence
        type: s1
      - id: agility
        type: s1
      - id: unkb
        type: u1
      - id: range
        type: u1
      - id: unkd
        type: u1
      - id: unke
        type: u1
      - id: attackshapeangle
        type: b5
      - id: attackshape
        type: b3

enums:
  materials:
    1: wood
    3: bronze
    4: iron
    5: hagane
    6: silver
    7: damascus
