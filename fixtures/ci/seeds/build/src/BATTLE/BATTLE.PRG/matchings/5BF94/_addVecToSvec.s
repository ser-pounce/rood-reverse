nonmatching _addVecToSvec, 0x40

glabel _addVecToSvec
    /* 6A1B0 800D29B0 0000A384 */  lh         $v1, 0x0($a1)
    /* 6A1B4 800D29B4 0000828C */  lw         $v0, 0x0($a0)
    /* 6A1B8 800D29B8 00000000 */  nop
    /* 6A1BC 800D29BC 21104300 */  addu       $v0, $v0, $v1
    /* 6A1C0 800D29C0 0000C2AC */  sw         $v0, 0x0($a2)
    /* 6A1C4 800D29C4 0200A384 */  lh         $v1, 0x2($a1)
    /* 6A1C8 800D29C8 0400828C */  lw         $v0, 0x4($a0)
    /* 6A1CC 800D29CC 00000000 */  nop
    /* 6A1D0 800D29D0 21104300 */  addu       $v0, $v0, $v1
    /* 6A1D4 800D29D4 0400C2AC */  sw         $v0, 0x4($a2)
    /* 6A1D8 800D29D8 0400A384 */  lh         $v1, 0x4($a1)
    /* 6A1DC 800D29DC 0800828C */  lw         $v0, 0x8($a0)
    /* 6A1E0 800D29E0 00000000 */  nop
    /* 6A1E4 800D29E4 21104300 */  addu       $v0, $v0, $v1
    /* 6A1E8 800D29E8 0800E003 */  jr         $ra
    /* 6A1EC 800D29EC 0800C2AC */   sw        $v0, 0x8($a2)
endlabel _addVecToSvec
