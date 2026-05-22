nonmatching func_800BA684, 0x34

glabel func_800BA684
    /* 51E84 800BA684 21188000 */  addu       $v1, $a0, $zero
    /* 51E88 800BA688 0F80023C */  lui        $v0, %hi(D_800F4C69)
    /* 51E8C 800BA68C 694C4490 */  lbu        $a0, %lo(D_800F4C69)($v0)
    /* 51E90 800BA690 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51E94 800BA694 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51E98 800BA698 01006580 */  lb         $a1, 0x1($v1)
    /* 51E9C 800BA69C 02006690 */  lbu        $a2, 0x2($v1)
    /* 51EA0 800BA6A0 6B15010C */  jal        func_800455AC
    /* 51EA4 800BA6A4 00000000 */   nop
    /* 51EA8 800BA6A8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51EAC 800BA6AC 21100000 */  addu       $v0, $zero, $zero
    /* 51EB0 800BA6B0 0800E003 */  jr         $ra
    /* 51EB4 800BA6B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA684
