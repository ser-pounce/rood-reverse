/* Handwritten function */
nonmatching SetTransMatrix, 0x20

glabel SetTransMatrix
    /* 31D78 80041578 1400888C */  lw         $t0, 0x14($a0)
    /* 31D7C 8004157C 1800898C */  lw         $t1, 0x18($a0)
    /* 31D80 80041580 1C008A8C */  lw         $t2, 0x1C($a0)
    /* 31D84 80041584 0028C848 */  ctc2       $t0, $5 /* handwritten instruction */
    /* 31D88 80041588 0030C948 */  ctc2       $t1, $6 /* handwritten instruction */
    /* 31D8C 8004158C 0038CA48 */  ctc2       $t2, $7 /* handwritten instruction */
    /* 31D90 80041590 0800E003 */  jr         $ra
    /* 31D94 80041594 00000000 */   nop
endlabel SetTransMatrix
