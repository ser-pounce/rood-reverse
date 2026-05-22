nonmatching func_80013588, 0x50

glabel func_80013588
    /* 3D88 80013588 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3D8C 8001358C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3D90 80013590 21808000 */  addu       $s0, $a0, $zero
    /* 3D94 80013594 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3D98 80013598 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3D9C 8001359C 1A4D000C */  jal        Sound_IsNotAkaoFile
    /* 3DA0 800135A0 2188A000 */   addu      $s1, $a1, $zero
    /* 3DA4 800135A4 07004014 */  bnez       $v0, .L800135C4
    /* 3DA8 800135A8 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 3DAC 800135AC 21200002 */  addu       $a0, $s0, $zero
    /* 3DB0 800135B0 1800868C */  lw         $a2, 0x18($a0)
    /* 3DB4 800135B4 1000878C */  lw         $a3, 0x10($a0)
    /* 3DB8 800135B8 764D000C */  jal        func_800135D8
    /* 3DBC 800135BC 21282002 */   addu      $a1, $s1, $zero
    /* 3DC0 800135C0 21100000 */  addu       $v0, $zero, $zero
  .L800135C4:
    /* 3DC4 800135C4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3DC8 800135C8 1400B18F */  lw         $s1, 0x14($sp)
    /* 3DCC 800135CC 1000B08F */  lw         $s0, 0x10($sp)
    /* 3DD0 800135D0 0800E003 */  jr         $ra
    /* 3DD4 800135D4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80013588
