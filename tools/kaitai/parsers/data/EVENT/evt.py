# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO
from tools.kaitai.parsers.data.EVENT import string_table
from enum import IntEnum


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class Evt(KaitaiStruct):

    class ActorSelectorKind(IntEnum):
        by_id = 0
        slot = 1
        special = 2

    class FlagComparison(IntEnum):
        le = 0
        ge = 1
        eq = 2
        ne = 3
        lt = 4
        gt = 5
        bitwise_and = 6

    class FlagOperation(IntEnum):
        add = 0
        subtract = 1
        multiply = 2
        divide = 3
        modulo = 4
        bitwise_and = 5
        bitwise_or = 6
        assign = 7
        abs_difference = 8
        swap = 9

    class Opcode(IntEnum):
        wait_evt_load = 10
        wait_gim_load = 12
        begin_skippable = 13
        end_skippable_body = 14
        end_skip_handler = 15
        init_text_box = 16
        show_text_box = 17
        dismiss_text_box = 18
        init_text_box_near_actor = 19
        dismiss_text_box_and_wait = 20
        wait_button_pressed = 21
        load_gim = 22
        show_gim_image = 23
        tween_gim_image = 24
        unload_gim = 25
        wait_gim_tweens = 26
        set_printf_arg_int = 27
        select_text_box = 28
        set_text_box_animation_duration = 29
        actor_death = 30
        get_actor_tile = 31
        spawn_actor = 32
        walk_actor_to_tile = 33
        play_animation = 34
        set_actor_flags = 35
        set_actor_sfx_pan_volume = 36
        move_actor_to_tile = 37
        move_actor_to_coordinate = 38
        slide_actor_to_tile = 39
        slide_actor_to_coordinate = 40
        attach_actor = 41
        walk_actor_to_coordinate = 42
        turn_actor_to_facing = 43
        turn_actor_to_face_actor = 44
        turn_actor_to_face_tile = 45
        set_actor_scale = 46
        despawn_actor = 47
        wait_actor_activity = 48
        set_actor_light_color = 49
        queue_animation = 50
        rotate_actor = 51
        set_actor_look_angles = 52
        play_animation_from_frame = 53
        queue_animation_from_frame = 54
        set_actor_move_animation = 55
        set_actor_look_target = 56
        set_actor_look_position = 57
        enqueue_event_data = 58
        wait_data_queue_empty = 59
        unload_event_data = 60
        select_event_data = 61
        set_actor_edge_highlight = 62
        set_weapon_drawn = 63
        jump_fwd_unless_flag_imm = 64
        jump_fwd_unless_flag = 65
        jump_fwd_else = 66
        nop_43 = 67
        nop_44 = 68
        jump_fwd = 69
        switch_on_flag = 70
        jump_fwd_case = 71
        end_scene_reset = 72
        set_loop_counter = 73
        loop_condition = 74
        break_loop = 75
        jump_fwd_unused = 76
        modify_flag_imm = 80
        modify_flag = 81
        set_flag_to_item_count = 82
        forget_zone_enemies = 83
        play_weapon_sfx = 84
        set_actors_awake = 85
        set_flag_to_buttons = 86
        fully_restore_actor = 87
        set_ui_visible = 88
        open_menu = 89
        set_battle_timer = 90
        set_text_box_speaker = 91
        set_actor_weapon_models = 92
        set_actor_sway = 93
        wait_frames_or_button = 94
        define_easing = 95
        set_cloudstone_moving = 96
        override_fog_depth = 97
        set_first_person_rendering = 98
        status_unk = 99
        show_geometry = 100
        hide_geometry = 101
        swap_geometry_flags = 102
        set_tile_blocked = 103
        warp = 104
        screen_transition_out = 105
        screen_transition_in = 106
        set_screen_transition_wipe_angle = 107
        set_screen_transition = 108
        set_scene_visibility = 109
        wait_for_screen_transition = 110
        set_unk = 111
        transform_colors = 112
        fade_actor = 113
        draw_sheathe_ashley_weapon = 114
        set_background_visible = 115
        load_background = 116
        wait_background_load = 117
        unload_background = 118
        set_particle_effect = 119
        freeze_particle_effect = 120
        control_room_task = 121
        set_particle_effect_sound_scripted = 122
        set_background_offset = 123
        cull_occluding_geometry = 124
        adjust_geometry_depth = 125
        set_background_parallax = 126
        play_sfx = 128
        play_actor_sfx = 129
        fade_sfx_volume = 130
        stop_all_sfx = 131
        stop_sfx = 132
        load_sfx_slot = 133
        wait_sfx_load = 134
        free_sfx = 135
        set_current_sfx = 136
        load_area_music = 137
        crossfade_music = 143
        load_music_slot = 144
        free_music = 145
        play_music = 146
        fade_music_volume = 147
        ramp_music_tempo = 148
        ramp_music_pitch = 149
        stop_music = 150
        wait_music_silent = 151
        push_music_state = 152
        wait_music_load = 153
        wait_music_bar = 154
        ramp_sfx_pitch = 155
        ramp_sfx_pan = 156
        load_instrument_bank = 157
        wait_instrument_bank_load = 158
        queue_music = 159
        start_effect = 160
        trigger_effect_stage = 161
        wait_effect_state = 162
        yield_if_skipping = 163
        wait_effect_stage_ready = 164
        cancel_effect = 165
        rearm_effect_stage = 166
        set_music_target_cue = 168
        play_vibration = 169
        set_actor_trail = 170
        set_entered_door = 177
        set_flags_to_actor_distance_and_angle = 178
        set_actor_awake = 179
        show_misc_loot = 180
        remove_misc_item = 181
        set_flag_to_actor_distance = 182
        special_op = 183
        wait_screen_effects_loaded = 184
        framebuffer_effect_depth = 185
        framebuffer_effect_use_previous_frame = 186
        set_screen_blur = 187
        load_screen_effects = 188
        nop_bd = 189
        unload_screen_effects = 190
        framebuffer_effect_preset = 191
        look_at_set_destination = 192
        look_at_cut = 193
        look_at_lerp_to = 194
        look_at_arc_to = 195
        look_at_orbit_to = 196
        look_at_orbit_by = 197
        look_at_set_destination_to_actor_offset = 199
        look_at_follow_actor = 200
        look_at_lock_offset = 201
        look_at_set_destination_to_actor_local_offset = 202
        look_at_terrain_follow_to = 203
        eye_set_destination = 208
        eye_cut = 209
        eye_lerp_to = 210
        eye_arc_to = 211
        eye_orbit_to = 212
        eye_orbit_by = 213
        eye_set_destination_to_actor_offset = 215
        eye_follow_actor = 216
        eye_lock_offset = 217
        eye_set_destination_to_actor_local_offset = 218
        eye_terrain_follow_to = 219
        stop_camera = 222
        set_camera_momentum = 223
        wait_camera_idle = 224
        set_framebuffer_effect = 225
        camera_roll = 226
        framebuffer_effect_spin = 227
        framebuffer_effect_scale = 228
        framebuffer_effect_tint = 229
        framebuffer_effect_offset = 230
        framebuffer_effect_blend_mode = 231
        attach_camera_to_actor = 232
        return_to_gameplay_camera = 233
        projection_distance = 234
        near_clip = 235
        far_clip = 236
        lens_distortion = 237
        camera_shake = 239
        wait_frames = 240
        set_frame_rate = 241
        play_menu_select_sfx = 242
        set_scanlines = 243
        join_script = 244
        fork_and_jump = 245
        end_script = 246
        queue_next_evt = 247
        end_scene = 254
        end_scene_ff = 255
    def __init__(self, _io, _parent=None, _root=None):
        super(Evt, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.num_bytes = self._io.read_u2le()
        if self.num_bytes != 0:
            pass
            self.body = Evt.Body(self.num_bytes, self._io, self, self._root)

        self.padding = self._io.read_bytes_full()
        _ = self.padding
        if not  ((len(_) == 0) or (KaitaiStream.byte_array_max(_) == 0)) :
            raise kaitaistruct.ValidationExprError(self.padding, self._io, u"/seq/2")


    def _fetch_instances(self):
        pass
        if self.num_bytes != 0:
            pass
            self.body._fetch_instances()


    class ActorDeath(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ActorDeath, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.play_animation = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class ActorSelector(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ActorSelector, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.raw = self._io.read_u2le()


        def _fetch_instances(self):
            pass

        @property
        def kind(self):
            if hasattr(self, '_m_kind'):
                return self._m_kind

            self._m_kind = KaitaiStream.resolve_enum(Evt.ActorSelectorKind, self.raw >> 12)
            return getattr(self, '_m_kind', None)

        @property
        def value(self):
            if hasattr(self, '_m_value'):
                return self._m_value

            self._m_value = self.raw & 4095
            return getattr(self, '_m_value', None)


    class AdjustGeometryDepth(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.AdjustGeometryDepth, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.object = self._io.read_u1()
            self.amount = self._io.read_s1()


        def _fetch_instances(self):
            pass


    class AttachActor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.AttachActor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.parent = Evt.ActorSelector(self._io, self, self._root)
            self.bone = self._io.read_u1()
            self.unused = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()
            self.parent._fetch_instances()


    class AttachCameraToActor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.AttachCameraToActor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class BeginSkippable(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.BeginSkippable, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.reserved_flags = self._io.read_bits_int_be(7)
            self.keep_music = self._io.read_bits_int_be(1) != 0
            self.unused = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class Body(KaitaiStruct):
        def __init__(self, num_bytes, _io, _parent=None, _root=None):
            super(Evt.Body, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_bytes = num_bytes
            self._read()

        def _read(self):
            self.ofs_strings = self._io.read_u2le()
            self.ofs_shapes = self._io.read_u2le()
            self.ofs_vibration = self._io.read_u2le()
            self.reserved = self._io.read_bytes(8)
            if not self.reserved == b"\x00\x00\x00\x00\x00\x00\x00\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00\x00\x00\x00\x00\x00\x00\x00", self.reserved, self._io, u"/types/body/seq/3")
            self._raw_script = self._io.read_bytes(self.ofs_strings - 16)
            _io__raw_script = KaitaiStream(BytesIO(self._raw_script))
            self.script = Evt.Script(_io__raw_script, self, self._root)
            if self.has_strings:
                pass
                self._raw_strings = self._io.read_bytes(self.ofs_shapes - self.ofs_strings)
                _io__raw_strings = KaitaiStream(BytesIO(self._raw_strings))
                self.strings = string_table.StringTable(0, _io__raw_strings)

            self._raw_shapes = self._io.read_bytes(self.ofs_vibration - self.ofs_shapes)
            _io__raw_shapes = KaitaiStream(BytesIO(self._raw_shapes))
            self.shapes = Evt.ShapeTable(_io__raw_shapes, self, self._root)
            self._raw_vibration = self._io.read_bytes(self.num_bytes - self.ofs_vibration)
            _io__raw_vibration = KaitaiStream(BytesIO(self._raw_vibration))
            self.vibration = Evt.VibrationTable(_io__raw_vibration, self, self._root)


        def _fetch_instances(self):
            pass
            self.script._fetch_instances()
            if self.has_strings:
                pass
                self.strings._fetch_instances()

            self.shapes._fetch_instances()
            self.vibration._fetch_instances()

        @property
        def has_strings(self):
            if hasattr(self, '_m_has_strings'):
                return self._m_has_strings

            self._m_has_strings = self.ofs_shapes > self.ofs_strings
            return getattr(self, '_m_has_strings', None)


    class CameraFollowActor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CameraFollowActor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.point = self._io.read_u1()
            self.x = self._io.read_s2le()
            self.y = self._io.read_s2le()
            self.z = self._io.read_s2le()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class CameraLerpTo(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CameraLerpTo, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.easing = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class CameraLockOffset(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CameraLockOffset, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class CameraOrbitBy(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CameraOrbitBy, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.angle = self._io.read_s2le()
            self.final_height = self._io.read_s2le()
            self.distance_scale = self._io.read_u1()
            self.distance_easing = self._io.read_bits_int_be(4)
            self.angle_easing = self._io.read_bits_int_be(4)
            self.height_easing = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class CameraOrbitTo(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CameraOrbitTo, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.angle_easing = self._io.read_bits_int_be(4)
            self.direction = self._io.read_bits_int_be(4)
            self.height_easing = self._io.read_bits_int_be(4)
            self.distance_easing = self._io.read_bits_int_be(4)
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class CameraRoll(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CameraRoll, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.angle = self._io.read_s2le()
            self.easing = self._io.read_bits_int_be(4)
            self.direction = self._io.read_bits_int_be(4)
            self.duration = self._io.read_u1()
            self.unused = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class CameraSetDestinationToActorOffset(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CameraSetDestinationToActorOffset, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.point = self._io.read_u1()
            self.x = self._io.read_s2le()
            self.y = self._io.read_s2le()
            self.z = self._io.read_s2le()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class CameraShake(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CameraShake, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.oscillations = self._io.read_u1()
            self.amplitude = self._io.read_u1()
            self.z_weight = self._io.read_bits_int_be(2)
            self.y_weight = self._io.read_bits_int_be(2)
            self.x_weight = self._io.read_bits_int_be(2)
            self.shakes_eye = self._io.read_bits_int_be(1) != 0
            self.shakes_look_at = self._io.read_bits_int_be(1) != 0
            self.envelope = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class CameraTerrainFollowTo(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CameraTerrainFollowTo, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unused = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ControlRoomTask(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ControlRoomTask, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.pause_resume = self._io.read_u1()
            self.task = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class CrossfadeMusic(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CrossfadeMusic, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()
            self.volume = self._io.read_u1()
            self.fade_in = self._io.read_u1()
            self.fade_out = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class CullOccludingGeometry(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.CullOccludingGeometry, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.enabled = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class DefineEasing(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.DefineEasing, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_bits_int_be(2)
            self.base_curve = self._io.read_bits_int_be(2)
            self.squarings = self._io.read_bits_int_be(4)


        def _fetch_instances(self):
            pass


    class DespawnActor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.DespawnActor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class DismissTextBox(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.DismissTextBox, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.box_id = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class DismissTextBoxAndWait(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.DismissTextBoxAndWait, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.box_id = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class DrawSheatheAshleyWeapon(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.DrawSheatheAshleyWeapon, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.draw = self._io.read_u1()
            self.animation = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class EndScript(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.EndScript, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unused = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class EnqueueEventData(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.EnqueueEventData, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.id = self._io.read_u2le()
            self.vram_slot = self._io.read_bits_int_be(4)
            self.what = self._io.read_bits_int_be(2)
            self.slot = self._io.read_bits_int_be(2)


        def _fetch_instances(self):
            pass


    class FadeActor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FadeActor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.fade = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class FadeMusicVolume(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FadeMusicVolume, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.volume = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class FadeSfxVolume(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FadeSfxVolume, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.group = self._io.read_u1()
            self.sound = self._io.read_u1()
            self.volume = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class FarClip(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FarClip, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.distance = self._io.read_u1()
            self.easing = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ForgetZoneEnemies(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ForgetZoneEnemies, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.zone = self._io.read_u1()
            self.map = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ForkAndJump(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ForkAndJump, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()
            self.offset = self._io.read_s2le()


        def _fetch_instances(self):
            pass


    class FramebufferEffectBlendMode(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FramebufferEffectBlendMode, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.blend_mode = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class FramebufferEffectDepth(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FramebufferEffectDepth, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.depth = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class FramebufferEffectOffset(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FramebufferEffectOffset, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.x = self._io.read_s1()
            self.y = self._io.read_s1()
            self.easing = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class FramebufferEffectPreset(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FramebufferEffectPreset, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.depth = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class FramebufferEffectScale(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FramebufferEffectScale, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.x = self._io.read_u1()
            self.y = self._io.read_u1()
            self.easing = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class FramebufferEffectTint(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FramebufferEffectTint, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.r = self._io.read_u1()
            self.g = self._io.read_u1()
            self.b = self._io.read_u1()
            self.easing = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class FramebufferEffectUsePreviousFrame(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FramebufferEffectUsePreviousFrame, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.use_previous_frame = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class FreeMusic(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FreeMusic, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class FreeSfx(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FreeSfx, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class FreezeParticleEffect(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FreezeParticleEffect, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.frozen = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class FullyRestoreActor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.FullyRestoreActor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.unused = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class GetActorTile(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.GetActorTile, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.first_flag = self._io.read_u2le()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class HideGeometry(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.HideGeometry, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.object = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class InitTextBox(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.InitTextBox, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.parent_box_id = self._io.read_bits_int_be(4)
            self.box_id = self._io.read_bits_int_be(4)
            self.flags = self._io.read_u2le()
            self.x = self._io.read_u1()
            self.y = self._io.read_u1()
            self.width = self._io.read_u1()
            self.height = self._io.read_u1()
            self.speaker = Evt.ActorSelector(self._io, self, self._root)
            self.speaker_animation = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.speaker._fetch_instances()


    class InitTextBoxNearActor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.InitTextBoxNearActor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.box_id = self._io.read_u1()
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.flags = self._io.read_u2le()
            self.width = self._io.read_u1()
            self.height = self._io.read_u1()
            self.speaker_animation = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class JoinScript(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.JoinScript, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.stop = self._io.read_bits_int_be(1) != 0
            self.unused = self._io.read_bits_int_be(5)
            self.slot = self._io.read_bits_int_be(2)


        def _fetch_instances(self):
            pass


    class Jump(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.Jump, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.offset = self._io.read_s2le()


        def _fetch_instances(self):
            pass


    class JumpFwdCase(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.JumpFwdCase, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.value = self._io.read_u1()
            self.offset = self._io.read_s2le()


        def _fetch_instances(self):
            pass


    class JumpFwdUnlessFlag(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.JumpFwdUnlessFlag, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.comparison = KaitaiStream.resolve_enum(Evt.FlagComparison, self._io.read_bits_int_be(4))
            self.flag_high = self._io.read_bits_int_be(4)
            self.flag_low = self._io.read_bits_int_be(6)
            self.other_flag_high = self._io.read_bits_int_be(2)
            self.other_flag_low = self._io.read_u1()
            self.offset = self._io.read_s2le()


        def _fetch_instances(self):
            pass

        @property
        def flag(self):
            if hasattr(self, '_m_flag'):
                return self._m_flag

            self._m_flag = self.flag_high << 6 | self.flag_low
            return getattr(self, '_m_flag', None)

        @property
        def other_flag(self):
            if hasattr(self, '_m_other_flag'):
                return self._m_other_flag

            self._m_other_flag = self.other_flag_high << 8 | self.other_flag_low
            return getattr(self, '_m_other_flag', None)


    class JumpFwdUnlessFlagImm(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.JumpFwdUnlessFlagImm, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.comparison = KaitaiStream.resolve_enum(Evt.FlagComparison, self._io.read_bits_int_be(4))
            self.flag_high = self._io.read_bits_int_be(4)
            self.flag_low = self._io.read_bits_int_be(6)
            self.unused = self._io.read_bits_int_be(2)
            self.value = self._io.read_s1()
            self.offset = self._io.read_s2le()


        def _fetch_instances(self):
            pass

        @property
        def flag(self):
            if hasattr(self, '_m_flag'):
                return self._m_flag

            self._m_flag = self.flag_high << 6 | self.flag_low
            return getattr(self, '_m_flag', None)


    class LensDistortion(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.LensDistortion, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.zoom = self._io.read_u1()
            self.distortion = self._io.read_s1()
            self.easing = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class LoadBackground(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.LoadBackground, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.texture_page_slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class LoadGim(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.LoadGim, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.index = self._io.read_u2le()
            self.first_vram_page_slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class LoadInstrumentBank(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.LoadInstrumentBank, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.music = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class LoadMusicSlot(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.LoadMusicSlot, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.music = self._io.read_u1()
            self.slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class LoadSfxSlot(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.LoadSfxSlot, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.file = self._io.read_u1()
            self.slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class LoopCondition(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.LoopCondition, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.counter = self._io.read_u1()
            self.offset_back = self._io.read_s2le()


        def _fetch_instances(self):
            pass


    class ModifyFlag(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ModifyFlag, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.operation = KaitaiStream.resolve_enum(Evt.FlagOperation, self._io.read_bits_int_be(4))
            self.flag_high = self._io.read_bits_int_be(4)
            self.flag_low = self._io.read_bits_int_be(6)
            self.other_flag_high = self._io.read_bits_int_be(2)
            self.other_flag_low = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ModifyFlagImm(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ModifyFlagImm, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.operation = KaitaiStream.resolve_enum(Evt.FlagOperation, self._io.read_bits_int_be(4))
            self.flag_high = self._io.read_bits_int_be(4)
            self.flag_low = self._io.read_bits_int_be(6)
            self.unused = self._io.read_bits_int_be(2)
            self.value = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class MoveActorToCoordinate(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.MoveActorToCoordinate, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.x = self._io.read_u2le()
            self.y = self._io.read_s2le()
            self.z = self._io.read_s2le()
            self.facing = self._io.read_u1()
            self.move_frames = self._io.read_u1()
            self.turn_frames = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class MoveActorToTile(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.MoveActorToTile, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.tile_x = self._io.read_u1()
            self.tile_surface = self._io.read_u1()
            self.tile_z = self._io.read_u1()
            self.facing = self._io.read_u1()
            self.move_frames = self._io.read_u1()
            self.turn_frames = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class NearClip(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.NearClip, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.distance = self._io.read_u1()
            self.easing = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class NoOperands(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.NoOperands, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            pass


        def _fetch_instances(self):
            pass


    class Nop44(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.Nop44, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unused = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class NopBd(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.NopBd, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unused = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class Op(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.Op, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.opcode = KaitaiStream.resolve_enum(Evt.Opcode, self._io.read_u1())
            _on = self.opcode
            if _on == Evt.Opcode.actor_death:
                pass
                self.operands = Evt.ActorDeath(self._io, self, self._root)
            elif _on == Evt.Opcode.adjust_geometry_depth:
                pass
                self.operands = Evt.AdjustGeometryDepth(self._io, self, self._root)
            elif _on == Evt.Opcode.attach_actor:
                pass
                self.operands = Evt.AttachActor(self._io, self, self._root)
            elif _on == Evt.Opcode.attach_camera_to_actor:
                pass
                self.operands = Evt.AttachCameraToActor(self._io, self, self._root)
            elif _on == Evt.Opcode.begin_skippable:
                pass
                self.operands = Evt.BeginSkippable(self._io, self, self._root)
            elif _on == Evt.Opcode.break_loop:
                pass
                self.operands = Evt.Jump(self._io, self, self._root)
            elif _on == Evt.Opcode.camera_roll:
                pass
                self.operands = Evt.CameraRoll(self._io, self, self._root)
            elif _on == Evt.Opcode.camera_shake:
                pass
                self.operands = Evt.CameraShake(self._io, self, self._root)
            elif _on == Evt.Opcode.cancel_effect:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.control_room_task:
                pass
                self.operands = Evt.ControlRoomTask(self._io, self, self._root)
            elif _on == Evt.Opcode.crossfade_music:
                pass
                self.operands = Evt.CrossfadeMusic(self._io, self, self._root)
            elif _on == Evt.Opcode.cull_occluding_geometry:
                pass
                self.operands = Evt.CullOccludingGeometry(self._io, self, self._root)
            elif _on == Evt.Opcode.define_easing:
                pass
                self.operands = Evt.DefineEasing(self._io, self, self._root)
            elif _on == Evt.Opcode.despawn_actor:
                pass
                self.operands = Evt.DespawnActor(self._io, self, self._root)
            elif _on == Evt.Opcode.dismiss_text_box:
                pass
                self.operands = Evt.DismissTextBox(self._io, self, self._root)
            elif _on == Evt.Opcode.dismiss_text_box_and_wait:
                pass
                self.operands = Evt.DismissTextBoxAndWait(self._io, self, self._root)
            elif _on == Evt.Opcode.draw_sheathe_ashley_weapon:
                pass
                self.operands = Evt.DrawSheatheAshleyWeapon(self._io, self, self._root)
            elif _on == Evt.Opcode.end_scene:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.end_scene_ff:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.end_scene_reset:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.end_script:
                pass
                self.operands = Evt.EndScript(self._io, self, self._root)
            elif _on == Evt.Opcode.end_skip_handler:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.end_skippable_body:
                pass
                self.operands = Evt.Jump(self._io, self, self._root)
            elif _on == Evt.Opcode.enqueue_event_data:
                pass
                self.operands = Evt.EnqueueEventData(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_arc_to:
                pass
                self.operands = Evt.CameraLerpTo(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_cut:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_follow_actor:
                pass
                self.operands = Evt.CameraFollowActor(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_lerp_to:
                pass
                self.operands = Evt.CameraLerpTo(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_lock_offset:
                pass
                self.operands = Evt.CameraLockOffset(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_orbit_by:
                pass
                self.operands = Evt.CameraOrbitBy(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_orbit_to:
                pass
                self.operands = Evt.CameraOrbitTo(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_set_destination:
                pass
                self.operands = Evt.SetCameraDestination(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_set_destination_to_actor_local_offset:
                pass
                self.operands = Evt.CameraSetDestinationToActorOffset(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_set_destination_to_actor_offset:
                pass
                self.operands = Evt.CameraSetDestinationToActorOffset(self._io, self, self._root)
            elif _on == Evt.Opcode.eye_terrain_follow_to:
                pass
                self.operands = Evt.CameraTerrainFollowTo(self._io, self, self._root)
            elif _on == Evt.Opcode.fade_actor:
                pass
                self.operands = Evt.FadeActor(self._io, self, self._root)
            elif _on == Evt.Opcode.fade_music_volume:
                pass
                self.operands = Evt.FadeMusicVolume(self._io, self, self._root)
            elif _on == Evt.Opcode.fade_sfx_volume:
                pass
                self.operands = Evt.FadeSfxVolume(self._io, self, self._root)
            elif _on == Evt.Opcode.far_clip:
                pass
                self.operands = Evt.FarClip(self._io, self, self._root)
            elif _on == Evt.Opcode.forget_zone_enemies:
                pass
                self.operands = Evt.ForgetZoneEnemies(self._io, self, self._root)
            elif _on == Evt.Opcode.fork_and_jump:
                pass
                self.operands = Evt.ForkAndJump(self._io, self, self._root)
            elif _on == Evt.Opcode.framebuffer_effect_blend_mode:
                pass
                self.operands = Evt.FramebufferEffectBlendMode(self._io, self, self._root)
            elif _on == Evt.Opcode.framebuffer_effect_depth:
                pass
                self.operands = Evt.FramebufferEffectDepth(self._io, self, self._root)
            elif _on == Evt.Opcode.framebuffer_effect_offset:
                pass
                self.operands = Evt.FramebufferEffectOffset(self._io, self, self._root)
            elif _on == Evt.Opcode.framebuffer_effect_preset:
                pass
                self.operands = Evt.FramebufferEffectPreset(self._io, self, self._root)
            elif _on == Evt.Opcode.framebuffer_effect_scale:
                pass
                self.operands = Evt.FramebufferEffectScale(self._io, self, self._root)
            elif _on == Evt.Opcode.framebuffer_effect_spin:
                pass
                self.operands = Evt.CameraRoll(self._io, self, self._root)
            elif _on == Evt.Opcode.framebuffer_effect_tint:
                pass
                self.operands = Evt.FramebufferEffectTint(self._io, self, self._root)
            elif _on == Evt.Opcode.framebuffer_effect_use_previous_frame:
                pass
                self.operands = Evt.FramebufferEffectUsePreviousFrame(self._io, self, self._root)
            elif _on == Evt.Opcode.free_music:
                pass
                self.operands = Evt.FreeMusic(self._io, self, self._root)
            elif _on == Evt.Opcode.free_sfx:
                pass
                self.operands = Evt.FreeSfx(self._io, self, self._root)
            elif _on == Evt.Opcode.freeze_particle_effect:
                pass
                self.operands = Evt.FreezeParticleEffect(self._io, self, self._root)
            elif _on == Evt.Opcode.fully_restore_actor:
                pass
                self.operands = Evt.FullyRestoreActor(self._io, self, self._root)
            elif _on == Evt.Opcode.get_actor_tile:
                pass
                self.operands = Evt.GetActorTile(self._io, self, self._root)
            elif _on == Evt.Opcode.hide_geometry:
                pass
                self.operands = Evt.HideGeometry(self._io, self, self._root)
            elif _on == Evt.Opcode.init_text_box:
                pass
                self.operands = Evt.InitTextBox(self._io, self, self._root)
            elif _on == Evt.Opcode.init_text_box_near_actor:
                pass
                self.operands = Evt.InitTextBoxNearActor(self._io, self, self._root)
            elif _on == Evt.Opcode.join_script:
                pass
                self.operands = Evt.JoinScript(self._io, self, self._root)
            elif _on == Evt.Opcode.jump_fwd:
                pass
                self.operands = Evt.Jump(self._io, self, self._root)
            elif _on == Evt.Opcode.jump_fwd_case:
                pass
                self.operands = Evt.JumpFwdCase(self._io, self, self._root)
            elif _on == Evt.Opcode.jump_fwd_else:
                pass
                self.operands = Evt.Jump(self._io, self, self._root)
            elif _on == Evt.Opcode.jump_fwd_unless_flag:
                pass
                self.operands = Evt.JumpFwdUnlessFlag(self._io, self, self._root)
            elif _on == Evt.Opcode.jump_fwd_unless_flag_imm:
                pass
                self.operands = Evt.JumpFwdUnlessFlagImm(self._io, self, self._root)
            elif _on == Evt.Opcode.jump_fwd_unused:
                pass
                self.operands = Evt.Jump(self._io, self, self._root)
            elif _on == Evt.Opcode.lens_distortion:
                pass
                self.operands = Evt.LensDistortion(self._io, self, self._root)
            elif _on == Evt.Opcode.load_area_music:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.load_background:
                pass
                self.operands = Evt.LoadBackground(self._io, self, self._root)
            elif _on == Evt.Opcode.load_gim:
                pass
                self.operands = Evt.LoadGim(self._io, self, self._root)
            elif _on == Evt.Opcode.load_instrument_bank:
                pass
                self.operands = Evt.LoadInstrumentBank(self._io, self, self._root)
            elif _on == Evt.Opcode.load_music_slot:
                pass
                self.operands = Evt.LoadMusicSlot(self._io, self, self._root)
            elif _on == Evt.Opcode.load_screen_effects:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.load_sfx_slot:
                pass
                self.operands = Evt.LoadSfxSlot(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_arc_to:
                pass
                self.operands = Evt.CameraLerpTo(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_cut:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_follow_actor:
                pass
                self.operands = Evt.CameraFollowActor(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_lerp_to:
                pass
                self.operands = Evt.CameraLerpTo(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_lock_offset:
                pass
                self.operands = Evt.CameraLockOffset(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_orbit_by:
                pass
                self.operands = Evt.CameraOrbitBy(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_orbit_to:
                pass
                self.operands = Evt.CameraOrbitTo(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_set_destination:
                pass
                self.operands = Evt.SetCameraDestination(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_set_destination_to_actor_local_offset:
                pass
                self.operands = Evt.CameraSetDestinationToActorOffset(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_set_destination_to_actor_offset:
                pass
                self.operands = Evt.CameraSetDestinationToActorOffset(self._io, self, self._root)
            elif _on == Evt.Opcode.look_at_terrain_follow_to:
                pass
                self.operands = Evt.CameraTerrainFollowTo(self._io, self, self._root)
            elif _on == Evt.Opcode.loop_condition:
                pass
                self.operands = Evt.LoopCondition(self._io, self, self._root)
            elif _on == Evt.Opcode.modify_flag:
                pass
                self.operands = Evt.ModifyFlag(self._io, self, self._root)
            elif _on == Evt.Opcode.modify_flag_imm:
                pass
                self.operands = Evt.ModifyFlagImm(self._io, self, self._root)
            elif _on == Evt.Opcode.move_actor_to_coordinate:
                pass
                self.operands = Evt.MoveActorToCoordinate(self._io, self, self._root)
            elif _on == Evt.Opcode.move_actor_to_tile:
                pass
                self.operands = Evt.MoveActorToTile(self._io, self, self._root)
            elif _on == Evt.Opcode.near_clip:
                pass
                self.operands = Evt.NearClip(self._io, self, self._root)
            elif _on == Evt.Opcode.nop_43:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.nop_44:
                pass
                self.operands = Evt.Nop44(self._io, self, self._root)
            elif _on == Evt.Opcode.nop_bd:
                pass
                self.operands = Evt.NopBd(self._io, self, self._root)
            elif _on == Evt.Opcode.open_menu:
                pass
                self.operands = Evt.OpenMenu(self._io, self, self._root)
            elif _on == Evt.Opcode.override_fog_depth:
                pass
                self.operands = Evt.OverrideFogDepth(self._io, self, self._root)
            elif _on == Evt.Opcode.play_actor_sfx:
                pass
                self.operands = Evt.PlayActorSfx(self._io, self, self._root)
            elif _on == Evt.Opcode.play_animation:
                pass
                self.operands = Evt.PlayAnimation(self._io, self, self._root)
            elif _on == Evt.Opcode.play_animation_from_frame:
                pass
                self.operands = Evt.PlayAnimationFromFrame(self._io, self, self._root)
            elif _on == Evt.Opcode.play_menu_select_sfx:
                pass
                self.operands = Evt.PlayMenuSelectSfx(self._io, self, self._root)
            elif _on == Evt.Opcode.play_music:
                pass
                self.operands = Evt.PlayMusic(self._io, self, self._root)
            elif _on == Evt.Opcode.play_sfx:
                pass
                self.operands = Evt.PlaySfx(self._io, self, self._root)
            elif _on == Evt.Opcode.play_vibration:
                pass
                self.operands = Evt.PlayVibration(self._io, self, self._root)
            elif _on == Evt.Opcode.play_weapon_sfx:
                pass
                self.operands = Evt.PlayWeaponSfx(self._io, self, self._root)
            elif _on == Evt.Opcode.projection_distance:
                pass
                self.operands = Evt.ProjectionDistance(self._io, self, self._root)
            elif _on == Evt.Opcode.push_music_state:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.queue_animation:
                pass
                self.operands = Evt.QueueAnimation(self._io, self, self._root)
            elif _on == Evt.Opcode.queue_animation_from_frame:
                pass
                self.operands = Evt.QueueAnimationFromFrame(self._io, self, self._root)
            elif _on == Evt.Opcode.queue_music:
                pass
                self.operands = Evt.QueueMusic(self._io, self, self._root)
            elif _on == Evt.Opcode.queue_next_evt:
                pass
                self.operands = Evt.QueueNextEvt(self._io, self, self._root)
            elif _on == Evt.Opcode.ramp_music_pitch:
                pass
                self.operands = Evt.RampMusicPitch(self._io, self, self._root)
            elif _on == Evt.Opcode.ramp_music_tempo:
                pass
                self.operands = Evt.RampMusicTempo(self._io, self, self._root)
            elif _on == Evt.Opcode.ramp_sfx_pan:
                pass
                self.operands = Evt.RampSfxPan(self._io, self, self._root)
            elif _on == Evt.Opcode.ramp_sfx_pitch:
                pass
                self.operands = Evt.RampSfxPitch(self._io, self, self._root)
            elif _on == Evt.Opcode.rearm_effect_stage:
                pass
                self.operands = Evt.RearmEffectStage(self._io, self, self._root)
            elif _on == Evt.Opcode.remove_misc_item:
                pass
                self.operands = Evt.RemoveMiscItem(self._io, self, self._root)
            elif _on == Evt.Opcode.return_to_gameplay_camera:
                pass
                self.operands = Evt.ReturnToGameplayCamera(self._io, self, self._root)
            elif _on == Evt.Opcode.rotate_actor:
                pass
                self.operands = Evt.RotateActor(self._io, self, self._root)
            elif _on == Evt.Opcode.screen_transition_in:
                pass
                self.operands = Evt.ScreenTransitionIn(self._io, self, self._root)
            elif _on == Evt.Opcode.screen_transition_out:
                pass
                self.operands = Evt.ScreenTransitionOut(self._io, self, self._root)
            elif _on == Evt.Opcode.select_event_data:
                pass
                self.operands = Evt.SelectEventData(self._io, self, self._root)
            elif _on == Evt.Opcode.select_text_box:
                pass
                self.operands = Evt.SelectTextBox(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_awake:
                pass
                self.operands = Evt.SetActorAwake(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_edge_highlight:
                pass
                self.operands = Evt.SetActorEdgeHighlight(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_flags:
                pass
                self.operands = Evt.SetActorFlags(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_light_color:
                pass
                self.operands = Evt.SetActorLightColor(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_look_angles:
                pass
                self.operands = Evt.SetActorLookAngles(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_look_position:
                pass
                self.operands = Evt.SetActorLookPosition(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_look_target:
                pass
                self.operands = Evt.SetActorLookTarget(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_move_animation:
                pass
                self.operands = Evt.SetActorMoveAnimation(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_scale:
                pass
                self.operands = Evt.SetActorScale(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_sfx_pan_volume:
                pass
                self.operands = Evt.SetActorSfxPanVolume(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_sway:
                pass
                self.operands = Evt.SetActorSway(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_trail:
                pass
                self.operands = Evt.SetActorTrail(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actor_weapon_models:
                pass
                self.operands = Evt.SetActorWeaponModels(self._io, self, self._root)
            elif _on == Evt.Opcode.set_actors_awake:
                pass
                self.operands = Evt.SetActorsAwake(self._io, self, self._root)
            elif _on == Evt.Opcode.set_background_offset:
                pass
                self.operands = Evt.SetBackgroundOffset(self._io, self, self._root)
            elif _on == Evt.Opcode.set_background_parallax:
                pass
                self.operands = Evt.SetBackgroundParallax(self._io, self, self._root)
            elif _on == Evt.Opcode.set_background_visible:
                pass
                self.operands = Evt.SetBackgroundVisible(self._io, self, self._root)
            elif _on == Evt.Opcode.set_battle_timer:
                pass
                self.operands = Evt.SetBattleTimer(self._io, self, self._root)
            elif _on == Evt.Opcode.set_camera_momentum:
                pass
                self.operands = Evt.SetCameraMomentum(self._io, self, self._root)
            elif _on == Evt.Opcode.set_cloudstone_moving:
                pass
                self.operands = Evt.SetCloudstoneMoving(self._io, self, self._root)
            elif _on == Evt.Opcode.set_current_sfx:
                pass
                self.operands = Evt.SetCurrentSfx(self._io, self, self._root)
            elif _on == Evt.Opcode.set_entered_door:
                pass
                self.operands = Evt.SetEnteredDoor(self._io, self, self._root)
            elif _on == Evt.Opcode.set_first_person_rendering:
                pass
                self.operands = Evt.SetFirstPersonRendering(self._io, self, self._root)
            elif _on == Evt.Opcode.set_flag_to_actor_distance:
                pass
                self.operands = Evt.SetFlagToActorDistance(self._io, self, self._root)
            elif _on == Evt.Opcode.set_flag_to_buttons:
                pass
                self.operands = Evt.SetFlagToButtons(self._io, self, self._root)
            elif _on == Evt.Opcode.set_flag_to_item_count:
                pass
                self.operands = Evt.SetFlagToItemCount(self._io, self, self._root)
            elif _on == Evt.Opcode.set_flags_to_actor_distance_and_angle:
                pass
                self.operands = Evt.SetFlagsToActorDistanceAndAngle(self._io, self, self._root)
            elif _on == Evt.Opcode.set_frame_rate:
                pass
                self.operands = Evt.SetFrameRate(self._io, self, self._root)
            elif _on == Evt.Opcode.set_framebuffer_effect:
                pass
                self.operands = Evt.SetFramebufferEffect(self._io, self, self._root)
            elif _on == Evt.Opcode.set_loop_counter:
                pass
                self.operands = Evt.SetLoopCounter(self._io, self, self._root)
            elif _on == Evt.Opcode.set_music_target_cue:
                pass
                self.operands = Evt.SetMusicTargetCue(self._io, self, self._root)
            elif _on == Evt.Opcode.set_particle_effect:
                pass
                self.operands = Evt.SetParticleEffect(self._io, self, self._root)
            elif _on == Evt.Opcode.set_particle_effect_sound_scripted:
                pass
                self.operands = Evt.SetParticleEffectSoundScripted(self._io, self, self._root)
            elif _on == Evt.Opcode.set_printf_arg_int:
                pass
                self.operands = Evt.SetPrintfArgInt(self._io, self, self._root)
            elif _on == Evt.Opcode.set_scanlines:
                pass
                self.operands = Evt.SetScanlines(self._io, self, self._root)
            elif _on == Evt.Opcode.set_scene_visibility:
                pass
                self.operands = Evt.SetSceneVisibility(self._io, self, self._root)
            elif _on == Evt.Opcode.set_screen_blur:
                pass
                self.operands = Evt.SetScreenBlur(self._io, self, self._root)
            elif _on == Evt.Opcode.set_screen_transition:
                pass
                self.operands = Evt.SetScreenTransition(self._io, self, self._root)
            elif _on == Evt.Opcode.set_screen_transition_wipe_angle:
                pass
                self.operands = Evt.SetScreenTransitionWipeAngle(self._io, self, self._root)
            elif _on == Evt.Opcode.set_text_box_animation_duration:
                pass
                self.operands = Evt.SetTextBoxAnimationDuration(self._io, self, self._root)
            elif _on == Evt.Opcode.set_text_box_speaker:
                pass
                self.operands = Evt.SetTextBoxSpeaker(self._io, self, self._root)
            elif _on == Evt.Opcode.set_tile_blocked:
                pass
                self.operands = Evt.SetTileBlocked(self._io, self, self._root)
            elif _on == Evt.Opcode.set_ui_visible:
                pass
                self.operands = Evt.SetUiVisible(self._io, self, self._root)
            elif _on == Evt.Opcode.set_unk:
                pass
                self.operands = Evt.SetUnk(self._io, self, self._root)
            elif _on == Evt.Opcode.set_weapon_drawn:
                pass
                self.operands = Evt.SetWeaponDrawn(self._io, self, self._root)
            elif _on == Evt.Opcode.show_geometry:
                pass
                self.operands = Evt.ShowGeometry(self._io, self, self._root)
            elif _on == Evt.Opcode.show_gim_image:
                pass
                self.operands = Evt.ShowGimImage(self._io, self, self._root)
            elif _on == Evt.Opcode.show_misc_loot:
                pass
                self.operands = Evt.ShowMiscLoot(self._io, self, self._root)
            elif _on == Evt.Opcode.show_text_box:
                pass
                self.operands = Evt.ShowTextBox(self._io, self, self._root)
            elif _on == Evt.Opcode.slide_actor_to_coordinate:
                pass
                self.operands = Evt.SlideActorToCoordinate(self._io, self, self._root)
            elif _on == Evt.Opcode.slide_actor_to_tile:
                pass
                self.operands = Evt.SlideActorToTile(self._io, self, self._root)
            elif _on == Evt.Opcode.spawn_actor:
                pass
                self.operands = Evt.SpawnActor(self._io, self, self._root)
            elif _on == Evt.Opcode.special_op:
                pass
                self.operands = Evt.SpecialOp(self._io, self, self._root)
            elif _on == Evt.Opcode.start_effect:
                pass
                self.operands = Evt.StartEffect(self._io, self, self._root)
            elif _on == Evt.Opcode.status_unk:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.stop_all_sfx:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.stop_camera:
                pass
                self.operands = Evt.StopCamera(self._io, self, self._root)
            elif _on == Evt.Opcode.stop_music:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.stop_sfx:
                pass
                self.operands = Evt.StopSfx(self._io, self, self._root)
            elif _on == Evt.Opcode.swap_geometry_flags:
                pass
                self.operands = Evt.SwapGeometryFlags(self._io, self, self._root)
            elif _on == Evt.Opcode.switch_on_flag:
                pass
                self.operands = Evt.SwitchOnFlag(self._io, self, self._root)
            elif _on == Evt.Opcode.transform_colors:
                pass
                self.operands = Evt.TransformColors(self._io, self, self._root)
            elif _on == Evt.Opcode.trigger_effect_stage:
                pass
                self.operands = Evt.TriggerEffectStage(self._io, self, self._root)
            elif _on == Evt.Opcode.turn_actor_to_face_actor:
                pass
                self.operands = Evt.TurnActorToFaceActor(self._io, self, self._root)
            elif _on == Evt.Opcode.turn_actor_to_face_tile:
                pass
                self.operands = Evt.TurnActorToFaceTile(self._io, self, self._root)
            elif _on == Evt.Opcode.turn_actor_to_facing:
                pass
                self.operands = Evt.TurnActorToFacing(self._io, self, self._root)
            elif _on == Evt.Opcode.tween_gim_image:
                pass
                self.operands = Evt.TweenGimImage(self._io, self, self._root)
            elif _on == Evt.Opcode.unload_background:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.unload_event_data:
                pass
                self.operands = Evt.UnloadEventData(self._io, self, self._root)
            elif _on == Evt.Opcode.unload_gim:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.unload_screen_effects:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_actor_activity:
                pass
                self.operands = Evt.WaitActorActivity(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_background_load:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_button_pressed:
                pass
                self.operands = Evt.WaitButtonPressed(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_camera_idle:
                pass
                self.operands = Evt.WaitCameraIdle(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_data_queue_empty:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_effect_stage_ready:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_effect_state:
                pass
                self.operands = Evt.WaitEffectState(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_evt_load:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_for_screen_transition:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_frames:
                pass
                self.operands = Evt.WaitFrames(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_frames_or_button:
                pass
                self.operands = Evt.WaitFramesOrButton(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_gim_load:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_gim_tweens:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_instrument_bank_load:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_music_bar:
                pass
                self.operands = Evt.WaitMusicBar(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_music_load:
                pass
                self.operands = Evt.WaitMusicLoad(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_music_silent:
                pass
                self.operands = Evt.WaitMusicSilent(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_screen_effects_loaded:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            elif _on == Evt.Opcode.wait_sfx_load:
                pass
                self.operands = Evt.WaitSfxLoad(self._io, self, self._root)
            elif _on == Evt.Opcode.walk_actor_to_coordinate:
                pass
                self.operands = Evt.WalkActorToCoordinate(self._io, self, self._root)
            elif _on == Evt.Opcode.walk_actor_to_tile:
                pass
                self.operands = Evt.WalkActorToTile(self._io, self, self._root)
            elif _on == Evt.Opcode.warp:
                pass
                self.operands = Evt.Warp(self._io, self, self._root)
            elif _on == Evt.Opcode.yield_if_skipping:
                pass
                self.operands = Evt.NoOperands(self._io, self, self._root)
            else:
                pass
                self.operands = Evt.Unparsed(self._io, self, self._root)


        def _fetch_instances(self):
            pass
            _on = self.opcode
            if _on == Evt.Opcode.actor_death:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.adjust_geometry_depth:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.attach_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.attach_camera_to_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.begin_skippable:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.break_loop:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.camera_roll:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.camera_shake:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.cancel_effect:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.control_room_task:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.crossfade_music:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.cull_occluding_geometry:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.define_easing:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.despawn_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.dismiss_text_box:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.dismiss_text_box_and_wait:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.draw_sheathe_ashley_weapon:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.end_scene:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.end_scene_ff:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.end_scene_reset:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.end_script:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.end_skip_handler:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.end_skippable_body:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.enqueue_event_data:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_arc_to:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_cut:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_follow_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_lerp_to:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_lock_offset:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_orbit_by:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_orbit_to:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_set_destination:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_set_destination_to_actor_local_offset:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_set_destination_to_actor_offset:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.eye_terrain_follow_to:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.fade_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.fade_music_volume:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.fade_sfx_volume:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.far_clip:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.forget_zone_enemies:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.fork_and_jump:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.framebuffer_effect_blend_mode:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.framebuffer_effect_depth:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.framebuffer_effect_offset:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.framebuffer_effect_preset:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.framebuffer_effect_scale:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.framebuffer_effect_spin:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.framebuffer_effect_tint:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.framebuffer_effect_use_previous_frame:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.free_music:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.free_sfx:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.freeze_particle_effect:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.fully_restore_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.get_actor_tile:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.hide_geometry:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.init_text_box:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.init_text_box_near_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.join_script:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.jump_fwd:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.jump_fwd_case:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.jump_fwd_else:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.jump_fwd_unless_flag:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.jump_fwd_unless_flag_imm:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.jump_fwd_unused:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.lens_distortion:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.load_area_music:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.load_background:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.load_gim:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.load_instrument_bank:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.load_music_slot:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.load_screen_effects:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.load_sfx_slot:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_arc_to:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_cut:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_follow_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_lerp_to:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_lock_offset:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_orbit_by:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_orbit_to:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_set_destination:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_set_destination_to_actor_local_offset:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_set_destination_to_actor_offset:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.look_at_terrain_follow_to:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.loop_condition:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.modify_flag:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.modify_flag_imm:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.move_actor_to_coordinate:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.move_actor_to_tile:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.near_clip:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.nop_43:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.nop_44:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.nop_bd:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.open_menu:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.override_fog_depth:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.play_actor_sfx:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.play_animation:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.play_animation_from_frame:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.play_menu_select_sfx:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.play_music:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.play_sfx:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.play_vibration:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.play_weapon_sfx:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.projection_distance:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.push_music_state:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.queue_animation:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.queue_animation_from_frame:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.queue_music:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.queue_next_evt:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.ramp_music_pitch:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.ramp_music_tempo:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.ramp_sfx_pan:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.ramp_sfx_pitch:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.rearm_effect_stage:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.remove_misc_item:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.return_to_gameplay_camera:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.rotate_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.screen_transition_in:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.screen_transition_out:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.select_event_data:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.select_text_box:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_awake:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_edge_highlight:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_flags:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_light_color:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_look_angles:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_look_position:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_look_target:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_move_animation:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_scale:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_sfx_pan_volume:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_sway:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_trail:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actor_weapon_models:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_actors_awake:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_background_offset:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_background_parallax:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_background_visible:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_battle_timer:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_camera_momentum:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_cloudstone_moving:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_current_sfx:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_entered_door:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_first_person_rendering:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_flag_to_actor_distance:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_flag_to_buttons:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_flag_to_item_count:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_flags_to_actor_distance_and_angle:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_frame_rate:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_framebuffer_effect:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_loop_counter:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_music_target_cue:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_particle_effect:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_particle_effect_sound_scripted:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_printf_arg_int:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_scanlines:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_scene_visibility:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_screen_blur:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_screen_transition:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_screen_transition_wipe_angle:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_text_box_animation_duration:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_text_box_speaker:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_tile_blocked:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_ui_visible:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_unk:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.set_weapon_drawn:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.show_geometry:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.show_gim_image:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.show_misc_loot:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.show_text_box:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.slide_actor_to_coordinate:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.slide_actor_to_tile:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.spawn_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.special_op:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.start_effect:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.status_unk:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.stop_all_sfx:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.stop_camera:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.stop_music:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.stop_sfx:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.swap_geometry_flags:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.switch_on_flag:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.transform_colors:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.trigger_effect_stage:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.turn_actor_to_face_actor:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.turn_actor_to_face_tile:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.turn_actor_to_facing:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.tween_gim_image:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.unload_background:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.unload_event_data:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.unload_gim:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.unload_screen_effects:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_actor_activity:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_background_load:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_button_pressed:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_camera_idle:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_data_queue_empty:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_effect_stage_ready:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_effect_state:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_evt_load:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_for_screen_transition:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_frames:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_frames_or_button:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_gim_load:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_gim_tweens:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_instrument_bank_load:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_music_bar:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_music_load:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_music_silent:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_screen_effects_loaded:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.wait_sfx_load:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.walk_actor_to_coordinate:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.walk_actor_to_tile:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.warp:
                pass
                self.operands._fetch_instances()
            elif _on == Evt.Opcode.yield_if_skipping:
                pass
                self.operands._fetch_instances()
            else:
                pass
                self.operands._fetch_instances()


    class OpenMenu(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.OpenMenu, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.menu = self._io.read_u1()
            self.unused = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class OverrideFogDepth(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.OverrideFogDepth, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.depth = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class PlayActorSfx(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.PlayActorSfx, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.type = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class PlayAnimation(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.PlayAnimation, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.animation = self._io.read_u1()
            self.unused = self._io.read_u1()
            self.bank = self._io.read_bits_int_be(2)
            self.blend_frames = self._io.read_bits_int_be(6)


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class PlayAnimationFromFrame(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.PlayAnimationFromFrame, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.animation = self._io.read_u1()
            self.frame = self._io.read_u1()
            self.unused = self._io.read_u1()
            self.bank = self._io.read_bits_int_be(2)
            self.blend_frames = self._io.read_bits_int_be(6)


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class PlayMenuSelectSfx(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.PlayMenuSelectSfx, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unused = self._io.read_u4le()


        def _fetch_instances(self):
            pass


    class PlayMusic(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.PlayMusic, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()
            self.volume = self._io.read_u1()
            self.fade = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class PlaySfx(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.PlaySfx, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.group = self._io.read_u1()
            self.sound = self._io.read_u1()
            self.pan = self._io.read_u1()
            self.volume = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class PlayVibration(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.PlayVibration, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.pattern = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class PlayWeaponSfx(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.PlayWeaponSfx, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.sheathe = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class ProjectionDistance(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ProjectionDistance, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.distance = self._io.read_u1()
            self.easing = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class QueueAnimation(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.QueueAnimation, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.animation = self._io.read_u1()
            self.unused = self._io.read_u1()
            self.bank = self._io.read_bits_int_be(2)
            self.blend_frames = self._io.read_bits_int_be(6)


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class QueueAnimationFromFrame(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.QueueAnimationFromFrame, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.animation = self._io.read_u1()
            self.frame = self._io.read_u1()
            self.unused = self._io.read_u1()
            self.bank = self._io.read_bits_int_be(2)
            self.blend_frames = self._io.read_bits_int_be(6)


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class QueueMusic(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.QueueMusic, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class QueueNextEvt(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.QueueNextEvt, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.evt_file = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class RampMusicPitch(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.RampMusicPitch, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.pitch = self._io.read_s1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class RampMusicTempo(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.RampMusicTempo, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.tempo = self._io.read_s1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class RampSfxPan(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.RampSfxPan, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.group = self._io.read_u1()
            self.sound = self._io.read_u1()
            self.pan = self._io.read_u1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class RampSfxPitch(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.RampSfxPitch, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.group = self._io.read_u1()
            self.sound = self._io.read_u1()
            self.pitch = self._io.read_s1()
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class RearmEffectStage(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.RearmEffectStage, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.stage = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class RemoveMiscItem(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.RemoveMiscItem, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.item = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class ReturnToGameplayCamera(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ReturnToGameplayCamera, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.facing = self._io.read_u1()
            self.zoom = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class RotateActor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.RotateActor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.relative = self._io.read_u1()
            self.x = self._io.read_s2le()
            self.y = self._io.read_s2le()
            self.z = self._io.read_s2le()
            self.frames = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class ScreenTransitionIn(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ScreenTransitionIn, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.effect = self._io.read_u1()
            self.speed = self._io.read_u1()
            self.wipe_angle = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ScreenTransitionOut(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ScreenTransitionOut, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.effect = self._io.read_u1()
            self.speed = self._io.read_u1()
            self.wipe_angle = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class Script(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.Script, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.ops = []
            i = 0
            while not self._io.is_eof():
                self.ops.append(Evt.Op(self._io, self, self._root))
                i += 1



        def _fetch_instances(self):
            pass
            for i in range(len(self.ops)):
                pass
                self.ops[i]._fetch_instances()



    class SelectEventData(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SelectEventData, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SelectTextBox(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SelectTextBox, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.box_mask = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetActorAwake(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorAwake, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.awake = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorEdgeHighlight(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorEdgeHighlight, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.x = self._io.read_s1()
            self.y = self._io.read_s1()
            self.z = self._io.read_s1()
            self.ot_depth = self._io.read_u1()
            self.r = self._io.read_u1()
            self.g = self._io.read_u1()
            self.b = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorFlags(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorFlags, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.flags = self._io.read_u1()
            self.weapon_flags = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorLightColor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorLightColor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.r = self._io.read_u1()
            self.g = self._io.read_u1()
            self.b = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorLookAngles(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorLookAngles, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.pitch = self._io.read_s2le()
            self.yaw = self._io.read_s2le()
            self.speed = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorLookPosition(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorLookPosition, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.x = self._io.read_s2le()
            self.y = self._io.read_s2le()
            self.z = self._io.read_s2le()
            self.speed = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorLookTarget(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorLookTarget, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.target = Evt.ActorSelector(self._io, self, self._root)
            self.speed = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()
            self.target._fetch_instances()


    class SetActorMoveAnimation(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorMoveAnimation, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.bank = self._io.read_u1()
            self.animation = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorScale(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorScale, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.x = self._io.read_s2le()
            self.y = self._io.read_s2le()
            self.z = self._io.read_s2le()
            self.frames = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorSfxPanVolume(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorSfxPanVolume, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor_id = self._io.read_u2le()
            self.mode = self._io.read_u1()
            self.pan = self._io.read_u1()
            self.volume = self._io.read_u1()
            self.ramp_duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetActorSway(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorSway, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.angle = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorTrail(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorTrail, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.start = self._io.read_u1()
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.bone = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorWeaponModels(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorWeaponModels, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.blade = self._io.read_u1()
            self.unused_0 = self._io.read_u1()
            self.shield = self._io.read_u1()
            self.unused_1 = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SetActorsAwake(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetActorsAwake, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.awake = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetBackgroundOffset(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetBackgroundOffset, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.x = self._io.read_s2le()
            self.y = self._io.read_s2le()


        def _fetch_instances(self):
            pass


    class SetBackgroundParallax(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetBackgroundParallax, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.horizontal = self._io.read_s1()
            self.vertical = self._io.read_s1()
            self.unused = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetBackgroundVisible(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetBackgroundVisible, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.visible = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetBattleTimer(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetBattleTimer, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.start = self._io.read_u1()
            self.lifetime = self._io.read_u1()
            self.mode = self._io.read_u1()
            self.hours = self._io.read_u1()
            self.minutes = self._io.read_u1()
            self.seconds = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetCameraDestination(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetCameraDestination, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.x = self._io.read_s2le()
            self.y = self._io.read_s2le()
            self.z = self._io.read_s2le()


        def _fetch_instances(self):
            pass


    class SetCameraMomentum(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetCameraMomentum, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.flags = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetCloudstoneMoving(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetCloudstoneMoving, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.cloudstone = self._io.read_u1()
            self.moving = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetCurrentSfx(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetCurrentSfx, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetEnteredDoor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetEnteredDoor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.door = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetFirstPersonRendering(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetFirstPersonRendering, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.enabled = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetFlagToActorDistance(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetFlagToActorDistance, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.other = Evt.ActorSelector(self._io, self, self._root)
            self.flag = self._io.read_u2le()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()
            self.other._fetch_instances()


    class SetFlagToButtons(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetFlagToButtons, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.flag_and_mode = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class SetFlagToItemCount(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetFlagToItemCount, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.item = self._io.read_u2le()
            self.flag = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class SetFlagsToActorDistanceAndAngle(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetFlagsToActorDistanceAndAngle, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.other = Evt.ActorSelector(self._io, self, self._root)
            self.scale = self._io.read_u1()
            self.flag = self._io.read_u2le()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()
            self.other._fetch_instances()


    class SetFrameRate(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetFrameRate, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.rate = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetFramebufferEffect(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetFramebufferEffect, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.enabled = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetLoopCounter(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetLoopCounter, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.counter = self._io.read_u1()
            self.count = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetMusicTargetCue(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetMusicTargetCue, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.cue = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetParticleEffect(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetParticleEffect, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.effect = self._io.read_bits_int_be(4)
            self.intensity = self._io.read_bits_int_be(4)
            self.direction = self._io.read_u1()
            self.fall_angle = self._io.read_u1()
            self.blend_frames = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetParticleEffectSoundScripted(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetParticleEffectSoundScripted, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.scripted = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetPrintfArgInt(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetPrintfArgInt, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.arg_index = self._io.read_u1()
            self.value = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class SetScanlines(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetScanlines, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.enabled = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetSceneVisibility(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetSceneVisibility, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unused = self._io.read_bits_int_be(2)
            self.actors = self._io.read_bits_int_be(2)
            self.geometry = self._io.read_bits_int_be(2)
            self.screen = self._io.read_bits_int_be(2)


        def _fetch_instances(self):
            pass


    class SetScreenBlur(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetScreenBlur, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.depth = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class SetScreenTransition(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetScreenTransition, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.effect = self._io.read_u1()
            self.speed = self._io.read_u1()
            self.wipe_angle = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetScreenTransitionWipeAngle(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetScreenTransitionWipeAngle, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.wipe_angle = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetTextBoxAnimationDuration(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetTextBoxAnimationDuration, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.box_id = self._io.read_bits_int_be(3)
            self.duration = self._io.read_bits_int_be(5)


        def _fetch_instances(self):
            pass


    class SetTextBoxSpeaker(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetTextBoxSpeaker, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.speaker_animation = self._io.read_bits_int_be(4)
            self.box_id = self._io.read_bits_int_be(4)
            self.speaker = Evt.ActorSelector(self._io, self, self._root)


        def _fetch_instances(self):
            pass
            self.speaker._fetch_instances()


    class SetTileBlocked(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetTileBlocked, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.tile_x = self._io.read_u1()
            self.layer = self._io.read_u1()
            self.tile_z = self._io.read_u1()
            self.blocked = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetUiVisible(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetUiVisible, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.visible = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetUnk(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetUnk, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.value = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SetWeaponDrawn(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SetWeaponDrawn, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.mode = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class Shape(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.Shape, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_vertices = self._io.read_u1()
            self.num_tails = self._io.read_u1()
            self.outline_count = self._io.read_u1()
            self.quad_count = self._io.read_u1()
            self.tails = []
            for i in range(self.num_tails):
                self.tails.append(Evt.ShapeTail(self._io, self, self._root))

            self.vertices = []
            for i in range(self.num_vertices):
                self.vertices.append(Evt.ShapeVertex(self._io, self, self._root))

            self.body = Evt.ShapeQuads(self.quad_count, self._io, self, self._root)
            self.tail_quads = []
            for i in range(self.num_tails):
                self.tail_quads.append(Evt.ShapeQuads(self.tails[i].quad_count, self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.tails)):
                pass
                self.tails[i]._fetch_instances()

            for i in range(len(self.vertices)):
                pass
                self.vertices[i]._fetch_instances()

            self.body._fetch_instances()
            for i in range(len(self.tail_quads)):
                pass
                self.tail_quads[i]._fetch_instances()



    class ShapeQuad(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ShapeQuad, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.v0 = self._io.read_u1()
            self.v1 = self._io.read_u1()
            self.v2 = self._io.read_u1()
            self.v3 = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ShapeQuads(KaitaiStruct):
        def __init__(self, num_quads, _io, _parent=None, _root=None):
            super(Evt.ShapeQuads, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self.num_quads = num_quads
            self._read()

        def _read(self):
            self.quads = []
            for i in range(self.num_quads):
                self.quads.append(Evt.ShapeQuad(self._io, self, self._root))



        def _fetch_instances(self):
            pass
            for i in range(len(self.quads)):
                pass
                self.quads[i]._fetch_instances()



    class ShapeTable(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ShapeTable, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unused_slot_0 = self._io.read_bytes(2)
            if not self.unused_slot_0 == b"\x00\x00":
                raise kaitaistruct.ValidationNotEqualError(b"\x00\x00", self.unused_slot_0, self._io, u"/types/shape_table/seq/0")
            self.offsets = []
            for i in range(7):
                self.offsets.append(self._io.read_u2le())

            self.shapes = []
            i = 0
            while not self._io.is_eof():
                self.shapes.append(Evt.Shape(self._io, self, self._root))
                i += 1



        def _fetch_instances(self):
            pass
            for i in range(len(self.offsets)):
                pass

            for i in range(len(self.shapes)):
                pass
                self.shapes[i]._fetch_instances()



    class ShapeTail(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ShapeTail, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.anchor = self._io.read_u1()
            self.join = self._io.read_u1()
            self.vertex_count = self._io.read_u1()
            self.quad_count = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ShapeVertex(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ShapeVertex, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.x = self._io.read_u1()
            self.y = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ShowGeometry(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ShowGeometry, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.object = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ShowGimImage(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ShowGimImage, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.image = self._io.read_bits_int_be(2)
            self.mode = self._io.read_bits_int_be(6)
            self.x = self._io.read_s1()
            self.y = self._io.read_s1()
            self.scale = self._io.read_u1()
            self.brightness = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ShowMiscLoot(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ShowMiscLoot, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.item_0 = self._io.read_u2le()
            self.count_0 = self._io.read_u1()
            self.item_1 = self._io.read_u2le()
            self.count_1 = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class ShowTextBox(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.ShowTextBox, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.box_id = self._io.read_u1()
            self.string_index = self._io.read_u1()
            self.no_wait = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SlideActorToCoordinate(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SlideActorToCoordinate, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.x = self._io.read_u2le()
            self.y = self._io.read_s2le()
            self.z = self._io.read_s2le()
            self.frames = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SlideActorToTile(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SlideActorToTile, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.tile_x = self._io.read_u1()
            self.tile_surface = self._io.read_u1()
            self.tile_z = self._io.read_u1()
            self.frames = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class SpawnActor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SpawnActor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = Evt.ActorSelector(self._io, self, self._root)
            self.model = self._io.read_u2le()
            self.tile_x = self._io.read_u1()
            self.tile_surface = self._io.read_u1()
            self.tile_z = self._io.read_u1()
            self.facing = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.slot._fetch_instances()


    class SpecialOp(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SpecialOp, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.sub_opcode = self._io.read_u1()
            self.argument = self._io.read_u1()
            self.unused_0 = self._io.read_u1()
            self.unused_1 = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class StartEffect(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.StartEffect, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.effect = self._io.read_u2le()
            self.target = Evt.ActorSelector(self._io, self, self._root)


        def _fetch_instances(self):
            pass
            self.target._fetch_instances()


    class StopCamera(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.StopCamera, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unused = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class StopSfx(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.StopSfx, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.group = self._io.read_u1()
            self.sound = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SwapGeometryFlags(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SwapGeometryFlags, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.first = self._io.read_u1()
            self.second = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class SwitchOnFlag(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.SwitchOnFlag, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.flag = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class TransformColors(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.TransformColors, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.target = self._io.read_bits_int_be(4)
            self.mode = self._io.read_bits_int_be(4)
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.duration = self._io.read_u1()
            self.r = self._io.read_s1()
            self.g = self._io.read_s1()
            self.b = self._io.read_s1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class TriggerEffectStage(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.TriggerEffectStage, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.stage = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class TurnActorToFaceActor(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.TurnActorToFaceActor, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.target = Evt.ActorSelector(self._io, self, self._root)
            self.frames = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()
            self.target._fetch_instances()


    class TurnActorToFaceTile(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.TurnActorToFaceTile, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.tile_x = self._io.read_u1()
            self.tile_surface = self._io.read_u1()
            self.tile_z = self._io.read_u1()
            self.frames = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class TurnActorToFacing(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.TurnActorToFacing, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.facing = self._io.read_u1()
            self.direction = self._io.read_s1()
            self.frames = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class TweenGimImage(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.TweenGimImage, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.x = self._io.read_s1()
            self.y = self._io.read_s1()
            self.scale = self._io.read_u1()
            self.brightness = self._io.read_u1()
            self.image = self._io.read_bits_int_be(2)
            self.curve = self._io.read_bits_int_be(6)
            self.duration = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class UnloadEventData(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.UnloadEventData, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.unused = self._io.read_bits_int_be(5)
            self.etm_only = self._io.read_bits_int_be(1) != 0
            self.slot = self._io.read_bits_int_be(2)


        def _fetch_instances(self):
            pass


    class Unparsed(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.Unparsed, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.bytes = self._io.read_bytes_full()


        def _fetch_instances(self):
            pass


    class VibrationKeyframe(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.VibrationKeyframe, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.frames = self._io.read_u1()
            self.level = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class VibrationKeyframes(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.VibrationKeyframes, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.keyframes = []
            i = 0
            while True:
                _ = Evt.VibrationKeyframe(self._io, self, self._root)
                self.keyframes.append(_)
                if _.frames == 0:
                    break
                i += 1


        def _fetch_instances(self):
            pass
            for i in range(len(self.keyframes)):
                pass
                self.keyframes[i]._fetch_instances()



    class VibrationPattern(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.VibrationPattern, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.num_effects = self._io.read_u4le()
            if not self.num_effects == 1:
                raise kaitaistruct.ValidationNotEqualError(1, self.num_effects, self._io, u"/types/vibration_pattern/seq/0")
            self.ofs_script = self._io.read_u2le()
            if not self.ofs_script == 8:
                raise kaitaistruct.ValidationNotEqualError(8, self.ofs_script, self._io, u"/types/vibration_pattern/seq/1")
            self.unused = self._io.read_u2le()
            self.ofs_large_motor = self._io.read_u1()
            self.small_motor = Evt.VibrationKeyframes(self._io, self, self._root)
            self.large_motor = Evt.VibrationKeyframes(self._io, self, self._root)
            self.padding = self._io.read_bytes(4 - (9 + 2 * (len(self.small_motor.keyframes) + len(self.large_motor.keyframes))) % 4)


        def _fetch_instances(self):
            pass
            self.small_motor._fetch_instances()
            self.large_motor._fetch_instances()


    class VibrationTable(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.VibrationTable, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.offsets = []
            for i in range(8):
                self.offsets.append(self._io.read_u2le())

            self.patterns = []
            i = 0
            while not self._io.is_eof():
                self.patterns.append(Evt.VibrationPattern(self._io, self, self._root))
                i += 1



        def _fetch_instances(self):
            pass
            for i in range(len(self.offsets)):
                pass

            for i in range(len(self.patterns)):
                pass
                self.patterns[i]._fetch_instances()



    class WaitActorActivity(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WaitActorActivity, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.mask = self._io.read_u2le()
            self.unused = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class WaitButtonPressed(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WaitButtonPressed, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.buttons = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class WaitCameraIdle(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WaitCameraIdle, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.mask = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class WaitEffectState(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WaitEffectState, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.state = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class WaitFrames(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WaitFrames, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.frames = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class WaitFramesOrButton(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WaitFramesOrButton, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.buttons = self._io.read_u1()
            self.frames = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class WaitMusicBar(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WaitMusicBar, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.bar = self._io.read_u2le()


        def _fetch_instances(self):
            pass


    class WaitMusicLoad(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WaitMusicLoad, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class WaitMusicSilent(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WaitMusicSilent, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class WaitSfxLoad(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WaitSfxLoad, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.slot = self._io.read_u1()


        def _fetch_instances(self):
            pass


    class WalkActorToCoordinate(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WalkActorToCoordinate, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.x = self._io.read_s2le()
            self.z = self._io.read_s2le()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class WalkActorToTile(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.WalkActorToTile, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.actor = Evt.ActorSelector(self._io, self, self._root)
            self.tile_x = self._io.read_u1()
            self.unused = self._io.read_u1()
            self.tile_z = self._io.read_u1()


        def _fetch_instances(self):
            pass
            self.actor._fetch_instances()


    class Warp(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Evt.Warp, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.zone = self._io.read_u1()
            self.map = self._io.read_u1()
            self.tile_x = self._io.read_u1()
            self.surface = self._io.read_u1()
            self.tile_z = self._io.read_u1()
            self.facing = self._io.read_u1()
            self.flags = self._io.read_u1()
            self.transition = self._io.read_u1()
            self.speed = self._io.read_u1()


        def _fetch_instances(self):
            pass



