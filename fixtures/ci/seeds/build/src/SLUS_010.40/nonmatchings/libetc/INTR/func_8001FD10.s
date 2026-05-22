nonmatching func_8001FD10, 0x148

glabel func_8001FD10
    /* 10510 8001FD10 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 10514 8001FD14 1400B1AF */  sw         $s1, 0x14($sp)
    /* 10518 8001FD18 21888000 */  addu       $s1, $a0, $zero
    /* 1051C 8001FD1C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 10520 8001FD20 2190A000 */  addu       $s2, $a1, $zero
    /* 10524 8001FD24 0380053C */  lui        $a1, %hi(D_80031050)
    /* 10528 8001FD28 5010A524 */  addiu      $a1, $a1, %lo(D_80031050)
    /* 1052C 8001FD2C 80101100 */  sll        $v0, $s1, 2
    /* 10530 8001FD30 21204500 */  addu       $a0, $v0, $a1
    /* 10534 8001FD34 2400BFAF */  sw         $ra, 0x24($sp)
    /* 10538 8001FD38 2000B4AF */  sw         $s4, 0x20($sp)
    /* 1053C 8001FD3C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 10540 8001FD40 1000B0AF */  sw         $s0, 0x10($sp)
    /* 10544 8001FD44 0000948C */  lw         $s4, 0x0($a0)
    /* 10548 8001FD48 00000000 */  nop
    /* 1054C 8001FD4C 3A005412 */  beq        $s2, $s4, .L8001FE38
    /* 10550 8001FD50 21108002 */   addu      $v0, $s4, $zero
    /* 10554 8001FD54 FCFFA294 */  lhu        $v0, -0x4($a1)
    /* 10558 8001FD58 00000000 */  nop
    /* 1055C 8001FD5C 35004010 */  beqz       $v0, .L8001FE34
    /* 10560 8001FD60 FCFFA624 */   addiu     $a2, $a1, -0x4
    /* 10564 8001FD64 0380023C */  lui        $v0, %hi(D_800320DC)
    /* 10568 8001FD68 DC20428C */  lw         $v0, %lo(D_800320DC)($v0)
    /* 1056C 8001FD6C 00000000 */  nop
    /* 10570 8001FD70 00004394 */  lhu        $v1, 0x0($v0)
    /* 10574 8001FD74 000040A4 */  sh         $zero, 0x0($v0)
    /* 10578 8001FD78 09004012 */  beqz       $s2, .L8001FDA0
    /* 1057C 8001FD7C FFFF7330 */   andi      $s3, $v1, 0xFFFF
    /* 10580 8001FD80 01000324 */  addiu      $v1, $zero, 0x1
    /* 10584 8001FD84 04182302 */  sllv       $v1, $v1, $s1
    /* 10588 8001FD88 000092AC */  sw         $s2, 0x0($a0)
    /* 1058C 8001FD8C 3000C294 */  lhu        $v0, 0x30($a2)
    /* 10590 8001FD90 25986302 */  or         $s3, $s3, $v1
    /* 10594 8001FD94 25104300 */  or         $v0, $v0, $v1
    /* 10598 8001FD98 707F0008 */  j          .L8001FDC0
    /* 1059C 8001FD9C 3000C2A4 */   sh        $v0, 0x30($a2)
  .L8001FDA0:
    /* 105A0 8001FDA0 01000224 */  addiu      $v0, $zero, 0x1
    /* 105A4 8001FDA4 04102202 */  sllv       $v0, $v0, $s1
    /* 105A8 8001FDA8 27100200 */  nor        $v0, $zero, $v0
    /* 105AC 8001FDAC 000080AC */  sw         $zero, 0x0($a0)
    /* 105B0 8001FDB0 2C00A394 */  lhu        $v1, 0x2C($a1)
    /* 105B4 8001FDB4 24986202 */  and        $s3, $s3, $v0
    /* 105B8 8001FDB8 24186200 */  and        $v1, $v1, $v0
    /* 105BC 8001FDBC 2C00A3A4 */  sh         $v1, 0x2C($a1)
  .L8001FDC0:
    /* 105C0 8001FDC0 08002016 */  bnez       $s1, .L8001FDE4
    /* 105C4 8001FDC4 04000224 */   addiu     $v0, $zero, 0x4
    /* 105C8 8001FDC8 0100502E */  sltiu      $s0, $s2, 0x1
    /* 105CC 8001FDCC 819A000C */  jal        ChangeClearPAD
    /* 105D0 8001FDD0 21200002 */   addu      $a0, $s0, $zero
    /* 105D4 8001FDD4 03000424 */  addiu      $a0, $zero, 0x3
    /* 105D8 8001FDD8 859A000C */  jal        ChangeClearRCnt
    /* 105DC 8001FDDC 21280002 */   addu      $a1, $s0, $zero
    /* 105E0 8001FDE0 04000224 */  addiu      $v0, $zero, 0x4
  .L8001FDE4:
    /* 105E4 8001FDE4 05002216 */  bne        $s1, $v0, .L8001FDFC
    /* 105E8 8001FDE8 05000224 */   addiu     $v0, $zero, 0x5
    /* 105EC 8001FDEC 21200000 */  addu       $a0, $zero, $zero
    /* 105F0 8001FDF0 859A000C */  jal        ChangeClearRCnt
    /* 105F4 8001FDF4 0100452E */   sltiu     $a1, $s2, 0x1
    /* 105F8 8001FDF8 05000224 */  addiu      $v0, $zero, 0x5
  .L8001FDFC:
    /* 105FC 8001FDFC 05002216 */  bne        $s1, $v0, .L8001FE14
    /* 10600 8001FE00 06000224 */   addiu     $v0, $zero, 0x6
    /* 10604 8001FE04 01000424 */  addiu      $a0, $zero, 0x1
    /* 10608 8001FE08 859A000C */  jal        ChangeClearRCnt
    /* 1060C 8001FE0C 0100452E */   sltiu     $a1, $s2, 0x1
    /* 10610 8001FE10 06000224 */  addiu      $v0, $zero, 0x6
  .L8001FE14:
    /* 10614 8001FE14 03002216 */  bne        $s1, $v0, .L8001FE24
    /* 10618 8001FE18 02000424 */   addiu     $a0, $zero, 0x2
    /* 1061C 8001FE1C 859A000C */  jal        ChangeClearRCnt
    /* 10620 8001FE20 0100452E */   sltiu     $a1, $s2, 0x1
  .L8001FE24:
    /* 10624 8001FE24 0380023C */  lui        $v0, %hi(D_800320DC)
    /* 10628 8001FE28 DC20428C */  lw         $v0, %lo(D_800320DC)($v0)
    /* 1062C 8001FE2C 00000000 */  nop
    /* 10630 8001FE30 000053A4 */  sh         $s3, 0x0($v0)
  .L8001FE34:
    /* 10634 8001FE34 21108002 */  addu       $v0, $s4, $zero
  .L8001FE38:
    /* 10638 8001FE38 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1063C 8001FE3C 2000B48F */  lw         $s4, 0x20($sp)
    /* 10640 8001FE40 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 10644 8001FE44 1800B28F */  lw         $s2, 0x18($sp)
    /* 10648 8001FE48 1400B18F */  lw         $s1, 0x14($sp)
    /* 1064C 8001FE4C 1000B08F */  lw         $s0, 0x10($sp)
    /* 10650 8001FE50 0800E003 */  jr         $ra
    /* 10654 8001FE54 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8001FD10
