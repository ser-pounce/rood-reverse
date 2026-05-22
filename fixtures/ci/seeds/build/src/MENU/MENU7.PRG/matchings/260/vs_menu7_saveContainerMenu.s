nonmatching vs_menu7_saveContainerMenu, 0x5EC

glabel vs_menu7_saveContainerMenu
    /* 6F78 80109778 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6F7C 8010977C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6F80 80109780 21888000 */  addu       $s1, $a0, $zero
    /* 6F84 80109784 2000BFAF */  sw         $ra, 0x20($sp)
    /* 6F88 80109788 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6F8C 8010978C 00002392 */  lbu        $v1, 0x0($s1)
    /* 6F90 80109790 00000000 */  nop
    /* 6F94 80109794 1100622C */  sltiu      $v0, $v1, 0x11
    /* 6F98 80109798 6C014010 */  beqz       $v0, .L80109D4C
    /* 6F9C 8010979C 1080023C */   lui       $v0, %hi(jtbl_801029C8)
    /* 6FA0 801097A0 C8294224 */  addiu      $v0, $v0, %lo(jtbl_801029C8)
    /* 6FA4 801097A4 80180300 */  sll        $v1, $v1, 2
    /* 6FA8 801097A8 21186200 */  addu       $v1, $v1, $v0
    /* 6FAC 801097AC 0000628C */  lw         $v0, 0x0($v1)
    /* 6FB0 801097B0 00000000 */  nop
    /* 6FB4 801097B4 08004000 */  jr         $v0
    /* 6FB8 801097B8 00000000 */   nop
    /* 6FBC 801097BC B600030C */  jal        vs_battle_playSfx10
    /* 6FC0 801097C0 00000000 */   nop
    /* 6FC4 801097C4 0100043C */  lui        $a0, (0x14730 >> 16)
    /* 6FC8 801097C8 30478434 */  ori        $a0, $a0, (0x14730 & 0xFFFF)
    /* 6FCC 801097CC 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 6FD0 801097D0 2000428C */  lw         $v0, %lo(vs_main_settings)($v0)
    /* 6FD4 801097D4 1080033C */  lui        $v1, %hi(D_80102578)
    /* 6FD8 801097D8 02110200 */  srl        $v0, $v0, 4
    /* 6FDC 801097DC 01004230 */  andi       $v0, $v0, 0x1
    /* 6FE0 801097E0 8F0F010C */  jal        vs_main_allocHeapR
    /* 6FE4 801097E4 782562A0 */   sb        $v0, %lo(D_80102578)($v1)
    /* 6FE8 801097E8 21204000 */  addu       $a0, $v0, $zero
    /* 6FEC 801097EC 0100053C */  lui        $a1, (0x14730 >> 16)
    /* 6FF0 801097F0 3047A534 */  ori        $a1, $a1, (0x14730 & 0xFFFF)
    /* 6FF4 801097F4 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 6FF8 801097F8 0733030C */  jal        vs_battle_rMemzero
    /* 6FFC 801097FC 5C2444AC */   sw        $a0, %lo(vs_menu_inventoryStorage)($v0)
    /* 7000 80109800 60EF030C */  jal        func_800FBD80
    /* 7004 80109804 10000424 */   addiu     $a0, $zero, 0x10
    /* 7008 80109808 8123030C */  jal        func_800C8E04
    /* 700C 8010980C 01000424 */   addiu     $a0, $zero, 0x1
    /* 7010 80109810 0F24040C */  jal        func_8010903C
    /* 7014 80109814 05000424 */   addiu     $a0, $zero, 0x5
    /* 7018 80109818 1180043C */  lui        $a0, %hi(D_8010A9BA)
    /* 701C 8010981C 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 7020 80109820 BAA98424 */   addiu     $a0, $a0, %lo(D_8010A9BA)
    /* 7024 80109824 01000224 */  addiu      $v0, $zero, 0x1
    /* 7028 80109828 53270408 */  j          .L80109D4C
    /* 702C 8010982C 000022A2 */   sb        $v0, 0x0($s1)
    /* 7030 80109830 0F24040C */  jal        func_8010903C
    /* 7034 80109834 21200000 */   addu      $a0, $zero, $zero
    /* 7038 80109838 21804000 */  addu       $s0, $v0, $zero
    /* 703C 8010983C 44010012 */  beqz       $s0, .L80109D50
    /* 7040 80109840 21100000 */   addu      $v0, $zero, $zero
    /* 7044 80109844 2F010006 */  bltz       $s0, .L80109D04
    /* 7048 80109848 10000224 */   addiu     $v0, $zero, 0x10
    /* 704C 8010984C F110040C */  jal        _initMemcard
    /* 7050 80109850 01000424 */   addiu     $a0, $zero, 0x1
    /* 7054 80109854 DAFE030C */  jal        func_800FFB68
    /* 7058 80109858 01000424 */   addiu     $a0, $zero, 0x1
    /* 705C 8010985C A2FE030C */  jal        func_800FFA88
    /* 7060 80109860 02000424 */   addiu     $a0, $zero, 0x2
    /* 7064 80109864 21200000 */  addu       $a0, $zero, $zero
    /* 7068 80109868 40010524 */  addiu      $a1, $zero, 0x140
    /* 706C 8010986C 12000624 */  addiu      $a2, $zero, 0x12
    /* 7070 80109870 08000224 */  addiu      $v0, $zero, 0x8
    /* 7074 80109874 1000A2AF */  sw         $v0, 0x10($sp)
    /* 7078 80109878 1180023C */  lui        $v0, %hi(D_8010A9D8)
    /* 707C 8010987C D8A94224 */  addiu      $v0, $v0, %lo(D_8010A9D8)
    /* 7080 80109880 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 7084 80109884 9723030C */  jal        vs_battle_setMenuItem
    /* 7088 80109888 1400A2AF */   sw        $v0, 0x14($sp)
    /* 708C 8010988C 02000424 */  addiu      $a0, $zero, 0x2
    /* 7090 80109890 B4000324 */  addiu      $v1, $zero, 0xB4
    /* 7094 80109894 180043A4 */  sh         $v1, 0x18($v0)
    /* 7098 80109898 01000324 */  addiu      $v1, $zero, 0x1
    /* 709C 8010989C 000044A0 */  sb         $a0, 0x0($v0)
    /* 70A0 801098A0 060043A0 */  sb         $v1, 0x6($v0)
    /* 70A4 801098A4 53270408 */  j          .L80109D4C
    /* 70A8 801098A8 000024A2 */   sb        $a0, 0x0($s1)
    /* 70AC 801098AC 74EA030C */  jal        vs_mainmenu_ready
    /* 70B0 801098B0 00000000 */   nop
    /* 70B4 801098B4 26014010 */  beqz       $v0, .L80109D50
    /* 70B8 801098B8 21100000 */   addu      $v0, $zero, $zero
    /* 70BC 801098BC F110040C */  jal        _initMemcard
    /* 70C0 801098C0 21200000 */   addu      $a0, $zero, $zero
    /* 70C4 801098C4 22014010 */  beqz       $v0, .L80109D50
    /* 70C8 801098C8 21100000 */   addu      $v0, $zero, $zero
    /* 70CC 801098CC 3729020C */  jal        func_8008A4DC
    /* 70D0 801098D0 21200000 */   addu      $a0, $zero, $zero
    /* 70D4 801098D4 952D030C */  jal        func_800CB654
    /* 70D8 801098D8 01000424 */   addiu     $a0, $zero, 0x1
    /* 70DC 801098DC FE070424 */  addiu      $a0, $zero, 0x7FE
    /* 70E0 801098E0 80000524 */  addiu      $a1, $zero, 0x80
    /* 70E4 801098E4 0F80033C */  lui        $v1, %hi(D_800EB9B0)
    /* 70E8 801098E8 2000023C */  lui        $v0, (0x200000 >> 16)
    /* 70EC 801098EC 0501040C */  jal        func_80100414
    /* 70F0 801098F0 B0B962AC */   sw        $v0, %lo(D_800EB9B0)($v1)
    /* 70F4 801098F4 5613040C */  jal        _initFileMenu
    /* 70F8 801098F8 00000000 */   nop
    /* 70FC 801098FC 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 7100 80109900 2000428C */  lw         $v0, %lo(vs_main_settings)($v0)
    /* 7104 80109904 00000000 */  nop
    /* 7108 80109908 10004230 */  andi       $v0, $v0, 0x10
    /* 710C 8010990C 07004010 */  beqz       $v0, .L8010992C
    /* 7110 80109910 1180023C */   lui       $v0, %hi(_spmcimg)
    /* 7114 80109914 F0AD448C */  lw         $a0, %lo(_spmcimg)($v0)
    /* 7118 80109918 003C0524 */  addiu      $a1, $zero, 0x3C00
    /* 711C 8010991C 0733030C */  jal        vs_battle_rMemzero
    /* 7120 80109920 E0798424 */   addiu     $a0, $a0, 0x79E0
    /* 7124 80109924 94260408 */  j          .L80109A50
    /* 7128 80109928 07000224 */   addiu     $v0, $zero, 0x7
  .L8010992C:
    /* 712C 8010992C 2014040C */  jal        _findCurrentSave
    /* 7130 80109930 01000424 */   addiu     $a0, $zero, 0x1
    /* 7134 80109934 03000224 */  addiu      $v0, $zero, 0x3
    /* 7138 80109938 53270408 */  j          .L80109D4C
    /* 713C 8010993C 000022A2 */   sb        $v0, 0x0($s1)
    /* 7140 80109940 2014040C */  jal        _findCurrentSave
    /* 7144 80109944 21200000 */   addu      $a0, $zero, $zero
    /* 7148 80109948 21804000 */  addu       $s0, $v0, $zero
    /* 714C 8010994C 00010012 */  beqz       $s0, .L80109D50
    /* 7150 80109950 21100000 */   addu      $v0, $zero, $zero
    /* 7154 80109954 0A000106 */  bgez       $s0, .L80109980
    /* 7158 80109958 07000232 */   andi      $v0, $s0, 0x7
    /* 715C 8010995C FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 7160 80109960 04000216 */  bne        $s0, $v0, .L80109974
    /* 7164 80109964 1180023C */   lui       $v0, %hi(_textTable)
    /* 7168 80109968 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 716C 8010996C 99260408 */  j          .L80109A64
    /* 7170 80109970 C6014424 */   addiu     $a0, $v0, 0x1C6
  .L80109974:
    /* 7174 80109974 F8AD428C */  lw         $v0, %lo(_textTable)($v0)
    /* 7178 80109978 99260408 */  j          .L80109A64
    /* 717C 8010997C EE014424 */   addiu     $a0, $v0, 0x1EE
  .L80109980:
    /* 7180 80109980 10000432 */  andi       $a0, $s0, 0x10
    /* 7184 80109984 00230400 */  sll        $a0, $a0, 12
    /* 7188 80109988 740F040C */  jal        _loadSaveData
    /* 718C 8010998C 25204400 */   or        $a0, $v0, $a0
    /* 7190 80109990 06000224 */  addiu      $v0, $zero, 0x6
    /* 7194 80109994 53270408 */  j          .L80109D4C
    /* 7198 80109998 000022A2 */   sb        $v0, 0x0($s1)
    /* 719C 8010999C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 71A0 801099A0 D0E14290 */  lbu        $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 71A4 801099A4 00000000 */  nop
    /* 71A8 801099A8 E8004010 */  beqz       $v0, .L80109D4C
    /* 71AC 801099AC 1180023C */   lui       $v0, %hi(_textTable)
    /* 71B0 801099B0 F8AD448C */  lw         $a0, %lo(_textTable)($v0)
    /* 71B4 801099B4 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 71B8 801099B8 68048424 */   addiu     $a0, $a0, 0x468
    /* 71BC 801099BC 0F24040C */  jal        func_8010903C
    /* 71C0 801099C0 02000424 */   addiu     $a0, $zero, 0x2
    /* 71C4 801099C4 05000224 */  addiu      $v0, $zero, 0x5
    /* 71C8 801099C8 53270408 */  j          .L80109D4C
    /* 71CC 801099CC 000022A2 */   sb        $v0, 0x0($s1)
    /* 71D0 801099D0 0F24040C */  jal        func_8010903C
    /* 71D4 801099D4 21200000 */   addu      $a0, $zero, $zero
    /* 71D8 801099D8 21804000 */  addu       $s0, $v0, $zero
    /* 71DC 801099DC DC000012 */  beqz       $s0, .L80109D50
    /* 71E0 801099E0 21100000 */   addu      $v0, $zero, $zero
    /* 71E4 801099E4 04000106 */  bgez       $s0, .L801099F8
    /* 71E8 801099E8 003C0524 */   addiu     $a1, $zero, 0x3C00
    /* 71EC 801099EC 0E000224 */  addiu      $v0, $zero, 0xE
    /* 71F0 801099F0 53270408 */  j          .L80109D4C
    /* 71F4 801099F4 000022A2 */   sb        $v0, 0x0($s1)
  .L801099F8:
    /* 71F8 801099F8 0680033C */  lui        $v1, %hi(vs_main_settings)
    /* 71FC 801099FC 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 7200 80109A00 F0AD448C */  lw         $a0, %lo(_spmcimg)($v0)
    /* 7204 80109A04 2000628C */  lw         $v0, %lo(vs_main_settings)($v1)
    /* 7208 80109A08 E0798424 */  addiu      $a0, $a0, 0x79E0
    /* 720C 80109A0C 10004234 */  ori        $v0, $v0, 0x10
    /* 7210 80109A10 0733030C */  jal        vs_battle_rMemzero
    /* 7214 80109A14 200062AC */   sw        $v0, %lo(vs_main_settings)($v1)
    /* 7218 80109A18 94260408 */  j          .L80109A50
    /* 721C 80109A1C 07000224 */   addiu     $v0, $zero, 0x7
    /* 7220 80109A20 740F040C */  jal        _loadSaveData
    /* 7224 80109A24 21200000 */   addu      $a0, $zero, $zero
    /* 7228 80109A28 21804000 */  addu       $s0, $v0, $zero
    /* 722C 80109A2C C8000012 */  beqz       $s0, .L80109D50
    /* 7230 80109A30 21100000 */   addu      $v0, $zero, $zero
    /* 7234 80109A34 0800001A */  blez       $s0, .L80109A58
    /* 7238 80109A38 1180023C */   lui       $v0, %hi(_textTable)
    /* 723C 80109A3C 8C0D040C */  jal        _applyLoadedSaveFile
    /* 7240 80109A40 21200000 */   addu      $a0, $zero, $zero
    /* 7244 80109A44 04004014 */  bnez       $v0, .L80109A58
    /* 7248 80109A48 1180023C */   lui       $v0, %hi(_textTable)
    /* 724C 80109A4C 07000224 */  addiu      $v0, $zero, 0x7
  .L80109A50:
    /* 7250 80109A50 53270408 */  j          .L80109D4C
    /* 7254 80109A54 000022A2 */   sb        $v0, 0x0($s1)
  .L80109A58:
    /* 7258 80109A58 F8AD448C */  lw         $a0, %lo(_textTable)($v0)
    /* 725C 80109A5C 00000000 */  nop
    /* 7260 80109A60 EE018424 */  addiu      $a0, $a0, 0x1EE
  .L80109A64:
    /* 7264 80109A64 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 7268 80109A68 00000000 */   nop
    /* 726C 80109A6C 04000224 */  addiu      $v0, $zero, 0x4
    /* 7270 80109A70 53270408 */  j          .L80109D4C
    /* 7274 80109A74 000022A2 */   sb        $v0, 0x0($s1)
    /* 7278 80109A78 0680053C */  lui        $a1, %hi(vs_battle_inventory)
    /* 727C 80109A7C 6801A524 */  addiu      $a1, $a1, %lo(vs_battle_inventory)
    /* 7280 80109A80 1080103C */  lui        $s0, %hi(vs_menu_inventoryStorage)
    /* 7284 80109A84 5C24048E */  lw         $a0, %lo(vs_menu_inventoryStorage)($s0)
    /* 7288 80109A88 7800030C */  jal        vs_battle_memcpy
    /* 728C 80109A8C 000F0624 */   addiu     $a2, $zero, 0xF00
    /* 7290 80109A90 0680053C */  lui        $a1, %hi(vs_main_inventoryIndices)
    /* 7294 80109A94 D819A524 */  addiu      $a1, $a1, %lo(vs_main_inventoryIndices)
    /* 7298 80109A98 5C24048E */  lw         $a0, %lo(vs_menu_inventoryStorage)($s0)
    /* 729C 80109A9C B0000624 */  addiu      $a2, $zero, 0xB0
    /* 72A0 80109AA0 7800030C */  jal        vs_battle_memcpy
    /* 72A4 80109AA4 000F8424 */   addiu     $a0, $a0, 0xF00
    /* 72A8 80109AA8 003C0624 */  addiu      $a2, $zero, 0x3C00
    /* 72AC 80109AAC 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 72B0 80109AB0 5C24048E */  lw         $a0, %lo(vs_menu_inventoryStorage)($s0)
    /* 72B4 80109AB4 F0AD458C */  lw         $a1, %lo(_spmcimg)($v0)
    /* 72B8 80109AB8 B00F8424 */  addiu      $a0, $a0, 0xFB0
    /* 72BC 80109ABC 7800030C */  jal        vs_battle_memcpy
    /* 72C0 80109AC0 E079A524 */   addiu     $a1, $a1, 0x79E0
    /* 72C4 80109AC4 8611040C */  jal        _shutdownMemcard
    /* 72C8 80109AC8 00000000 */   nop
    /* 72CC 80109ACC 08000224 */  addiu      $v0, $zero, 0x8
    /* 72D0 80109AD0 000022A2 */  sb         $v0, 0x0($s1)
    /* 72D4 80109AD4 0F80023C */  lui        $v0, %hi(vs_battle_menuState)
    /* 72D8 80109AD8 C0514490 */  lbu        $a0, %lo(vs_battle_menuState)($v0)
    /* 72DC 80109ADC 0E000324 */  addiu      $v1, $zero, 0xE
    /* 72E0 80109AE0 C05143A0 */  sb         $v1, %lo(vs_battle_menuState)($v0)
    /* 72E4 80109AE4 C0514224 */  addiu      $v0, $v0, %lo(vs_battle_menuState)
    /* 72E8 80109AE8 53270408 */  j          .L80109D4C
    /* 72EC 80109AEC 010044A0 */   sb        $a0, 0x1($v0)
    /* 72F0 80109AF0 74EA030C */  jal        vs_mainmenu_ready
    /* 72F4 80109AF4 00000000 */   nop
    /* 72F8 80109AF8 95004010 */  beqz       $v0, .L80109D50
    /* 72FC 80109AFC 21100000 */   addu      $v0, $zero, $zero
    /* 7300 80109B00 F110040C */  jal        _initMemcard
    /* 7304 80109B04 01000424 */   addiu     $a0, $zero, 0x1
    /* 7308 80109B08 09000224 */  addiu      $v0, $zero, 0x9
    /* 730C 80109B0C 53270408 */  j          .L80109D4C
    /* 7310 80109B10 000022A2 */   sb        $v0, 0x0($s1)
    /* 7314 80109B14 F110040C */  jal        _initMemcard
    /* 7318 80109B18 21200000 */   addu      $a0, $zero, $zero
    /* 731C 80109B1C 8B004010 */  beqz       $v0, .L80109D4C
    /* 7320 80109B20 0F80023C */   lui       $v0, %hi(D_800F51C1)
    /* 7324 80109B24 C1515090 */  lbu        $s0, %lo(D_800F51C1)($v0)
    /* 7328 80109B28 00000000 */  nop
    /* 732C 80109B2C 42000012 */  beqz       $s0, .L80109C38
    /* 7330 80109B30 0D000224 */   addiu     $v0, $zero, 0xD
    /* 7334 80109B34 8123030C */  jal        func_800C8E04
    /* 7338 80109B38 01000424 */   addiu     $a0, $zero, 0x1
    /* 733C 80109B3C 01000224 */  addiu      $v0, $zero, 0x1
    /* 7340 80109B40 3A000216 */  bne        $s0, $v0, .L80109C2C
    /* 7344 80109B44 00000000 */   nop
    /* 7348 80109B48 0F24040C */  jal        func_8010903C
    /* 734C 80109B4C 21204000 */   addu      $a0, $v0, $zero
    /* 7350 80109B50 1180043C */  lui        $a0, %hi(D_8010A9E2)
    /* 7354 80109B54 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 7358 80109B58 E2A98424 */   addiu     $a0, $a0, %lo(D_8010A9E2)
    /* 735C 80109B5C 0C000224 */  addiu      $v0, $zero, 0xC
    /* 7360 80109B60 53270408 */  j          .L80109D4C
    /* 7364 80109B64 000022A2 */   sb        $v0, 0x0($s1)
    /* 7368 80109B68 0100063C */  lui        $a2, (0x10030 >> 16)
    /* 736C 80109B6C 1180023C */  lui        $v0, %hi(_spmcimg)
    /* 7370 80109B70 3000C634 */  ori        $a2, $a2, (0x10030 & 0xFFFF)
    /* 7374 80109B74 F0AD448C */  lw         $a0, %lo(_spmcimg)($v0)
    /* 7378 80109B78 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 737C 80109B7C 30C40534 */  ori        $a1, $zero, 0xC430
    /* 7380 80109B80 5C24428C */  lw         $v0, %lo(vs_menu_inventoryStorage)($v0)
    /* 7384 80109B84 E0798424 */  addiu      $a0, $a0, 0x79E0
    /* 7388 80109B88 21284500 */  addu       $a1, $v0, $a1
    /* 738C 80109B8C B124040C */  jal        _copyContainer
    /* 7390 80109B90 21304600 */   addu      $a2, $v0, $a2
    /* 7394 80109B94 9A1C040C */  jal        _showSaveMenu
    /* 7398 80109B98 02000424 */   addiu     $a0, $zero, 0x2
    /* 739C 80109B9C 0B000224 */  addiu      $v0, $zero, 0xB
    /* 73A0 80109BA0 53270408 */  j          .L80109D4C
    /* 73A4 80109BA4 000022A2 */   sb        $v0, 0x0($s1)
    /* 73A8 80109BA8 9A1C040C */  jal        _showSaveMenu
    /* 73AC 80109BAC 21200000 */   addu      $a0, $zero, $zero
    /* 73B0 80109BB0 21804000 */  addu       $s0, $v0, $zero
    /* 73B4 80109BB4 10000012 */  beqz       $s0, .L80109BF8
    /* 73B8 80109BB8 1180023C */   lui       $v0, %hi(_dataNotSaved)
    /* 73BC 80109BBC ABB04290 */  lbu        $v0, %lo(_dataNotSaved)($v0)
    /* 73C0 80109BC0 00000000 */  nop
    /* 73C4 80109BC4 0B004014 */  bnez       $v0, .L80109BF4
    /* 73C8 80109BC8 0E000224 */   addiu     $v0, $zero, 0xE
    /* 73CC 80109BCC 09000106 */  bgez       $s0, .L80109BF4
    /* 73D0 80109BD0 00000000 */   nop
    /* 73D4 80109BD4 8123030C */  jal        func_800C8E04
    /* 73D8 80109BD8 01000424 */   addiu     $a0, $zero, 0x1
    /* 73DC 80109BDC 0F24040C */  jal        func_8010903C
    /* 73E0 80109BE0 01000424 */   addiu     $a0, $zero, 0x1
    /* 73E4 80109BE4 1180043C */  lui        $a0, %hi(D_8010A9E2)
    /* 73E8 80109BE8 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 73EC 80109BEC E2A98424 */   addiu     $a0, $a0, %lo(D_8010A9E2)
    /* 73F0 80109BF0 0C000224 */  addiu      $v0, $zero, 0xC
  .L80109BF4:
    /* 73F4 80109BF4 000022A2 */  sb         $v0, 0x0($s1)
  .L80109BF8:
    /* 73F8 80109BF8 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
    /* 73FC 80109BFC 10E2448C */  lw         $a0, %lo(vs_main_frameBuf)($v0)
    /* 7400 80109C00 F916040C */  jal        _drawFileMenu
    /* 7404 80109C04 00000000 */   nop
    /* 7408 80109C08 54270408 */  j          .L80109D50
    /* 740C 80109C0C 21100000 */   addu      $v0, $zero, $zero
    /* 7410 80109C10 0F24040C */  jal        func_8010903C
    /* 7414 80109C14 21200000 */   addu      $a0, $zero, $zero
    /* 7418 80109C18 21804000 */  addu       $s0, $v0, $zero
    /* 741C 80109C1C 4B000012 */  beqz       $s0, .L80109D4C
    /* 7420 80109C20 01000224 */   addiu     $v0, $zero, 0x1
    /* 7424 80109C24 04000216 */  bne        $s0, $v0, .L80109C38
    /* 7428 80109C28 0D000224 */   addiu     $v0, $zero, 0xD
  .L80109C2C:
    /* 742C 80109C2C 0A000224 */  addiu      $v0, $zero, 0xA
    /* 7430 80109C30 53270408 */  j          .L80109D4C
    /* 7434 80109C34 000022A2 */   sb        $v0, 0x0($s1)
  .L80109C38:
    /* 7438 80109C38 53270408 */  j          .L80109D4C
    /* 743C 80109C3C 000022A2 */   sb        $v0, 0x0($s1)
    /* 7440 80109C40 0680043C */  lui        $a0, %hi(vs_battle_inventory)
    /* 7444 80109C44 68018424 */  addiu      $a0, $a0, %lo(vs_battle_inventory)
    /* 7448 80109C48 000F0624 */  addiu      $a2, $zero, 0xF00
    /* 744C 80109C4C 1080103C */  lui        $s0, %hi(vs_menu_inventoryStorage)
    /* 7450 80109C50 0680083C */  lui        $t0, %hi(vs_main_settings)
    /* 7454 80109C54 1080023C */  lui        $v0, %hi(D_80102578)
    /* 7458 80109C58 EFFF0724 */  addiu      $a3, $zero, -0x11
    /* 745C 80109C5C 5C24058E */  lw         $a1, %lo(vs_menu_inventoryStorage)($s0)
    /* 7460 80109C60 2000038D */  lw         $v1, %lo(vs_main_settings)($t0)
    /* 7464 80109C64 78254290 */  lbu        $v0, %lo(D_80102578)($v0)
    /* 7468 80109C68 24186700 */  and        $v1, $v1, $a3
    /* 746C 80109C6C 01004230 */  andi       $v0, $v0, 0x1
    /* 7470 80109C70 00110200 */  sll        $v0, $v0, 4
    /* 7474 80109C74 25186200 */  or         $v1, $v1, $v0
    /* 7478 80109C78 7800030C */  jal        vs_battle_memcpy
    /* 747C 80109C7C 200003AD */   sw        $v1, %lo(vs_main_settings)($t0)
    /* 7480 80109C80 0680043C */  lui        $a0, %hi(vs_main_inventoryIndices)
    /* 7484 80109C84 D8198424 */  addiu      $a0, $a0, %lo(vs_main_inventoryIndices)
    /* 7488 80109C88 5C24058E */  lw         $a1, %lo(vs_menu_inventoryStorage)($s0)
    /* 748C 80109C8C B0000624 */  addiu      $a2, $zero, 0xB0
    /* 7490 80109C90 7800030C */  jal        vs_battle_memcpy
    /* 7494 80109C94 000FA524 */   addiu     $a1, $a1, 0xF00
    /* 7498 80109C98 3729020C */  jal        func_8008A4DC
    /* 749C 80109C9C 01000424 */   addiu     $a0, $zero, 0x1
    /* 74A0 80109CA0 952D030C */  jal        func_800CB654
    /* 74A4 80109CA4 21200000 */   addu      $a0, $zero, $zero
    /* 74A8 80109CA8 28000424 */  addiu      $a0, $zero, 0x28
    /* 74AC 80109CAC 0F80023C */  lui        $v0, %hi(D_800EB9B0)
    /* 74B0 80109CB0 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 74B4 80109CB4 B0B940AC */   sw        $zero, %lo(D_800EB9B0)($v0)
    /* 74B8 80109CB8 FCFF0424 */  addiu      $a0, $zero, -0x4
    /* 74BC 80109CBC 0501040C */  jal        func_80100414
    /* 74C0 80109CC0 80000524 */   addiu     $a1, $zero, 0x80
    /* 74C4 80109CC4 0F000224 */  addiu      $v0, $zero, 0xF
    /* 74C8 80109CC8 53270408 */  j          .L80109D4C
    /* 74CC 80109CCC 000022A2 */   sb        $v0, 0x0($s1)
    /* 74D0 80109CD0 A2FE030C */  jal        func_800FFA88
    /* 74D4 80109CD4 21200000 */   addu      $a0, $zero, $zero
    /* 74D8 80109CD8 EAFE030C */  jal        func_800FFBA8
    /* 74DC 80109CDC 00000000 */   nop
    /* 74E0 80109CE0 DAFE030C */  jal        func_800FFB68
    /* 74E4 80109CE4 21200000 */   addu      $a0, $zero, $zero
    /* 74E8 80109CE8 74EA030C */  jal        vs_mainmenu_ready
    /* 74EC 80109CEC 00000000 */   nop
    /* 74F0 80109CF0 17004010 */  beqz       $v0, .L80109D50
    /* 74F4 80109CF4 21100000 */   addu      $v0, $zero, $zero
    /* 74F8 80109CF8 8611040C */  jal        _shutdownMemcard
    /* 74FC 80109CFC 00000000 */   nop
    /* 7500 80109D00 10000224 */  addiu      $v0, $zero, 0x10
  .L80109D04:
    /* 7504 80109D04 53270408 */  j          .L80109D4C
    /* 7508 80109D08 000022A2 */   sb        $v0, 0x0($s1)
    /* 750C 80109D0C 1934030C */  jal        vs_battle_dismissTextBox
    /* 7510 80109D10 07000424 */   addiu     $a0, $zero, 0x7
    /* 7514 80109D14 0E004014 */  bnez       $v0, .L80109D50
    /* 7518 80109D18 21100000 */   addu      $v0, $zero, $zero
    /* 751C 80109D1C 1080023C */  lui        $v0, %hi(D_801022D8)
    /* 7520 80109D20 D822428C */  lw         $v0, %lo(D_801022D8)($v0)
    /* 7524 80109D24 00000000 */  nop
    /* 7528 80109D28 09004014 */  bnez       $v0, .L80109D50
    /* 752C 80109D2C 21100000 */   addu      $v0, $zero, $zero
    /* 7530 80109D30 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 7534 80109D34 5C24448C */  lw         $a0, %lo(vs_menu_inventoryStorage)($v0)
    /* 7538 80109D38 180F010C */  jal        vs_main_freeHeapR
    /* 753C 80109D3C 00000000 */   nop
    /* 7540 80109D40 01000224 */  addiu      $v0, $zero, 0x1
    /* 7544 80109D44 54270408 */  j          .L80109D50
    /* 7548 80109D48 000020A2 */   sb        $zero, 0x0($s1)
  .L80109D4C:
    /* 754C 80109D4C 21100000 */  addu       $v0, $zero, $zero
  .L80109D50:
    /* 7550 80109D50 2000BF8F */  lw         $ra, 0x20($sp)
    /* 7554 80109D54 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 7558 80109D58 1800B08F */  lw         $s0, 0x18($sp)
    /* 755C 80109D5C 0800E003 */  jr         $ra
    /* 7560 80109D60 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_menu7_saveContainerMenu
