nonmatching func_8008C458, 0x20

glabel func_8008C458
    /* 23C58 8008C458 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 23C5C 8008C45C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 23C60 8008C460 CE62020C */  jal        func_80098B38
    /* 23C64 8008C464 21280000 */   addu      $a1, $zero, $zero
    /* 23C68 8008C468 1000BF8F */  lw         $ra, 0x10($sp)
    /* 23C6C 8008C46C 00000000 */  nop
    /* 23C70 8008C470 0800E003 */  jr         $ra
    /* 23C74 8008C474 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008C458
