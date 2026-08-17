# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import IntEnum


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class ArmorSyd(KaitaiStruct):

    class Materials(IntEnum):
        wood = 1
        leather = 2
        bronze = 3
        iron = 4
        hagane = 5
        silver = 6
        damascus = 7
    def __init__(self, _io, _parent=None, _root=None):
        super(ArmorSyd, self).__init__(_io)
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


    class ArmorRow(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ArmorSyd.ArmorRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.materials = []
            for i in range(8):
                self.materials.append(ArmorSyd.MaterialRow(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.materials)):
                pass
                self.materials[i]._fetch_instances()



    class CombinationRow(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ArmorSyd.CombinationRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.data = []
            for i in range(65):
                self.data.append(self._io.read_u1())



        def _fetch_instances(self):
            pass
            for i in range(len(self.data)):
                pass



    class Info(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ArmorSyd.Info, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.subid = self._io.read_u1()
            self.wepid = self._io.read_u1()
            self.category = self._io.read_u1()
            self.gemslots = self._io.read_u1()
            self.strength = self._io.read_s1()
            self.intelligence = self._io.read_s1()
            self.agility = self._io.read_s1()


        def _fetch_instances(self):
            pass


    class MaterialRow(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ArmorSyd.MaterialRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.armor = []
            for i in range(4):
                self.armor.append(KaitaiStream.resolve_enum(ArmorSyd.Materials, self._io.read_u1()))



        def _fetch_instances(self):
            pass
            for i in range(len(self.armor)):
                pass



    class MaterialsTable(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ArmorSyd.MaterialsTable, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.materials = []
            for i in range(8):
                self.materials.append(ArmorSyd.OuterMaterialRow(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.materials)):
                pass
                self.materials[i]._fetch_instances()



    class OuterMaterialRow(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ArmorSyd.OuterMaterialRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.armor = []
            for i in range(4):
                self.armor.append(ArmorSyd.ArmorRow(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.armor)):
                pass
                self.armor[i]._fetch_instances()



    @property
    def combinations(self):
        if hasattr(self, '_m_combinations'):
            return self._m_combinations

        _pos = self._io.pos()
        self._io.seek(self.combinations_offset)
        self._m_combinations = []
        for i in range(65):
            self._m_combinations.append(ArmorSyd.CombinationRow(self._io, self, self._root))

        self._io.seek(_pos)
        return getattr(self, '_m_combinations', None)

    @property
    def info(self):
        if hasattr(self, '_m_info'):
            return self._m_info

        _pos = self._io.pos()
        self._io.seek(self.info_offset)
        self._raw__m_info = []
        self._m_info = []
        for i in range(81):
            self._raw__m_info.append(self._io.read_bytes(8))
            _io__raw__m_info = KaitaiStream(BytesIO(self._raw__m_info[i]))
            self._m_info.append(ArmorSyd.Info(_io__raw__m_info, self, self._root))

        self._io.seek(_pos)
        return getattr(self, '_m_info', None)

    @property
    def materialcombinations(self):
        if hasattr(self, '_m_materialcombinations'):
            return self._m_materialcombinations

        _pos = self._io.pos()
        self._io.seek(self.materials_offset)
        self._m_materialcombinations = ArmorSyd.MaterialsTable(self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_materialcombinations', None)


