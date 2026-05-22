nonmatching func_80013328, 0x20

glabel func_80013328
    /* 3B28 80013328 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3B2C 8001332C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3B30 80013330 0C63000C */  jal        func_80018C30
    /* 3B34 80013334 E2000424 */   addiu     $a0, $zero, 0xE2
    /* 3B38 80013338 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3B3C 8001333C 00000000 */  nop
    /* 3B40 80013340 0800E003 */  jr         $ra
    /* 3B44 80013344 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80013328
