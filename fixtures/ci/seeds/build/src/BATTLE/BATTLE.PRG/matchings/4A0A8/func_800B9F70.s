nonmatching func_800B9F70, 0x20

glabel func_800B9F70
    /* 51770 800B9F70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51774 800B9F74 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51778 800B9F78 3F3C020C */  jal        func_8008F0FC
    /* 5177C 800B9F7C 00000000 */   nop
    /* 51780 800B9F80 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51784 800B9F84 0100422C */  sltiu      $v0, $v0, 0x1
    /* 51788 800B9F88 0800E003 */  jr         $ra
    /* 5178C 800B9F8C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9F70
