nonmatching func_800A3C00, 0x34

glabel func_800A3C00
    /* 3B400 800A3C00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3B404 800A3C04 21108000 */  addu       $v0, $a0, $zero
    /* 3B408 800A3C08 2138A000 */  addu       $a3, $a1, $zero
    /* 3B40C 800A3C0C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3B410 800A3C10 5C004490 */  lbu        $a0, 0x5C($v0)
    /* 3B414 800A3C14 5E004590 */  lbu        $a1, 0x5E($v0)
    /* 3B418 800A3C18 1E004684 */  lh         $a2, 0x1E($v0)
    /* 3B41C 800A3C1C 0D8F020C */  jal        func_800A3C34
    /* 3B420 800A3C20 00000000 */   nop
    /* 3B424 800A3C24 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3B428 800A3C28 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 3B42C 800A3C2C 0800E003 */  jr         $ra
    /* 3B430 800A3C30 00000000 */   nop
endlabel func_800A3C00
