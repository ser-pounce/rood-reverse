# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class HelpHf1(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(HelpHf1, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.num_blocks = self._io.read_u4le()
        self.num_cluts = self._io.read_u4le()
        self.blocks = []
        for i in range(self.num_blocks):
            self.blocks.append(self._io.read_bytes(128))

        self.cluts = []
        for i in range(self.num_cluts):
            self.cluts.append(HelpHf1.Clut(self._io, self, self._root))



    def _fetch_instances(self):
        pass
        for i in range(len(self.blocks)):
            pass

        for i in range(len(self.cluts)):
            pass
            self.cluts[i]._fetch_instances()


    class Bgr5551(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(HelpHf1.Bgr5551, self).__init__(_io)
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
            super(HelpHf1.Clut, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.color = []
            for i in range(16):
                self.color.append(HelpHf1.Bgr5551(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.color)):
                pass
                self.color[i]._fetch_instances()




