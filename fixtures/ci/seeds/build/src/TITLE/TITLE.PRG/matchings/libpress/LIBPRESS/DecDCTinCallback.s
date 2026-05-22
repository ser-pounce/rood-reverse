nonmatching DecDCTinCallback, 0x24

glabel DecDCTinCallback
    /* 9808 80072008 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 980C 8007200C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 9810 80072010 21288000 */  addu       $a1, $a0, $zero
    /* 9814 80072014 4D7E000C */  jal        DMACallback
    /* 9818 80072018 21200000 */   addu      $a0, $zero, $zero
    /* 981C 8007201C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 9820 80072020 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 9824 80072024 0800E003 */  jr         $ra
    /* 9828 80072028 00000000 */   nop
endlabel DecDCTinCallback
