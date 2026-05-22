/* Handwritten function */
nonmatching SetGeomOffset, 0x18

glabel SetGeomOffset
    /* 31D40 80041540 00240400 */  sll        $a0, $a0, 16
    /* 31D44 80041544 002C0500 */  sll        $a1, $a1, 16
    /* 31D48 80041548 00C0C448 */  ctc2       $a0, $24 /* handwritten instruction */
    /* 31D4C 8004154C 00C8C548 */  ctc2       $a1, $25 /* handwritten instruction */
    /* 31D50 80041550 0800E003 */  jr         $ra
    /* 31D54 80041554 00000000 */   nop
endlabel SetGeomOffset
