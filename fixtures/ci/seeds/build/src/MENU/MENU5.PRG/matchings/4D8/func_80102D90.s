nonmatching func_80102D90, 0x148

glabel func_80102D90
    /* 590 80102D90 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 594 80102D94 1800BEAF */  sw         $fp, 0x18($sp)
    /* 598 80102D98 21F0A003 */  addu       $fp, $sp, $zero
    /* 59C 80102D9C 21408000 */  addu       $t0, $a0, $zero
    /* 5A0 80102DA0 40110800 */  sll        $v0, $t0, 5
    /* 5A4 80102DA4 C2100200 */  srl        $v0, $v0, 3
    /* 5A8 80102DA8 07004224 */  addiu      $v0, $v0, 0x7
    /* 5AC 80102DAC C2100200 */  srl        $v0, $v0, 3
    /* 5B0 80102DB0 C0100200 */  sll        $v0, $v0, 3
    /* 5B4 80102DB4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 5B8 80102DB8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5BC 80102DBC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5C0 80102DC0 23E8A203 */  subu       $sp, $sp, $v0
    /* 5C4 80102DC4 1180043C */  lui        $a0, %hi(func_801083F8)
    /* 5C8 80102DC8 F883838C */  lw         $v1, %lo(func_801083F8)($a0)
    /* 5CC 80102DCC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 5D0 80102DD0 02006214 */  bne        $v1, $v0, .L80102DDC
    /* 5D4 80102DD4 1000A727 */   addiu     $a3, $sp, 0x10
    /* 5D8 80102DD8 F88385AC */  sw         $a1, %lo(func_801083F8)($a0)
  .L80102DDC:
    /* 5DC 80102DDC 07000019 */  blez       $t0, .L80102DFC
    /* 5E0 80102DE0 21180000 */   addu      $v1, $zero, $zero
    /* 5E4 80102DE4 2120E000 */  addu       $a0, $a3, $zero
  .L80102DE8:
    /* 5E8 80102DE8 000080AC */  sw         $zero, 0x0($a0)
    /* 5EC 80102DEC 01006324 */  addiu      $v1, $v1, 0x1
    /* 5F0 80102DF0 2A106800 */  slt        $v0, $v1, $t0
    /* 5F4 80102DF4 FCFF4014 */  bnez       $v0, .L80102DE8
    /* 5F8 80102DF8 04008424 */   addiu     $a0, $a0, 0x4
  .L80102DFC:
    /* 5FC 80102DFC 8000A230 */  andi       $v0, $a1, 0x80
    /* 600 80102E00 0D004014 */  bnez       $v0, .L80102E38
    /* 604 80102E04 09000229 */   slti      $v0, $t0, 0x9
    /* 608 80102E08 1180023C */  lui        $v0, %hi(func_801083F8)
    /* 60C 80102E0C F883438C */  lw         $v1, %lo(func_801083F8)($v0)
    /* 610 80102E10 00000000 */  nop
    /* 614 80102E14 2A106800 */  slt        $v0, $v1, $t0
    /* 618 80102E18 06004010 */  beqz       $v0, .L80102E34
    /* 61C 80102E1C 80180300 */   sll       $v1, $v1, 2
    /* 620 80102E20 2118E300 */  addu       $v1, $a3, $v1
    /* 624 80102E24 0000628C */  lw         $v0, 0x0($v1)
    /* 628 80102E28 00000000 */  nop
    /* 62C 80102E2C 04004234 */  ori        $v0, $v0, 0x4
    /* 630 80102E30 000062AC */  sw         $v0, 0x0($v1)
  .L80102E34:
    /* 634 80102E34 09000229 */  slti       $v0, $t0, 0x9
  .L80102E38:
    /* 638 80102E38 04004014 */  bnez       $v0, .L80102E4C
    /* 63C 80102E3C 7F00A530 */   andi      $a1, $a1, 0x7F
    /* 640 80102E40 0800A228 */  slti       $v0, $a1, 0x8
    /* 644 80102E44 06004010 */  beqz       $v0, .L80102E60
    /* 648 80102E48 F8FF0225 */   addiu     $v0, $t0, -0x8
  .L80102E4C:
    /* 64C 80102E4C 0F80023C */  lui        $v0, %hi(D_800F4EE8)
    /* 650 80102E50 E84E45A0 */  sb         $a1, %lo(D_800F4EE8)($v0)
    /* 654 80102E54 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 658 80102E58 A60B0408 */  j          .L80102E98
    /* 65C 80102E5C 010040A0 */   sb        $zero, 0x1($v0)
  .L80102E60:
    /* 660 80102E60 2A10A200 */  slt        $v0, $a1, $v0
    /* 664 80102E64 07004014 */  bnez       $v0, .L80102E84
    /* 668 80102E68 0F80023C */   lui       $v0, %hi(D_800F4EE8)
    /* 66C 80102E6C F7FF0425 */  addiu      $a0, $t0, -0x9
    /* 670 80102E70 2318A400 */  subu       $v1, $a1, $a0
    /* 674 80102E74 E84E43A0 */  sb         $v1, %lo(D_800F4EE8)($v0)
    /* 678 80102E78 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 67C 80102E7C A60B0408 */  j          .L80102E98
    /* 680 80102E80 010044A0 */   sb        $a0, 0x1($v0)
  .L80102E84:
    /* 684 80102E84 04000324 */  addiu      $v1, $zero, 0x4
    /* 688 80102E88 E84E43A0 */  sb         $v1, %lo(D_800F4EE8)($v0)
    /* 68C 80102E8C E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 690 80102E90 FCFFA324 */  addiu      $v1, $a1, -0x4
    /* 694 80102E94 010043A0 */  sb         $v1, 0x1($v0)
  .L80102E98:
    /* 698 80102E98 0680103C */  lui        $s0, %hi(vs_main_settings)
    /* 69C 80102E9C 20001026 */  addiu      $s0, $s0, %lo(vs_main_settings)
    /* 6A0 80102EA0 01000224 */  addiu      $v0, $zero, 0x1
    /* 6A4 80102EA4 21200001 */  addu       $a0, $t0, $zero
    /* 6A8 80102EA8 01001192 */  lbu        $s1, 0x1($s0)
    /* 6AC 80102EAC 00010524 */  addiu      $a1, $zero, 0x100
    /* 6B0 80102EB0 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 6B4 80102EB4 010002A2 */   sb        $v0, 0x1($s0)
    /* 6B8 80102EB8 010011A2 */  sb         $s1, 0x1($s0)
    /* 6BC 80102EBC 21E8C003 */  addu       $sp, $fp, $zero
    /* 6C0 80102EC0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6C4 80102EC4 1800BE8F */  lw         $fp, 0x18($sp)
    /* 6C8 80102EC8 1400B18F */  lw         $s1, 0x14($sp)
    /* 6CC 80102ECC 1000B08F */  lw         $s0, 0x10($sp)
    /* 6D0 80102ED0 0800E003 */  jr         $ra
    /* 6D4 80102ED4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80102D90
