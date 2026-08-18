# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import IntEnum


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class Syd(KaitaiStruct):

    class Materials(IntEnum):
        wood = 1
        leather = 2
        bronze = 3
        iron = 4
        hagane = 5
        silver = 6
        damascus = 7
    def __init__(self, _io, _parent=None, _root=None):
        super(Syd, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        pass


    def _fetch_instances(self):
        pass

    class ArmorInfo(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Syd.ArmorInfo, self).__init__(_io)
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
            self.reserved = self._io.read_bytes(1)
            if not self.reserved == b"\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00", self.reserved, self._io, u"/types/armor_info/seq/7")


        def _fetch_instances(self):
            pass


    class CombinationRow(KaitaiStruct):
        def __init__(self, num_data, _io, _parent=None, _root=None):
            super(Syd.CombinationRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_data = num_data
            self._read()

        def _read(self):
            self.data = []
            for i in range(self.num_data):
                self.data.append(self._io.read_u1())



        def _fetch_instances(self):
            pass
            for i in range(len(self.data)):
                pass



    class EquipmentRow(KaitaiStruct):
        def __init__(self, num_materials, num_equipment, _io, _parent=None, _root=None):
            super(Syd.EquipmentRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_materials = num_materials
            self.num_equipment = num_equipment
            self._read()

        def _read(self):
            self.materials = []
            for i in range(self.num_materials):
                self.materials.append(Syd.MaterialRow(self.num_equipment, self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.materials)):
                pass
                self.materials[i]._fetch_instances()



    class MaterialRow(KaitaiStruct):
        def __init__(self, num_equipment, _io, _parent=None, _root=None):
            super(Syd.MaterialRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_equipment = num_equipment
            self._read()

        def _read(self):
            self.equipment = []
            for i in range(self.num_equipment):
                self.equipment.append(KaitaiStream.resolve_enum(Syd.Materials, self._io.read_u1()))



        def _fetch_instances(self):
            pass
            for i in range(len(self.equipment)):
                pass



    class MaterialsTable(KaitaiStruct):
        def __init__(self, num_materials, num_equipment, _io, _parent=None, _root=None):
            super(Syd.MaterialsTable, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_materials = num_materials
            self.num_equipment = num_equipment
            self._read()

        def _read(self):
            self.materials = []
            for i in range(self.num_materials):
                self.materials.append(Syd.OuterMaterialRow(self.num_materials, self.num_equipment, self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.materials)):
                pass
                self.materials[i]._fetch_instances()



    class Offsets(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Syd.Offsets, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.combinations = self._io.read_u4le()
            self.materials = self._io.read_u4le()
            self.info = self._io.read_u4le()


        def _fetch_instances(self):
            pass


    class OuterMaterialRow(KaitaiStruct):
        def __init__(self, num_materials, num_equipment, _io, _parent=None, _root=None):
            super(Syd.OuterMaterialRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_materials = num_materials
            self.num_equipment = num_equipment
            self._read()

        def _read(self):
            self.equipment = []
            for i in range(self.num_equipment):
                self.equipment.append(Syd.EquipmentRow(self.num_materials, self.num_equipment, self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.equipment)):
                pass
                self.equipment[i]._fetch_instances()



    class SquareArray(KaitaiStruct):
        def __init__(self, num_rows, _io, _parent=None, _root=None):
            super(Syd.SquareArray, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_rows = num_rows
            self._read()

        def _read(self):
            self.rows = []
            for i in range(self.num_rows):
                self.rows.append(Syd.CombinationRow(self.num_rows, self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.rows)):
                pass
                self.rows[i]._fetch_instances()




