nonmatching _loadAndFreeSfx, 0x4C

glabel _loadAndFreeSfx
    /* 36838 80046038 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3683C 8004603C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 36840 80046040 C317010C */  jal        _loadSfx
    /* 36844 80046044 1000B0AF */   sw        $s0, 0x10($sp)
    /* 36848 80046048 21804000 */  addu       $s0, $v0, $zero
    /* 3684C 8004604C 09000012 */  beqz       $s0, .L80046074
    /* 36850 80046050 21100002 */   addu      $v0, $s0, $zero
  .L80046054:
    /* 36854 80046054 FB17010C */  jal        _freeSfxSlots
    /* 36858 80046058 00000000 */   nop
    /* 3685C 8004605C 05004010 */  beqz       $v0, .L80046074
    /* 36860 80046060 21100002 */   addu      $v0, $s0, $zero
    /* 36864 80046064 8709010C */  jal        vs_main_gametimeUpdate
    /* 36868 80046068 21200000 */   addu      $a0, $zero, $zero
    /* 3686C 8004606C 15180108 */  j          .L80046054
    /* 36870 80046070 00000000 */   nop
  .L80046074:
    /* 36874 80046074 1400BF8F */  lw         $ra, 0x14($sp)
    /* 36878 80046078 1000B08F */  lw         $s0, 0x10($sp)
    /* 3687C 8004607C 0800E003 */  jr         $ra
    /* 36880 80046080 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _loadAndFreeSfx
