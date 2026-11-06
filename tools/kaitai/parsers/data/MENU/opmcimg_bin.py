# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.MENU import img


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class OpmcimgBin(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(OpmcimgBin, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self._raw_title_frame = self._io.read_bytes(128)
        _io__raw_title_frame = KaitaiStream(BytesIO(self._raw_title_frame))
        self.title_frame = OpmcimgBin.TitleFrame(_io__raw_title_frame, self, self._root)
        self.icon_frame0 = self._io.read_bytes(128)
        self.pocket_station_icon = self._io.read_bytes(128)
        self.key = self._io.read_u4le()
        self.encrypted = self._io.read_bytes(8192 - 388)


    def _fetch_instances(self):
        pass
        self.title_frame._fetch_instances()

    class ArtsStatus(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.ArtsStatus, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.arts_learned = self._io.read_bytes(12)
            self.weapon_category_kills = []
            for i in range(10):
                self.weapon_category_kills.append(self._io.read_u2le())

            self.battle_abilities_unlocked = self._io.read_u2le()
            self.total_kills = self._io.read_u2le()


        def _fetch_instances(self):
            pass
            for i in range(len(self.weapon_category_kills)):
                pass



    class Character(KaitaiStruct):
        """Ashley's battle state (vs_main_characterSnapshot_t)."""
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.Character, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.restore_pending = self._io.read_s4le()
            self.current_hp = self._io.read_s2le()
            self.max_hp = self._io.read_s2le()
            self.current_mp = self._io.read_s2le()
            self.max_mp = self._io.read_s2le()
            self.strength = self._io.read_s2le()
            self.total_strength = self._io.read_s2le()
            self.intelligence = self._io.read_s2le()
            self.total_intelligence = self._io.read_s2le()
            self.agility = self._io.read_s2le()
            self.total_agility = self._io.read_s2le()
            self.risk = self._io.read_s2le()
            self.flags = self._io.read_u2le()
            self.statuses = self._io.read_u4le()
            self.status_timers = self._io.read_bytes(8)
            self.limbs = []
            for i in range(6):
                self.limbs.append(OpmcimgBin.Limb(self._io, self, self._root))

            self.weapon_drawn = self._io.read_s4le()
            self.camera_pitch = self._io.read_s4le()
            self.camera_distance = self._io.read_s4le()
            self.reserved_dc = []
            for i in range(9):
                self.reserved_dc.append(self._io.read_s4le())



        def _fetch_instances(self):
            pass
            for i in range(len(self.limbs)):
                pass
                self.limbs[i]._fetch_instances()

            for i in range(len(self.reserved_dc)):
                pass



    class DecryptedSave(KaitaiStruct):
        """Decrypted contents of OPMCIMG*.BIN from offset 0x184 (after the key) to
        the end of the 8KB block, i.e. savedata_t from info.identity.base onward.
        """
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.DecryptedSave, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.identity = OpmcimgBin.Identity(self._io, self, self._root)
            self.stats = OpmcimgBin.Stats(self._io, self, self._root)
            self.checksums = self._io.read_bytes(92)
            self.state_flags = self._io.read_bytes(1088)
            self.actions_learned = self._io.read_bytes(32)
            self.map_status = self._io.read_bytes(72)
            self.settings = OpmcimgBin.Settings(self._io, self, self._root)
            self.character = OpmcimgBin.Character(self._io, self, self._root)
            self.inventory = self._io.read_bytes(3840)
            self.inventory_indices = OpmcimgBin.InventoryIndices(self._io, self, self._root)
            self.spawn_point = OpmcimgBin.SpawnPoint(self._io, self, self._root)
            self.score_data = OpmcimgBin.ScoreData(self._io, self, self._root)
            self.zone_enemy_cache_index = self._io.read_u4le()
            self.zone_enemy_cache = []
            for i in range(4):
                self.zone_enemy_cache.append(OpmcimgBin.ZoneEnemyCache(self._io, self, self._root))

            self.arts_status = OpmcimgBin.ArtsStatus(self._io, self, self._root)
            self.unused = self._io.read_bytes(544)


        def _fetch_instances(self):
            pass
            self.identity._fetch_instances()
            self.stats._fetch_instances()
            self.settings._fetch_instances()
            self.character._fetch_instances()
            self.inventory_indices._fetch_instances()
            self.spawn_point._fetch_instances()
            self.score_data._fetch_instances()
            for i in range(len(self.zone_enemy_cache)):
                pass
                self.zone_enemy_cache[i]._fetch_instances()

            self.arts_status._fetch_instances()


    class Gametime(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.Gametime, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.f = self._io.read_s1()
            self.s = self._io.read_s1()
            self.m = self._io.read_s1()
            self.h = self._io.read_s1()


        def _fetch_instances(self):
            pass


    class Identity(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.Identity, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot_state = self._io.read_u4le()
            self.generation = self._io.read_u4le()
            self.version = self._io.read_u4le()


        def _fetch_instances(self):
            pass


    class InventoryIndices(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.InventoryIndices, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.weapons = self._io.read_bytes(8)
            self.blades = self._io.read_bytes(16)
            self.grips = self._io.read_bytes(16)
            self.shields = self._io.read_bytes(8)
            self.armor = self._io.read_bytes(16)
            self.gems = self._io.read_bytes(48)
            self.misc = self._io.read_bytes(64)


        def _fetch_instances(self):
            pass


    class Limb(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.Limb, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.hp = self._io.read_u2le()
            self.max_hp = self._io.read_u2le()
            self.types = []
            for i in range(4):
                self.types.append(self._io.read_u2le())

            self.affinities = []
            for i in range(8):
                self.affinities.append(self._io.read_u2le())



        def _fetch_instances(self):
            pass
            for i in range(len(self.types)):
                pass

            for i in range(len(self.affinities)):
                pass



    class SavedEnemyState(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.SavedEnemyState, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.index = self._io.read_u1()
            self.hidden = self._io.read_u1()
            self.actor_state = self._io.read_s2le()
            self.current_hp = self._io.read_s2le()
            self.max_hp = self._io.read_s2le()
            self.current_mp = self._io.read_s2le()
            self.max_mp = self._io.read_s2le()
            self.strength = self._io.read_s2le()
            self.intelligence = self._io.read_s2le()
            self.agility = self._io.read_s2le()
            self.limb_hp = []
            for i in range(6):
                self.limb_hp.append(self._io.read_s2le())

            self.pad = self._io.read_s2le()
            self.statuses = self._io.read_u4le()
            self.x = self._io.read_u1()
            self.direction = self._io.read_u1()
            self.z = self._io.read_u1()
            self.height = self._io.read_u1()


        def _fetch_instances(self):
            pass
            for i in range(len(self.limb_hp)):
                pass



    class ScoreData(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.ScoreData, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.titles = self._io.read_s4le()
            self.enemy_kills = []
            for i in range(6):
                self.enemy_kills.append(self._io.read_u2le())

            self.reserved10 = self._io.read_s4le()
            self.weapon_attacks = []
            for i in range(10):
                self.weapon_attacks.append(self._io.read_u2le())

            self.boss_time_trial_scores = []
            for i in range(8 * 3):
                self.boss_time_trial_scores.append(OpmcimgBin.TrialScore(self._io, self, self._root))

            self.max_chain = self._io.read_u2le()
            self.pad8a = self._io.read_u2le()
            self.clear_count = self._io.read_u4le()
            self.completion_time_minutes = self._io.read_u4le()
            self.map_completion = self._io.read_u4le()
            self.opened_chest_count = self._io.read_u4le()
            self.enemy_kill_flags = []
            for i in range(26):
                self.enemy_kill_flags.append(self._io.read_s4le())

            self.streak_score = self._io.read_u4le()
            self.misc_score = self._io.read_u4le()
            self.kill_streak_enemy_class = self._io.read_s1()
            self.kill_streak_enemy_count = self._io.read_s1()
            self.weapon_kill_streak_blade_category = self._io.read_s1()
            self.weapon_kill_streak = self._io.read_s1()
            self.chain_streak = self._io.read_u2le()
            self.heal_count = self._io.read_u2le()


        def _fetch_instances(self):
            pass
            for i in range(len(self.enemy_kills)):
                pass

            for i in range(len(self.weapon_attacks)):
                pass

            for i in range(len(self.boss_time_trial_scores)):
                pass
                self.boss_time_trial_scores[i]._fetch_instances()

            for i in range(len(self.enemy_kill_flags)):
                pass



    class Settings(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.Settings, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unk0_0 = self._io.read_bits_int_le(4)
            self.container_empty = self._io.read_bits_int_le(1) != 0
            self.ability_timing_display = self._io.read_bits_int_le(1) != 0
            self.weapon_stat_change = self._io.read_bits_int_le(1) != 0
            self.armor_stat_change = self._io.read_bits_int_le(1) != 0
            self.cursor_memory = self._io.read_s1()
            self.menu_flags = self._io.read_u2le()
            self.slot_state = self._io.read_u4le()
            self.information = self._io.read_s1()
            self.simple_map = self._io.read_s1()
            self.mono_sound = self._io.read_s1()
            self.vibration_on = self._io.read_s1()
            self.mapped_chain_abilities = self._io.read_bytes(4)
            self.mapped_defense_abilities = self._io.read_bytes(4)
            self.key = self._io.read_u4le()
            self.cumulative_save_count = self._io.read_u2le()
            self.current_game_save_count = self._io.read_u2le()
            self.save_file_generation = self._io.read_u4le()


        def _fetch_instances(self):
            pass


    class SpawnPoint(KaitaiStruct):
        """Where the player appears when the map loads (_mpdRoomDoorSection_t, the
        same record the map's door table uses).
        """
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.SpawnPoint, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.znd_id = self._io.read_u1()
            self.map_id = self._io.read_u1()
            self.unk2_0 = self._io.read_bits_int_le(5)
            self.unk2_5 = self._io.read_bits_int_le(5)
            self.unk2_10 = self._io.read_bits_int_le(3)
            self.y = self._io.read_bits_int_le(3)
            self.unk4_0 = self._io.read_bits_int_le(8)
            self.x = self._io.read_bits_int_le(5)
            self.facing = self._io.read_bits_int_le(2)
            self.unk4_15 = self._io.read_bits_int_le(1) != 0
            self.unk6_0 = self._io.read_bits_int_le(10)
            self.z = self._io.read_bits_int_le(5)
            self.unk6_15 = self._io.read_bits_int_le(1) != 0
            self.unk8 = self._io.read_bytes(4)


        def _fetch_instances(self):
            pass


    class Stats(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.Stats, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.game_time = OpmcimgBin.Gametime(self._io, self, self._root)
            self.cumulative_save_count = self._io.read_u2le()
            self.current_game_save_count = self._io.read_u2le()
            self.current_hp = self._io.read_u2le()
            self.max_hp = self._io.read_u2le()
            self.save_location = self._io.read_u1()
            self.clear_count = self._io.read_u1()
            self.map_completion = self._io.read_u1()
            self.unk1b = self._io.read_u1()
            self.current_mp = self._io.read_u2le()
            self.max_mp = self._io.read_u2le()


        def _fetch_instances(self):
            pass
            self.game_time._fetch_instances()


    class TitleFrame(KaitaiStruct):
        """PS1 memory card title frame."""
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.TitleFrame, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.magic = self._io.read_bytes(2)
            if not self.magic == b"\x53\x43":
                raise kaitaistruct.ValidationNotEqualError(b"\x53\x43", self.magic, self._io, u"/types/title_frame/seq/0")
            self.icon_flag = self._io.read_u1()
            self.block_count = self._io.read_u1()
            self.title = (self._io.read_bytes(64)).decode(u"Shift_JIS")
            self.reserved44 = self._io.read_bytes(12)
            self.pocket_station_header = self._io.read_bytes(16)
            self._raw_icon_palette = self._io.read_bytes(32)
            _io__raw_icon_palette = KaitaiStream(BytesIO(self._raw_icon_palette))
            self.icon_palette = img.Img.Clut(_io__raw_icon_palette)


        def _fetch_instances(self):
            pass
            self.icon_palette._fetch_instances()


    class TrialScore(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.TrialScore, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.time = self._io.read_bits_int_le(24)
            self.round = self._io.read_bits_int_le(7)
            self.difficulty = self._io.read_bits_int_le(1) != 0


        def _fetch_instances(self):
            pass


    class ZoneEnemyCache(KaitaiStruct):
        """Saved enemy state for one visited map. The game keeps the last four,
        ordered by lru (4 is the most recently entered, 0 is an empty record).
        """
        def __init__(self, _io, _parent=None, _root=None):
            super(OpmcimgBin.ZoneEnemyCache, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.lru = self._io.read_s1()
            self.znd_id = self._io.read_s1()
            self.map_id = self._io.read_u2le()
            self.next_slot = self._io.read_u4le()
            self.enemies = []
            for i in range(8):
                self.enemies.append(OpmcimgBin.SavedEnemyState(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.enemies)):
                pass
                self.enemies[i]._fetch_instances()




