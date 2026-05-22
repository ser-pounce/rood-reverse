nonmatching _initContainerObject, 0x208

glabel _initContainerObject
    /* 580 80102D80 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 584 80102D84 1800B2AF */  sw         $s2, 0x18($sp)
    /* 588 80102D88 2190A000 */  addu       $s2, $a1, $zero
    /* 58C 80102D8C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 590 80102D90 2198C000 */  addu       $s3, $a2, $zero
    /* 594 80102D94 0700822C */  sltiu      $v0, $a0, 0x7
    /* 598 80102D98 2000BFAF */  sw         $ra, 0x20($sp)
    /* 59C 80102D9C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5A0 80102DA0 72004010 */  beqz       $v0, .L80102F6C
    /* 5A4 80102DA4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 5A8 80102DA8 1080023C */  lui        $v0, %hi(jtbl_80102800)
    /* 5AC 80102DAC 00284224 */  addiu      $v0, $v0, %lo(jtbl_80102800)
    /* 5B0 80102DB0 80180400 */  sll        $v1, $a0, 2
    /* 5B4 80102DB4 21186200 */  addu       $v1, $v1, $v0
    /* 5B8 80102DB8 0000628C */  lw         $v0, 0x0($v1)
    /* 5BC 80102DBC 00000000 */  nop
    /* 5C0 80102DC0 08004000 */  jr         $v0
    /* 5C4 80102DC4 00000000 */   nop
    /* 5C8 80102DC8 01000424 */  addiu      $a0, $zero, 0x1
    /* 5CC 80102DCC 21306002 */  addu       $a2, $s3, $zero
    /* 5D0 80102DD0 40111200 */  sll        $v0, $s2, 5
    /* 5D4 80102DD4 21886202 */  addu       $s1, $s3, $v0
    /* 5D8 80102DD8 01002592 */  lbu        $a1, 0x1($s1)
    /* 5DC 80102DDC 21800000 */  addu       $s0, $zero, $zero
    /* 5E0 80102DE0 600B040C */  jal        _initContainerObject
    /* 5E4 80102DE4 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 5E8 80102DE8 02000424 */  addiu      $a0, $zero, 0x2
    /* 5EC 80102DEC 02002592 */  lbu        $a1, 0x2($s1)
    /* 5F0 80102DF0 21306002 */  addu       $a2, $s3, $zero
    /* 5F4 80102DF4 600B040C */  jal        _initContainerObject
    /* 5F8 80102DF8 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 5FC 80102DFC 21103002 */  addu       $v0, $s1, $s0
  .L80102E00:
    /* 600 80102E00 04004590 */  lbu        $a1, 0x4($v0)
    /* 604 80102E04 00000000 */  nop
    /* 608 80102E08 0400A010 */  beqz       $a1, .L80102E1C
    /* 60C 80102E0C 05000424 */   addiu     $a0, $zero, 0x5
    /* 610 80102E10 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 614 80102E14 600B040C */  jal        _initContainerObject
    /* 618 80102E18 21306002 */   addu      $a2, $s3, $zero
  .L80102E1C:
    /* 61C 80102E1C 01001026 */  addiu      $s0, $s0, 0x1
    /* 620 80102E20 0300022A */  slti       $v0, $s0, 0x3
    /* 624 80102E24 F6FF4014 */  bnez       $v0, .L80102E00
    /* 628 80102E28 21103002 */   addu      $v0, $s1, $s0
    /* 62C 80102E2C 21202002 */  addu       $a0, $s1, $zero
    /* 630 80102E30 B80B0408 */  j          .L80102EE0
    /* 634 80102E34 20000524 */   addiu     $a1, $zero, 0x20
    /* 638 80102E38 40801200 */  sll        $s0, $s2, 1
    /* 63C 80102E3C 21801202 */  addu       $s0, $s0, $s2
    /* 640 80102E40 80801000 */  sll        $s0, $s0, 2
    /* 644 80102E44 23801202 */  subu       $s0, $s0, $s2
    /* 648 80102E48 80801000 */  sll        $s0, $s0, 2
    /* 64C 80102E4C 000A1026 */  addiu      $s0, $s0, 0xA00
    /* 650 80102E50 21807002 */  addu       $s0, $s3, $s0
    /* 654 80102E54 21200002 */  addu       $a0, $s0, $zero
    /* 658 80102E58 0733030C */  jal        vs_battle_rMemzero
    /* 65C 80102E5C 2C000524 */   addiu     $a1, $zero, 0x2C
    /* 660 80102E60 01004226 */  addiu      $v0, $s2, 0x1
    /* 664 80102E64 DB0B0408 */  j          .L80102F6C
    /* 668 80102E68 2B0002A2 */   sb        $v0, 0x2B($s0)
    /* 66C 80102E6C 00811200 */  sll        $s0, $s2, 4
    /* 670 80102E70 00151026 */  addiu      $s0, $s0, 0x1500
    /* 674 80102E74 21807002 */  addu       $s0, $s3, $s0
    /* 678 80102E78 21200002 */  addu       $a0, $s0, $zero
    /* 67C 80102E7C 0733030C */  jal        vs_battle_rMemzero
    /* 680 80102E80 10000524 */   addiu     $a1, $zero, 0x10
    /* 684 80102E84 01004226 */  addiu      $v0, $s2, 0x1
    /* 688 80102E88 DB0B0408 */  j          .L80102F6C
    /* 68C 80102E8C 0E0002A6 */   sh        $v0, 0xE($s0)
    /* 690 80102E90 40101200 */  sll        $v0, $s2, 1
    /* 694 80102E94 21105200 */  addu       $v0, $v0, $s2
    /* 698 80102E98 00110200 */  sll        $v0, $v0, 4
    /* 69C 80102E9C 00044224 */  addiu      $v0, $v0, 0x400
    /* 6A0 80102EA0 21886202 */  addu       $s1, $s3, $v0
    /* 6A4 80102EA4 21800000 */  addu       $s0, $zero, $zero
    /* 6A8 80102EA8 21103002 */  addu       $v0, $s1, $s0
  .L80102EAC:
    /* 6AC 80102EAC 2C004590 */  lbu        $a1, 0x2C($v0)
    /* 6B0 80102EB0 00000000 */  nop
    /* 6B4 80102EB4 0400A010 */  beqz       $a1, .L80102EC8
    /* 6B8 80102EB8 05000424 */   addiu     $a0, $zero, 0x5
    /* 6BC 80102EBC FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 6C0 80102EC0 600B040C */  jal        _initContainerObject
    /* 6C4 80102EC4 21306002 */   addu      $a2, $s3, $zero
  .L80102EC8:
    /* 6C8 80102EC8 01001026 */  addiu      $s0, $s0, 0x1
    /* 6CC 80102ECC 0300022A */  slti       $v0, $s0, 0x3
    /* 6D0 80102ED0 F6FF4014 */  bnez       $v0, .L80102EAC
    /* 6D4 80102ED4 21103002 */   addu      $v0, $s1, $s0
    /* 6D8 80102ED8 21202002 */  addu       $a0, $s1, $zero
    /* 6DC 80102EDC 30000524 */  addiu      $a1, $zero, 0x30
  .L80102EE0:
    /* 6E0 80102EE0 0733030C */  jal        vs_battle_rMemzero
    /* 6E4 80102EE4 00000000 */   nop
    /* 6E8 80102EE8 01004226 */  addiu      $v0, $s2, 0x1
    /* 6EC 80102EEC DB0B0408 */  j          .L80102F6C
    /* 6F0 80102EF0 000022A2 */   sb        $v0, 0x0($s1)
    /* 6F4 80102EF4 80801200 */  sll        $s0, $s2, 2
    /* 6F8 80102EF8 21801202 */  addu       $s0, $s0, $s2
    /* 6FC 80102EFC C0801000 */  sll        $s0, $s0, 3
    /* 700 80102F00 00191026 */  addiu      $s0, $s0, 0x1900
    /* 704 80102F04 21807002 */  addu       $s0, $s3, $s0
    /* 708 80102F08 21200002 */  addu       $a0, $s0, $zero
    /* 70C 80102F0C 0733030C */  jal        vs_battle_rMemzero
    /* 710 80102F10 28000524 */   addiu     $a1, $zero, 0x28
    /* 714 80102F14 01004226 */  addiu      $v0, $s2, 0x1
    /* 718 80102F18 DB0B0408 */  j          .L80102F6C
    /* 71C 80102F1C 270002A2 */   sb        $v0, 0x27($s0)
    /* 720 80102F20 C0801200 */  sll        $s0, $s2, 3
    /* 724 80102F24 23801202 */  subu       $s0, $s0, $s2
    /* 728 80102F28 80801000 */  sll        $s0, $s0, 2
    /* 72C 80102F2C 00231026 */  addiu      $s0, $s0, 0x2300
    /* 730 80102F30 21807002 */  addu       $s0, $s3, $s0
    /* 734 80102F34 21200002 */  addu       $a0, $s0, $zero
    /* 738 80102F38 0733030C */  jal        vs_battle_rMemzero
    /* 73C 80102F3C 1C000524 */   addiu     $a1, $zero, 0x1C
    /* 740 80102F40 01004226 */  addiu      $v0, $s2, 0x1
    /* 744 80102F44 DB0B0408 */  j          .L80102F6C
    /* 748 80102F48 1A0002A6 */   sh        $v0, 0x1A($s0)
    /* 74C 80102F4C 80801200 */  sll        $s0, $s2, 2
    /* 750 80102F50 00381026 */  addiu      $s0, $s0, 0x3800
    /* 754 80102F54 21807002 */  addu       $s0, $s3, $s0
    /* 758 80102F58 21200002 */  addu       $a0, $s0, $zero
    /* 75C 80102F5C 0733030C */  jal        vs_battle_rMemzero
    /* 760 80102F60 04000524 */   addiu     $a1, $zero, 0x4
    /* 764 80102F64 01004226 */  addiu      $v0, $s2, 0x1
    /* 768 80102F68 030002A2 */  sb         $v0, 0x3($s0)
  .L80102F6C:
    /* 76C 80102F6C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 770 80102F70 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 774 80102F74 1800B28F */  lw         $s2, 0x18($sp)
    /* 778 80102F78 1400B18F */  lw         $s1, 0x14($sp)
    /* 77C 80102F7C 1000B08F */  lw         $s0, 0x10($sp)
    /* 780 80102F80 0800E003 */  jr         $ra
    /* 784 80102F84 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _initContainerObject
