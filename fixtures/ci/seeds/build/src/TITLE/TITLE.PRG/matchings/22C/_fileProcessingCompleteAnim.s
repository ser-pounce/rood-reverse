nonmatching _fileProcessingCompleteAnim, 0x138

glabel _fileProcessingCompleteAnim
    /* 24D8 8006ACD8 0E80023C */  lui        $v0, %hi(_isSaving)
    /* 24DC 8006ACDC 70ED4290 */  lbu        $v0, %lo(_isSaving)($v0)
    /* 24E0 8006ACE0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 24E4 8006ACE4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 24E8 8006ACE8 2198A000 */  addu       $s3, $a1, $zero
    /* 24EC 8006ACEC 2400B5AF */  sw         $s5, 0x24($sp)
    /* 24F0 8006ACF0 21A80000 */  addu       $s5, $zero, $zero
    /* 24F4 8006ACF4 2800BFAF */  sw         $ra, 0x28($sp)
    /* 24F8 8006ACF8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 24FC 8006ACFC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2500 8006AD00 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2504 8006AD04 04004010 */  beqz       $v0, .L8006AD18
    /* 2508 8006AD08 1000B0AF */   sw        $s0, 0x10($sp)
    /* 250C 8006AD0C C0130400 */  sll        $v0, $a0, 15
    /* 2510 8006AD10 4AAB0108 */  j          .L8006AD28
    /* 2514 8006AD14 21908200 */   addu      $s2, $a0, $v0
  .L8006AD18:
    /* 2518 8006AD18 C3100400 */  sra        $v0, $a0, 3
    /* 251C 8006AD1C 23108200 */  subu       $v0, $a0, $v0
    /* 2520 8006AD20 001A0400 */  sll        $v1, $a0, 8
    /* 2524 8006AD24 21904300 */  addu       $s2, $v0, $v1
  .L8006AD28:
    /* 2528 8006AD28 94A1000C */  jal        DrawSync
    /* 252C 8006AD2C 21200000 */   addu      $a0, $zero, $zero
    /* 2530 8006AD30 00E1033C */  lui        $v1, (0xE1000220 >> 16)
    /* 2534 8006AD34 20026334 */  ori        $v1, $v1, (0xE1000220 & 0xFFFF)
    /* 2538 8006AD38 2000053C */  lui        $a1, (0x200100 >> 16)
    /* 253C 8006AD3C 0001A534 */  ori        $a1, $a1, (0x200100 & 0xFFFF)
    /* 2540 8006AD40 0E80113C */  lui        $s1, %hi(_primBuf)
    /* 2544 8006AD44 28ED3026 */  addiu      $s0, $s1, %lo(_primBuf)
    /* 2548 8006AD48 21200002 */  addu       $a0, $s0, $zero
    /* 254C 8006AD4C 0004023C */  lui        $v0, (0x4000000 >> 16)
    /* 2550 8006AD50 28ED22AE */  sw         $v0, %lo(_primBuf)($s1)
    /* 2554 8006AD54 0062023C */  lui        $v0, (0x62000000 >> 16)
    /* 2558 8006AD58 25104202 */  or         $v0, $s2, $v0
    /* 255C 8006AD5C 080002AE */  sw         $v0, 0x8($s0)
    /* 2560 8006AD60 40006236 */  ori        $v0, $s3, 0x40
    /* 2564 8006AD64 040003AE */  sw         $v1, 0x4($s0)
    /* 2568 8006AD68 0C0002AE */  sw         $v0, 0xC($s0)
    /* 256C 8006AD6C FAA2000C */  jal        DrawPrim
    /* 2570 8006AD70 100005AE */   sw        $a1, 0x10($s0)
    /* 2574 8006AD74 21A00000 */  addu       $s4, $zero, $zero
  .L8006AD78:
    /* 2578 8006AD78 94A1000C */  jal        DrawSync
    /* 257C 8006AD7C 21200000 */   addu      $a0, $zero, $zero
    /* 2580 8006AD80 21200002 */  addu       $a0, $s0, $zero
    /* 2584 8006AD84 0008023C */  lui        $v0, (0x8000000 >> 16)
    /* 2588 8006AD88 28ED22AE */  sw         $v0, %lo(_primBuf)($s1)
    /* 258C 8006AD8C 003A023C */  lui        $v0, (0x3A000000 >> 16)
    /* 2590 8006AD90 2510A202 */  or         $v0, $s5, $v0
    /* 2594 8006AD94 F8FF033C */  lui        $v1, (0xFFF80140 >> 16)
    /* 2598 8006AD98 21186302 */  addu       $v1, $s3, $v1
    /* 259C 8006AD9C 040002AE */  sw         $v0, 0x4($s0)
    /* 25A0 8006ADA0 40006234 */  ori        $v0, $v1, (0xFFF80040 & 0xFFFF)
    /* 25A4 8006ADA4 40016334 */  ori        $v1, $v1, (0xFFF80140 & 0xFFFF)
    /* 25A8 8006ADA8 080002AE */  sw         $v0, 0x8($s0)
    /* 25AC 8006ADAC 40006236 */  ori        $v0, $s3, (0x280040 & 0xFFFF)
    /* 25B0 8006ADB0 180002AE */  sw         $v0, 0x18($s0)
    /* 25B4 8006ADB4 40016236 */  ori        $v0, $s3, (0x280140 & 0xFFFF)
    /* 25B8 8006ADB8 0C0015AE */  sw         $s5, 0xC($s0)
    /* 25BC 8006ADBC 100003AE */  sw         $v1, 0x10($s0)
    /* 25C0 8006ADC0 140012AE */  sw         $s2, 0x14($s0)
    /* 25C4 8006ADC4 1C0012AE */  sw         $s2, 0x1C($s0)
    /* 25C8 8006ADC8 FAA2000C */  jal        DrawPrim
    /* 25CC 8006ADCC 200002AE */   sw        $v0, 0x20($s0)
    /* 25D0 8006ADD0 2800023C */  lui        $v0, (0x280140 >> 16)
    /* 25D4 8006ADD4 21986202 */  addu       $s3, $s3, $v0
    /* 25D8 8006ADD8 21A84002 */  addu       $s5, $s2, $zero
    /* 25DC 8006ADDC 01009426 */  addiu      $s4, $s4, 0x1
    /* 25E0 8006ADE0 0200822E */  sltiu      $v0, $s4, 0x2
    /* 25E4 8006ADE4 E4FF4014 */  bnez       $v0, .L8006AD78
    /* 25E8 8006ADE8 21900000 */   addu      $s2, $zero, $zero
    /* 25EC 8006ADEC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 25F0 8006ADF0 2400B58F */  lw         $s5, 0x24($sp)
    /* 25F4 8006ADF4 2000B48F */  lw         $s4, 0x20($sp)
    /* 25F8 8006ADF8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 25FC 8006ADFC 1800B28F */  lw         $s2, 0x18($sp)
    /* 2600 8006AE00 1400B18F */  lw         $s1, 0x14($sp)
    /* 2604 8006AE04 1000B08F */  lw         $s0, 0x10($sp)
    /* 2608 8006AE08 0800E003 */  jr         $ra
    /* 260C 8006AE0C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _fileProcessingCompleteAnim
