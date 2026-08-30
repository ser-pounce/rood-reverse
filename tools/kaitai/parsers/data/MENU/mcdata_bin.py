# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.MENU import img


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class McdataBin(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(McdataBin, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self._raw_cluts = []
        self.cluts = []
        for i in range(2):
            self._raw_cluts.append(self._io.read_bytes(512))
            _io__raw_cluts = KaitaiStream(BytesIO(self._raw_cluts[i]))
            self.cluts.append(img.Img.Clut(_io__raw_cluts))

        self.unk400 = []
        for i in range(7):
            self.unk400.append(self._io.read_bytes(32))

        self.unk4e0 = []
        for i in range(7):
            self.unk4e0.append(self._io.read_bytes(128))

        self.unk860 = []
        for i in range(7):
            self.unk860.append(self._io.read_bytes(128))



    def _fetch_instances(self):
        pass
        for i in range(len(self.cluts)):
            pass
            self.cluts[i]._fetch_instances()

        for i in range(len(self.unk400)):
            pass

        for i in range(len(self.unk4e0)):
            pass

        for i in range(len(self.unk860)):
            pass



