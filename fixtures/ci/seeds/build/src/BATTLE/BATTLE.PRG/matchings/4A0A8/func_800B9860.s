nonmatching func_800B9860, 0x2C

glabel func_800B9860
    /* 51060 800B9860 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51064 800B9864 21108000 */  addu       $v0, $a0, $zero
    /* 51068 800B9868 1000BFAF */  sw         $ra, 0x10($sp)
    /* 5106C 800B986C 01004490 */  lbu        $a0, 0x1($v0)
    /* 51070 800B9870 02004590 */  lbu        $a1, 0x2($v0)
    /* 51074 800B9874 8746020C */  jal        func_80091A1C
    /* 51078 800B9878 00000000 */   nop
    /* 5107C 800B987C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51080 800B9880 21100000 */  addu       $v0, $zero, $zero
    /* 51084 800B9884 0800E003 */  jr         $ra
    /* 51088 800B9888 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9860
