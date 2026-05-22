/* Handwritten function */
nonmatching SetRotMatrix, 0x30

glabel SetRotMatrix
    /* 31D98 80041598 0000888C */  lw         $t0, 0x0($a0)
    /* 31D9C 8004159C 0400898C */  lw         $t1, 0x4($a0)
    /* 31DA0 800415A0 08008A8C */  lw         $t2, 0x8($a0)
    /* 31DA4 800415A4 0C008B8C */  lw         $t3, 0xC($a0)
    /* 31DA8 800415A8 10008C8C */  lw         $t4, 0x10($a0)
    /* 31DAC 800415AC 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 31DB0 800415B0 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 31DB4 800415B4 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 31DB8 800415B8 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 31DBC 800415BC 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 31DC0 800415C0 0800E003 */  jr         $ra
    /* 31DC4 800415C4 00000000 */   nop
endlabel SetRotMatrix
