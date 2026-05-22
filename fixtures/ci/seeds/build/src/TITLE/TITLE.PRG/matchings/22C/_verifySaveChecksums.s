nonmatching _verifySaveChecksums, 0x94

glabel _verifySaveChecksums
    /* 6C8 80068EC8 21408000 */  addu       $t0, $a0, $zero
    /* 6CC 80068ECC 1700A018 */  blez       $a1, .L80068F2C
    /* 6D0 80068ED0 21380000 */   addu      $a3, $zero, $zero
    /* 6D4 80068ED4 01000924 */  addiu      $t1, $zero, 0x1
  .L80068ED8:
    /* 6D8 80068ED8 1000E910 */  beq        $a3, $t1, .L80068F1C
    /* 6DC 80068EDC 21300000 */   addu      $a2, $zero, $zero
    /* 6E0 80068EE0 2118C000 */  addu       $v1, $a2, $zero
    /* 6E4 80068EE4 21100301 */  addu       $v0, $t0, $v1
  .L80068EE8:
    /* 6E8 80068EE8 00004290 */  lbu        $v0, 0x0($v0)
    /* 6EC 80068EEC 01006324 */  addiu      $v1, $v1, 0x1
    /* 6F0 80068EF0 2630C200 */  xor        $a2, $a2, $v0
    /* 6F4 80068EF4 00016228 */  slti       $v0, $v1, 0x100
    /* 6F8 80068EF8 FBFF4014 */  bnez       $v0, .L80068EE8
    /* 6FC 80068EFC 21100301 */   addu      $v0, $t0, $v1
    /* 700 80068F00 21108700 */  addu       $v0, $a0, $a3
    /* 704 80068F04 A4014290 */  lbu        $v0, 0x1A4($v0)
    /* 708 80068F08 00000000 */  nop
    /* 70C 80068F0C 04004610 */  beq        $v0, $a2, .L80068F20
    /* 710 80068F10 0100E724 */   addiu     $a3, $a3, 0x1
    /* 714 80068F14 0800E003 */  jr         $ra
    /* 718 80068F18 01000224 */   addiu     $v0, $zero, 0x1
  .L80068F1C:
    /* 71C 80068F1C 0100E724 */  addiu      $a3, $a3, 0x1
  .L80068F20:
    /* 720 80068F20 2A10E500 */  slt        $v0, $a3, $a1
    /* 724 80068F24 ECFF4014 */  bnez       $v0, .L80068ED8
    /* 728 80068F28 00010825 */   addiu     $t0, $t0, 0x100
  .L80068F2C:
    /* 72C 80068F2C 00018824 */  addiu      $t0, $a0, 0x100
    /* 730 80068F30 21300000 */  addu       $a2, $zero, $zero
    /* 734 80068F34 2118C000 */  addu       $v1, $a2, $zero
    /* 738 80068F38 21100301 */  addu       $v0, $t0, $v1
  .L80068F3C:
    /* 73C 80068F3C 00004290 */  lbu        $v0, 0x0($v0)
    /* 740 80068F40 01006324 */  addiu      $v1, $v1, 0x1
    /* 744 80068F44 2630C200 */  xor        $a2, $a2, $v0
    /* 748 80068F48 00016228 */  slti       $v0, $v1, 0x100
    /* 74C 80068F4C FBFF4014 */  bnez       $v0, .L80068F3C
    /* 750 80068F50 21100301 */   addu      $v0, $t0, $v1
    /* 754 80068F54 0800E003 */  jr         $ra
    /* 758 80068F58 2B100600 */   sltu      $v0, $zero, $a2
endlabel _verifySaveChecksums
