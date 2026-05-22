nonmatching _toVsStringInt, 0x70

glabel _toVsStringInt
    /* 44EC 80106CEC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 44F0 80106CF0 2130A000 */  addu       $a2, $a1, $zero
    /* 44F4 80106CF4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 44F8 80106CF8 21808000 */  addu       $s0, $a0, $zero
    /* 44FC 80106CFC 1080053C */  lui        $a1, %hi(D_801029AC)
    /* 4500 80106D00 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4504 80106D04 BD9B000C */  jal        sprintf
    /* 4508 80106D08 AC29A524 */   addiu     $a1, $a1, %lo(D_801029AC)
    /* 450C 80106D0C A59B000C */  jal        strlen
    /* 4510 80106D10 21200002 */   addu      $a0, $s0, $zero
    /* 4514 80106D14 21284000 */  addu       $a1, $v0, $zero
    /* 4518 80106D18 0900A018 */  blez       $a1, .L80106D40
    /* 451C 80106D1C 21200000 */   addu      $a0, $zero, $zero
    /* 4520 80106D20 21100402 */  addu       $v0, $s0, $a0
  .L80106D24:
    /* 4524 80106D24 00004390 */  lbu        $v1, 0x0($v0)
    /* 4528 80106D28 01008424 */  addiu      $a0, $a0, 0x1
    /* 452C 80106D2C D0FF6324 */  addiu      $v1, $v1, -0x30
    /* 4530 80106D30 000043A0 */  sb         $v1, 0x0($v0)
    /* 4534 80106D34 2A108500 */  slt        $v0, $a0, $a1
    /* 4538 80106D38 FAFF4014 */  bnez       $v0, .L80106D24
    /* 453C 80106D3C 21100402 */   addu      $v0, $s0, $a0
  .L80106D40:
    /* 4540 80106D40 21800502 */  addu       $s0, $s0, $a1
    /* 4544 80106D44 E7000224 */  addiu      $v0, $zero, 0xE7
    /* 4548 80106D48 000002A2 */  sb         $v0, 0x0($s0)
    /* 454C 80106D4C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4550 80106D50 1000B08F */  lw         $s0, 0x10($sp)
    /* 4554 80106D54 0800E003 */  jr         $ra
    /* 4558 80106D58 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _toVsStringInt
