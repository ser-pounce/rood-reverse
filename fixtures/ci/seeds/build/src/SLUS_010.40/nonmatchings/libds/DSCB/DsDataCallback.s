nonmatching DsDataCallback, 0x24

glabel DsDataCallback
    /* 17040 80026840 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 17044 80026844 1000BFAF */  sw         $ra, 0x10($sp)
    /* 17048 80026848 21288000 */  addu       $a1, $a0, $zero
    /* 1704C 8002684C 4D7E000C */  jal        DMACallback
    /* 17050 80026850 03000424 */   addiu     $a0, $zero, 0x3
    /* 17054 80026854 1000BF8F */  lw         $ra, 0x10($sp)
    /* 17058 80026858 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1705C 8002685C 0800E003 */  jr         $ra
    /* 17060 80026860 00000000 */   nop
endlabel DsDataCallback
