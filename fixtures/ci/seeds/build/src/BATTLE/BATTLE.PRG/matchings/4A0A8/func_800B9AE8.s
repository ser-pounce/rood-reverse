nonmatching func_800B9AE8, 0x30

glabel func_800B9AE8
    /* 512E8 800B9AE8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 512EC 800B9AEC 21108000 */  addu       $v0, $a0, $zero
    /* 512F0 800B9AF0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 512F4 800B9AF4 03004690 */  lbu        $a2, 0x3($v0)
    /* 512F8 800B9AF8 01004490 */  lbu        $a0, 0x1($v0)
    /* 512FC 800B9AFC 02004590 */  lbu        $a1, 0x2($v0)
    /* 51300 800B9B00 11F1010C */  jal        func_8007C444
    /* 51304 800B9B04 00310600 */   sll       $a2, $a2, 4
    /* 51308 800B9B08 1000BF8F */  lw         $ra, 0x10($sp)
    /* 5130C 800B9B0C 21100000 */  addu       $v0, $zero, $zero
    /* 51310 800B9B10 0800E003 */  jr         $ra
    /* 51314 800B9B14 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9AE8
