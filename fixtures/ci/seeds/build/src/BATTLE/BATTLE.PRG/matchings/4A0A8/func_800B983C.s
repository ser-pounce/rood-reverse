nonmatching func_800B983C, 0x24

glabel func_800B983C
    /* 5103C 800B983C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51040 800B9840 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51044 800B9844 01008490 */  lbu        $a0, 0x1($a0)
    /* 51048 800B9848 7646020C */  jal        func_800919D8
    /* 5104C 800B984C 00000000 */   nop
    /* 51050 800B9850 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51054 800B9854 21100000 */  addu       $v0, $zero, $zero
    /* 51058 800B9858 0800E003 */  jr         $ra
    /* 5105C 800B985C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B983C
