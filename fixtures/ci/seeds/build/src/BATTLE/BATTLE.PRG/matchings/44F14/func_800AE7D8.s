nonmatching func_800AE7D8, 0x50

glabel func_800AE7D8
    /* 45FD8 800AE7D8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 45FDC 800AE7DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 45FE0 800AE7E0 2188C000 */  addu       $s1, $a2, $zero
    /* 45FE4 800AE7E4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 45FE8 800AE7E8 1C009024 */  addiu      $s0, $a0, 0x1C
    /* 45FEC 800AE7EC 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 45FF0 800AE7F0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 45FF4 800AE7F4 AA16010C */  jal        vs_main_panSfx
    /* 45FF8 800AE7F8 21300002 */   addu      $a2, $s0, $zero
    /* 45FFC 800AE7FC 04002012 */  beqz       $s1, .L800AE810
    /* 46000 800AE800 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 46004 800AE804 21282002 */  addu       $a1, $s1, $zero
    /* 46008 800AE808 AA16010C */  jal        vs_main_panSfx
    /* 4600C 800AE80C 21300002 */   addu      $a2, $s0, $zero
  .L800AE810:
    /* 46010 800AE810 1800BF8F */  lw         $ra, 0x18($sp)
    /* 46014 800AE814 1400B18F */  lw         $s1, 0x14($sp)
    /* 46018 800AE818 1000B08F */  lw         $s0, 0x10($sp)
    /* 4601C 800AE81C 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 46020 800AE820 0800E003 */  jr         $ra
    /* 46024 800AE824 00000000 */   nop
endlabel func_800AE7D8
