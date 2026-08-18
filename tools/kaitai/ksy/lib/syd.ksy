meta:
  id: syd
  endian: le

types:
  offsets:
    seq:
      - id: combinations
        type: u4
      - id: materials
        type: u4
      - id: info
        type: u4

  square_array:
    params:
      - id: num_rows
        type: u4
    seq:
      - id: rows
        type: combination_row(num_rows)
        repeat: expr
        repeat-expr: num_rows

  combination_row:
    params:
      - id: num_data
        type: u4
    seq:
      - id: data
        type: u1
        repeat: expr
        repeat-expr: num_data

  armor_info:
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
      - id: reserved
        contents: [0]

  materials_table:
    params:
      - id: num_materials
        type: u4
      - id: num_equipment
        type: u4
    seq:
      - id: materials
        type: outer_material_row(num_materials, num_equipment)
        repeat: expr
        repeat-expr: num_materials
        
  outer_material_row:
    params:
      - id: num_materials
        type: u4
      - id: num_equipment
        type: u4
    seq:
    - id: equipment
      type: equipment_row(num_materials, num_equipment)
      repeat: expr
      repeat-expr: num_equipment
        
  equipment_row:
    params:
      - id: num_materials
        type: u4
      - id: num_equipment
        type: u4
    seq:
      - id: materials
        type: material_row(num_equipment)
        repeat: expr
        repeat-expr: num_materials

  material_row:
    params:
      - id: num_equipment
        type: u4
    seq:
      - id: equipment
        type: u1
        repeat: expr
        repeat-expr: num_equipment
        enum: materials

enums:
  materials:
    1: wood
    2: leather
    3: bronze
    4: iron
    5: hagane
    6: silver
    7: damascus
