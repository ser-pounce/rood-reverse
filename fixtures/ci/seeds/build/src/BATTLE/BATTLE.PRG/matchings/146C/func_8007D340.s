nonmatching func_8007D340, 0x20

glabel func_8007D340
    /* 14B40 8007D340 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14B44 8007D344 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14B48 8007D348 8AA8010C */  jal        _removeActorAtIndex
    /* 14B4C 8007D34C 21280000 */   addu      $a1, $zero, $zero
    /* 14B50 8007D350 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14B54 8007D354 00000000 */  nop
    /* 14B58 8007D358 0800E003 */  jr         $ra
    /* 14B5C 8007D35C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007D340
