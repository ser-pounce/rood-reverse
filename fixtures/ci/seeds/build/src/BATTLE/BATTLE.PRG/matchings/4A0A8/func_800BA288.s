nonmatching func_800BA288, 0x2C

glabel func_800BA288
    /* 51A88 800BA288 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51A8C 800BA28C 21108000 */  addu       $v0, $a0, $zero
    /* 51A90 800BA290 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51A94 800BA294 01004490 */  lbu        $a0, 0x1($v0)
    /* 51A98 800BA298 02004580 */  lb         $a1, 0x2($v0)
    /* 51A9C 800BA29C 9E46020C */  jal        func_80091A78
    /* 51AA0 800BA2A0 00000000 */   nop
    /* 51AA4 800BA2A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51AA8 800BA2A8 21100000 */  addu       $v0, $zero, $zero
    /* 51AAC 800BA2AC 0800E003 */  jr         $ra
    /* 51AB0 800BA2B0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA288
