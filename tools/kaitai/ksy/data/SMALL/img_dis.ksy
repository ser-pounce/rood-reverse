meta:
  id: img_dis
  file-extension: DIS
  endian: le
  bit-endian: le
  imports: [/img]

seq:
  - id: sections
    type: section
    repeat: eos

types:
  section:
    instances:
      magic:
        pos: _io.pos
        type: u4
    seq:
      - id: body
        type:
          switch-on: magic
          cases:
            0x10: img::tim
            _: iq_table

  iq_table:
    seq:
      - id: iq_data
        type: iq_data
        repeat: eos

  iq_data:
    seq:
      - id: zone_id
        type: u2
      - id: map_id
        type: u2
      - id: par_time
        type: u2
      - id: rank_cap
        type: u2
