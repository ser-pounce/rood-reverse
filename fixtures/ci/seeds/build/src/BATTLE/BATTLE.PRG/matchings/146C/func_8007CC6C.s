nonmatching func_8007CC6C, 0x20

glabel func_8007CC6C
    /* 1446C 8007CC6C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14470 8007CC70 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14474 8007CC74 A773020C */  jal        func_8009CE9C
    /* 14478 8007CC78 00000000 */   nop
    /* 1447C 8007CC7C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14480 8007CC80 00000000 */  nop
    /* 14484 8007CC84 0800E003 */  jr         $ra
    /* 14488 8007CC88 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007CC6C
