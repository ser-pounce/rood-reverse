nonmatching _freeSfxSlots, 0x4C

glabel _freeSfxSlots
    /* 367EC 80045FEC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 367F0 80045FF0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 367F4 80045FF4 21880000 */  addu       $s1, $zero, $zero
    /* 367F8 80045FF8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 367FC 80045FFC 21802002 */  addu       $s0, $s1, $zero
    /* 36800 80046000 1800BFAF */  sw         $ra, 0x18($sp)
    /* 36804 80046004 01001026 */  addiu      $s0, $s0, 0x1
  .L80046008:
    /* 36808 80046008 D917010C */  jal        vs_main_freeSfxQueueSlot
    /* 3680C 8004600C 21200002 */   addu      $a0, $s0, $zero
    /* 36810 80046010 25882202 */  or         $s1, $s1, $v0
    /* 36814 80046014 0300022A */  slti       $v0, $s0, 0x3
    /* 36818 80046018 FBFF4014 */  bnez       $v0, .L80046008
    /* 3681C 8004601C 01001026 */   addiu     $s0, $s0, 0x1
    /* 36820 80046020 21102002 */  addu       $v0, $s1, $zero
    /* 36824 80046024 1800BF8F */  lw         $ra, 0x18($sp)
    /* 36828 80046028 1400B18F */  lw         $s1, 0x14($sp)
    /* 3682C 8004602C 1000B08F */  lw         $s0, 0x10($sp)
    /* 36830 80046030 0800E003 */  jr         $ra
    /* 36834 80046034 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _freeSfxSlots
