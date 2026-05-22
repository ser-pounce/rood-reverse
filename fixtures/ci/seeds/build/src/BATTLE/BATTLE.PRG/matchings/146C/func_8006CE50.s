nonmatching func_8006CE50, 0x20

glabel func_8006CE50
    /* 4650 8006CE50 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4654 8006CE54 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4658 8006CE58 6835020C */  jal        func_8008D5A0
    /* 465C 8006CE5C B4000424 */   addiu     $a0, $zero, 0xB4
    /* 4660 8006CE60 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4664 8006CE64 00000000 */  nop
    /* 4668 8006CE68 0800E003 */  jr         $ra
    /* 466C 8006CE6C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006CE50
