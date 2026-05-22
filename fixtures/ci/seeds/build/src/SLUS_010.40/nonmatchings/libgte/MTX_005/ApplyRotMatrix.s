/* Handwritten function */
nonmatching ApplyRotMatrix, 0x2C

glabel ApplyRotMatrix
    /* 31D08 80041508 0000888C */  lw         $t0, 0x0($a0)
    /* 31D0C 8004150C 0400898C */  lw         $t1, 0x4($a0)
    /* 31D10 80041510 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 31D14 80041514 00088948 */  mtc2       $t1, $1 /* handwritten instruction */
    /* 31D18 80041518 00000000 */  nop
    /* 31D1C 8004151C 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 31D20 80041520 0000A9E8 */  swc2       $9, 0x0($a1)
    /* 31D24 80041524 0400AAE8 */  swc2       $10, 0x4($a1)
    /* 31D28 80041528 0800ABE8 */  swc2       $11, 0x8($a1)
    /* 31D2C 8004152C 0800E003 */  jr         $ra
    /* 31D30 80041530 2110A000 */   addu      $v0, $a1, $zero
endlabel ApplyRotMatrix
