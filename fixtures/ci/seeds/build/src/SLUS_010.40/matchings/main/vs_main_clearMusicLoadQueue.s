nonmatching vs_main_clearMusicLoadQueue, 0x4C

glabel vs_main_clearMusicLoadQueue
    /* 35B50 80045350 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 35B54 80045354 1400B1AF */  sw         $s1, 0x14($sp)
    /* 35B58 80045358 21880000 */  addu       $s1, $zero, $zero
    /* 35B5C 8004535C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 35B60 80045360 21802002 */  addu       $s0, $s1, $zero
    /* 35B64 80045364 1800BFAF */  sw         $ra, 0x18($sp)
    /* 35B68 80045368 01001026 */  addiu      $s0, $s0, 0x1
  .L8004536C:
    /* 35B6C 8004536C B214010C */  jal        vs_main_clearMusicLoadSlot
    /* 35B70 80045370 21200002 */   addu      $a0, $s0, $zero
    /* 35B74 80045374 25882202 */  or         $s1, $s1, $v0
    /* 35B78 80045378 0400022A */  slti       $v0, $s0, 0x4
    /* 35B7C 8004537C FBFF4014 */  bnez       $v0, .L8004536C
    /* 35B80 80045380 01001026 */   addiu     $s0, $s0, 0x1
    /* 35B84 80045384 21102002 */  addu       $v0, $s1, $zero
    /* 35B88 80045388 1800BF8F */  lw         $ra, 0x18($sp)
    /* 35B8C 8004538C 1400B18F */  lw         $s1, 0x14($sp)
    /* 35B90 80045390 1000B08F */  lw         $s0, 0x10($sp)
    /* 35B94 80045394 0800E003 */  jr         $ra
    /* 35B98 80045398 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_main_clearMusicLoadQueue
