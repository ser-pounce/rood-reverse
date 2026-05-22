nonmatching func_800BB2E4, 0x20

glabel func_800BB2E4
    /* 52AE4 800BB2E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52AE8 800BB2E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52AEC 800BB2EC E72D030C */  jal        func_800CB79C
    /* 52AF0 800BB2F0 00000000 */   nop
    /* 52AF4 800BB2F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52AF8 800BB2F8 21100000 */  addu       $v0, $zero, $zero
    /* 52AFC 800BB2FC 0800E003 */  jr         $ra
    /* 52B00 800BB300 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB2E4
