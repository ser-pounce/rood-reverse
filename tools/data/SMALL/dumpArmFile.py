"""
Parse and export Vagrant Story .ARM file geometry as Wavefront OBJ.

Usage:
    python3 dumpArmFile.py <file.ARM> <out.obj>

Based on: https://datacrystal.tcrf.net/wiki/Vagrant_Story/ARM_files
"""

import sys
import io
from tools.etc.vsString import decode
from tools.data.SMALL.arm_constants import (
    ROOM_NAME_SIZE, VERTEX_FORMAT, POLY3_FORMAT, POLY4_FORMAT,
    LINE_FORMAT, POINT_FORMAT, ROOM_HEADER_FORMAT, ROOM_FOOTER_FORMAT,
    read_struct, read_bytes
)

# ---------------------------------------------------------------------------
# Parsing functions
# ---------------------------------------------------------------------------

def parse_room_graphics(f):
    """Parse graphics block for a single room."""
    info = {}
    
    # Vertices
    num_vertices, = read_struct('<I', f)
    info["vertices"] = [
        read_struct(VERTEX_FORMAT, f)[:3] 
        for _ in range(num_vertices)
    ]
    
    # Triangles
    num_poly3, = read_struct('<I', f)
    info["poly3"] = [
        read_struct(POLY3_FORMAT, f)[:3] 
        for _ in range(num_poly3)
    ]
    
    # Quads
    num_poly4, = read_struct('<I', f)
    info["poly4"] = [
        read_struct(POLY4_FORMAT, f) 
        for _ in range(num_poly4)
    ]
    
    # Floor lines
    num_floor, = read_struct('<I', f)
    info["floor_lines"] = [
        read_struct(LINE_FORMAT, f)[:2] 
        for _ in range(num_floor)
    ]
    
    # Wall lines
    num_wall, = read_struct('<I', f)
    info["wall_lines"] = [
        read_struct(LINE_FORMAT, f)[:2] 
        for _ in range(num_wall)
    ]
    
    # Points (doors, etc.)
    num_points, = read_struct('<I', f)
    points = []
    for _ in range(num_points):
        vertex_id, point_id, flags, lock = read_struct(POINT_FORMAT, f)
        points.append({
            "vertex_id": vertex_id,
            "point_id": point_id,
            "flags": flags,
            "lock": lock
        })
    info["points"] = points
    
    return info

# ---------------------------------------------------------------------------
# OBJ Export
# ---------------------------------------------------------------------------

def clean_room_name(name):
    """Remove control codes from room name."""
    if name is None:
        return "Room"
    for control_code in ("|!0|", "|f4|", "|f6|"):
        name = name.replace(control_code, "")
    return name.strip()

def write_obj_vertices(out, vertices):
    """Write vertex data to OBJ file."""
    for x, y, z in vertices:
        out.write(f"v {x:.6f} {y:.6f} {z:.6f}\n")

def write_obj_faces(out, faces, face_type, offset):
    """Write face data (triangles or quads) to OBJ file."""
    if not faces:
        return
    
    out.write(f"# {face_type}\n")
    for face in faces:
        indices = " ".join(str(idx + offset) for idx in face)
        out.write(f"f {indices}\n")

def write_obj_lines(out, lines, line_type, offset):
    """Write line data to OBJ file."""
    if not lines:
        return
    
    out.write(f"# {line_type}\n")
    for a, b in lines:
        out.write(f"l {a + offset} {b + offset}\n")

def write_obj_points(out, points, offset):
    """Write point data to OBJ file."""
    if not points:
        return
    
    out.write("# Points\n")
    for p in points:
        v_index = p["vertex_id"] + offset
        parts = [f"point_id={p['point_id']}"]
        if p["flags"] != 0:
            parts.append(f"flags={p['flags']}")
        if p["lock"] != 0:
            parts.append(f"lock={p['lock']}")
        out.write(f"# {' '.join(parts)}\n")
        out.write(f"p {v_index}\n")

def export_room_to_obj(out, room_idx, gfx, main, name_data, vertex_offset):
    """Export a single room to OBJ format."""
    name, prev, next_ = name_data
    clean_name = clean_room_name(name)
    
    # Room header
    out.write(f"o {clean_name} {room_idx}\n")
    out.write(f"# Room {room_idx}\n")
    if name is not None:
        out.write(f"# Full name: {name}\n")
    out.write(f"# Zone={main['zone']} Map={main['map']} Prev={prev} Next={next_}\n")
    
    # Geometry
    write_obj_vertices(out, gfx["vertices"])
    write_obj_faces(out, gfx["poly3"], "Triangles", vertex_offset)
    write_obj_faces(out, gfx["poly4"], "Quads", vertex_offset)
    write_obj_lines(out, gfx["floor_lines"], "Floor lines", vertex_offset)
    write_obj_lines(out, gfx["wall_lines"], "Wall lines", vertex_offset)
    write_obj_points(out, gfx["points"], vertex_offset)
    
    out.write("\n")
    return vertex_offset + len(gfx["vertices"])

def export_to_obj(filename, out_name, rooms, main_data, room_names):
    """Export all rooms to a single OBJ file."""
    with open(out_name, "w", encoding="utf-8") as out:
        out.write(f"# Source: {filename}\n\n")
        
        vertex_offset = 1  # OBJ indices are 1-based
        for i, (gfx, main, name_data) in enumerate(zip(rooms, main_data, room_names)):
            vertex_offset = export_room_to_obj(
                out, i, gfx, main, name_data, vertex_offset
            )

# ---------------------------------------------------------------------------
# Main parser
# ---------------------------------------------------------------------------

def read_arm_binary(filename: str):
    """Read ARM file into BytesIO object."""
    with open(filename, "rb") as f:
        return io.BytesIO(f.read())

def parse_arm(in_name: str, out_name: str):
    """Parse a full ARM file and export OBJ."""
    f = read_arm_binary(in_name)
    
    # Read number of rooms
    num_rooms, = read_struct('<I', f)
    
    # Read main data for all rooms
    main_data = []
    for _ in range(num_rooms):
        ram_only, gfx_len, zone, mapno = read_struct(ROOM_HEADER_FORMAT, f)
        main_data.append({
            "ram_only": ram_only,
            "gfx_len": gfx_len,
            "zone": zone,
            "map": mapno
        })
    
    # Read graphics for all rooms
    room_graphics = [parse_room_graphics(f) for _ in range(num_rooms)]
    
    # Read room names (may be missing if file ends prematurely)
    room_names = []
    for i in range(num_rooms):
        try:
            raw_name = read_bytes(f, ROOM_NAME_SIZE)
            prev, next_ = read_struct(ROOM_FOOTER_FORMAT, f)
            room_names.append((decode(list(raw_name)), prev, next_))
        except EOFError:
            # File ended before all names - fill remaining with defaults
            room_names.append((None, 0, 0))
    
    # Export OBJ
    export_to_obj(in_name, out_name, room_graphics, main_data, room_names)

# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <file.ARM> <out.obj>", file=sys.stderr)
        sys.exit(1)
    
    try:
        parse_arm(sys.argv[1], sys.argv[2])
    except (IOError, EOFError, ValueError) as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()