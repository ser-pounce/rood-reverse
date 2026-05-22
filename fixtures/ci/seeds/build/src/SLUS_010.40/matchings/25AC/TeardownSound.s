nonmatching TeardownSound, 0x20

glabel TeardownSound
    /* 25CC 80011DCC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25D0 80011DD0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 25D4 80011DD4 8A4E000C */  jal        StopSound
    /* 25D8 80011DD8 00000000 */   nop
    /* 25DC 80011DDC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25E0 80011DE0 21100000 */  addu       $v0, $zero, $zero
    /* 25E4 80011DE4 0800E003 */  jr         $ra
    /* 25E8 80011DE8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel TeardownSound
