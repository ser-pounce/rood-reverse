nonmatching func_800F9EBC, 0xFC

glabel func_800F9EBC
    /* 6BC 800F9EBC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 6C0 800F9EC0 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 6C4 800F9EC4 21B88000 */  addu       $s7, $a0, $zero
    /* 6C8 800F9EC8 2800B6AF */  sw         $s6, 0x28($sp)
    /* 6CC 800F9ECC 21B0A000 */  addu       $s6, $a1, $zero
    /* 6D0 800F9ED0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6D4 800F9ED4 2198C000 */  addu       $s3, $a2, $zero
    /* 6D8 800F9ED8 2400B5AF */  sw         $s5, 0x24($sp)
    /* 6DC 800F9EDC 21A8E000 */  addu       $s5, $a3, $zero
    /* 6E0 800F9EE0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6E4 800F9EE4 2190C002 */  addu       $s2, $s6, $zero
    /* 6E8 800F9EE8 01000224 */  addiu      $v0, $zero, 0x1
    /* 6EC 800F9EEC 3000BFAF */  sw         $ra, 0x30($sp)
    /* 6F0 800F9EF0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 6F4 800F9EF4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6F8 800F9EF8 23004010 */  beqz       $v0, .L800F9F88
    /* 6FC 800F9EFC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 700 800F9F00 A000143C */  lui        $s4, (0xA0A0A0 >> 16)
    /* 704 800F9F04 A0A09436 */  ori        $s4, $s4, (0xA0A0A0 & 0xFFFF)
    /* 708 800F9F08 1800D124 */  addiu      $s1, $a2, 0x18
  .L800F9F0C:
    /* 70C 800F9F0C FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 710 800F9F10 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 714 800F9F14 FF32063C */  lui        $a2, (0x32FFFFFF >> 16)
    /* 718 800F9F18 FFFFC634 */  ori        $a2, $a2, (0x32FFFFFF & 0xFFFF)
    /* 71C 800F9F1C 01005026 */  addiu      $s0, $s2, 0x1
    /* 720 800F9F20 21200002 */  addu       $a0, $s0, $zero
    /* 724 800F9F24 0000A38E */  lw         $v1, 0x0($s5)
    /* 728 800F9F28 80000524 */  addiu      $a1, $zero, 0x80
    /* 72C 800F9F2C 24186200 */  and        $v1, $v1, $v0
    /* 730 800F9F30 0006023C */  lui        $v0, (0x6000000 >> 16)
    /* 734 800F9F34 25186200 */  or         $v1, $v1, $v0
    /* 738 800F9F38 000063AE */  sw         $v1, 0x0($s3)
    /* 73C 800F9F3C ECFF26AE */  sw         $a2, -0x14($s1)
    /* 740 800F9F40 F0FF37AE */  sw         $s7, -0x10($s1)
    /* 744 800F9F44 7EE7030C */  jal        func_800F9DF8
    /* 748 800F9F48 F4FF34AE */   sw        $s4, -0xC($s1)
    /* 74C 800F9F4C 21204002 */  addu       $a0, $s2, $zero
    /* 750 800F9F50 80000524 */  addiu      $a1, $zero, 0x80
    /* 754 800F9F54 F8FF22AE */  sw         $v0, -0x8($s1)
    /* 758 800F9F58 7EE7030C */  jal        func_800F9DF8
    /* 75C 800F9F5C FCFF34AE */   sw        $s4, -0x4($s1)
    /* 760 800F9F60 000022AE */  sw         $v0, 0x0($s1)
    /* 764 800F9F64 1C003126 */  addiu      $s1, $s1, 0x1C
    /* 768 800F9F68 00121300 */  sll        $v0, $s3, 8
    /* 76C 800F9F6C 21900002 */  addu       $s2, $s0, $zero
    /* 770 800F9F70 02120200 */  srl        $v0, $v0, 8
    /* 774 800F9F74 0000A2AE */  sw         $v0, 0x0($s5)
    /* 778 800F9F78 0400C226 */  addiu      $v0, $s6, 0x4
    /* 77C 800F9F7C 2A104202 */  slt        $v0, $s2, $v0
    /* 780 800F9F80 E2FF4014 */  bnez       $v0, .L800F9F0C
    /* 784 800F9F84 1C007326 */   addiu     $s3, $s3, 0x1C
  .L800F9F88:
    /* 788 800F9F88 21106002 */  addu       $v0, $s3, $zero
    /* 78C 800F9F8C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 790 800F9F90 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 794 800F9F94 2800B68F */  lw         $s6, 0x28($sp)
    /* 798 800F9F98 2400B58F */  lw         $s5, 0x24($sp)
    /* 79C 800F9F9C 2000B48F */  lw         $s4, 0x20($sp)
    /* 7A0 800F9FA0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7A4 800F9FA4 1800B28F */  lw         $s2, 0x18($sp)
    /* 7A8 800F9FA8 1400B18F */  lw         $s1, 0x14($sp)
    /* 7AC 800F9FAC 1000B08F */  lw         $s0, 0x10($sp)
    /* 7B0 800F9FB0 0800E003 */  jr         $ra
    /* 7B4 800F9FB4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800F9EBC
