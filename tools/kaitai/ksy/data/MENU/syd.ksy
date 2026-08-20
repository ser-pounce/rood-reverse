meta:
  id: syd
  endian: le

params:
  - id: item_type
    type: str
  - id: num_itemcombinations
    type: u4
  - id: num_items
    type: u4
  - id: num_categories
    type: u4
  - id: num_materials
    type: u4
seq:
  - id: itemcombinationsoffset
    type: u4
  - id: materialcombinationsoffset
    type: u4
  - id: infooffset
    type: u4

instances:
  itemcombinations:
    pos: itemcombinationsoffset
    type: combination_row(num_itemcombinations)
    repeat: expr
    repeat-expr: num_itemcombinations

  materialcombinations:
    pos: materialcombinationsoffset
    type: materials_table(num_categories, num_materials)

  items:
    pos: infooffset
    type:
      switch-on: item_type
      cases:
        '"blade"': blade_info
        '"armor"': armor_info
    repeat: expr
    repeat-expr: num_items

types:
  combination_row:
    params:
      - id: num_data
        type: u4
    seq:
      - id: data
        type: u1
        repeat: expr
        repeat-expr: num_data

  materials_table:
    params:
      - id: num_materials
        type: u4
      - id: num_categories
        type: u4
    seq:
      - id: materials
        type: outer_material_row(num_materials, num_categories)
        repeat: expr
        repeat-expr: num_materials
        
  outer_material_row:
    params:
      - id: num_materials
        type: u4
      - id: num_categories
        type: u4
    seq:
    - id: categories
      type: category_row(num_materials, num_categories)
      repeat: expr
      repeat-expr: num_categories
        
  category_row:
    params:
      - id: num_materials
        type: u4
      - id: num_categories
        type: u4
    seq:
      - id: materials
        type: material_row(num_categories)
        repeat: expr
        repeat-expr: num_materials

  material_row:
    params:
      - id: num_categories
        type: u4
    seq:
      - id: categories
        type: u1
        repeat: expr
        repeat-expr: num_categories
        enum: materials

  blade_info:
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

enums:
  materials:
    0: none
    1: wood
    2: leather
    3: bronze
    4: iron
    5: hagane
    6: silver
    7: damascus
