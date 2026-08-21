# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.SMALL import string_table


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class MonBin(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(MonBin, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.monsters = []
        for i in range(150):
            self.monsters.append(MonBin.Monster(i, self._io, self, self._root))

        self._raw_descriptions = self._io.read_bytes_full()
        _io__raw_descriptions = KaitaiStream(BytesIO(self._raw_descriptions))
        self.descriptions = string_table.StringTable(0, _io__raw_descriptions)


    def _fetch_instances(self):
        pass
        for i in range(len(self.monsters)):
            pass
            self.monsters[i]._fetch_instances()

        self.descriptions._fetch_instances()

    class Monster(KaitaiStruct):
        def __init__(self, index, _io, _parent=None, _root=None):
            super(MonBin.Monster, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.index = index
            self._read()

        def _read(self):
            self.zudid = self._io.read_s2le()
            self.classid = self._io.read_s2le()
            self.killflagsoffset = self._io.read_s2le()
            self.killflagscount = self._io.read_s2le()
            self.reserved = self._io.read_bytes(8)
            if not self.reserved == b"\x00\x00\x00\x00\x00\x00\x00\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00\x00\x00\x00\x00\x00\x00\x00", self.reserved, self._io, u"/types/monster/seq/4")
            self.name = self._io.read_bytes(28)


        def _fetch_instances(self):
            pass

        @property
        def description(self):
            if hasattr(self, '_m_description'):
                return self._m_description

            self._m_description = self._root.descriptions.string_refs[self.index].text
            return getattr(self, '_m_description', None)



