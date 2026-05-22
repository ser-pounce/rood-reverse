nonmatching func_800B9F28, 0x24

glabel func_800B9F28
    /* 51728 800B9F28 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5172C 800B9F2C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51730 800B9F30 01008490 */  lbu        $a0, 0x1($a0)
    /* 51734 800B9F34 BE3A020C */  jal        func_8008EAF8
    /* 51738 800B9F38 00000000 */   nop
    /* 5173C 800B9F3C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51740 800B9F40 21100000 */  addu       $v0, $zero, $zero
    /* 51744 800B9F44 0800E003 */  jr         $ra
    /* 51748 800B9F48 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9F28
