# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.SMALL import string_table


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class HelpHf0(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(HelpHf0, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.len_help_text = self._io.read_u4le()
        self.len_sprite_table = self._io.read_u4le()
        self.lines_size = self._io.read_u4le()
        self.reserved = self._io.read_bytes(4)
        if not self.reserved == b"\x00\x00\x00\x00":
            raise kaitaistruct.ValidationNotEqualError(b"\x00\x00\x00\x00", self.reserved, self._io, u"/seq/3")
        self._raw_help_text = self._io.read_bytes(self.len_help_text)
        _io__raw_help_text = KaitaiStream(BytesIO(self._raw_help_text))
        self.help_text = string_table.StringTable(2, _io__raw_help_text)


    def _fetch_instances(self):
        pass
        self.help_text._fetch_instances()
        _ = self.line_table
        if hasattr(self, '_m_line_table'):
            pass
            self._m_line_table._fetch_instances()

        _ = self.sprite_table
        if hasattr(self, '_m_sprite_table'):
            pass
            self._m_sprite_table._fetch_instances()


    class Animation(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(HelpHf0.Animation, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.enabled = self._io.read_u2le()
            self.frame_mask = self._io.read_u2le()
            self.frame_duration = self._io.read_s2le()
            self.repeat = self._io.read_s2le()
            self.reserved = self._io.read_bytes(8)
            if not self.reserved == b"\x00\x00\x00\x00\x00\x00\x00\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00\x00\x00\x00\x00\x00\x00\x00", self.reserved, self._io, u"/types/animation/seq/4")


        def _fetch_instances(self):
            pass


    class LineData(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(HelpHf0.LineData, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.animation = HelpHf0.Animation(self._io, self, self._root)
            self.x0 = self._io.read_s2le()
            self.y0 = self._io.read_s2le()
            self.x1 = self._io.read_s2le()
            self.y1 = self._io.read_s2le()
            self.r = self._io.read_u1()
            self.g = self._io.read_u1()
            self.b = self._io.read_u1()
            self.reserved = self._io.read_bytes(1)
            if not self.reserved == b"\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00", self.reserved, self._io, u"/types/line_data/seq/8")


        def _fetch_instances(self):
            pass
            self.animation._fetch_instances()


    class LineTable(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(HelpHf0.LineTable, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_lines = self._io.read_u2le()
            self.lines = []
            for i in range(self.num_lines):
                self.lines.append(HelpHf0.LineData(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.lines)):
                pass
                self.lines[i]._fetch_instances()



    class SpriteData(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(HelpHf0.SpriteData, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.animation = HelpHf0.Animation(self._io, self, self._root)
            self.x = self._io.read_s2le()
            self.y = self._io.read_s2le()
            self.w = self._io.read_s2le()
            self.h = self._io.read_s2le()
            self.num_sprites = self._io.read_s2le()
            self.colors = self._io.read_s2le()
            self.clut_x = self._io.read_bits_int_le(4)
            self.clut_y = self._io.read_bits_int_le(12)
            self.sprites = []
            for i in range(self.num_sprites):
                self.sprites.append(self._io.read_s2le())



        def _fetch_instances(self):
            pass
            self.animation._fetch_instances()
            for i in range(len(self.sprites)):
                pass



    class SpriteRef(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(HelpHf0.SpriteRef, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.offset = self._io.read_s2le()


        def _fetch_instances(self):
            pass
            _ = self.sprite
            if hasattr(self, '_m_sprite'):
                pass
                self._m_sprite._fetch_instances()


        @property
        def sprite(self):
            if hasattr(self, '_m_sprite'):
                return self._m_sprite

            io = self._parent._io
            _pos = io.pos()
            io.seek(self.offset * 2)
            self._m_sprite = HelpHf0.SpriteData(io, self, self._root)
            io.seek(_pos)
            return getattr(self, '_m_sprite', None)


    class SpriteTable(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(HelpHf0.SpriteTable, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_sprite_refs = self._io.read_u2le()
            self.sprite_refs = []
            for i in range(self.num_sprite_refs):
                self.sprite_refs.append(HelpHf0.SpriteRef(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.sprite_refs)):
                pass
                self.sprite_refs[i]._fetch_instances()



    @property
    def content_start(self):
        if hasattr(self, '_m_content_start'):
            return self._m_content_start

        self._m_content_start = self.len_help_text + 16
        return getattr(self, '_m_content_start', None)

    @property
    def line_table(self):
        if hasattr(self, '_m_line_table'):
            return self._m_line_table

        _pos = self._io.pos()
        self._io.seek(self.content_start + self.len_sprite_table)
        self._m_line_table = HelpHf0.LineTable(self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_line_table', None)

    @property
    def sprite_table(self):
        if hasattr(self, '_m_sprite_table'):
            return self._m_sprite_table

        _pos = self._io.pos()
        self._io.seek(self.content_start)
        self._raw__m_sprite_table = self._io.read_bytes(self.len_sprite_table)
        _io__raw__m_sprite_table = KaitaiStream(BytesIO(self._raw__m_sprite_table))
        self._m_sprite_table = HelpHf0.SpriteTable(_io__raw__m_sprite_table, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_sprite_table', None)


