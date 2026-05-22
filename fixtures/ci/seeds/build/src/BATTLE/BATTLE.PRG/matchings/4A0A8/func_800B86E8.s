nonmatching func_800B86E8, 0x20

glabel func_800B86E8
    /* 4FEE8 800B86E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4FEEC 800B86EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4FEF0 800B86F0 2BF3010C */  jal        func_8007CCAC
    /* 4FEF4 800B86F4 00000000 */   nop
    /* 4FEF8 800B86F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4FEFC 800B86FC 2A100200 */  slt        $v0, $zero, $v0
    /* 4FF00 800B8700 0800E003 */  jr         $ra
    /* 4FF04 800B8704 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B86E8
