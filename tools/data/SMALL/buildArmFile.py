#!/usr/bin/env python3
"""
Rebuild a Vagrant Story .ARM binary from an OBJ exported by the dump tool.

Usage:
    python3 buildArmFile.py <input.obj> <output.ARM>

Assumptions:
- OBJ was produced by the exporter used earlier in this conversation.
- 'Full name' comment present (preferred) or 'o <name>' used as fallback.
- Per-room blocks are in the same order as the original ARM.
- ram_only is written as 0 (this script writes 0).
"""

import sys
import struct
import re
from tools.etc.vsString import encode
from tools.data.SMALL.arm_constants import (
    ROOM_NAME_SIZE, VERTEX_FORMAT, POLY3_FORMAT, POLY4_FORMAT,
    LINE_FORMAT, POINT_FORMAT, ROOM_HEADER_FORMAT, ROOM_FOOTER_FORMAT,
    SECTION_KEYWORDS, clamp_byte, pack_collection
)

# ---------------------------------------------------------------------------
# OBJ Parsing
# ---------------------------------------------------------------------------

def parse_obj_blocks(path):
    """Split OBJ file into per-room blocks."""
    with open(path, "r", encoding="utf-8", errors="ignore") as f:
        lines = [ln.rstrip("\n") for ln in f]
    
    blocks = []
    current = None
    
    for ln in lines:
        if ln.startswith("o "):
            if current is not None:
                blocks.append(current)
            current = [ln]
        elif current is not None:
            current.append(ln)
    
    if current is not None:
        blocks.append(current)
    
    return blocks

def extract_metadata_from_comments(comments):
    """Extract room metadata from comment lines."""
    metadata = {
        'full_name': None,
        'zone': None,
        'map_id': None,
        'prev': None,
        'next': None
    }
    
    for c in comments:
        if c.startswith("# Full name:"):
            metadata['full_name'] = c[13:].strip()
        elif m := re.match(r"# Zone=(\d+)\s+Map=(\d+)\s+Prev=(\d+)\s+Next=(\d+)", c):
            metadata['zone'] = int(m[1])
            metadata['map_id'] = int(m[2])
            metadata['prev'] = int(m[3])
            metadata['next'] = int(m[4])
    
    return metadata

def detect_section(line_lower):
    """Detect which section a comment line indicates."""
    for keyword, section_name in SECTION_KEYWORDS.items():
        if keyword in line_lower:
            return section_name
    if 'points' in line_lower or 'doors' in line_lower:
        return 'points'
    return None

def parse_point_metadata(line):
    """Parse metadata from a point comment line."""
    parts = line.lstrip("#").strip().split()
    metadata = {}
    for p in parts:
        if '=' in p:
            key, value = p.split("=", 1)
            try:
                metadata[key] = int(value)
            except ValueError:
                metadata[key] = value
    return metadata

def parse_vertex_line(line):
    """Parse a vertex (v) line."""
    tokens = line.split()
    if len(tokens) >= 4:
        x, y, z = float(tokens[1]), float(tokens[2]), float(tokens[3])
        return (int(round(x)), int(round(y)), int(round(z)))
    return None

def parse_face_line(line):
    """Parse a face (f) line."""
    tokens = line.split()[1:]
    return [int(t.split("/")[0]) for t in tokens]

def parse_line_line(line):
    """Parse a line (l) line."""
    tokens = line.split()[1:]
    return [int(t) for t in tokens]

def parse_point_line(line):
    """Parse a point (p) line."""
    tokens = line.split()[1:]
    return int(tokens[0]) if tokens else None

def convert_to_local_indices(collections, vertex_offset):
    """Convert global indices to local room indices."""
    def to_local(indices):
        return tuple(idx - vertex_offset - 1 for idx in indices)
    
    return {
        key: [to_local(item) for item in coll]
        for key, coll in collections.items()
    }

def parse_block(block, vertex_offset_global):
    """Parse a single OBJ block representing one room."""
    obj_line = block[0]
    comments = [ln for ln in block if ln.startswith("#")]
    
    # Extract metadata
    metadata = extract_metadata_from_comments(comments)
    full_name = metadata['full_name']or ""
    
    # Initialize geometry storage
    vertices = []
    poly3 = []
    poly4 = []
    floor_lines = []
    wall_lines = []
    points_meta = []
    section = None
    
    # Parse geometry
    for ln in block[1:]:
        ln = ln.strip()
        if not ln:
            continue
        
        # Handle comment lines
        if ln.startswith("#"):
            # Check for section headers
            new_section = detect_section(ln.lower())
            if new_section:
                section = new_section
                continue
            
            # Check for point metadata
            if 'exit_zone=' in ln:
                points_meta.append({
                    "meta": parse_point_metadata(ln),
                    "vertex_index_global": None
                })
            continue
        
        # Parse geometry elements
        if ln.startswith("v "):
            vertex = parse_vertex_line(ln)
            if vertex:
                vertices.append(vertex)
        
        elif ln.startswith("f "):
            indices = parse_face_line(ln)
            if len(indices) == 3:
                poly3.append(tuple(indices))
            else:
                poly4.append(tuple(indices))
        
        elif ln.startswith("l "):
            indices = parse_line_line(ln)
            target = floor_lines if section == "floor" else wall_lines
            target.append(tuple(indices))
        
        elif ln.startswith("p "):
            global_idx = parse_point_line(ln)
            if global_idx is not None:
                # Assign to first unassigned point metadata
                assigned = False
                for pm in points_meta:
                    if pm.get("vertex_index_global") is None:
                        pm["vertex_index_global"] = global_idx
                        assigned = True
                        break
                if not assigned:
                    points_meta.append({
                        "meta": {},
                        "vertex_index_global": global_idx
                    })
    
    # Convert to local indices
    local_indices = convert_to_local_indices({
        'poly3': poly3,
        'poly4': poly4,
        'floor_lines': floor_lines,
        'wall_lines': wall_lines
    }, vertex_offset_global)
    
    # Process points with local indices
    points = []
    for pm in points_meta:
        global_idx = pm.get("vertex_index_global")
        if global_idx is None:
            continue
        
        local_idx = global_idx - vertex_offset_global - 1
        meta = pm.get("meta", {})
        points.append({
            "vertex_id": clamp_byte(local_idx),
            "exit_zone": clamp_byte(meta.get("exit_zone", 0)),
            "flags": clamp_byte(meta.get("flags", 0)),
            "lock": clamp_byte(meta.get("lock", 0))
        })
    
    return {
        "name": full_name,
        "zone": metadata['zone'],
        "map": metadata['map_id'],
        "prev": metadata['prev'],
        "next": metadata['next'],
        "vertices": vertices,
        **local_indices,
        "points": points
    }

# ---------------------------------------------------------------------------
# ARM Building
# ---------------------------------------------------------------------------

def build_graphics_block(room):
    """Build binary graphics block for a room."""
    buffer = bytearray()
    
    # Vertices
    buffer = pack_collection(
        buffer, room["vertices"], VERTEX_FORMAT,
        lambda v: (*v, 0)
    )
    
    # Triangles
    buffer = pack_collection(
        buffer, room["poly3"], POLY3_FORMAT,
        lambda t: (*[clamp_byte(i) for i in t], 0)
    )
    
    # Quads
    buffer = pack_collection(
        buffer, room["poly4"], POLY4_FORMAT,
        lambda q: tuple(clamp_byte(i) for i in q[:4])
    )
    
    # Floor lines
    buffer = pack_collection(
        buffer, room["floor_lines"], LINE_FORMAT,
        lambda l: (clamp_byte(l[0]), clamp_byte(l[1]), 0)
    )
    
    # Wall lines
    buffer = pack_collection(
        buffer, room["wall_lines"], LINE_FORMAT,
        lambda l: (clamp_byte(l[0]), clamp_byte(l[1]), 0)
    )
    
    # Points
    buffer = pack_collection(
        buffer, room["points"], POINT_FORMAT,
        lambda p: (p["vertex_id"], p["exit_zone"], p["flags"], p["lock"])
    )
    
    return bytes(buffer)

def write_room_headers(out, rooms, gfx_blocks):
    """Write room header section to ARM file."""
    out.write(struct.pack("<I", len(rooms)))
    for i, room in enumerate(rooms):
        ram_only = 0
        gfx_len = len(gfx_blocks[i])
        zone = room.get("zone") or 0
        mapno = room.get("map") or 0
        out.write(struct.pack(ROOM_HEADER_FORMAT, ram_only, gfx_len, zone, mapno))

def write_room_graphics(out, gfx_blocks):
    """Write graphics blocks to ARM file."""
    for block in gfx_blocks:
        out.write(block)

def write_room_names(out, rooms):
    """Write room name section to ARM file. Only writes rooms with complete metadata."""
    for room in rooms:
        # Only write rooms that have prev/next data
        if room.get("name") == "" and room.get("prev") == 0 and room.get("next") == 0:
            continue
        
        # Encode and pad name
        name = encode(room.get("name", ""), None)[:ROOM_NAME_SIZE]
        if len(name) < ROOM_NAME_SIZE:
            name += b'\x00' * (ROOM_NAME_SIZE - len(name))
        out.write(name)
        
        # Write prev/next pointers
        prev = room.get("prev") or 0
        next_ = room.get("next") or 0
        out.write(struct.pack(ROOM_FOOTER_FORMAT, prev, next_))

def rebuild_arm_from_obj(obj_path, out_path):
    """Rebuild ARM file from OBJ."""
    # Parse OBJ file
    blocks = parse_obj_blocks(obj_path)
    
    # Parse each room block
    rooms = []
    vertex_offset = 0
    for block in blocks:
        parsed = parse_block(block, vertex_offset)
        rooms.append(parsed)
        vertex_offset += len(parsed["vertices"])
    
    # Build graphics blocks
    gfx_blocks = [build_graphics_block(room) for room in rooms]
    
    # Check if ALL rooms have name data (prev/next not None)
    # We need ALL rooms to have names to write the section
    has_complete_names = all(
        room.get("prev") is not None and room.get("next") is not None 
        for room in rooms
    )
    
    # Write ARM file
    with open(out_path, "wb") as out:
        write_room_headers(out, rooms, gfx_blocks)
        write_room_graphics(out, gfx_blocks)
        if has_complete_names:
            write_room_names(out, rooms)

# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <file.obj> <out.ARM>", file=sys.stderr)
        sys.exit(1)
    
    try:
        rebuild_arm_from_obj(sys.argv[1], sys.argv[2])
    except (IOError, ValueError, EOFError) as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()