nonmatching InitSound, 0x20

glabel InitSound
    /* 25AC 80011DAC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 25B0 80011DB0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 25B4 80011DB4 4E4E000C */  jal        StartSound
    /* 25B8 80011DB8 00000000 */   nop
    /* 25BC 80011DBC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 25C0 80011DC0 21100000 */  addu       $v0, $zero, $zero
    /* 25C4 80011DC4 0800E003 */  jr         $ra
    /* 25C8 80011DC8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel InitSound
