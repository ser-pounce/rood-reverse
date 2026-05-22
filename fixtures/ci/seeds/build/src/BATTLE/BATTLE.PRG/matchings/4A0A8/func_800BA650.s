nonmatching func_800BA650, 0x34

glabel func_800BA650
    /* 51E50 800BA650 21188000 */  addu       $v1, $a0, $zero
    /* 51E54 800BA654 0F80023C */  lui        $v0, %hi(D_800F4C69)
    /* 51E58 800BA658 694C4490 */  lbu        $a0, %lo(D_800F4C69)($v0)
    /* 51E5C 800BA65C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51E60 800BA660 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51E64 800BA664 01006580 */  lb         $a1, 0x1($v1)
    /* 51E68 800BA668 02006690 */  lbu        $a2, 0x2($v1)
    /* 51E6C 800BA66C 5D15010C */  jal        func_80045574
    /* 51E70 800BA670 00000000 */   nop
    /* 51E74 800BA674 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51E78 800BA678 21100000 */  addu       $v0, $zero, $zero
    /* 51E7C 800BA67C 0800E003 */  jr         $ra
    /* 51E80 800BA680 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA650
