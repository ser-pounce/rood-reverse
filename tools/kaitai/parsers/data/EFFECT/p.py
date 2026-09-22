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
        type4 = 4
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
            if _.next_block == 0:
                break
            i += 1


    def _fetch_instances(self):
        pass
        for i in range(len(self.blocks)):
            pass
            self.blocks[i]._fetch_instances()


    class Block(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(P.Block, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.next_block = self._io.read_u2le()
            self.type = KaitaiStream.resolve_enum(P.BlockType, self._io.read_u2le())
            if self.next_block != 0:
                pass
                _on = self.type
                if _on == P.BlockType.type0:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type1:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.Type1Body(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type10:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type11:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type12:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type13:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type14:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type2:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.Type2Body(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type3:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type4:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.Type4Body(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type5:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.Type5Body(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type8:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                elif _on == P.BlockType.type9:
                    pass
                    self._raw_body = self._io.read_bytes(self.next_block - 4)
                    _io__raw_body = KaitaiStream(BytesIO(self._raw_body))
                    self.body = P.RawBody(_io__raw_body, self, self._root)
                else:
                    pass
                    self.body = self._io.read_bytes(self.next_block - 4)



        def _fetch_instances(self):
            pass
            if self.next_block != 0:
                pass
                _on = self.type
                if _on == P.BlockType.type0:
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
                elif _on == P.BlockType.type14:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type2:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type3:
                    pass
                    self.body._fetch_instances()
                elif _on == P.BlockType.type4:
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



    class Type4Body(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(P.Type4Body, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_offsets = self._io.read_u2le()
            self.data_offset = self._io.read_u2le()
            self.offsets = []
            for i in range(self.num_offsets):
                self.offsets.append(self._io.read_u1())

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
                self.data.append(self._io.read_bytes(204))



        def _fetch_instances(self):
            pass
            for i in range(len(self.data)):
                pass




