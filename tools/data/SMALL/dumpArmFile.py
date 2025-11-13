import struct
import sys
import io
import os
from tools.etc.vsString import decode


# ---------------------------------------------------------------------------
# Utility functions
# ---------------------------------------------------------------------------

def read(fmt, f):
    size = struct.calcsize(fmt)
    data = f.read(size)
    if len(data) != size:
        raise EOFError("Unexpected EOF while reading structure.")
    return struct.unpack(fmt, data)

def read_bytes(f, length):
    data = f.read(length)
    if len(data) != length:
        raise EOFError("Unexpected EOF while reading bytes.")
    return data


# ---------------------------------------------------------------------------
# Parsing functions
# ---------------------------------------------------------------------------

def parse_room_graphics(f, base_offset):
    start = f.tell()
    info = {}

    num_vertices, = read('<I', f)
    verts = []
    for _ in range(num_vertices):
        x, y, z, _pad = read('<hhhH', f)
        verts.append((x, y, z))
    info["vertices"] = verts

    num_poly3, = read('<I', f)
    poly3 = [read('<BBBB', f)[:3] for _ in range(num_poly3)]
    info["poly3"] = poly3

    num_poly4, = read('<I', f)
    poly4 = [read('<BBBB', f) for _ in range(num_poly4)]
    info["poly4"] = poly4

    num_floor, = read('<I', f)
    floors = [read('<BBH', f)[:2] for _ in range(num_floor)]
    info["floor_lines"] = floors

    num_wall, = read('<I', f)
    walls = [read('<BBH', f)[:2] for _ in range(num_wall)]
    info["wall_lines"] = walls

    num_points, = read('<I', f)
    points = []
    for _ in range(num_points):
        vertex_id, exit_zone, flags, lock = read('<BBBB', f)
        points.append({
            "vertex_id": vertex_id,
            "exit_zone": exit_zone,
            "flags": flags,
            "lock": lock
        })
    info["points"] = points

    end = f.tell()
    info["size"] = end - start
    info["offset"] = base_offset + start
    return info


# ---------------------------------------------------------------------------
# OBJ Export
# ---------------------------------------------------------------------------

def export_to_obj(filename, out_name, rooms, main_data, room_names):
    with open(out_name, "w", encoding="utf-8") as out:
        out.write(f"# Source: {filename}\n\n")

        vertex_offset = 1  # OBJ indices are 1-based

        for i, (gfx, main, (name, prev, next_)) in enumerate(zip(rooms, main_data, room_names)):
            # Clean up control codes in room names for display
            room_name = name
            for control_code in ("|!0|", "|f4|", "|f6|"):
                room_name = room_name.replace(control_code, "")
            room_name = room_name.strip()

            out.write(f"o {room_name}\n")
            out.write(f"# Room {i}\n")
            if name != room_name:
                out.write(f"# Full name: {name}\n")
            out.write(f"# Zone={main['zone']} Map={main['map']} Prev={prev} Next={next_}\n")

            # Write vertices
            for (x, y, z) in gfx["vertices"]:
                out.write(f"v {x:.6f} {y:.6f} {z:.6f}\n")

            # Triangles
            if gfx["poly3"]:
                out.write("# Triangles\n")
                for (a, b, c) in gfx["poly3"]:
                    out.write(f"f {a+vertex_offset} {b+vertex_offset} {c+vertex_offset}\n")

            # Quads
            if gfx["poly4"]:
                out.write("# Quads\n")
                for (a, b, c, d) in gfx["poly4"]:
                    out.write(f"f {a+vertex_offset} {b+vertex_offset} {c+vertex_offset} {d+vertex_offset}\n")

            # Floor and Wall lines
            if gfx["floor_lines"]:
                out.write("# Floor lines\n")
                for (a, b) in gfx["floor_lines"]:
                    out.write(f"l {a+vertex_offset} {b+vertex_offset}\n")
            if gfx["wall_lines"]:
                out.write("# Wall lines\n")
                for (a, b) in gfx["wall_lines"]:
                    out.write(f"l {a+vertex_offset} {b+vertex_offset}\n")

            # Points (including doors)
            if gfx["points"]:
                out.write("# Points\n")
                for p in gfx["points"]:
                    v_index = p["vertex_id"] + vertex_offset
                    exit_zone = p["exit_zone"]
                    parts = [f"exit_zone={exit_zone}"]
                    if p["flags"] != 0:
                        parts.append(f"flags={p['flags']}")
                    if p["lock"] != 0:
                        parts.append(f"lock={p['lock']}")
                    comment = " ".join(parts)
                    out.write(f"# {comment}\n")
                    out.write(f"p {v_index}\n")

            out.write("\n")
            vertex_offset += len(gfx["vertices"])


# ---------------------------------------------------------------------------
# Main parser
# ---------------------------------------------------------------------------

def parse_arm(filename, out_name):
    """Parse a full ARM file and export OBJ."""
    with open(filename, "rb") as f:
        data = f.read()
    f = io.BytesIO(data)

    num_rooms, = read('<I', f)

    main_data = []
    for _ in range(num_rooms):
        ram_only, gfx_len, zone, mapno = read('<IIHH', f)
        main_data.append({
            "ram_only": ram_only,
            "gfx_len": gfx_len,
            "zone": zone,
            "map": mapno
        })

    room_graphics = []
    for r in main_data:
        gfx = parse_room_graphics(f, base_offset=0)
        room_graphics.append(gfx)

    room_names = []
    for _ in range(num_rooms):
        raw_name = read_bytes(f, 0x20)
        name_bytes = list(raw_name)
        prev, next_ = read('<HH', f)
        room_names.append((decode(name_bytes), prev, next_))

    # Export OBJ
    export_to_obj(filename, out_name, room_graphics, main_data, room_names)


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: dumpArmFile.py <file.ARM> <out.obj>")
        sys.exit(1)
    parse_arm(sys.argv[1], sys.argv[2])