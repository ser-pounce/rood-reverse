# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class SceneArm(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(SceneArm, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.num_rooms = self._io.read_u4le()
        self.rooms = []
        for i in range(self.num_rooms):
            self.rooms.append(SceneArm.Room(i, self._io, self, self._root))

        self.room_headers = []
        for i in range(self.num_rooms):
            self.room_headers.append(SceneArm.RoomHeader(self._io, self, self._root))

        self.primitives = []
        for i in range(self.num_rooms):
            self.primitives.append(SceneArm.Primitives(self._io, self, self._root))

        self.room_info = []
        i = 0
        while not self._io.is_eof():
            self.room_info.append(SceneArm.RoomInfo(self._io, self, self._root))
            i += 1



    def _fetch_instances(self):
        pass
        for i in range(len(self.rooms)):
            pass
            self.rooms[i]._fetch_instances()

        for i in range(len(self.room_headers)):
            pass
            self.room_headers[i]._fetch_instances()

        for i in range(len(self.primitives)):
            pass
            self.primitives[i]._fetch_instances()

        for i in range(len(self.room_info)):
            pass
            self.room_info[i]._fetch_instances()


    class Line(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(SceneArm.Line, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.p0 = self._io.read_u1()
            self.p1 = self._io.read_u1()
            self.reserved = self._io.read_bytes(2)
            if not self.reserved == b"\x00\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00\x00", self.reserved, self._io, u"/types/line/seq/2")


        def _fetch_instances(self):
            pass


    class Point(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(SceneArm.Point, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.vertex = self._io.read_u1()
            self.point_id = self._io.read_u1()
            self.flags = self._io.read_u1()
            self.lock = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class Poly3(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(SceneArm.Poly3, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.p0 = self._io.read_u1()
            self.p1 = self._io.read_u1()
            self.p2 = self._io.read_u1()
            self.reserved = self._io.read_bytes(1)
            if not self.reserved == b"\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00", self.reserved, self._io, u"/types/poly3/seq/3")


        def _fetch_instances(self):
            pass


    class Poly4(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(SceneArm.Poly4, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.p0 = self._io.read_u1()
            self.p1 = self._io.read_u1()
            self.p2 = self._io.read_u1()
            self.p3 = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class Primitives(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(SceneArm.Primitives, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_vertices = self._io.read_u4le()
            self.vertices = []
            for i in range(self.num_vertices):
                self.vertices.append(SceneArm.Vertex(self._io, self, self._root))

            self.num_poly3s = self._io.read_u4le()
            self.poly3s = []
            for i in range(self.num_poly3s):
                self.poly3s.append(SceneArm.Poly3(self._io, self, self._root))

            self.num_poly4s = self._io.read_u4le()
            self.poly4s = []
            for i in range(self.num_poly4s):
                self.poly4s.append(SceneArm.Poly4(self._io, self, self._root))

            self.num_floor_lines = self._io.read_u4le()
            self.floor_lines = []
            for i in range(self.num_floor_lines):
                self.floor_lines.append(SceneArm.Line(self._io, self, self._root))

            self.num_wall_lines = self._io.read_u4le()
            self.wall_lines = []
            for i in range(self.num_wall_lines):
                self.wall_lines.append(SceneArm.Line(self._io, self, self._root))

            self.num_points = self._io.read_u4le()
            self.points = []
            for i in range(self.num_points):
                self.points.append(SceneArm.Point(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.vertices)):
                pass
                self.vertices[i]._fetch_instances()

            for i in range(len(self.poly3s)):
                pass
                self.poly3s[i]._fetch_instances()

            for i in range(len(self.poly4s)):
                pass
                self.poly4s[i]._fetch_instances()

            for i in range(len(self.floor_lines)):
                pass
                self.floor_lines[i]._fetch_instances()

            for i in range(len(self.wall_lines)):
                pass
                self.wall_lines[i]._fetch_instances()

            for i in range(len(self.points)):
                pass
                self.points[i]._fetch_instances()



    class Room(KaitaiStruct):
        def __init__(self, index, _io, _parent=None, _root=None):
            super(SceneArm.Room, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.index = index
            self._read()

        def _read(self):
            pass


        def _fetch_instances(self):
            pass

        @property
        def floor_lines(self):
            if hasattr(self, '_m_floor_lines'):
                return self._m_floor_lines

            self._m_floor_lines = self._root.primitives[self.index].floor_lines
            return getattr(self, '_m_floor_lines', None)

        @property
        def map(self):
            if hasattr(self, '_m_map'):
                return self._m_map

            self._m_map = self._root.room_headers[self.index].map
            return getattr(self, '_m_map', None)

        @property
        def name(self):
            if hasattr(self, '_m_name'):
                return self._m_name

            if self.index < len(self._root.room_info):
                pass
                self._m_name = self._root.room_info[self.index].name

            return getattr(self, '_m_name', None)

        @property
        def next(self):
            if hasattr(self, '_m_next'):
                return self._m_next

            if self.index < len(self._root.room_info):
                pass
                self._m_next = self._root.room_info[self.index].next

            return getattr(self, '_m_next', None)

        @property
        def points(self):
            if hasattr(self, '_m_points'):
                return self._m_points

            self._m_points = self._root.primitives[self.index].points
            return getattr(self, '_m_points', None)

        @property
        def poly3s(self):
            if hasattr(self, '_m_poly3s'):
                return self._m_poly3s

            self._m_poly3s = self._root.primitives[self.index].poly3s
            return getattr(self, '_m_poly3s', None)

        @property
        def poly4s(self):
            if hasattr(self, '_m_poly4s'):
                return self._m_poly4s

            self._m_poly4s = self._root.primitives[self.index].poly4s
            return getattr(self, '_m_poly4s', None)

        @property
        def prev(self):
            if hasattr(self, '_m_prev'):
                return self._m_prev

            if self.index < len(self._root.room_info):
                pass
                self._m_prev = self._root.room_info[self.index].prev

            return getattr(self, '_m_prev', None)

        @property
        def vertices(self):
            if hasattr(self, '_m_vertices'):
                return self._m_vertices

            self._m_vertices = self._root.primitives[self.index].vertices
            return getattr(self, '_m_vertices', None)

        @property
        def wall_lines(self):
            if hasattr(self, '_m_wall_lines'):
                return self._m_wall_lines

            self._m_wall_lines = self._root.primitives[self.index].wall_lines
            return getattr(self, '_m_wall_lines', None)

        @property
        def zone(self):
            if hasattr(self, '_m_zone'):
                return self._m_zone

            self._m_zone = self._root.room_headers[self.index].zone
            return getattr(self, '_m_zone', None)


    class RoomHeader(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(SceneArm.RoomHeader, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.reserved = self._io.read_bytes(4)
            if not self.reserved == b"\x00\x00\x00\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00\x00\x00\x00", self.reserved, self._io, u"/types/room_header/seq/0")
            self.size = self._io.read_u4le()
            self.zone = self._io.read_u2le()
            self.map = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class RoomInfo(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(SceneArm.RoomInfo, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.name = self._io.read_bytes(32)
            self.prev = self._io.read_u2le()
            self.next = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class Vertex(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(SceneArm.Vertex, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.vx = self._io.read_s2le()
            self.vy = self._io.read_s2le()
            self.vz = self._io.read_s2le()
            self.reserved = self._io.read_bytes(2)
            if not self.reserved == b"\x00\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00\x00", self.reserved, self._io, u"/types/vertex/seq/3")


        def _fetch_instances(self):
            pass



