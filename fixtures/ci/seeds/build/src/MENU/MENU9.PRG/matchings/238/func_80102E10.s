nonmatching func_80102E10, 0xFC

glabel func_80102E10
    /* 610 80102E10 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 614 80102E14 1800BEAF */  sw         $fp, 0x18($sp)
    /* 618 80102E18 21F0A003 */  addu       $fp, $sp, $zero
    /* 61C 80102E1C 21408000 */  addu       $t0, $a0, $zero
    /* 620 80102E20 40110800 */  sll        $v0, $t0, 5
    /* 624 80102E24 C2100200 */  srl        $v0, $v0, 3
    /* 628 80102E28 07004224 */  addiu      $v0, $v0, 0x7
    /* 62C 80102E2C C2100200 */  srl        $v0, $v0, 3
    /* 630 80102E30 C0100200 */  sll        $v0, $v0, 3
    /* 634 80102E34 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 638 80102E38 1400B1AF */  sw         $s1, 0x14($sp)
    /* 63C 80102E3C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 640 80102E40 23E8A203 */  subu       $sp, $sp, $v0
    /* 644 80102E44 21180000 */  addu       $v1, $zero, $zero
    /* 648 80102E48 07000019 */  blez       $t0, .L80102E68
    /* 64C 80102E4C 1000A727 */   addiu     $a3, $sp, 0x10
    /* 650 80102E50 2120E000 */  addu       $a0, $a3, $zero
  .L80102E54:
    /* 654 80102E54 000080AC */  sw         $zero, 0x0($a0)
    /* 658 80102E58 01006324 */  addiu      $v1, $v1, 0x1
    /* 65C 80102E5C 2A106800 */  slt        $v0, $v1, $t0
    /* 660 80102E60 FCFF4014 */  bnez       $v0, .L80102E54
    /* 664 80102E64 04008424 */   addiu     $a0, $a0, 0x4
  .L80102E68:
    /* 668 80102E68 09000229 */  slti       $v0, $t0, 0x9
    /* 66C 80102E6C 04004014 */  bnez       $v0, .L80102E80
    /* 670 80102E70 0F80023C */   lui       $v0, %hi(D_800F4EE8)
    /* 674 80102E74 0800A228 */  slti       $v0, $a1, 0x8
    /* 678 80102E78 05004010 */  beqz       $v0, .L80102E90
    /* 67C 80102E7C 0F80023C */   lui       $v0, %hi(D_800F4EE8)
  .L80102E80:
    /* 680 80102E80 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 684 80102E84 020045A0 */  sb         $a1, 0x2($v0)
    /* 688 80102E88 B30B0408 */  j          .L80102ECC
    /* 68C 80102E8C 030040A0 */   sb        $zero, 0x3($v0)
  .L80102E90:
    /* 690 80102E90 F8FF0225 */  addiu      $v0, $t0, -0x8
    /* 694 80102E94 2A10A200 */  slt        $v0, $a1, $v0
    /* 698 80102E98 07004014 */  bnez       $v0, .L80102EB8
    /* 69C 80102E9C 0F80023C */   lui       $v0, %hi(D_800F4EE8)
    /* 6A0 80102EA0 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 6A4 80102EA4 F7FF0425 */  addiu      $a0, $t0, -0x9
    /* 6A8 80102EA8 2318A400 */  subu       $v1, $a1, $a0
    /* 6AC 80102EAC 020043A0 */  sb         $v1, 0x2($v0)
    /* 6B0 80102EB0 B30B0408 */  j          .L80102ECC
    /* 6B4 80102EB4 030044A0 */   sb        $a0, 0x3($v0)
  .L80102EB8:
    /* 6B8 80102EB8 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 6BC 80102EBC 04000324 */  addiu      $v1, $zero, 0x4
    /* 6C0 80102EC0 020043A0 */  sb         $v1, 0x2($v0)
    /* 6C4 80102EC4 FCFFA324 */  addiu      $v1, $a1, -0x4
    /* 6C8 80102EC8 030043A0 */  sb         $v1, 0x3($v0)
  .L80102ECC:
    /* 6CC 80102ECC 0680103C */  lui        $s0, %hi(vs_main_settings)
    /* 6D0 80102ED0 20001026 */  addiu      $s0, $s0, %lo(vs_main_settings)
    /* 6D4 80102ED4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6D8 80102ED8 21200001 */  addu       $a0, $t0, $zero
    /* 6DC 80102EDC 01001192 */  lbu        $s1, 0x1($s0)
    /* 6E0 80102EE0 01010524 */  addiu      $a1, $zero, 0x101
    /* 6E4 80102EE4 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 6E8 80102EE8 010002A2 */   sb        $v0, 0x1($s0)
    /* 6EC 80102EEC 010011A2 */  sb         $s1, 0x1($s0)
    /* 6F0 80102EF0 21E8C003 */  addu       $sp, $fp, $zero
    /* 6F4 80102EF4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6F8 80102EF8 1800BE8F */  lw         $fp, 0x18($sp)
    /* 6FC 80102EFC 1400B18F */  lw         $s1, 0x14($sp)
    /* 700 80102F00 1000B08F */  lw         $s0, 0x10($sp)
    /* 704 80102F04 0800E003 */  jr         $ra
    /* 708 80102F08 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80102E10
