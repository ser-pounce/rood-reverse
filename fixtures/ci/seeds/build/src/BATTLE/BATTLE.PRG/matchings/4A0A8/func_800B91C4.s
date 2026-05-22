nonmatching func_800B91C4, 0x2C

glabel func_800B91C4
    /* 509C4 800B91C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 509C8 800B91C8 21108000 */  addu       $v0, $a0, $zero
    /* 509CC 800B91CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 509D0 800B91D0 02004490 */  lbu        $a0, 0x2($v0)
    /* 509D4 800B91D4 01004590 */  lbu        $a1, 0x1($v0)
    /* 509D8 800B91D8 EEEE010C */  jal        func_8007BBB8
    /* 509DC 800B91DC 00000000 */   nop
    /* 509E0 800B91E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 509E4 800B91E4 21100000 */  addu       $v0, $zero, $zero
    /* 509E8 800B91E8 0800E003 */  jr         $ra
    /* 509EC 800B91EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B91C4
