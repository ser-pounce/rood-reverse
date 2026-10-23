# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class VsMainActions(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(VsMainActions, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.actions = []
        for i in range(256):
            self.actions.append(VsMainActions.Action(self._io, self, self._root))



    def _fetch_instances(self):
        pass
        for i in range(len(self.actions)):
            pass
            self.actions[i]._fetch_instances()


    class Action(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(VsMainActions.Action, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.id = self._io.read_u1()
            self.unk1 = self._io.read_u1()
            self.unk2_0 = self._io.read_bits_int_le(1) != 0
            self.type = self._io.read_bits_int_le(3)
            self.unk2_4 = self._io.read_bits_int_le(4)
            self.cost = self._io.read_u1()
            self.range_x = self._io.read_u1()
            self.range_y = self._io.read_u1()
            self.range_z = self._io.read_u1()
            self.shape = self._io.read_bits_int_le(3)
            self.angle = self._io.read_bits_int_le(5)
            self.aoe_0 = self._io.read_u1()
            self.aoe_8 = self._io.read_u1()
            self.aoe_16 = self._io.read_u1()
            self.aoe_24 = self._io.read_u1()
            self.flags_0 = self._io.read_u1()
            self.flags_d_0 = self._io.read_bits_int_le(4)
            self.flags_d_4 = self._io.read_bits_int_le(2)
            self.flags_d_6 = self._io.read_bits_int_le(1) != 0
            self.unlocked = self._io.read_bits_int_le(1) != 0
            self.flags_e = VsMainActions.ActionFlags(self._io, self, self._root)
            self.unk10 = self._io.read_s4le()
            self.hit_params = []
            for i in range(2):
                self.hit_params.append(VsMainActions.HitParams(self._io, self, self._root))

            self.name = self._io.read_bytes(24)


        def _fetch_instances(self):
            pass
            self.flags_e._fetch_instances()
            for i in range(len(self.hit_params)):
                pass
                self.hit_params[i]._fetch_instances()



    class ActionFlags(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(VsMainActions.ActionFlags, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unk0 = self._io.read_bits_int_le(4)
            self.unk4 = self._io.read_bits_int_le(1) != 0
            self.unk5 = self._io.read_bits_int_le(1) != 0
            self.unk6 = self._io.read_bits_int_le(1) != 0
            self.unk7 = self._io.read_bits_int_le(1) != 0
            self.unk8 = self._io.read_bits_int_le(4)
            self.unk12 = self._io.read_bits_int_le(1) != 0
            self.unk13 = self._io.read_bits_int_le(1) != 0
            self.unk14 = self._io.read_bits_int_le(2)


        def _fetch_instances(self):
            pass


    class HitParams(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(VsMainActions.HitParams, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.effect = self._io.read_bits_int_le(7)
            self.prerequisite_function = self._io.read_bits_int_le(6)
            self.hit_function = self._io.read_bits_int_le(3)
            self.stat_calculator = self._io.read_bits_int_le(6)
            self.stat_factor = self._io.read_bits_int_le(5)
            self.type = self._io.read_bits_int_le(2)
            self.affinity = self._io.read_bits_int_le(3)


        def _fetch_instances(self):
            pass



