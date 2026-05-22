nonmatching _getSetShieldIndex, 0x3C

glabel _getSetShieldIndex
    /* 1514 80103D14 05000224 */  addiu      $v0, $zero, 0x5
    /* 1518 80103D18 0B008214 */  bne        $a0, $v0, .L80103D48
    /* 151C 80103D1C 21180000 */   addu      $v1, $zero, $zero
    /* 1520 80103D20 C0100500 */  sll        $v0, $a1, 3
    /* 1524 80103D24 23104500 */  subu       $v0, $v0, $a1
    /* 1528 80103D28 80100200 */  sll        $v0, $v0, 2
    /* 152C 80103D2C 2110C200 */  addu       $v0, $a2, $v0
    /* 1530 80103D30 18234394 */  lhu        $v1, 0x2318($v0)
    /* 1534 80103D34 00000000 */  nop
    /* 1538 80103D38 80006230 */  andi       $v0, $v1, 0x80
    /* 153C 80103D3C 02004014 */  bnez       $v0, .L80103D48
    /* 1540 80103D40 00000000 */   nop
    /* 1544 80103D44 21180000 */  addu       $v1, $zero, $zero
  .L80103D48:
    /* 1548 80103D48 0800E003 */  jr         $ra
    /* 154C 80103D4C 7F006230 */   andi      $v0, $v1, 0x7F
endlabel _getSetShieldIndex
