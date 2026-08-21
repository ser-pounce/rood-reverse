meta:
  id: mon_bin
  file-extension: BIN
  endian: le
  imports: [/string_table]

seq:
  - id: monsters
    type: monster(_index)
    repeat: expr
    repeat-expr: 150
  - id: descriptions
    type: string_table(0)
    size-eos: true

types:
  monster:
    params:
      - id: index
        type: s4
    seq:
      - id: zudid
        type: s2
      - id: classid
        type: s2
      - id: killflagsoffset
        type: s2
      - id: killflagscount
        type: s2
      - id: reserved
        contents: [0, 0, 0, 0, 0, 0, 0, 0]
      - id: name
        size: 28
    instances:
      description:
        value: _root.descriptions.string_refs[index].text
