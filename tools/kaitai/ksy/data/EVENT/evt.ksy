# .as<T> cast used to work around kaitai's naming lint warning.

meta:
  id: evt
  file-extension: EVT
  endian: le
  imports: [/string_table]

seq:
  - id: num_bytes
    type: u2
  - id: ofs_strings
    type: u2
  - id: ofs_shapes
    type: u2
  - id: ofs_vibration
    type: u2
  - id: reserved
    contents: [0, 0, 0, 0, 0, 0, 0, 0]
  - id: script
    type: script
    size: ofs_strings - 16
  - id: strings
    type: string_table(0)
    size: ofs_shapes - ofs_strings
    if: has_strings
  - id: shapes
    type: shape_table
    size: ofs_vibration - ofs_shapes
  - id: vibration
    type: vibration_table
    size: num_bytes - ofs_vibration
  - id: padding
    size-eos: true
    valid:
      expr: _.length == 0 or _.max == 0

instances:
  has_strings:
    value: ofs_shapes > ofs_strings

types:
  script:
    seq:
      - id: ops
        type: op
        repeat: eos

  op:
    seq:
      - id: opcode
        type: u1
        enum: opcode
      - id: operands
        type:
          switch-on: opcode
          cases:
            'opcode::begin_skippable': begin_skippable
            'opcode::end_skippable_body': jump
            'opcode::jump_fwd_unless_flag_imm': jump_fwd_unless_flag_imm
            'opcode::jump_fwd_unless_flag': jump_fwd_unless_flag
            'opcode::jump_fwd_else': jump
            'opcode::jump_fwd': jump
            'opcode::switch_on_flag': switch_on_flag
            'opcode::jump_fwd_case': jump_fwd_case
            'opcode::set_loop_counter': set_loop_counter
            'opcode::loop_condition': loop_condition
            'opcode::break_loop': jump
            'opcode::jump_fwd_unused': jump
            'opcode::wait_frames': wait_frames
            'opcode::join_script': join_script
            'opcode::fork_and_jump': fork_and_jump
            'opcode::end_script': end_script
            'opcode::queue_next_evt': queue_next_evt
            'opcode::init_text_box': init_text_box
            'opcode::show_text_box': show_text_box
            'opcode::dismiss_text_box': dismiss_text_box
            'opcode::init_text_box_near_actor': init_text_box_near_actor
            'opcode::dismiss_text_box_and_wait': dismiss_text_box_and_wait
            'opcode::wait_button_pressed': wait_button_pressed
            'opcode::load_gim': load_gim
            'opcode::show_gim_image': show_gim_image
            'opcode::tween_gim_image': tween_gim_image
            'opcode::set_printf_arg_int': set_printf_arg_int
            'opcode::select_text_box': select_text_box
            'opcode::set_text_box_animation_duration': set_text_box_animation_duration
            'opcode::actor_death': actor_death
            'opcode::get_actor_tile': get_actor_tile
            'opcode::spawn_actor': spawn_actor
            'opcode::walk_actor_to_tile': walk_actor_to_tile
            'opcode::play_animation': play_animation
            'opcode::set_actor_flags': set_actor_flags
            'opcode::set_actor_sfx_pan_volume': set_actor_sfx_pan_volume
            'opcode::move_actor_to_tile': move_actor_to_tile
            'opcode::move_actor_to_coordinate': move_actor_to_coordinate
            'opcode::slide_actor_to_tile': slide_actor_to_tile
            'opcode::slide_actor_to_coordinate': slide_actor_to_coordinate
            'opcode::attach_actor': attach_actor
            'opcode::walk_actor_to_coordinate': walk_actor_to_coordinate
            'opcode::turn_actor_to_facing': turn_actor_to_facing
            'opcode::turn_actor_to_face_actor': turn_actor_to_face_actor
            'opcode::turn_actor_to_face_tile': turn_actor_to_face_tile
            'opcode::set_actor_scale': set_actor_scale
            'opcode::despawn_actor': despawn_actor
            'opcode::wait_actor_activity': wait_actor_activity
            'opcode::set_actor_light_color': set_actor_light_color
            'opcode::queue_animation': queue_animation
            'opcode::rotate_actor': rotate_actor
            'opcode::set_actor_look_angles': set_actor_look_angles
            'opcode::play_animation_from_frame': play_animation_from_frame
            'opcode::queue_animation_from_frame': queue_animation_from_frame
            'opcode::set_actor_move_animation': set_actor_move_animation
            'opcode::set_actor_look_target': set_actor_look_target
            'opcode::set_actor_look_position': set_actor_look_position
            'opcode::enqueue_event_data': enqueue_event_data
            'opcode::unload_event_data': unload_event_data
            'opcode::select_event_data': select_event_data
            'opcode::set_actor_edge_highlight': set_actor_edge_highlight
            'opcode::set_weapon_drawn': set_weapon_drawn
            'opcode::wait_evt_load': no_operands
            'opcode::wait_gim_load': no_operands
            'opcode::end_skip_handler': no_operands
            'opcode::unload_gim': no_operands
            'opcode::wait_gim_tweens': no_operands
            'opcode::wait_data_queue_empty': no_operands
            'opcode::nop_43': no_operands
            'opcode::end_scene_reset': no_operands
            'opcode::status_unk': no_operands
            'opcode::wait_for_screen_transition': no_operands
            'opcode::wait_background_load': no_operands
            'opcode::unload_background': no_operands
            'opcode::stop_all_sfx': no_operands
            'opcode::load_area_music': no_operands
            'opcode::stop_music': no_operands
            'opcode::push_music_state': no_operands
            'opcode::wait_instrument_bank_load': no_operands
            'opcode::yield_if_skipping': no_operands
            'opcode::wait_effect_stage_ready': no_operands
            'opcode::cancel_effect': no_operands
            'opcode::wait_screen_effects_loaded': no_operands
            'opcode::load_screen_effects': no_operands
            'opcode::unload_screen_effects': no_operands
            'opcode::look_at_cut': no_operands
            'opcode::eye_cut': no_operands
            'opcode::end_scene': no_operands
            'opcode::end_scene_ff': no_operands
            'opcode::modify_flag_imm': modify_flag_imm
            'opcode::modify_flag': modify_flag
            'opcode::set_flag_to_item_count': set_flag_to_item_count
            'opcode::forget_zone_enemies': forget_zone_enemies
            'opcode::play_weapon_sfx': play_weapon_sfx
            'opcode::set_actors_awake': set_actors_awake
            'opcode::set_flag_to_buttons': set_flag_to_buttons
            'opcode::fully_restore_actor': fully_restore_actor
            'opcode::set_ui_visible': set_ui_visible
            'opcode::open_menu': open_menu
            'opcode::set_battle_timer': set_battle_timer
            'opcode::set_text_box_speaker': set_text_box_speaker
            'opcode::set_actor_weapon_models': set_actor_weapon_models
            'opcode::set_actor_sway': set_actor_sway
            'opcode::wait_frames_or_button': wait_frames_or_button
            'opcode::define_easing': define_easing
            'opcode::set_cloudstone_moving': set_cloudstone_moving
            'opcode::override_fog_depth': override_fog_depth
            'opcode::set_first_person_rendering': set_first_person_rendering
            'opcode::show_geometry': show_geometry
            'opcode::hide_geometry': hide_geometry
            'opcode::swap_geometry_flags': swap_geometry_flags
            'opcode::set_tile_blocked': set_tile_blocked
            'opcode::warp': warp
            'opcode::screen_transition_out': screen_transition_out
            'opcode::screen_transition_in': screen_transition_in
            'opcode::set_screen_transition_wipe_angle': set_screen_transition_wipe_angle
            'opcode::set_screen_transition': set_screen_transition
            'opcode::set_scene_visibility': set_scene_visibility
            'opcode::set_unk': set_unk
            'opcode::transform_colors': transform_colors
            'opcode::fade_actor': fade_actor
            'opcode::draw_sheathe_ashley_weapon': draw_sheathe_ashley_weapon
            'opcode::set_background_visible': set_background_visible
            'opcode::load_background': load_background
            'opcode::set_particle_effect': set_particle_effect
            'opcode::freeze_particle_effect': freeze_particle_effect
            'opcode::control_room_task': control_room_task
            'opcode::set_particle_effect_sound_scripted': set_particle_effect_sound_scripted
            'opcode::set_background_offset': set_background_offset
            'opcode::cull_occluding_geometry': cull_occluding_geometry
            'opcode::adjust_geometry_depth': adjust_geometry_depth
            'opcode::set_background_parallax': set_background_parallax
            'opcode::play_sfx': play_sfx
            'opcode::play_actor_sfx': play_actor_sfx
            'opcode::fade_sfx_volume': fade_sfx_volume
            'opcode::stop_sfx': stop_sfx
            'opcode::load_sfx_slot': load_sfx_slot
            'opcode::wait_sfx_load': wait_sfx_load
            'opcode::free_sfx': free_sfx
            'opcode::set_current_sfx': set_current_sfx
            'opcode::crossfade_music': crossfade_music
            'opcode::load_music_slot': load_music_slot
            'opcode::free_music': free_music
            'opcode::play_music': play_music
            'opcode::fade_music_volume': fade_music_volume
            'opcode::ramp_music_tempo': ramp_music_tempo
            'opcode::ramp_music_pitch': ramp_music_pitch
            'opcode::wait_music_silent': wait_music_silent
            'opcode::wait_music_load': wait_music_load
            'opcode::wait_music_bar': wait_music_bar
            'opcode::ramp_sfx_pitch': ramp_sfx_pitch
            'opcode::ramp_sfx_pan': ramp_sfx_pan
            'opcode::load_instrument_bank': load_instrument_bank
            'opcode::queue_music': queue_music
            'opcode::start_effect': start_effect
            'opcode::trigger_effect_stage': trigger_effect_stage
            'opcode::wait_effect_state': wait_effect_state
            'opcode::rearm_effect_stage': rearm_effect_stage
            'opcode::set_music_target_cue': set_music_target_cue
            'opcode::play_vibration': play_vibration
            'opcode::set_actor_trail': set_actor_trail
            'opcode::set_entered_door': set_entered_door
            'opcode::set_flags_to_actor_distance_and_angle': set_flags_to_actor_distance_and_angle
            'opcode::set_actor_awake': set_actor_awake
            'opcode::show_misc_loot': show_misc_loot
            'opcode::remove_misc_item': remove_misc_item
            'opcode::set_flag_to_actor_distance': set_flag_to_actor_distance
            'opcode::special_op': special_op
            'opcode::set_screen_blur': set_screen_blur
            'opcode::nop_bd': nop_bd
            'opcode::stop_camera': stop_camera
            'opcode::set_camera_momentum': set_camera_momentum
            'opcode::wait_camera_idle': wait_camera_idle
            'opcode::set_framebuffer_effect': set_framebuffer_effect
            'opcode::attach_camera_to_actor': attach_camera_to_actor
            'opcode::return_to_gameplay_camera': return_to_gameplay_camera
            'opcode::set_frame_rate': set_frame_rate
            'opcode::play_menu_select_sfx': play_menu_select_sfx
            'opcode::set_scanlines': set_scanlines
            'opcode::nop_44': nop_44
            'opcode::look_at_set_destination': set_camera_destination
            'opcode::eye_set_destination': set_camera_destination
            'opcode::look_at_lerp_to': camera_lerp_to
            'opcode::eye_lerp_to': camera_lerp_to
            'opcode::look_at_arc_to': camera_lerp_to
            'opcode::eye_arc_to': camera_lerp_to
            'opcode::look_at_orbit_to': camera_orbit_to
            'opcode::eye_orbit_to': camera_orbit_to
            'opcode::look_at_orbit_by': camera_orbit_by
            'opcode::eye_orbit_by': camera_orbit_by
            'opcode::look_at_set_destination_to_actor_offset': camera_set_destination_to_actor_offset
            'opcode::eye_set_destination_to_actor_offset': camera_set_destination_to_actor_offset
            'opcode::look_at_set_destination_to_actor_local_offset': camera_set_destination_to_actor_offset
            'opcode::eye_set_destination_to_actor_local_offset': camera_set_destination_to_actor_offset
            'opcode::look_at_follow_actor': camera_follow_actor
            'opcode::eye_follow_actor': camera_follow_actor
            'opcode::look_at_lock_offset': camera_lock_offset
            'opcode::eye_lock_offset': camera_lock_offset
            'opcode::look_at_terrain_follow_to': camera_terrain_follow_to
            'opcode::eye_terrain_follow_to': camera_terrain_follow_to
            'opcode::camera_roll': camera_roll
            'opcode::framebuffer_effect_spin': camera_roll
            'opcode::framebuffer_effect_scale': framebuffer_effect_scale
            'opcode::framebuffer_effect_tint': framebuffer_effect_tint
            'opcode::framebuffer_effect_offset': framebuffer_effect_offset
            'opcode::framebuffer_effect_blend_mode': framebuffer_effect_blend_mode
            'opcode::lens_distortion': lens_distortion
            'opcode::framebuffer_effect_depth': framebuffer_effect_depth
            'opcode::framebuffer_effect_use_previous_frame': framebuffer_effect_use_previous_frame
            'opcode::framebuffer_effect_preset': framebuffer_effect_preset
            'opcode::projection_distance': projection_distance
            'opcode::near_clip': near_clip
            'opcode::far_clip': far_clip
            'opcode::camera_shake': camera_shake
            _: unparsed

  unparsed:
    seq:
      - id: bytes
        size-eos: true

  begin_skippable:
    seq:
      - id: reserved_flags
        type: b7
      - id: keep_music
        type: b1
        doc: Keeps the music playing if the section is skipped.
      - id: unused
        type: u1

  jump:
    seq:
      - id: offset
        type: s2

  jump_fwd_unless_flag_imm:
    seq:
      - id: comparison
        type: b4
        enum: flag_comparison
      - id: flag_high
        type: b4
      - id: flag_low
        type: b6
      - id: unused
        type: b2
      - id: value
        type: s1
      - id: offset
        type: s2
        doc: Offset to jump to if the comparison is false.
    instances:
      flag:
        value: (flag_high << 6) | flag_low

  jump_fwd_unless_flag:
    seq:
      - id: comparison
        type: b4
        enum: flag_comparison
      - id: flag_high
        type: b4
      - id: flag_low
        type: b6
      - id: other_flag_high
        type: b2
      - id: other_flag_low
        type: u1
      - id: offset
        type: s2
        doc: Offset to jump to if the comparison is false.
    instances:
      flag:
        value: (flag_high << 6) | flag_low
      other_flag:
        value: (other_flag_high << 8) | other_flag_low

  switch_on_flag:
    seq:
      - id: flag
        type: u2

  jump_fwd_case:
    seq:
      - id: value
        type: u1
      - id: offset
        type: s2

  set_loop_counter:
    seq:
      - id: counter
        type: u1
        doc: 0xFF is a marker for the start of an infinite loop.
      - id: count
        type: u1

  loop_condition:
    seq:
      - id: counter
        type: u1
        doc: 0xFF always jumps.
      - id: offset_back
        type: s2
        doc: How far before the opcode to jump to.

  wait_frames:
    seq:
      - id: frames
        type: u1

  join_script:
    seq:
      - id: stop
        type: b1
        doc: Stops the slot instead of waiting for it.
      - id: unused
        type: b5
      - id: slot
        type: b2

  fork_and_jump:
    seq:
      - id: slot
        type: u1
      - id: offset
        type: s2
        doc: Where the current script continues, the forked script follows this opcode.

  end_script:
    seq:
      - id: unused
        type: u1

  queue_next_evt:
    seq:
      - id: evt_file
        type: u2

  no_operands:
    seq: []

  actor_selector:
    seq:
      - id: raw
        type: u2
    instances:
      kind:
        value: raw >> 12
        enum: actor_selector_kind
      value:
        value: raw & 0xFFF

  init_text_box:
    seq:
      - id: parent_box_id
        type: b4
      - id: box_id
        type: b4
      - id: flags
        type: u2
      - id: x
        type: u1
        doc: 'Scaled: x * 2 - 0x20.'
      - id: y
        type: u1
        doc: 'Scaled: y - 0x20.'
      - id: width
        type: u1
        doc: In characters.
      - id: height
        type: u1
        doc: In lines.
      - id: speaker
        type: actor_selector
        doc: None for no speaker.
      - id: speaker_animation
        type: u1

  show_text_box:
    seq:
      - id: box_id
        type: u1
      - id: string_index
        type: u1
      - id: no_wait
        type: u1
        doc: 'Nonzero: do not wait for the player to advance the text.'

  dismiss_text_box:
    seq:
      - id: box_id
        type: u1

  init_text_box_near_actor:
    seq:
      - id: box_id
        type: u1
      - id: actor
        type: actor_selector
        doc: The actor to place the box next to.
      - id: flags
        type: u2
        doc: The low nibble of the second byte is the box shape, which also selects the placement preset.
      - id: width
        type: u1
        doc: In characters.
      - id: height
        type: u1
        doc: In lines.
      - id: speaker_animation
        type: u1

  dismiss_text_box_and_wait:
    seq:
      - id: box_id
        type: u1

  wait_button_pressed:
    seq:
      - id: buttons
        type: u1
        doc: Mask of the pad buttons, only the low byte (L2, R2, L1, R1 and the face buttons).

  load_gim:
    seq:
      - id: index
        type: u2
      - id: first_vram_page_slot
        type: u1

  show_gim_image:
    seq:
      - id: image
        type: b2
        doc: 0 to 2 within the GIM.
      - id: mode
        type: b6
        doc: Selects the draw function.
      - id: x
        type: s1
        doc: From the screen centre, in units of 2 pixels.
      - id: y
        type: s1
        doc: From the screen centre, in units of 2 pixels.
      - id: scale
        type: u1
        doc: 0x20 is full size.
      - id: brightness
        type: u1
        doc: 0x80 is normal.

  tween_gim_image:
    seq:
      - id: x
        type: s1
        doc: From the screen centre, in units of 2 pixels.
      - id: y
        type: s1
        doc: From the screen centre, in units of 2 pixels.
      - id: scale
        type: u1
        doc: Target scale, 0x20 is full size.
      - id: brightness
        type: u1
        doc: Target brightness.
      - id: image
        type: b2
      - id: curve
        type: b6
        doc: 0 to 3 are built in and 4 to 7 are set up by script.
      - id: duration
        type: u1

  set_printf_arg_int:
    seq:
      - id: arg_index
        type: u1
        doc: 0 to 9.
      - id: value
        type: u2
        doc: 'State flag id in bits 0 to 9, type in bits 14 and 15: 0 unsigned byte, 1 signed byte, 2 unsigned 16 bits, 3 signed 16 bits. 2 and 3 read two sequential state flags.'

  select_text_box:
    seq:
      - id: box_mask
        type: u1
        doc: Bit n is box n.

  set_text_box_animation_duration:
    seq:
      - id: box_id
        type: b3
      - id: duration
        type: b5
        doc: 0 to 31.

  actor_death:
    seq:
      - id: actor
        type: actor_selector
        doc: A single actor or a group.
      - id: play_animation
        type: u1
        doc: 'Nonzero: play the death animation first, 0: start the fade-out directly.'

  get_actor_tile:
    seq:
      - id: actor
        type: actor_selector
      - id: first_flag
        type: u2
        doc: First of three consecutive state flags for the tile x, surface and z. The first is set to 0xFF if the actor does not exist.

  spawn_actor:
    seq:
      - id: slot
        type: actor_selector
        doc: Selects the empty slot to create the actor in.
      - id: model
        type: u2
        doc: Index of the model, also the id the actor is looked up by.
      - id: tile_x
        type: u1
      - id: tile_surface
        type: u1
      - id: tile_z
        type: u1
      - id: facing
        type: u1
        doc: 1/256 turn.

  walk_actor_to_tile:
    seq:
      - id: actor
        type: actor_selector
      - id: tile_x
        type: u1
      - id: unused
        type: u1
      - id: tile_z
        type: u1

  play_animation:
    seq:
      - id: actor
        type: actor_selector
      - id: animation
        type: u1
        doc: Index within the bank.
      - id: unused
        type: u1
      - id: bank
        type: b2
        doc: Selects the base id.
      - id: blend_frames
        type: b6

  set_actor_flags:
    seq:
      - id: actor
        type: actor_selector
        doc: A single actor or a group.
      - id: flags
        type: u1
        doc: Bit 0 enabled, bit 1 visible, bit 2 frozen, bit 6 unknown.
      - id: weapon_flags
        type: u1
        doc: 'Bit 0: new flag value for the blade model. Bit 1: leave the blade as it is. Bit 2: new flag value for the shield model. Bit 3: leave the shield as it is. Bit 5: toggle deactivation of the actor.'

  set_actor_sfx_pan_volume:
    seq:
      - id: actor_id
        type: u2
      - id: mode
        type: u1
        doc: 0 clears the override, 1 uses the pan and volume, ramped over the duration, 2 mutes the actor.
      - id: pan
        type: u1
        doc: 0x80 is centered.
      - id: volume
        type: u1
        doc: 0x7F is maximum.
      - id: ramp_duration
        type: u1
        doc: In frames, 0 applies immediately.

  move_actor_to_tile:
    seq:
      - id: actor
        type: actor_selector
      - id: tile_x
        type: u1
      - id: tile_surface
        type: u1
      - id: tile_z
        type: u1
      - id: facing
        type: u1
        doc: 1/256 turn. With frame counts, 0xFF skips the final turn.
      - id: move_frames
        type: u1
        doc: 0 is immediately, 0xFF the default.
      - id: turn_frames
        type: u1
        doc: 0 is immediately, 0xFF the default.

  move_actor_to_coordinate:
    seq:
      - id: actor
        type: actor_selector
      - id: x
        type: u2
        doc: Bits 1 to 15 are the x. If bit 0 is set, x, y and z are added to the position of the actor.
      - id: y
        type: s2
        doc: 0x8000 is the ground height at the target, absolute only.
      - id: z
        type: s2
      - id: facing
        type: u1
        doc: 1/256 turn, 0xFF turns towards the direction of travel.
      - id: move_frames
        type: u1
        doc: 0 is immediately, 0xFF the default.
      - id: turn_frames
        type: u1
        doc: 0 is immediately, 0xFF the default.

  slide_actor_to_tile:
    seq:
      - id: actor
        type: actor_selector
      - id: tile_x
        type: u1
      - id: tile_surface
        type: u1
      - id: tile_z
        type: u1
      - id: frames
        type: u1
        doc: 0xFF is the default.

  slide_actor_to_coordinate:
    seq:
      - id: actor
        type: actor_selector
      - id: x
        type: u2
        doc: Bits 1 to 15 are the x. If bit 0 is set, x, y and z are added to the position of the actor.
      - id: y
        type: s2
      - id: z
        type: s2
      - id: frames
        type: u1
        doc: 0xFF is the default.

  attach_actor:
    seq:
      - id: actor
        type: actor_selector
      - id: parent
        type: actor_selector
        doc: None detaches the actor.
      - id: bone
        type: u1
        doc: Index in the parent.
      - id: unused
        type: u1

  walk_actor_to_coordinate:
    seq:
      - id: actor
        type: actor_selector
      - id: x
        type: s2
      - id: z
        type: s2

  turn_actor_to_facing:
    seq:
      - id: actor
        type: actor_selector
      - id: facing
        type: u1
        doc: 1/256 turn.
      - id: direction
        type: s1
        doc: 0 shortest, 1 positive, -1 negative.
      - id: frames
        type: u1
        doc: 0 is immediately, 0xFF the default.

  turn_actor_to_face_actor:
    seq:
      - id: actor
        type: actor_selector
      - id: target
        type: actor_selector
      - id: frames
        type: u1
        doc: 0 is immediately, 0xFF the default.

  turn_actor_to_face_tile:
    seq:
      - id: actor
        type: actor_selector
      - id: tile_x
        type: u1
      - id: tile_surface
        type: u1
      - id: tile_z
        type: u1
      - id: frames
        type: u1
        doc: 0 is immediately, 0xFF the default.

  set_actor_scale:
    seq:
      - id: actor
        type: actor_selector
      - id: x
        type: s2
        doc: ONE is normal size.
      - id: y
        type: s2
      - id: z
        type: s2
      - id: frames
        type: u1
        doc: 0 is immediately.

  despawn_actor:
    seq:
      - id: actor
        type: actor_selector

  wait_actor_activity:
    seq:
      - id: actor
        type: actor_selector
      - id: mask
        type: u2
        doc: Mask of the actor flag bits to wait for.
      - id: unused
        type: u1

  set_actor_light_color:
    seq:
      - id: actor
        type: actor_selector
      - id: r
        type: u1
        doc: 0x80 is neutral.
      - id: g
        type: u1
      - id: b
        type: u1

  queue_animation:
    seq:
      - id: actor
        type: actor_selector
      - id: animation
        type: u1
        doc: Index within the bank.
      - id: unused
        type: u1
      - id: bank
        type: b2
      - id: blend_frames
        type: b6

  rotate_actor:
    seq:
      - id: actor
        type: actor_selector
      - id: relative
        type: u1
        doc: 0 rotates to the given rotation, otherwise by it.
      - id: x
        type: s2
        doc: 1/ONE turn.
      - id: y
        type: s2
        doc: The facing.
      - id: z
        type: s2
      - id: frames
        type: u1
        doc: 0 is immediately, 0xFF the default.

  set_actor_look_angles:
    seq:
      - id: actor
        type: actor_selector
      - id: pitch
        type: s2
        doc: 1/ONE turn.
      - id: yaw
        type: s2
      - id: speed
        type: u1
        doc: 0 is unlimited.

  play_animation_from_frame:
    seq:
      - id: actor
        type: actor_selector
      - id: animation
        type: u1
        doc: Index within the bank.
      - id: frame
        type: u1
        doc: The frame to start at.
      - id: unused
        type: u1
      - id: bank
        type: b2
      - id: blend_frames
        type: b6

  queue_animation_from_frame:
    seq:
      - id: actor
        type: actor_selector
      - id: animation
        type: u1
        doc: Index within the bank.
      - id: frame
        type: u1
        doc: The frame to start at.
      - id: unused
        type: u1
      - id: bank
        type: b2
      - id: blend_frames
        type: b6

  set_actor_move_animation:
    seq:
      - id: actor
        type: actor_selector
      - id: bank
        type: u1
      - id: animation
        type: u1
        doc: 0xFF is the default.

  set_actor_look_target:
    seq:
      - id: actor
        type: actor_selector
      - id: target
        type: actor_selector
        doc: None stops looking at anything.
      - id: speed
        type: u1
        doc: 0 is unlimited.

  set_actor_look_position:
    seq:
      - id: actor
        type: actor_selector
      - id: x
        type: s2
      - id: y
        type: s2
      - id: z
        type: s2
      - id: speed
        type: u1
        doc: 0 is unlimited.

  enqueue_event_data:
    seq:
      - id: id
        type: u2
        doc: Of E<id>.ESQ and E<id>.ETM.
      - id: vram_slot
        type: b4
        doc: Selects the VRAM slot of the ETM.
      - id: what
        type: b2
        doc: 0 loads the ESQ, 1 the ESQ and then the ETM, 2 the ETM.
      - id: slot
        type: b2

  unload_event_data:
    seq:
      - id: unused
        type: b5
      - id: etm_only
        type: b1
        doc: Otherwise the ESQ and its ETM are unloaded.
      - id: slot
        type: b2

  select_event_data:
    seq:
      - id: slot
        type: u1
        doc: 1 to 3.

  set_actor_edge_highlight:
    seq:
      - id: actor
        type: actor_selector
      - id: x
        type: s1
      - id: y
        type: s1
      - id: z
        type: s1
      - id: ot_depth
        type: u1
        doc: Ordering table entries to push the copy back.
      - id: r
        type: u1
        doc: All zero is no edge highlight.
      - id: g
        type: u1
      - id: b
        type: u1

  set_weapon_drawn:
    seq:
      - id: actor
        type: actor_selector
      - id: mode
        type: u1
        doc: 0 sheathes, 1 draws, 2 toggles.

  modify_flag_imm:
    seq:
      - id: operation
        type: b4
        enum: flag_operation
        doc: Applied as flag = flag <operation> value.
      - id: flag_high
        type: b4
      - id: flag_low
        type: b6
      - id: unused
        type: b2
      - id: value
        type: u1

  modify_flag:
    seq:
      - id: operation
        type: b4
        enum: flag_operation
        doc: Applied as flag = flag <operation> other flag, there are two more operations than with an immediate.
      - id: flag_high
        type: b4
      - id: flag_low
        type: b6
      - id: other_flag_high
        type: b2
      - id: other_flag_low
        type: u1

  set_flag_to_item_count:
    seq:
      - id: item
        type: u2
      - id: flag
        type: u2

  forget_zone_enemies:
    seq:
      - id: zone
        type: u1
      - id: map
        type: u1

  play_weapon_sfx:
    seq:
      - id: actor
        type: actor_selector
      - id: sheathe
        type: u1
        doc: 0 draws, 1 sheathes.

  set_actors_awake:
    seq:
      - id: awake
        type: u1
        doc: 0 is dormant.

  set_flag_to_buttons:
    seq:
      - id: flag_and_mode
        type: u2
        doc: Bits 0 to 9 are the state flag, bit 15 selects the buttons newly pressed this frame instead of the ones held.

  fully_restore_actor:
    seq:
      - id: actor
        type: actor_selector
      - id: unused
        type: u1

  set_ui_visible:
    seq:
      - id: visible
        type: u1

  open_menu:
    seq:
      - id: menu
        type: u1
        doc: 10 to 14 open MENUF.PRG, 15 the loot or unlock screens, anything else the menu screen with that id.
      - id: unused
        type: u2

  set_battle_timer:
    seq:
      - id: start
        type: u1
        doc: 0 stops and clears the timer.
      - id: lifetime
        type: u1
      - id: mode
        type: u1
        doc: 0 counts up, 1 counts down.
      - id: hours
        type: u1
      - id: minutes
        type: u1
      - id: seconds
        type: u1

  set_text_box_speaker:
    seq:
      - id: speaker_animation
        type: b4
      - id: box_id
        type: b4
      - id: speaker
        type: actor_selector
        doc: None for no speaker.

  set_actor_weapon_models:
    seq:
      - id: actor
        type: actor_selector
      - id: blade
        type: u1
        doc: 0 none, 0xFF unchanged, 0xFE takes both weapons from the equipment.
      - id: unused_0
        type: u1
      - id: shield
        type: u1
        doc: 0 none, 0xFF unchanged.
      - id: unused_1
        type: u1

  set_actor_sway:
    seq:
      - id: actor
        type: actor_selector
      - id: angle
        type: u1
        doc: Angle at its peak in 1/ONE turn, 0 stops.

  wait_frames_or_button:
    seq:
      - id: buttons
        type: u1
        doc: Mask of the pad buttons, only the low byte.
      - id: frames
        type: u1
        doc: Must not be 0.

  define_easing:
    seq:
      - id: slot
        type: b2
        doc: Defines curve 4 to 7.
      - id: base_curve
        type: b2
      - id: squarings
        type: b4
        doc: Signed, ease-in if positive and ease-out if negative.

  set_cloudstone_moving:
    seq:
      - id: cloudstone
        type: u1
      - id: moving
        type: u1

  override_fog_depth:
    seq:
      - id: depth
        type: u2
        doc: Bit 15 toggles the override.

  set_first_person_rendering:
    seq:
      - id: enabled
        type: u1

  show_geometry:
    seq:
      - id: object
        type: u1

  hide_geometry:
    seq:
      - id: object
        type: u1

  swap_geometry_flags:
    seq:
      - id: first
        type: u1
      - id: second
        type: u1

  set_tile_blocked:
    seq:
      - id: tile_x
        type: u1
      - id: layer
        type: u1
        doc: 0 and 1 are the tile grid, 2 and above the cloudstone layer - 2.
      - id: tile_z
        type: u1
      - id: blocked
        type: u1

  warp:
    seq:
      - id: zone
        type: u1
        doc: 0 is the current zone.
      - id: map
        type: u1
      - id: tile_x
        type: u1
      - id: surface
        type: u1
      - id: tile_z
        type: u1
      - id: facing
        type: u1
      - id: flags
        type: u1
        doc: Bit 0 walk forward, bit 1 face the camera, bit 2 continue the script in the new room, bit 3 switch to the zone music.
      - id: transition
        type: u1
      - id: speed
        type: u1

  screen_transition_out:
    seq:
      - id: effect
        type: u1
      - id: speed
        type: u1
      - id: wipe_angle
        type: u1
        doc: 1/256 turn.

  screen_transition_in:
    seq:
      - id: effect
        type: u1
      - id: speed
        type: u1
      - id: wipe_angle
        type: u1
        doc: 1/256 turn.

  set_screen_transition_wipe_angle:
    seq:
      - id: wipe_angle
        type: u1
        doc: 1/256 turn.

  set_screen_transition:
    seq:
      - id: effect
        type: u1
      - id: speed
        type: u1
      - id: wipe_angle
        type: u1
        doc: 1/256 turn.

  set_scene_visibility:
    seq:
      - id: unused
        type: b2
      - id: actors
        type: b2
        doc: 0 off, 1 on, 2 and 3 unchanged.
      - id: geometry
        type: b2
      - id: screen
        type: b2

  set_unk:
    seq:
      - id: value
        type: u1

  transform_colors:
    seq:
      - id: target
        type: b4
        doc: 0 actors, 1 scene, 2 background.
      - id: mode
        type: b4
        doc: 8 restores the original colours.
      - id: actor
        type: actor_selector
      - id: duration
        type: u1
        doc: As a power of two frames, 0 to 4, higher is instant.
      - id: r
        type: s1
      - id: g
        type: s1
      - id: b
        type: s1

  fade_actor:
    seq:
      - id: actor
        type: actor_selector
      - id: fade
        type: u1
        doc: 1 fades out, 2 fades in.

  draw_sheathe_ashley_weapon:
    seq:
      - id: draw
        type: u1
        doc: 0 sheathes, 1 draws.
      - id: animation
        type: u1
        doc: 0 at once, 1 quick, 2 slow.

  set_background_visible:
    seq:
      - id: visible
        type: u1

  load_background:
    seq:
      - id: texture_page_slot
        type: u1

  set_particle_effect:
    seq:
      - id: effect
        type: b4
        doc: 0 none, 1 rain, 2 snow, 3 heavy snow, 4 dark particles.
      - id: intensity
        type: b4
      - id: direction
        type: u1
        doc: 1/256 turn.
      - id: fall_angle
        type: u1
        doc: 0x80 falls straight down.
      - id: blend_frames
        type: u1
        doc: 0 is at once.

  freeze_particle_effect:
    seq:
      - id: frozen
        type: u1

  control_room_task:
    seq:
      - id: pause_resume
        type: u1
        doc: 0 starts the task, 1 pauses or resumes it.
      - id: task
        type: u1
        doc: The scripted tasks start at 0x40.

  set_particle_effect_sound_scripted:
    seq:
      - id: scripted
        type: u1

  set_background_offset:
    seq:
      - id: x
        type: s2
      - id: y
        type: s2

  cull_occluding_geometry:
    seq:
      - id: enabled
        type: u1

  adjust_geometry_depth:
    seq:
      - id: object
        type: u1
      - id: amount
        type: s1

  set_background_parallax:
    seq:
      - id: horizontal
        type: s1
      - id: vertical
        type: s1
      - id: unused
        type: u1

  play_sfx:
    seq:
      - id: group
        type: u1
        doc: 1 general, 2 the particle effect, 3 the bank selected by set_current_sfx.
      - id: sound
        type: u1
      - id: pan
        type: u1
        doc: 0x80 is centre.
      - id: volume
        type: u1
        doc: Up to 0x7F.

  play_actor_sfx:
    seq:
      - id: actor
        type: actor_selector
      - id: type
        type: u1

  fade_sfx_volume:
    seq:
      - id: group
        type: u1
      - id: sound
        type: u1
        doc: 0 is every sound in the group.
      - id: volume
        type: u1
      - id: duration
        type: u1

  stop_sfx:
    seq:
      - id: group
        type: u1
      - id: sound
        type: u1
        doc: 0 is every sound in the group.

  load_sfx_slot:
    seq:
      - id: file
        type: u1
      - id: slot
        type: u1
        doc: 1 to 3.

  wait_sfx_load:
    seq:
      - id: slot
        type: u1
        doc: 1 to 3.

  free_sfx:
    seq:
      - id: slot
        type: u1
        doc: 1 to 3.

  set_current_sfx:
    seq:
      - id: slot
        type: u1
        doc: 1 to 3.

  crossfade_music:
    seq:
      - id: slot
        type: u1
        doc: 1 to 4.
      - id: volume
        type: u1
      - id: fade_in
        type: u1
      - id: fade_out
        type: u1

  load_music_slot:
    seq:
      - id: music
        type: u1
      - id: slot
        type: u1
        doc: 1 to 4.

  free_music:
    seq:
      - id: slot
        type: u1
        doc: 1 to 4.

  play_music:
    seq:
      - id: slot
        type: u1
        doc: 1 to 4.
      - id: volume
        type: u1
      - id: fade
        type: u1

  fade_music_volume:
    seq:
      - id: volume
        type: u1
      - id: duration
        type: u1

  ramp_music_tempo:
    seq:
      - id: tempo
        type: s1
      - id: duration
        type: u1

  ramp_music_pitch:
    seq:
      - id: pitch
        type: s1
      - id: duration
        type: u1

  wait_music_silent:
    seq:
      - id: slot
        type: u1
        doc: 1 to 4.

  wait_music_load:
    seq:
      - id: slot
        type: u1
        doc: 1 to 4.

  wait_music_bar:
    seq:
      - id: bar
        type: u2

  ramp_sfx_pitch:
    seq:
      - id: group
        type: u1
      - id: sound
        type: u1
        doc: 0 is every sound in the group.
      - id: pitch
        type: s1
      - id: duration
        type: u1

  ramp_sfx_pan:
    seq:
      - id: group
        type: u1
      - id: sound
        type: u1
        doc: 0 is every sound in the group.
      - id: pan
        type: u1
        doc: 0x80 is centre.
      - id: duration
        type: u1

  load_instrument_bank:
    seq:
      - id: music
        type: u1

  queue_music:
    seq:
      - id: slot
        type: u1
        doc: 1 to 4.

  start_effect:
    seq:
      - id: effect
        type: u2
        doc: The effect is EFFECT/E<effect>.P.
      - id: target
        type: actor_selector

  trigger_effect_stage:
    seq:
      - id: stage
        type: u1

  wait_effect_state:
    seq:
      - id: state
        type: u1

  rearm_effect_stage:
    seq:
      - id: stage
        type: u1

  set_music_target_cue:
    seq:
      - id: cue
        type: u1

  play_vibration:
    seq:
      - id: pattern
        type: u1
        doc: 0xFF stops. Adding 8 copies the pattern before playing.

  set_actor_trail:
    seq:
      - id: start
        type: u1
        doc: 0 stops every trail.
      - id: actor
        type: actor_selector
      - id: bone
        type: u1

  set_entered_door:
    seq:
      - id: door
        type: u1

  set_flags_to_actor_distance_and_angle:
    seq:
      - id: actor
        type: actor_selector
      - id: other
        type: actor_selector
      - id: scale
        type: u1
      - id: flag
        type: u2
        doc: The angle is stored in the following flag.

  set_actor_awake:
    seq:
      - id: actor
        type: actor_selector
      - id: awake
        type: u1
        doc: 0 is dormant.

  show_misc_loot:
    seq:
      - id: item_0
        type: u2
      - id: count_0
        type: u1
      - id: item_1
        type: u2
      - id: count_1
        type: u1

  remove_misc_item:
    seq:
      - id: item
        type: u2

  set_flag_to_actor_distance:
    seq:
      - id: actor
        type: actor_selector
      - id: other
        type: actor_selector
      - id: flag
        type: u2

  special_op:
    seq:
      - id: sub_opcode
        type: u1
      - id: argument
        type: u1
      - id: unused_0
        type: u1
      - id: unused_1
        type: u2

  set_screen_blur:
    seq:
      - id: depth
        type: u2
        doc: 0 is off.

  nop_bd:
    seq:
      - id: unused
        type: u1

  stop_camera:
    seq:
      - id: unused
        type: u1

  set_camera_momentum:
    seq:
      - id: flags
        type: u1
        doc: Bit 0 look-at, bit 1 eye.

  wait_camera_idle:
    seq:
      - id: mask
        type: u1

  set_framebuffer_effect:
    seq:
      - id: enabled
        type: u1

  attach_camera_to_actor:
    seq:
      - id: actor
        type: u2
        doc: 0x2000 detaches.

  return_to_gameplay_camera:
    seq:
      - id: facing
        type: u1
        doc: In 45 degree steps, 0xFF is unchanged.
      - id: zoom
        type: u1
        doc: 1 normal, 2 zoomed out, 0 unchanged.

  set_frame_rate:
    seq:
      - id: rate
        type: u1
        doc: 2 is full rate, 4 half.

  play_menu_select_sfx:
    seq:
      - id: unused
        type: u4

  set_scanlines:
    seq:
      - id: enabled
        type: u1

  nop_44:
    seq:
      - id: unused
        type: u1
        doc: A label or block marker, 531 uses, every one with a different operand.

  set_camera_destination:
    seq:
      - id: x
        type: s2
      - id: y
        type: s2
      - id: z
        type: s2

  camera_lerp_to:
    seq:
      - id: easing
        type: u1
      - id: duration
        type: u1

  camera_orbit_to:
    seq:
      - id: angle_easing
        type: b4
      - id: direction
        type: b4
        doc: 0 shortest, 1 positive, 15 negative.
      - id: height_easing
        type: b4
      - id: distance_easing
        type: b4
      - id: duration
        type: u1

  camera_orbit_by:
    seq:
      - id: angle
        type: s2
      - id: final_height
        type: s2
        doc: World y.
      - id: distance_scale
        type: u1
        doc: In 1/64 units.
      - id: distance_easing
        type: b4
      - id: angle_easing
        type: b4
      - id: height_easing
        type: u1
      - id: duration
        type: u1

  camera_set_destination_to_actor_offset:
    seq:
      - id: actor
        type: actor_selector
      - id: point
        type: u1
        doc: A bone id or an actor point.
      - id: x
        type: s2
      - id: y
        type: s2
      - id: z
        type: s2

  camera_follow_actor:
    seq:
      - id: actor
        type: actor_selector
      - id: point
        type: u1
        doc: A bone id or an actor point.
      - id: x
        type: s2
      - id: y
        type: s2
      - id: z
        type: s2
      - id: duration
        type: u1

  camera_lock_offset:
    seq:
      - id: duration
        type: u1

  camera_terrain_follow_to:
    seq:
      - id: unused
        type: u1
      - id: duration
        type: u1

  camera_roll:
    seq:
      - id: angle
        type: s2
      - id: easing
        type: b4
      - id: direction
        type: b4
        doc: 0 negative, 1 shortest, 2 positive.
      - id: duration
        type: u1
        doc: 0 sets the angle immediately.
      - id: unused
        type: u1

  framebuffer_effect_scale:
    seq:
      - id: x
        type: u1
        doc: Scaled by 128.
      - id: y
        type: u1
      - id: easing
        type: u1
      - id: duration
        type: u1
        doc: 0 is immediate.

  framebuffer_effect_tint:
    seq:
      - id: r
        type: u1
      - id: g
        type: u1
      - id: b
        type: u1
      - id: easing
        type: u1
      - id: duration
        type: u1
        doc: 0 is immediate.

  framebuffer_effect_offset:
    seq:
      - id: x
        type: s1
      - id: y
        type: s1
      - id: easing
        type: u1
      - id: duration
        type: u1
        doc: 0 is immediate.

  framebuffer_effect_blend_mode:
    seq:
      - id: blend_mode
        type: u1

  lens_distortion:
    seq:
      - id: zoom
        type: u1
        doc: Scaled by 64.
      - id: distortion
        type: s1
      - id: easing
        type: u1
      - id: duration
        type: u1
        doc: 0 is immediate.

  framebuffer_effect_depth:
    seq:
      - id: depth
        type: u2
        doc: Ordering table index.

  framebuffer_effect_use_previous_frame:
    seq:
      - id: use_previous_frame
        type: u1

  framebuffer_effect_preset:
    seq:
      - id: depth
        type: u2
        doc: 0 turns the effect off, otherwise the ordering table index.

  projection_distance:
    seq:
      - id: distance
        type: u1
        doc: Scaled by 4, 0 is the default.
      - id: easing
        type: u1
      - id: duration
        type: u1
        doc: 0 is immediate.

  near_clip:
    seq:
      - id: distance
        type: u1
        doc: 0 is the default.
      - id: easing
        type: u1
      - id: duration
        type: u1
        doc: 0 is immediate.

  far_clip:
    seq:
      - id: distance
        type: u1
        doc: Scaled by 128, 0 is the default.
      - id: easing
        type: u1
      - id: duration
        type: u1
        doc: 0 is immediate.

  camera_shake:
    seq:
      - id: oscillations
        type: u1
      - id: amplitude
        type: u1
        doc: In world units, 0 stops all shakes.
      - id: z_weight
        type: b2
      - id: y_weight
        type: b2
      - id: x_weight
        type: b2
        doc: Weights of the shake along each axis, minus 1.
      - id: shakes_eye
        type: b1
      - id: shakes_look_at
        type: b1
      - id: envelope
        type: u1
        doc: 0 constant, 1 fades out, 2 swells then fades, 3 fades in.
      - id: duration
        type: u1

  shape_table:
    seq:
      - id: unused_slot_0
        contents: [0, 0]
      - id: offsets
        type: u2
        repeat: expr
        repeat-expr: 7
      - id: shapes
        type: shape
        repeat: eos

  shape:
    seq:
      - id: num_vertices
        type: u1
      - id: num_tails
        type: u1
      - id: outline_count
        type: u1
      - id: quad_count
        type: u1
      - id: tails
        type: shape_tail
        repeat: expr
        repeat-expr: num_tails.as<u1>
      - id: vertices
        type: shape_vertex
        repeat: expr
        repeat-expr: num_vertices
      - id: body
        type: shape_quads(quad_count)
      - id: tail_quads
        type: shape_quads(tails[_index].quad_count)
        repeat: expr
        repeat-expr: num_tails.as<u1>

  shape_tail:
    seq:
      - id: anchor
        type: u1
      - id: join
        type: u1
      - id: vertex_count
        type: u1
      - id: quad_count
        type: u1

  shape_vertex:
    seq:
      - id: x
        type: u1
      - id: y
        type: u1

  shape_quads:
    params:
      - id: num_quads
        type: u1
    seq:
      - id: quads
        type: shape_quad
        repeat: expr
        repeat-expr: num_quads

  shape_quad:
    seq:
      - id: v0
        type: u1
      - id: v1
        type: u1
      - id: v2
        type: u1
      - id: v3
        type: u1
        doc: 0xFF makes it a triangle.

  vibration_table:
    seq:
      - id: offsets
        type: u2
        repeat: expr
        repeat-expr: 8
      - id: patterns
        type: vibration_pattern
        repeat: eos

  vibration_pattern:
    seq:
      - id: num_effects
        type: u4
        valid: 1
      - id: ofs_script
        type: u2
        valid: 8
      - id: unused
        type: u2
      - id: ofs_large_motor
        type: u1
      - id: small_motor
        type: vibration_keyframes
      - id: large_motor
        type: vibration_keyframes
      - id: padding
        size: 4 - (9 + 2 * (small_motor.keyframes.size + large_motor.keyframes.size)) % 4

  vibration_keyframes:
    seq:
      - id: keyframes
        type: vibration_keyframe
        repeat: until
        repeat-until: _.frames == 0

  vibration_keyframe:
    seq:
      - id: frames
        type: u1
      - id: level
        type: u1

enums:
  flag_operation:
    0: add
    1: subtract
    2: multiply
    3: divide
    4: modulo
    5: bitwise_and
    6: bitwise_or
    7: assign
    8: abs_difference
    9: swap

  actor_selector_kind:
    0: by_id
    1: slot
    2: special

  flag_comparison:
    0: le
    1: ge
    2: eq
    3: ne
    4: lt
    5: gt
    6: bitwise_and

  opcode:
    0x0A: wait_evt_load
    0x0C: wait_gim_load
    0x0D: begin_skippable
    0x0E: end_skippable_body
    0x0F: end_skip_handler
    0x10: init_text_box
    0x11: show_text_box
    0x12: dismiss_text_box
    0x13: init_text_box_near_actor
    0x14: dismiss_text_box_and_wait
    0x15: wait_button_pressed
    0x16: load_gim
    0x17: show_gim_image
    0x18: tween_gim_image
    0x19: unload_gim
    0x1A: wait_gim_tweens
    0x1B: set_printf_arg_int
    0x1C: select_text_box
    0x1D: set_text_box_animation_duration
    0x1E: actor_death
    0x1F: get_actor_tile
    0x20: spawn_actor
    0x21: walk_actor_to_tile
    0x22: play_animation
    0x23: set_actor_flags
    0x24: set_actor_sfx_pan_volume
    0x25: move_actor_to_tile
    0x26: move_actor_to_coordinate
    0x27: slide_actor_to_tile
    0x28: slide_actor_to_coordinate
    0x29: attach_actor
    0x2A: walk_actor_to_coordinate
    0x2B: turn_actor_to_facing
    0x2C: turn_actor_to_face_actor
    0x2D: turn_actor_to_face_tile
    0x2E: set_actor_scale
    0x2F: despawn_actor
    0x30: wait_actor_activity
    0x31: set_actor_light_color
    0x32: queue_animation
    0x33: rotate_actor
    0x34: set_actor_look_angles
    0x35: play_animation_from_frame
    0x36: queue_animation_from_frame
    0x37: set_actor_move_animation
    0x38: set_actor_look_target
    0x39: set_actor_look_position
    0x3A: enqueue_event_data
    0x3B: wait_data_queue_empty
    0x3C: unload_event_data
    0x3D: select_event_data
    0x3E: set_actor_edge_highlight
    0x3F: set_weapon_drawn
    0x40: jump_fwd_unless_flag_imm
    0x41: jump_fwd_unless_flag
    0x42: jump_fwd_else
    0x43: nop_43
    0x44: nop_44
    0x45: jump_fwd
    0x46: switch_on_flag
    0x47: jump_fwd_case
    0x48: end_scene_reset
    0x49: set_loop_counter
    0x4A: loop_condition
    0x4B: break_loop
    0x4C: jump_fwd_unused
    0x50: modify_flag_imm
    0x51: modify_flag
    0x52: set_flag_to_item_count
    0x53: forget_zone_enemies
    0x54: play_weapon_sfx
    0x55: set_actors_awake
    0x56: set_flag_to_buttons
    0x57: fully_restore_actor
    0x58: set_ui_visible
    0x59: open_menu
    0x5A: set_battle_timer
    0x5B: set_text_box_speaker
    0x5C: set_actor_weapon_models
    0x5D: set_actor_sway
    0x5E: wait_frames_or_button
    0x5F: define_easing
    0x60: set_cloudstone_moving
    0x61: override_fog_depth
    0x62: set_first_person_rendering
    0x63: status_unk
    0x64: show_geometry
    0x65: hide_geometry
    0x66: swap_geometry_flags
    0x67: set_tile_blocked
    0x68: warp
    0x69: screen_transition_out
    0x6A: screen_transition_in
    0x6B: set_screen_transition_wipe_angle
    0x6C: set_screen_transition
    0x6D: set_scene_visibility
    0x6E: wait_for_screen_transition
    0x6F: set_unk
    0x70: transform_colors
    0x71: fade_actor
    0x72: draw_sheathe_ashley_weapon
    0x73: set_background_visible
    0x74: load_background
    0x75: wait_background_load
    0x76: unload_background
    0x77: set_particle_effect
    0x78: freeze_particle_effect
    0x79: control_room_task
    0x7A: set_particle_effect_sound_scripted
    0x7B: set_background_offset
    0x7C: cull_occluding_geometry
    0x7D: adjust_geometry_depth
    0x7E: set_background_parallax
    0x80: play_sfx
    0x81: play_actor_sfx
    0x82: fade_sfx_volume
    0x83: stop_all_sfx
    0x84: stop_sfx
    0x85: load_sfx_slot
    0x86: wait_sfx_load
    0x87: free_sfx
    0x88: set_current_sfx
    0x89: load_area_music
    0x8F: crossfade_music
    0x90: load_music_slot
    0x91: free_music
    0x92: play_music
    0x93: fade_music_volume
    0x94: ramp_music_tempo
    0x95: ramp_music_pitch
    0x96: stop_music
    0x97: wait_music_silent
    0x98: push_music_state
    0x99: wait_music_load
    0x9A: wait_music_bar
    0x9B: ramp_sfx_pitch
    0x9C: ramp_sfx_pan
    0x9D: load_instrument_bank
    0x9E: wait_instrument_bank_load
    0x9F: queue_music
    0xA0: start_effect
    0xA1: trigger_effect_stage
    0xA2: wait_effect_state
    0xA3: yield_if_skipping
    0xA4: wait_effect_stage_ready
    0xA5: cancel_effect
    0xA6: rearm_effect_stage
    0xA8: set_music_target_cue
    0xA9: play_vibration
    0xAA: set_actor_trail
    0xB1: set_entered_door
    0xB2: set_flags_to_actor_distance_and_angle
    0xB3: set_actor_awake
    0xB4: show_misc_loot
    0xB5: remove_misc_item
    0xB6: set_flag_to_actor_distance
    0xB7: special_op
    0xB8: wait_screen_effects_loaded
    0xB9: framebuffer_effect_depth
    0xBA: framebuffer_effect_use_previous_frame
    0xBB: set_screen_blur
    0xBC: load_screen_effects
    0xBD: nop_bd
    0xBE: unload_screen_effects
    0xBF: framebuffer_effect_preset
    0xC0: look_at_set_destination
    0xC1: look_at_cut
    0xC2: look_at_lerp_to
    0xC3: look_at_arc_to
    0xC4: look_at_orbit_to
    0xC5: look_at_orbit_by
    0xC7: look_at_set_destination_to_actor_offset
    0xC8: look_at_follow_actor
    0xC9: look_at_lock_offset
    0xCA: look_at_set_destination_to_actor_local_offset
    0xCB: look_at_terrain_follow_to
    0xD0: eye_set_destination
    0xD1: eye_cut
    0xD2: eye_lerp_to
    0xD3: eye_arc_to
    0xD4: eye_orbit_to
    0xD5: eye_orbit_by
    0xD7: eye_set_destination_to_actor_offset
    0xD8: eye_follow_actor
    0xD9: eye_lock_offset
    0xDA: eye_set_destination_to_actor_local_offset
    0xDB: eye_terrain_follow_to
    0xDE: stop_camera
    0xDF: set_camera_momentum
    0xE0: wait_camera_idle
    0xE1: set_framebuffer_effect
    0xE2: camera_roll
    0xE3: framebuffer_effect_spin
    0xE4: framebuffer_effect_scale
    0xE5: framebuffer_effect_tint
    0xE6: framebuffer_effect_offset
    0xE7: framebuffer_effect_blend_mode
    0xE8: attach_camera_to_actor
    0xE9: return_to_gameplay_camera
    0xEA: projection_distance
    0xEB: near_clip
    0xEC: far_clip
    0xED: lens_distortion
    0xEF: camera_shake
    0xF0: wait_frames
    0xF1: set_frame_rate
    0xF2: play_menu_select_sfx
    0xF3: set_scanlines
    0xF4: join_script
    0xF5: fork_and_jump
    0xF6: end_script
    0xF7: queue_next_evt
    0xFE: end_scene
    0xFF: end_scene_ff
