nonmatching _setMenuRows, 0x118

glabel _setMenuRows
    /* 4D8 80102CD8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4DC 80102CDC 1800BEAF */  sw         $fp, 0x18($sp)
    /* 4E0 80102CE0 21F0A003 */  addu       $fp, $sp, $zero
    /* 4E4 80102CE4 21408000 */  addu       $t0, $a0, $zero
    /* 4E8 80102CE8 40110800 */  sll        $v0, $t0, 5
    /* 4EC 80102CEC C2100200 */  srl        $v0, $v0, 3
    /* 4F0 80102CF0 07004224 */  addiu      $v0, $v0, 0x7
    /* 4F4 80102CF4 C2100200 */  srl        $v0, $v0, 3
    /* 4F8 80102CF8 C0100200 */  sll        $v0, $v0, 3
    /* 4FC 80102CFC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 500 80102D00 1400B1AF */  sw         $s1, 0x14($sp)
    /* 504 80102D04 1000B0AF */  sw         $s0, 0x10($sp)
    /* 508 80102D08 23E8A203 */  subu       $sp, $sp, $v0
    /* 50C 80102D0C 21180000 */  addu       $v1, $zero, $zero
    /* 510 80102D10 07000019 */  blez       $t0, .L80102D30
    /* 514 80102D14 1000A727 */   addiu     $a3, $sp, 0x10
    /* 518 80102D18 2120E000 */  addu       $a0, $a3, $zero
  .L80102D1C:
    /* 51C 80102D1C 000080AC */  sw         $zero, 0x0($a0)
    /* 520 80102D20 01006324 */  addiu      $v1, $v1, 0x1
    /* 524 80102D24 2A106800 */  slt        $v0, $v1, $t0
    /* 528 80102D28 FCFF4014 */  bnez       $v0, .L80102D1C
    /* 52C 80102D2C 04008424 */   addiu     $a0, $a0, 0x4
  .L80102D30:
    /* 530 80102D30 FFFF0225 */  addiu      $v0, $t0, -0x1
    /* 534 80102D34 80100200 */  sll        $v0, $v0, 2
    /* 538 80102D38 2110E200 */  addu       $v0, $a3, $v0
    /* 53C 80102D3C 0000438C */  lw         $v1, 0x0($v0)
    /* 540 80102D40 00000000 */  nop
    /* 544 80102D44 04006334 */  ori        $v1, $v1, 0x4
    /* 548 80102D48 000043AC */  sw         $v1, 0x0($v0)
    /* 54C 80102D4C 09000229 */  slti       $v0, $t0, 0x9
    /* 550 80102D50 04004014 */  bnez       $v0, .L80102D64
    /* 554 80102D54 0F80023C */   lui       $v0, %hi(D_800F4EE8)
    /* 558 80102D58 0800A228 */  slti       $v0, $a1, 0x8
    /* 55C 80102D5C 05004010 */  beqz       $v0, .L80102D74
    /* 560 80102D60 0F80023C */   lui       $v0, %hi(D_800F4EE8)
  .L80102D64:
    /* 564 80102D64 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 568 80102D68 040045A0 */  sb         $a1, 0x4($v0)
    /* 56C 80102D6C 6C0B0408 */  j          .L80102DB0
    /* 570 80102D70 050040A0 */   sb        $zero, 0x5($v0)
  .L80102D74:
    /* 574 80102D74 F8FF0225 */  addiu      $v0, $t0, -0x8
    /* 578 80102D78 2A10A200 */  slt        $v0, $a1, $v0
    /* 57C 80102D7C 07004014 */  bnez       $v0, .L80102D9C
    /* 580 80102D80 0F80023C */   lui       $v0, %hi(D_800F4EE8)
    /* 584 80102D84 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 588 80102D88 F7FF0425 */  addiu      $a0, $t0, -0x9
    /* 58C 80102D8C 2318A400 */  subu       $v1, $a1, $a0
    /* 590 80102D90 040043A0 */  sb         $v1, 0x4($v0)
    /* 594 80102D94 6C0B0408 */  j          .L80102DB0
    /* 598 80102D98 050044A0 */   sb        $a0, 0x5($v0)
  .L80102D9C:
    /* 59C 80102D9C E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 5A0 80102DA0 04000324 */  addiu      $v1, $zero, 0x4
    /* 5A4 80102DA4 040043A0 */  sb         $v1, 0x4($v0)
    /* 5A8 80102DA8 FCFFA324 */  addiu      $v1, $a1, -0x4
    /* 5AC 80102DAC 050043A0 */  sb         $v1, 0x5($v0)
  .L80102DB0:
    /* 5B0 80102DB0 0680103C */  lui        $s0, %hi(vs_main_settings)
    /* 5B4 80102DB4 20001026 */  addiu      $s0, $s0, %lo(vs_main_settings)
    /* 5B8 80102DB8 01000224 */  addiu      $v0, $zero, 0x1
    /* 5BC 80102DBC 21200001 */  addu       $a0, $t0, $zero
    /* 5C0 80102DC0 01001192 */  lbu        $s1, 0x1($s0)
    /* 5C4 80102DC4 02010524 */  addiu      $a1, $zero, 0x102
    /* 5C8 80102DC8 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 5CC 80102DCC 010002A2 */   sb        $v0, 0x1($s0)
    /* 5D0 80102DD0 010011A2 */  sb         $s1, 0x1($s0)
    /* 5D4 80102DD4 21E8C003 */  addu       $sp, $fp, $zero
    /* 5D8 80102DD8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 5DC 80102DDC 1800BE8F */  lw         $fp, 0x18($sp)
    /* 5E0 80102DE0 1400B18F */  lw         $s1, 0x14($sp)
    /* 5E4 80102DE4 1000B08F */  lw         $s0, 0x10($sp)
    /* 5E8 80102DE8 0800E003 */  jr         $ra
    /* 5EC 80102DEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _setMenuRows
