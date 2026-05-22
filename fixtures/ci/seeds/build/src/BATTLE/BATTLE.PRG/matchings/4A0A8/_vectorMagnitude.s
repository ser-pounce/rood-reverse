nonmatching _vectorMagnitude, 0x78

glabel _vectorMagnitude
    /* 55F40 800BE740 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 55F44 800BE744 21288000 */  addu       $a1, $a0, $zero
    /* 55F48 800BE748 2000BFAF */  sw         $ra, 0x20($sp)
    /* 55F4C 800BE74C C7F9020C */  jal        _copyVector
    /* 55F50 800BE750 1000A427 */   addiu     $a0, $sp, 0x10
    /* 55F54 800BE754 1000A48F */  lw         $a0, 0x10($sp)
    /* 55F58 800BE758 00000000 */  nop
    /* 55F5C 800BE75C 03230400 */  sra        $a0, $a0, 12
    /* 55F60 800BE760 18008400 */  mult       $a0, $a0
    /* 55F64 800BE764 1400A38F */  lw         $v1, 0x14($sp)
    /* 55F68 800BE768 12300000 */  mflo       $a2
    /* 55F6C 800BE76C 031B0300 */  sra        $v1, $v1, 12
    /* 55F70 800BE770 00000000 */  nop
    /* 55F74 800BE774 18006300 */  mult       $v1, $v1
    /* 55F78 800BE778 1800A28F */  lw         $v0, 0x18($sp)
    /* 55F7C 800BE77C 12280000 */  mflo       $a1
    /* 55F80 800BE780 03130200 */  sra        $v0, $v0, 12
    /* 55F84 800BE784 00000000 */  nop
    /* 55F88 800BE788 18004200 */  mult       $v0, $v0
    /* 55F8C 800BE78C 1000A4AF */  sw         $a0, 0x10($sp)
    /* 55F90 800BE790 1400A3AF */  sw         $v1, 0x14($sp)
    /* 55F94 800BE794 1800A2AF */  sw         $v0, 0x18($sp)
    /* 55F98 800BE798 2120C500 */  addu       $a0, $a2, $a1
    /* 55F9C 800BE79C 12400000 */  mflo       $t0
    /* 55FA0 800BE7A0 E506010C */  jal        vs_gte_rsqrt
    /* 55FA4 800BE7A4 21208800 */   addu      $a0, $a0, $t0
    /* 55FA8 800BE7A8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 55FAC 800BE7AC 00130200 */  sll        $v0, $v0, 12
    /* 55FB0 800BE7B0 0800E003 */  jr         $ra
    /* 55FB4 800BE7B4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _vectorMagnitude
