/* Handwritten function */
nonmatching SetGeomScreen, 0xC

glabel SetGeomScreen
    /* 31D34 80041534 00D0C448 */  ctc2       $a0, $26 /* handwritten instruction */
    /* 31D38 80041538 0800E003 */  jr         $ra
    /* 31D3C 8004153C 00000000 */   nop
endlabel SetGeomScreen
