nonmatching func_800AA454, 0x3C

glabel func_800AA454
    /* 41C54 800AA454 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 41C58 800AA458 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 41C5C 800AA45C 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 41C60 800AA460 80180400 */  sll        $v1, $a0, 2
    /* 41C64 800AA464 21186200 */  addu       $v1, $v1, $v0
    /* 41C68 800AA468 1000BFAF */  sw         $ra, 0x10($sp)
    /* 41C6C 800AA46C 0000628C */  lw         $v0, 0x0($v1)
    /* 41C70 800AA470 00000000 */  nop
    /* 41C74 800AA474 C0054794 */  lhu        $a3, 0x5C0($v0)
    /* 41C78 800AA478 24A9020C */  jal        func_800AA490
    /* 41C7C 800AA47C 00000000 */   nop
    /* 41C80 800AA480 1000BF8F */  lw         $ra, 0x10($sp)
    /* 41C84 800AA484 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 41C88 800AA488 0800E003 */  jr         $ra
    /* 41C8C 800AA48C 00000000 */   nop
endlabel func_800AA454
