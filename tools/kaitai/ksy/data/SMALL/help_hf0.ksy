meta:
  id: help_hf0
  file-extension: HF0
  endian: le
  bit-endian: le
  imports: [/string_table]
  
seq:
  - id: len_help_text
    type: u4
  - id: len_sprite_table
    type: u4
  - id: lines_size
    type: u4
  - id: reserved
    contents: [0, 0, 0, 0]
  - id: help_text
    type: string_table(2)
    size: len_help_text

instances:
  content_start:
    value: len_help_text + 16
    
  sprite_table:
    type: sprite_table
    pos: content_start
    size: len_sprite_table
    
  line_table:
    type: line_table
    pos: content_start + len_sprite_table
    
types:
  sprite_table:
    seq:
      - id: num_sprite_refs
        type: u2
      - id: sprite_refs
        type: sprite_ref
        repeat: expr
        repeat-expr: num_sprite_refs
        
  sprite_ref:
    seq:
      - id: offset
        type: s2
    instances:
      sprite:
        io: _parent._io
        pos: offset * 2
        type: sprite_data
            
  sprite_data:
    seq:
      - id: animation
        type: animation
      - id: x
        type: s2
      - id: y
        type: s2
      - id: w
        type: s2
      - id: h
        type: s2
      - id: num_sprites
        type: s2
      - id: colors
        type: s2
      - id: clut_x
        type: b4
      - id: clut_y
        type: b12
      - id: sprites
        type: s2
        repeat: expr
        repeat-expr: num_sprites
        
  line_table:
    seq:
      - id: num_lines
        type: u2
      - id: lines
        type: line_data
        repeat: expr
        repeat-expr: num_lines
            
  line_data:
    seq:
      - id: animation
        type: animation
      - id: x0
        type: s2
      - id: y0
        type: s2
      - id: x1
        type: s2
      - id: y1
        type: s2
      - id: r
        type: u1
      - id: g
        type: u1
      - id: b
        type: u1
      - id: reserved
        contents: [0]
        
  animation:
    seq:
      - id: enabled
        type: u2
      - id: frame_mask
        type: u2
      - id: frame_duration
        type: s2
      - id: repeat
        type: s2
      - id: reserved
        contents: [0, 0, 0, 0, 0, 0, 0, 0]
