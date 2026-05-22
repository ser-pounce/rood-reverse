nonmatching DsReadBreak, 0x20

glabel DsReadBreak
    /* 16888 80026088 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1688C 8002608C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 16890 80026090 2A98000C */  jal        func_800260A8
    /* 16894 80026094 21200000 */   addu      $a0, $zero, $zero
    /* 16898 80026098 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1689C 8002609C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 168A0 800260A0 0800E003 */  jr         $ra
    /* 168A4 800260A4 00000000 */   nop
endlabel DsReadBreak
