# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class StringTable(KaitaiStruct):
    def __init__(self, offset, _io, _parent=None, _root=None):
        super(StringTable, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self.offset = offset
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



    class StringRef(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(StringTable.StringRef, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.offset = self._io.read_s2le()


        def _fetch_instances(self):
            pass
            _ = self.text
            if hasattr(self, '_m_text'):
                pass


        @property
        def text(self):
            if hasattr(self, '_m_text'):
                return self._m_text

            io = self._parent._io
            _pos = io.pos()
            io.seek(self.offset * 2)
            self._m_text = io.read_bytes_term(231, False, True, True)
            io.seek(_pos)
            return getattr(self, '_m_text', None)


    @property
    def string_refs(self):
        if hasattr(self, '_m_string_refs'):
            return self._m_string_refs

        _pos = self._io.pos()
        self._io.seek(self.offset)
        self._m_string_refs = []
        for i in range(self.num_string_refs):
            self._m_string_refs.append(StringTable.StringRef(self._io, self, self._root))

        self._io.seek(_pos)
        return getattr(self, '_m_string_refs', None)


