nonmatching func_8006A4D8, 0xE8

glabel func_8006A4D8
    /* 1CD8 8006A4D8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1CDC 8006A4DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1CE0 8006A4E0 21888000 */  addu       $s1, $a0, $zero
    /* 1CE4 8006A4E4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1CE8 8006A4E8 801F123C */  lui        $s2, (0x1F800000 >> 16)
    /* 1CEC 8006A4EC 01000424 */  addiu      $a0, $zero, 0x1
    /* 1CF0 8006A4F0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1CF4 8006A4F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1CF8 8006A4F8 08002286 */  lh         $v0, 0x8($s1)
    /* 1CFC 8006A4FC 0000508E */  lw         $s0, (0x1F800000 & 0xFFFF)($s2)
    /* 1D00 8006A500 03004414 */  bne        $v0, $a0, .L8006A510
    /* 1D04 8006A504 02000224 */   addiu     $v0, $zero, 0x2
    /* 1D08 8006A508 0A0020A6 */  sh         $zero, 0xA($s1)
    /* 1D0C 8006A50C 080022A6 */  sh         $v0, 0x8($s1)
  .L8006A510:
    /* 1D10 8006A510 0A002296 */  lhu        $v0, 0xA($s1)
    /* 1D14 8006A514 80000324 */  addiu      $v1, $zero, 0x80
    /* 1D18 8006A518 01004224 */  addiu      $v0, $v0, 0x1
    /* 1D1C 8006A51C 0A0022A6 */  sh         $v0, 0xA($s1)
    /* 1D20 8006A520 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 1D24 8006A524 02004314 */  bne        $v0, $v1, .L8006A530
    /* 1D28 8006A528 0E80023C */   lui       $v0, %hi(D_800DC188)
    /* 1D2C 8006A52C 88C144A0 */  sb         $a0, %lo(D_800DC188)($v0)
  .L8006A530:
    /* 1D30 8006A530 91AD000C */  jal        SetTile
    /* 1D34 8006A534 21200002 */   addu      $a0, $s0, $zero
    /* 1D38 8006A538 07000292 */  lbu        $v0, 0x7($s0)
    /* 1D3C 8006A53C 01000424 */  addiu      $a0, $zero, 0x1
    /* 1D40 8006A540 02004234 */  ori        $v0, $v0, 0x2
    /* 1D44 8006A544 070002A2 */  sb         $v0, 0x7($s0)
    /* 1D48 8006A548 0A002586 */  lh         $a1, 0xA($s1)
    /* 1D4C 8006A54C 95AB010C */  jal        func_8006AE54
    /* 1D50 8006A550 80000624 */   addiu     $a2, $zero, 0x80
    /* 1D54 8006A554 001A0200 */  sll        $v1, $v0, 8
    /* 1D58 8006A558 23186200 */  subu       $v1, $v1, $v0
    /* 1D5C 8006A55C 031B0300 */  sra        $v1, $v1, 12
    /* 1D60 8006A560 40010224 */  addiu      $v0, $zero, 0x140
    /* 1D64 8006A564 0C0002A6 */  sh         $v0, 0xC($s0)
    /* 1D68 8006A568 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 1D6C 8006A56C 21280002 */  addu       $a1, $s0, $zero
    /* 1D70 8006A570 060003A2 */  sb         $v1, 0x6($s0)
    /* 1D74 8006A574 050003A2 */  sb         $v1, 0x5($s0)
    /* 1D78 8006A578 040003A2 */  sb         $v1, 0x4($s0)
    /* 1D7C 8006A57C 0E0002A6 */  sh         $v0, 0xE($s0)
    /* 1D80 8006A580 080000A6 */  sh         $zero, 0x8($s0)
    /* 1D84 8006A584 0A0000A6 */  sh         $zero, 0xA($s0)
    /* 1D88 8006A588 0400448E */  lw         $a0, (0x1F800004 & 0xFFFF)($s2)
    /* 1D8C 8006A58C 35AD000C */  jal        AddPrim
    /* 1D90 8006A590 10001026 */   addiu     $s0, $s0, 0x10
    /* 1D94 8006A594 40000424 */  addiu      $a0, $zero, 0x40
    /* 1D98 8006A598 21280000 */  addu       $a1, $zero, $zero
    /* 1D9C 8006A59C 56AA010C */  jal        _insertTpage
    /* 1DA0 8006A5A0 000050AE */   sw        $s0, (0x1F800000 & 0xFFFF)($s2)
    /* 1DA4 8006A5A4 000042AE */  sw         $v0, (0x1F800000 & 0xFFFF)($s2)
    /* 1DA8 8006A5A8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1DAC 8006A5AC 1800B28F */  lw         $s2, 0x18($sp)
    /* 1DB0 8006A5B0 1400B18F */  lw         $s1, 0x14($sp)
    /* 1DB4 8006A5B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1DB8 8006A5B8 0800E003 */  jr         $ra
    /* 1DBC 8006A5BC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006A4D8
