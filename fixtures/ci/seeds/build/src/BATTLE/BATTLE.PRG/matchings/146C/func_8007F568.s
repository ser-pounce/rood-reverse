nonmatching func_8007F568, 0x24

glabel func_8007F568
    /* 16D68 8007F568 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16D6C 8007F56C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16D70 8007F570 46FD010C */  jal        _getEnemyClass
    /* 16D74 8007F574 2120A000 */   addu      $a0, $a1, $zero
    /* 16D78 8007F578 02004238 */  xori       $v0, $v0, 0x2
    /* 16D7C 8007F57C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16D80 8007F580 0100422C */  sltiu      $v0, $v0, 0x1
    /* 16D84 8007F584 0800E003 */  jr         $ra
    /* 16D88 8007F588 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007F568
