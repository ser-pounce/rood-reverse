# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class StringTable(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(StringTable, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.num_string_refs = self._io.read_s2le()


    def _fetch_instances(self):
        pass
        _ = self.string_refs
        if hasattr(self, '_m_string_refs'):
            pass
            for i in range(len(self._m_string_refs)):
                pass
                self._m_string_refs[i]._fetch_instances()



    class Description(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(StringTable.Description, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.text = self._io.read_bytes_term(231, False, True, True)
            if self._io.pos() % 2 != 0:
                pass
                self.pad = self._io.read_u1()
                if not self.pad == 235:
                    raise kaitaistruct.ValidationNotEqualError(235, self.pad, self._io, u"/types/description/seq/1")



        def _fetch_instances(self):
            pass
            if self._io.pos() % 2 != 0:
                pass



    class StringRef(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(StringTable.StringRef, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.value = self._io.read_s2le()


        def _fetch_instances(self):
            pass
            _ = self.description
            if hasattr(self, '_m_description'):
                pass
                self._m_description._fetch_instances()


        @property
        def description(self):
            if hasattr(self, '_m_description'):
                return self._m_description

            io = self._parent._io
            _pos = io.pos()
            io.seek(self.value * 2)
            self._m_description = StringTable.Description(io, self, self._root)
            io.seek(_pos)
            return getattr(self, '_m_description', None)


    @property
    def string_refs(self):
        if hasattr(self, '_m_string_refs'):
            return self._m_string_refs

        _pos = self._io.pos()
        self._io.seek(0)
        self._m_string_refs = []
        for i in range(self.num_string_refs):
            self._m_string_refs.append(StringTable.StringRef(self._io, self, self._root))

        self._io.seek(_pos)
        return getattr(self, '_m_string_refs', None)


