nonmatching func_800719DC, 0x20

glabel func_800719DC
    /* 91DC 800719DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 91E0 800719E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 91E4 800719E4 CAC3010C */  jal        func_80070F28
    /* 91E8 800719E8 21200000 */   addu      $a0, $zero, $zero
    /* 91EC 800719EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 91F0 800719F0 00000000 */  nop
    /* 91F4 800719F4 0800E003 */  jr         $ra
    /* 91F8 800719F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800719DC
