# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.SMALL import img


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class ImageDis(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(ImageDis, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.tims = []
        i = 0
        while not self._io.is_eof():
            self.tims.append(ImageDis.Tim(self._io, self, self._root))
            i += 1



    def _fetch_instances(self):
        pass
        for i in range(len(self.tims)):
            pass
            self.tims[i]._fetch_instances()


    class Clutsection(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ImageDis.Clutsection, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.len = self._io.read_u4le()
            self.rect = img.Img.Rect(self._io)
            self._raw_clut = self._io.read_bytes(self.len - 12)
            _io__raw_clut = KaitaiStream(BytesIO(self._raw_clut))
            self.clut = img.Img.Clut(_io__raw_clut)


        def _fetch_instances(self):
            pass
            self.rect._fetch_instances()
            self.clut._fetch_instances()


    class Indices(KaitaiStruct):
        def __init__(self, mode, _io, _parent=None, _root=None):
            super(ImageDis.Indices, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.mode = mode
            self._read()

        def _read(self):
            self.index = []
            i = 0
            while not self._io.is_eof():
                _on = self.mode
                if _on == 0:
                    pass
                    self.index.append(self._io.read_bits_int_le(4))
                elif _on == 1:
                    pass
                    self.index.append(self._io.read_u1())
                elif _on == 2:
                    pass
                    self.index.append(img.Img.Bgr5551(self._io))
                i += 1



        def _fetch_instances(self):
            pass
            for i in range(len(self.index)):
                pass
                _on = self.mode
                if _on == 0:
                    pass
                elif _on == 1:
                    pass
                elif _on == 2:
                    pass
                    self.index[i]._fetch_instances()



    class Tim(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ImageDis.Tim, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.magic = self._io.read_bytes(4)
            if not self.magic == b"\x10\x00\x00\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x10\x00\x00\x00", self.magic, self._io, u"/types/tim/seq/0")
            self.mode = self._io.read_bits_int_le(3)
            self.has_clut = self._io.read_bits_int_le(1) != 0
            self.reserved = self._io.read_bits_int_le(28)
            if self.has_clut:
                pass
                self.clut = ImageDis.Clutsection(self._io, self, self._root)

            self.indices_len = self._io.read_u4le()
            self.rect = img.Img.Rect(self._io)
            self._raw_indices = self._io.read_bytes(self.indices_len - 12)
            _io__raw_indices = KaitaiStream(BytesIO(self._raw_indices))
            self.indices = ImageDis.Indices(self.mode, _io__raw_indices, self, self._root)


        def _fetch_instances(self):
            pass
            if self.has_clut:
                pass
                self.clut._fetch_instances()

            self.rect._fetch_instances()
            self.indices._fetch_instances()



