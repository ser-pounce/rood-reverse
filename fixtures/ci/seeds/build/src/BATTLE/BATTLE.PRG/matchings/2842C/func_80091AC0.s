nonmatching func_80091AC0, 0x44

glabel func_80091AC0
    /* 292C0 80091AC0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 292C4 80091AC4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 292C8 80091AC8 5746020C */  jal        func_8009195C
    /* 292CC 80091ACC 00000000 */   nop
    /* 292D0 80091AD0 21204000 */  addu       $a0, $v0, $zero
    /* 292D4 80091AD4 03008014 */  bnez       $a0, .L80091AE4
    /* 292D8 80091AD8 01000224 */   addiu     $v0, $zero, 0x1
    /* 292DC 80091ADC BD460208 */  j          .L80091AF4
    /* 292E0 80091AE0 21100000 */   addu      $v0, $zero, $zero
  .L80091AE4:
    /* 292E4 80091AE4 0000838C */  lw         $v1, 0x0($a0)
    /* 292E8 80091AE8 00000000 */  nop
    /* 292EC 80091AEC 00106334 */  ori        $v1, $v1, 0x1000
    /* 292F0 80091AF0 000083AC */  sw         $v1, 0x0($a0)
  .L80091AF4:
    /* 292F4 80091AF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 292F8 80091AF8 00000000 */  nop
    /* 292FC 80091AFC 0800E003 */  jr         $ra
    /* 29300 80091B00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80091AC0
