nonmatching _verifySaveChecksums, 0x94

glabel _verifySaveChecksums
    /* 628 80102E28 21408000 */  addu       $t0, $a0, $zero
    /* 62C 80102E2C 1700A018 */  blez       $a1, .L80102E8C
    /* 630 80102E30 21380000 */   addu      $a3, $zero, $zero
    /* 634 80102E34 01000924 */  addiu      $t1, $zero, 0x1
  .L80102E38:
    /* 638 80102E38 1000E910 */  beq        $a3, $t1, .L80102E7C
    /* 63C 80102E3C 21300000 */   addu      $a2, $zero, $zero
    /* 640 80102E40 2118C000 */  addu       $v1, $a2, $zero
    /* 644 80102E44 21100301 */  addu       $v0, $t0, $v1
  .L80102E48:
    /* 648 80102E48 00004290 */  lbu        $v0, 0x0($v0)
    /* 64C 80102E4C 01006324 */  addiu      $v1, $v1, 0x1
    /* 650 80102E50 2630C200 */  xor        $a2, $a2, $v0
    /* 654 80102E54 00016228 */  slti       $v0, $v1, 0x100
    /* 658 80102E58 FBFF4014 */  bnez       $v0, .L80102E48
    /* 65C 80102E5C 21100301 */   addu      $v0, $t0, $v1
    /* 660 80102E60 21108700 */  addu       $v0, $a0, $a3
    /* 664 80102E64 A4014290 */  lbu        $v0, 0x1A4($v0)
    /* 668 80102E68 00000000 */  nop
    /* 66C 80102E6C 04004610 */  beq        $v0, $a2, .L80102E80
    /* 670 80102E70 0100E724 */   addiu     $a3, $a3, 0x1
    /* 674 80102E74 0800E003 */  jr         $ra
    /* 678 80102E78 01000224 */   addiu     $v0, $zero, 0x1
  .L80102E7C:
    /* 67C 80102E7C 0100E724 */  addiu      $a3, $a3, 0x1
  .L80102E80:
    /* 680 80102E80 2A10E500 */  slt        $v0, $a3, $a1
    /* 684 80102E84 ECFF4014 */  bnez       $v0, .L80102E38
    /* 688 80102E88 00010825 */   addiu     $t0, $t0, 0x100
  .L80102E8C:
    /* 68C 80102E8C 00018824 */  addiu      $t0, $a0, 0x100
    /* 690 80102E90 21300000 */  addu       $a2, $zero, $zero
    /* 694 80102E94 2118C000 */  addu       $v1, $a2, $zero
    /* 698 80102E98 21100301 */  addu       $v0, $t0, $v1
  .L80102E9C:
    /* 69C 80102E9C 00004290 */  lbu        $v0, 0x0($v0)
    /* 6A0 80102EA0 01006324 */  addiu      $v1, $v1, 0x1
    /* 6A4 80102EA4 2630C200 */  xor        $a2, $a2, $v0
    /* 6A8 80102EA8 00016228 */  slti       $v0, $v1, 0x100
    /* 6AC 80102EAC FBFF4014 */  bnez       $v0, .L80102E9C
    /* 6B0 80102EB0 21100301 */   addu      $v0, $t0, $v1
    /* 6B4 80102EB4 0800E003 */  jr         $ra
    /* 6B8 80102EB8 2B100600 */   sltu      $v0, $zero, $a2
endlabel _verifySaveChecksums
