nonmatching func_80091320, 0x2C

glabel func_80091320
    /* 28B20 80091320 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 28B24 80091324 0F80023C */  lui        $v0, %hi(D_800F1DC4)
    /* 28B28 80091328 1000BFAF */  sw         $ra, 0x10($sp)
    /* 28B2C 8009132C 8744020C */  jal        func_8009121C
    /* 28B30 80091330 C41D44A4 */   sh        $a0, %lo(D_800F1DC4)($v0)
    /* 28B34 80091334 CA42020C */  jal        func_80090B28
    /* 28B38 80091338 00000000 */   nop
    /* 28B3C 8009133C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 28B40 80091340 00000000 */  nop
    /* 28B44 80091344 0800E003 */  jr         $ra
    /* 28B48 80091348 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80091320
