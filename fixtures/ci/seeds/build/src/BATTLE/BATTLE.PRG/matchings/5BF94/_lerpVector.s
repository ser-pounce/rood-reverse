nonmatching _lerpVector, 0x70

glabel _lerpVector
    /* 674F0 800CFCF0 00008884 */  lh         $t0, 0x0($a0)
    /* 674F4 800CFCF4 02008284 */  lh         $v0, 0x2($a0)
    /* 674F8 800CFCF8 00000000 */  nop
    /* 674FC 800CFCFC 23104800 */  subu       $v0, $v0, $t0
    /* 67500 800CFD00 18004500 */  mult       $v0, $a1
    /* 67504 800CFD04 04008784 */  lh         $a3, 0x4($a0)
    /* 67508 800CFD08 06008284 */  lh         $v0, 0x6($a0)
    /* 6750C 800CFD0C 12500000 */  mflo       $t2
    /* 67510 800CFD10 23104700 */  subu       $v0, $v0, $a3
    /* 67514 800CFD14 00000000 */  nop
    /* 67518 800CFD18 18004500 */  mult       $v0, $a1
    /* 6751C 800CFD1C 08008384 */  lh         $v1, 0x8($a0)
    /* 67520 800CFD20 0A008284 */  lh         $v0, 0xA($a0)
    /* 67524 800CFD24 12480000 */  mflo       $t1
    /* 67528 800CFD28 23104300 */  subu       $v0, $v0, $v1
    /* 6752C 800CFD2C 00000000 */  nop
    /* 67530 800CFD30 18004500 */  mult       $v0, $a1
    /* 67534 800CFD34 C3110A00 */  sra        $v0, $t2, 7
    /* 67538 800CFD38 21104800 */  addu       $v0, $v0, $t0
    /* 6753C 800CFD3C 0000C2AC */  sw         $v0, 0x0($a2)
    /* 67540 800CFD40 C3110900 */  sra        $v0, $t1, 7
    /* 67544 800CFD44 21104700 */  addu       $v0, $v0, $a3
    /* 67548 800CFD48 0400C2AC */  sw         $v0, 0x4($a2)
    /* 6754C 800CFD4C 12600000 */  mflo       $t4
    /* 67550 800CFD50 C3110C00 */  sra        $v0, $t4, 7
    /* 67554 800CFD54 21104300 */  addu       $v0, $v0, $v1
    /* 67558 800CFD58 0800E003 */  jr         $ra
    /* 6755C 800CFD5C 0800C2AC */   sw        $v0, 0x8($a2)
endlabel _lerpVector
