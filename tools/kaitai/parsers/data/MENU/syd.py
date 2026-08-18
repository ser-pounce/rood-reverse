# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import IntEnum


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class Syd(KaitaiStruct):

    class Materials(IntEnum):
        none = 0
        wood = 1
        leather = 2
        bronze = 3
        iron = 4
        hagane = 5
        silver = 6
        damascus = 7
    def __init__(self, item_type, num_itemcombinations, num_items, num_categories, num_materials, _io, _parent=None, _root=None):
        super(Syd, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self.item_type = item_type
        self.num_itemcombinations = num_itemcombinations
        self.num_items = num_items
        self.num_categories = num_categories
        self.num_materials = num_materials
        self._read()

    def _read(self):
        self.itemcombinationsoffset = self._io.read_u4le()
        self.materialcombinationsoffset = self._io.read_u4le()
        self.infooffset = self._io.read_u4le()


    def _fetch_instances(self):
        pass
        _ = self.itemcombinations
        if hasattr(self, '_m_itemcombinations'):
            pass
            for i in range(len(self._m_itemcombinations)):
                pass
                self._m_itemcombinations[i]._fetch_instances()


        _ = self.items
        if hasattr(self, '_m_items'):
            pass
            for i in range(len(self._m_items)):
                pass
                _on = self.item_type
                if _on == u"armor":
                    pass
                    self._m_items[i]._fetch_instances()
                elif _on == u"blade":
                    pass
                    self._m_items[i]._fetch_instances()


        _ = self.materialcombinations
        if hasattr(self, '_m_materialcombinations'):
            pass
            self._m_materialcombinations._fetch_instances()


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


    class BladeInfo(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Syd.BladeInfo, self).__init__(_io)
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


    class CategoryRow(KaitaiStruct):
        def __init__(self, num_materials, num_categories, _io, _parent=None, _root=None):
            super(Syd.CategoryRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_materials = num_materials
            self.num_categories = num_categories
            self._read()

        def _read(self):
            self.materials = []
            for i in range(self.num_materials):
                self.materials.append(Syd.MaterialRow(self.num_categories, self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.materials)):
                pass
                self.materials[i]._fetch_instances()



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



    class MaterialRow(KaitaiStruct):
        def __init__(self, num_categories, _io, _parent=None, _root=None):
            super(Syd.MaterialRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_categories = num_categories
            self._read()

        def _read(self):
            self.categories = []
            for i in range(self.num_categories):
                self.categories.append(KaitaiStream.resolve_enum(Syd.Materials, self._io.read_u1()))



        def _fetch_instances(self):
            pass
            for i in range(len(self.categories)):
                pass



    class MaterialsTable(KaitaiStruct):
        def __init__(self, num_materials, num_categories, _io, _parent=None, _root=None):
            super(Syd.MaterialsTable, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_materials = num_materials
            self.num_categories = num_categories
            self._read()

        def _read(self):
            self.materials = []
            for i in range(self.num_materials):
                self.materials.append(Syd.OuterMaterialRow(self.num_materials, self.num_categories, self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.materials)):
                pass
                self.materials[i]._fetch_instances()



    class OuterMaterialRow(KaitaiStruct):
        def __init__(self, num_materials, num_categories, _io, _parent=None, _root=None):
            super(Syd.OuterMaterialRow, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_materials = num_materials
            self.num_categories = num_categories
            self._read()

        def _read(self):
            self.categories = []
            for i in range(self.num_categories):
                self.categories.append(Syd.CategoryRow(self.num_materials, self.num_categories, self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.categories)):
                pass
                self.categories[i]._fetch_instances()



    @property
    def itemcombinations(self):
        if hasattr(self, '_m_itemcombinations'):
            return self._m_itemcombinations

        _pos = self._io.pos()
        self._io.seek(self.itemcombinationsoffset)
        self._m_itemcombinations = []
        for i in range(self.num_itemcombinations):
            self._m_itemcombinations.append(Syd.CombinationRow(self.num_itemcombinations, self._io, self, self._root))

        self._io.seek(_pos)
        return getattr(self, '_m_itemcombinations', None)

    @property
    def items(self):
        if hasattr(self, '_m_items'):
            return self._m_items

        _pos = self._io.pos()
        self._io.seek(self.infooffset)
        self._m_items = []
        for i in range(self.num_items):
            _on = self.item_type
            if _on == u"armor":
                pass
                self._m_items.append(Syd.ArmorInfo(self._io, self, self._root))
            elif _on == u"blade":
                pass
                self._m_items.append(Syd.BladeInfo(self._io, self, self._root))

        self._io.seek(_pos)
        return getattr(self, '_m_items', None)

    @property
    def materialcombinations(self):
        if hasattr(self, '_m_materialcombinations'):
            return self._m_materialcombinations

        _pos = self._io.pos()
        self._io.seek(self.materialcombinationsoffset)
        self._m_materialcombinations = Syd.MaterialsTable(self.num_categories, self.num_materials, self._io, self, self._root)
        self._io.seek(_pos)
        return getattr(self, '_m_materialcombinations', None)


