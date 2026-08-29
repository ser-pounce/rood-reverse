# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.MENU import img
import tools.libdata.rle


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class MenubgBin(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(MenubgBin, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self._raw_clut = self._io.read_bytes(512)
        _io__raw_clut = KaitaiStream(BytesIO(self._raw_clut))
        self.clut = img.Img.Clut(_io__raw_clut)
        self._raw_indices = self._io.read_bytes_full()
        _process = tools.libdata.rle.RleDecompressor()
        self.indices = _process.decode(self._raw_indices)


    def _fetch_instances(self):
        pass
        self.clut._fetch_instances()


