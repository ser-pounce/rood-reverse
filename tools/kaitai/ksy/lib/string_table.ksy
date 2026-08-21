meta:
  id: string_table
  endian: le
  
params:
  - id: offset
    type: u4
  
seq:
  - id: num_string_refs
    type: s2

instances:
  string_refs:
    type: string_ref
    pos: offset
    repeat: expr
    repeat-expr: num_string_refs

types:
  string_ref:
    seq:
      - id: offset
        type: s2
    instances:
      text:
        io: _parent._io
        pos: offset * 2
        terminator: 0xE7
