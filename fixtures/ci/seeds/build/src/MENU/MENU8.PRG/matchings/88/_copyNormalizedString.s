nonmatching _copyNormalizedString, 0xBC

glabel _copyNormalizedString
    /* 171C 80103F1C 21280000 */  addu       $a1, $zero, $zero
    /* 1720 80103F20 2130A000 */  addu       $a2, $a1, $zero
    /* 1724 80103F24 1080023C */  lui        $v0, %hi(_stringBuf)
    /* 1728 80103F28 405F4824 */  addiu      $t0, $v0, %lo(_stringBuf)
    /* 172C 80103F2C E7000724 */  addiu      $a3, $zero, 0xE7
  .L80103F30:
    /* 1730 80103F30 2110C800 */  addu       $v0, $a2, $t0
    /* 1734 80103F34 00004390 */  lbu        $v1, 0x0($v0)
    /* 1738 80103F38 00000000 */  nop
    /* 173C 80103F3C 06006710 */  beq        $v1, $a3, .L80103F58
    /* 1740 80103F40 21108500 */   addu      $v0, $a0, $a1
    /* 1744 80103F44 000043A0 */  sb         $v1, 0x0($v0)
    /* 1748 80103F48 0100C624 */  addiu      $a2, $a2, 0x1
    /* 174C 80103F4C 1400C228 */  slti       $v0, $a2, 0x14
    /* 1750 80103F50 F7FF4014 */  bnez       $v0, .L80103F30
    /* 1754 80103F54 0100A524 */   addiu     $a1, $a1, 0x1
  .L80103F58:
    /* 1758 80103F58 21108500 */  addu       $v0, $a0, $a1
    /* 175C 80103F5C FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 1760 80103F60 21308500 */  addu       $a2, $a0, $a1
    /* 1764 80103F64 000047A0 */  sb         $a3, 0x0($v0)
    /* 1768 80103F68 0000C390 */  lbu        $v1, 0x0($a2)
    /* 176C 80103F6C 8F000224 */  addiu      $v0, $zero, 0x8F
    /* 1770 80103F70 0E006214 */  bne        $v1, $v0, .L80103FAC
    /* 1774 80103F74 00000000 */   nop
    /* 1778 80103F78 E7000724 */  addiu      $a3, $zero, 0xE7
    /* 177C 80103F7C 21184000 */  addu       $v1, $v0, $zero
    /* 1780 80103F80 FFFFA524 */  addiu      $a1, $a1, -0x1
  .L80103F84:
    /* 1784 80103F84 0300A104 */  bgez       $a1, .L80103F94
    /* 1788 80103F88 0000C7A0 */   sb        $a3, 0x0($a2)
    /* 178C 80103F8C 0800E003 */  jr         $ra
    /* 1790 80103F90 01000224 */   addiu     $v0, $zero, 0x1
  .L80103F94:
    /* 1794 80103F94 21308500 */  addu       $a2, $a0, $a1
    /* 1798 80103F98 0000C290 */  lbu        $v0, 0x0($a2)
    /* 179C 80103F9C 00000000 */  nop
    /* 17A0 80103FA0 F8FF4310 */  beq        $v0, $v1, .L80103F84
    /* 17A4 80103FA4 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 17A8 80103FA8 0100A524 */  addiu      $a1, $a1, 0x1
  .L80103FAC:
    /* 17AC 80103FAC 0200A524 */  addiu      $a1, $a1, 0x2
    /* 17B0 80103FB0 1800A228 */  slti       $v0, $a1, 0x18
    /* 17B4 80103FB4 06004010 */  beqz       $v0, .L80103FD0
    /* 17B8 80103FB8 21108500 */   addu      $v0, $a0, $a1
  .L80103FBC:
    /* 17BC 80103FBC 000040A0 */  sb         $zero, 0x0($v0)
    /* 17C0 80103FC0 0100A524 */  addiu      $a1, $a1, 0x1
    /* 17C4 80103FC4 1800A228 */  slti       $v0, $a1, 0x18
    /* 17C8 80103FC8 FCFF4014 */  bnez       $v0, .L80103FBC
    /* 17CC 80103FCC 21108500 */   addu      $v0, $a0, $a1
  .L80103FD0:
    /* 17D0 80103FD0 0800E003 */  jr         $ra
    /* 17D4 80103FD4 21100000 */   addu      $v0, $zero, $zero
endlabel _copyNormalizedString
