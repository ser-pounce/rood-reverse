meta:
  id: scene_arm
  file-extension: ARM
  endian: le
  
seq:
  - id: num_rooms
    type: u4
  - id: rooms
    type: room(_index)
    repeat: expr
    repeat-expr: num_rooms
  - id: room_headers
    type: room_header
    repeat: expr
    repeat-expr: num_rooms
  - id: primitives
    type: primitives
    repeat: expr
    repeat-expr: num_rooms
  - id: room_info
    type: room_info
    repeat: eos
    
types:
  room:
    params:
      - id: index
        type: s4
    instances:
      zone:
        value: _root.room_headers[index].zone
      map:
        value: _root.room_headers[index].map
      vertices:
        value: _root.primitives[index].vertices
      poly3s:
        value: _root.primitives[index].poly3s
      poly4s:
        value: _root.primitives[index].poly4s
      floor_lines:
        value: _root.primitives[index].floor_lines
      wall_lines:
        value: _root.primitives[index].wall_lines
      points:
        value: _root.primitives[index].points
      name:
        if: index < _root.room_info.size
        value: _root.room_info[index].name
      prev:
        if: index < _root.room_info.size
        value: _root.room_info[index].prev
      next:
        if: index < _root.room_info.size
        value: _root.room_info[index].next
    
  room_header:
    seq:
      - id: reserved
        contents: [0, 0, 0, 0]
      - id: size
        type: u4
      - id: zone
        type: u2
      - id: map
        type: u2
      
  primitives:
    seq:
      - id: num_vertices
        type: u4
      - id: vertices
        type: vertex
        repeat: expr
        repeat-expr: num_vertices
      - id: num_poly3s
        type: u4
      - id: poly3s
        type: poly3
        repeat: expr
        repeat-expr: num_poly3s
      - id: num_poly4s
        type: u4
      - id: poly4s
        type: poly4
        repeat: expr
        repeat-expr: num_poly4s
      - id: num_floor_lines
        type: u4
      - id: floor_lines
        type: line
        repeat: expr
        repeat-expr: num_floor_lines
      - id: num_wall_lines
        type: u4
      - id: wall_lines
        type: line
        repeat: expr
        repeat-expr: num_wall_lines
      - id: num_points
        type: u4
      - id: points
        type: point
        repeat: expr
        repeat-expr: num_points
    
  vertex:
    seq:
      - id: vx
        type: s2
      - id: vy
        type: s2
      - id: vz
        type: s2
      - id: reserved
        contents: [0, 0]
        
  poly3:
    seq:
      - id: p0
        type: u1
      - id: p1
        type: u1
      - id: p2
        type: u1
      - id: reserved
        contents: [0]
        
  poly4:
    seq:
      - id: p0
        type: u1
      - id: p1
        type: u1
      - id: p2
        type: u1
      - id: p3
        type: u1
        
  line:
    seq:
      - id: p0
        type: u1
      - id: p1
        type: u1
      - id: reserved
        contents: [0, 0]
        
  point:
    seq:
      - id: vertex
        type: u1
      - id: point_id
        type: u1
      - id: flags
        type: u1
      - id: lock
        type: u1
        
  room_info:
    seq:
      - id: name
        size: 32
      - id: prev
        type: u2
      - id: next
        type: u2