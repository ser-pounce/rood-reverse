nonmatching func_80089D04, 0x20

glabel func_80089D04
    /* 21504 80089D04 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21508 80089D08 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2150C 80089D0C 6EA1000C */  jal        SetDispMask
    /* 21510 80089D10 21200000 */   addu      $a0, $zero, $zero
    /* 21514 80089D14 1000BF8F */  lw         $ra, 0x10($sp)
    /* 21518 80089D18 00000000 */  nop
    /* 2151C 80089D1C 0800E003 */  jr         $ra
    /* 21520 80089D20 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80089D04
