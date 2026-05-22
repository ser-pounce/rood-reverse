nonmatching DsStatus, 0x20

glabel DsStatus
    /* 14C8C 8002448C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14C90 80024490 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14C94 80024494 5792000C */  jal        DS_status
    /* 14C98 80024498 00000000 */   nop
    /* 14C9C 8002449C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14CA0 800244A0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 14CA4 800244A4 0800E003 */  jr         $ra
    /* 14CA8 800244A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel DsStatus
