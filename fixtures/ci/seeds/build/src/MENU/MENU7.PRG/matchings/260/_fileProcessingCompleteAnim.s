nonmatching _fileProcessingCompleteAnim, 0x138

glabel _fileProcessingCompleteAnim
    /* 2420 80104C20 1180023C */  lui        $v0, %hi(_isSaving)
    /* 2424 80104C24 A8B04290 */  lbu        $v0, %lo(_isSaving)($v0)
    /* 2428 80104C28 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 242C 80104C2C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2430 80104C30 2198A000 */  addu       $s3, $a1, $zero
    /* 2434 80104C34 2400B5AF */  sw         $s5, 0x24($sp)
    /* 2438 80104C38 21A80000 */  addu       $s5, $zero, $zero
    /* 243C 80104C3C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 2440 80104C40 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2444 80104C44 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2448 80104C48 1400B1AF */  sw         $s1, 0x14($sp)
    /* 244C 80104C4C 04004010 */  beqz       $v0, .L80104C60
    /* 2450 80104C50 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2454 80104C54 C0130400 */  sll        $v0, $a0, 15
    /* 2458 80104C58 1C130408 */  j          .L80104C70
    /* 245C 80104C5C 21908200 */   addu      $s2, $a0, $v0
  .L80104C60:
    /* 2460 80104C60 C3100400 */  sra        $v0, $a0, 3
    /* 2464 80104C64 23108200 */  subu       $v0, $a0, $v0
    /* 2468 80104C68 001A0400 */  sll        $v1, $a0, 8
    /* 246C 80104C6C 21904300 */  addu       $s2, $v0, $v1
  .L80104C70:
    /* 2470 80104C70 94A1000C */  jal        DrawSync
    /* 2474 80104C74 21200000 */   addu      $a0, $zero, $zero
    /* 2478 80104C78 00E1033C */  lui        $v1, (0xE1000220 >> 16)
    /* 247C 80104C7C 20026334 */  ori        $v1, $v1, (0xE1000220 & 0xFFFF)
    /* 2480 80104C80 2000053C */  lui        $a1, (0x200100 >> 16)
    /* 2484 80104C84 0001A534 */  ori        $a1, $a1, (0x200100 & 0xFFFF)
    /* 2488 80104C88 1180113C */  lui        $s1, %hi(_primBuf)
    /* 248C 80104C8C 60B03026 */  addiu      $s0, $s1, %lo(_primBuf)
    /* 2490 80104C90 21200002 */  addu       $a0, $s0, $zero
    /* 2494 80104C94 0004023C */  lui        $v0, (0x4000000 >> 16)
    /* 2498 80104C98 60B022AE */  sw         $v0, %lo(_primBuf)($s1)
    /* 249C 80104C9C 0062023C */  lui        $v0, (0x62000000 >> 16)
    /* 24A0 80104CA0 25104202 */  or         $v0, $s2, $v0
    /* 24A4 80104CA4 080002AE */  sw         $v0, 0x8($s0)
    /* 24A8 80104CA8 40006236 */  ori        $v0, $s3, 0x40
    /* 24AC 80104CAC 040003AE */  sw         $v1, 0x4($s0)
    /* 24B0 80104CB0 0C0002AE */  sw         $v0, 0xC($s0)
    /* 24B4 80104CB4 FAA2000C */  jal        DrawPrim
    /* 24B8 80104CB8 100005AE */   sw        $a1, 0x10($s0)
    /* 24BC 80104CBC 21A00000 */  addu       $s4, $zero, $zero
  .L80104CC0:
    /* 24C0 80104CC0 94A1000C */  jal        DrawSync
    /* 24C4 80104CC4 21200000 */   addu      $a0, $zero, $zero
    /* 24C8 80104CC8 21200002 */  addu       $a0, $s0, $zero
    /* 24CC 80104CCC 0008023C */  lui        $v0, (0x8000000 >> 16)
    /* 24D0 80104CD0 60B022AE */  sw         $v0, %lo(_primBuf)($s1)
    /* 24D4 80104CD4 003A023C */  lui        $v0, (0x3A000000 >> 16)
    /* 24D8 80104CD8 2510A202 */  or         $v0, $s5, $v0
    /* 24DC 80104CDC F8FF033C */  lui        $v1, (0xFFF80140 >> 16)
    /* 24E0 80104CE0 21186302 */  addu       $v1, $s3, $v1
    /* 24E4 80104CE4 040002AE */  sw         $v0, 0x4($s0)
    /* 24E8 80104CE8 40006234 */  ori        $v0, $v1, (0xFFF80040 & 0xFFFF)
    /* 24EC 80104CEC 40016334 */  ori        $v1, $v1, (0xFFF80140 & 0xFFFF)
    /* 24F0 80104CF0 080002AE */  sw         $v0, 0x8($s0)
    /* 24F4 80104CF4 40006236 */  ori        $v0, $s3, (0x280040 & 0xFFFF)
    /* 24F8 80104CF8 180002AE */  sw         $v0, 0x18($s0)
    /* 24FC 80104CFC 40016236 */  ori        $v0, $s3, (0x280140 & 0xFFFF)
    /* 2500 80104D00 0C0015AE */  sw         $s5, 0xC($s0)
    /* 2504 80104D04 100003AE */  sw         $v1, 0x10($s0)
    /* 2508 80104D08 140012AE */  sw         $s2, 0x14($s0)
    /* 250C 80104D0C 1C0012AE */  sw         $s2, 0x1C($s0)
    /* 2510 80104D10 FAA2000C */  jal        DrawPrim
    /* 2514 80104D14 200002AE */   sw        $v0, 0x20($s0)
    /* 2518 80104D18 2800023C */  lui        $v0, (0x280140 >> 16)
    /* 251C 80104D1C 21986202 */  addu       $s3, $s3, $v0
    /* 2520 80104D20 21A84002 */  addu       $s5, $s2, $zero
    /* 2524 80104D24 01009426 */  addiu      $s4, $s4, 0x1
    /* 2528 80104D28 0200822E */  sltiu      $v0, $s4, 0x2
    /* 252C 80104D2C E4FF4014 */  bnez       $v0, .L80104CC0
    /* 2530 80104D30 21900000 */   addu      $s2, $zero, $zero
    /* 2534 80104D34 2800BF8F */  lw         $ra, 0x28($sp)
    /* 2538 80104D38 2400B58F */  lw         $s5, 0x24($sp)
    /* 253C 80104D3C 2000B48F */  lw         $s4, 0x20($sp)
    /* 2540 80104D40 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2544 80104D44 1800B28F */  lw         $s2, 0x18($sp)
    /* 2548 80104D48 1400B18F */  lw         $s1, 0x14($sp)
    /* 254C 80104D4C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2550 80104D50 0800E003 */  jr         $ra
    /* 2554 80104D54 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _fileProcessingCompleteAnim
