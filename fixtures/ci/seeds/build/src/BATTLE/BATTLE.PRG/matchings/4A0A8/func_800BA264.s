nonmatching func_800BA264, 0x24

glabel func_800BA264
    /* 51A64 800BA264 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51A68 800BA268 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51A6C 800BA26C 01008490 */  lbu        $a0, 0x1($a0)
    /* 51A70 800BA270 76EF010C */  jal        func_8007BDD8
    /* 51A74 800BA274 2B200400 */   sltu      $a0, $zero, $a0
    /* 51A78 800BA278 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51A7C 800BA27C 21100000 */  addu       $v0, $zero, $zero
    /* 51A80 800BA280 0800E003 */  jr         $ra
    /* 51A84 800BA284 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA264
