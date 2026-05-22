nonmatching func_800BA5E8, 0x34

glabel func_800BA5E8
    /* 51DE8 800BA5E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51DEC 800BA5EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51DF0 800BA5F0 01008390 */  lbu        $v1, 0x1($a0)
    /* 51DF4 800BA5F4 0F80023C */  lui        $v0, %hi(D_800F4C69)
    /* 51DF8 800BA5F8 694C43A0 */  sb         $v1, %lo(D_800F4C69)($v0)
    /* 51DFC 800BA5FC 02008590 */  lbu        $a1, 0x2($a0)
    /* 51E00 800BA600 03008690 */  lbu        $a2, 0x3($a0)
    /* 51E04 800BA604 0014010C */  jal        func_80045000
    /* 51E08 800BA608 FF006430 */   andi      $a0, $v1, 0xFF
    /* 51E0C 800BA60C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51E10 800BA610 21100000 */  addu       $v0, $zero, $zero
    /* 51E14 800BA614 0800E003 */  jr         $ra
    /* 51E18 800BA618 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA5E8
