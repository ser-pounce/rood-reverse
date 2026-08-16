meta:
  id: string_table
  endian: le

seq:
  - id: num_string_refs
    type: s2
instances:
  string_refs:
    pos: 0
    type: string_ref
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
