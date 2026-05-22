nonmatching CdSync, 0x20

glabel CdSync
    /* 10CF8 800204F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10CFC 800204FC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10D00 80020500 CA83000C */  jal        CD_sync
    /* 10D04 80020504 00000000 */   nop
    /* 10D08 80020508 1000BF8F */  lw         $ra, 0x10($sp)
    /* 10D0C 8002050C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 10D10 80020510 0800E003 */  jr         $ra
    /* 10D14 80020514 00000000 */   nop
endlabel CdSync
