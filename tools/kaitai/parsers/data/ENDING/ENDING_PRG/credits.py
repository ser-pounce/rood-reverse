# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from enum import IntEnum


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class Credits(KaitaiStruct):

    class Opcode(IntEnum):
        wait = 1
        render_text = 2
        enable_illustrations = 3
        render_special = 4
        fade_in = 5
        fade_out = 6
        freeze_scrolling = 7
        illustration_timer = 8
        end_of_stream = 255

    class SpecialOpcode(IntEnum):
        copyright = 0
        vagrant_story = 1
        fin = 2
        phantom_pain = 3
    def __init__(self, _io, _parent=None, _root=None):
        super(Credits, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.commands = []
        i = 0
        while True:
            _ = Credits.Command(self._io, self, self._root)
            self.commands.append(_)
            if _.opcode == Credits.Opcode.end_of_stream:
                break
            i += 1


    def _fetch_instances(self):
        pass
        for i in range(len(self.commands)):
            pass
            self.commands[i]._fetch_instances()


    class Command(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Credits.Command, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.opcode = KaitaiStream.resolve_enum(Credits.Opcode, self._io.read_u1())
            _on = self.opcode
            if _on == Credits.Opcode.illustration_timer:
                pass
                self.body = Credits.IllustrationTimerCommand(self._io, self, self._root)
            elif _on == Credits.Opcode.render_special:
                pass
                self.body = Credits.RenderSpecialCommand(self._io, self, self._root)
            elif _on == Credits.Opcode.render_text:
                pass
                self.body = Credits.RenderTextCommand(self._io, self, self._root)
            elif _on == Credits.Opcode.wait:
                pass
                self.body = Credits.WaitCommand(self._io, self, self._root)


        def _fetch_instances(self):
            pass
            _on = self.opcode
            if _on == Credits.Opcode.illustration_timer:
                pass
                self.body._fetch_instances()
            elif _on == Credits.Opcode.render_special:
                pass
                self.body._fetch_instances()
            elif _on == Credits.Opcode.render_text:
                pass
                self.body._fetch_instances()
            elif _on == Credits.Opcode.wait:
                pass
                self.body._fetch_instances()


    class IllustrationTimerCommand(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Credits.IllustrationTimerCommand, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.id = self._io.read_u1()
            self.duration = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class RenderSpecialCommand(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Credits.RenderSpecialCommand, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.opcode = KaitaiStream.resolve_enum(Credits.SpecialOpcode, self._io.read_u1())


        def _fetch_instances(self):
            pass


    class RenderTextCommand(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Credits.RenderTextCommand, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.len_text = self._io.read_u1()
            self.text = self._io.read_bytes(self.len_text)


        def _fetch_instances(self):
            pass


    class WaitCommand(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Credits.WaitCommand, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass



