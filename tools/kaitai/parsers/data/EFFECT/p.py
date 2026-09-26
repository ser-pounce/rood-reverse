# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import IntEnum


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class P(KaitaiStruct):

    class BlockType(IntEnum):
        type0 = 0
        type1 = 1
        type2 = 2
        type3 = 3
        transparency_curves = 4
        type5 = 5
        type8 = 8
        type9 = 9
        type10 = 10
        type11 = 11
        type12 = 12
        type13 = 13
        type14 = 14
    def __init__(self, _io, _parent=None, _root=None):
        super(P, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.blocks = []
        i = 0
        while True:
            _ = P.Block(self._io, self, self._root)
            self.blocks.append(_)
            if _.size == 0:
                break
            i += 1


    def _fetch_instances(self):
        pass
        for i in range(len(self.blocks)):
            pass
            self.blocks[i]._fetch_instances()


    class Array1d(KaitaiStruct):
        def __init__(self, num_value, _io, _parent=None, _root=None):
            super(P.Array1d, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_value = num_value
            self._read()

        def _read(self):
            self.value = []
            for i in range(self.num_value):
                self.value.append(self._io.read_s2le())



        def _fetch_instances(self):
            pass
            for i in range(len(self.value)):
                pass



    class Array2d(KaitaiStruct):
        def __init__(self, num_rows, cols, _io, _parent=None, _root=None):
            super(P.Array2d, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_rows = num_rows
            self.cols = cols
            self._read()

        def _read(self):
            self.rows = []
            for i in range(self.num_rows):
                self.rows.append(P.Array1d(self.cols, self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.rows)):
                pass
                self.rows[i]._fetch_instances()



    class Block(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(P.Block, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.size = self._io.read_u2le()
            self.type = KaitaiStream.resolve_enum(P.BlockType, self._io.read_u2le())
            if self.size != 0:
                pass
                _on = self.type
                if _on == P.BlockType.transparency_curves:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.TransparencyCurves(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type0:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type1:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.Type1Body(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type10:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type11:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.Type11Body(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type12:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type13:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type2:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.Type2Body(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type3:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type5:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.Type5Body(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type8:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type9:
                    pass
                    self._raw_body = self._io.read_bytes(self.size - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                else:
                    pass
                    self.body = self._io.read_bytes(self.size - 4)



        def _fetch_instances(self):
            pass
            if self.size != 0:
                pass
                _on = self.type
                if _on == P.BlockType.transparency_curves:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type0:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type1:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type10:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type11:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type12:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type13:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type2:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type3:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type5:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type8:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type9:
                    pass
                    self.body._fetch_instances()
                else:
                    pass



    class BlockChunk(KaitaiStruct):
        def __init__(self, idx, _io, _parent=None, _root=None):
            super(P.BlockChunk, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.idx = idx
            self._read()

        def _read(self):
            self.body = self._io.read_bytes(self._parent.sizes[self.idx])


        def _fetch_instances(self):
            pass


    class Func800fa098Arg0(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(P.Func800fa098Arg0, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unk0 = self._io.read_u1()
            self.unk1 = self._io.read_u1()
            self.unk2 = self._io.read_u1()
            self.unk3 = self._io.read_u1()
            self.unk4_bit0 = self._io.read_bits_int_le(26)
            self.transparency_curve = self._io.read_bits_int_le(6)
            self.unk8 = self._io.read_u1()
            self.unk9 = self._io.read_u1()
            self.unka = self._io.read_u1()
            self.unkb = self._io.read_u1()
            self.unkc = self._io.read_u1()
            self.unkd = self._io.read_u1()
            self.unke = self._io.read_u1()
            self.unkf = self._io.read_u1()
            self.unk10 = self._io.read_u1()
            self.unk11 = self._io.read_u1()
            self.unk12 = self._io.read_u1()
            self.unk13 = self._io.read_u1()
            self.unk14 = self._io.read_u1()
            self.unk15 = self._io.read_u1()
            self.unk16 = self._io.read_u1()
            self.unk17 = self._io.read_u1()
            self.unk18 = self._io.read_bytes(24)
            self.unk30 = P.Array1d(2, self._io, self, self._root)
            self.unk34 = P.Array2d(8, 6, self._io, self, self._root)
            self.unk94 = P.Array2d(5, 4, self._io, self, self._root)
            self.unkbc = self._io.read_s4le()
            self.unkc0 = P.Array1d(2, self._io, self, self._root)
            self.unkc4 = self._io.read_u1()
            self.unkc5 = self._io.read_u1()
            self.unkc6 = self._io.read_u1()
            self.unkc7 = self._io.read_u1()
            self.unkc8 = self._io.read_u1()
            self.unkc9 = self._io.read_u1()
            self.unkca = self._io.read_u1()
            self.unkcb = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.unk30._fetch_instances()
            self.unk34._fetch_instances()
            self.unk94._fetch_instances()
            self.unkc0._fetch_instances()


    class RawBody(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(P.RawBody, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.data = self._io.read_bytes_full()


        def _fetch_instances(self):
            pass


    class TransparencyCurves(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(P.TransparencyCurves, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_curves = self._io.read_u2le()
            self.data_offset = self._io.read_u2le()
            self.sizes = []
            for i in range(self.num_curves):
                self.sizes.append(self._io.read_u1())

            self.curves = []
            for i in range(self.num_curves):
                self.curves.append(P.BlockChunk(i, self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.sizes)):
                pass

            for i in range(len(self.curves)):
                pass
                self.curves[i]._fetch_instances()



    class Type11Body(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(P.Type11Body, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_offsets = self._io.read_u4le()
            self.offsets = []
            for i in range(self.num_offsets):
                self.offsets.append(self._io.read_u2le())

            self.data = self._io.read_bytes_full()


        def _fetch_instances(self):
            pass
            for i in range(len(self.offsets)):
                pass



    class Type1Body(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(P.Type1Body, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_table_offsets = self._io.read_u2le()
            self.data_offset = self._io.read_u2le()
            self.table_offsets = []
            for i in range(self.num_table_offsets):
                self.table_offsets.append(self._io.read_u4le())

            self.data = self._io.read_bytes_full()


        def _fetch_instances(self):
            pass
            for i in range(len(self.table_offsets)):
                pass



    class Type2Body(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(P.Type2Body, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_offsets = self._io.read_u4le()
            self.offsets = []
            for i in range(self.num_offsets):
                self.offsets.append(self._io.read_u2le())

            self.data = self._io.read_bytes_full()


        def _fetch_instances(self):
            pass
            for i in range(len(self.offsets)):
                pass



    class Type5Body(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(P.Type5Body, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_data = self._io.read_u4le()
            self.data = []
            for i in range(self.num_data):
                self.data.append(P.Func800fa098Arg0(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.data)):
                pass
                self.data[i]._fetch_instances()




