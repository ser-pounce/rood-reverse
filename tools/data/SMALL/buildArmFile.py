import sys, struct, re
from tools.etc.vsString import encode

def parse_obj_blocks(path):
    with open(path, "r", encoding="utf-8", errors="ignore") as f:
        lines = [ln.rstrip("\n") for ln in f]

    blocks = []
    current = None
    for ln in lines:
        if ln.startswith("o "):
            if current is not None:
                blocks.append(current)
            current = [ln]
        else:
            if current is None:
                continue
            current.append(ln)
    if current is not None:
        blocks.append(current)
    return blocks

def parse_block(blk, vertex_offset_global):
    obj_line = blk[0]
    comments = [ln for ln in blk if ln.startswith("#")]
    full_name = None
    zone = None
    map_id = None
    prev = 0
    next_ = 0
    for c in comments:
        if c.startswith("# Full name:"):
            full_name = c[len("# Full name:"):].strip()
        m = re.match(r"# Zone=(\d+)\s+Map=(\d+)\s+Prev=(\d+)\s+Next=(\d+)", c)
        if m:
            zone = int(m.group(1)); map_id = int(m.group(2)); prev = int(m.group(3)); next_ = int(m.group(4))
    if full_name is None:
        full_name = obj_line[2:].strip()

    verts = []
    poly3 = []
    poly4 = []
    floor_lines = []
    wall_lines = []
    points_meta = []
    section = None

    for ln in blk[1:]:
        ln = ln.strip()
        if not ln:
            continue
        if ln.startswith("#"):
            low = ln.lower()
            if "triangles" in low:
                section = "triangles"; continue
            if "quads" in low:
                section = "quads"; continue
            if "floor lines" in low:
                section = "floor"; continue
            if "wall lines" in low:
                section = "wall"; continue
            if "points" in low or "doors" in low:
                section = "points"; continue
            if 'exit_zone=' in ln:
                parts = ln.lstrip("#").strip().split()
                d = {}
                for p in parts:
                    if '=' in p:
                        k,v = p.split("=",1)
                        try:
                            d[k]=int(v)
                        except:
                            d[k]=v
                points_meta.append({"meta": d, "vertex_index_global": None})
                continue
            continue

        if ln.startswith("v "):
            toks = ln.split()
            if len(toks) >= 4:
                x = float(toks[1]); y = float(toks[2]); z = float(toks[3])
                verts.append((int(round(x)), int(round(y)), int(round(z))))
            continue

        if ln.startswith("f "):
            toks = ln.split()[1:]
            idxs = [int(t.split("/")[0]) for t in toks]
            if len(idxs) == 3:
                poly3.append(tuple(idxs))
            else:
                poly4.append(tuple(idxs))
            continue

        if ln.startswith("l "):
            toks = ln.split()[1:]
            idxs = [int(t) for t in toks]
            if section == "floor":
                floor_lines.append(tuple(idxs))
            elif section == "wall":
                wall_lines.append(tuple(idxs))
            else:
                wall_lines.append(tuple(idxs))
            continue

        if ln.startswith("p "):
            toks = ln.split()[1:]
            if toks:
                gi = int(toks[0])
                assigned = False
                for pm in points_meta:
                    if pm.get("vertex_index_global") is None:
                        pm["vertex_index_global"] = gi
                        assigned = True
                        break
                if not assigned:
                    points_meta.append({"meta": {}, "vertex_index_global": gi})
            continue

    def to_local(tup):
        return tuple(idx - vertex_offset_global - 1 for idx in tup)

    poly3_local = [to_local(p) for p in poly3]
    poly4_local = [to_local(p) for p in poly4]
    floor_local = [to_local(p) for p in floor_lines]
    wall_local = [to_local(p) for p in wall_lines]

    points = []
    for pm in points_meta:
        gi = pm.get("vertex_index_global")
        if gi is None:
            continue
        local = gi - vertex_offset_global - 1
        meta = pm.get("meta", {})
        points.append({
            "vertex_id": local & 0xFF,
            "exit_zone": int(meta.get("exit_zone",0)) & 0xFF,
            "flags": int(meta.get("flags",0)) & 0xFF,
            "lock": int(meta.get("lock",0)) & 0xFF
        })

    return {
        "name": full_name,
        "zone": zone,
        "map": map_id,
        "prev": prev,
        "next": next_,
        "vertices": verts,
        "poly3": poly3_local,
        "poly4": poly4_local,
        "floor_lines": floor_local,
        "wall_lines": wall_local,
        "points": points
    }

def build_graphics_block(room):
    b = bytearray()
    b += struct.pack("<I", len(room["vertices"]))
    for (x,y,z) in room["vertices"]:
        b += struct.pack("<hhhH", int(x), int(y), int(z), 0)
    b += struct.pack("<I", len(room["poly3"]))
    for (a,b_,c) in room["poly3"]:
        b += struct.pack("<BBBB", a & 0xFF, b_ & 0xFF, c & 0xFF, 0)
    b += struct.pack("<I", len(room["poly4"]))
    for quad in room["poly4"]:
        if len(quad) >= 4:
            a,b_,c,d = quad[:4]
            b += struct.pack("<BBBB", a & 0xFF, b_ & 0xFF, c & 0xFF, d & 0xFF)
    b += struct.pack("<I", len(room["floor_lines"]))
    for a,b_ in room["floor_lines"]:
        b += struct.pack("<BBH", a & 0xFF, b_ & 0xFF, 0)
    b += struct.pack("<I", len(room["wall_lines"]))
    for a,b_ in room["wall_lines"]:
        b += struct.pack("<BBH", a & 0xFF, b_ & 0xFF, 0)
    b += struct.pack("<I", len(room["points"]))
    for p in room["points"]:
        b += struct.pack("<BBBB", p["vertex_id"] & 0xFF, p["exit_zone"] & 0xFF, p["flags"] & 0xFF, p["lock"] & 0xFF)
    return bytes(b)

def rebuild_arm_from_obj(obj_path, out_path):
    blocks = parse_obj_blocks(obj_path)
    rooms = []
    vertex_offset = 0
    for blk in blocks:
        parsed = parse_block(blk, vertex_offset)
        rooms.append(parsed)
        vertex_offset += len(parsed["vertices"])
    gfx_blocks = [build_graphics_block(r) for r in rooms]

    with open(out_path, "wb") as out:
        out.write(struct.pack("<I", len(rooms)))
        for i, r in enumerate(rooms):
            ram_only = 0
            gfx_len = len(gfx_blocks[i])
            zone = r.get("zone") or 0
            mapno = r.get("map") or 0
            out.write(struct.pack("<I", ram_only))
            out.write(struct.pack("<I", gfx_len))
            out.write(struct.pack("<HH", zone, mapno))
        for blk in gfx_blocks:
            out.write(blk)
        for r in rooms:
            name = encode(r.get("name", ""), None)[:0x20]
            if len(name) < 0x20:
                name += b'\x00' * (0x20 - len(name))
            out.write(name)
            prev = r.get("prev",0) or 0
            next_ = r.get("next",0) or 0
            out.write(struct.pack("<HH", prev, next_))

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: rebuild_arm.py <file.obj> <out.ARM>")
    else:
        rebuild_arm_from_obj(sys.argv[1], sys.argv[2])