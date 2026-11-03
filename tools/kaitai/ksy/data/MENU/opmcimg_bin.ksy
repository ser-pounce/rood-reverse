meta:
  id: opmcimg_bin
  file-extension: BIN
  endian: le
  bit-endian: le
  imports: [/img]

seq:
  - id: title_frame
    type: title_frame
    size: 0x80
  - id: icon_frame0
    size: 0x80
    doc: 16x16 4bpp icon bitmap, palette in title_frame.icon_palette
  - id: pocket_station_icon
    size: 0x80
    doc: |
      PocketStation file viewer mono icon slot (32x32, 1bpp). Zero in these
      files; the title frame's PocketStation header is also unset.
  - id: key
    type: u4
    doc: Key for the keystream applied to everything after it
  - id: encrypted
    size: 0x2000 - 0x184

types:
  title_frame:
    doc: PS1 memory card title frame
    seq:
      - id: magic
        contents: 'SC'
      - id: icon_flag
        type: u1
        doc: 0x11 to 0x13, number of icon frames
      - id: block_count
        type: u1
      - id: title
        size: 64
        type: str
        encoding: Shift_JIS
        doc: |
          Full-width template string with the file number and playtime digits
          patched in, e.g. "VAGRANT STORY FILE 1   00:00:00"
      - id: reserved44
        size: 0xC
      - id: pocket_station_header
        size: 0x10
        doc: |
          PocketStation header (mono icon frame count, MCX0/MCX1 id, icon list
          size, function count, entry point), zero in these files
      - id: icon_palette
        size: 0x20
        type: img::clut

  decrypted_save:
    doc: |
      Decrypted contents of OPMCIMG*.BIN from offset 0x184 (after the key) to
      the end of the 8KB block, i.e. savedata_t from info.identity.base onward.
    seq:
      - id: identity
        type: identity
      - id: stats
        type: stats
      - id: checksums
        size: 0x5C
        doc: One XOR checksum per 256-byte sector, 92 in a full save
      - id: state_flags
        size: 0x440
      - id: actions_learned
        size: 32
      - id: map_status
        size: 0x48
      - id: settings
        type: settings
      - id: character
        type: character
      - id: inventory
        size: 0xF00
        doc: vs_main_inventory_t, weapons, shields, blades, grips, armor, gems, misc
      - id: inventory_indices
        type: inventory_indices
      - id: spawn_point
        type: spawn_point
      - id: score_data
        type: score_data
      - id: zone_enemy_cache_index
        type: u4
        doc: Index into zone_enemy_cache of the current zone
      - id: zone_enemy_cache
        type: zone_enemy_cache
        repeat: expr
        repeat-expr: 4
      - id: arts_status
        type: arts_status
      - id: unused
        size: 0x220

  identity:
    seq:
      - id: slot_state
        type: u4
        doc: 0xFFFFFFFF in these files
      - id: generation
        type: u4
        doc: Incremented on every save, 0 in these files
      - id: version
        type: u4
        doc: 0x20000107, a BCD date (2000-01-07)

  gametime:
    seq:
      - id: f
        type: s1
      - id: s
        type: s1
      - id: m
        type: s1
      - id: h
        type: s1

  stats:
    seq:
      - id: game_time
        type: gametime
      - id: cumulative_save_count
        type: u2
      - id: current_game_save_count
        type: u2
      - id: current_hp
        type: u2
      - id: max_hp
        type: u2
      - id: save_location
        type: u1
      - id: clear_count
        type: u1
      - id: map_completion
        type: u1
      - id: unk1b
        type: u1
      - id: current_mp
        type: u2
      - id: max_mp
        type: u2

  settings:
    seq:
      - id: unk0_0
        type: b4
      - id: container_empty
        type: b1
      - id: ability_timing_display
        type: b1
      - id: weapon_stat_change
        type: b1
      - id: armor_stat_change
        type: b1
      - id: cursor_memory
        type: s1
      - id: menu_flags
        type: u2
      - id: slot_state
        type: u4
      - id: information
        type: s1
      - id: simple_map
        type: s1
      - id: mono_sound
        type: s1
      - id: vibration_on
        type: s1
      - id: mapped_chain_abilities
        size: 4
      - id: mapped_defense_abilities
        size: 4
      - id: key
        type: u4
      - id: cumulative_save_count
        type: u2
      - id: current_game_save_count
        type: u2
      - id: save_file_generation
        type: u4

  character:
    doc: Ashley's battle state (D_80060068_t)
    seq:
      - id: unk0
        type: u4
      - id: current_hp
        type: s2
      - id: max_hp
        type: s2
      - id: current_mp
        type: s2
      - id: max_mp
        type: s2
      - id: strength
        type: s2
      - id: total_strength
        type: s2
      - id: intelligence
        type: s2
      - id: total_intelligence
        type: s2
      - id: agility
        type: s2
      - id: total_agility
        type: s2
      - id: risk
        type: s2
      - id: flags
        type: u2
      - id: statuses
        type: u4
      - id: status_timers
        size: 8
      - id: limbs
        type: limb
        repeat: expr
        repeat-expr: 6
      - id: weapon_drawn
        type: s4
      - id: camera_pitch
        type: s4
      - id: camera_distance
        type: s4
      - id: unk88
        type: s4
        repeat: expr
        repeat-expr: 9

  limb:
    seq:
      - id: hp
        type: u2
      - id: max_hp
        type: u2
      - id: types
        type: u2
        repeat: expr
        repeat-expr: 4
      - id: affinities
        type: u2
        repeat: expr
        repeat-expr: 8

  inventory_indices:
    seq:
      - id: weapons
        size: 8
      - id: blades
        size: 16
      - id: grips
        size: 16
      - id: shields
        size: 8
      - id: armor
        size: 16
      - id: gems
        size: 48
      - id: misc
        size: 64

  spawn_point:
    doc: |
      Where the player appears when the map loads (_mpdRoomDoorSection_t, the
      same record the map's door table uses).
    seq:
      - id: znd_id
        type: u1
      - id: map_id
        type: u1
      - id: unk2_0
        type: b5
      - id: unk2_5
        type: b5
      - id: unk2_10
        type: b3
      - id: y
        type: b3
      - id: unk4_0
        type: b8
      - id: x
        type: b5
      - id: facing
        type: b2
      - id: unk4_15
        type: b1
      - id: unk6_0
        type: b10
      - id: z
        type: b5
      - id: unk6_15
        type: b1
      - id: unk8
        size: 4

  score_data:
    seq:
      - id: titles
        type: s4
      - id: enemy_kills
        type: u2
        repeat: expr
        repeat-expr: 6
      - id: unk10
        type: s4
      - id: weapon_attacks
        type: u2
        repeat: expr
        repeat-expr: 10
      - id: boss_time_trial_scores
        type: trial_score
        repeat: expr
        repeat-expr: 8 * 3
      - id: max_chain
        type: u2
      - id: unk8a
        type: u2
      - id: clear_count
        type: u4
      - id: completion_time_minutes
        type: u4
      - id: map_completion
        type: u4
      - id: opened_chest_count
        type: u4
      - id: enemy_kill_flags
        type: s4
        repeat: expr
        repeat-expr: 26
      - id: streak_score
        type: u4
      - id: misc_score
        type: u4
      - id: kill_streak_enemy_class
        type: s1
      - id: kill_streak_enemy_count
        type: s1
      - id: weapon_kill_streak_blade_category
        type: s1
      - id: weapon_kill_streak
        type: s1
      - id: chain_streak
        type: u2
      - id: heal_count
        type: u2

  trial_score:
    seq:
      - id: time
        type: b24
      - id: round
        type: b7
      - id: difficulty
        type: b1

  zone_enemy_cache:
    doc: |
      Saved enemy state for one visited map. The game keeps the last four,
      ordered by lru (4 is the most recently entered, 0 is an empty record).
    seq:
      - id: lru
        type: s1
      - id: znd_id
        type: s1
      - id: map_id
        type: u2
      - id: next_slot
        type: u4
        doc: Next write position in the ring buffer of enemies
      - id: enemies
        type: saved_enemy_state
        repeat: expr
        repeat-expr: 8

  saved_enemy_state:
    seq:
      - id: index
        type: u1
        doc: Index of the enemy in the map's enemy table plus 1, 0 if empty
      - id: hidden
        type: u1
      - id: actor_state
        type: s2
      - id: current_hp
        type: s2
      - id: max_hp
        type: s2
      - id: current_mp
        type: s2
      - id: max_mp
        type: s2
      - id: strength
        type: s2
      - id: intelligence
        type: s2
      - id: agility
        type: s2
      - id: limb_hp
        type: s2
        repeat: expr
        repeat-expr: 6
      - id: pad
        type: s2
      - id: statuses
        type: u4
      - id: x
        type: u1
      - id: direction
        type: u1
      - id: z
        type: u1
      - id: height
        type: u1

  arts_status:
    seq:
      - id: arts_learned
        size: 12
      - id: weapon_category_kills
        type: u2
        repeat: expr
        repeat-expr: 10
      - id: battle_abilities_unlocked
        type: u2
      - id: total_kills
        type: u2
