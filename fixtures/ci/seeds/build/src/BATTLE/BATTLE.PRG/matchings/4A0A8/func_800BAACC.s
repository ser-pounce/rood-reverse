nonmatching func_800BAACC, 0x24

glabel func_800BAACC
    /* 522CC 800BAACC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 522D0 800BAAD0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 522D4 800BAAD4 01008490 */  lbu        $a0, 0x1($a0)
    /* 522D8 800BAAD8 CE3B030C */  jal        func_800CEF38
    /* 522DC 800BAADC 00000000 */   nop
    /* 522E0 800BAAE0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 522E4 800BAAE4 21100000 */  addu       $v0, $zero, $zero
    /* 522E8 800BAAE8 0800E003 */  jr         $ra
    /* 522EC 800BAAEC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BAACC
