nonmatching func_800B92D0, 0x24

glabel func_800B92D0
    /* 50AD0 800B92D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50AD4 800B92D4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 50AD8 800B92D8 01008490 */  lbu        $a0, 0x1($a0)
    /* 50ADC 800B92DC 63EF010C */  jal        func_8007BD8C
    /* 50AE0 800B92E0 01008438 */   xori      $a0, $a0, 0x1
    /* 50AE4 800B92E4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 50AE8 800B92E8 21100000 */  addu       $v0, $zero, $zero
    /* 50AEC 800B92EC 0800E003 */  jr         $ra
    /* 50AF0 800B92F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B92D0
