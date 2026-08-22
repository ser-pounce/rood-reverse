# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


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

    class Bgr5551(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Img.Bgr5551, self).__init__(_io)
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

            self._m_a8 = (255 if  ((self.stp) or (self.r != 0) or (self.g != 0) or (self.b != 0))  else 0)
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
                self.colors.append(Img.Bgr5551(self._io, self, self._root))
                i += 1



        def _fetch_instances(self):
            pass
            for i in range(len(self.colors)):
                pass
                self.colors[i]._fetch_instances()



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



