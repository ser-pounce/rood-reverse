import argparse
import re
import struct
from dataclasses import dataclass
from pathlib import Path
from typing import TextIO

from tools.etc.vsString import decode, encode
from tools.kaitai.parsers.data.SMALL.scene_arm import SceneArm


ROOM_NAME_SIZE = 0x20
ROOM_HEADER_STRUCT = struct.Struct("<IIHH")
ROOM_FOOTER_STRUCT = struct.Struct("<HH")
VERTEX_STRUCT = struct.Struct("<hhhH")
POLY3_STRUCT = struct.Struct("<BBBB")
POLY4_STRUCT = struct.Struct("<BBBB")
LINE_STRUCT = struct.Struct("<BBH")
POINT_STRUCT = struct.Struct("<BBBB")

SECTION_NAMES = {
    "triangles": "triangles",
    "quads": "quads",
    "floor lines": "floor",
    "wall lines": "wall",
}


@dataclass
class RoomData:
    name: str
    zone: int | None
    map: int | None
    prev: int | None
    next: int | None
    vertices: list[tuple[int, int, int]]
    poly3: list[tuple[int, int, int]]
    poly4: list[tuple[int, int, int, int]]
    floor_lines: list[tuple[int, int]]
    wall_lines: list[tuple[int, int]]
    points: list[dict[str, int]]


def clean_room_name(name: str | None) -> str:
    if name is None:
        return "Room"

    for control_code in ("|!0|", "|f4|", "|f6|"):
        name = name.replace(control_code, "")
    return name.strip()


def write_obj_vertices(file: TextIO, vertices) -> None:
    for vertex in vertices:
        file.write(f"v {vertex.vx} {vertex.vy} {vertex.vz}\n")


def write_obj_faces(
    file: TextIO,
    faces,
    face_type: str,
    fields: tuple[str, ...],
    vertex_offset: int,
) -> None:
    if not faces:
        return

    file.write(f"# {face_type}\n")
    for face in faces:
        indices = " ".join(
            str(getattr(face, field) + vertex_offset) for field in fields
        )
        file.write(f"f {indices}\n")


def write_obj_lines(file: TextIO, lines, line_type: str, vertex_offset: int) -> None:
    if not lines:
        return

    file.write(f"# {line_type}\n")
    for line in lines:
        file.write(f"l {line.p0 + vertex_offset} {line.p1 + vertex_offset}\n")


def write_obj_points(file: TextIO, points, vertex_offset: int) -> None:
    if not points:
        return

    file.write("# Points\n")
    for point in points:
        parts = [f"point_id={point.point_id}"]
        if point.flags != 0:
            parts.append(f"flags={point.flags}")
        if point.lock != 0:
            parts.append(f"lock={point.lock}")
        file.write(f"# {' '.join(parts)}\n")
        file.write(f"p {point.vertex + vertex_offset}\n")


def write_room(
    file: TextIO,
    room_index: int,
    room: SceneArm.Room,
    vertex_offset: int,
    jp_font: bool,
) -> int:
    name = (
        decode(list(room.name[:ROOM_NAME_SIZE]), jp_font)
        if room.name is not None
        else None
    )
    prev = room.prev if room.prev is not None else 0
    next_ = room.next if room.next is not None else 0

    file.write(f"o {room_index} {clean_room_name(name)}\n")
    if name is not None:
        file.write(f"# Full name: {name}\n")
    file.write(
        f"# Zone={room.zone} Map={room.map} "
        f"Prev={prev} Next={next_}\n"
    )

    write_obj_vertices(file, room.vertices)
    write_obj_faces(file, room.poly3s, "Triangles", ("p0", "p1", "p2"), vertex_offset)
    write_obj_faces(file, room.poly4s, "Quads", ("p0", "p1", "p2", "p3"), vertex_offset)
    write_obj_lines(file, room.floor_lines, "Floor lines", vertex_offset)
    write_obj_lines(file, room.wall_lines, "Wall lines", vertex_offset)
    write_obj_points(file, room.points, vertex_offset)

    file.write("\n")
    return vertex_offset + len(room.vertices)


def decode_arm(in_path: Path, out_path: Path, jp_font: bool = False) -> None:
    data = SceneArm.from_file(str(in_path))

    with out_path.open("w", encoding="utf-8") as file:
        vertex_offset = 1
        for index, room in enumerate(data.rooms):
            vertex_offset = write_room(file, index, room, vertex_offset, jp_font)


def parse_obj_blocks(in_path: Path) -> list[list[str]]:
    blocks: list[list[str]] = []
    current: list[str] | None = None

    for line in in_path.read_text(encoding="utf-8", errors="ignore").splitlines():
        if line.startswith("o "):
            if current is not None:
                blocks.append(current)
            current = [line]
        elif current is not None:
            current.append(line)

    if current is not None:
        blocks.append(current)
    return blocks


def parse_metadata(comments: list[str]) -> dict[str, int | str | None]:
    metadata: dict[str, int | str | None] = {
        "name": None,
        "zone": None,
        "map": None,
        "prev": None,
        "next": None,
    }

    for comment in comments:
        if comment.startswith("# Full name:"):
            metadata["name"] = comment.removeprefix("# Full name:").strip()
        elif match := re.fullmatch(
            r"# Zone=(\d+) Map=(\d+) Prev=(\d+) Next=(\d+)", comment
        ):
            metadata.update(
                zone=int(match[1]),
                map=int(match[2]),
                prev=int(match[3]),
                next=int(match[4]),
            )
    return metadata


def parse_point_metadata(comment: str) -> dict[str, int]:
    return {
        key: int(value)
        for key, value in (
            token.split("=", 1)
            for token in comment.removeprefix("#").split()
            if "=" in token
        )
    }


def section_for(comment: str) -> str | None:
    comment = comment.lower()
    if "points" in comment or "doors" in comment:
        return "points"
    return next(
        (section for keyword, section in SECTION_NAMES.items() if keyword in comment),
        None,
    )


def local_indices(indices: list[int], vertex_offset: int) -> tuple[int, ...]:
    return tuple(index - vertex_offset - 1 for index in indices)


def parse_room(block: list[str], vertex_offset: int) -> RoomData:
    comments = [line for line in block if line.startswith("#")]
    metadata = parse_metadata(comments)
    vertices: list[tuple[int, int, int]] = []
    poly3: list[tuple[int, int, int]] = []
    poly4: list[tuple[int, int, int, int]] = []
    floor_lines: list[tuple[int, int]] = []
    wall_lines: list[tuple[int, int]] = []
    points: list[dict[str, int]] = []
    point_metadata: list[dict[str, int]] = []
    section = None

    for line in block[1:]:
        line = line.strip()
        if not line:
            continue
        if line.startswith("#"):
            section = section_for(line) or section
            if "point_id=" in line:
                point_metadata.append(parse_point_metadata(line))
            continue

        tokens = line.split()
        kind = tokens[0]
        if kind == "v" and len(tokens) >= 4:
            vertices.append(tuple(round(float(value)) for value in tokens[1:4]))
        elif kind == "f":
            indices = [int(token.split("/")[0]) for token in tokens[1:]]
            local = local_indices(indices, vertex_offset)
            if len(local) == 3:
                poly3.append(local)
            elif len(local) == 4:
                poly4.append(local)
            else:
                raise ValueError(f"Expected a triangle or quad, got {line!r}")
        elif kind == "l":
            line_data = local_indices([int(value) for value in tokens[1:]], vertex_offset)
            if len(line_data) != 2:
                raise ValueError(f"Expected a two-vertex line, got {line!r}")
            (floor_lines if section == "floor" else wall_lines).append(line_data)
        elif kind == "p":
            point = point_metadata[len(points)] if len(points) < len(point_metadata) else {}
            points.append(
                {
                    "vertex": local_indices([int(tokens[1])], vertex_offset)[0],
                    "point_id": point.get("point_id", 0),
                    "flags": point.get("flags", 0),
                    "lock": point.get("lock", 0),
                }
            )

    return RoomData(
        name=metadata["name"] or "",
        zone=metadata["zone"],
        map=metadata["map"],
        prev=metadata["prev"],
        next=metadata["next"],
        vertices=vertices,
        poly3=poly3,
        poly4=poly4,
        floor_lines=floor_lines,
        wall_lines=wall_lines,
        points=points,
    )


def pack_collection(
    records,
    record_struct: struct.Struct,
    transform=lambda record: record,
) -> bytes:
    return struct.pack("<I", len(records)) + b"".join(
        record_struct.pack(*transform(record)) for record in records
    )


def build_graphics_block(room: RoomData) -> bytes:
    return b"".join(
        (
            pack_collection(room.vertices, VERTEX_STRUCT, lambda vertex: (*vertex, 0)),
            pack_collection(room.poly3, POLY3_STRUCT, lambda face: (*face, 0)),
            pack_collection(room.poly4, POLY4_STRUCT),
            pack_collection(room.floor_lines, LINE_STRUCT, lambda line: (*line, 0)),
            pack_collection(room.wall_lines, LINE_STRUCT, lambda line: (*line, 0)),
            pack_collection(
                room.points,
                POINT_STRUCT,
                lambda point: tuple(point[field] for field in ("vertex", "point_id", "flags", "lock")),
            ),
        )
    )


def build_arm(rooms: list[RoomData], jp_font: bool) -> bytes:
    graphics = [build_graphics_block(room) for room in rooms]
    headers = b"".join(
        ROOM_HEADER_STRUCT.pack(
            0,
            len(graphic),
            room.zone or 0,
            room.map or 0,
        )
        for room, graphic in zip(rooms, graphics)
    )
    result = struct.pack("<I", len(rooms)) + headers + b"".join(graphics)

    has_room_info = any(
        room.name or room.prev or room.next
        for room in rooms
    )
    if has_room_info:
        result += b"".join(
            encode(room.name, None, jp_font)[:ROOM_NAME_SIZE].ljust(ROOM_NAME_SIZE, b"\0")
            + ROOM_FOOTER_STRUCT.pack(room.prev or 0, room.next or 0)
            for room in rooms
        )
    return result


def encode_arm(in_path: Path, out_path: Path, jp_font: bool = False) -> None:
    rooms = []
    vertex_offset = 0
    for block in parse_obj_blocks(in_path):
        room = parse_room(block, vertex_offset)
        rooms.append(room)
        vertex_offset += len(room.vertices)

    out_path.write_bytes(build_arm(rooms, jp_font))


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description="Decode or encode an ARM scene file")
    parser.add_argument("input", type=Path)
    parser.add_argument("output", type=Path)
    parser.add_argument(
        "--jp-font",
        action="store_true",
        help="Use the Japanese font table for room names",
    )
    args = parser.parse_args(argv)

    suffix = args.input.suffix.lower()
    if suffix == ".arm":
        decode_arm(args.input, args.output, args.jp_font)
    elif suffix == ".obj":
        encode_arm(args.input, args.output, args.jp_font)
    else:
        parser.error("Could not infer mode from input file extension; expected .ARM or .obj")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
