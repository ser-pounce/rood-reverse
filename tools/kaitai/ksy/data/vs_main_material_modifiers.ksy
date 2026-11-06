meta:
  id: vs_main_material_modifiers
  endian: le
  bit-endian: le

seq:
  - id: modifiers
    type: material_modifiers
    repeat: expr
    repeat-expr: 8

types:
  material_modifiers:
    seq:
      - id: human
        type: s1
      - id: beast
        type: s1
      - id: undead
        type: s1
      - id: phantom
        type: s1
      - id: dragon
        type: s1
      - id: evil
        type: s1
      - id: attack_affinities
        type: affinity
      - id: defense_affinities
        type: affinity
      - id: max_dp_mod
        type: s2
      - id: str_mod
        type: s2
      - id: int_mod
        type: s2
      - id: agi_mod
        type: s2
        
  affinity:
    seq:
      - id: phys
        type: s1
      - id: wind
        type: s1
      - id: fire
        type: s1
      - id: earth
        type: s1
      - id: water
        type: s1
      - id: light
        type: s1
      - id: dark
        type: s1
      - id: reserved
        contents: [0]
