nonmatching func_8009E634, 0xCC

glabel func_8009E634
    /* 35E34 8009E634 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35E38 8009E638 21288000 */  addu       $a1, $a0, $zero
    /* 35E3C 8009E63C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 35E40 8009E640 0F00A290 */  lbu        $v0, 0xF($a1)
    /* 35E44 8009E644 00000000 */  nop
    /* 35E48 8009E648 29004014 */  bnez       $v0, .L8009E6F0
    /* 35E4C 8009E64C 01000424 */   addiu     $a0, $zero, 0x1
    /* 35E50 8009E650 B805A390 */  lbu        $v1, 0x5B8($a1)
    /* 35E54 8009E654 00000000 */  nop
    /* 35E58 8009E658 B1FF6224 */  addiu      $v0, $v1, -0x4F
    /* 35E5C 8009E65C 0400422C */  sltiu      $v0, $v0, 0x4
    /* 35E60 8009E660 0A004014 */  bnez       $v0, .L8009E68C
    /* 35E64 8009E664 00000000 */   nop
    /* 35E68 8009E668 B9FF6224 */  addiu      $v0, $v1, -0x47
    /* 35E6C 8009E66C 0400422C */  sltiu      $v0, $v0, 0x4
    /* 35E70 8009E670 07004014 */  bnez       $v0, .L8009E690
    /* 35E74 8009E674 00000000 */   nop
    /* 35E78 8009E678 4C000224 */  addiu      $v0, $zero, 0x4C
    /* 35E7C 8009E67C 04006210 */  beq        $v1, $v0, .L8009E690
    /* 35E80 8009E680 00000000 */   nop
    /* 35E84 8009E684 BC790208 */  j          .L8009E6F0
    /* 35E88 8009E688 00000000 */   nop
  .L8009E68C:
    /* 35E8C 8009E68C 02000424 */  addiu      $a0, $zero, 0x2
  .L8009E690:
    /* 35E90 8009E690 2600A284 */  lh         $v0, 0x26($a1)
    /* 35E94 8009E694 00000000 */  nop
    /* 35E98 8009E698 00024324 */  addiu      $v1, $v0, 0x200
    /* 35E9C 8009E69C FF0F6330 */  andi       $v1, $v1, 0xFFF
    /* 35EA0 8009E6A0 02006104 */  bgez       $v1, .L8009E6AC
    /* 35EA4 8009E6A4 21106000 */   addu      $v0, $v1, $zero
    /* 35EA8 8009E6A8 FF036224 */  addiu      $v0, $v1, 0x3FF
  .L8009E6AC:
    /* 35EAC 8009E6AC 831A0200 */  sra        $v1, $v0, 10
    /* 35EB0 8009E6B0 21300000 */  addu       $a2, $zero, $zero
    /* 35EB4 8009E6B4 02006228 */  slti       $v0, $v1, 0x2
    /* 35EB8 8009E6B8 02004010 */  beqz       $v0, .L8009E6C4
    /* 35EBC 8009E6BC 2138C000 */   addu      $a3, $a2, $zero
    /* 35EC0 8009E6C0 23200400 */  negu       $a0, $a0
  .L8009E6C4:
    /* 35EC4 8009E6C4 01006230 */  andi       $v0, $v1, 0x1
    /* 35EC8 8009E6C8 03004010 */  beqz       $v0, .L8009E6D8
    /* 35ECC 8009E6CC 00000000 */   nop
    /* 35ED0 8009E6D0 B7790208 */  j          .L8009E6DC
    /* 35ED4 8009E6D4 21308000 */   addu      $a2, $a0, $zero
  .L8009E6D8:
    /* 35ED8 8009E6D8 21388000 */  addu       $a3, $a0, $zero
  .L8009E6DC:
    /* 35EDC 8009E6DC 5C00A490 */  lbu        $a0, 0x5C($a1)
    /* 35EE0 8009E6E0 5E00A590 */  lbu        $a1, 0x5E($a1)
    /* 35EE4 8009E6E4 21208600 */  addu       $a0, $a0, $a2
    /* 35EE8 8009E6E8 0A93030C */  jal        func_800E4C28
    /* 35EEC 8009E6EC 2128A700 */   addu      $a1, $a1, $a3
  .L8009E6F0:
    /* 35EF0 8009E6F0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 35EF4 8009E6F4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 35EF8 8009E6F8 0800E003 */  jr         $ra
    /* 35EFC 8009E6FC 00000000 */   nop
endlabel func_8009E634
