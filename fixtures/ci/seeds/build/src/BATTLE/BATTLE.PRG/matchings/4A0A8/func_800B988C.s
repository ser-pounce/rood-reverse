nonmatching func_800B988C, 0x34

glabel func_800B988C
    /* 5108C 800B988C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51090 800B9890 21108000 */  addu       $v0, $a0, $zero
    /* 51094 800B9894 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51098 800B9898 01004490 */  lbu        $a0, 0x1($v0)
    /* 5109C 800B989C 03004590 */  lbu        $a1, 0x3($v0)
    /* 510A0 800B98A0 02004690 */  lbu        $a2, 0x2($v0)
    /* 510A4 800B98A4 04004790 */  lbu        $a3, 0x4($v0)
    /* 510A8 800B98A8 022E020C */  jal        func_8008B808
    /* 510AC 800B98AC 00000000 */   nop
    /* 510B0 800B98B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 510B4 800B98B4 21100000 */  addu       $v0, $zero, $zero
    /* 510B8 800B98B8 0800E003 */  jr         $ra
    /* 510BC 800B98BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B988C
