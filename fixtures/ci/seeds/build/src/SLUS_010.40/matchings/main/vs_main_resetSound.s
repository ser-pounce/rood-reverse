nonmatching vs_main_resetSound, 0x104

glabel vs_main_resetSound
    /* 37238 80046A38 21200000 */  addu       $a0, $zero, $zero
    /* 3723C 80046A3C FFFF0634 */  ori        $a2, $zero, 0xFFFF
    /* 37240 80046A40 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 37244 80046A44 38E04324 */  addiu      $v1, $v0, %lo(vs_main_soundData)
    /* 37248 80046A48 21286000 */  addu       $a1, $v1, $zero
    /* 3724C 80046A4C 38E040AC */  sw         $zero, %lo(vs_main_soundData)($v0)
    /* 37250 80046A50 2110C000 */  addu       $v0, $a2, $zero
    /* 37254 80046A54 0C0060AC */  sw         $zero, 0xC($v1)
    /* 37258 80046A58 080062AC */  sw         $v0, 0x8($v1)
    /* 3725C 80046A5C 040062AC */  sw         $v0, 0x4($v1)
    /* 37260 80046A60 440060AC */  sw         $zero, 0x44($v1)
  .L80046A64:
    /* 37264 80046A64 21108300 */  addu       $v0, $a0, $v1
    /* 37268 80046A68 100040A0 */  sb         $zero, 0x10($v0)
    /* 3726C 80046A6C 1400A6AC */  sw         $a2, 0x14($a1)
    /* 37270 80046A70 2400A0AC */  sw         $zero, 0x24($a1)
    /* 37274 80046A74 3400A0AC */  sw         $zero, 0x34($a1)
    /* 37278 80046A78 01008424 */  addiu      $a0, $a0, 0x1
    /* 3727C 80046A7C 04008228 */  slti       $v0, $a0, 0x4
    /* 37280 80046A80 F8FF4014 */  bnez       $v0, .L80046A64
    /* 37284 80046A84 0400A524 */   addiu     $a1, $a1, 0x4
    /* 37288 80046A88 21200000 */  addu       $a0, $zero, $zero
    /* 3728C 80046A8C 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 37290 80046A90 38E04324 */  addiu      $v1, $v0, %lo(vs_main_soundData)
    /* 37294 80046A94 21286000 */  addu       $a1, $v1, $zero
  .L80046A98:
    /* 37298 80046A98 21108500 */  addu       $v0, $a0, $a1
    /* 3729C 80046A9C 480040A0 */  sb         $zero, 0x48($v0)
    /* 372A0 80046AA0 4C0060AC */  sw         $zero, 0x4C($v1)
    /* 372A4 80046AA4 580060AC */  sw         $zero, 0x58($v1)
    /* 372A8 80046AA8 01008424 */  addiu      $a0, $a0, 0x1
    /* 372AC 80046AAC 03008228 */  slti       $v0, $a0, 0x3
    /* 372B0 80046AB0 F9FF4014 */  bnez       $v0, .L80046A98
    /* 372B4 80046AB4 04006324 */   addiu     $v1, $v1, 0x4
    /* 372B8 80046AB8 21200000 */  addu       $a0, $zero, $zero
    /* 372BC 80046ABC 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 372C0 80046AC0 38E04324 */  addiu      $v1, $v0, %lo(vs_main_soundData)
  .L80046AC4:
    /* 372C4 80046AC4 640060AC */  sw         $zero, 0x64($v1)
    /* 372C8 80046AC8 700060AC */  sw         $zero, 0x70($v1)
    /* 372CC 80046ACC 01008424 */  addiu      $a0, $a0, 0x1
    /* 372D0 80046AD0 03008228 */  slti       $v0, $a0, 0x3
    /* 372D4 80046AD4 FBFF4014 */  bnez       $v0, .L80046AC4
    /* 372D8 80046AD8 04006324 */   addiu     $v1, $v1, 0x4
    /* 372DC 80046ADC 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 372E0 80046AE0 38E04224 */  addiu      $v0, $v0, %lo(vs_main_soundData)
    /* 372E4 80046AE4 0680033C */  lui        $v1, %hi(D_8005FE70)
    /* 372E8 80046AE8 7C0040AC */  sw         $zero, 0x7C($v0)
    /* 372EC 80046AEC 800040AC */  sw         $zero, 0x80($v0)
    /* 372F0 80046AF0 840040AC */  sw         $zero, 0x84($v0)
    /* 372F4 80046AF4 01000224 */  addiu      $v0, $zero, 0x1
    /* 372F8 80046AF8 70FE62AC */  sw         $v0, %lo(D_8005FE70)($v1)
    /* 372FC 80046AFC 0680033C */  lui        $v1, %hi(D_8005FE74)
    /* 37300 80046B00 02000224 */  addiu      $v0, $zero, 0x2
    /* 37304 80046B04 74FE62AC */  sw         $v0, %lo(D_8005FE74)($v1)
    /* 37308 80046B08 0680033C */  lui        $v1, %hi(D_8005FE78)
    /* 3730C 80046B0C 80000224 */  addiu      $v0, $zero, 0x80
    /* 37310 80046B10 78FE62AC */  sw         $v0, %lo(D_8005FE78)($v1)
    /* 37314 80046B14 0680033C */  lui        $v1, %hi(D_8005FE7C)
    /* 37318 80046B18 00020224 */  addiu      $v0, $zero, 0x200
    /* 3731C 80046B1C 7CFE62AC */  sw         $v0, %lo(D_8005FE7C)($v1)
    /* 37320 80046B20 0680033C */  lui        $v1, %hi(D_8005FE80)
    /* 37324 80046B24 00100224 */  addiu      $v0, $zero, 0x1000
    /* 37328 80046B28 80FE62AC */  sw         $v0, %lo(D_8005FE80)($v1)
    /* 3732C 80046B2C 0680033C */  lui        $v1, %hi(D_8005FE84)
    /* 37330 80046B30 1000023C */  lui        $v0, (0x100000 >> 16)
    /* 37334 80046B34 0800E003 */  jr         $ra
    /* 37338 80046B38 84FE62AC */   sw        $v0, %lo(D_8005FE84)($v1)
endlabel vs_main_resetSound
