# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.MENU import syd


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class ShieldSyd(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(ShieldSyd, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.root = syd.Syd(u"armor", 17, 17, 1, 8, self._io)


    def _fetch_instances(self):
        pass
        self.root._fetch_instances()


