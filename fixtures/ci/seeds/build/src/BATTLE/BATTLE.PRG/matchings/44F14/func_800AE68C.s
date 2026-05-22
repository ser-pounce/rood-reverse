nonmatching func_800AE68C, 0x34

glabel func_800AE68C
    /* 45E8C 800AE68C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 45E90 800AE690 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 45E94 800AE694 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 45E98 800AE698 80200400 */  sll        $a0, $a0, 2
    /* 45E9C 800AE69C 21208200 */  addu       $a0, $a0, $v0
    /* 45EA0 800AE6A0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 45EA4 800AE6A4 0000848C */  lw         $a0, 0x0($a0)
    /* 45EA8 800AE6A8 3FB9020C */  jal        func_800AE4FC
    /* 45EAC 800AE6AC 0400A524 */   addiu     $a1, $a1, 0x4
    /* 45EB0 800AE6B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 45EB4 800AE6B4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 45EB8 800AE6B8 0800E003 */  jr         $ra
    /* 45EBC 800AE6BC 00000000 */   nop
endlabel func_800AE68C
