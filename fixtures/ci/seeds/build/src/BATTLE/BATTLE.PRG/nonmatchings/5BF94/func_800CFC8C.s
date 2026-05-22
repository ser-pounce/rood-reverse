nonmatching func_800CFC8C, 0x64

glabel func_800CFC8C
    /* 6748C 800CFC8C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 67490 800CFC90 1400B1AF */  sw         $s1, 0x14($sp)
    /* 67494 800CFC94 21888000 */  addu       $s1, $a0, $zero
    /* 67498 800CFC98 C0220700 */  sll        $a0, $a3, 11
    /* 6749C 800CFC9C 1A008600 */  div        $zero, $a0, $a2
    /* 674A0 800CFCA0 12200000 */  mflo       $a0
    /* 674A4 800CFCA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 674A8 800CFCA8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 674AC 800CFCAC C903010C */  jal        rcos
    /* 674B0 800CFCB0 2180A000 */   addu      $s0, $a1, $zero
    /* 674B4 800CFCB4 23801102 */  subu       $s0, $s0, $s1
    /* 674B8 800CFCB8 00100324 */  addiu      $v1, $zero, 0x1000
    /* 674BC 800CFCBC 23186200 */  subu       $v1, $v1, $v0
    /* 674C0 800CFCC0 18000302 */  mult       $s0, $v1
    /* 674C4 800CFCC4 12100000 */  mflo       $v0
    /* 674C8 800CFCC8 02004104 */  bgez       $v0, .L800CFCD4
    /* 674CC 800CFCCC 00000000 */   nop
    /* 674D0 800CFCD0 FF1F4224 */  addiu      $v0, $v0, 0x1FFF
  .L800CFCD4:
    /* 674D4 800CFCD4 43130200 */  sra        $v0, $v0, 13
    /* 674D8 800CFCD8 21102202 */  addu       $v0, $s1, $v0
    /* 674DC 800CFCDC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 674E0 800CFCE0 1400B18F */  lw         $s1, 0x14($sp)
    /* 674E4 800CFCE4 1000B08F */  lw         $s0, 0x10($sp)
    /* 674E8 800CFCE8 0800E003 */  jr         $ra
    /* 674EC 800CFCEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CFC8C
