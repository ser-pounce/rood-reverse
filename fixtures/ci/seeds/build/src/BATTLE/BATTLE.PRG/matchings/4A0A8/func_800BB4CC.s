nonmatching func_800BB4CC, 0x24

glabel func_800BB4CC
    /* 52CCC 800BB4CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52CD0 800BB4D0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 52CD4 800BB4D4 01008490 */  lbu        $a0, 0x1($a0)
    /* 52CD8 800BB4D8 DBF0010C */  jal        func_8007C36C
    /* 52CDC 800BB4DC 00000000 */   nop
    /* 52CE0 800BB4E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 52CE4 800BB4E4 21100000 */  addu       $v0, $zero, $zero
    /* 52CE8 800BB4E8 0800E003 */  jr         $ra
    /* 52CEC 800BB4EC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB4CC
