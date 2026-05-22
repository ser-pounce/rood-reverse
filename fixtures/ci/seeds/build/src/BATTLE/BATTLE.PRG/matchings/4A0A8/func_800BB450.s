nonmatching func_800BB450, 0x24

glabel func_800BB450
    /* 52C50 800BB450 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52C54 800BB454 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52C58 800BB458 01008490 */  lbu        $a0, 0x1($a0)
    /* 52C5C 800BB45C 54F7010C */  jal        func_8007DD50
    /* 52C60 800BB460 00000000 */   nop
    /* 52C64 800BB464 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52C68 800BB468 21100000 */  addu       $v0, $zero, $zero
    /* 52C6C 800BB46C 0800E003 */  jr         $ra
    /* 52C70 800BB470 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB450
