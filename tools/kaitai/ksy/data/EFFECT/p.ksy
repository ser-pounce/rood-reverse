meta:
  id: p
  file-extension: .P
  endian: le

seq:
  - id: blocks
    type: block
    repeat: until
    repeat-until: _.next_block == 0

enums:
  block_type:
    0: type0
    1: type1
    2: type2
    3: type3
    4: type4
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
      - id: next_block
        type: u2
      - id: type
        type: u2
        enum: block_type
      - id: body
        size: next_block - 4
        type:
          switch-on: type
          cases:
            'block_type::type0': raw_body
            'block_type::type1': type1_body
            'block_type::type2': type2_body
            'block_type::type3': raw_body
            'block_type::type4': type4_body
            'block_type::type5': type5_body
            'block_type::type8': raw_body
            'block_type::type9': raw_body
            'block_type::type10': raw_body
            'block_type::type11': raw_body
            'block_type::type12': raw_body
            'block_type::type13': raw_body
            'block_type::type14': raw_body
        if: next_block != 0

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
        
  type4_body:
    seq:
      - id: num_offsets
        type: u2
      - id: data_offset
        type: u2
      - id: offsets
        type: u1
        repeat: expr
        repeat-expr: num_offsets
      - id: data
        size-eos: true

  type5_body:
    seq:
      - id: num_data
        type: u4
      - id: data
        size: 0xCC
        repeat: expr
        repeat-expr: num_data
