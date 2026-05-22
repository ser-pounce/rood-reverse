nonmatching func_800CFE98, 0x58

glabel func_800CFE98
    /* 67698 800CFE98 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6769C 800CFE9C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 676A0 800CFEA0 21888000 */  addu       $s1, $a0, $zero
    /* 676A4 800CFEA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 676A8 800CFEA8 2180A000 */  addu       $s0, $a1, $zero
    /* 676AC 800CFEAC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 676B0 800CFEB0 9F3F030C */  jal        func_800CFE7C
    /* 676B4 800CFEB4 21200002 */   addu      $a0, $s0, $zero
    /* 676B8 800CFEB8 00002286 */  lh         $v0, 0x0($s1)
    /* 676BC 800CFEBC 00000000 */  nop
    /* 676C0 800CFEC0 140002AE */  sw         $v0, 0x14($s0)
    /* 676C4 800CFEC4 02002286 */  lh         $v0, 0x2($s1)
    /* 676C8 800CFEC8 00000000 */  nop
    /* 676CC 800CFECC 180002AE */  sw         $v0, 0x18($s0)
    /* 676D0 800CFED0 04002286 */  lh         $v0, 0x4($s1)
    /* 676D4 800CFED4 00000000 */  nop
    /* 676D8 800CFED8 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 676DC 800CFEDC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 676E0 800CFEE0 1400B18F */  lw         $s1, 0x14($sp)
    /* 676E4 800CFEE4 1000B08F */  lw         $s0, 0x10($sp)
    /* 676E8 800CFEE8 0800E003 */  jr         $ra
    /* 676EC 800CFEEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CFE98
