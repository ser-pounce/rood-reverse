nonmatching func_80102A64, 0x10C

glabel func_80102A64
    /* 264 80102A64 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 268 80102A68 1400B1AF */  sw         $s1, 0x14($sp)
    /* 26C 80102A6C 21888000 */  addu       $s1, $a0, $zero
    /* 270 80102A70 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 274 80102A74 08000324 */  addiu      $v1, $zero, 0x8
    /* 278 80102A78 1800BFAF */  sw         $ra, 0x18($sp)
    /* 27C 80102A7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 280 80102A80 88F4030C */  jal        vs_mainMenu_resetStats
    /* 284 80102A84 452543A0 */   sb        $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 288 80102A88 18002296 */  lhu        $v0, 0x18($s1)
    /* 28C 80102A8C 00000000 */  nop
    /* 290 80102A90 30004010 */  beqz       $v0, .L80102B54
    /* 294 80102A94 1080103C */   lui       $s0, %hi(vs_mainMenu_equipmentStats)
    /* 298 80102A98 C0241026 */  addiu      $s0, $s0, %lo(vs_mainMenu_equipmentStats)
    /* 29C 80102A9C 21200002 */  addu       $a0, $s0, $zero
    /* 2A0 80102AA0 F4002526 */  addiu      $a1, $s1, 0xF4
    /* 2A4 80102AA4 7800030C */  jal        vs_battle_memcpy
    /* 2A8 80102AA8 40000624 */   addiu     $a2, $zero, 0x40
    /* 2AC 80102AAC 60000426 */  addiu      $a0, $s0, 0x60
    /* 2B0 80102AB0 44012526 */  addiu      $a1, $s1, 0x144
    /* 2B4 80102AB4 7800030C */  jal        vs_battle_memcpy
    /* 2B8 80102AB8 20000624 */   addiu     $a2, $zero, 0x20
    /* 2BC 80102ABC 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 2C0 80102AC0 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 2C4 80102AC4 21200000 */  addu       $a0, $zero, $zero
    /* 2C8 80102AC8 3C00428C */  lw         $v0, 0x3C($v0)
    /* 2CC 80102ACC 40000524 */  addiu      $a1, $zero, 0x40
    /* 2D0 80102AD0 D4014224 */  addiu      $v0, $v0, 0x1D4
    /* 2D4 80102AD4 26102202 */  xor        $v0, $s1, $v0
    /* 2D8 80102AD8 0100422C */  sltiu      $v0, $v0, 0x1
    /* 2DC 80102ADC 7E0002A6 */  sh         $v0, 0x7E($s0)
  .L80102AE0:
    /* 2E0 80102AE0 2118B000 */  addu       $v1, $a1, $s0
    /* 2E4 80102AE4 21102402 */  addu       $v0, $s1, $a0
    /* 2E8 80102AE8 F0004290 */  lbu        $v0, 0xF0($v0)
    /* 2EC 80102AEC 01008424 */  addiu      $a0, $a0, 0x1
    /* 2F0 80102AF0 000062A4 */  sh         $v0, 0x0($v1)
    /* 2F4 80102AF4 04008228 */  slti       $v0, $a0, 0x4
    /* 2F8 80102AF8 F9FF4014 */  bnez       $v0, .L80102AE0
    /* 2FC 80102AFC 0200A524 */   addiu     $a1, $a1, 0x2
    /* 300 80102B00 E0002496 */  lhu        $a0, 0xE0($s1)
    /* 304 80102B04 E2002596 */  lhu        $a1, 0xE2($s1)
    /* 308 80102B08 DC002696 */  lhu        $a2, 0xDC($s1)
    /* 30C 80102B0C DE002796 */  lhu        $a3, 0xDE($s1)
    /* 310 80102B10 82F0030C */  jal        vs_mainMenu_setDpPp
    /* 314 80102B14 00000000 */   nop
    /* 318 80102B18 E4002486 */  lh         $a0, 0xE4($s1)
    /* 31C 80102B1C E8002586 */  lh         $a1, 0xE8($s1)
    /* 320 80102B20 EC002686 */  lh         $a2, 0xEC($s1)
    /* 324 80102B24 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 328 80102B28 01000724 */   addiu     $a3, $zero, 0x1
    /* 32C 80102B2C 1080033C */  lui        $v1, %hi(vs_mainMenu_strIntAgi)
    /* 330 80102B30 E6002296 */  lhu        $v0, 0xE6($s1)
    /* 334 80102B34 A8246324 */  addiu      $v1, $v1, %lo(vs_mainMenu_strIntAgi)
    /* 338 80102B38 080062A4 */  sh         $v0, 0x8($v1)
    /* 33C 80102B3C EA002296 */  lhu        $v0, 0xEA($s1)
    /* 340 80102B40 00000000 */  nop
    /* 344 80102B44 0A0062A4 */  sh         $v0, 0xA($v1)
    /* 348 80102B48 EE002296 */  lhu        $v0, 0xEE($s1)
    /* 34C 80102B4C 00000000 */  nop
    /* 350 80102B50 0C0062A4 */  sh         $v0, 0xC($v1)
  .L80102B54:
    /* 354 80102B54 E3EE030C */  jal        func_800FBB8C
    /* 358 80102B58 07000424 */   addiu     $a0, $zero, 0x7
    /* 35C 80102B5C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 360 80102B60 1400B18F */  lw         $s1, 0x14($sp)
    /* 364 80102B64 1000B08F */  lw         $s0, 0x10($sp)
    /* 368 80102B68 0800E003 */  jr         $ra
    /* 36C 80102B6C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80102A64
