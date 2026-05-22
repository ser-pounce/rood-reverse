/* Handwritten function */
nonmatching NormalClip, 0x24

glabel NormalClip
    /* 31FC8 800417C8 00608448 */  mtc2       $a0, $12 /* handwritten instruction */
    /* 31FCC 800417CC 00708648 */  mtc2       $a2, $14 /* handwritten instruction */
    /* 31FD0 800417D0 00688548 */  mtc2       $a1, $13 /* handwritten instruction */
    /* 31FD4 800417D4 00000000 */  nop
    /* 31FD8 800417D8 00000000 */  nop
    /* 31FDC 800417DC 0600404B */  nclip
    /* 31FE0 800417E0 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 31FE4 800417E4 0800E003 */  jr         $ra
    /* 31FE8 800417E8 00000000 */   nop
endlabel NormalClip
