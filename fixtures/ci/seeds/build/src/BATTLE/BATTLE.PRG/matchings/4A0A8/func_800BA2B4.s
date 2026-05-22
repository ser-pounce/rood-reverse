nonmatching func_800BA2B4, 0x2C

glabel func_800BA2B4
    /* 51AB4 800BA2B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51AB8 800BA2B8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51ABC 800BA2BC 01008280 */  lb         $v0, 0x1($a0)
    /* 51AC0 800BA2C0 02008580 */  lb         $a1, 0x2($a0)
    /* 51AC4 800BA2C4 C0210200 */  sll        $a0, $v0, 7
    /* 51AC8 800BA2C8 B93A020C */  jal        func_8008EAE4
    /* 51ACC 800BA2CC C0290500 */   sll       $a1, $a1, 7
    /* 51AD0 800BA2D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51AD4 800BA2D4 21100000 */  addu       $v0, $zero, $zero
    /* 51AD8 800BA2D8 0800E003 */  jr         $ra
    /* 51ADC 800BA2DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA2B4
