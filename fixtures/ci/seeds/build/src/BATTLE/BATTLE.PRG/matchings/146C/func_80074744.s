nonmatching func_80074744, 0x54

glabel func_80074744
    /* BF44 80074744 0680023C */  lui        $v0, %hi(vs_main_projectionDistance)
    /* BF48 80074748 48E2428C */  lw         $v0, %lo(vs_main_projectionDistance)($v0)
    /* BF4C 8007474C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BF50 80074750 11014228 */  slti       $v0, $v0, 0x111
    /* BF54 80074754 06004014 */  bnez       $v0, .L80074770
    /* BF58 80074758 1000BFAF */   sw        $ra, 0x10($sp)
    /* BF5C 8007475C F882020C */  jal        func_800A0BE0
    /* BF60 80074760 21200000 */   addu      $a0, $zero, $zero
    /* BF64 80074764 21200000 */  addu       $a0, $zero, $zero
    /* BF68 80074768 1F82020C */  jal        func_800A087C
    /* BF6C 8007476C 02004534 */   ori       $a1, $v0, 0x2
  .L80074770:
    /* BF70 80074770 81BC010C */  jal        _stepCameraTransition
    /* BF74 80074774 00000000 */   nop
    /* BF78 80074778 03004010 */  beqz       $v0, .L80074788
    /* BF7C 8007477C 00000000 */   nop
    /* BF80 80074780 ABCC010C */  jal        _endBattleCameraTransition
    /* BF84 80074784 00000000 */   nop
  .L80074788:
    /* BF88 80074788 1000BF8F */  lw         $ra, 0x10($sp)
    /* BF8C 8007478C 00000000 */  nop
    /* BF90 80074790 0800E003 */  jr         $ra
    /* BF94 80074794 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80074744
