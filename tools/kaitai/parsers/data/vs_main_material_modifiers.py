# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class VsMainMaterialModifiers(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(VsMainMaterialModifiers, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.modifiers = []
        for i in range(8):
            self.modifiers.append(VsMainMaterialModifiers.MaterialModifiers(self._io, self, self._root))



    def _fetch_instances(self):
        pass
        for i in range(len(self.modifiers)):
            pass
            self.modifiers[i]._fetch_instances()


    class Affinity(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(VsMainMaterialModifiers.Affinity, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.phys = self._io.read_s1()
            self.wind = self._io.read_s1()
            self.fire = self._io.read_s1()
            self.earth = self._io.read_s1()
            self.water = self._io.read_s1()
            self.light = self._io.read_s1()
            self.dark = self._io.read_s1()
            self.reserved = self._io.read_bytes(1)
            if not self.reserved == b"\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00", self.reserved, self._io, u"/types/affinity/seq/7")


        def _fetch_instances(self):
            pass


    class MaterialModifiers(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(VsMainMaterialModifiers.MaterialModifiers, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.human = self._io.read_s1()
            self.beast = self._io.read_s1()
            self.undead = self._io.read_s1()
            self.phantom = self._io.read_s1()
            self.dragon = self._io.read_s1()
            self.evil = self._io.read_s1()
            self.attack_affinities = VsMainMaterialModifiers.Affinity(self._io, self, self._root)
            self.defense_affinities = VsMainMaterialModifiers.Affinity(self._io, self, self._root)
            self.max_dp_mod = self._io.read_s2le()
            self.str_mod = self._io.read_s2le()
            self.int_mod = self._io.read_s2le()
            self.agi_mod = self._io.read_s2le()


        def _fetch_instances(self):
            pass
            self.attack_affinities._fetch_instances()
            self.defense_affinities._fetch_instances()



