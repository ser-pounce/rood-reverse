# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.lib import syd


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class BladeSyd(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(BladeSyd, self).__init__(_io)
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
            self._m_materialcombinations._fetch_instances()


    class Info(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(BladeSyd.Info, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.subid = self._io.read_u1()
            self.wepid = self._io.read_u1()
            self.category = self._io.read_u1()
            self.damagetype = self._io.read_u1()
            self.costtype = self._io.read_u1()
            self.cost = self._io.read_u1()
            self.unk6 = self._io.read_u1()
            self.unk7 = self._io.read_u1()
            self.strength = self._io.read_s1()
            self.intelligence = self._io.read_s1()
            self.agility = self._io.read_s1()
            self.unkb = self._io.read_u1()
            self.range = self._io.read_u1()
            self.unkd = self._io.read_u1()
            self.unke = self._io.read_u1()
            self.attackshapeangle = self._io.read_bits_int_be(5)
            self.attackshape = self._io.read_bits_int_be(3)


        def _fetch_instances(self):
            pass


    @property
    def combinations(self):
        if hasattr(self, '_m_combinations'):
            return self._m_combinations

        _pos = self._io.pos()
        self._io.seek(self.offsets.combinations)
        self._m_combinations = syd.Syd.SquareArray(96, self._io)
        self._io.seek(_pos)
        return getattr(self, '_m_combinations', None)

    @property
    def info(self):
        if hasattr(self, '_m_info'):
            return self._m_info

        _pos = self._io.pos()
        self._io.seek(self.offsets.info)
        self._m_info = []
        for i in range(96):
            self._m_info.append(BladeSyd.Info(self._io, self, self._root))

        self._io.seek(_pos)
        return getattr(self, '_m_info', None)

    @property
    def materialcombinations(self):
        if hasattr(self, '_m_materialcombinations'):
            return self._m_materialcombinations

        _pos = self._io.pos()
        self._io.seek(self.offsets.materials)
        self._m_materialcombinations = syd.Syd.MaterialsTable(5, 10, self._io)
        self._io.seek(_pos)
        return getattr(self, '_m_materialcombinations', None)


