nonmatching func_800CB23C, 0x2C

glabel func_800CB23C
    /* 62A3C 800CB23C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62A40 800CB240 0F000424 */  addiu      $a0, $zero, 0xF
    /* 62A44 800CB244 1000BFAF */  sw         $ra, 0x10($sp)
    /* 62A48 800CB248 342B030C */  jal        func_800CACD0
    /* 62A4C 800CB24C 02000524 */   addiu     $a1, $zero, 0x2
    /* 62A50 800CB250 0F80033C */  lui        $v1, %hi(D_800F4FDB)
    /* 62A54 800CB254 1000BF8F */  lw         $ra, 0x10($sp)
    /* 62A58 800CB258 01000224 */  addiu      $v0, $zero, 0x1
    /* 62A5C 800CB25C DB4F62A0 */  sb         $v0, %lo(D_800F4FDB)($v1)
    /* 62A60 800CB260 0800E003 */  jr         $ra
    /* 62A64 800CB264 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB23C
