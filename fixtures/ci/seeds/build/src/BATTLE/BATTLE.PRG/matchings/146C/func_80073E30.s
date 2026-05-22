nonmatching func_80073E30, 0x14C

glabel func_80073E30
    /* B630 80073E30 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* B634 80073E34 1800B0AF */  sw         $s0, 0x18($sp)
    /* B638 80073E38 21808000 */  addu       $s0, $a0, $zero
    /* B63C 80073E3C 2000BFAF */  sw         $ra, 0x20($sp)
    /* B640 80073E40 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* B644 80073E44 00000286 */  lh         $v0, 0x0($s0)
    /* B648 80073E48 00000000 */  nop
    /* B64C 80073E4C C0110200 */  sll        $v0, $v0, 7
    /* B650 80073E50 40004224 */  addiu      $v0, $v0, 0x40
    /* B654 80073E54 1000A2A7 */  sh         $v0, 0x10($sp)
    /* B658 80073E58 02000286 */  lh         $v0, 0x2($s0)
    /* B65C 80073E5C 00000000 */  nop
    /* B660 80073E60 C0110200 */  sll        $v0, $v0, 7
    /* B664 80073E64 40004224 */  addiu      $v0, $v0, 0x40
    /* B668 80073E68 1400A2A7 */  sh         $v0, 0x14($sp)
    /* B66C 80073E6C 0C000386 */  lh         $v1, 0xC($s0)
    /* B670 80073E70 01000224 */  addiu      $v0, $zero, 0x1
    /* B674 80073E74 0F006210 */  beq        $v1, $v0, .L80073EB4
    /* B678 80073E78 21880000 */   addu      $s1, $zero, $zero
    /* B67C 80073E7C 02006228 */  slti       $v0, $v1, 0x2
    /* B680 80073E80 05004010 */  beqz       $v0, .L80073E98
    /* B684 80073E84 00000000 */   nop
    /* B688 80073E88 08006010 */  beqz       $v1, .L80073EAC
    /* B68C 80073E8C 00000000 */   nop
    /* B690 80073E90 CECF0108 */  j          .L80073F38
    /* B694 80073E94 00000000 */   nop
  .L80073E98:
    /* B698 80073E98 03000224 */  addiu      $v0, $zero, 0x3
    /* B69C 80073E9C 05006210 */  beq        $v1, $v0, .L80073EB4
    /* B6A0 80073EA0 00000000 */   nop
    /* B6A4 80073EA4 CECF0108 */  j          .L80073F38
    /* B6A8 80073EA8 00000000 */   nop
  .L80073EAC:
    /* B6AC 80073EAC CECF0108 */  j          .L80073F38
    /* B6B0 80073EB0 01001124 */   addiu     $s1, $zero, 0x1
  .L80073EB4:
    /* B6B4 80073EB4 0E000496 */  lhu        $a0, 0xE($s0)
    /* B6B8 80073EB8 00000000 */  nop
    /* B6BC 80073EBC B6018424 */  addiu      $a0, $a0, 0x1B6
    /* B6C0 80073EC0 00240400 */  sll        $a0, $a0, 16
    /* B6C4 80073EC4 FDFA020C */  jal        vs_battle_getStateFlag
    /* B6C8 80073EC8 03240400 */   sra       $a0, $a0, 16
    /* B6CC 80073ECC FF004230 */  andi       $v0, $v0, 0xFF
    /* B6D0 80073ED0 14004014 */  bnez       $v0, .L80073F24
    /* B6D4 80073ED4 04000424 */   addiu     $a0, $zero, 0x4
    /* B6D8 80073ED8 0E000486 */  lh         $a0, 0xE($s0)
    /* B6DC 80073EDC 15F9010C */  jal        vs_battle_itemIdIsInInventory
    /* B6E0 80073EE0 00000000 */   nop
    /* B6E4 80073EE4 14004010 */  beqz       $v0, .L80073F38
    /* B6E8 80073EE8 01000524 */   addiu     $a1, $zero, 0x1
    /* B6EC 80073EEC 0E000496 */  lhu        $a0, 0xE($s0)
    /* B6F0 80073EF0 00000000 */  nop
    /* B6F4 80073EF4 B6018424 */  addiu      $a0, $a0, 0x1B6
    /* B6F8 80073EF8 00240400 */  sll        $a0, $a0, 16
    /* B6FC 80073EFC 05FB020C */  jal        vs_battle_setStateFlag
    /* B700 80073F00 03240400 */   sra       $a0, $a0, 16
    /* B704 80073F04 0E000486 */  lh         $a0, 0xE($s0)
    /* B708 80073F08 00000000 */  nop
    /* B70C 80073F0C D2018228 */  slti       $v0, $a0, 0x1D2
    /* B710 80073F10 03004014 */  bnez       $v0, .L80073F20
    /* B714 80073F14 00000000 */   nop
    /* B718 80073F18 E732030C */  jal        vs_battle_decreaseMiscCount
    /* B71C 80073F1C 00000000 */   nop
  .L80073F20:
    /* B720 80073F20 04000424 */  addiu      $a0, $zero, 0x4
  .L80073F24:
    /* B724 80073F24 01000624 */  addiu      $a2, $zero, 0x1
    /* B728 80073F28 0E000586 */  lh         $a1, 0xE($s0)
    /* B72C 80073F2C 2188C000 */  addu       $s1, $a2, $zero
    /* B730 80073F30 AE2C030C */  jal        vs_battle_displaySceneMessage
    /* B734 80073F34 0C0000A6 */   sh        $zero, 0xC($s0)
  .L80073F38:
    /* B738 80073F38 08002012 */  beqz       $s1, .L80073F5C
    /* B73C 80073F3C 21200000 */   addu      $a0, $zero, $zero
    /* B740 80073F40 1000A527 */  addiu      $a1, $sp, 0x10
    /* B744 80073F44 1C78020C */  jal        func_8009E070
    /* B748 80073F48 02000624 */   addiu     $a2, $zero, 0x2
    /* B74C 80073F4C 7F35020C */  jal        func_8008D5FC
    /* B750 80073F50 21200002 */   addu      $a0, $s0, $zero
    /* B754 80073F54 DACF0108 */  j          .L80073F68
    /* B758 80073F58 00000000 */   nop
  .L80073F5C:
    /* B75C 80073F5C 1000A527 */  addiu      $a1, $sp, 0x10
    /* B760 80073F60 1C78020C */  jal        func_8009E070
    /* B764 80073F64 03000624 */   addiu     $a2, $zero, 0x3
  .L80073F68:
    /* B768 80073F68 2000BF8F */  lw         $ra, 0x20($sp)
    /* B76C 80073F6C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* B770 80073F70 1800B08F */  lw         $s0, 0x18($sp)
    /* B774 80073F74 0800E003 */  jr         $ra
    /* B778 80073F78 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80073E30
