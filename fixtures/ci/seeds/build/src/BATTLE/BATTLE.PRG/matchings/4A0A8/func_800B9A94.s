nonmatching func_800B9A94, 0x30

glabel func_800B9A94
    /* 51294 800B9A94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51298 800B9A98 21108000 */  addu       $v0, $a0, $zero
    /* 5129C 800B9A9C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 512A0 800B9AA0 03004690 */  lbu        $a2, 0x3($v0)
    /* 512A4 800B9AA4 01004490 */  lbu        $a0, 0x1($v0)
    /* 512A8 800B9AA8 02004590 */  lbu        $a1, 0x2($v0)
    /* 512AC 800B9AAC 2BF1010C */  jal        func_8007C4AC
    /* 512B0 800B9AB0 00310600 */   sll       $a2, $a2, 4
    /* 512B4 800B9AB4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 512B8 800B9AB8 21100000 */  addu       $v0, $zero, $zero
    /* 512BC 800B9ABC 0800E003 */  jr         $ra
    /* 512C0 800B9AC0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B9A94
