nonmatching vs_menuB_exec, 0x3BC

glabel vs_menuB_exec
    /* 7690 80109E90 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7694 80109E94 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7698 80109E98 21888000 */  addu       $s1, $a0, $zero
    /* 769C 80109E9C 1180023C */  lui        $v0, %hi(D_8010A6B7)
    /* 76A0 80109EA0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 76A4 80109EA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 76A8 80109EA8 B7A640A0 */  sb         $zero, %lo(D_8010A6B7)($v0)
    /* 76AC 80109EAC 00002392 */  lbu        $v1, 0x0($s1)
    /* 76B0 80109EB0 00000000 */  nop
    /* 76B4 80109EB4 0600622C */  sltiu      $v0, $v1, 0x6
    /* 76B8 80109EB8 8D004010 */  beqz       $v0, .L8010A0F0
    /* 76BC 80109EBC 1080023C */   lui       $v0, %hi(jtbl_80102A48)
    /* 76C0 80109EC0 482A4224 */  addiu      $v0, $v0, %lo(jtbl_80102A48)
    /* 76C4 80109EC4 80180300 */  sll        $v1, $v1, 2
    /* 76C8 80109EC8 21186200 */  addu       $v1, $v1, $v0
    /* 76CC 80109ECC 0000628C */  lw         $v0, 0x0($v1)
    /* 76D0 80109ED0 00000000 */  nop
    /* 76D4 80109ED4 08004000 */  jr         $v0
    /* 76D8 80109ED8 00000000 */   nop
    /* 76DC 80109EDC B600030C */  jal        vs_battle_playSfx10
    /* 76E0 80109EE0 21800000 */   addu      $s0, $zero, $zero
    /* 76E4 80109EE4 60EF030C */  jal        func_800FBD80
    /* 76E8 80109EE8 10000424 */   addiu     $a0, $zero, 0x10
  .L80109EEC:
    /* 76EC 80109EEC 2CFA030C */  jal        vs_mainMenu_rebuildInventory
    /* 76F0 80109EF0 21200002 */   addu      $a0, $s0, $zero
    /* 76F4 80109EF4 01001026 */  addiu      $s0, $s0, 0x1
    /* 76F8 80109EF8 0700022A */  slti       $v0, $s0, 0x7
    /* 76FC 80109EFC FBFF4014 */  bnez       $v0, .L80109EEC
    /* 7700 80109F00 00000000 */   nop
    /* 7704 80109F04 8F0F010C */  jal        vs_main_allocHeapR
    /* 7708 80109F08 00230424 */   addiu     $a0, $zero, 0x2300
    /* 770C 80109F0C 01000424 */  addiu      $a0, $zero, 0x1
    /* 7710 80109F10 1180033C */  lui        $v1, %hi(_inventory)
    /* 7714 80109F14 1180053C */  lui        $a1, %hi(D_8010A6AC)
    /* 7718 80109F18 A8A662AC */  sw         $v0, %lo(_inventory)($v1)
    /* 771C 80109F1C 000F4324 */  addiu      $v1, $v0, 0xF00
    /* 7720 80109F20 ACA6A3AC */  sw         $v1, %lo(D_8010A6AC)($a1)
    /* 7724 80109F24 1180053C */  lui        $a1, %hi(D_8010A6A0)
    /* 7728 80109F28 001E4324 */  addiu      $v1, $v0, 0x1E00
    /* 772C 80109F2C A0A6A3AC */  sw         $v1, %lo(D_8010A6A0)($a1)
    /* 7730 80109F30 1180033C */  lui        $v1, %hi(D_8010A6A4)
    /* 7734 80109F34 80204224 */  addiu      $v0, $v0, 0x2080
    /* 7738 80109F38 A4A662AC */  sw         $v0, %lo(D_8010A6A4)($v1)
    /* 773C 80109F3C 1180023C */  lui        $v0, %hi(D_8010A6B8)
    /* 7740 80109F40 B8A640A0 */  sb         $zero, %lo(D_8010A6B8)($v0)
    /* 7744 80109F44 1180023C */  lui        $v0, %hi(D_8010A6B6)
    /* 7748 80109F48 B6A640A0 */  sb         $zero, %lo(D_8010A6B6)($v0)
    /* 774C 80109F4C 1180023C */  lui        $v0, %hi(D_8010A6B5)
    /* 7750 80109F50 B5A640A0 */  sb         $zero, %lo(D_8010A6B5)($v0)
    /* 7754 80109F54 1180023C */  lui        $v0, %hi(D_8010A69E)
    /* 7758 80109F58 73F9030C */  jal        vs_mainMenu_loadItemNames
    /* 775C 80109F5C 9EA640A0 */   sb        $zero, %lo(D_8010A69E)($v0)
    /* 7760 80109F60 0F80023C */  lui        $v0, %hi(D_800EB9C4)
    /* 7764 80109F64 C4B9448C */  lw         $a0, %lo(D_800EB9C4)($v0)
    /* 7768 80109F68 3522040C */  jal        func_801088D4
    /* 776C 80109F6C 00000000 */   nop
    /* 7770 80109F70 1180023C */  lui        $v0, %hi(D_8010A505)
    /* 7774 80109F74 05A540A0 */  sb         $zero, %lo(D_8010A505)($v0)
    /* 7778 80109F78 1180023C */  lui        $v0, %hi(D_8010A6B0)
    /* 777C 80109F7C 01000424 */  addiu      $a0, $zero, 0x1
    /* 7780 80109F80 B0A644A0 */  sb         $a0, %lo(D_8010A6B0)($v0)
    /* 7784 80109F84 1180023C */  lui        $v0, %hi(D_8010A6B1)
    /* 7788 80109F88 0A000324 */  addiu      $v1, $zero, 0xA
    /* 778C 80109F8C B1A643A0 */  sb         $v1, %lo(D_8010A6B1)($v0)
    /* 7790 80109F90 1180023C */  lui        $v0, %hi(D_8010A6B2)
    /* 7794 80109F94 B2A640A0 */  sb         $zero, %lo(D_8010A6B2)($v0)
    /* 7798 80109F98 1180023C */  lui        $v0, %hi(D_8010A6B3)
    /* 779C 80109F9C B3A643A0 */  sb         $v1, %lo(D_8010A6B3)($v0)
    /* 77A0 80109FA0 3C280408 */  j          .L8010A0F0
    /* 77A4 80109FA4 000024A2 */   sb        $a0, 0x0($s1)
    /* 77A8 80109FA8 73F9030C */  jal        vs_mainMenu_loadItemNames
    /* 77AC 80109FAC 21200000 */   addu      $a0, $zero, $zero
    /* 77B0 80109FB0 4F004010 */  beqz       $v0, .L8010A0F0
    /* 77B4 80109FB4 1180043C */   lui       $a0, %hi(D_8010A6B2)
    /* 77B8 80109FB8 1180023C */  lui        $v0, %hi(D_8010A6B6)
    /* 77BC 80109FBC B6A64390 */  lbu        $v1, %lo(D_8010A6B6)($v0)
    /* 77C0 80109FC0 01000224 */  addiu      $v0, $zero, 0x1
    /* 77C4 80109FC4 09006014 */  bnez       $v1, .L80109FEC
    /* 77C8 80109FC8 B2A682A0 */   sb        $v0, %lo(D_8010A6B2)($a0)
    /* 77CC 80109FCC 8123030C */  jal        func_800C8E04
    /* 77D0 80109FD0 01000424 */   addiu     $a0, $zero, 0x1
    /* 77D4 80109FD4 1180043C */  lui        $a0, %hi(D_8010A2C4)
    /* 77D8 80109FD8 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 77DC 80109FDC C4A28424 */   addiu     $a0, $a0, %lo(D_8010A2C4)
    /* 77E0 80109FE0 04000224 */  addiu      $v0, $zero, 0x4
    /* 77E4 80109FE4 3C280408 */  j          .L8010A0F0
    /* 77E8 80109FE8 000022A2 */   sb        $v0, 0x0($s1)
  .L80109FEC:
    /* 77EC 80109FEC F2FE030C */  jal        func_800FFBC8
    /* 77F0 80109FF0 00000000 */   nop
    /* 77F4 80109FF4 02000224 */  addiu      $v0, $zero, 0x2
    /* 77F8 80109FF8 3C280408 */  j          .L8010A0F0
    /* 77FC 80109FFC 000022A2 */   sb        $v0, 0x0($s1)
    /* 7800 8010A000 74EA030C */  jal        vs_mainmenu_ready
    /* 7804 8010A004 00000000 */   nop
    /* 7808 8010A008 39004010 */  beqz       $v0, .L8010A0F0
    /* 780C 8010A00C 1180023C */   lui       $v0, %hi(D_8010A6B3)
    /* 7810 8010A010 B3A64290 */  lbu        $v0, %lo(D_8010A6B3)($v0)
    /* 7814 8010A014 00000000 */  nop
    /* 7818 8010A018 36004014 */  bnez       $v0, .L8010A0F4
    /* 781C 8010A01C 1180023C */   lui       $v0, %hi(D_8010A6B0)
    /* 7820 8010A020 D425040C */  jal        func_80109750
    /* 7824 8010A024 01000424 */   addiu     $a0, $zero, 0x1
    /* 7828 8010A028 03000224 */  addiu      $v0, $zero, 0x3
    /* 782C 8010A02C 000022A2 */  sb         $v0, 0x0($s1)
    /* 7830 8010A030 D425040C */  jal        func_80109750
    /* 7834 8010A034 21200000 */   addu      $a0, $zero, $zero
    /* 7838 8010A038 21804000 */  addu       $s0, $v0, $zero
    /* 783C 8010A03C 2C000012 */  beqz       $s0, .L8010A0F0
    /* 7840 8010A040 0F80023C */   lui       $v0, %hi(D_800F4E98 + 0x2)
    /* 7844 8010A044 0100033A */  xori       $v1, $s0, 0x1
    /* 7848 8010A048 0100632C */  sltiu      $v1, $v1, 0x1
    /* 784C 8010A04C 20280408 */  j          .L8010A080
    /* 7850 8010A050 9A4E43A4 */   sh        $v1, %lo(D_800F4E98 + 0x2)($v0)
    /* 7854 8010A054 0F80023C */  lui        $v0, %hi(D_800F5130)
    /* 7858 8010A058 3051428C */  lw         $v0, %lo(D_800F5130)($v0)
    /* 785C 8010A05C 00000000 */  nop
    /* 7860 8010A060 82170200 */  srl        $v0, $v0, 30
    /* 7864 8010A064 01004230 */  andi       $v0, $v0, 0x1
    /* 7868 8010A068 21004010 */  beqz       $v0, .L8010A0F0
    /* 786C 8010A06C 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 7870 8010A070 D0E14290 */  lbu        $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 7874 8010A074 00000000 */  nop
    /* 7878 8010A078 1E004010 */  beqz       $v0, .L8010A0F4
    /* 787C 8010A07C 1180023C */   lui       $v0, %hi(D_8010A6B0)
  .L8010A080:
    /* 7880 8010A080 05000224 */  addiu      $v0, $zero, 0x5
    /* 7884 8010A084 3C280408 */  j          .L8010A0F0
    /* 7888 8010A088 000022A2 */   sb        $v0, 0x0($s1)
    /* 788C 8010A08C 07000424 */  addiu      $a0, $zero, 0x7
    /* 7890 8010A090 1180023C */  lui        $v0, %hi(D_8010A6B0)
    /* 7894 8010A094 B0A640A0 */  sb         $zero, %lo(D_8010A6B0)($v0)
    /* 7898 8010A098 1180023C */  lui        $v0, %hi(D_8010A6B2)
    /* 789C 8010A09C 1934030C */  jal        vs_battle_dismissTextBox
    /* 78A0 8010A0A0 B2A640A0 */   sb        $zero, %lo(D_8010A6B2)($v0)
    /* 78A4 8010A0A4 13004014 */  bnez       $v0, .L8010A0F4
    /* 78A8 8010A0A8 1180023C */   lui       $v0, %hi(D_8010A6B0)
    /* 78AC 8010A0AC A5F9030C */  jal        vs_mainMenu_ensureItemNamesLoaded
    /* 78B0 8010A0B0 00000000 */   nop
    /* 78B4 8010A0B4 0E004010 */  beqz       $v0, .L8010A0F0
    /* 78B8 8010A0B8 1180023C */   lui       $v0, %hi(_inventory)
    /* 78BC 8010A0BC A8A6448C */  lw         $a0, %lo(_inventory)($v0)
    /* 78C0 8010A0C0 180F010C */  jal        vs_main_freeHeapR
    /* 78C4 8010A0C4 00000000 */   nop
    /* 78C8 8010A0C8 0F80023C */  lui        $v0, %hi(D_800EB9C4)
    /* 78CC 8010A0CC C4B9428C */  lw         $v0, %lo(D_800EB9C4)($v0)
    /* 78D0 8010A0D0 00000000 */  nop
    /* 78D4 8010A0D4 03004010 */  beqz       $v0, .L8010A0E4
    /* 78D8 8010A0D8 00000000 */   nop
    /* 78DC 8010A0DC BF29020C */  jal        func_8008A6FC
    /* 78E0 8010A0E0 00000000 */   nop
  .L8010A0E4:
    /* 78E4 8010A0E4 000020A2 */  sb         $zero, 0x0($s1)
    /* 78E8 8010A0E8 8E280408 */  j          .L8010A238
    /* 78EC 8010A0EC 01000224 */   addiu     $v0, $zero, 0x1
  .L8010A0F0:
    /* 78F0 8010A0F0 1180023C */  lui        $v0, %hi(D_8010A6B0)
  .L8010A0F4:
    /* 78F4 8010A0F4 B0A64290 */  lbu        $v0, %lo(D_8010A6B0)($v0)
    /* 78F8 8010A0F8 00000000 */  nop
    /* 78FC 8010A0FC 0D004010 */  beqz       $v0, .L8010A134
    /* 7900 8010A100 1180033C */   lui       $v1, %hi(D_8010A6B1)
    /* 7904 8010A104 B1A66290 */  lbu        $v0, %lo(D_8010A6B1)($v1)
    /* 7908 8010A108 00000000 */  nop
    /* 790C 8010A10C 02004010 */  beqz       $v0, .L8010A118
    /* 7910 8010A110 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 7914 8010A114 B1A662A0 */  sb         $v0, %lo(D_8010A6B1)($v1)
  .L8010A118:
    /* 7918 8010A118 0F80023C */  lui        $v0, %hi(vs_battle_rowAnimationSteps)
    /* 791C 8010A11C B1A66390 */  lbu        $v1, %lo(D_8010A6B1)($v1)
    /* 7920 8010A120 C8BB4224 */  addiu      $v0, $v0, %lo(vs_battle_rowAnimationSteps)
    /* 7924 8010A124 21186200 */  addu       $v1, $v1, $v0
    /* 7928 8010A128 00007090 */  lbu        $s0, 0x0($v1)
    /* 792C 8010A12C 58280408 */  j          .L8010A160
    /* 7930 8010A130 1180023C */   lui       $v0, %hi(D_8010A6B1)
  .L8010A134:
    /* 7934 8010A134 1180043C */  lui        $a0, %hi(D_8010A6B1)
    /* 7938 8010A138 B1A68390 */  lbu        $v1, %lo(D_8010A6B1)($a0)
    /* 793C 8010A13C 00000000 */  nop
    /* 7940 8010A140 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 7944 8010A144 02004010 */  beqz       $v0, .L8010A150
    /* 7948 8010A148 01006224 */   addiu     $v0, $v1, 0x1
    /* 794C 8010A14C B1A682A0 */  sb         $v0, %lo(D_8010A6B1)($a0)
  .L8010A150:
    /* 7950 8010A150 B1A68290 */  lbu        $v0, %lo(D_8010A6B1)($a0)
    /* 7954 8010A154 00000000 */  nop
    /* 7958 8010A158 40810200 */  sll        $s0, $v0, 5
    /* 795C 8010A15C 1180023C */  lui        $v0, %hi(D_8010A6B1)
  .L8010A160:
    /* 7960 8010A160 B1A64290 */  lbu        $v0, %lo(D_8010A6B1)($v0)
    /* 7964 8010A164 00000000 */  nop
    /* 7968 8010A168 0A00422C */  sltiu      $v0, $v0, 0xA
    /* 796C 8010A16C 04004010 */  beqz       $v0, .L8010A180
    /* 7970 8010A170 1180023C */   lui       $v0, %hi(D_8010A6B2)
    /* 7974 8010A174 DF20040C */  jal        _displayInventoryCapacities
    /* 7978 8010A178 21200002 */   addu      $a0, $s0, $zero
    /* 797C 8010A17C 1180023C */  lui        $v0, %hi(D_8010A6B2)
  .L8010A180:
    /* 7980 8010A180 B2A64290 */  lbu        $v0, %lo(D_8010A6B2)($v0)
    /* 7984 8010A184 00000000 */  nop
    /* 7988 8010A188 0D004010 */  beqz       $v0, .L8010A1C0
    /* 798C 8010A18C 1180033C */   lui       $v1, %hi(D_8010A6B3)
    /* 7990 8010A190 B3A66290 */  lbu        $v0, %lo(D_8010A6B3)($v1)
    /* 7994 8010A194 00000000 */  nop
    /* 7998 8010A198 02004010 */  beqz       $v0, .L8010A1A4
    /* 799C 8010A19C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 79A0 8010A1A0 B3A662A0 */  sb         $v0, %lo(D_8010A6B3)($v1)
  .L8010A1A4:
    /* 79A4 8010A1A4 0F80023C */  lui        $v0, %hi(vs_battle_rowAnimationSteps)
    /* 79A8 8010A1A8 B3A66390 */  lbu        $v1, %lo(D_8010A6B3)($v1)
    /* 79AC 8010A1AC C8BB4224 */  addiu      $v0, $v0, %lo(vs_battle_rowAnimationSteps)
    /* 79B0 8010A1B0 21186200 */  addu       $v1, $v1, $v0
    /* 79B4 8010A1B4 00007090 */  lbu        $s0, 0x0($v1)
    /* 79B8 8010A1B8 7B280408 */  j          .L8010A1EC
    /* 79BC 8010A1BC 1180023C */   lui       $v0, %hi(D_8010A6B3)
  .L8010A1C0:
    /* 79C0 8010A1C0 1180043C */  lui        $a0, %hi(D_8010A6B3)
    /* 79C4 8010A1C4 B3A68390 */  lbu        $v1, %lo(D_8010A6B3)($a0)
    /* 79C8 8010A1C8 00000000 */  nop
    /* 79CC 8010A1CC 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 79D0 8010A1D0 02004010 */  beqz       $v0, .L8010A1DC
    /* 79D4 8010A1D4 01006224 */   addiu     $v0, $v1, 0x1
    /* 79D8 8010A1D8 B3A682A0 */  sb         $v0, %lo(D_8010A6B3)($a0)
  .L8010A1DC:
    /* 79DC 8010A1DC B3A68290 */  lbu        $v0, %lo(D_8010A6B3)($a0)
    /* 79E0 8010A1E0 00000000 */  nop
    /* 79E4 8010A1E4 40810200 */  sll        $s0, $v0, 5
    /* 79E8 8010A1E8 1180023C */  lui        $v0, %hi(D_8010A6B3)
  .L8010A1EC:
    /* 79EC 8010A1EC B3A64290 */  lbu        $v0, %lo(D_8010A6B3)($v0)
    /* 79F0 8010A1F0 00000000 */  nop
    /* 79F4 8010A1F4 0A00422C */  sltiu      $v0, $v0, 0xA
    /* 79F8 8010A1F8 0F004010 */  beqz       $v0, .L8010A238
    /* 79FC 8010A1FC 21100000 */   addu      $v0, $zero, $zero
    /* 7A00 8010A200 4E22040C */  jal        func_80108938
    /* 7A04 8010A204 21200002 */   addu      $a0, $s0, $zero
    /* 7A08 8010A208 1180033C */  lui        $v1, %hi(D_8010A6B7)
    /* 7A0C 8010A20C B7A66290 */  lbu        $v0, %lo(D_8010A6B7)($v1)
    /* 7A10 8010A210 00000000 */  nop
    /* 7A14 8010A214 0F004230 */  andi       $v0, $v0, 0xF
    /* 7A18 8010A218 07004010 */  beqz       $v0, .L8010A238
    /* 7A1C 8010A21C 21100000 */   addu      $v0, $zero, $zero
    /* 7A20 8010A220 B7A66490 */  lbu        $a0, %lo(D_8010A6B7)($v1)
    /* 7A24 8010A224 9223030C */  jal        vs_battle_getMenuItem
    /* 7A28 8010A228 1F008424 */   addiu     $a0, $a0, 0x1F
    /* 7A2C 8010A22C 01000324 */  addiu      $v1, $zero, 0x1
    /* 7A30 8010A230 060043A0 */  sb         $v1, 0x6($v0)
    /* 7A34 8010A234 21100000 */  addu       $v0, $zero, $zero
  .L8010A238:
    /* 7A38 8010A238 1800BF8F */  lw         $ra, 0x18($sp)
    /* 7A3C 8010A23C 1400B18F */  lw         $s1, 0x14($sp)
    /* 7A40 8010A240 1000B08F */  lw         $s0, 0x10($sp)
    /* 7A44 8010A244 0800E003 */  jr         $ra
    /* 7A48 8010A248 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel vs_menuB_exec
