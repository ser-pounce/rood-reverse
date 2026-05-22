nonmatching _copyTitleBgData, 0x1C4

glabel _copyTitleBgData
    /* 746C 8006FC6C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 7470 8006FC70 1800B0AF */  sw         $s0, 0x18($sp)
    /* 7474 8006FC74 21800000 */  addu       $s0, $zero, $zero
    /* 7478 8006FC78 0900043C */  lui        $a0, (0x99000 >> 16)
    /* 747C 8006FC7C 00908434 */  ori        $a0, $a0, (0x99000 & 0xFFFF)
    /* 7480 8006FC80 3000BFAF */  sw         $ra, 0x30($sp)
    /* 7484 8006FC84 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 7488 8006FC88 2800B4AF */  sw         $s4, 0x28($sp)
    /* 748C 8006FC8C 2400B3AF */  sw         $s3, 0x24($sp)
    /* 7490 8006FC90 2000B2AF */  sw         $s2, 0x20($sp)
    /* 7494 8006FC94 B10F010C */  jal        vs_main_allocHeap
    /* 7498 8006FC98 1C00B1AF */   sw        $s1, 0x1C($sp)
    /* 749C 8006FC9C 21884000 */  addu       $s1, $v0, $zero
    /* 74A0 8006FCA0 21282002 */  addu       $a1, $s1, $zero
    /* 74A4 8006FCA4 B4D90834 */  ori        $t0, $zero, 0xD9B4
    /* 74A8 8006FCA8 0780023C */  lui        $v0, %hi(D_80076AD4)
    /* 74AC 8006FCAC D46A4724 */  addiu      $a3, $v0, %lo(D_80076AD4)
    /* 74B0 8006FCB0 2130E000 */  addu       $a2, $a3, $zero
  .L8006FCB4:
    /* 74B4 8006FCB4 0000C28C */  lw         $v0, 0x0($a2)
    /* 74B8 8006FCB8 0400C624 */  addiu      $a2, $a2, 0x4
    /* 74BC 8006FCBC FFFF4330 */  andi       $v1, $v0, 0xFFFF
    /* 74C0 8006FCC0 05006010 */  beqz       $v1, .L8006FCD8
    /* 74C4 8006FCC4 01001026 */   addiu     $s0, $s0, 0x1
  .L8006FCC8:
    /* 74C8 8006FCC8 0000A0AC */  sw         $zero, 0x0($a1)
    /* 74CC 8006FCCC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 74D0 8006FCD0 FDFF6014 */  bnez       $v1, .L8006FCC8
    /* 74D4 8006FCD4 0400A524 */   addiu     $a1, $a1, 0x4
  .L8006FCD8:
    /* 74D8 8006FCD8 021C0200 */  srl        $v1, $v0, 16
    /* 74DC 8006FCDC 0C006010 */  beqz       $v1, .L8006FD10
    /* 74E0 8006FCE0 2B101001 */   sltu      $v0, $t0, $s0
    /* 74E4 8006FCE4 80101000 */  sll        $v0, $s0, 2
    /* 74E8 8006FCE8 21204700 */  addu       $a0, $v0, $a3
  .L8006FCEC:
    /* 74EC 8006FCEC 0000828C */  lw         $v0, 0x0($a0)
    /* 74F0 8006FCF0 04008424 */  addiu      $a0, $a0, 0x4
    /* 74F4 8006FCF4 0400C624 */  addiu      $a2, $a2, 0x4
    /* 74F8 8006FCF8 01001026 */  addiu      $s0, $s0, 0x1
    /* 74FC 8006FCFC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 7500 8006FD00 0000A2AC */  sw         $v0, 0x0($a1)
    /* 7504 8006FD04 F9FF6014 */  bnez       $v1, .L8006FCEC
    /* 7508 8006FD08 0400A524 */   addiu     $a1, $a1, 0x4
    /* 750C 8006FD0C 2B101001 */  sltu       $v0, $t0, $s0
  .L8006FD10:
    /* 7510 8006FD10 E8FF4010 */  beqz       $v0, .L8006FCB4
    /* 7514 8006FD14 00000000 */   nop
    /* 7518 8006FD18 94A1000C */  jal        DrawSync
    /* 751C 8006FD1C 21200000 */   addu      $a0, $zero, $zero
    /* 7520 8006FD20 1000A427 */  addiu      $a0, $sp, 0x10
    /* 7524 8006FD24 21282002 */  addu       $a1, $s1, $zero
    /* 7528 8006FD28 E0010224 */  addiu      $v0, $zero, 0x1E0
    /* 752C 8006FD2C 20021024 */  addiu      $s0, $zero, 0x220
    /* 7530 8006FD30 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 7534 8006FD34 00020224 */  addiu      $v0, $zero, 0x200
    /* 7538 8006FD38 1200A0A7 */  sh         $zero, 0x12($sp)
    /* 753C 8006FD3C 1400B0A7 */  sh         $s0, 0x14($sp)
    /* 7540 8006FD40 3FA2000C */  jal        LoadImage
    /* 7544 8006FD44 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 7548 8006FD48 94A1000C */  jal        DrawSync
    /* 754C 8006FD4C 21200000 */   addu      $a0, $zero, $zero
    /* 7550 8006FD50 0800053C */  lui        $a1, (0x88000 >> 16)
    /* 7554 8006FD54 0080A534 */  ori        $a1, $a1, (0x88000 & 0xFFFF)
    /* 7558 8006FD58 1000A427 */  addiu      $a0, $sp, 0x10
    /* 755C 8006FD5C 21282502 */  addu       $a1, $s1, $a1
    /* 7560 8006FD60 C0010224 */  addiu      $v0, $zero, 0x1C0
    /* 7564 8006FD64 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 7568 8006FD68 40000224 */  addiu      $v0, $zero, 0x40
    /* 756C 8006FD6C 1000A0A7 */  sh         $zero, 0x10($sp)
    /* 7570 8006FD70 1400B0A7 */  sh         $s0, 0x14($sp)
    /* 7574 8006FD74 3FA2000C */  jal        LoadImage
    /* 7578 8006FD78 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 757C 8006FD7C 94A1000C */  jal        DrawSync
    /* 7580 8006FD80 21200000 */   addu      $a0, $zero, $zero
    /* 7584 8006FD84 21800000 */  addu       $s0, $zero, $zero
    /* 7588 8006FD88 E0011524 */  addiu      $s5, $zero, 0x1E0
    /* 758C 8006FD8C 10001424 */  addiu      $s4, $zero, 0x10
    /* 7590 8006FD90 01001324 */  addiu      $s3, $zero, 0x1
    /* 7594 8006FD94 0780123C */  lui        $s2, %hi(_menuItemTextClut)
  .L8006FD98:
    /* 7598 8006FD98 1000A427 */  addiu      $a0, $sp, 0x10
    /* 759C 8006FD9C B44A4526 */  addiu      $a1, $s2, %lo(_menuItemTextClut)
    /* 75A0 8006FDA0 80010226 */  addiu      $v0, $s0, 0x180
    /* 75A4 8006FDA4 1000B5A7 */  sh         $s5, 0x10($sp)
    /* 75A8 8006FDA8 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 75AC 8006FDAC 1400B4A7 */  sh         $s4, 0x14($sp)
    /* 75B0 8006FDB0 3FA2000C */  jal        LoadImage
    /* 75B4 8006FDB4 1600B3A7 */   sh        $s3, 0x16($sp)
    /* 75B8 8006FDB8 94A1000C */  jal        DrawSync
    /* 75BC 8006FDBC 21200000 */   addu      $a0, $zero, $zero
    /* 75C0 8006FDC0 01001026 */  addiu      $s0, $s0, 0x1
    /* 75C4 8006FDC4 0800022E */  sltiu      $v0, $s0, 0x8
    /* 75C8 8006FDC8 F3FF4014 */  bnez       $v0, .L8006FD98
    /* 75CC 8006FDCC 0780053C */   lui       $a1, %hi(_menuItemOutlineClut)
    /* 75D0 8006FDD0 1000A427 */  addiu      $a0, $sp, 0x10
    /* 75D4 8006FDD4 F44AA524 */  addiu      $a1, $a1, %lo(_menuItemOutlineClut)
    /* 75D8 8006FDD8 E0010224 */  addiu      $v0, $zero, 0x1E0
    /* 75DC 8006FDDC 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 75E0 8006FDE0 8A010224 */  addiu      $v0, $zero, 0x18A
    /* 75E4 8006FDE4 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 75E8 8006FDE8 10000224 */  addiu      $v0, $zero, 0x10
    /* 75EC 8006FDEC 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 75F0 8006FDF0 01000224 */  addiu      $v0, $zero, 0x1
    /* 75F4 8006FDF4 3FA2000C */  jal        LoadImage
    /* 75F8 8006FDF8 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 75FC 8006FDFC 94A1000C */  jal        DrawSync
    /* 7600 8006FE00 21200000 */   addu      $a0, $zero, $zero
    /* 7604 8006FE04 540F010C */  jal        vs_main_freeHeap
    /* 7608 8006FE08 21202002 */   addu      $a0, $s1, $zero
    /* 760C 8006FE0C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 7610 8006FE10 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 7614 8006FE14 2800B48F */  lw         $s4, 0x28($sp)
    /* 7618 8006FE18 2400B38F */  lw         $s3, 0x24($sp)
    /* 761C 8006FE1C 2000B28F */  lw         $s2, 0x20($sp)
    /* 7620 8006FE20 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 7624 8006FE24 1800B08F */  lw         $s0, 0x18($sp)
    /* 7628 8006FE28 0800E003 */  jr         $ra
    /* 762C 8006FE2C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _copyTitleBgData
