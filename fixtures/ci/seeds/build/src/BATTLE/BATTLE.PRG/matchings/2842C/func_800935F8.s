nonmatching func_800935F8, 0x24

glabel func_800935F8
    /* 2ADF8 800935F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2ADFC 800935FC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2AE00 80093600 0400A48C */  lw         $a0, 0x4($a1)
    /* 2AE04 80093604 474A020C */  jal        func_8009291C
    /* 2AE08 80093608 00000000 */   nop
    /* 2AE0C 8009360C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2AE10 80093610 21100000 */  addu       $v0, $zero, $zero
    /* 2AE14 80093614 0800E003 */  jr         $ra
    /* 2AE18 80093618 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800935F8
