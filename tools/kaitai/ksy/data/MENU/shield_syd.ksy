meta:
  id: shield_syd
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
    repeat-expr: 17

  materials:
    pos: materials_offset
    type: material_row
    repeat: expr
    repeat-expr: 8

  info:
    pos: info_offset
    type: shieldinfo
    size: 8
    repeat: expr
    repeat-expr: 17

types:
  combination_row:
    seq:
      - id: data
        type: u1
        repeat: expr
        repeat-expr: 17

  material_row:
    seq:
      - id: data
        type: u1
        repeat: expr
        repeat-expr: 8
        enum: materials

  shieldinfo:
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
