nonmatching func_80077EC4, 0x50

glabel func_80077EC4
    /* F6C4 80077EC4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* F6C8 80077EC8 1000B0AF */  sw         $s0, 0x10($sp)
    /* F6CC 80077ECC 801F103C */  lui        $s0, %hi(D_1F800034)
    /* F6D0 80077ED0 34001026 */  addiu      $s0, $s0, %lo(D_1F800034)
    /* F6D4 80077ED4 21200002 */  addu       $a0, $s0, $zero
    /* F6D8 80077ED8 10000526 */  addiu      $a1, $s0, 0x10
    /* F6DC 80077EDC FFFF0624 */  addiu      $a2, $zero, -0x1
    /* F6E0 80077EE0 1400BFAF */  sw         $ra, 0x14($sp)
    /* F6E4 80077EE4 5CF3010C */  jal        vs_battle_initialiseCameraFromSpherical
    /* F6E8 80077EE8 2138C000 */   addu      $a3, $a2, $zero
    /* F6EC 80077EEC CCFF1026 */  addiu      $s0, $s0, -0x34
    /* F6F0 80077EF0 00100224 */  addiu      $v0, $zero, 0x1000
    /* F6F4 80077EF4 640002AE */  sw         $v0, 0x64($s0)
    /* F6F8 80077EF8 5C0000AE */  sw         $zero, 0x5C($s0)
    /* F6FC 80077EFC 580000AE */  sw         $zero, 0x58($s0)
    /* F700 80077F00 540000AE */  sw         $zero, 0x54($s0)
    /* F704 80077F04 1400BF8F */  lw         $ra, 0x14($sp)
    /* F708 80077F08 1000B08F */  lw         $s0, 0x10($sp)
    /* F70C 80077F0C 0800E003 */  jr         $ra
    /* F710 80077F10 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80077EC4
