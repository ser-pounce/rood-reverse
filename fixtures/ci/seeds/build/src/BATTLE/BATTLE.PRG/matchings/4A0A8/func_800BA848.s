nonmatching func_800BA848, 0x48

glabel func_800BA848
    /* 52048 800BA848 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5204C 800BA84C 21388000 */  addu       $a3, $a0, $zero
    /* 52050 800BA850 0F80033C */  lui        $v1, %hi(D_800E9B34)
    /* 52054 800BA854 349B6324 */  addiu      $v1, $v1, %lo(D_800E9B34)
    /* 52058 800BA858 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5205C 800BA85C 0100E290 */  lbu        $v0, 0x1($a3)
    /* 52060 800BA860 0200E590 */  lbu        $a1, 0x2($a3)
    /* 52064 800BA864 0300E690 */  lbu        $a2, 0x3($a3)
    /* 52068 800BA868 0400E790 */  lbu        $a3, 0x4($a3)
    /* 5206C 800BA86C 80100200 */  sll        $v0, $v0, 2
    /* 52070 800BA870 21104300 */  addu       $v0, $v0, $v1
    /* 52074 800BA874 0000448C */  lw         $a0, 0x0($v0)
    /* 52078 800BA878 3B17010C */  jal        func_80045CEC
    /* 5207C 800BA87C 00000000 */   nop
    /* 52080 800BA880 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52084 800BA884 21100000 */  addu       $v0, $zero, $zero
    /* 52088 800BA888 0800E003 */  jr         $ra
    /* 5208C 800BA88C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA848
