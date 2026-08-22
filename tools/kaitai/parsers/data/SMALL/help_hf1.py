# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.SMALL import img


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

        self._raw_cluts = []
        self.cluts = []
        for i in range(self.num_cluts):
            self._raw_cluts.append(self._io.read_bytes(32))
            _io__raw_cluts = KaitaiStream(BytesIO(self._raw_cluts[i]))
            self.cluts.append(img.Img.Clut(_io__raw_cluts))



    def _fetch_instances(self):
        pass
        for i in range(len(self.blocks)):
            pass

        for i in range(len(self.cluts)):
            pass
            self.cluts[i]._fetch_instances()



