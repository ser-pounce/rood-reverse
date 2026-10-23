meta:
  id: vs_main_actions
  endian: le
  bit-endian: le

seq:
  - id: actions
    type: action
    repeat: expr
    repeat-expr: 256

types:
  action:
    seq:
      - id: id
        type: u1
      - id: unk1
        type: u1
      - id: unk2_0
        type: b1
      - id: type
        type: b3
      - id: unk2_4
        type: b4
      - id: cost
        type: u1
      - id: range_x
        type: u1
      - id: range_y
        type: u1
      - id: range_z
        type: u1
      - id: shape
        type: b3
      - id: angle
        type: b5
      - id: aoe_0
        type: u1
      - id: aoe_8
        type: u1
      - id: aoe_16
        type: u1
      - id: aoe_24
        type: u1
      - id: flags_0
        type: u1
      - id: flags_d_0
        type: b4
      - id: flags_d_4
        type: b2
      - id: flags_d_6
        type: b1
      - id: unlocked
        type: b1
      - id: flags_e
        type: action_flags
      - id: unk10
        type: s4
      - id: hit_params
        type: hit_params
        repeat: expr
        repeat-expr: 2
      - id: name
        size: 24

  action_flags:
    seq:
      - id: unk0
        type: b4
      - id: unk4
        type: b1
      - id: unk5
        type: b1
      - id: unk6
        type: b1
      - id: unk7
        type: b1
      - id: unk8
        type: b4
      - id: unk12
        type: b1
      - id: unk13
        type: b1
      - id: unk14
        type: b2

  hit_params:
    seq:
      - id: effect
        type: b7
      - id: prerequisite_function
        type: b6
      - id: hit_function
        type: b3
      - id: stat_calculator
        type: b6
      - id: stat_factor
        type: b5
      - id: type
        type: b2
      - id: affinity
        type: b3
