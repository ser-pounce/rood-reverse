nonmatching func_800B9230, 0x24

glabel func_800B9230
    /* 50A30 800B9230 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50A34 800B9234 1000BFAF */  sw         $ra, 0x10($sp)
    /* 50A38 800B9238 01008490 */  lbu        $a0, 0x1($a0)
    /* 50A3C 800B923C 57F4010C */  jal        func_8007D15C
    /* 50A40 800B9240 00000000 */   nop
    /* 50A44 800B9244 1000BF8F */  lw         $ra, 0x10($sp)
    /* 50A48 800B9248 21100000 */  addu       $v0, $zero, $zero
    /* 50A4C 800B924C 0800E003 */  jr         $ra
    /* 50A50 800B9250 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9230
