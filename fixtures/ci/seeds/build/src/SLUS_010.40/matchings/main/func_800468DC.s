nonmatching func_800468DC, 0x20

glabel func_800468DC
    /* 370DC 800468DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 370E0 800468E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 370E4 800468E4 464A000C */  jal        func_80012918
    /* 370E8 800468E8 FF7F0424 */   addiu     $a0, $zero, 0x7FFF
    /* 370EC 800468EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 370F0 800468F0 00000000 */  nop
    /* 370F4 800468F4 0800E003 */  jr         $ra
    /* 370F8 800468F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800468DC
