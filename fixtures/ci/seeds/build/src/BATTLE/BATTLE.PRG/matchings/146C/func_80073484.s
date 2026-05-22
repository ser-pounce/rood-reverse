nonmatching func_80073484, 0x3C

glabel func_80073484
    /* AC84 80073484 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* AC88 80073488 1000BFAF */  sw         $ra, 0x10($sp)
    /* AC8C 8007348C 73BD010C */  jal        func_8006F5CC
    /* AC90 80073490 00000000 */   nop
    /* AC94 80073494 0680033C */  lui        $v1, %hi(vs_gametime_tickspeed)
    /* AC98 80073498 02000224 */  addiu      $v0, $zero, 0x2
    /* AC9C 8007349C 21200000 */  addu       $a0, $zero, $zero
    /* ACA0 800734A0 952D030C */  jal        func_800CB654
    /* ACA4 800734A4 4CE262AC */   sw        $v0, %lo(vs_gametime_tickspeed)($v1)
    /* ACA8 800734A8 322D020C */  jal        func_8008B4C8
    /* ACAC 800734AC 01000424 */   addiu     $a0, $zero, 0x1
    /* ACB0 800734B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* ACB4 800734B4 00000000 */  nop
    /* ACB8 800734B8 0800E003 */  jr         $ra
    /* ACBC 800734BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80073484
