nonmatching _freeHeap, 0x20

glabel _freeHeap
    /* 7804 80070004 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7808 80070008 1000BFAF */  sw         $ra, 0x10($sp)
    /* 780C 8007000C 540F010C */  jal        vs_main_freeHeap
    /* 7810 80070010 00000000 */   nop
    /* 7814 80070014 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7818 80070018 00000000 */  nop
    /* 781C 8007001C 0800E003 */  jr         $ra
    /* 7820 80070020 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _freeHeap
