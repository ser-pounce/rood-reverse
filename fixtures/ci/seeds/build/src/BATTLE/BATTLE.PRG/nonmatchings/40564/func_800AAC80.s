nonmatching func_800AAC80, 0x5C

glabel func_800AAC80
    /* 42480 800AAC80 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 42484 800AAC84 21108000 */  addu       $v0, $a0, $zero
    /* 42488 800AAC88 2118A000 */  addu       $v1, $a1, $zero
    /* 4248C 800AAC8C 2138C000 */  addu       $a3, $a2, $zero
    /* 42490 800AAC90 1400B1AF */  sw         $s1, 0x14($sp)
    /* 42494 800AAC94 801F113C */  lui        $s1, (0x1F800000 >> 16)
    /* 42498 800AAC98 21284000 */  addu       $a1, $v0, $zero
    /* 4249C 800AAC9C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 424A0 800AACA0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 424A4 800AACA4 0000308E */  lw         $s0, (0x1F800000 & 0xFFFF)($s1)
    /* 424A8 800AACA8 21306000 */  addu       $a2, $v1, $zero
    /* 424AC 800AACAC ADAD000C */  jal        SetDrawMove
    /* 424B0 800AACB0 21200002 */   addu      $a0, $s0, $zero
    /* 424B4 800AACB4 09EA010C */  jal        func_8007A824
    /* 424B8 800AACB8 21200002 */   addu      $a0, $s0, $zero
    /* 424BC 800AACBC 18001026 */  addiu      $s0, $s0, 0x18
    /* 424C0 800AACC0 000030AE */  sw         $s0, (0x1F800000 & 0xFFFF)($s1)
    /* 424C4 800AACC4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 424C8 800AACC8 1400B18F */  lw         $s1, 0x14($sp)
    /* 424CC 800AACCC 1000B08F */  lw         $s0, 0x10($sp)
    /* 424D0 800AACD0 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 424D4 800AACD4 0800E003 */  jr         $ra
    /* 424D8 800AACD8 00000000 */   nop
endlabel func_800AAC80
