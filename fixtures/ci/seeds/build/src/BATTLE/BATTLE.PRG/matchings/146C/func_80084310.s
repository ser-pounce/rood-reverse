nonmatching func_80084310, 0x30

glabel func_80084310
    /* 1BB10 80084310 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1BB14 80084314 2800A28F */  lw         $v0, 0x28($sp)
    /* 1BB18 80084318 00000000 */  nop
    /* 1BB1C 8008431C 04004010 */  beqz       $v0, .L80084330
    /* 1BB20 80084320 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1BB24 80084324 40000424 */  addiu      $a0, $zero, 0x40
    /* 1BB28 80084328 05FB020C */  jal        vs_battle_setStateFlag
    /* 1BB2C 8008432C 01000524 */   addiu     $a1, $zero, 0x1
  .L80084330:
    /* 1BB30 80084330 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1BB34 80084334 00000000 */  nop
    /* 1BB38 80084338 0800E003 */  jr         $ra
    /* 1BB3C 8008433C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80084310
