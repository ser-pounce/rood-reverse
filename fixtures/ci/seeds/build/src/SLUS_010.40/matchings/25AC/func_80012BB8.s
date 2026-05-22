nonmatching func_80012BB8, 0x4C

glabel func_80012BB8
    /* 33B8 80012BB8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 33BC 80012BBC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 33C0 80012BC0 21808000 */  addu       $s0, $a0, $zero
    /* 33C4 80012BC4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 33C8 80012BC8 2188A000 */  addu       $s1, $a1, $zero
    /* 33CC 80012BCC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 33D0 80012BD0 01001224 */  addiu      $s2, $zero, 0x1
    /* 33D4 80012BD4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 33D8 80012BD8 21200002 */  addu       $a0, $s0, $zero
  .L80012BDC:
    /* 33DC 80012BDC 624D000C */  jal        func_80013588
    /* 33E0 80012BE0 21282002 */   addu      $a1, $s1, $zero
    /* 33E4 80012BE4 FDFF5210 */  beq        $v0, $s2, .L80012BDC
    /* 33E8 80012BE8 21200002 */   addu      $a0, $s0, $zero
    /* 33EC 80012BEC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 33F0 80012BF0 1800B28F */  lw         $s2, 0x18($sp)
    /* 33F4 80012BF4 1400B18F */  lw         $s1, 0x14($sp)
    /* 33F8 80012BF8 1000B08F */  lw         $s0, 0x10($sp)
    /* 33FC 80012BFC 0800E003 */  jr         $ra
    /* 3400 80012C00 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80012BB8
