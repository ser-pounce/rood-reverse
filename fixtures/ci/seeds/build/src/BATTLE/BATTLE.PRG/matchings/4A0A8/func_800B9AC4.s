nonmatching func_800B9AC4, 0x24

glabel func_800B9AC4
    /* 512C4 800B9AC4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 512C8 800B9AC8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 512CC 800B9ACC 01008490 */  lbu        $a0, 0x1($a0)
    /* 512D0 800B9AD0 18F1010C */  jal        func_8007C460
    /* 512D4 800B9AD4 00210400 */   sll       $a0, $a0, 4
    /* 512D8 800B9AD8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 512DC 800B9ADC 21100000 */  addu       $v0, $zero, $zero
    /* 512E0 800B9AE0 0800E003 */  jr         $ra
    /* 512E4 800B9AE4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9AC4
