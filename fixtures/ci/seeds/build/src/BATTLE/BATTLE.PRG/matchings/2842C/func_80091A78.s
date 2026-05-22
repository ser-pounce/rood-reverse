nonmatching func_80091A78, 0x48

glabel func_80091A78
    /* 29278 80091A78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2927C 80091A7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 29280 80091A80 1400BFAF */  sw         $ra, 0x14($sp)
    /* 29284 80091A84 5746020C */  jal        func_8009195C
    /* 29288 80091A88 2180A000 */   addu      $s0, $a1, $zero
    /* 2928C 80091A8C 21204000 */  addu       $a0, $v0, $zero
    /* 29290 80091A90 03008014 */  bnez       $a0, .L80091AA0
    /* 29294 80091A94 01000224 */   addiu     $v0, $zero, 0x1
    /* 29298 80091A98 AC460208 */  j          .L80091AB0
    /* 2929C 80091A9C 21100000 */   addu      $v0, $zero, $zero
  .L80091AA0:
    /* 292A0 80091AA0 02008394 */  lhu        $v1, 0x2($a0)
    /* 292A4 80091AA4 00000000 */  nop
    /* 292A8 80091AA8 21187000 */  addu       $v1, $v1, $s0
    /* 292AC 80091AAC 020083A4 */  sh         $v1, 0x2($a0)
  .L80091AB0:
    /* 292B0 80091AB0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 292B4 80091AB4 1000B08F */  lw         $s0, 0x10($sp)
    /* 292B8 80091AB8 0800E003 */  jr         $ra
    /* 292BC 80091ABC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80091A78
