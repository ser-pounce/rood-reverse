nonmatching func_800D4D44, 0x20

glabel func_800D4D44
    /* 6C544 800D4D44 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C548 800D4D48 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C54C 800D4D4C 3C5E030C */  jal        func_800D78F0
    /* 6C550 800D4D50 00000000 */   nop
    /* 6C554 800D4D54 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C558 800D4D58 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C55C 800D4D5C 0800E003 */  jr         $ra
    /* 6C560 800D4D60 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D4D44
