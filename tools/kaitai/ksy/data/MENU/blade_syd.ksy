meta:
  id: blade_syd
  file-extension: SYD
  endian: le
  imports: [/syd]

seq:
  - id: offsets
    type: syd::offsets

instances:
    
  combinations:
    pos: offsets.combinations
    type: syd::square_array(96)

  materialcombinations:
    pos: offsets.materials
    type: syd::materials_table(5, 10)
    
  info:
    pos: offsets.info
    type: info
    repeat: expr
    repeat-expr: 96

types:        
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
