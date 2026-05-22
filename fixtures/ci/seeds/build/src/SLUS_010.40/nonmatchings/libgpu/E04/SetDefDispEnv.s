nonmatching SetDefDispEnv, 0x3C

glabel SetDefDispEnv
    /* 1BC34 8002B434 1000A38F */  lw         $v1, 0x10($sp)
    /* 1BC38 8002B438 21108000 */  addu       $v0, $a0, $zero
    /* 1BC3C 8002B43C 000045A4 */  sh         $a1, 0x0($v0)
    /* 1BC40 8002B440 020046A4 */  sh         $a2, 0x2($v0)
    /* 1BC44 8002B444 040047A4 */  sh         $a3, 0x4($v0)
    /* 1BC48 8002B448 080040A4 */  sh         $zero, 0x8($v0)
    /* 1BC4C 8002B44C 0A0040A4 */  sh         $zero, 0xA($v0)
    /* 1BC50 8002B450 0C0040A4 */  sh         $zero, 0xC($v0)
    /* 1BC54 8002B454 0E0040A4 */  sh         $zero, 0xE($v0)
    /* 1BC58 8002B458 110040A0 */  sb         $zero, 0x11($v0)
    /* 1BC5C 8002B45C 100040A0 */  sb         $zero, 0x10($v0)
    /* 1BC60 8002B460 130040A0 */  sb         $zero, 0x13($v0)
    /* 1BC64 8002B464 120040A0 */  sb         $zero, 0x12($v0)
    /* 1BC68 8002B468 0800E003 */  jr         $ra
    /* 1BC6C 8002B46C 060043A4 */   sh        $v1, 0x6($v0)
endlabel SetDefDispEnv
    /* 1BC70 8002B470 00000000 */  nop
