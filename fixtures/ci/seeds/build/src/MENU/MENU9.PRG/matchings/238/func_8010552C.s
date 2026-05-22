nonmatching func_8010552C, 0x18C

glabel func_8010552C
    /* 2D2C 8010552C 18FFBD27 */  addiu      $sp, $sp, -0xE8
    /* 2D30 80105530 DC00B5AF */  sw         $s5, 0xDC($sp)
    /* 2D34 80105534 21A88000 */  addu       $s5, $a0, $zero
    /* 2D38 80105538 0800A22A */  slti       $v0, $s5, 0x8
    /* 2D3C 8010553C E000BFAF */  sw         $ra, 0xE0($sp)
    /* 2D40 80105540 D800B4AF */  sw         $s4, 0xD8($sp)
    /* 2D44 80105544 D400B3AF */  sw         $s3, 0xD4($sp)
    /* 2D48 80105548 D000B2AF */  sw         $s2, 0xD0($sp)
    /* 2D4C 8010554C CC00B1AF */  sw         $s1, 0xCC($sp)
    /* 2D50 80105550 03004010 */  beqz       $v0, .L80105560
    /* 2D54 80105554 C800B0AF */   sw        $s0, 0xC8($sp)
    /* 2D58 80105558 4A19040C */  jal        func_80106528
    /* 2D5C 8010555C 00000000 */   nop
  .L80105560:
    /* 2D60 80105560 3565020C */  jal        vs_battle_getGeomOffset
    /* 2D64 80105564 1800A427 */   addiu     $a0, $sp, 0x18
    /* 2D68 80105568 2000A427 */  addiu      $a0, $sp, 0x20
    /* 2D6C 8010556C 08000324 */  addiu      $v1, $zero, 0x8
    /* 2D70 80105570 23187500 */  subu       $v1, $v1, $s5
    /* 2D74 80105574 40190300 */  sll        $v1, $v1, 5
    /* 2D78 80105578 80000224 */  addiu      $v0, $zero, 0x80
    /* 2D7C 8010557C 23104300 */  subu       $v0, $v0, $v1
    /* 2D80 80105580 2000A2AF */  sw         $v0, 0x20($sp)
    /* 2D84 80105584 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 2D88 80105588 3D65020C */  jal        vs_battle_setGeomOffset
    /* 2D8C 8010558C 2400A2AF */   sw        $v0, 0x24($sp)
    /* 2D90 80105590 A800B027 */  addiu      $s0, $sp, 0xA8
    /* 2D94 80105594 2F13040C */  jal        func_80104CBC
    /* 2D98 80105598 21200002 */   addu      $a0, $s0, $zero
    /* 2D9C 8010559C AEE7030C */  jal        func_800F9EB8
    /* 2DA0 801055A0 21200002 */   addu      $a0, $s0, $zero
    /* 2DA4 801055A4 3D65020C */  jal        vs_battle_setGeomOffset
    /* 2DA8 801055A8 1800A427 */   addiu     $a0, $sp, 0x18
    /* 2DAC 801055AC 2800B427 */  addiu      $s4, $sp, 0x28
    /* 2DB0 801055B0 21208002 */  addu       $a0, $s4, $zero
    /* 2DB4 801055B4 1180023C */  lui        $v0, %hi(_score)
    /* 2DB8 801055B8 1080053C */  lui        $a1, %hi(D_80102908)
    /* 2DBC 801055BC 60A4468C */  lw         $a2, %lo(_score)($v0)
    /* 2DC0 801055C0 BD9B000C */  jal        sprintf
    /* 2DC4 801055C4 0829A524 */   addiu     $a1, $a1, %lo(D_80102908)
    /* 2DC8 801055C8 1080043C */  lui        $a0, %hi(D_80102910)
    /* 2DCC 801055CC 10298424 */  addiu      $a0, $a0, %lo(D_80102910)
    /* 2DD0 801055D0 00811500 */  sll        $s0, $s5, 4
    /* 2DD4 801055D4 88FF1126 */  addiu      $s1, $s0, -0x78
    /* 2DD8 801055D8 FFFF3132 */  andi       $s1, $s1, 0xFFFF
    /* 2DDC 801055DC 1000133C */  lui        $s3, (0x100000 >> 16)
    /* 2DE0 801055E0 25283302 */  or         $a1, $s1, $s3
    /* 2DE4 801055E4 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 2DE8 801055E8 801F123C */  lui        $s2, (0x1F800004 >> 16)
    /* 2DEC 801055EC 0400478E */  lw         $a3, (0x1F800004 & 0xFFFF)($s2)
    /* 2DF0 801055F0 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* 2DF4 801055F4 5019030C */  jal        vs_battle_renderTextRawColor
    /* 2DF8 801055F8 1C00E724 */   addiu     $a3, $a3, 0x1C
    /* 2DFC 801055FC 21208002 */  addu       $a0, $s4, $zero
    /* 2E00 80105600 FFFF0532 */  andi       $a1, $s0, 0xFFFF
    /* 2E04 80105604 2528B300 */  or         $a1, $a1, $s3
    /* 2E08 80105608 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 2E0C 8010560C 0400478E */  lw         $a3, (0x1F800004 & 0xFFFF)($s2)
    /* 2E10 80105610 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* 2E14 80105614 5019030C */  jal        vs_battle_renderTextRawColor
    /* 2E18 80105618 1C00E724 */   addiu     $a3, $a3, 0x1C
    /* 2E1C 8010561C 80FF1026 */  addiu      $s0, $s0, -0x80
    /* 2E20 80105620 21200002 */  addu       $a0, $s0, $zero
    /* 2E24 80105624 10000524 */  addiu      $a1, $zero, 0x10
    /* 2E28 80105628 88000624 */  addiu      $a2, $zero, 0x88
    /* 2E2C 8010562C 0C000724 */  addiu      $a3, $zero, 0xC
    /* 2E30 80105630 02000224 */  addiu      $v0, $zero, 0x2
    /* 2E34 80105634 6B14040C */  jal        func_801051AC
    /* 2E38 80105638 1000A2AF */   sw        $v0, 0x10($sp)
    /* 2E3C 8010563C 1080043C */  lui        $a0, %hi(D_80102918)
    /* 2E40 80105640 18298424 */  addiu      $a0, $a0, %lo(D_80102918)
    /* 2E44 80105644 B800053C */  lui        $a1, (0xB80000 >> 16)
    /* 2E48 80105648 25282502 */  or         $a1, $s1, $a1
    /* 2E4C 8010564C 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 2E50 80105650 0400478E */  lw         $a3, (0x1F800004 & 0xFFFF)($s2)
    /* 2E54 80105654 8080C634 */  ori        $a2, $a2, (0x808080 & 0xFFFF)
    /* 2E58 80105658 5019030C */  jal        vs_battle_renderTextRawColor
    /* 2E5C 8010565C 1C00E724 */   addiu     $a3, $a3, 0x1C
    /* 2E60 80105660 21200002 */  addu       $a0, $s0, $zero
    /* 2E64 80105664 B8000524 */  addiu      $a1, $zero, 0xB8
    /* 2E68 80105668 88000624 */  addiu      $a2, $zero, 0x88
    /* 2E6C 8010566C 0C000724 */  addiu      $a3, $zero, 0xC
    /* 2E70 80105670 01000224 */  addiu      $v0, $zero, 0x1
    /* 2E74 80105674 6B14040C */  jal        func_801051AC
    /* 2E78 80105678 1000A2AF */   sw        $v0, 0x10($sp)
    /* 2E7C 8010567C 40201500 */  sll        $a0, $s5, 1
    /* 2E80 80105680 21209500 */  addu       $a0, $a0, $s5
    /* 2E84 80105684 40200400 */  sll        $a0, $a0, 1
    /* 2E88 80105688 EC000224 */  addiu      $v0, $zero, 0xEC
    /* 2E8C 8010568C E714040C */  jal        func_8010539C
    /* 2E90 80105690 23204400 */   subu      $a0, $v0, $a0
    /* 2E94 80105694 E000BF8F */  lw         $ra, 0xE0($sp)
    /* 2E98 80105698 DC00B58F */  lw         $s5, 0xDC($sp)
    /* 2E9C 8010569C D800B48F */  lw         $s4, 0xD8($sp)
    /* 2EA0 801056A0 D400B38F */  lw         $s3, 0xD4($sp)
    /* 2EA4 801056A4 D000B28F */  lw         $s2, 0xD0($sp)
    /* 2EA8 801056A8 CC00B18F */  lw         $s1, 0xCC($sp)
    /* 2EAC 801056AC C800B08F */  lw         $s0, 0xC8($sp)
    /* 2EB0 801056B0 0800E003 */  jr         $ra
    /* 2EB4 801056B4 E800BD27 */   addiu     $sp, $sp, 0xE8
endlabel func_8010552C
