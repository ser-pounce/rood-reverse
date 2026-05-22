nonmatching func_800AC500, 0x40

glabel func_800AC500
    /* 43D00 800AC500 00008290 */  lbu        $v0, 0x0($a0)
    /* 43D04 800AC504 21280000 */  addu       $a1, $zero, $zero
    /* 43D08 800AC508 D01880A0 */  sb         $zero, 0x18D0($a0)
    /* 43D0C 800AC50C 0A004010 */  beqz       $v0, .L800AC538
    /* 43D10 800AC510 D11880A0 */   sb        $zero, 0x18D1($a0)
  .L800AC514:
    /* 43D14 800AC514 6800828C */  lw         $v0, 0x68($a0)
    /* 43D18 800AC518 00190500 */  sll        $v1, $a1, 4
    /* 43D1C 800AC51C 21104300 */  addu       $v0, $v0, $v1
    /* 43D20 800AC520 4C0040A0 */  sb         $zero, 0x4C($v0)
    /* 43D24 800AC524 00008290 */  lbu        $v0, 0x0($a0)
    /* 43D28 800AC528 0100A524 */  addiu      $a1, $a1, 0x1
    /* 43D2C 800AC52C 2A10A200 */  slt        $v0, $a1, $v0
    /* 43D30 800AC530 F8FF4014 */  bnez       $v0, .L800AC514
    /* 43D34 800AC534 00000000 */   nop
  .L800AC538:
    /* 43D38 800AC538 0800E003 */  jr         $ra
    /* 43D3C 800AC53C 00000000 */   nop
endlabel func_800AC500
