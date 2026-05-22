nonmatching _loadSfx, 0x58

glabel _loadSfx
    /* 3670C 80045F0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36710 80045F10 1000BFAF */  sw         $ra, 0x10($sp)
    /* 36714 80045F14 21280000 */  addu       $a1, $zero, $zero
    /* 36718 80045F18 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 3671C 80045F1C 38E04324 */  addiu      $v1, $v0, %lo(vs_main_soundData)
  .L80045F20:
    /* 36720 80045F20 4C00628C */  lw         $v0, 0x4C($v1)
    /* 36724 80045F24 00000000 */  nop
    /* 36728 80045F28 05004014 */  bnez       $v0, .L80045F40
    /* 3672C 80045F2C 00000000 */   nop
    /* 36730 80045F30 7817010C */  jal        vs_main_loadSfxSlot
    /* 36734 80045F34 0100A524 */   addiu     $a1, $a1, 0x1
    /* 36738 80045F38 D5170108 */  j          .L80045F54
    /* 3673C 80045F3C 00000000 */   nop
  .L80045F40:
    /* 36740 80045F40 0100A524 */  addiu      $a1, $a1, 0x1
    /* 36744 80045F44 0300A228 */  slti       $v0, $a1, 0x3
    /* 36748 80045F48 F5FF4014 */  bnez       $v0, .L80045F20
    /* 3674C 80045F4C 04006324 */   addiu     $v1, $v1, 0x4
    /* 36750 80045F50 21100000 */  addu       $v0, $zero, $zero
  .L80045F54:
    /* 36754 80045F54 1000BF8F */  lw         $ra, 0x10($sp)
    /* 36758 80045F58 00000000 */  nop
    /* 3675C 80045F5C 0800E003 */  jr         $ra
    /* 36760 80045F60 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _loadSfx
