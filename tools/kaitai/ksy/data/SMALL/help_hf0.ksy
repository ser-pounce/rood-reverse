meta:
  id: help_hf0
  file-extension: HF0
  endian: le
  bit-endian: le
  imports: [/string_table]
  
seq:
  - id: strings_size
    type: u4
  - id: sprites_size
    type: u4
  - id: lines_size
    type: u4
  - id: reserved
    contents: [0, 0, 0, 0]
  - id: help_text
    type: string_table(2)
    size: strings_size

instances:
  content_start:
    value: strings_size + 16
    
  sprite_table:
    type: sprite_table
    pos: content_start
    size: sprites_size
    
  line_table:
    type: line_table
    pos: content_start + sprites_size
    
types:
  sprite_table:
    seq:
      - id: num_sprites
        type: u2
      - id: sprite_refs
        type: sprite_ref
        repeat: expr
        repeat-expr: num_sprites
        
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
