nonmatching func_800B9818, 0x24

glabel func_800B9818
    /* 51018 800B9818 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5101C 800B981C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51020 800B9820 01008490 */  lbu        $a0, 0x1($a0)
    /* 51024 800B9824 6646020C */  jal        func_80091998
    /* 51028 800B9828 00000000 */   nop
    /* 5102C 800B982C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51030 800B9830 21100000 */  addu       $v0, $zero, $zero
    /* 51034 800B9834 0800E003 */  jr         $ra
    /* 51038 800B9838 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9818
