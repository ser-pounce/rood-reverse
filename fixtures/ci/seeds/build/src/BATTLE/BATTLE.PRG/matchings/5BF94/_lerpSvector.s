nonmatching _lerpSvector, 0x70

glabel _lerpSvector
    /* 67560 800CFD60 00008884 */  lh         $t0, 0x0($a0)
    /* 67564 800CFD64 02008284 */  lh         $v0, 0x2($a0)
    /* 67568 800CFD68 00000000 */  nop
    /* 6756C 800CFD6C 23104800 */  subu       $v0, $v0, $t0
    /* 67570 800CFD70 18004500 */  mult       $v0, $a1
    /* 67574 800CFD74 04008784 */  lh         $a3, 0x4($a0)
    /* 67578 800CFD78 06008284 */  lh         $v0, 0x6($a0)
    /* 6757C 800CFD7C 12500000 */  mflo       $t2
    /* 67580 800CFD80 23104700 */  subu       $v0, $v0, $a3
    /* 67584 800CFD84 00000000 */  nop
    /* 67588 800CFD88 18004500 */  mult       $v0, $a1
    /* 6758C 800CFD8C 08008384 */  lh         $v1, 0x8($a0)
    /* 67590 800CFD90 0A008284 */  lh         $v0, 0xA($a0)
    /* 67594 800CFD94 12480000 */  mflo       $t1
    /* 67598 800CFD98 23104300 */  subu       $v0, $v0, $v1
    /* 6759C 800CFD9C 00000000 */  nop
    /* 675A0 800CFDA0 18004500 */  mult       $v0, $a1
    /* 675A4 800CFDA4 C3110A00 */  sra        $v0, $t2, 7
    /* 675A8 800CFDA8 21104800 */  addu       $v0, $v0, $t0
    /* 675AC 800CFDAC 0000C2A4 */  sh         $v0, 0x0($a2)
    /* 675B0 800CFDB0 C3110900 */  sra        $v0, $t1, 7
    /* 675B4 800CFDB4 21104700 */  addu       $v0, $v0, $a3
    /* 675B8 800CFDB8 0200C2A4 */  sh         $v0, 0x2($a2)
    /* 675BC 800CFDBC 12600000 */  mflo       $t4
    /* 675C0 800CFDC0 C3110C00 */  sra        $v0, $t4, 7
    /* 675C4 800CFDC4 21104300 */  addu       $v0, $v0, $v1
    /* 675C8 800CFDC8 0800E003 */  jr         $ra
    /* 675CC 800CFDCC 0400C2A4 */   sh        $v0, 0x4($a2)
endlabel _lerpSvector
