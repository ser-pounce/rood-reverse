nonmatching DsControlF, 0x28

glabel DsControlF
    /* 16354 80025B54 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 16358 80025B58 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1635C 80025B5C FF008430 */  andi       $a0, $a0, 0xFF
    /* 16360 80025B60 21300000 */  addu       $a2, $zero, $zero
    /* 16364 80025B64 CD8E000C */  jal        DsCommand
    /* 16368 80025B68 21380000 */   addu      $a3, $zero, $zero
    /* 1636C 80025B6C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16370 80025B70 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 16374 80025B74 0800E003 */  jr         $ra
    /* 16378 80025B78 00000000 */   nop
endlabel DsControlF
