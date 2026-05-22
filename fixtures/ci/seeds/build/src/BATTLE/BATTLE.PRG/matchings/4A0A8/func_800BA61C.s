nonmatching func_800BA61C, 0x34

glabel func_800BA61C
    /* 51E1C 800BA61C 21188000 */  addu       $v1, $a0, $zero
    /* 51E20 800BA620 0F80023C */  lui        $v0, %hi(D_800F4C69)
    /* 51E24 800BA624 694C4490 */  lbu        $a0, %lo(D_800F4C69)($v0)
    /* 51E28 800BA628 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51E2C 800BA62C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51E30 800BA630 01006590 */  lbu        $a1, 0x1($v1)
    /* 51E34 800BA634 02006690 */  lbu        $a2, 0x2($v1)
    /* 51E38 800BA638 4B15010C */  jal        func_8004552C
    /* 51E3C 800BA63C 00000000 */   nop
    /* 51E40 800BA640 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51E44 800BA644 21100000 */  addu       $v0, $zero, $zero
    /* 51E48 800BA648 0800E003 */  jr         $ra
    /* 51E4C 800BA64C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA61C
