nonmatching func_8007F58C, 0x24

glabel func_8007F58C
    /* 16D8C 8007F58C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16D90 8007F590 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16D94 8007F594 46FD010C */  jal        _getEnemyClass
    /* 16D98 8007F598 2120A000 */   addu      $a0, $a1, $zero
    /* 16D9C 8007F59C 02004238 */  xori       $v0, $v0, 0x2
    /* 16DA0 8007F5A0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16DA4 8007F5A4 2B100200 */  sltu       $v0, $zero, $v0
    /* 16DA8 8007F5A8 0800E003 */  jr         $ra
    /* 16DAC 8007F5AC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F58C
