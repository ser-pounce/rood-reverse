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
      - id: value
        type: s2
    instances:
      description:
        io: _parent._io
        pos: value * 2
        type: description

  description:
    seq:
      - id: text
        terminator: 0xE7
      - id: pad
        type: u1
        if: _io.pos % 2 != 0
        valid: 0xEB
