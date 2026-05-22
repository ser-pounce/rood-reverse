/* Handwritten function */
nonmatching ApplyMatrix, 0x4C

glabel ApplyMatrix
    /* 31F7C 8004177C 0000888C */  lw         $t0, 0x0($a0)
    /* 31F80 80041780 0400898C */  lw         $t1, 0x4($a0)
    /* 31F84 80041784 08008A8C */  lw         $t2, 0x8($a0)
    /* 31F88 80041788 0C008B8C */  lw         $t3, 0xC($a0)
    /* 31F8C 8004178C 10008C8C */  lw         $t4, 0x10($a0)
    /* 31F90 80041790 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 31F94 80041794 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 31F98 80041798 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 31F9C 8004179C 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 31FA0 800417A0 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 31FA4 800417A4 0000A0C8 */  lwc2       $0, 0x0($a1)
    /* 31FA8 800417A8 0400A1C8 */  lwc2       $1, 0x4($a1)
    /* 31FAC 800417AC 00000000 */  nop
    /* 31FB0 800417B0 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 31FB4 800417B4 0000D9E8 */  swc2       $25, 0x0($a2)
    /* 31FB8 800417B8 0400DAE8 */  swc2       $26, 0x4($a2) /* handwritten instruction */
    /* 31FBC 800417BC 0800DBE8 */  swc2       $27, 0x8($a2) /* handwritten instruction */
    /* 31FC0 800417C0 0800E003 */  jr         $ra
    /* 31FC4 800417C4 2110C000 */   addu      $v0, $a2, $zero
endlabel ApplyMatrix
