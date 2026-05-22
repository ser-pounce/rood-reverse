nonmatching CdDataSync, 0x20

glabel CdDataSync
    /* 111A0 800209A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 111A4 800209A4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 111A8 800209A8 3D87000C */  jal        CD_datasync
    /* 111AC 800209AC 00000000 */   nop
    /* 111B0 800209B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 111B4 800209B4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 111B8 800209B8 0800E003 */  jr         $ra
    /* 111BC 800209BC 00000000 */   nop
endlabel CdDataSync
    /* 111C0 800209C0 00000000 */  nop
