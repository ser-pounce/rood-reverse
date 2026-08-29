# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.SMALL import img


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class ImgDis(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(ImgDis, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.sections = []
        i = 0
        while not self._io.is_eof():
            self.sections.append(ImgDis.Section(self._io, self, self._root))
            i += 1



    def _fetch_instances(self):
        pass
        for i in range(len(self.sections)):
            pass
            self.sections[i]._fetch_instances()


    class IqData(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ImgDis.IqData, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.zone_id = self._io.read_u2le()
            self.map_id = self._io.read_u2le()
            self.par_time = self._io.read_u2le()
            self.rank_cap = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class IqTable(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ImgDis.IqTable, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.iq_data = []
            i = 0
            while not self._io.is_eof():
                self.iq_data.append(ImgDis.IqData(self._io, self, self._root))
                i += 1



        def _fetch_instances(self):
            pass
            for i in range(len(self.iq_data)):
                pass
                self.iq_data[i]._fetch_instances()



    class Section(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(ImgDis.Section, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            _on = self.magic
            if _on == 16:
                pass
                self.body = img.Img.Tim(self._io)
            else:
                pass
                self.body = ImgDis.IqTable(self._io, self, self._root)


        def _fetch_instances(self):
            pass
            _on = self.magic
            if _on == 16:
                pass
                self.body._fetch_instances()
            else:
                pass
                self.body._fetch_instances()
            _ = self.magic
            if hasattr(self, '_m_magic'):
                pass


        @property
        def magic(self):
            if hasattr(self, '_m_magic'):
                return self._m_magic

            _pos = self._io.pos()
            self._io.seek(self._io.pos())
            self._m_magic = self._io.read_u4le()
            self._io.seek(_pos)
            return getattr(self, '_m_magic', None)



