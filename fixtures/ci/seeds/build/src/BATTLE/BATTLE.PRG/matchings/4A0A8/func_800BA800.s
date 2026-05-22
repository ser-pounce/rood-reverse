nonmatching func_800BA800, 0x48

glabel func_800BA800
    /* 52000 800BA800 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52004 800BA804 21388000 */  addu       $a3, $a0, $zero
    /* 52008 800BA808 0F80033C */  lui        $v1, %hi(D_800E9B34)
    /* 5200C 800BA80C 349B6324 */  addiu      $v1, $v1, %lo(D_800E9B34)
    /* 52010 800BA810 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52014 800BA814 0100E290 */  lbu        $v0, 0x1($a3)
    /* 52018 800BA818 0200E590 */  lbu        $a1, 0x2($a3)
    /* 5201C 800BA81C 0300E680 */  lb         $a2, 0x3($a3)
    /* 52020 800BA820 0400E790 */  lbu        $a3, 0x4($a3)
    /* 52024 800BA824 80100200 */  sll        $v0, $v0, 2
    /* 52028 800BA828 21104300 */  addu       $v0, $v0, $v1
    /* 5202C 800BA82C 0000448C */  lw         $a0, 0x0($v0)
    /* 52030 800BA830 1D17010C */  jal        func_80045C74
    /* 52034 800BA834 00000000 */   nop
    /* 52038 800BA838 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5203C 800BA83C 21100000 */  addu       $v0, $zero, $zero
    /* 52040 800BA840 0800E003 */  jr         $ra
    /* 52044 800BA844 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA800
