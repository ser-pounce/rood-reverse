nonmatching func_80046634, 0x44

glabel func_80046634
    /* 36E34 80046634 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 36E38 80046638 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 36E3C 8004663C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 36E40 80046640 38E05024 */  addiu      $s0, $v0, %lo(vs_main_soundData)
    /* 36E44 80046644 1400BFAF */  sw         $ra, 0x14($sp)
    /* 36E48 80046648 6C00028E */  lw         $v0, 0x6C($s0)
    /* 36E4C 8004664C 00000000 */  nop
    /* 36E50 80046650 05004010 */  beqz       $v0, .L80046668
    /* 36E54 80046654 21100000 */   addu      $v0, $zero, $zero
    /* 36E58 80046658 CA4C000C */  jal        func_80013328
    /* 36E5C 8004665C 00000000 */   nop
    /* 36E60 80046660 6C0000AE */  sw         $zero, 0x6C($s0)
    /* 36E64 80046664 01000224 */  addiu      $v0, $zero, 0x1
  .L80046668:
    /* 36E68 80046668 1400BF8F */  lw         $ra, 0x14($sp)
    /* 36E6C 8004666C 1000B08F */  lw         $s0, 0x10($sp)
    /* 36E70 80046670 0800E003 */  jr         $ra
    /* 36E74 80046674 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80046634
