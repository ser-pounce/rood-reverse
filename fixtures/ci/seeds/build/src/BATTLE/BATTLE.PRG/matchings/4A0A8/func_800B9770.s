nonmatching func_800B9770, 0x2C

glabel func_800B9770
    /* 50F70 800B9770 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 50F74 800B9774 21108000 */  addu       $v0, $a0, $zero
    /* 50F78 800B9778 1000BFAF */  sw         $ra, 0x10($sp)
    /* 50F7C 800B977C 01004490 */  lbu        $a0, 0x1($v0)
    /* 50F80 800B9780 02004590 */  lbu        $a1, 0x2($v0)
    /* 50F84 800B9784 8938020C */  jal        func_8008E224
    /* 50F88 800B9788 00000000 */   nop
    /* 50F8C 800B978C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 50F90 800B9790 21100000 */  addu       $v0, $zero, $zero
    /* 50F94 800B9794 0800E003 */  jr         $ra
    /* 50F98 800B9798 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9770
