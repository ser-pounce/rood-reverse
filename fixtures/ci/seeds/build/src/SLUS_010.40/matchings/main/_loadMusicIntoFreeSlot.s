nonmatching _loadMusicIntoFreeSlot, 0x58

glabel _loadMusicIntoFreeSlot
    /* 35A70 80045270 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35A74 80045274 1000BFAF */  sw         $ra, 0x10($sp)
    /* 35A78 80045278 21280000 */  addu       $a1, $zero, $zero
    /* 35A7C 8004527C 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 35A80 80045280 38E04324 */  addiu      $v1, $v0, %lo(vs_main_soundData)
  .L80045284:
    /* 35A84 80045284 2400628C */  lw         $v0, 0x24($v1)
    /* 35A88 80045288 00000000 */  nop
    /* 35A8C 8004528C 05004014 */  bnez       $v0, .L800452A4
    /* 35A90 80045290 00000000 */   nop
    /* 35A94 80045294 4414010C */  jal        vs_main_loadMusicSlot
    /* 35A98 80045298 0100A524 */   addiu     $a1, $a1, 0x1
    /* 35A9C 8004529C AE140108 */  j          .L800452B8
    /* 35AA0 800452A0 00000000 */   nop
  .L800452A4:
    /* 35AA4 800452A4 0100A524 */  addiu      $a1, $a1, 0x1
    /* 35AA8 800452A8 0400A228 */  slti       $v0, $a1, 0x4
    /* 35AAC 800452AC F5FF4014 */  bnez       $v0, .L80045284
    /* 35AB0 800452B0 04006324 */   addiu     $v1, $v1, 0x4
    /* 35AB4 800452B4 21100000 */  addu       $v0, $zero, $zero
  .L800452B8:
    /* 35AB8 800452B8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 35ABC 800452BC 00000000 */  nop
    /* 35AC0 800452C0 0800E003 */  jr         $ra
    /* 35AC4 800452C4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _loadMusicIntoFreeSlot
