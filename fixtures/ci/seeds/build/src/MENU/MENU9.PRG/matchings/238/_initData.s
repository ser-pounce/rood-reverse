nonmatching _initData, 0x1C0

glabel _initData
    /* 9BC 801031BC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9C0 801031C0 0680023C */  lui        $v0, %hi(vs_main_mapStatus)
    /* 9C4 801031C4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 9C8 801031C8 D8FF5024 */  addiu      $s0, $v0, %lo(vs_main_mapStatus)
    /* 9CC 801031CC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 9D0 801031D0 0400038E */  lw         $v1, 0x4($s0)
    /* 9D4 801031D4 8000023C */  lui        $v0, (0x800000 >> 16)
    /* 9D8 801031D8 24106200 */  and        $v0, $v1, $v0
    /* 9DC 801031DC 03004010 */  beqz       $v0, .L801031EC
    /* 9E0 801031E0 4000023C */   lui       $v0, (0x400000 >> 16)
    /* 9E4 801031E4 25106200 */  or         $v0, $v1, $v0
    /* 9E8 801031E8 040002AE */  sw         $v0, 0x4($s0)
  .L801031EC:
    /* 9EC 801031EC 1180023C */  lui        $v0, %hi(_menuState)
    /* 9F0 801031F0 3CA440AC */  sw         $zero, %lo(_menuState)($v0)
    /* 9F4 801031F4 0680023C */  lui        $v0, %hi(D_80060021)
    /* 9F8 801031F8 21004390 */  lbu        $v1, %lo(D_80060021)($v0)
    /* 9FC 801031FC 1180023C */  lui        $v0, %hi(D_8010A45C)
    /* A00 80103200 05006014 */  bnez       $v1, .L80103218
    /* A04 80103204 5CA440AC */   sw        $zero, %lo(D_8010A45C)($v0)
    /* A08 80103208 0F80043C */  lui        $a0, %hi(vs_battle_menu9CursorMemory)
    /* A0C 8010320C F01B8424 */  addiu      $a0, $a0, %lo(vs_battle_menu9CursorMemory)
    /* A10 80103210 4424010C */  jal        vs_main_bzero
    /* A14 80103214 08000524 */   addiu     $a1, $zero, 0x8
  .L80103218:
    /* A18 80103218 1180023C */  lui        $v0, %hi(_mapCompletion)
    /* A1C 8010321C 6AA440A4 */  sh         $zero, %lo(_mapCompletion)($v0)
    /* A20 80103220 21280000 */  addu       $a1, $zero, $zero
    /* A24 80103224 01000924 */  addiu      $t1, $zero, 0x1
    /* A28 80103228 0F80023C */  lui        $v0, %hi(vs_battle_mapCompletionFlags)
    /* A2C 8010322C 08854824 */  addiu      $t0, $v0, %lo(vs_battle_mapCompletionFlags)
    /* A30 80103230 21380002 */  addu       $a3, $s0, $zero
  .L80103234:
    /* A34 80103234 21200000 */  addu       $a0, $zero, $zero
    /* A38 80103238 0000E38C */  lw         $v1, 0x0($a3)
    /* A3C 8010323C 0000028D */  lw         $v0, 0x0($t0)
    /* A40 80103240 1180063C */  lui        $a2, %hi(_mapCompletion)
    /* A44 80103244 24186200 */  and        $v1, $v1, $v0
    /* A48 80103248 04108900 */  sllv       $v0, $t1, $a0
  .L8010324C:
    /* A4C 8010324C 24106200 */  and        $v0, $v1, $v0
    /* A50 80103250 05004010 */  beqz       $v0, .L80103268
    /* A54 80103254 00000000 */   nop
    /* A58 80103258 6AA4C294 */  lhu        $v0, %lo(_mapCompletion)($a2)
    /* A5C 8010325C 00000000 */  nop
    /* A60 80103260 01004224 */  addiu      $v0, $v0, 0x1
    /* A64 80103264 6AA4C2A4 */  sh         $v0, %lo(_mapCompletion)($a2)
  .L80103268:
    /* A68 80103268 01008424 */  addiu      $a0, $a0, 0x1
    /* A6C 8010326C 20008228 */  slti       $v0, $a0, 0x20
    /* A70 80103270 F6FF4014 */  bnez       $v0, .L8010324C
    /* A74 80103274 04108900 */   sllv      $v0, $t1, $a0
    /* A78 80103278 04000825 */  addiu      $t0, $t0, 0x4
    /* A7C 8010327C 0100A524 */  addiu      $a1, $a1, 0x1
    /* A80 80103280 1000A228 */  slti       $v0, $a1, 0x10
    /* A84 80103284 EBFF4014 */  bnez       $v0, .L80103234
    /* A88 80103288 0400E724 */   addiu     $a3, $a3, 0x4
    /* A8C 8010328C 1180033C */  lui        $v1, %hi(D_8010A468)
    /* A90 80103290 68A460A4 */  sh         $zero, %lo(D_8010A468)($v1)
    /* A94 80103294 21280000 */  addu       $a1, $zero, $zero
    /* A98 80103298 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* A9C 8010329C 98154424 */  addiu      $a0, $v0, %lo(vs_main_stateFlags)
    /* AA0 801032A0 2110A400 */  addu       $v0, $a1, $a0
  .L801032A4:
    /* AA4 801032A4 C0034290 */  lbu        $v0, 0x3C0($v0)
    /* AA8 801032A8 00000000 */  nop
    /* AAC 801032AC 05004010 */  beqz       $v0, .L801032C4
    /* AB0 801032B0 00000000 */   nop
    /* AB4 801032B4 68A46294 */  lhu        $v0, %lo(D_8010A468)($v1)
    /* AB8 801032B8 00000000 */  nop
    /* ABC 801032BC 01004224 */  addiu      $v0, $v0, 0x1
    /* AC0 801032C0 68A462A4 */  sh         $v0, %lo(D_8010A468)($v1)
  .L801032C4:
    /* AC4 801032C4 0100A524 */  addiu      $a1, $a1, 0x1
    /* AC8 801032C8 4000A228 */  slti       $v0, $a1, 0x40
    /* ACC 801032CC F5FF4014 */  bnez       $v0, .L801032A4
    /* AD0 801032D0 2110A400 */   addu      $v0, $a1, $a0
    /* AD4 801032D4 0680033C */  lui        $v1, %hi(vs_main_stateFlags)
    /* AD8 801032D8 1180043C */  lui        $a0, %hi(_mapCompletion)
    /* ADC 801032DC 0680023C */  lui        $v0, %hi(vs_main_scoredata)
    /* AE0 801032E0 A0FE4624 */  addiu      $a2, $v0, %lo(vs_main_scoredata)
    /* AE4 801032E4 98156590 */  lbu        $a1, %lo(vs_main_stateFlags)($v1)
    /* AE8 801032E8 6AA48494 */  lhu        $a0, %lo(_mapCompletion)($a0)
    /* AEC 801032EC 9400C28C */  lw         $v0, 0x94($a2)
    /* AF0 801032F0 1180033C */  lui        $v1, %hi(_clearCount)
    /* AF4 801032F4 2B104400 */  sltu       $v0, $v0, $a0
    /* AF8 801032F8 02004010 */  beqz       $v0, .L80103304
    /* AFC 801032FC 66A465A4 */   sh        $a1, %lo(_clearCount)($v1)
    /* B00 80103300 9400C4AC */  sw         $a0, 0x94($a2)
  .L80103304:
    /* B04 80103304 1180023C */  lui        $v0, %hi(D_8010A468)
    /* B08 80103308 68A44394 */  lhu        $v1, %lo(D_8010A468)($v0)
    /* B0C 8010330C 9800C28C */  lw         $v0, 0x98($a2)
    /* B10 80103310 00000000 */  nop
    /* B14 80103314 2B104300 */  sltu       $v0, $v0, $v1
    /* B18 80103318 02004010 */  beqz       $v0, .L80103324
    /* B1C 8010331C 1180043C */   lui       $a0, %hi(D_8010A480)
    /* B20 80103320 9800C3AC */  sw         $v1, 0x98($a2)
  .L80103324:
    /* B24 80103324 80A48424 */  addiu      $a0, $a0, %lo(D_8010A480)
    /* B28 80103328 801F053C */  lui        $a1, (0x1F800034 >> 16)
    /* B2C 8010332C 3400A534 */  ori        $a1, $a1, (0x1F800034 & 0xFFFF)
    /* B30 80103330 2C24010C */  jal        vs_main_memcpy
    /* B34 80103334 10000624 */   addiu     $a2, $zero, 0x10
    /* B38 80103338 1180043C */  lui        $a0, %hi(D_8010A490)
    /* B3C 8010333C 90A48424 */  addiu      $a0, $a0, %lo(D_8010A490)
    /* B40 80103340 801F053C */  lui        $a1, (0x1F800054 >> 16)
    /* B44 80103344 5400A534 */  ori        $a1, $a1, (0x1F800054 & 0xFFFF)
    /* B48 80103348 2C24010C */  jal        vs_main_memcpy
    /* B4C 8010334C 10000624 */   addiu     $a2, $zero, 0x10
    /* B50 80103350 A91D040C */  jal        _setTitleFlags
    /* B54 80103354 00000000 */   nop
    /* B58 80103358 0D1F040C */  jal        _calculateScore
    /* B5C 8010335C 00000000 */   nop
    /* B60 80103360 801D040C */  jal        _determineCharacterRank
    /* B64 80103364 00000000 */   nop
    /* B68 80103368 1400BF8F */  lw         $ra, 0x14($sp)
    /* B6C 8010336C 1000B08F */  lw         $s0, 0x10($sp)
    /* B70 80103370 01000224 */  addiu      $v0, $zero, 0x1
    /* B74 80103374 0800E003 */  jr         $ra
    /* B78 80103378 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _initData
