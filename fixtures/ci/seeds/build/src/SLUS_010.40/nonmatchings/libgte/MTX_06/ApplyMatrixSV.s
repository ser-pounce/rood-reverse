/* Handwritten function */
nonmatching ApplyMatrixSV, 0x58

glabel ApplyMatrixSV
    /* 31F24 80041724 0000888C */  lw         $t0, 0x0($a0)
    /* 31F28 80041728 0400898C */  lw         $t1, 0x4($a0)
    /* 31F2C 8004172C 08008A8C */  lw         $t2, 0x8($a0)
    /* 31F30 80041730 0C008B8C */  lw         $t3, 0xC($a0)
    /* 31F34 80041734 10008C8C */  lw         $t4, 0x10($a0)
    /* 31F38 80041738 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 31F3C 8004173C 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 31F40 80041740 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 31F44 80041744 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 31F48 80041748 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 31F4C 8004174C 0000A0C8 */  lwc2       $0, 0x0($a1)
    /* 31F50 80041750 0400A1C8 */  lwc2       $1, 0x4($a1)
    /* 31F54 80041754 00000000 */  nop
    /* 31F58 80041758 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 31F5C 8004175C 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 31F60 80041760 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 31F64 80041764 00580A48 */  mfc2       $t2, $11 /* handwritten instruction */
    /* 31F68 80041768 0000C8A4 */  sh         $t0, 0x0($a2)
    /* 31F6C 8004176C 0200C9A4 */  sh         $t1, 0x2($a2)
    /* 31F70 80041770 0400CAA4 */  sh         $t2, 0x4($a2)
    /* 31F74 80041774 0800E003 */  jr         $ra
    /* 31F78 80041778 2110C000 */   addu      $v0, $a2, $zero
endlabel ApplyMatrixSV
