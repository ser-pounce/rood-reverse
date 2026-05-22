nonmatching func_80084340, 0x30

glabel func_80084340
    /* 1BB40 80084340 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1BB44 80084344 2800A28F */  lw         $v0, 0x28($sp)
    /* 1BB48 80084348 00000000 */  nop
    /* 1BB4C 8008434C 04004010 */  beqz       $v0, .L80084360
    /* 1BB50 80084350 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1BB54 80084354 20000424 */  addiu      $a0, $zero, 0x20
    /* 1BB58 80084358 05FB020C */  jal        vs_battle_setStateFlag
    /* 1BB5C 8008435C 01000524 */   addiu     $a1, $zero, 0x1
  .L80084360:
    /* 1BB60 80084360 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1BB64 80084364 00000000 */  nop
    /* 1BB68 80084368 0800E003 */  jr         $ra
    /* 1BB6C 8008436C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80084340
