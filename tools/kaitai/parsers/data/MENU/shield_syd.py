# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.lib import syd


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class ShieldSyd(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(ShieldSyd, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.offsets = syd.Syd.Offsets(self._io)


    def _fetch_instances(self):
        pass
        self.offsets._fetch_instances()
        _ = self.combinations
        if hasattr(self, '_m_combinations'):
            pass
            self._m_combinations._fetch_instances()

        _ = self.info
        if hasattr(self, '_m_info'):
            pass
            for i in range(len(self._m_info)):
                pass
                self._m_info[i]._fetch_instances()


        _ = self.materialcombinations
        if hasattr(self, '_m_materialcombinations'):
            pass
            for i in range(len(self._m_materialcombinations)):
                pass
                self._m_materialcombinations[i]._fetch_instances()



    @property
    def combinations(self):
        if hasattr(self, '_m_combinations'):
            return self._m_combinations

        _pos = self._io.pos()
        self._io.seek(self.offsets.combinations)
        self._m_combinations = syd.Syd.SquareArray(17, self._io)
        self._io.seek(_pos)
        return getattr(self, '_m_combinations', None)

    @property
    def info(self):
        if hasattr(self, '_m_info'):
            return self._m_info

        _pos = self._io.pos()
        self._io.seek(self.offsets.info)
        self._m_info = []
        for i in range(17):
            self._m_info.append(syd.Syd.ArmorInfo(self._io))

        self._io.seek(_pos)
        return getattr(self, '_m_info', None)

    @property
    def materialcombinations(self):
        if hasattr(self, '_m_materialcombinations'):
            return self._m_materialcombinations

        _pos = self._io.pos()
        self._io.seek(self.offsets.materials)
        self._m_materialcombinations = []
        for i in range(8):
            self._m_materialcombinations.append(syd.Syd.MaterialRow(8, self._io))

        self._io.seek(_pos)
        return getattr(self, '_m_materialcombinations', None)


