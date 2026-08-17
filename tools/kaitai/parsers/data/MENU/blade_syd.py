# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import IntEnum


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class BladeSyd(KaitaiStruct):

    class Materials(IntEnum):
        wood = 1
        leather = 2
        bronze = 3
        iron = 4
        hagane = 5
        silver = 6
        damascus = 7
    def __init__(self, _io, _parent=None, _root=None):
        super(BladeSyd, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.combinations_offset = self._io.read_u4le()
        self.materials_offset = self._io.read_u4le()
        self.info_offset = self._io.read_u4le()


    def _fetch_instances(self):
        pass
        _ = self.combinations
        if hasattr(self, '_m_combinations'):
            pass
            for i in range(len(self._m_combinations)):
                pass
                self._m_combinations[i]._fetch_instances()


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


    class CombinationRow(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(BladeSyd.CombinationRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.data = []
            for i in range(96):
                self.data.append(self._io.read_u1())



        def _fetch_instances(self):
            pass
            for i in range(len(self.data)):
                pass



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


    class MaterialRow(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(BladeSyd.MaterialRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.weapons = []
            for i in range(10):
                self.weapons.append(KaitaiStream.resolve_enum(BladeSyd.Materials, self._io.read_u1()))



        def _fetch_instances(self):
            pass
            for i in range(len(self.weapons)):
                pass



    class MaterialsTable(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(BladeSyd.MaterialsTable, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.materials = []
            for i in range(5):
                self.materials.append(BladeSyd.OuterMaterialRow(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.materials)):
                pass
                self.materials[i]._fetch_instances()



    class OuterMaterialRow(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(BladeSyd.OuterMaterialRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.weapons = []
            for i in range(10):
                self.weapons.append(BladeSyd.WeaponRow(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.weapons)):
                pass
                self.weapons[i]._fetch_instances()



    class WeaponRow(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(BladeSyd.WeaponRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.materials = []
            for i in range(5):
                self.materials.append(BladeSyd.MaterialRow(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.materials)):
                pass
                self.materials[i]._fetch_instances()



    @property
    def combinations(self):
        if hasattr(self, '_m_combinations'):
            return self._m_combinations

        _pos = self._io.pos()
        self._io.seek(self.combinations_offset)
        self._m_combinations = []
        for i in range(96):
            self._m_combinations.append(BladeSyd.CombinationRow(self._io, self, self._root))

        self._io.seek(_pos)
        return getattr(self, '_m_combinations', None)

    @property
    def info(self):
        if hasattr(self, '_m_info'):
            return self._m_info

        _pos = self._io.pos()
        self._io.seek(self.info_offset)
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
        self._io.seek(self.materials_offset)
        self._m_materialcombinations = BladeSyd.MaterialsTable(self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_materialcombinations', None)


