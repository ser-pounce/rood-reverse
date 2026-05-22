nonmatching func_800819D0, 0x2C

glabel func_800819D0
    /* 191D0 800819D0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 191D4 800819D4 3000A28F */  lw         $v0, 0x30($sp)
    /* 191D8 800819D8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 191DC 800819DC 1400A0AF */  sw         $zero, 0x14($sp)
    /* 191E0 800819E0 5204020C */  jal        func_80081148
    /* 191E4 800819E4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 191E8 800819E8 00140200 */  sll        $v0, $v0, 16
    /* 191EC 800819EC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 191F0 800819F0 03140200 */  sra        $v0, $v0, 16
    /* 191F4 800819F4 0800E003 */  jr         $ra
    /* 191F8 800819F8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800819D0
