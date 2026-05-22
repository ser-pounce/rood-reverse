nonmatching _lerp2DVector, 0x4C

glabel _lerp2DVector
    /* 675D0 800CFDD0 00008784 */  lh         $a3, 0x0($a0)
    /* 675D4 800CFDD4 02008284 */  lh         $v0, 0x2($a0)
    /* 675D8 800CFDD8 00000000 */  nop
    /* 675DC 800CFDDC 23104700 */  subu       $v0, $v0, $a3
    /* 675E0 800CFDE0 18004500 */  mult       $v0, $a1
    /* 675E4 800CFDE4 04008384 */  lh         $v1, 0x4($a0)
    /* 675E8 800CFDE8 06008284 */  lh         $v0, 0x6($a0)
    /* 675EC 800CFDEC 12400000 */  mflo       $t0
    /* 675F0 800CFDF0 23104300 */  subu       $v0, $v0, $v1
    /* 675F4 800CFDF4 00000000 */  nop
    /* 675F8 800CFDF8 18004500 */  mult       $v0, $a1
    /* 675FC 800CFDFC C3110800 */  sra        $v0, $t0, 7
    /* 67600 800CFE00 21104700 */  addu       $v0, $v0, $a3
    /* 67604 800CFE04 0000C2AC */  sw         $v0, 0x0($a2)
    /* 67608 800CFE08 12500000 */  mflo       $t2
    /* 6760C 800CFE0C C3110A00 */  sra        $v0, $t2, 7
    /* 67610 800CFE10 21104300 */  addu       $v0, $v0, $v1
    /* 67614 800CFE14 0800E003 */  jr         $ra
    /* 67618 800CFE18 0400C2AC */   sw        $v0, 0x4($a2)
endlabel _lerp2DVector
