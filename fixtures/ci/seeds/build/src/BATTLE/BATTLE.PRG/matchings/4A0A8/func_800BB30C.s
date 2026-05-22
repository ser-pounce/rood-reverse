nonmatching func_800BB30C, 0x30

glabel func_800BB30C
    /* 52B0C 800BB30C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52B10 800BB310 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52B14 800BB314 F72D030C */  jal        func_800CB7DC
    /* 52B18 800BB318 00000000 */   nop
    /* 52B1C 800BB31C 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 52B20 800BB320 2C4C4290 */  lbu        $v0, %lo(D_800F4C2C)($v0)
    /* 52B24 800BB324 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52B28 800BB328 02004238 */  xori       $v0, $v0, 0x2
    /* 52B2C 800BB32C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 52B30 800BB330 80100200 */  sll        $v0, $v0, 2
    /* 52B34 800BB334 0800E003 */  jr         $ra
    /* 52B38 800BB338 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB30C
