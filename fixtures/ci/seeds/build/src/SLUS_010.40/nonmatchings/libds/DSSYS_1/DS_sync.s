nonmatching DS_sync, 0x24

glabel DS_sync
    /* 1516C 8002496C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 15170 80024970 1000BFAF */  sw         $ra, 0x10($sp)
    /* 15174 80024974 21288000 */  addu       $a1, $a0, $zero
    /* 15178 80024978 CA83000C */  jal        CD_sync
    /* 1517C 8002497C 01000424 */   addiu     $a0, $zero, 0x1
    /* 15180 80024980 1000BF8F */  lw         $ra, 0x10($sp)
    /* 15184 80024984 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 15188 80024988 0800E003 */  jr         $ra
    /* 1518C 8002498C 00000000 */   nop
endlabel DS_sync
