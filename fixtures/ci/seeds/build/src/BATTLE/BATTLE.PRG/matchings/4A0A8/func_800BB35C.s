nonmatching func_800BB35C, 0x30

glabel func_800BB35C
    /* 52B5C 800BB35C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52B60 800BB360 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52B64 800BB364 01008490 */  lbu        $a0, 0x1($a0)
    /* 52B68 800BB368 00000000 */  nop
    /* 52B6C 800BB36C 02008530 */  andi       $a1, $a0, 0x2
    /* 52B70 800BB370 01008430 */  andi       $a0, $a0, 0x1
    /* 52B74 800BB374 DBF8020C */  jal        func_800BE36C
    /* 52B78 800BB378 2B280500 */   sltu      $a1, $zero, $a1
    /* 52B7C 800BB37C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52B80 800BB380 21100000 */  addu       $v0, $zero, $zero
    /* 52B84 800BB384 0800E003 */  jr         $ra
    /* 52B88 800BB388 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB35C
