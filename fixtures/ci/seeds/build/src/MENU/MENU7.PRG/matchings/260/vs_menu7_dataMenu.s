nonmatching vs_menu7_dataMenu, 0x3FC

glabel vs_menu7_dataMenu
    /* 76B8 80109EB8 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 76BC 80109EBC 3800B2AF */  sw         $s2, 0x38($sp)
    /* 76C0 80109EC0 21908000 */  addu       $s2, $a0, $zero
    /* 76C4 80109EC4 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 76C8 80109EC8 3400B1AF */  sw         $s1, 0x34($sp)
    /* 76CC 80109ECC 3000B0AF */  sw         $s0, 0x30($sp)
    /* 76D0 80109ED0 00004292 */  lbu        $v0, 0x0($s2)
    /* 76D4 80109ED4 00000000 */  nop
    /* 76D8 80109ED8 0B00422C */  sltiu      $v0, $v0, 0xB
    /* 76DC 80109EDC 03004010 */  beqz       $v0, .L80109EEC
    /* 76E0 80109EE0 00000000 */   nop
    /* 76E4 80109EE4 5927040C */  jal        func_80109D64
    /* 76E8 80109EE8 00000000 */   nop
  .L80109EEC:
    /* 76EC 80109EEC 00004292 */  lbu        $v0, 0x0($s2)
    /* 76F0 80109EF0 00000000 */  nop
    /* 76F4 80109EF4 FDFF4324 */  addiu      $v1, $v0, -0x3
    /* 76F8 80109EF8 0C00622C */  sltiu      $v0, $v1, 0xC
    /* 76FC 80109EFC E6004010 */  beqz       $v0, .L8010A298
    /* 7700 80109F00 1080023C */   lui       $v0, %hi(jtbl_80102A30)
    /* 7704 80109F04 302A4224 */  addiu      $v0, $v0, %lo(jtbl_80102A30)
    /* 7708 80109F08 80180300 */  sll        $v1, $v1, 2
    /* 770C 80109F0C 21186200 */  addu       $v1, $v1, $v0
    /* 7710 80109F10 0000628C */  lw         $v0, 0x0($v1)
    /* 7714 80109F14 00000000 */  nop
    /* 7718 80109F18 08004000 */  jr         $v0
    /* 771C 80109F1C 00000000 */   nop
    /* 7720 80109F20 F110040C */  jal        _initMemcard
    /* 7724 80109F24 01000424 */   addiu     $a0, $zero, 0x1
    /* 7728 80109F28 04000224 */  addiu      $v0, $zero, 0x4
    /* 772C 80109F2C A6280408 */  j          .L8010A298
    /* 7730 80109F30 000042A2 */   sb        $v0, 0x0($s2)
    /* 7734 80109F34 74EA030C */  jal        vs_mainmenu_ready
    /* 7738 80109F38 00000000 */   nop
    /* 773C 80109F3C D7004010 */  beqz       $v0, .L8010A29C
    /* 7740 80109F40 21100000 */   addu      $v0, $zero, $zero
    /* 7744 80109F44 F110040C */  jal        _initMemcard
    /* 7748 80109F48 21200000 */   addu      $a0, $zero, $zero
    /* 774C 80109F4C D3004010 */  beqz       $v0, .L8010A29C
    /* 7750 80109F50 21100000 */   addu      $v0, $zero, $zero
    /* 7754 80109F54 21800000 */  addu       $s0, $zero, $zero
    /* 7758 80109F58 2000A727 */  addiu      $a3, $sp, 0x20
    /* 775C 80109F5C 04000624 */  addiu      $a2, $zero, 0x4
    /* 7760 80109F60 1000A927 */  addiu      $t1, $sp, 0x10
    /* 7764 80109F64 1180023C */  lui        $v0, %hi(_textTable)
    /* 7768 80109F68 F8AD488C */  lw         $t0, %lo(_textTable)($v0)
    /* 776C 80109F6C 21282001 */  addu       $a1, $t1, $zero
    /* 7770 80109F70 88060A25 */  addiu      $t2, $t0, 0x688
    /* 7774 80109F74 21200001 */  addu       $a0, $t0, $zero
  .L80109F78:
    /* 7778 80109F78 21182601 */  addu       $v1, $t1, $a2
    /* 777C 80109F7C 0800C624 */  addiu      $a2, $a2, 0x8
    /* 7780 80109F80 00008294 */  lhu        $v0, 0x0($a0)
    /* 7784 80109F84 04008424 */  addiu      $a0, $a0, 0x4
    /* 7788 80109F88 01001026 */  addiu      $s0, $s0, 0x1
    /* 778C 80109F8C 40100200 */  sll        $v0, $v0, 1
    /* 7790 80109F90 21100201 */  addu       $v0, $t0, $v0
    /* 7794 80109F94 0000A2AC */  sw         $v0, 0x0($a1)
    /* 7798 80109F98 00006AAC */  sw         $t2, 0x0($v1)
    /* 779C 80109F9C 0000E0AC */  sw         $zero, 0x0($a3)
    /* 77A0 80109FA0 0400E724 */  addiu      $a3, $a3, 0x4
    /* 77A4 80109FA4 0200022A */  slti       $v0, $s0, 0x2
    /* 77A8 80109FA8 F3FF4014 */  bnez       $v0, .L80109F78
    /* 77AC 80109FAC 0800A524 */   addiu     $a1, $a1, 0x8
    /* 77B0 80109FB0 3F29020C */  jal        func_8008A4FC
    /* 77B4 80109FB4 00000000 */   nop
    /* 77B8 80109FB8 0F80033C */  lui        $v1, %hi(D_800F4E6B)
    /* 77BC 80109FBC 6B4E62A0 */  sb         $v0, %lo(D_800F4E6B)($v1)
    /* 77C0 80109FC0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 77C4 80109FC4 05004010 */  beqz       $v0, .L80109FDC
    /* 77C8 80109FC8 0680023C */   lui       $v0, %hi(vs_main_stateFlags + 0xA7)
    /* 77CC 80109FCC 3F164290 */  lbu        $v0, %lo(vs_main_stateFlags + 0xA7)($v0)
    /* 77D0 80109FD0 00000000 */  nop
    /* 77D4 80109FD4 06004010 */  beqz       $v0, .L80109FF0
    /* 77D8 80109FD8 0680023C */   lui       $v0, %hi(vs_main_settings)
  .L80109FDC:
    /* 77DC 80109FDC 2000A28F */  lw         $v0, 0x20($sp)
    /* 77E0 80109FE0 00000000 */  nop
    /* 77E4 80109FE4 01004234 */  ori        $v0, $v0, 0x1
    /* 77E8 80109FE8 2000A2AF */  sw         $v0, 0x20($sp)
    /* 77EC 80109FEC 0680023C */  lui        $v0, %hi(vs_main_settings)
  .L80109FF0:
    /* 77F0 80109FF0 20005124 */  addiu      $s1, $v0, %lo(vs_main_settings)
    /* 77F4 80109FF4 04000224 */  addiu      $v0, $zero, 0x4
    /* 77F8 80109FF8 00004392 */  lbu        $v1, 0x0($s2)
    /* 77FC 80109FFC 01003092 */  lbu        $s0, 0x1($s1)
    /* 7800 8010A000 02006210 */  beq        $v1, $v0, .L8010A00C
    /* 7804 8010A004 01000224 */   addiu     $v0, $zero, 0x1
    /* 7808 8010A008 010022A2 */  sb         $v0, 0x1($s1)
  .L8010A00C:
    /* 780C 8010A00C 02000424 */  addiu      $a0, $zero, 0x2
    /* 7810 8010A010 43010524 */  addiu      $a1, $zero, 0x143
    /* 7814 8010A014 1000A627 */  addiu      $a2, $sp, 0x10
    /* 7818 8010A018 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 781C 8010A01C 2000A727 */   addiu     $a3, $sp, 0x20
    /* 7820 8010A020 21200000 */  addu       $a0, $zero, $zero
    /* 7824 8010A024 3729020C */  jal        func_8008A4DC
    /* 7828 8010A028 010030A2 */   sb        $s0, 0x1($s1)
    /* 782C 8010A02C 06000224 */  addiu      $v0, $zero, 0x6
    /* 7830 8010A030 A6280408 */  j          .L8010A298
    /* 7834 8010A034 000042A2 */   sb        $v0, 0x0($s2)
    /* 7838 8010A038 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 783C 8010A03C 00000000 */   nop
    /* 7840 8010A040 01005024 */  addiu      $s0, $v0, 0x1
    /* 7844 8010A044 20000012 */  beqz       $s0, .L8010A0C8
    /* 7848 8010A048 0F80023C */   lui       $v0, %hi(D_800F4E6B)
    /* 784C 8010A04C 1200001A */  blez       $s0, .L8010A098
    /* 7850 8010A050 00000000 */   nop
    /* 7854 8010A054 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 7858 8010A058 06000424 */   addiu     $a0, $zero, 0x6
    /* 785C 8010A05C 5613040C */  jal        _initFileMenu
    /* 7860 8010A060 00000000 */   nop
    /* 7864 8010A064 01000224 */  addiu      $v0, $zero, 0x1
    /* 7868 8010A068 05000212 */  beq        $s0, $v0, .L8010A080
    /* 786C 8010A06C 02000224 */   addiu     $v0, $zero, 0x2
    /* 7870 8010A070 06000212 */  beq        $s0, $v0, .L8010A08C
    /* 7874 8010A074 21100000 */   addu      $v0, $zero, $zero
    /* 7878 8010A078 A7280408 */  j          .L8010A29C
    /* 787C 8010A07C 00000000 */   nop
  .L8010A080:
    /* 7880 8010A080 07000224 */  addiu      $v0, $zero, 0x7
    /* 7884 8010A084 A6280408 */  j          .L8010A298
    /* 7888 8010A088 000042A2 */   sb        $v0, 0x0($s2)
  .L8010A08C:
    /* 788C 8010A08C 09000224 */  addiu      $v0, $zero, 0x9
    /* 7890 8010A090 A6280408 */  j          .L8010A298
    /* 7894 8010A094 000042A2 */   sb        $v0, 0x0($s2)
  .L8010A098:
    /* 7898 8010A098 3729020C */  jal        func_8008A4DC
    /* 789C 8010A09C 01000424 */   addiu     $a0, $zero, 0x1
    /* 78A0 8010A0A0 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 78A4 8010A0A4 28000424 */   addiu     $a0, $zero, 0x28
    /* 78A8 8010A0A8 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 78AC 8010A0AC 04000216 */  bne        $s0, $v0, .L8010A0C0
    /* 78B0 8010A0B0 0B000224 */   addiu     $v0, $zero, 0xB
    /* 78B4 8010A0B4 0C000224 */  addiu      $v0, $zero, 0xC
    /* 78B8 8010A0B8 A6280408 */  j          .L8010A298
    /* 78BC 8010A0BC 000042A2 */   sb        $v0, 0x0($s2)
  .L8010A0C0:
    /* 78C0 8010A0C0 A6280408 */  j          .L8010A298
    /* 78C4 8010A0C4 000042A2 */   sb        $v0, 0x0($s2)
  .L8010A0C8:
    /* 78C8 8010A0C8 6B4E4290 */  lbu        $v0, %lo(D_800F4E6B)($v0)
    /* 78CC 8010A0CC 00000000 */  nop
    /* 78D0 8010A0D0 0F004010 */  beqz       $v0, .L8010A110
    /* 78D4 8010A0D4 0680023C */   lui       $v0, %hi(vs_main_stateFlags + 0xA7)
    /* 78D8 8010A0D8 3F164290 */  lbu        $v0, %lo(vs_main_stateFlags + 0xA7)($v0)
    /* 78DC 8010A0DC 00000000 */  nop
    /* 78E0 8010A0E0 0C004010 */  beqz       $v0, .L8010A114
    /* 78E4 8010A0E4 0F80023C */   lui       $v0, %hi(D_800F514C)
    /* 78E8 8010A0E8 2C02040C */  jal        func_801008B0
    /* 78EC 8010A0EC 00000000 */   nop
    /* 78F0 8010A0F0 08004014 */  bnez       $v0, .L8010A114
    /* 78F4 8010A0F4 0F80023C */   lui       $v0, %hi(D_800F514C)
    /* 78F8 8010A0F8 8123030C */  jal        func_800C8E04
    /* 78FC 8010A0FC 01000424 */   addiu     $a0, $zero, 0x1
    /* 7900 8010A100 0F80033C */  lui        $v1, %hi(D_800F514C)
    /* 7904 8010A104 0B000224 */  addiu      $v0, $zero, 0xB
    /* 7908 8010A108 A6280408 */  j          .L8010A298
    /* 790C 8010A10C 4C5162A4 */   sh        $v0, %lo(D_800F514C)($v1)
  .L8010A110:
    /* 7910 8010A110 0F80023C */  lui        $v0, %hi(D_800F514C)
  .L8010A114:
    /* 7914 8010A114 A6280408 */  j          .L8010A298
    /* 7918 8010A118 4C5140A4 */   sh        $zero, %lo(D_800F514C)($v0)
    /* 791C 8010A11C 74EA030C */  jal        vs_mainmenu_ready
    /* 7920 8010A120 00000000 */   nop
    /* 7924 8010A124 5D004010 */  beqz       $v0, .L8010A29C
    /* 7928 8010A128 21100000 */   addu      $v0, $zero, $zero
    /* 792C 8010A12C 9A1C040C */  jal        _showSaveMenu
    /* 7930 8010A130 01000424 */   addiu     $a0, $zero, 0x1
    /* 7934 8010A134 08000224 */  addiu      $v0, $zero, 0x8
    /* 7938 8010A138 A6280408 */  j          .L8010A298
    /* 793C 8010A13C 000042A2 */   sb        $v0, 0x0($s2)
    /* 7940 8010A140 9A1C040C */  jal        _showSaveMenu
    /* 7944 8010A144 21200000 */   addu      $a0, $zero, $zero
    /* 7948 8010A148 2B004010 */  beqz       $v0, .L8010A1F8
    /* 794C 8010A14C 05000224 */   addiu     $v0, $zero, 0x5
    /* 7950 8010A150 7E280408 */  j          .L8010A1F8
    /* 7954 8010A154 000042A2 */   sb        $v0, 0x0($s2)
    /* 7958 8010A158 74EA030C */  jal        vs_mainmenu_ready
    /* 795C 8010A15C 00000000 */   nop
    /* 7960 8010A160 4E004010 */  beqz       $v0, .L8010A29C
    /* 7964 8010A164 21100000 */   addu      $v0, $zero, $zero
    /* 7968 8010A168 7720040C */  jal        _loadFileMenu
    /* 796C 8010A16C 01000424 */   addiu     $a0, $zero, 0x1
    /* 7970 8010A170 0A000224 */  addiu      $v0, $zero, 0xA
    /* 7974 8010A174 A6280408 */  j          .L8010A298
    /* 7978 8010A178 000042A2 */   sb        $v0, 0x0($s2)
    /* 797C 8010A17C 7720040C */  jal        _loadFileMenu
    /* 7980 8010A180 21200000 */   addu      $a0, $zero, $zero
    /* 7984 8010A184 21804000 */  addu       $s0, $v0, $zero
    /* 7988 8010A188 1C000012 */  beqz       $s0, .L8010A1FC
    /* 798C 8010A18C 0680023C */   lui       $v0, %hi(vs_main_frameBuf)
    /* 7990 8010A190 04000106 */  bgez       $s0, .L8010A1A4
    /* 7994 8010A194 21200000 */   addu      $a0, $zero, $zero
    /* 7998 8010A198 05000224 */  addiu      $v0, $zero, 0x5
    /* 799C 8010A19C A6280408 */  j          .L8010A298
    /* 79A0 8010A1A0 000042A2 */   sb        $v0, 0x0($s2)
  .L8010A1A4:
    /* 79A4 8010A1A4 80020224 */  addiu      $v0, $zero, 0x280
    /* 79A8 8010A1A8 2C00A2A7 */  sh         $v0, 0x2C($sp)
    /* 79AC 8010A1AC F0000224 */  addiu      $v0, $zero, 0xF0
    /* 79B0 8010A1B0 2800A0A7 */  sh         $zero, 0x28($sp)
    /* 79B4 8010A1B4 2A00A0A7 */  sh         $zero, 0x2A($sp)
    /* 79B8 8010A1B8 94A1000C */  jal        DrawSync
    /* 79BC 8010A1BC 2E00A2A7 */   sh        $v0, 0x2E($sp)
    /* 79C0 8010A1C0 2800A427 */  addiu      $a0, $sp, 0x28
    /* 79C4 8010A1C4 21280000 */  addu       $a1, $zero, $zero
    /* 79C8 8010A1C8 2130A000 */  addu       $a2, $a1, $zero
    /* 79CC 8010A1CC F5A1000C */  jal        ClearImage
    /* 79D0 8010A1D0 2138A000 */   addu      $a3, $a1, $zero
    /* 79D4 8010A1D4 8611040C */  jal        _shutdownMemcard
    /* 79D8 8010A1D8 00000000 */   nop
    /* 79DC 8010A1DC 21200000 */  addu       $a0, $zero, $zero
    /* 79E0 8010A1E0 94A1000C */  jal        DrawSync
    /* 79E4 8010A1E4 000040A2 */   sb        $zero, 0x0($s2)
    /* 79E8 8010A1E8 0809010C */  jal        vs_main_jumpToBattle
    /* 79EC 8010A1EC 00000000 */   nop
    /* 79F0 8010A1F0 A7280408 */  j          .L8010A29C
    /* 79F4 8010A1F4 21100000 */   addu      $v0, $zero, $zero
  .L8010A1F8:
    /* 79F8 8010A1F8 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
  .L8010A1FC:
    /* 79FC 8010A1FC 10E2448C */  lw         $a0, %lo(vs_main_frameBuf)($v0)
    /* 7A00 8010A200 F916040C */  jal        _drawFileMenu
    /* 7A04 8010A204 00000000 */   nop
    /* 7A08 8010A208 A7280408 */  j          .L8010A29C
    /* 7A0C 8010A20C 21100000 */   addu      $v0, $zero, $zero
    /* 7A10 8010A210 A2FE030C */  jal        func_800FFA88
    /* 7A14 8010A214 21200000 */   addu      $a0, $zero, $zero
    /* 7A18 8010A218 EAFE030C */  jal        func_800FFBA8
    /* 7A1C 8010A21C 00000000 */   nop
    /* 7A20 8010A220 DAFE030C */  jal        func_800FFB68
    /* 7A24 8010A224 21200000 */   addu      $a0, $zero, $zero
    /* 7A28 8010A228 0D000224 */  addiu      $v0, $zero, 0xD
    /* 7A2C 8010A22C A6280408 */  j          .L8010A298
    /* 7A30 8010A230 000042A2 */   sb        $v0, 0x0($s2)
    /* 7A34 8010A234 A2FE030C */  jal        func_800FFA88
    /* 7A38 8010A238 21200000 */   addu      $a0, $zero, $zero
    /* 7A3C 8010A23C EAFE030C */  jal        func_800FFBA8
    /* 7A40 8010A240 00000000 */   nop
    /* 7A44 8010A244 DAFE030C */  jal        func_800FFB68
    /* 7A48 8010A248 21200000 */   addu      $a0, $zero, $zero
    /* 7A4C 8010A24C 0E000224 */  addiu      $v0, $zero, 0xE
    /* 7A50 8010A250 A6280408 */  j          .L8010A298
    /* 7A54 8010A254 000042A2 */   sb        $v0, 0x0($s2)
    /* 7A58 8010A258 1080023C */  lui        $v0, %hi(D_801022D8)
    /* 7A5C 8010A25C D822428C */  lw         $v0, %lo(D_801022D8)($v0)
    /* 7A60 8010A260 00000000 */  nop
    /* 7A64 8010A264 0D004014 */  bnez       $v0, .L8010A29C
    /* 7A68 8010A268 21100000 */   addu      $v0, $zero, $zero
    /* 7A6C 8010A26C 8611040C */  jal        _shutdownMemcard
    /* 7A70 8010A270 00000000 */   nop
    /* 7A74 8010A274 00004392 */  lbu        $v1, 0x0($s2)
    /* 7A78 8010A278 0E000224 */  addiu      $v0, $zero, 0xE
    /* 7A7C 8010A27C 03006214 */  bne        $v1, $v0, .L8010A28C
    /* 7A80 8010A280 0F80033C */   lui       $v1, %hi(vs_battle_menuState)
    /* 7A84 8010A284 07000224 */  addiu      $v0, $zero, 0x7
    /* 7A88 8010A288 C05162A0 */  sb         $v0, %lo(vs_battle_menuState)($v1)
  .L8010A28C:
    /* 7A8C 8010A28C 000040A2 */  sb         $zero, 0x0($s2)
    /* 7A90 8010A290 A7280408 */  j          .L8010A29C
    /* 7A94 8010A294 01000224 */   addiu     $v0, $zero, 0x1
  .L8010A298:
    /* 7A98 8010A298 21100000 */  addu       $v0, $zero, $zero
  .L8010A29C:
    /* 7A9C 8010A29C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 7AA0 8010A2A0 3800B28F */  lw         $s2, 0x38($sp)
    /* 7AA4 8010A2A4 3400B18F */  lw         $s1, 0x34($sp)
    /* 7AA8 8010A2A8 3000B08F */  lw         $s0, 0x30($sp)
    /* 7AAC 8010A2AC 0800E003 */  jr         $ra
    /* 7AB0 8010A2B0 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel vs_menu7_dataMenu
