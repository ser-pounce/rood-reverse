nonmatching _findCurrentSaveOnActiveMemcard, 0x98

glabel _findCurrentSaveOnActiveMemcard
    /* 514 80102D14 21280000 */  addu       $a1, $zero, $zero
    /* 518 80102D18 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 51C 80102D1C 20004624 */  addiu      $a2, $v0, %lo(vs_main_settings)
    /* 520 80102D20 1180023C */  lui        $v0, %hi(_saveFileInfo)
    /* 524 80102D24 40AE448C */  lw         $a0, %lo(_saveFileInfo)($v0)
  .L80102D28:
    /* 528 80102D28 00000000 */  nop
    /* 52C 80102D2C 0400838C */  lw         $v1, 0x4($a0)
    /* 530 80102D30 00000000 */  nop
    /* 534 80102D34 0300622C */  sltiu      $v0, $v1, 0x3
    /* 538 80102D38 14004014 */  bnez       $v0, .L80102D8C
    /* 53C 80102D3C 00000000 */   nop
    /* 540 80102D40 0400C28C */  lw         $v0, 0x4($a2)
    /* 544 80102D44 00000000 */  nop
    /* 548 80102D48 10006214 */  bne        $v1, $v0, .L80102D8C
    /* 54C 80102D4C 00000000 */   nop
    /* 550 80102D50 0000838C */  lw         $v1, 0x0($a0)
    /* 554 80102D54 1400C28C */  lw         $v0, 0x14($a2)
    /* 558 80102D58 00000000 */  nop
    /* 55C 80102D5C 0B006214 */  bne        $v1, $v0, .L80102D8C
    /* 560 80102D60 00000000 */   nop
    /* 564 80102D64 14008394 */  lhu        $v1, 0x14($a0)
    /* 568 80102D68 1800C294 */  lhu        $v0, 0x18($a2)
    /* 56C 80102D6C 00000000 */  nop
    /* 570 80102D70 06006214 */  bne        $v1, $v0, .L80102D8C
    /* 574 80102D74 00000000 */   nop
    /* 578 80102D78 0800838C */  lw         $v1, 0x8($a0)
    /* 57C 80102D7C 1C00C28C */  lw         $v0, 0x1C($a2)
    /* 580 80102D80 00000000 */  nop
    /* 584 80102D84 07006210 */  beq        $v1, $v0, .L80102DA4
    /* 588 80102D88 0100A224 */   addiu     $v0, $a1, 0x1
  .L80102D8C:
    /* 58C 80102D8C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 590 80102D90 0500A228 */  slti       $v0, $a1, 0x5
    /* 594 80102D94 E4FF4014 */  bnez       $v0, .L80102D28
    /* 598 80102D98 80008424 */   addiu     $a0, $a0, 0x80
    /* 59C 80102D9C 0800E003 */  jr         $ra
    /* 5A0 80102DA0 21100000 */   addu      $v0, $zero, $zero
  .L80102DA4:
    /* 5A4 80102DA4 0800E003 */  jr         $ra
    /* 5A8 80102DA8 00000000 */   nop
endlabel _findCurrentSaveOnActiveMemcard
