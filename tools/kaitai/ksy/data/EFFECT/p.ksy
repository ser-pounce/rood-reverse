meta:
  id: p
  file-extension: .P
  endian: le
  bit-endian: le

seq:
  - id: blocks
    type: block
    repeat: until
    repeat-until: _.size == 0

enums:
  block_type:
    0: type0
    1: type1
    2: type2
    3: type3
    4: curves
    5: type5
    8: type8
    9: type9
    10: type10
    11: type11
    12: type12
    13: type13
    14: type14

types:
  block:
    seq:
      - id: size
        type: u2
      - id: type
        type: u2
        enum: block_type
      - id: body
        size: size - 4
        type:
          switch-on: type
          cases:
            'block_type::type0': raw_body
            'block_type::type1': type1_body
            'block_type::type2': type2_body
            'block_type::type3': raw_body
            'block_type::curves': curves
            'block_type::type5': type5_body
            'block_type::type8': raw_body
            'block_type::type9': raw_body
            'block_type::type10': raw_body
            'block_type::type11': type11_body
            'block_type::type12': raw_body
            'block_type::type13': raw_body
        if: size != 0

  raw_body:
    seq:
      - id: data
        size-eos: true

  type1_body:
    seq:
      - id: num_table_offsets
        type: u2
      - id: data_offset
        type: u2
      - id: table_offsets
        type: u4
        repeat: expr
        repeat-expr: num_table_offsets
      - id: data
        size-eos: true
        
  type2_body:
    seq:
      - id: num_offsets
        type: u4
      - id: offsets
        type: u2 
        repeat: expr
        repeat-expr: num_offsets
      - id: data
        size-eos: true
        
  curves:
    seq:
      - id: num_curves
        type: u2
      - id: data_offset
        type: u2
      - id: sizes
        type: u1
        repeat: expr
        repeat-expr: num_curves
      - id: curves
        type: block_chunk(_index)
        repeat: expr
        repeat-expr: num_curves

  block_chunk:
    params:
      - id: idx
        type: u4
    seq:
      - id: body
        size: _parent.sizes[idx]

  type5_body:
    seq:
      - id: num_data
        type: u4
      - id: data
        type: func_800fa098_arg0
        repeat: expr
        repeat-expr: num_data
        
  func_800fa098_arg0:
    seq:
      - id: unk0
        type: u1
      - id: unk1
        type: u1
      - id: unk2
        type: u1
      - id: unk3
        type: u1
      - id: flags
        type: b26
      - id: transparency_curve
        type: b6
      - id: unk8
        type: u1
      - id: unk9
        type: u1
      - id: unka
        type: u1
      - id: unkb
        type: u1
      - id: unkc
        type: u1
      - id: unkd
        type: u1
      - id: unke
        type: u1
      - id: unkf
        type: u1
      - id: unk10
        type: u1
      - id: unk11
        type: u1
      - id: unk12
        type: u1
      - id: unk13
        type: u1
      - id: unk14
        type: u1
      - id: unk15
        type: u1
      - id: unk16
        type: u1
      - id: unk17
        type: u1
      - id: unk18
        type: array1d(6)
      - id: unk24
        type: array1d(6)
      - id: unk30
        type: array1d(2)
      - id: unk34
        type: array2d(8, 6)
      - id: unk94
        type: array2d(5, 4)
      - id: unkbc
        type: s4
      - id: unkc0
        type: array1d(2)
      - id: unkc4
        type: u1
      - id: unkc5
        type: u1
      - id: unkc6
        type: u1
      - id: unkc7
        type: u1
      - id: unkc8
        type: u1
      - id: unkc9
        type: u1
      - id: unkca
        type: u1
      - id: unkcb
        type: u1
        
  type11_body:
    seq:
      - id: num_offsets
        type: u4
      - id: offsets
        type: u2
        repeat: expr
        repeat-expr: num_offsets
      - id: data
        size-eos: true
        
  array1d:
    params:
      - id: num_value
        type: s4
    seq:
      - id: value
        type: s2
        repeat: expr
        repeat-expr: num_value

  array2d:
    params:
      - id: num_rows
        type: s4
      - id: cols
        type: s4
    seq:
      - id: rows
        type: array1d(cols)
        repeat: expr
        repeat-expr: num_rows
