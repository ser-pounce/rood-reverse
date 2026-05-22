nonmatching func_8007B508, 0x134

glabel func_8007B508
    /* 12D08 8007B508 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 12D0C 8007B50C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 12D10 8007B510 FDFA020C */  jal        vs_battle_getStateFlag
    /* 12D14 8007B514 B6000424 */   addiu     $a0, $zero, 0xB6
    /* 12D18 8007B518 FF004230 */  andi       $v0, $v0, 0xFF
    /* 12D1C 8007B51C 0D004010 */  beqz       $v0, .L8007B554
    /* 12D20 8007B520 00000000 */   nop
    /* 12D24 8007B524 FDFA020C */  jal        vs_battle_getStateFlag
    /* 12D28 8007B528 B6000424 */   addiu     $a0, $zero, 0xB6
    /* 12D2C 8007B52C FF004230 */  andi       $v0, $v0, 0xFF
    /* 12D30 8007B530 02000324 */  addiu      $v1, $zero, 0x2
    /* 12D34 8007B534 07004310 */  beq        $v0, $v1, .L8007B554
    /* 12D38 8007B538 00000000 */   nop
    /* 12D3C 8007B53C FDFA020C */  jal        vs_battle_getStateFlag
    /* 12D40 8007B540 B6000424 */   addiu     $a0, $zero, 0xB6
    /* 12D44 8007B544 FF004230 */  andi       $v0, $v0, 0xFF
    /* 12D48 8007B548 03000324 */  addiu      $v1, $zero, 0x3
    /* 12D4C 8007B54C 06004314 */  bne        $v0, $v1, .L8007B568
    /* 12D50 8007B550 0F80023C */   lui       $v0, %hi(D_800F19CC)
  .L8007B554:
    /* 12D54 8007B554 D8BD010C */  jal        _isArtOrAbilityUnlocked
    /* 12D58 8007B558 00000000 */   nop
    /* 12D5C 8007B55C 22004014 */  bnez       $v0, .L8007B5E8
    /* 12D60 8007B560 0F80043C */   lui       $a0, %hi(_cameraMode)
    /* 12D64 8007B564 0F80023C */  lui        $v0, %hi(D_800F19CC)
  .L8007B568:
    /* 12D68 8007B568 CC19458C */  lw         $a1, %lo(D_800F19CC)($v0)
    /* 12D6C 8007B56C 00000000 */  nop
    /* 12D70 8007B570 0800A294 */  lhu        $v0, 0x8($a1)
    /* 12D74 8007B574 00000000 */  nop
    /* 12D78 8007B578 2A004010 */  beqz       $v0, .L8007B624
    /* 12D7C 8007B57C 0580043C */   lui       $a0, %hi(vs_main_skills)
    /* 12D80 8007B580 21184000 */  addu       $v1, $v0, $zero
    /* 12D84 8007B584 DCB98424 */  addiu      $a0, $a0, %lo(vs_main_skills)
    /* 12D88 8007B588 40100300 */  sll        $v0, $v1, 1
    /* 12D8C 8007B58C 21104300 */  addu       $v0, $v0, $v1
    /* 12D90 8007B590 80100200 */  sll        $v0, $v0, 2
    /* 12D94 8007B594 21104300 */  addu       $v0, $v0, $v1
    /* 12D98 8007B598 80100200 */  sll        $v0, $v0, 2
    /* 12D9C 8007B59C 21104400 */  addu       $v0, $v0, $a0
    /* 12DA0 8007B5A0 0C00428C */  lw         $v0, 0xC($v0)
    /* 12DA4 8007B5A4 00000000 */  nop
    /* 12DA8 8007B5A8 C2130200 */  srl        $v0, $v0, 15
    /* 12DAC 8007B5AC 01004230 */  andi       $v0, $v0, 0x1
    /* 12DB0 8007B5B0 1C004014 */  bnez       $v0, .L8007B624
    /* 12DB4 8007B5B4 00000000 */   nop
    /* 12DB8 8007B5B8 4C00A28C */  lw         $v0, 0x4C($a1)
    /* 12DBC 8007B5BC 00000000 */  nop
    /* 12DC0 8007B5C0 18004014 */  bnez       $v0, .L8007B624
    /* 12DC4 8007B5C4 00000000 */   nop
    /* 12DC8 8007B5C8 072CA290 */  lbu        $v0, 0x2C07($a1)
    /* 12DCC 8007B5CC 00000000 */  nop
    /* 12DD0 8007B5D0 14004014 */  bnez       $v0, .L8007B624
    /* 12DD4 8007B5D4 00000000 */   nop
    /* 12DD8 8007B5D8 0C00A290 */  lbu        $v0, 0xC($a1)
    /* 12DDC 8007B5DC 00000000 */  nop
    /* 12DE0 8007B5E0 10004014 */  bnez       $v0, .L8007B624
    /* 12DE4 8007B5E4 0F80043C */   lui       $a0, %hi(_cameraMode)
  .L8007B5E8:
    /* 12DE8 8007B5E8 0F80023C */  lui        $v0, %hi(D_800F1864)
    /* 12DEC 8007B5EC 6418438C */  lw         $v1, %lo(D_800F1864)($v0)
    /* 12DF0 8007B5F0 05000224 */  addiu      $v0, $zero, 0x5
    /* 12DF4 8007B5F4 07006010 */  beqz       $v1, .L8007B614
    /* 12DF8 8007B5F8 F01882AC */   sw        $v0, %lo(_cameraMode)($a0)
    /* 12DFC 8007B5FC 21200000 */  addu       $a0, $zero, $zero
    /* 12E00 8007B600 21288000 */  addu       $a1, $a0, $zero
    /* 12E04 8007B604 1C78020C */  jal        func_8009E070
    /* 12E08 8007B608 06000624 */   addiu     $a2, $zero, 0x6
    /* 12E0C 8007B60C 12BE010C */  jal        func_8006F848
    /* 12E10 8007B610 00000000 */   nop
  .L8007B614:
    /* 12E14 8007B614 6535020C */  jal        func_8008D594
    /* 12E18 8007B618 01000424 */   addiu     $a0, $zero, 0x1
    /* 12E1C 8007B61C 8BED0108 */  j          .L8007B62C
    /* 12E20 8007B620 00000000 */   nop
  .L8007B624:
    /* 12E24 8007B624 31ED010C */  jal        func_8007B4C4
    /* 12E28 8007B628 00000000 */   nop
  .L8007B62C:
    /* 12E2C 8007B62C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12E30 8007B630 00000000 */  nop
    /* 12E34 8007B634 0800E003 */  jr         $ra
    /* 12E38 8007B638 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007B508
