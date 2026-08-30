# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
import tools.libdata.rle


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class Img(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(Img, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        pass


    def _fetch_instances(self):
        pass

    class Clut(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Img.Clut, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.colors = []
            i = 0
            while not self._io.is_eof():
                self.colors.append(Img.Rgb5(self._io, self, self._root))
                i += 1



        def _fetch_instances(self):
            pass
            for i in range(len(self.colors)):
                pass
                self.colors[i]._fetch_instances()



    class Clutsection(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Img.Clutsection, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.len = self._io.read_u4le()
            self.rect = Img.Rect(self._io, self, self._root)
            self._raw_clut = self._io.read_bytes(self.len - 12)
            _io__raw_clut = KaitaiStream(BytesIO(self._raw_clut))
            self.clut = Img.Clut(_io__raw_clut, self, self._root)


        def _fetch_instances(self):
            pass
            self.rect._fetch_instances()
            self.clut._fetch_instances()


    class Indices(KaitaiStruct):
        def __init__(self, mode, _io, _parent=None, _root=None):
            super(Img.Indices, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.mode = mode
            self._read()

        def _read(self):
            self.indices = []
            i = 0
            while not self._io.is_eof():
                _on = self.mode
                if _on == 0:
                    pass
                    self.indices.append(self._io.read_bits_int_le(4))
                elif _on == 1:
                    pass
                    self.indices.append(self._io.read_u1())
                elif _on == 2:
                    pass
                    self.indices.append(Img.Rgb5(self._io, self, self._root))
                i += 1



        def _fetch_instances(self):
            pass
            for i in range(len(self.indices)):
                pass
                _on = self.mode
                if _on == 0:
                    pass
                elif _on == 1:
                    pass
                elif _on == 2:
                    pass
                    self.indices[i]._fetch_instances()



    class Rect(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Img.Rect, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.x = self._io.read_s2le()
            self.y = self._io.read_s2le()
            self.w = self._io.read_s2le()
            self.h = self._io.read_s2le()


        def _fetch_instances(self):
            pass


    class Rgb5(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Img.Rgb5, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.r = self._io.read_bits_int_le(5)
            self.g = self._io.read_bits_int_le(5)
            self.b = self._io.read_bits_int_le(5)
            self.stp = self._io.read_bits_int_le(1) != 0


        def _fetch_instances(self):
            pass

        @property
        def a8(self):
            if hasattr(self, '_m_a8'):
                return self._m_a8

            self._m_a8 = (0 if  ((self.stp) and ( ((self.r == 0) and (self.g == 0) and (self.b == 0)) ))  else 255)
            return getattr(self, '_m_a8', None)

        @property
        def b8(self):
            if hasattr(self, '_m_b8'):
                return self._m_b8

            self._m_b8 = self.b << 3
            return getattr(self, '_m_b8', None)

        @property
        def g8(self):
            if hasattr(self, '_m_g8'):
                return self._m_g8

            self._m_g8 = self.g << 3
            return getattr(self, '_m_g8', None)

        @property
        def r8(self):
            if hasattr(self, '_m_r8'):
                return self._m_r8

            self._m_r8 = self.r << 3
            return getattr(self, '_m_r8', None)

        @property
        def raw(self):
            if hasattr(self, '_m_raw'):
                return self._m_raw

            self._m_raw = ((self.r + (self.g << 5)) + (self.b << 10)) + (int(self.stp) << 15)
            return getattr(self, '_m_raw', None)


    class Rgb5Array(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Img.Rgb5Array, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.colors = []
            i = 0
            while not self._io.is_eof():
                self.colors.append(Img.Rgb5(self._io, self, self._root))
                i += 1



        def _fetch_instances(self):
            pass
            for i in range(len(self.colors)):
                pass
                self.colors[i]._fetch_instances()



    class RleRgb5(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Img.RleRgb5, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self._raw__raw_raw_indices = self._io.read_bytes_full()
            _process = tools.libdata.rle.RleDecompressor(2147516416)
            self._raw_raw_indices = _process.decode(self._raw__raw_raw_indices)
            _io__raw_raw_indices = KaitaiStream(BytesIO(self._raw_raw_indices))
            self.raw_indices = Img.Rgb5Array(_io__raw_raw_indices, self, self._root)


        def _fetch_instances(self):
            pass
            self.raw_indices._fetch_instances()


    class Tim(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Img.Tim, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.magic = self._io.read_u4le()
            self.mode = self._io.read_bits_int_le(3)
            self.has_clut = self._io.read_bits_int_le(1) != 0
            self.reserved = self._io.read_bits_int_le(28)
            if self.has_clut:
                pass
                self.clut = Img.Clutsection(self._io, self, self._root)

            self.indices_len = self._io.read_u4le()
            self.rect = Img.Rect(self._io, self, self._root)
            self._raw_indices = self._io.read_bytes(self.indices_len - 12)
            _io__raw_indices = KaitaiStream(BytesIO(self._raw_indices))
            self.indices = Img.Indices(self.mode, _io__raw_indices, self, self._root)


        def _fetch_instances(self):
            pass
            if self.has_clut:
                pass
                self.clut._fetch_instances()

            self.rect._fetch_instances()
            self.indices._fetch_instances()



