# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.BATTLE import img


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class SystemDat(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(SystemDat, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.offsets = []
        for i in range(8):
            self.offsets.append(self._io.read_u4le())



    def _fetch_instances(self):
        pass
        for i in range(len(self.offsets)):
            pass

        _ = self.base_effect
        if hasattr(self, '_m_base_effect'):
            pass
            self._m_base_effect._fetch_instances()

        _ = self.clut0
        if hasattr(self, '_m_clut0'):
            pass
            self._m_clut0._fetch_instances()

        _ = self.clut1
        if hasattr(self, '_m_clut1'):
            pass
            self._m_clut1._fetch_instances()

        _ = self.font
        if hasattr(self, '_m_font'):
            pass
            self._m_font._fetch_instances()

        _ = self.grid0
        if hasattr(self, '_m_grid0'):
            pass
            self._m_grid0._fetch_instances()

        _ = self.grid1
        if hasattr(self, '_m_grid1'):
            pass
            self._m_grid1._fetch_instances()

        _ = self.ui_tex0
        if hasattr(self, '_m_ui_tex0'):
            pass
            self._m_ui_tex0._fetch_instances()

        _ = self.ui_tex1
        if hasattr(self, '_m_ui_tex1'):
            pass
            self._m_ui_tex1._fetch_instances()


    class Clut(KaitaiStruct):
        def __init__(self, max_size, _io, _parent=None, _root=None):
            super(SystemDat.Clut, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.max_size = max_size
            self._read()

        def _read(self):
            self.w = self._io.read_s2le()
            self.h = self._io.read_s2le()
            self._raw_pixels = self._io.read_bytes(self.len_pixels)
            _io__raw_pixels = KaitaiStream(BytesIO(self._raw_pixels))
            self.pixels = img.Img.Clut(_io__raw_pixels)


        def _fetch_instances(self):
            pass
            self.pixels._fetch_instances()

        @property
        def len_pixels(self):
            if hasattr(self, '_m_len_pixels'):
                return self._m_len_pixels

            self._m_len_pixels = (self.max_size if  ((self.max_size > 0) and (self.max_size < (self.w * self.h) * 2))  else (self.w * self.h) * 2)
            return getattr(self, '_m_len_pixels', None)


    class Font(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(SystemDat.Font, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self._raw_table0 = self._io.read_bytes(28672)
            _io__raw_table0 = KaitaiStream(BytesIO(self._raw_table0))
            self.table0 = img.Img.Indices(0, _io__raw_table0)
            self._raw_table1 = self._io.read_bytes(28672)
            _io__raw_table1 = KaitaiStream(BytesIO(self._raw_table1))
            self.table1 = img.Img.Indices(0, _io__raw_table1)
            self._raw_table2 = self._io.read_bytes(20224)
            _io__raw_table2 = KaitaiStream(BytesIO(self._raw_table2))
            self.table2 = img.Img.Indices(0, _io__raw_table2)


        def _fetch_instances(self):
            pass
            self.table0._fetch_instances()
            self.table1._fetch_instances()
            self.table2._fetch_instances()


    class Image(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(SystemDat.Image, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.header = img.Img.Rect(self._io)
            self._raw_pixels = self._io.read_bytes((self.header.w * self.header.h) * 2)
            _io__raw_pixels = KaitaiStream(BytesIO(self._raw_pixels))
            self.pixels = img.Img.Indices(0, _io__raw_pixels)


        def _fetch_instances(self):
            pass
            self.header._fetch_instances()
            self.pixels._fetch_instances()


    @property
    def base_effect(self):
        if hasattr(self, '_m_base_effect'):
            return self._m_base_effect

        _pos = self._io.pos()
        self._io.seek(self.offsets[5])
        self._m_base_effect = SystemDat.Image(self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_base_effect', None)

    @property
    def clut0(self):
        if hasattr(self, '_m_clut0'):
            return self._m_clut0

        _pos = self._io.pos()
        self._io.seek(self.offsets[2])
        self._m_clut0 = SystemDat.Clut(32, self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_clut0', None)

    @property
    def clut1(self):
        if hasattr(self, '_m_clut1'):
            return self._m_clut1

        _pos = self._io.pos()
        self._io.seek(self.offsets[6])
        self._m_clut1 = SystemDat.Clut(0, self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_clut1', None)

    @property
    def font(self):
        if hasattr(self, '_m_font'):
            return self._m_font

        _pos = self._io.pos()
        self._io.seek(self.offsets[7])
        self._m_font = SystemDat.Font(self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_font', None)

    @property
    def grid0(self):
        if hasattr(self, '_m_grid0'):
            return self._m_grid0

        _pos = self._io.pos()
        self._io.seek(self.offsets[3])
        self._m_grid0 = SystemDat.Image(self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_grid0', None)

    @property
    def grid1(self):
        if hasattr(self, '_m_grid1'):
            return self._m_grid1

        _pos = self._io.pos()
        self._io.seek(self.offsets[4])
        self._m_grid1 = SystemDat.Image(self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_grid1', None)

    @property
    def ui_tex0(self):
        if hasattr(self, '_m_ui_tex0'):
            return self._m_ui_tex0

        _pos = self._io.pos()
        self._io.seek(self.offsets[0])
        self._m_ui_tex0 = SystemDat.Image(self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_ui_tex0', None)

    @property
    def ui_tex1(self):
        if hasattr(self, '_m_ui_tex1'):
            return self._m_ui_tex1

        _pos = self._io.pos()
        self._io.seek(self.offsets[1])
        self._m_ui_tex1 = SystemDat.Image(self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_ui_tex1', None)


