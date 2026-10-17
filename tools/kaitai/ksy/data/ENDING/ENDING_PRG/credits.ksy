meta:
  id: credits
  endian: le

seq:
  - id: commands
    type: command
    repeat: until
    repeat-until: _.opcode == opcode::end_of_stream

enums:
  opcode:
    1: wait
    2: render_text
    3: enable_illustrations
    4: render_special
    5: fade_in
    6: fade_out
    7: freeze_scrolling
    8: illustration_timer
    255: end_of_stream

  special_opcode:
    0: copyright
    1: vagrant_story
    2: fin
    3: phantom_pain

types:
  command:
    seq:
      - id: opcode
        type: u1
        enum: opcode
      - id: body
        type:
          switch-on: opcode
          cases:
            'opcode::wait': wait_command
            'opcode::render_text': render_text_command
            'opcode::render_special': render_special_command
            'opcode::illustration_timer': illustration_timer_command

  wait_command:
    seq:
      - id: duration
        type: u1
        doc: The game waits for twice this many frames.

  render_text_command:
    seq:
      - id: len_text
        type: u1
      - id: text
        size: len_text

  render_special_command:
    seq:
      - id: opcode
        type: u1
        enum: special_opcode

  illustration_timer_command:
    seq:
      - id: id
        type: u1
      - id: duration
        type: u2
        doc: The game subtracts 160 from this.
