nonmatching func_800BA404, 0x40

glabel func_800BA404
    /* 51C04 800BA404 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51C08 800BA408 21288000 */  addu       $a1, $a0, $zero
    /* 51C0C 800BA40C 0F80033C */  lui        $v1, %hi(D_800E9B34)
    /* 51C10 800BA410 349B6324 */  addiu      $v1, $v1, %lo(D_800E9B34)
    /* 51C14 800BA414 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51C18 800BA418 0100A290 */  lbu        $v0, 0x1($a1)
    /* 51C1C 800BA41C 0200A590 */  lbu        $a1, 0x2($a1)
    /* 51C20 800BA420 80100200 */  sll        $v0, $v0, 2
    /* 51C24 800BA424 21104300 */  addu       $v0, $v0, $v1
    /* 51C28 800BA428 0000448C */  lw         $a0, 0x0($v0)
    /* 51C2C 800BA42C 5917010C */  jal        func_80045D64
    /* 51C30 800BA430 00000000 */   nop
    /* 51C34 800BA434 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51C38 800BA438 21100000 */  addu       $v0, $zero, $zero
    /* 51C3C 800BA43C 0800E003 */  jr         $ra
    /* 51C40 800BA440 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA404
