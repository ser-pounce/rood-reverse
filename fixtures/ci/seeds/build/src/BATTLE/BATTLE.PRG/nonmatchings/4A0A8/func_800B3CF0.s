/* Handwritten function */
nonmatching func_800B3CF0, 0x8A4

glabel func_800B3CF0
    /* 4B4F0 800B3CF0 801F083C */  lui        $t0, (0x1F800390 >> 16)
    /* 4B4F4 800B3CF4 580310AD */  sw         $s0, (0x1F800358 & 0xFFFF)($t0)
    /* 4B4F8 800B3CF8 5C0311AD */  sw         $s1, (0x1F80035C & 0xFFFF)($t0)
    /* 4B4FC 800B3CFC 600312AD */  sw         $s2, (0x1F800360 & 0xFFFF)($t0)
    /* 4B500 800B3D00 640313AD */  sw         $s3, (0x1F800364 & 0xFFFF)($t0)
    /* 4B504 800B3D04 680314AD */  sw         $s4, (0x1F800368 & 0xFFFF)($t0)
    /* 4B508 800B3D08 6C0315AD */  sw         $s5, (0x1F80036C & 0xFFFF)($t0)
    /* 4B50C 800B3D0C 700316AD */  sw         $s6, (0x1F800370 & 0xFFFF)($t0)
    /* 4B510 800B3D10 740317AD */  sw         $s7, (0x1F800374 & 0xFFFF)($t0)
    /* 4B514 800B3D14 78031FAD */  sw         $ra, (0x1F800378 & 0xFFFF)($t0)
    /* 4B518 800B3D18 7C031CAD */  sw         $gp, (0x1F80037C & 0xFFFF)($t0)
    /* 4B51C 800B3D1C 80031EAD */  sw         $fp, (0x1F800380 & 0xFFFF)($t0)
    /* 4B520 800B3D20 90031C8D */  lw         $gp, (0x1F800390 & 0xFFFF)($t0)
    /* 4B524 800B3D24 FF00143C */  lui        $s4, (0xFFFFFF >> 16)
    /* 4B528 800B3D28 FFFF9436 */  ori        $s4, $s4, (0xFFFFFF & 0xFFFF)
    /* 4B52C 800B3D2C 00FC1C00 */  sll        $ra, $gp, 16
    /* 4B530 800B3D30 02E41C00 */  srl        $gp, $gp, 16
    /* 4B534 800B3D34 00E41C00 */  sll        $gp, $gp, 16
    /* 4B538 800B3D38 00FF153C */  lui        $s5, (0xFF000000 >> 16)
    /* 4B53C 800B3D3C 801F103C */  lui        $s0, (0x1F800004 >> 16)
    /* 4B540 800B3D40 0200B394 */  lhu        $s3, 0x2($a1)
    /* 4B544 800B3D44 3C00F28C */  lw         $s2, 0x3C($a3)
    /* 4B548 800B3D48 000C9E24 */  addiu      $fp, $a0, 0xC00
    /* 4B54C 800B3D4C 0000118E */  lw         $s1, (0x1F800000 & 0xFFFF)($s0)
    /* 4B550 800B3D50 0400178E */  lw         $s7, (0x1F800004 & 0xFFFF)($s0)
    /* 4B554 800B3D54 0000C68C */  lw         $a2, 0x0($a2)
    /* 4B558 800B3D58 FCFFF722 */  addi       $s7, $s7, -0x4 /* handwritten instruction */
    /* 4B55C 800B3D5C 2430D400 */  and        $a2, $a2, $s4
    /* 4B560 800B3D60 42006012 */  beqz       $s3, .L800B3E6C
    /* 4B564 800B3D64 0007183C */   lui       $t8, (0x7000000 >> 16)
    /* 4B568 800B3D68 0024033C */  lui        $v1, (0x24000000 >> 16)
    /* 4B56C 800B3D6C 25186600 */  or         $v1, $v1, $a2
    /* 4B570 800B3D70 04004B8E */  lw         $t3, 0x4($s2)
  .L800B3D74:
    /* 4B574 800B3D74 08004F8E */  lw         $t7, 0x8($s2)
    /* 4B578 800B3D78 FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4B57C 800B3D7C 024C0B00 */  srl        $t1, $t3, 16
    /* 4B580 800B3D80 FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4B584 800B3D84 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4B588 800B3D88 00008C8D */  lw         $t4, 0x0($t4)
    /* 4B58C 800B3D8C 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4B590 800B3D90 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4B594 800B3D94 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4B598 800B3D98 0000CE8D */  lw         $t6, 0x0($t6)
    /* 4B59C 800B3D9C 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4B5A0 800B3DA0 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4B5A4 800B3DA4 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4B5A8 800B3DA8 027C0F00 */  srl        $t7, $t7, 16
    /* 4B5AC 800B3DAC 20401E01 */  add        $t0, $t0, $fp /* handwritten instruction */
    /* 4B5B0 800B3DB0 0600404B */  nclip
    /* 4B5B4 800B3DB4 0000088D */  lw         $t0, 0x0($t0)
    /* 4B5B8 800B3DB8 20483E01 */  add        $t1, $t1, $fp /* handwritten instruction */
    /* 4B5BC 800B3DBC 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4B5C0 800B3DC0 20505E01 */  add        $t2, $t2, $fp /* handwritten instruction */
    /* 4B5C4 800B3DC4 0500401C */  bgtz       $v0, .L800B3DDC
    /* 4B5C8 800B3DC8 FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4B5CC 800B3DCC 27006012 */  beqz       $s3, .L800B3E6C
    /* 4B5D0 800B3DD0 10005226 */   addiu     $s2, $s2, 0x10
    /* 4B5D4 800B3DD4 5DCF0208 */  j          .L800B3D74
    /* 4B5D8 800B3DD8 04004B8E */   lw        $t3, 0x4($s2)
  .L800B3DDC:
    /* 4B5DC 800B3DDC 0000298D */  lw         $t1, 0x0($t1)
    /* 4B5E0 800B3DE0 00004A8D */  lw         $t2, 0x0($t2)
    /* 4B5E4 800B3DE4 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4B5E8 800B3DE8 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4B5EC 800B3DEC 00988A48 */  mtc2       $t2, $19 /* handwritten instruction */
    /* 4B5F0 800B3DF0 0C004B8E */  lw         $t3, 0xC($s2)
    /* 4B5F4 800B3DF4 040023AE */  sw         $v1, 0x4($s1)
    /* 4B5F8 800B3DF8 2D00584B */  avsz3
    /* 4B5FC 800B3DFC 08002CAE */  sw         $t4, 0x8($s1)
    /* 4B600 800B3E00 024C0B00 */  srl        $t1, $t3, 16
    /* 4B604 800B3E04 25483F01 */  or         $t1, $t1, $ra
    /* 4B608 800B3E08 FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4B60C 800B3E0C 25401C01 */  or         $t0, $t0, $gp
    /* 4B610 800B3E10 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4B614 800B3E14 10002DAE */  sw         $t5, 0x10($s1)
    /* 4B618 800B3E18 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4B61C 800B3E1C 140029AE */  sw         $t1, 0x14($s1)
    /* 4B620 800B3E20 C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4B624 800B3E24 0D000011 */  beqz       $t0, .L800B3E5C
    /* 4B628 800B3E28 80100200 */   sll       $v0, $v0, 2
    /* 4B62C 800B3E2C 18002EAE */  sw         $t6, 0x18($s1)
    /* 4B630 800B3E30 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4B634 800B3E34 1C002FAE */  sw         $t7, 0x1C($s1)
    /* 4B638 800B3E38 00004A8C */  lw         $t2, 0x0($v0)
    /* 4B63C 800B3E3C 24483402 */  and        $t1, $s1, $s4
    /* 4B640 800B3E40 24405401 */  and        $t0, $t2, $s4
    /* 4B644 800B3E44 25401801 */  or         $t0, $t0, $t8
    /* 4B648 800B3E48 000028AE */  sw         $t0, 0x0($s1)
    /* 4B64C 800B3E4C 24405501 */  and        $t0, $t2, $s5
    /* 4B650 800B3E50 25400901 */  or         $t0, $t0, $t1
    /* 4B654 800B3E54 000048AC */  sw         $t0, 0x0($v0)
    /* 4B658 800B3E58 20003126 */  addiu      $s1, $s1, 0x20
  .L800B3E5C:
    /* 4B65C 800B3E5C 03006012 */  beqz       $s3, .L800B3E6C
    /* 4B660 800B3E60 10005226 */   addiu     $s2, $s2, 0x10
    /* 4B664 800B3E64 5DCF0208 */  j          .L800B3D74
    /* 4B668 800B3E68 04004B8E */   lw        $t3, 0x4($s2)
  .L800B3E6C:
    /* 4B66C 800B3E6C 0400B394 */  lhu        $s3, 0x4($a1)
    /* 4B670 800B3E70 0009183C */  lui        $t8, (0x9000000 >> 16)
    /* 4B674 800B3E74 002C033C */  lui        $v1, (0x2C000000 >> 16)
    /* 4B678 800B3E78 47006012 */  beqz       $s3, .L800B3F98
    /* 4B67C 800B3E7C 25186600 */   or        $v1, $v1, $a2
    /* 4B680 800B3E80 04004B8E */  lw         $t3, 0x4($s2)
  .L800B3E84:
    /* 4B684 800B3E84 08004F8E */  lw         $t7, 0x8($s2)
    /* 4B688 800B3E88 FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4B68C 800B3E8C 024C0B00 */  srl        $t1, $t3, 16
    /* 4B690 800B3E90 FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4B694 800B3E94 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4B698 800B3E98 00008C8D */  lw         $t4, 0x0($t4)
    /* 4B69C 800B3E9C 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4B6A0 800B3EA0 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4B6A4 800B3EA4 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4B6A8 800B3EA8 0000CE8D */  lw         $t6, 0x0($t6)
    /* 4B6AC 800B3EAC 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4B6B0 800B3EB0 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4B6B4 800B3EB4 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4B6B8 800B3EB8 025C0F00 */  srl        $t3, $t7, 16
    /* 4B6BC 800B3EBC 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4B6C0 800B3EC0 0600404B */  nclip
    /* 4B6C4 800B3EC4 20401E01 */  add        $t0, $t0, $fp /* handwritten instruction */
    /* 4B6C8 800B3EC8 20483E01 */  add        $t1, $t1, $fp /* handwritten instruction */
    /* 4B6CC 800B3ECC 20505E01 */  add        $t2, $t2, $fp /* handwritten instruction */
    /* 4B6D0 800B3ED0 0000088D */  lw         $t0, 0x0($t0)
    /* 4B6D4 800B3ED4 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4B6D8 800B3ED8 20587E01 */  add        $t3, $t3, $fp /* handwritten instruction */
    /* 4B6DC 800B3EDC 0500401C */  bgtz       $v0, .L800B3EF4
    /* 4B6E0 800B3EE0 FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4B6E4 800B3EE4 2C006012 */  beqz       $s3, .L800B3F98
    /* 4B6E8 800B3EE8 14005226 */   addiu     $s2, $s2, 0x14
    /* 4B6EC 800B3EEC A1CF0208 */  j          .L800B3E84
    /* 4B6F0 800B3EF0 04004B8E */   lw        $t3, 0x4($s2)
  .L800B3EF4:
    /* 4B6F4 800B3EF4 0000298D */  lw         $t1, 0x0($t1)
    /* 4B6F8 800B3EF8 00004A8D */  lw         $t2, 0x0($t2)
    /* 4B6FC 800B3EFC 00006B8D */  lw         $t3, 0x0($t3)
    /* 4B700 800B3F00 20100901 */  add        $v0, $t0, $t1 /* handwritten instruction */
    /* 4B704 800B3F04 0000EF8D */  lw         $t7, 0x0($t7)
    /* 4B708 800B3F08 20104A00 */  add        $v0, $v0, $t2 /* handwritten instruction */
    /* 4B70C 800B3F0C 0C00488E */  lw         $t0, 0xC($s2)
    /* 4B710 800B3F10 10004A8E */  lw         $t2, 0x10($s2)
    /* 4B714 800B3F14 024C0800 */  srl        $t1, $t0, 16
    /* 4B718 800B3F18 25483F01 */  or         $t1, $t1, $ra
    /* 4B71C 800B3F1C FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4B720 800B3F20 25401C01 */  or         $t0, $t0, $gp
    /* 4B724 800B3F24 040023AE */  sw         $v1, 0x4($s1)
    /* 4B728 800B3F28 08002CAE */  sw         $t4, 0x8($s1)
    /* 4B72C 800B3F2C 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4B730 800B3F30 10002DAE */  sw         $t5, 0x10($s1)
    /* 4B734 800B3F34 20104B00 */  add        $v0, $v0, $t3 /* handwritten instruction */
    /* 4B738 800B3F38 140029AE */  sw         $t1, 0x14($s1)
    /* 4B73C 800B3F3C 025C0A00 */  srl        $t3, $t2, 16
    /* 4B740 800B3F40 18002EAE */  sw         $t6, 0x18($s1)
    /* 4B744 800B3F44 02110200 */  srl        $v0, $v0, 4
    /* 4B748 800B3F48 1C002AAE */  sw         $t2, 0x1C($s1)
    /* 4B74C 800B3F4C C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4B750 800B3F50 0D000011 */  beqz       $t0, .L800B3F88
    /* 4B754 800B3F54 80100200 */   sll       $v0, $v0, 2
    /* 4B758 800B3F58 20002FAE */  sw         $t7, 0x20($s1)
    /* 4B75C 800B3F5C 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4B760 800B3F60 24002BAE */  sw         $t3, 0x24($s1)
    /* 4B764 800B3F64 00004A8C */  lw         $t2, 0x0($v0)
    /* 4B768 800B3F68 24483402 */  and        $t1, $s1, $s4
    /* 4B76C 800B3F6C 24405401 */  and        $t0, $t2, $s4
    /* 4B770 800B3F70 25401801 */  or         $t0, $t0, $t8
    /* 4B774 800B3F74 000028AE */  sw         $t0, 0x0($s1)
    /* 4B778 800B3F78 24405501 */  and        $t0, $t2, $s5
    /* 4B77C 800B3F7C 25400901 */  or         $t0, $t0, $t1
    /* 4B780 800B3F80 000048AC */  sw         $t0, 0x0($v0)
    /* 4B784 800B3F84 28003126 */  addiu      $s1, $s1, 0x28
  .L800B3F88:
    /* 4B788 800B3F88 03006012 */  beqz       $s3, .L800B3F98
    /* 4B78C 800B3F8C 14005226 */   addiu     $s2, $s2, 0x14
    /* 4B790 800B3F90 A1CF0208 */  j          .L800B3E84
    /* 4B794 800B3F94 04004B8E */   lw        $t3, 0x4($s2)
  .L800B3F98:
    /* 4B798 800B3F98 0600B394 */  lhu        $s3, 0x6($a1)
    /* 4B79C 800B3F9C F0FFF722 */  addi       $s7, $s7, -0x10 /* handwritten instruction */
    /* 4B7A0 800B3FA0 6E016012 */  beqz       $s3, .L800B455C
    /* 4B7A4 800B3FA4 2528C003 */   or        $a1, $fp, $zero
    /* 4B7A8 800B3FA8 00005E8E */  lw         $fp, 0x0($s2)
  .L800B3FAC:
    /* 4B7AC 800B3FAC 04004B8E */  lw         $t3, 0x4($s2)
    /* 4B7B0 800B3FB0 021C1E00 */  srl        $v1, $fp, 16
    /* 4B7B4 800B3FB4 01006230 */  andi       $v0, $v1, 0x1
    /* 4B7B8 800B3FB8 08004F8E */  lw         $t7, 0x8($s2)
    /* 4B7BC 800B3FBC FFFF6831 */  andi       $t0, $t3, 0xFFFF
    /* 4B7C0 800B3FC0 024C0B00 */  srl        $t1, $t3, 16
    /* 4B7C4 800B3FC4 FFFFEA31 */  andi       $t2, $t7, 0xFFFF
    /* 4B7C8 800B3FC8 20600401 */  add        $t4, $t0, $a0 /* handwritten instruction */
    /* 4B7CC 800B3FCC 00008C8D */  lw         $t4, 0x0($t4)
    /* 4B7D0 800B3FD0 20682401 */  add        $t5, $t1, $a0 /* handwritten instruction */
    /* 4B7D4 800B3FD4 0000AD8D */  lw         $t5, 0x0($t5)
    /* 4B7D8 800B3FD8 20704401 */  add        $t6, $t2, $a0 /* handwritten instruction */
    /* 4B7DC 800B3FDC 16004014 */  bnez       $v0, .L800B4038
    /* 4B7E0 800B3FE0 0000CE8D */   lw        $t6, 0x0($t6)
    /* 4B7E4 800B3FE4 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4B7E8 800B3FE8 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4B7EC 800B3FEC 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4B7F0 800B3FF0 025C0F00 */  srl        $t3, $t7, 16
    /* 4B7F4 800B3FF4 25806001 */  or         $s0, $t3, $zero
    /* 4B7F8 800B3FF8 0600404B */  nclip
    /* 4B7FC 800B3FFC 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4B800 800B4000 20400501 */  add        $t0, $t0, $a1 /* handwritten instruction */
    /* 4B804 800B4004 20482501 */  add        $t1, $t1, $a1 /* handwritten instruction */
    /* 4B808 800B4008 20504501 */  add        $t2, $t2, $a1 /* handwritten instruction */
    /* 4B80C 800B400C 20586501 */  add        $t3, $t3, $a1 /* handwritten instruction */
    /* 4B810 800B4010 FF00D833 */  andi       $t8, $fp, 0xFF
    /* 4B814 800B4014 021A1E00 */  srl        $v1, $fp, 8
    /* 4B818 800B4018 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4B81C 800B401C FF006330 */  andi       $v1, $v1, 0xFF
    /* 4B820 800B4020 1100401C */  bgtz       $v0, .L800B4068
    /* 4B824 800B4024 FFFF7326 */   addiu     $s3, $s3, -0x1
    /* 4B828 800B4028 4C016012 */  beqz       $s3, .L800B455C
    /* 4B82C 800B402C 20904302 */   add       $s2, $s2, $v1 /* handwritten instruction */
    /* 4B830 800B4030 EBCF0208 */  j          .L800B3FAC
    /* 4B834 800B4034 00005E8E */   lw        $fp, 0x0($s2)
  .L800B4038:
    /* 4B838 800B4038 FFFF7326 */  addiu      $s3, $s3, -0x1
    /* 4B83C 800B403C 025C0F00 */  srl        $t3, $t7, 16
    /* 4B840 800B4040 25806001 */  or         $s0, $t3, $zero
    /* 4B844 800B4044 20788B00 */  add        $t7, $a0, $t3 /* handwritten instruction */
    /* 4B848 800B4048 20400501 */  add        $t0, $t0, $a1 /* handwritten instruction */
    /* 4B84C 800B404C 20482501 */  add        $t1, $t1, $a1 /* handwritten instruction */
    /* 4B850 800B4050 20504501 */  add        $t2, $t2, $a1 /* handwritten instruction */
    /* 4B854 800B4054 20586501 */  add        $t3, $t3, $a1 /* handwritten instruction */
    /* 4B858 800B4058 02CA1E00 */  srl        $t9, $fp, 8
    /* 4B85C 800B405C 02006330 */  andi       $v1, $v1, 0x2
    /* 4B860 800B4060 6D006014 */  bnez       $v1, .L800B4218
    /* 4B864 800B4064 FF00D833 */   andi      $t8, $fp, 0xFF
  .L800B4068:
    /* 4B868 800B4068 0000088D */  lw         $t0, 0x0($t0)
    /* 4B86C 800B406C 2C000234 */  ori        $v0, $zero, 0x2C
    /* 4B870 800B4070 0000298D */  lw         $t1, 0x0($t1)
    /* 4B874 800B4074 32000213 */  beq        $t8, $v0, .L800B4140
    /* 4B878 800B4078 00004A8D */   lw        $t2, 0x0($t2)
    /* 4B87C 800B407C 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4B880 800B4080 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4B884 800B4084 00988A48 */  mtc2       $t2, $19 /* handwritten instruction */
    /* 4B888 800B4088 02551E00 */  srl        $t2, $fp, 20
    /* 4B88C 800B408C 01004A31 */  andi       $t2, $t2, 0x1
    /* 4B890 800B4090 40560A00 */  sll        $t2, $t2, 25
    /* 4B894 800B4094 0024033C */  lui        $v1, (0x24000000 >> 16)
    /* 4B898 800B4098 25186A00 */  or         $v1, $v1, $t2
    /* 4B89C 800B409C 25186600 */  or         $v1, $v1, $a2
    /* 4B8A0 800B40A0 2D00584B */  avsz3
    /* 4B8A4 800B40A4 02541E00 */  srl        $t2, $fp, 16
    /* 4B8A8 800B40A8 60004A31 */  andi       $t2, $t2, 0x60
    /* 4B8AC 800B40AC 00540A00 */  sll        $t2, $t2, 16
    /* 4B8B0 800B40B0 0C00488E */  lw         $t0, 0xC($s2)
    /* 4B8B4 800B40B4 040023AE */  sw         $v1, 0x4($s1)
    /* 4B8B8 800B40B8 024C0800 */  srl        $t1, $t0, 16
    /* 4B8BC 800B40BC 25483F01 */  or         $t1, $t1, $ra
    /* 4B8C0 800B40C0 25482A01 */  or         $t1, $t1, $t2
    /* 4B8C4 800B40C4 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4B8C8 800B40C8 25401C01 */  or         $t0, $t0, $gp
    /* 4B8CC 800B40CC 08002CAE */  sw         $t4, 0x8($s1)
    /* 4B8D0 800B40D0 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4B8D4 800B40D4 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4B8D8 800B40D8 10002DAE */  sw         $t5, 0x10($s1)
    /* 4B8DC 800B40DC 821C1E00 */  srl        $v1, $fp, 18
    /* 4B8E0 800B40E0 140029AE */  sw         $t1, 0x14($s1)
    /* 4B8E4 800B40E4 03006330 */  andi       $v1, $v1, 0x3
    /* 4B8E8 800B40E8 18002EAE */  sw         $t6, 0x18($s1)
    /* 4B8EC 800B40EC 80180300 */  sll        $v1, $v1, 2
    /* 4B8F0 800B40F0 1C0030AE */  sw         $s0, 0x1C($s1)
    /* 4B8F4 800B40F4 20104300 */  add        $v0, $v0, $v1 /* handwritten instruction */
    /* 4B8F8 800B40F8 C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4B8FC 800B40FC 0C000011 */  beqz       $t0, .L800B4130
    /* 4B900 800B4100 80100200 */   sll       $v0, $v0, 2
    /* 4B904 800B4104 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4B908 800B4108 0000438C */  lw         $v1, 0x0($v0)
    /* 4B90C 800B410C 0007183C */  lui        $t8, (0x7000000 >> 16)
    /* 4B910 800B4110 24407400 */  and        $t0, $v1, $s4
    /* 4B914 800B4114 25401801 */  or         $t0, $t0, $t8
    /* 4B918 800B4118 000028AE */  sw         $t0, 0x0($s1)
    /* 4B91C 800B411C 24483402 */  and        $t1, $s1, $s4
    /* 4B920 800B4120 24407500 */  and        $t0, $v1, $s5
    /* 4B924 800B4124 25400901 */  or         $t0, $t0, $t1
    /* 4B928 800B4128 000048AC */  sw         $t0, 0x0($v0)
    /* 4B92C 800B412C 20003126 */  addiu      $s1, $s1, 0x20
  .L800B4130:
    /* 4B930 800B4130 0A016012 */  beqz       $s3, .L800B455C
    /* 4B934 800B4134 10005226 */   addiu     $s2, $s2, 0x10
    /* 4B938 800B4138 EBCF0208 */  j          .L800B3FAC
    /* 4B93C 800B413C 00005E8E */   lw        $fp, 0x0($s2)
  .L800B4140:
    /* 4B940 800B4140 00006B8D */  lw         $t3, 0x0($t3)
    /* 4B944 800B4144 20100901 */  add        $v0, $t0, $t1 /* handwritten instruction */
    /* 4B948 800B4148 0000EF8D */  lw         $t7, 0x0($t7)
    /* 4B94C 800B414C 20104A00 */  add        $v0, $v0, $t2 /* handwritten instruction */
    /* 4B950 800B4150 0C00488E */  lw         $t0, 0xC($s2)
    /* 4B954 800B4154 10004A8E */  lw         $t2, 0x10($s2)
    /* 4B958 800B4158 024C0800 */  srl        $t1, $t0, 16
    /* 4B95C 800B415C 25483F01 */  or         $t1, $t1, $ra
    /* 4B960 800B4160 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4B964 800B4164 25401C01 */  or         $t0, $t0, $gp
    /* 4B968 800B4168 02C51E00 */  srl        $t8, $fp, 20
    /* 4B96C 800B416C 01001833 */  andi       $t8, $t8, 0x1
    /* 4B970 800B4170 40C61800 */  sll        $t8, $t8, 25
    /* 4B974 800B4174 002C033C */  lui        $v1, (0x2C000000 >> 16)
    /* 4B978 800B4178 25187800 */  or         $v1, $v1, $t8
    /* 4B97C 800B417C 25186600 */  or         $v1, $v1, $a2
    /* 4B980 800B4180 040023AE */  sw         $v1, 0x4($s1)
    /* 4B984 800B4184 08002CAE */  sw         $t4, 0x8($s1)
    /* 4B988 800B4188 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4B98C 800B418C 02C41E00 */  srl        $t8, $fp, 16
    /* 4B990 800B4190 60001833 */  andi       $t8, $t8, 0x60
    /* 4B994 800B4194 00C41800 */  sll        $t8, $t8, 16
    /* 4B998 800B4198 10002DAE */  sw         $t5, 0x10($s1)
    /* 4B99C 800B419C 20104B00 */  add        $v0, $v0, $t3 /* handwritten instruction */
    /* 4B9A0 800B41A0 25483801 */  or         $t1, $t1, $t8
    /* 4B9A4 800B41A4 140029AE */  sw         $t1, 0x14($s1)
    /* 4B9A8 800B41A8 025C0A00 */  srl        $t3, $t2, 16
    /* 4B9AC 800B41AC 18002EAE */  sw         $t6, 0x18($s1)
    /* 4B9B0 800B41B0 02110200 */  srl        $v0, $v0, 4
    /* 4B9B4 800B41B4 1C002AAE */  sw         $t2, 0x1C($s1)
    /* 4B9B8 800B41B8 821C1E00 */  srl        $v1, $fp, 18
    /* 4B9BC 800B41BC 20002FAE */  sw         $t7, 0x20($s1)
    /* 4B9C0 800B41C0 03006330 */  andi       $v1, $v1, 0x3
    /* 4B9C4 800B41C4 24002BAE */  sw         $t3, 0x24($s1)
    /* 4B9C8 800B41C8 80180300 */  sll        $v1, $v1, 2
    /* 4B9CC 800B41CC 20104300 */  add        $v0, $v0, $v1 /* handwritten instruction */
    /* 4B9D0 800B41D0 C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4B9D4 800B41D4 0C000011 */  beqz       $t0, .L800B4208
    /* 4B9D8 800B41D8 80100200 */   sll       $v0, $v0, 2
    /* 4B9DC 800B41DC 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4B9E0 800B41E0 0000438C */  lw         $v1, 0x0($v0)
    /* 4B9E4 800B41E4 0009183C */  lui        $t8, (0x9000000 >> 16)
    /* 4B9E8 800B41E8 24407400 */  and        $t0, $v1, $s4
    /* 4B9EC 800B41EC 25401801 */  or         $t0, $t0, $t8
    /* 4B9F0 800B41F0 000028AE */  sw         $t0, 0x0($s1)
    /* 4B9F4 800B41F4 24483402 */  and        $t1, $s1, $s4
    /* 4B9F8 800B41F8 24407500 */  and        $t0, $v1, $s5
    /* 4B9FC 800B41FC 25400901 */  or         $t0, $t0, $t1
    /* 4BA00 800B4200 000048AC */  sw         $t0, 0x0($v0)
    /* 4BA04 800B4204 28003126 */  addiu      $s1, $s1, 0x28
  .L800B4208:
    /* 4BA08 800B4208 D4006012 */  beqz       $s3, .L800B455C
    /* 4BA0C 800B420C 14005226 */   addiu     $s2, $s2, 0x14
    /* 4BA10 800B4210 EBCF0208 */  j          .L800B3FAC
    /* 4BA14 800B4214 00005E8E */   lw        $fp, 0x0($s2)
  .L800B4218:
    /* 4BA18 800B4218 0000088D */  lw         $t0, 0x0($t0)
    /* 4BA1C 800B421C 0000298D */  lw         $t1, 0x0($t1)
    /* 4BA20 800B4220 00004A8D */  lw         $t2, 0x0($t2)
    /* 4BA24 800B4224 00140C00 */  sll        $v0, $t4, 16
    /* 4BA28 800B4228 001C0E00 */  sll        $v1, $t6, 16
    /* 4BA2C 800B422C 03140200 */  sra        $v0, $v0, 16
    /* 4BA30 800B4230 031C0300 */  sra        $v1, $v1, 16
    /* 4BA34 800B4234 23C06200 */  subu       $t8, $v1, $v0
    /* 4BA38 800B4238 0000D848 */  ctc2       $t8, $0 /* handwritten instruction */
    /* 4BA3C 800B423C 03840C00 */  sra        $s0, $t4, 16
    /* 4BA40 800B4240 031C0E00 */  sra        $v1, $t6, 16
    /* 4BA44 800B4244 23C07000 */  subu       $t8, $v1, $s0
    /* 4BA48 800B4248 0010D848 */  ctc2       $t8, $2 /* handwritten instruction */
    /* 4BA4C 800B424C 23804801 */  subu       $s0, $t2, $t0
    /* 4BA50 800B4250 0020D048 */  ctc2       $s0, $4 /* handwritten instruction */
    /* 4BA54 800B4254 23802801 */  subu       $s0, $t1, $t0
    /* 4BA58 800B4258 00589048 */  mtc2       $s0, $11 /* handwritten instruction */
    /* 4BA5C 800B425C 001C0D00 */  sll        $v1, $t5, 16
    /* 4BA60 800B4260 031C0300 */  sra        $v1, $v1, 16
    /* 4BA64 800B4264 23C06200 */  subu       $t8, $v1, $v0
    /* 4BA68 800B4268 00489848 */  mtc2       $t8, $9 /* handwritten instruction */
    /* 4BA6C 800B426C 03840C00 */  sra        $s0, $t4, 16
    /* 4BA70 800B4270 031C0D00 */  sra        $v1, $t5, 16
    /* 4BA74 800B4274 23C07000 */  subu       $t8, $v1, $s0
    /* 4BA78 800B4278 00509848 */  mtc2       $t8, $10 /* handwritten instruction */
    /* 4BA7C 800B427C 00000000 */  nop
    /* 4BA80 800B4280 0C00704B */  op         0
    /* 4BA84 800B4284 0000EF8D */  lw         $t7, 0x0($t7)
    /* 4BA88 800B4288 00C81648 */  mfc2       $s6, $25 /* handwritten instruction */
    /* 4BA8C 800B428C 001C0F00 */  sll        $v1, $t7, 16
    /* 4BA90 800B4290 031C0300 */  sra        $v1, $v1, 16
    /* 4BA94 800B4294 23C06200 */  subu       $t8, $v1, $v0
    /* 4BA98 800B4298 19001603 */  multu      $t8, $s6
    /* 4BA9C 800B429C 031C0F00 */  sra        $v1, $t7, 16
    /* 4BAA0 800B42A0 12C00000 */  mflo       $t8
    /* 4BAA4 800B42A4 00D00248 */  mfc2       $v0, $26 /* handwritten instruction */
    /* 4BAA8 800B42A8 23B07000 */  subu       $s6, $v1, $s0
    /* 4BAAC 800B42AC 1900C202 */  multu      $s6, $v0
    /* 4BAB0 800B42B0 00006B8D */  lw         $t3, 0x0($t3)
    /* 4BAB4 800B42B4 12B00000 */  mflo       $s6
    /* 4BAB8 800B42B8 00D80248 */  mfc2       $v0, $27 /* handwritten instruction */
    /* 4BABC 800B42BC 23186801 */  subu       $v1, $t3, $t0
    /* 4BAC0 800B42C0 19004300 */  multu      $v0, $v1
    /* 4BAC4 800B42C4 20C01603 */  add        $t8, $t8, $s6 /* handwritten instruction */
    /* 4BAC8 800B42C8 00608C48 */  mtc2       $t4, $12 /* handwritten instruction */
    /* 4BACC 800B42CC 00688D48 */  mtc2       $t5, $13 /* handwritten instruction */
    /* 4BAD0 800B42D0 12100000 */  mflo       $v0
    /* 4BAD4 800B42D4 20100203 */  add        $v0, $t8, $v0 /* handwritten instruction */
    /* 4BAD8 800B42D8 23100200 */  negu       $v0, $v0
    /* 4BADC 800B42DC 4F00401C */  bgtz       $v0, .L800B441C
    /* 4BAE0 800B42E0 00000000 */   nop
    /* 4BAE4 800B42E4 00708F48 */  mtc2       $t7, $14 /* handwritten instruction */
    /* 4BAE8 800B42E8 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4BAEC 800B42EC 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4BAF0 800B42F0 0600404B */  nclip
    /* 4BAF4 800B42F4 00988B48 */  mtc2       $t3, $19 /* handwritten instruction */
    /* 4BAF8 800B42F8 0C00488E */  lw         $t0, 0xC($s2)
    /* 4BAFC 800B42FC 1000568E */  lw         $s6, 0x10($s2)
    /* 4BB00 800B4300 024C0800 */  srl        $t1, $t0, 16
    /* 4BB04 800B4304 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4BB08 800B4308 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4BB0C 800B430C 1D004018 */  blez       $v0, .L800B4384
    /* 4BB10 800B4310 25401C01 */   or        $t0, $t0, $gp
    /* 4BB14 800B4314 2D00584B */  avsz3
    /* 4BB18 800B4318 0024033C */  lui        $v1, (0x24000000 >> 16)
    /* 4BB1C 800B431C 25186600 */  or         $v1, $v1, $a2
    /* 4BB20 800B4320 040023AE */  sw         $v1, 0x4($s1)
    /* 4BB24 800B4324 08002CAE */  sw         $t4, 0x8($s1)
    /* 4BB28 800B4328 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4BB2C 800B432C 10002DAE */  sw         $t5, 0x10($s1)
    /* 4BB30 800B4330 25483F01 */  or         $t1, $t1, $ra
    /* 4BB34 800B4334 140029AE */  sw         $t1, 0x14($s1)
    /* 4BB38 800B4338 025C1600 */  srl        $t3, $s6, 16
    /* 4BB3C 800B433C 18002FAE */  sw         $t7, 0x18($s1)
    /* 4BB40 800B4340 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4BB44 800B4344 1C002BAE */  sw         $t3, 0x1C($s1)
    /* 4BB48 800B4348 04004224 */  addiu      $v0, $v0, 0x4
    /* 4BB4C 800B434C C007502C */  sltiu      $s0, $v0, 0x7C0
    /* 4BB50 800B4350 0C000012 */  beqz       $s0, .L800B4384
    /* 4BB54 800B4354 80100200 */   sll       $v0, $v0, 2
    /* 4BB58 800B4358 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4BB5C 800B435C 0000438C */  lw         $v1, 0x0($v0)
    /* 4BB60 800B4360 0007183C */  lui        $t8, (0x7000000 >> 16)
    /* 4BB64 800B4364 24807400 */  and        $s0, $v1, $s4
    /* 4BB68 800B4368 25801802 */  or         $s0, $s0, $t8
    /* 4BB6C 800B436C 000030AE */  sw         $s0, 0x0($s1)
    /* 4BB70 800B4370 24483402 */  and        $t1, $s1, $s4
    /* 4BB74 800B4374 24807500 */  and        $s0, $v1, $s5
    /* 4BB78 800B4378 25800902 */  or         $s0, $s0, $t1
    /* 4BB7C 800B437C 000050AC */  sw         $s0, 0x0($v0)
    /* 4BB80 800B4380 20003126 */  addiu      $s1, $s1, 0x20
  .L800B4384:
    /* 4BB84 800B4384 00688F48 */  mtc2       $t7, $13 /* handwritten instruction */
    /* 4BB88 800B4388 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4BB8C 800B438C 00908A48 */  mtc2       $t2, $18 /* handwritten instruction */
    /* 4BB90 800B4390 0024033C */  lui        $v1, (0x24000000 >> 16)
    /* 4BB94 800B4394 0600404B */  nclip
    /* 4BB98 800B4398 25186600 */  or         $v1, $v1, $a2
    /* 4BB9C 800B439C 025C1600 */  srl        $t3, $s6, 16
    /* 4BBA0 800B43A0 25587F01 */  or         $t3, $t3, $ra
    /* 4BBA4 800B43A4 040023AE */  sw         $v1, 0x4($s1)
    /* 4BBA8 800B43A8 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4BBAC 800B43AC 08002CAE */  sw         $t4, 0x8($s1)
    /* 4BBB0 800B43B0 15004018 */  blez       $v0, .L800B4408
    /* 4BBB4 800B43B4 0C0028AE */   sw        $t0, 0xC($s1)
    /* 4BBB8 800B43B8 2D00584B */  avsz3
    /* 4BBBC 800B43BC 10002FAE */  sw         $t7, 0x10($s1)
    /* 4BBC0 800B43C0 14002BAE */  sw         $t3, 0x14($s1)
    /* 4BBC4 800B43C4 18002EAE */  sw         $t6, 0x18($s1)
    /* 4BBC8 800B43C8 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4BBCC 800B43CC 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 4BBD0 800B43D0 04004224 */  addiu      $v0, $v0, 0x4
    /* 4BBD4 800B43D4 C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4BBD8 800B43D8 0C000011 */  beqz       $t0, .L800B440C
    /* 4BBDC 800B43DC 80100200 */   sll       $v0, $v0, 2
    /* 4BBE0 800B43E0 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4BBE4 800B43E4 0000438C */  lw         $v1, 0x0($v0)
    /* 4BBE8 800B43E8 0007183C */  lui        $t8, (0x7000000 >> 16)
    /* 4BBEC 800B43EC 24407400 */  and        $t0, $v1, $s4
    /* 4BBF0 800B43F0 25401801 */  or         $t0, $t0, $t8
    /* 4BBF4 800B43F4 000028AE */  sw         $t0, 0x0($s1)
    /* 4BBF8 800B43F8 24483402 */  and        $t1, $s1, $s4
    /* 4BBFC 800B43FC 24407500 */  and        $t0, $v1, $s5
    /* 4BC00 800B4400 25400901 */  or         $t0, $t0, $t1
    /* 4BC04 800B4404 000048AC */  sw         $t0, 0x0($v0)
  .L800B4408:
    /* 4BC08 800B4408 20003126 */  addiu      $s1, $s1, 0x20
  .L800B440C:
    /* 4BC0C 800B440C 53006012 */  beqz       $s3, .L800B455C
    /* 4BC10 800B4410 14005226 */   addiu     $s2, $s2, 0x14
    /* 4BC14 800B4414 EBCF0208 */  j          .L800B3FAC
    /* 4BC18 800B4418 00005E8E */   lw        $fp, 0x0($s2)
  .L800B441C:
    /* 4BC1C 800B441C 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4BC20 800B4420 00888848 */  mtc2       $t0, $17 /* handwritten instruction */
    /* 4BC24 800B4424 00908948 */  mtc2       $t1, $18 /* handwritten instruction */
    /* 4BC28 800B4428 0600404B */  nclip
    /* 4BC2C 800B442C 00988A48 */  mtc2       $t2, $19 /* handwritten instruction */
    /* 4BC30 800B4430 0C00488E */  lw         $t0, 0xC($s2)
    /* 4BC34 800B4434 1000568E */  lw         $s6, 0x10($s2)
    /* 4BC38 800B4438 024C0800 */  srl        $t1, $t0, 16
    /* 4BC3C 800B443C 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4BC40 800B4440 0024033C */  lui        $v1, (0x24000000 >> 16)
    /* 4BC44 800B4444 1C004018 */  blez       $v0, .L800B44B8
    /* 4BC48 800B4448 25186600 */   or        $v1, $v1, $a2
    /* 4BC4C 800B444C 2D00584B */  avsz3
    /* 4BC50 800B4450 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4BC54 800B4454 040023AE */  sw         $v1, 0x4($s1)
    /* 4BC58 800B4458 08002CAE */  sw         $t4, 0x8($s1)
    /* 4BC5C 800B445C FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 4BC60 800B4460 25401C01 */  or         $t0, $t0, $gp
    /* 4BC64 800B4464 0C0028AE */  sw         $t0, 0xC($s1)
    /* 4BC68 800B4468 10002DAE */  sw         $t5, 0x10($s1)
    /* 4BC6C 800B446C 25483F01 */  or         $t1, $t1, $ra
    /* 4BC70 800B4470 140029AE */  sw         $t1, 0x14($s1)
    /* 4BC74 800B4474 04004224 */  addiu      $v0, $v0, 0x4
    /* 4BC78 800B4478 18002EAE */  sw         $t6, 0x18($s1)
    /* 4BC7C 800B447C C007502C */  sltiu      $s0, $v0, 0x7C0
    /* 4BC80 800B4480 0D000012 */  beqz       $s0, .L800B44B8
    /* 4BC84 800B4484 80100200 */   sll       $v0, $v0, 2
    /* 4BC88 800B4488 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 4BC8C 800B448C 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4BC90 800B4490 0000438C */  lw         $v1, 0x0($v0)
    /* 4BC94 800B4494 0007183C */  lui        $t8, (0x7000000 >> 16)
    /* 4BC98 800B4498 24807400 */  and        $s0, $v1, $s4
    /* 4BC9C 800B449C 25801802 */  or         $s0, $s0, $t8
    /* 4BCA0 800B44A0 000030AE */  sw         $s0, 0x0($s1)
    /* 4BCA4 800B44A4 24403402 */  and        $t0, $s1, $s4
    /* 4BCA8 800B44A8 24807500 */  and        $s0, $v1, $s5
    /* 4BCAC 800B44AC 25800802 */  or         $s0, $s0, $t0
    /* 4BCB0 800B44B0 000050AC */  sw         $s0, 0x0($v0)
    /* 4BCB4 800B44B4 20003126 */  addiu      $s1, $s1, 0x20
  .L800B44B8:
    /* 4BCB8 800B44B8 00608D48 */  mtc2       $t5, $12 /* handwritten instruction */
    /* 4BCBC 800B44BC 00688F48 */  mtc2       $t7, $13 /* handwritten instruction */
    /* 4BCC0 800B44C0 00708E48 */  mtc2       $t6, $14 /* handwritten instruction */
    /* 4BCC4 800B44C4 00888B48 */  mtc2       $t3, $17 /* handwritten instruction */
    /* 4BCC8 800B44C8 0024033C */  lui        $v1, (0x24000000 >> 16)
    /* 4BCCC 800B44CC 0600404B */  nclip
    /* 4BCD0 800B44D0 25186600 */  or         $v1, $v1, $a2
    /* 4BCD4 800B44D4 040023AE */  sw         $v1, 0x4($s1)
    /* 4BCD8 800B44D8 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 4BCDC 800B44DC 25483C01 */  or         $t1, $t1, $gp
    /* 4BCE0 800B44E0 00C00248 */  mfc2       $v0, $24 /* handwritten instruction */
    /* 4BCE4 800B44E4 025C1600 */  srl        $t3, $s6, 16
    /* 4BCE8 800B44E8 18004018 */  blez       $v0, .L800B454C
    /* 4BCEC 800B44EC 25587F01 */   or        $t3, $t3, $ra
    /* 4BCF0 800B44F0 2D00584B */  avsz3
    /* 4BCF4 800B44F4 08002DAE */  sw         $t5, 0x8($s1)
    /* 4BCF8 800B44F8 0C0029AE */  sw         $t1, 0xC($s1)
    /* 4BCFC 800B44FC 10002FAE */  sw         $t7, 0x10($s1)
    /* 4BD00 800B4500 14002BAE */  sw         $t3, 0x14($s1)
    /* 4BD04 800B4504 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 4BD08 800B4508 18002EAE */  sw         $t6, 0x18($s1)
    /* 4BD0C 800B450C 04004224 */  addiu      $v0, $v0, 0x4
    /* 4BD10 800B4510 1C0036AE */  sw         $s6, 0x1C($s1)
    /* 4BD14 800B4514 C007482C */  sltiu      $t0, $v0, 0x7C0
    /* 4BD18 800B4518 0C000011 */  beqz       $t0, .L800B454C
    /* 4BD1C 800B451C 80100200 */   sll       $v0, $v0, 2
    /* 4BD20 800B4520 2010E202 */  add        $v0, $s7, $v0 /* handwritten instruction */
    /* 4BD24 800B4524 0000438C */  lw         $v1, 0x0($v0)
    /* 4BD28 800B4528 0007183C */  lui        $t8, (0x7000000 >> 16)
    /* 4BD2C 800B452C 24407400 */  and        $t0, $v1, $s4
    /* 4BD30 800B4530 25401801 */  or         $t0, $t0, $t8
    /* 4BD34 800B4534 000028AE */  sw         $t0, 0x0($s1)
    /* 4BD38 800B4538 24483402 */  and        $t1, $s1, $s4
    /* 4BD3C 800B453C 24407500 */  and        $t0, $v1, $s5
    /* 4BD40 800B4540 25400901 */  or         $t0, $t0, $t1
    /* 4BD44 800B4544 000048AC */  sw         $t0, 0x0($v0)
    /* 4BD48 800B4548 20003126 */  addiu      $s1, $s1, 0x20
  .L800B454C:
    /* 4BD4C 800B454C 03006012 */  beqz       $s3, .L800B455C
    /* 4BD50 800B4550 14005226 */   addiu     $s2, $s2, 0x14
    /* 4BD54 800B4554 EBCF0208 */  j          .L800B3FAC
    /* 4BD58 800B4558 00005E8E */   lw        $fp, 0x0($s2)
  .L800B455C:
    /* 4BD5C 800B455C 801F083C */  lui        $t0, (0x1F800380 >> 16)
    /* 4BD60 800B4560 000011AD */  sw         $s1, (0x1F800000 & 0xFFFF)($t0)
    /* 4BD64 800B4564 5803108D */  lw         $s0, (0x1F800358 & 0xFFFF)($t0)
    /* 4BD68 800B4568 5C03118D */  lw         $s1, (0x1F80035C & 0xFFFF)($t0)
    /* 4BD6C 800B456C 6003128D */  lw         $s2, (0x1F800360 & 0xFFFF)($t0)
    /* 4BD70 800B4570 6403138D */  lw         $s3, (0x1F800364 & 0xFFFF)($t0)
    /* 4BD74 800B4574 6803148D */  lw         $s4, (0x1F800368 & 0xFFFF)($t0)
    /* 4BD78 800B4578 6C03158D */  lw         $s5, (0x1F80036C & 0xFFFF)($t0)
    /* 4BD7C 800B457C 7003168D */  lw         $s6, (0x1F800370 & 0xFFFF)($t0)
    /* 4BD80 800B4580 7403178D */  lw         $s7, (0x1F800374 & 0xFFFF)($t0)
    /* 4BD84 800B4584 78031F8D */  lw         $ra, (0x1F800378 & 0xFFFF)($t0)
    /* 4BD88 800B4588 7C031C8D */  lw         $gp, (0x1F80037C & 0xFFFF)($t0)
    /* 4BD8C 800B458C 0800E003 */  jr         $ra
    /* 4BD90 800B4590 80031E8D */   lw        $fp, (0x1F800380 & 0xFFFF)($t0)
endlabel func_800B3CF0
