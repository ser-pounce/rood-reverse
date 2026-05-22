nonmatching func_8010A6BC, 0x2BC

glabel func_8010A6BC
    /* 7EBC 8010A6BC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 7EC0 8010A6C0 3800BFAF */  sw         $ra, 0x38($sp)
    /* 7EC4 8010A6C4 3400B3AF */  sw         $s3, 0x34($sp)
    /* 7EC8 8010A6C8 3000B2AF */  sw         $s2, 0x30($sp)
    /* 7ECC 8010A6CC 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 7ED0 8010A6D0 0B008010 */  beqz       $a0, .L8010A700
    /* 7ED4 8010A6D4 2800B0AF */   sw        $s0, 0x28($sp)
    /* 7ED8 8010A6D8 05000424 */  addiu      $a0, $zero, 0x5
    /* 7EDC 8010A6DC 01000524 */  addiu      $a1, $zero, 0x1
    /* 7EE0 8010A6E0 1180023C */  lui        $v0, %hi(D_8010BC7E)
    /* 7EE4 8010A6E4 2118A000 */  addu       $v1, $a1, $zero
    /* 7EE8 8010A6E8 4BEA030C */  jal        func_800FA92C
    /* 7EEC 8010A6EC 7EBC43A0 */   sb        $v1, %lo(D_8010BC7E)($v0)
    /* 7EF0 8010A6F0 21100000 */  addu       $v0, $zero, $zero
    /* 7EF4 8010A6F4 1180033C */  lui        $v1, %hi(D_8010BC7D)
    /* 7EF8 8010A6F8 572A0408 */  j          .L8010A95C
    /* 7EFC 8010A6FC 7DBC60A0 */   sb        $zero, %lo(D_8010BC7D)($v1)
  .L8010A700:
    /* 7F00 8010A700 1180023C */  lui        $v0, %hi(D_8010BC7D)
    /* 7F04 8010A704 7DBC4390 */  lbu        $v1, %lo(D_8010BC7D)($v0)
    /* 7F08 8010A708 00000000 */  nop
    /* 7F0C 8010A70C 0600622C */  sltiu      $v0, $v1, 0x6
    /* 7F10 8010A710 91004010 */  beqz       $v0, .L8010A958
    /* 7F14 8010A714 1080023C */   lui       $v0, %hi(jtbl_80102908)
    /* 7F18 8010A718 08294224 */  addiu      $v0, $v0, %lo(jtbl_80102908)
    /* 7F1C 8010A71C 80180300 */  sll        $v1, $v1, 2
    /* 7F20 8010A720 21186200 */  addu       $v1, $v1, $v0
    /* 7F24 8010A724 0000628C */  lw         $v0, 0x0($v1)
    /* 7F28 8010A728 00000000 */  nop
    /* 7F2C 8010A72C 08004000 */  jr         $v0
    /* 7F30 8010A730 00000000 */   nop
    /* 7F34 8010A734 74EA030C */  jal        vs_mainmenu_ready
    /* 7F38 8010A738 00000000 */   nop
    /* 7F3C 8010A73C 86004010 */  beqz       $v0, .L8010A958
    /* 7F40 8010A740 21880000 */   addu      $s1, $zero, $zero
    /* 7F44 8010A744 04001224 */  addiu      $s2, $zero, 0x4
    /* 7F48 8010A748 1000B327 */  addiu      $s3, $sp, 0x10
    /* 7F4C 8010A74C 21806002 */  addu       $s0, $s3, $zero
  .L8010A750:
    /* 7F50 8010A750 8F29040C */  jal        func_8010A63C
    /* 7F54 8010A754 21202002 */   addu      $a0, $s1, $zero
    /* 7F58 8010A758 1080033C */  lui        $v1, %hi(vs_mainMenu_menu12Text)
    /* 7F5C 8010A75C A424648C */  lw         $a0, %lo(vs_mainMenu_menu12Text)($v1)
    /* 7F60 8010A760 40181100 */  sll        $v1, $s1, 1
    /* 7F64 8010A764 21304000 */  addu       $a2, $v0, $zero
    /* 7F68 8010A768 21387202 */  addu       $a3, $s3, $s2
    /* 7F6C 8010A76C 21286400 */  addu       $a1, $v1, $a0
    /* 7F70 8010A770 8C00A394 */  lhu        $v1, 0x8C($a1)
    /* 7F74 8010A774 0200C228 */  slti       $v0, $a2, 0x2
    /* 7F78 8010A778 40180300 */  sll        $v1, $v1, 1
    /* 7F7C 8010A77C 21188300 */  addu       $v1, $a0, $v1
    /* 7F80 8010A780 09004010 */  beqz       $v0, .L8010A7A8
    /* 7F84 8010A784 000003AE */   sw        $v1, 0x0($s0)
    /* 7F88 8010A788 80100600 */  sll        $v0, $a2, 2
    /* 7F8C 8010A78C 35000324 */  addiu      $v1, $zero, 0x35
    /* 7F90 8010A790 23186200 */  subu       $v1, $v1, $v0
    /* 7F94 8010A794 40180300 */  sll        $v1, $v1, 1
    /* 7F98 8010A798 21186400 */  addu       $v1, $v1, $a0
    /* 7F9C 8010A79C 00006294 */  lhu        $v0, 0x0($v1)
    /* 7FA0 8010A7A0 ED290408 */  j          .L8010A7B4
    /* 7FA4 8010A7A4 40100200 */   sll       $v0, $v0, 1
  .L8010A7A8:
    /* 7FA8 8010A7A8 9200A294 */  lhu        $v0, 0x92($a1)
    /* 7FAC 8010A7AC 00000000 */  nop
    /* 7FB0 8010A7B0 40100200 */  sll        $v0, $v0, 1
  .L8010A7B4:
    /* 7FB4 8010A7B4 21108200 */  addu       $v0, $a0, $v0
    /* 7FB8 8010A7B8 0000E2AC */  sw         $v0, 0x0($a3)
    /* 7FBC 8010A7BC 08005226 */  addiu      $s2, $s2, 0x8
    /* 7FC0 8010A7C0 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 7FC4 8010A7C4 80181100 */  sll        $v1, $s1, 2
    /* 7FC8 8010A7C8 01003126 */  addiu      $s1, $s1, 0x1
    /* 7FCC 8010A7CC 844E478C */  lw         $a3, %lo(vs_battle_rowTypeBuf)($v0)
    /* 7FD0 8010A7D0 0200C228 */  slti       $v0, $a2, 0x2
    /* 7FD4 8010A7D4 21186700 */  addu       $v1, $v1, $a3
    /* 7FD8 8010A7D8 000062AC */  sw         $v0, 0x0($v1)
    /* 7FDC 8010A7DC 0300222A */  slti       $v0, $s1, 0x3
    /* 7FE0 8010A7E0 DBFF4014 */  bnez       $v0, .L8010A750
    /* 7FE4 8010A7E4 08001026 */   addiu     $s0, $s0, 0x8
    /* 7FE8 8010A7E8 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 7FEC 8010A7EC 20005024 */  addiu      $s0, $v0, %lo(vs_main_settings)
    /* 7FF0 8010A7F0 1180033C */  lui        $v1, %hi(D_8010BC7E)
    /* 7FF4 8010A7F4 7EBC6290 */  lbu        $v0, %lo(D_8010BC7E)($v1)
    /* 7FF8 8010A7F8 01001192 */  lbu        $s1, 0x1($s0)
    /* 7FFC 8010A7FC 03004014 */  bnez       $v0, .L8010A80C
    /* 8000 8010A800 03000424 */   addiu     $a0, $zero, 0x3
    /* 8004 8010A804 01000224 */  addiu      $v0, $zero, 0x1
    /* 8008 8010A808 010002A2 */  sb         $v0, 0x1($s0)
  .L8010A80C:
    /* 800C 8010A80C 3D020524 */  addiu      $a1, $zero, 0x23D
    /* 8010 8010A810 1000A627 */  addiu      $a2, $sp, 0x10
    /* 8014 8010A814 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 8018 8010A818 7EBC60A0 */   sb        $zero, %lo(D_8010BC7E)($v1)
    /* 801C 8010A81C 1180033C */  lui        $v1, %hi(D_8010BC7D)
    /* 8020 8010A820 01000224 */  addiu      $v0, $zero, 0x1
    /* 8024 8010A824 010011A2 */  sb         $s1, 0x1($s0)
    /* 8028 8010A828 562A0408 */  j          .L8010A958
    /* 802C 8010A82C 7DBC62A0 */   sb        $v0, %lo(D_8010BC7D)($v1)
    /* 8030 8010A830 2C02040C */  jal        func_801008B0
    /* 8034 8010A834 00000000 */   nop
    /* 8038 8010A838 1080033C */  lui        $v1, %hi(D_801023D0)
    /* 803C 8010A83C D0236590 */  lbu        $a1, %lo(D_801023D0)($v1)
    /* 8040 8010A840 79FE030C */  jal        vs_mainMenu_printInformation
    /* 8044 8010A844 21204000 */   addu      $a0, $v0, $zero
    /* 8048 8010A848 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 804C 8010A84C 00000000 */   nop
    /* 8050 8010A850 21804000 */  addu       $s0, $v0, $zero
    /* 8054 8010A854 01001126 */  addiu      $s1, $s0, 0x1
    /* 8058 8010A858 40002012 */  beqz       $s1, .L8010A95C
    /* 805C 8010A85C 21100000 */   addu      $v0, $zero, $zero
    /* 8060 8010A860 05002106 */  bgez       $s1, .L8010A878
    /* 8064 8010A864 00000000 */   nop
    /* 8068 8010A868 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 806C 8010A86C 21200000 */   addu      $a0, $zero, $zero
  .L8010A870:
    /* 8070 8010A870 572A0408 */  j          .L8010A95C
    /* 8074 8010A874 21102002 */   addu      $v0, $s1, $zero
  .L8010A878:
    /* 8078 8010A878 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 807C 8010A87C 28000424 */   addiu     $a0, $zero, 0x28
    /* 8080 8010A880 1180033C */  lui        $v1, %hi(D_8010BB78)
    /* 8084 8010A884 78BB6324 */  addiu      $v1, $v1, %lo(D_8010BB78)
    /* 8088 8010A888 80101000 */  sll        $v0, $s0, 2
    /* 808C 8010A88C 21104300 */  addu       $v0, $v0, $v1
    /* 8090 8010A890 0000428C */  lw         $v0, 0x0($v0)
    /* 8094 8010A894 00000000 */  nop
    /* 8098 8010A898 09F84000 */  jalr       $v0
    /* 809C 8010A89C 01000424 */   addiu     $a0, $zero, 0x1
    /* 80A0 8010A8A0 C11D040C */  jal        _loadSyd
    /* 80A4 8010A8A4 21202002 */   addu      $a0, $s1, $zero
    /* 80A8 8010A8A8 1180033C */  lui        $v1, %hi(D_8010BC7D)
    /* 80AC 8010A8AC 02000226 */  addiu      $v0, $s0, 0x2
    /* 80B0 8010A8B0 562A0408 */  j          .L8010A958
    /* 80B4 8010A8B4 7DBC62A0 */   sb        $v0, %lo(D_8010BC7D)($v1)
    /* 80B8 8010A8B8 C11D040C */  jal        _loadSyd
    /* 80BC 8010A8BC 21200000 */   addu      $a0, $zero, $zero
    /* 80C0 8010A8C0 25004010 */  beqz       $v0, .L8010A958
    /* 80C4 8010A8C4 1180023C */   lui       $v0, %hi(D_8010BB78)
    /* 80C8 8010A8C8 1180123C */  lui        $s2, %hi(D_8010BC7D)
    /* 80CC 8010A8CC 7DBC4392 */  lbu        $v1, %lo(D_8010BC7D)($s2)
    /* 80D0 8010A8D0 78BB4224 */  addiu      $v0, $v0, %lo(D_8010BB78)
    /* 80D4 8010A8D4 FEFF6324 */  addiu      $v1, $v1, -0x2
    /* 80D8 8010A8D8 80180300 */  sll        $v1, $v1, 2
    /* 80DC 8010A8DC 21186200 */  addu       $v1, $v1, $v0
    /* 80E0 8010A8E0 0000628C */  lw         $v0, 0x0($v1)
    /* 80E4 8010A8E4 00000000 */  nop
    /* 80E8 8010A8E8 09F84000 */  jalr       $v0
    /* 80EC 8010A8EC 21200000 */   addu      $a0, $zero, $zero
    /* 80F0 8010A8F0 21884000 */  addu       $s1, $v0, $zero
    /* 80F4 8010A8F4 18002012 */  beqz       $s1, .L8010A958
    /* 80F8 8010A8F8 1180103C */   lui       $s0, %hi(_sydData)
    /* 80FC 8010A8FC 58BB048E */  lw         $a0, %lo(_sydData)($s0)
    /* 8100 8010A900 180F010C */  jal        vs_main_freeHeapR
    /* 8104 8010A904 00000000 */   nop
    /* 8108 8010A908 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 810C 8010A90C D8FF2216 */  bne        $s1, $v0, .L8010A870
    /* 8110 8010A910 58BB00AE */   sw        $zero, %lo(_sydData)($s0)
    /* 8114 8010A914 05000224 */  addiu      $v0, $zero, 0x5
    /* 8118 8010A918 562A0408 */  j          .L8010A958
    /* 811C 8010A91C 7DBC42A2 */   sb        $v0, %lo(D_8010BC7D)($s2)
    /* 8120 8010A920 74EA030C */  jal        vs_mainmenu_ready
    /* 8124 8010A924 00000000 */   nop
    /* 8128 8010A928 0C004010 */  beqz       $v0, .L8010A95C
    /* 812C 8010A92C 21100000 */   addu      $v0, $zero, $zero
    /* 8130 8010A930 F2FE030C */  jal        func_800FFBC8
    /* 8134 8010A934 00000000 */   nop
    /* 8138 8010A938 21200000 */  addu       $a0, $zero, $zero
    /* 813C 8010A93C 740A040C */  jal        func_801029D0
    /* 8140 8010A940 57000524 */   addiu     $a1, $zero, 0x57
    /* 8144 8010A944 0F000424 */  addiu      $a0, $zero, 0xF
    /* 8148 8010A948 740A040C */  jal        func_801029D0
    /* 814C 8010A94C ED000524 */   addiu     $a1, $zero, 0xED
    /* 8150 8010A950 1180023C */  lui        $v0, %hi(D_8010BC7D)
    /* 8154 8010A954 7DBC40A0 */  sb         $zero, %lo(D_8010BC7D)($v0)
  .L8010A958:
    /* 8158 8010A958 21100000 */  addu       $v0, $zero, $zero
  .L8010A95C:
    /* 815C 8010A95C 3800BF8F */  lw         $ra, 0x38($sp)
    /* 8160 8010A960 3400B38F */  lw         $s3, 0x34($sp)
    /* 8164 8010A964 3000B28F */  lw         $s2, 0x30($sp)
    /* 8168 8010A968 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 816C 8010A96C 2800B08F */  lw         $s0, 0x28($sp)
    /* 8170 8010A970 0800E003 */  jr         $ra
    /* 8174 8010A974 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8010A6BC
