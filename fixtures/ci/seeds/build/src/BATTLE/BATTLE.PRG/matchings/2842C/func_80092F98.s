nonmatching func_80092F98, 0x24

glabel func_80092F98
    /* 2A798 80092F98 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A79C 80092F9C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2A7A0 80092FA0 0400A48C */  lw         $a0, 0x4($a1)
    /* 2A7A4 80092FA4 6646020C */  jal        func_80091998
    /* 2A7A8 80092FA8 00000000 */   nop
    /* 2A7AC 80092FAC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2A7B0 80092FB0 21100000 */  addu       $v0, $zero, $zero
    /* 2A7B4 80092FB4 0800E003 */  jr         $ra
    /* 2A7B8 80092FB8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80092F98
