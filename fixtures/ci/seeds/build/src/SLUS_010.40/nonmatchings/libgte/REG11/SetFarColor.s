/* Handwritten function */
nonmatching SetFarColor, 0x20

glabel SetFarColor
    /* 31D58 80041558 00210400 */  sll        $a0, $a0, 4
    /* 31D5C 8004155C 00290500 */  sll        $a1, $a1, 4
    /* 31D60 80041560 00310600 */  sll        $a2, $a2, 4
    /* 31D64 80041564 00A8C448 */  ctc2       $a0, $21 /* handwritten instruction */
    /* 31D68 80041568 00B0C548 */  ctc2       $a1, $22 /* handwritten instruction */
    /* 31D6C 8004156C 00B8C648 */  ctc2       $a2, $23 /* handwritten instruction */
    /* 31D70 80041570 0800E003 */  jr         $ra
    /* 31D74 80041574 00000000 */   nop
endlabel SetFarColor
