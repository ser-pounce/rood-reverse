nonmatching func_800CB208, 0x34

glabel func_800CB208
    /* 62A08 800CB208 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62A0C 800CB20C 0F80023C */  lui        $v0, %hi(D_800F4E88)
    /* 62A10 800CB210 884E44A0 */  sb         $a0, %lo(D_800F4E88)($v0)
    /* 62A14 800CB214 0F80023C */  lui        $v0, %hi(D_800F4FDA)
    /* 62A18 800CB218 03000424 */  addiu      $a0, $zero, 0x3
    /* 62A1C 800CB21C DA4F45A0 */  sb         $a1, %lo(D_800F4FDA)($v0)
    /* 62A20 800CB220 1000BFAF */  sw         $ra, 0x10($sp)
    /* 62A24 800CB224 342B030C */  jal        func_800CACD0
    /* 62A28 800CB228 02000524 */   addiu     $a1, $zero, 0x2
    /* 62A2C 800CB22C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 62A30 800CB230 00000000 */  nop
    /* 62A34 800CB234 0800E003 */  jr         $ra
    /* 62A38 800CB238 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB208
