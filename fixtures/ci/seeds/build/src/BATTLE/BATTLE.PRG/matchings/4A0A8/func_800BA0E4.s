nonmatching func_800BA0E4, 0x24

glabel func_800BA0E4
    /* 518E4 800BA0E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 518E8 800BA0E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 518EC 800BA0EC 01008490 */  lbu        $a0, 0x1($a0)
    /* 518F0 800BA0F0 C544020C */  jal        func_80091314
    /* 518F4 800BA0F4 01008438 */   xori      $a0, $a0, 0x1
    /* 518F8 800BA0F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 518FC 800BA0FC 21100000 */  addu       $v0, $zero, $zero
    /* 51900 800BA100 0800E003 */  jr         $ra
    /* 51904 800BA104 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA0E4
