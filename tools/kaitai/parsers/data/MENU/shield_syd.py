# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import IntEnum


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class ShieldSyd(KaitaiStruct):

    class Materials(IntEnum):
        wood = 1
        bronze = 3
        iron = 4
        hagane = 5
        silver = 6
        damascus = 7
    def __init__(self, _io, _parent=None, _root=None):
        super(ShieldSyd, self).__init__(_io)
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


        _ = self.materials
        if hasattr(self, '_m_materials'):
            pass
            for i in range(len(self._m_materials)):
                pass
                self._m_materials[i]._fetch_instances()



    class CombinationRow(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ShieldSyd.CombinationRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.data = []
            for i in range(17):
                self.data.append(self._io.read_u1())



        def _fetch_instances(self):
            pass
            for i in range(len(self.data)):
                pass



    class MaterialRow(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ShieldSyd.MaterialRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.data = []
            for i in range(8):
                self.data.append(KaitaiStream.resolve_enum(ShieldSyd.Materials, self._io.read_u1()))



        def _fetch_instances(self):
            pass
            for i in range(len(self.data)):
                pass



    class Shieldinfo(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ShieldSyd.Shieldinfo, self).__init__(_io)
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


    @property
    def combinations(self):
        if hasattr(self, '_m_combinations'):
            return self._m_combinations

        _pos = self._io.pos()
        self._io.seek(self.combinations_offset)
        self._m_combinations = []
        for i in range(17):
            self._m_combinations.append(ShieldSyd.CombinationRow(self._io, self, self._root))

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
        for i in range(17):
            self._raw__m_info.append(self._io.read_bytes(8))
            _io__raw__m_info = KaitaiStream(BytesIO(self._raw__m_info[i]))
            self._m_info.append(ShieldSyd.Shieldinfo(_io__raw__m_info, self, self._root))

        self._io.seek(_pos)
        return getattr(self, '_m_info', None)

    @property
    def materials(self):
        if hasattr(self, '_m_materials'):
            return self._m_materials

        _pos = self._io.pos()
        self._io.seek(self.materials_offset)
        self._m_materials = []
        for i in range(8):
            self._m_materials.append(ShieldSyd.MaterialRow(self._io, self, self._root))

        self._io.seek(_pos)
        return getattr(self, '_m_materials', None)


