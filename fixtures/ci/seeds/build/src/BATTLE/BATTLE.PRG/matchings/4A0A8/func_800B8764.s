nonmatching func_800B8764, 0x24

glabel func_800B8764
    /* 4FF64 800B8764 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4FF68 800B8768 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4FF6C 800B876C 01008490 */  lbu        $a0, 0x1($a0)
    /* 4FF70 800B8770 1BF3010C */  jal        func_8007CC6C
    /* 4FF74 800B8774 00000000 */   nop
    /* 4FF78 800B8778 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4FF7C 800B877C 21100000 */  addu       $v0, $zero, $zero
    /* 4FF80 800B8780 0800E003 */  jr         $ra
    /* 4FF84 800B8784 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B8764
