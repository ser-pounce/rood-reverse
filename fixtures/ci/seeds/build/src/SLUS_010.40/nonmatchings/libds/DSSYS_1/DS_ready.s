nonmatching DS_ready, 0x24

glabel DS_ready
    /* 15190 80024990 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 15194 80024994 1000BFAF */  sw         $ra, 0x10($sp)
    /* 15198 80024998 21288000 */  addu       $a1, $a0, $zero
    /* 1519C 8002499C 6A84000C */  jal        CD_ready
    /* 151A0 800249A0 01000424 */   addiu     $a0, $zero, 0x1
    /* 151A4 800249A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 151A8 800249A8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 151AC 800249AC 0800E003 */  jr         $ra
    /* 151B0 800249B0 00000000 */   nop
endlabel DS_ready
