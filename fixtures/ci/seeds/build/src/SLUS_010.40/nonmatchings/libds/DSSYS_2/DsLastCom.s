nonmatching DsLastCom, 0x20

glabel DsLastCom
    /* 14CCC 800244CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14CD0 800244D0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14CD4 800244D4 4492000C */  jal        DS_lastcom
    /* 14CD8 800244D8 00000000 */   nop
    /* 14CDC 800244DC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14CE0 800244E0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 14CE4 800244E4 0800E003 */  jr         $ra
    /* 14CE8 800244E8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DsLastCom
