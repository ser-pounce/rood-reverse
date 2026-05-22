nonmatching func_80107490, 0x152C

glabel func_80107490
    /* 4C90 80107490 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 4C94 80107494 3000B0AF */  sw         $s0, 0x30($sp)
    /* 4C98 80107498 21808000 */  addu       $s0, $a0, $zero
    /* 4C9C 8010749C 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 4CA0 801074A0 4800B6AF */  sw         $s6, 0x48($sp)
    /* 4CA4 801074A4 4400B5AF */  sw         $s5, 0x44($sp)
    /* 4CA8 801074A8 4000B4AF */  sw         $s4, 0x40($sp)
    /* 4CAC 801074AC 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 4CB0 801074B0 3800B2AF */  sw         $s2, 0x38($sp)
    /* 4CB4 801074B4 3400B1AF */  sw         $s1, 0x34($sp)
  .L801074B8:
    /* 4CB8 801074B8 36000012 */  beqz       $s0, .L80107594
    /* 4CBC 801074BC 01000424 */   addiu     $a0, $zero, 0x1
    /* 4CC0 801074C0 1180033C */  lui        $v1, %hi(D_80109A6A)
    /* 4CC4 801074C4 21108000 */  addu       $v0, $a0, $zero
    /* 4CC8 801074C8 540F040C */  jal        func_80103D50
    /* 4CCC 801074CC 6A9A62A0 */   sb        $v0, %lo(D_80109A6A)($v1)
    /* 4CD0 801074D0 0680023C */  lui        $v0, %hi(D_80060021)
    /* 4CD4 801074D4 21004390 */  lbu        $v1, %lo(D_80060021)($v0)
    /* 4CD8 801074D8 1180023C */  lui        $v0, %hi(D_80109A7E)
    /* 4CDC 801074DC 06006014 */  bnez       $v1, .L801074F8
    /* 4CE0 801074E0 7E9A40A0 */   sb        $zero, %lo(D_80109A7E)($v0)
    /* 4CE4 801074E4 0F80043C */  lui        $a0, %hi(D_800F4EE8 + 0xA0)
    /* 4CE8 801074E8 884F8424 */  addiu      $a0, $a0, %lo(D_800F4EE8 + 0xA0)
    /* 4CEC 801074EC 21280000 */  addu       $a1, $zero, $zero
    /* 4CF0 801074F0 AD9B000C */  jal        memset
    /* 4CF4 801074F4 12000624 */   addiu     $a2, $zero, 0x12
  .L801074F8:
    /* 4CF8 801074F8 003C0524 */  addiu      $a1, $zero, 0x3C00
    /* 4CFC 801074FC 1080113C */  lui        $s1, %hi(vs_menu_inventoryStorage)
    /* 4D00 80107500 5C24228E */  lw         $v0, %lo(vs_menu_inventoryStorage)($s1)
    /* 4D04 80107504 B0870434 */  ori        $a0, $zero, 0x87B0
    /* 4D08 80107508 0733030C */  jal        vs_battle_rMemzero
    /* 4D0C 8010750C 21204400 */   addu      $a0, $v0, $a0
    /* 4D10 80107510 80000524 */  addiu      $a1, $zero, 0x80
    /* 4D14 80107514 5C24228E */  lw         $v0, %lo(vs_menu_inventoryStorage)($s1)
    /* 4D18 80107518 B0C30434 */  ori        $a0, $zero, 0xC3B0
    /* 4D1C 8010751C 0733030C */  jal        vs_battle_rMemzero
    /* 4D20 80107520 21204400 */   addu      $a0, $v0, $a0
    /* 4D24 80107524 1180033C */  lui        $v1, %hi(D_80109A7A)
    /* 4D28 80107528 FFFF0226 */  addiu      $v0, $s0, -0x1
    /* 4D2C 8010752C 7A9A62A0 */  sb         $v0, %lo(D_80109A7A)($v1)
    /* 4D30 80107530 FF004230 */  andi       $v0, $v0, 0xFF
    /* 4D34 80107534 0B004010 */  beqz       $v0, .L80107564
    /* 4D38 80107538 0100023C */   lui       $v0, (0x105B0 >> 16)
    /* 4D3C 8010753C B0054234 */  ori        $v0, $v0, (0x105B0 & 0xFFFF)
    /* 4D40 80107540 5C24238E */  lw         $v1, %lo(vs_menu_inventoryStorage)($s1)
    /* 4D44 80107544 1180043C */  lui        $a0, %hi(vs_menuD_containerData)
    /* 4D48 80107548 21106200 */  addu       $v0, $v1, $v0
    /* 4D4C 8010754C 8C9A82AC */  sw         $v0, %lo(vs_menuD_containerData)($a0)
    /* 4D50 80107550 1180043C */  lui        $a0, %hi(D_80109A88)
    /* 4D54 80107554 30C40234 */  ori        $v0, $zero, 0xC430
    /* 4D58 80107558 21186200 */  addu       $v1, $v1, $v0
    /* 4D5C 8010755C 631D0408 */  j          .L8010758C
    /* 4D60 80107560 889A83AC */   sw        $v1, %lo(D_80109A88)($a0)
  .L80107564:
    /* 4D64 80107564 0100053C */  lui        $a1, (0x105B0 >> 16)
    /* 4D68 80107568 B005A534 */  ori        $a1, $a1, (0x105B0 & 0xFFFF)
    /* 4D6C 8010756C 1180043C */  lui        $a0, %hi(vs_menuD_containerData)
    /* 4D70 80107570 5C24238E */  lw         $v1, %lo(vs_menu_inventoryStorage)($s1)
    /* 4D74 80107574 30C40234 */  ori        $v0, $zero, 0xC430
    /* 4D78 80107578 21106200 */  addu       $v0, $v1, $v0
    /* 4D7C 8010757C 8C9A82AC */  sw         $v0, %lo(vs_menuD_containerData)($a0)
    /* 4D80 80107580 1180023C */  lui        $v0, %hi(D_80109A88)
    /* 4D84 80107584 21186500 */  addu       $v1, $v1, $a1
    /* 4D88 80107588 889A43AC */  sw         $v1, %lo(D_80109A88)($v0)
  .L8010758C:
    /* 4D8C 8010758C A4210408 */  j          .L80108690
    /* 4D90 80107590 1180033C */   lui       $v1, %hi(D_80109A68)
  .L80107594:
    /* 4D94 80107594 0F80023C */  lui        $v0, %hi(D_800F4EE8 + 0xA0)
    /* 4D98 80107598 1180033C */  lui        $v1, %hi(vs_menuD_containerData)
    /* 4D9C 8010759C 884F4290 */  lbu        $v0, %lo(D_800F4EE8 + 0xA0)($v0)
    /* 4DA0 801075A0 8C9A658C */  lw         $a1, %lo(vs_menuD_containerData)($v1)
    /* 4DA4 801075A4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 4DA8 801075A8 07005430 */  andi       $s4, $v0, 0x7
    /* 4DAC 801075AC 250B040C */  jal        _getContainerIndicesOffset
    /* 4DB0 801075B0 21208002 */   addu      $a0, $s4, $zero
    /* 4DB4 801075B4 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 4DB8 801075B8 689A6390 */  lbu        $v1, %lo(D_80109A68)($v1)
    /* 4DBC 801075BC 21884000 */  addu       $s1, $v0, $zero
    /* 4DC0 801075C0 1200622C */  sltiu      $v0, $v1, 0x12
    /* 4DC4 801075C4 F2044010 */  beqz       $v0, .L80108990
    /* 4DC8 801075C8 1080023C */   lui       $v0, %hi(jtbl_801029A0)
    /* 4DCC 801075CC A0294224 */  addiu      $v0, $v0, %lo(jtbl_801029A0)
    /* 4DD0 801075D0 80180300 */  sll        $v1, $v1, 2
    /* 4DD4 801075D4 21186200 */  addu       $v1, $v1, $v0
    /* 4DD8 801075D8 0000628C */  lw         $v0, 0x0($v1)
    /* 4DDC 801075DC 00000000 */  nop
    /* 4DE0 801075E0 08004000 */  jr         $v0
    /* 4DE4 801075E4 00000000 */   nop
    /* 4DE8 801075E8 F2FE030C */  jal        func_800FFBC8
    /* 4DEC 801075EC 00000000 */   nop
    /* 4DF0 801075F0 8F0F010C */  jal        vs_main_allocHeapR
    /* 4DF4 801075F4 006C0424 */   addiu     $a0, $zero, 0x6C00
    /* 4DF8 801075F8 21884000 */  addu       $s1, $v0, $zero
    /* 4DFC 801075FC 00603626 */  addiu      $s6, $s1, 0x6000
    /* 4E00 80107600 00643526 */  addiu      $s5, $s1, 0x6400
    /* 4E04 80107604 1080033C */  lui        $v1, %hi(D_801023E3)
    /* 4E08 80107608 01000224 */  addiu      $v0, $zero, 0x1
    /* 4E0C 8010760C E32362A0 */  sb         $v0, %lo(D_801023E3)($v1)
    /* 4E10 80107610 21980000 */  addu       $s3, $zero, $zero
    /* 4E14 80107614 1180103C */  lui        $s0, %hi(vs_menuD_containerData)
    /* 4E18 80107618 21206002 */  addu       $a0, $s3, $zero
  .L8010761C:
    /* 4E1C 8010761C 8C9A058E */  lw         $a1, %lo(vs_menuD_containerData)($s0)
    /* 4E20 80107620 F60D040C */  jal        _defragmentContainerItems
    /* 4E24 80107624 01007326 */   addiu     $s3, $s3, 0x1
    /* 4E28 80107628 0700622A */  slti       $v0, $s3, 0x7
    /* 4E2C 8010762C FBFF4014 */  bnez       $v0, .L8010761C
    /* 4E30 80107630 21206002 */   addu      $a0, $s3, $zero
    /* 4E34 80107634 941A040C */  jal        func_80106A50
    /* 4E38 80107638 00000000 */   nop
    /* 4E3C 8010763C 21208002 */  addu       $a0, $s4, $zero
    /* 4E40 80107640 2128A002 */  addu       $a1, $s5, $zero
    /* 4E44 80107644 2130C002 */  addu       $a2, $s6, $zero
    /* 4E48 80107648 191B040C */  jal        func_80106C64
    /* 4E4C 8010764C 21382002 */   addu      $a3, $s1, $zero
    /* 4E50 80107650 21904000 */  addu       $s2, $v0, $zero
    /* 4E54 80107654 1180033C */  lui        $v1, %hi(D_80109A69)
    /* 4E58 80107658 0100422E */  sltiu      $v0, $s2, 0x1
    /* 4E5C 8010765C 15004010 */  beqz       $v0, .L801076B4
    /* 4E60 80107660 699A62A0 */   sb        $v0, %lo(D_80109A69)($v1)
    /* 4E64 80107664 1180023C */  lui        $v0, %hi(_menuText)
    /* 4E68 80107668 1180033C */  lui        $v1, %hi(D_80109A7A)
    /* 4E6C 8010766C 7A9A6490 */  lbu        $a0, %lo(D_80109A7A)($v1)
    /* 4E70 80107670 2C954524 */  addiu      $a1, $v0, %lo(_menuText)
    /* 4E74 80107674 07000224 */  addiu      $v0, $zero, 0x7
    /* 4E78 80107678 04008216 */  bne        $s4, $v0, .L8010768C
    /* 4E7C 8010767C 1B008324 */   addiu     $v1, $a0, 0x1B
    /* 4E80 80107680 1D008224 */  addiu      $v0, $a0, 0x1D
    /* 4E84 80107684 A41D0408 */  j          .L80107690
    /* 4E88 80107688 40100200 */   sll       $v0, $v0, 1
  .L8010768C:
    /* 4E8C 8010768C 40100300 */  sll        $v0, $v1, 1
  .L80107690:
    /* 4E90 80107690 2110A200 */  addu       $v0, $a1, $v0
    /* 4E94 80107694 00004294 */  lhu        $v0, 0x0($v0)
    /* 4E98 80107698 1180043C */  lui        $a0, %hi(_menuText)
    /* 4E9C 8010769C 2C958424 */  addiu      $a0, $a0, %lo(_menuText)
    /* 4EA0 801076A0 40100200 */  sll        $v0, $v0, 1
    /* 4EA4 801076A4 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 4EA8 801076A8 21204400 */   addu      $a0, $v0, $a0
    /* 4EAC 801076AC C71D0408 */  j          .L8010771C
    /* 4EB0 801076B0 00000000 */   nop
  .L801076B4:
    /* 4EB4 801076B4 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 4EB8 801076B8 20005024 */  addiu      $s0, $v0, %lo(vs_main_settings)
    /* 4EBC 801076BC 1180033C */  lui        $v1, %hi(D_80109A6A)
    /* 4EC0 801076C0 6A9A6290 */  lbu        $v0, %lo(D_80109A6A)($v1)
    /* 4EC4 801076C4 01001392 */  lbu        $s3, 0x1($s0)
    /* 4EC8 801076C8 04004014 */  bnez       $v0, .L801076DC
    /* 4ECC 801076CC 0100023C */   lui       $v0, (0x19200 >> 16)
    /* 4ED0 801076D0 01000224 */  addiu      $v0, $zero, 0x1
    /* 4ED4 801076D4 010002A2 */  sb         $v0, 0x1($s0)
    /* 4ED8 801076D8 0100023C */  lui        $v0, (0x19200 >> 16)
  .L801076DC:
    /* 4EDC 801076DC 00924234 */  ori        $v0, $v0, (0x19200 & 0xFFFF)
    /* 4EE0 801076E0 21204002 */  addu       $a0, $s2, $zero
    /* 4EE4 801076E4 51008526 */  addiu      $a1, $s4, 0x51
    /* 4EE8 801076E8 2528A200 */  or         $a1, $a1, $v0
    /* 4EEC 801076EC 2130A002 */  addu       $a2, $s5, $zero
    /* 4EF0 801076F0 2138C002 */  addu       $a3, $s6, $zero
    /* 4EF4 801076F4 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 4EF8 801076F8 6A9A60A0 */   sb        $zero, %lo(D_80109A6A)($v1)
    /* 4EFC 801076FC 1180023C */  lui        $v0, %hi(D_80109A68)
    /* 4F00 80107700 689A4290 */  lbu        $v0, %lo(D_80109A68)($v0)
    /* 4F04 80107704 00000000 */  nop
    /* 4F08 80107708 03004014 */  bnez       $v0, .L80107718
    /* 4F0C 8010770C 00000000 */   nop
    /* 4F10 80107710 761C040C */  jal        func_801071D8
    /* 4F14 80107714 21208002 */   addu      $a0, $s4, $zero
  .L80107718:
    /* 4F18 80107718 010013A2 */  sb         $s3, 0x1($s0)
  .L8010771C:
    /* 4F1C 8010771C 180F010C */  jal        vs_main_freeHeapR
    /* 4F20 80107720 21202002 */   addu      $a0, $s1, $zero
    /* 4F24 80107724 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 4F28 80107728 02000224 */  addiu      $v0, $zero, 0x2
    /* 4F2C 8010772C 64220408 */  j          .L80108990
    /* 4F30 80107730 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
    /* 4F34 80107734 1180153C */  lui        $s5, %hi(D_80109A7D)
    /* 4F38 80107738 1180023C */  lui        $v0, %hi(D_80109A69)
    /* 4F3C 8010773C 699A4390 */  lbu        $v1, %lo(D_80109A69)($v0)
    /* 4F40 80107740 01000224 */  addiu      $v0, $zero, 0x1
    /* 4F44 80107744 1F006010 */  beqz       $v1, .L801077C4
    /* 4F48 80107748 7D9AA2A2 */   sb        $v0, %lo(D_80109A7D)($s5)
    /* 4F4C 8010774C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 4F50 80107750 D0E1438C */  lw         $v1, %lo(vs_main_buttonsPressed)($v0)
    /* 4F54 80107754 00000000 */  nop
    /* 4F58 80107758 10006230 */  andi       $v0, $v1, 0x10
    /* 4F5C 8010775C 05004010 */  beqz       $v0, .L80107774
    /* 4F60 80107760 40006230 */   andi      $v0, $v1, 0x40
    /* 4F64 80107764 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 4F68 80107768 00000000 */   nop
    /* 4F6C 8010776C 65220408 */  j          .L80108994
    /* 4F70 80107770 FEFF0224 */   addiu     $v0, $zero, -0x2
  .L80107774:
    /* 4F74 80107774 0D004010 */  beqz       $v0, .L801077AC
    /* 4F78 80107778 A0006230 */   andi      $v0, $v1, 0xA0
    /* 4F7C 8010777C BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 4F80 80107780 00000000 */   nop
    /* 4F84 80107784 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 4F88 80107788 5C24428C */  lw         $v0, %lo(vs_menu_inventoryStorage)($v0)
    /* 4F8C 8010778C 00800334 */  ori        $v1, $zero, 0x8000
    /* 4F90 80107790 21104300 */  addu       $v0, $v0, $v1
    /* 4F94 80107794 B0434294 */  lhu        $v0, 0x43B0($v0)
    /* 4F98 80107798 00000000 */  nop
    /* 4F9C 8010779C 76004014 */  bnez       $v0, .L80107978
    /* 4FA0 801077A0 07000224 */   addiu     $v0, $zero, 0x7
    /* 4FA4 801077A4 65220408 */  j          .L80108994
    /* 4FA8 801077A8 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L801077AC:
    /* 4FAC 801077AC 7C004010 */  beqz       $v0, .L801079A0
    /* 4FB0 801077B0 0680023C */   lui       $v0, %hi(vs_main_buttonsState)
  .L801077B4:
    /* 4FB4 801077B4 B800030C */  jal        vs_battle_playInvalidSfx
    /* 4FB8 801077B8 00000000 */   nop
    /* 4FBC 801077BC 681E0408 */  j          .L801079A0
    /* 4FC0 801077C0 0680023C */   lui       $v0, %hi(vs_main_buttonsState)
  .L801077C4:
    /* 4FC4 801077C4 0600902A */  slti       $s0, $s4, 0x6
    /* 4FC8 801077C8 01000226 */  addiu      $v0, $s0, 0x1
    /* 4FCC 801077CC 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 4FD0 801077D0 7D9AA2A2 */   sb        $v0, %lo(D_80109A7D)($s5)
    /* 4FD4 801077D4 1180133C */  lui        $s3, %hi(D_80109A6C)
    /* 4FD8 801077D8 21204000 */  addu       $a0, $v0, $zero
    /* 4FDC 801077DC 01008324 */  addiu      $v1, $a0, 0x1
    /* 4FE0 801077E0 01001624 */  addiu      $s6, $zero, 0x1
    /* 4FE4 801077E4 1F006014 */  bnez       $v1, .L80107864
    /* 4FE8 801077E8 6C9A63AE */   sw        $v1, %lo(D_80109A6C)($s3)
    /* 4FEC 801077EC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 4FF0 801077F0 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 4FF4 801077F4 00000000 */  nop
    /* 4FF8 801077F8 80004230 */  andi       $v0, $v0, 0x80
    /* 4FFC 801077FC 68004010 */  beqz       $v0, .L801079A0
    /* 5000 80107800 0680023C */   lui       $v0, %hi(vs_main_buttonsState)
    /* 5004 80107804 EBFF0012 */  beqz       $s0, .L801077B4
    /* 5008 80107808 00000000 */   nop
    /* 500C 8010780C 74EA030C */  jal        vs_mainmenu_ready
    /* 5010 80107810 00000000 */   nop
    /* 5014 80107814 E7FF4010 */  beqz       $v0, .L801077B4
    /* 5018 80107818 00000000 */   nop
    /* 501C 8010781C BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 5020 80107820 00000000 */   nop
    /* 5024 80107824 0502040C */  jal        func_80100814
    /* 5028 80107828 00000000 */   nop
    /* 502C 8010782C 21804000 */  addu       $s0, $v0, $zero
    /* 5030 80107830 9223030C */  jal        vs_battle_getMenuItem
    /* 5034 80107834 03221000 */   sra       $a0, $s0, 8
    /* 5038 80107838 21201602 */  addu       $a0, $s0, $s6
    /* 503C 8010783C 00210400 */  sll        $a0, $a0, 4
    /* 5040 80107840 25208402 */  or         $a0, $s4, $a0
    /* 5044 80107844 0214040C */  jal        func_80105008
    /* 5048 80107848 0D0040A0 */   sb        $zero, 0xD($v0)
    /* 504C 8010784C 1180023C */  lui        $v0, %hi(D_80109A7B)
    /* 5050 80107850 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5054 80107854 7B9A40A0 */  sb         $zero, %lo(D_80109A7B)($v0)
    /* 5058 80107858 07000224 */  addiu      $v0, $zero, 0x7
    /* 505C 8010785C 64220408 */  j          .L80108990
    /* 5060 80107860 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
  .L80107864:
    /* 5064 80107864 35006018 */  blez       $v1, .L8010793C
    /* 5068 80107868 07000224 */   addiu     $v0, $zero, 0x7
    /* 506C 8010786C 0B008216 */  bne        $s4, $v0, .L8010789C
    /* 5070 80107870 00000000 */   nop
    /* 5074 80107874 2F1A040C */  jal        func_801068BC
    /* 5078 80107878 00000000 */   nop
    /* 507C 8010787C 9C0C040C */  jal        func_80103270
    /* 5080 80107880 00000000 */   nop
    /* 5084 80107884 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 5088 80107888 21200000 */   addu      $a0, $zero, $zero
    /* 508C 8010788C 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5090 80107890 04000224 */  addiu      $v0, $zero, 0x4
    /* 5094 80107894 671E0408 */  j          .L8010799C
    /* 5098 80107898 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
  .L8010789C:
    /* 509C 8010789C 8F0F010C */  jal        vs_main_allocHeapR
    /* 50A0 801078A0 006C0424 */   addiu     $a0, $zero, 0x6C00
    /* 50A4 801078A4 21208002 */  addu       $a0, $s4, $zero
    /* 50A8 801078A8 21904000 */  addu       $s2, $v0, $zero
    /* 50AC 801078AC 00645026 */  addiu      $s0, $s2, 0x6400
    /* 50B0 801078B0 21280002 */  addu       $a1, $s0, $zero
    /* 50B4 801078B4 00605126 */  addiu      $s1, $s2, 0x6000
    /* 50B8 801078B8 21302002 */  addu       $a2, $s1, $zero
    /* 50BC 801078BC 191B040C */  jal        func_80106C64
    /* 50C0 801078C0 21384002 */   addu      $a3, $s2, $zero
    /* 50C4 801078C4 0100063C */  lui        $a2, (0x19200 >> 16)
    /* 50C8 801078C8 0092C634 */  ori        $a2, $a2, (0x19200 & 0xFFFF)
    /* 50CC 801078CC 21204000 */  addu       $a0, $v0, $zero
    /* 50D0 801078D0 51008526 */  addiu      $a1, $s4, 0x51
    /* 50D4 801078D4 2528A600 */  or         $a1, $a1, $a2
    /* 50D8 801078D8 21300002 */  addu       $a2, $s0, $zero
    /* 50DC 801078DC 6C9A638E */  lw         $v1, %lo(D_80109A6C)($s3)
    /* 50E0 801078E0 0680103C */  lui        $s0, %hi(vs_main_settings)
    /* 50E4 801078E4 80180300 */  sll        $v1, $v1, 2
    /* 50E8 801078E8 21187100 */  addu       $v1, $v1, $s1
    /* 50EC 801078EC FCFF628C */  lw         $v0, -0x4($v1)
    /* 50F0 801078F0 20001026 */  addiu      $s0, $s0, %lo(vs_main_settings)
    /* 50F4 801078F4 08004234 */  ori        $v0, $v0, 0x8
    /* 50F8 801078F8 FCFF62AC */  sw         $v0, -0x4($v1)
    /* 50FC 801078FC 01001392 */  lbu        $s3, 0x1($s0)
    /* 5100 80107900 21382002 */  addu       $a3, $s1, $zero
    /* 5104 80107904 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 5108 80107908 010016A2 */   sb        $s6, 0x1($s0)
    /* 510C 8010790C 21208002 */  addu       $a0, $s4, $zero
    /* 5110 80107910 761C040C */  jal        func_801071D8
    /* 5114 80107914 010013A2 */   sb        $s3, 0x1($s0)
    /* 5118 80107918 21204002 */  addu       $a0, $s2, $zero
    /* 511C 8010791C 1080023C */  lui        $v0, %hi(D_801023E3)
    /* 5120 80107920 7D9AB6A2 */  sb         $s6, %lo(D_80109A7D)($s5)
    /* 5124 80107924 180F010C */  jal        vs_main_freeHeapR
    /* 5128 80107928 E32340A0 */   sb        $zero, %lo(D_801023E3)($v0)
    /* 512C 8010792C 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5130 80107930 06000224 */  addiu      $v0, $zero, 0x6
    /* 5134 80107934 671E0408 */  j          .L8010799C
    /* 5138 80107938 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
  .L8010793C:
    /* 513C 8010793C FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 5140 80107940 14046210 */  beq        $v1, $v0, .L80108994
    /* 5144 80107944 00800334 */   ori       $v1, $zero, 0x8000
    /* 5148 80107948 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 514C 8010794C 5C24428C */  lw         $v0, %lo(vs_menu_inventoryStorage)($v0)
    /* 5150 80107950 00000000 */  nop
    /* 5154 80107954 21104300 */  addu       $v0, $v0, $v1
    /* 5158 80107958 B0434294 */  lhu        $v0, 0x43B0($v0)
    /* 515C 8010795C 00000000 */  nop
    /* 5160 80107960 05004014 */  bnez       $v0, .L80107978
    /* 5164 80107964 07000224 */   addiu     $v0, $zero, 0x7
    /* 5168 80107968 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 516C 8010796C 21200000 */   addu      $a0, $zero, $zero
    /* 5170 80107970 65220408 */  j          .L80108994
    /* 5174 80107974 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80107978:
    /* 5178 80107978 95038212 */  beq        $s4, $v0, .L801087D0
    /* 517C 8010797C 21200000 */   addu      $a0, $zero, $zero
    /* 5180 80107980 0F80023C */  lui        $v0, %hi(D_800F4EE8 + 0xA0)
    /* 5184 80107984 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 5188 80107988 884F40A0 */   sb        $zero, %lo(D_800F4EE8 + 0xA0)($v0)
    /* 518C 8010798C 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5190 80107990 0D000224 */  addiu      $v0, $zero, 0xD
    /* 5194 80107994 64220408 */  j          .L80108990
    /* 5198 80107998 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
  .L8010799C:
    /* 519C 8010799C 0680023C */  lui        $v0, %hi(vs_main_buttonsState)
  .L801079A0:
    /* 51A0 801079A0 38E2428C */  lw         $v0, %lo(vs_main_buttonsState)($v0)
    /* 51A4 801079A4 00000000 */  nop
    /* 51A8 801079A8 04805330 */  andi       $s3, $v0, 0x8004
    /* 51AC 801079AC 08205230 */  andi       $s2, $v0, 0x2008
    /* 51B0 801079B0 2B101300 */  sltu       $v0, $zero, $s3
    /* 51B4 801079B4 03004012 */  beqz       $s2, .L801079C4
    /* 51B8 801079B8 21204000 */   addu      $a0, $v0, $zero
    /* 51BC 801079BC 721E0408 */  j          .L801079C8
    /* 51C0 801079C0 01005038 */   xori      $s0, $v0, 0x1
  .L801079C4:
    /* 51C4 801079C4 01009030 */  andi       $s0, $a0, 0x1
  .L801079C8:
    /* 51C8 801079C8 2F000012 */  beqz       $s0, .L80107A88
    /* 51CC 801079CC 04800634 */   ori       $a2, $zero, 0x8004
    /* 51D0 801079D0 02006616 */  bne        $s3, $a2, .L801079DC
    /* 51D4 801079D4 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 51D8 801079D8 00800634 */  ori        $a2, $zero, 0x8000
  .L801079DC:
    /* 51DC 801079DC DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 51E0 801079E0 00000000 */  nop
    /* 51E4 801079E4 24106600 */  and        $v0, $v1, $a2
    /* 51E8 801079E8 02004010 */  beqz       $v0, .L801079F4
    /* 51EC 801079EC FFFF8226 */   addiu     $v0, $s4, -0x1
    /* 51F0 801079F0 07005430 */  andi       $s4, $v0, 0x7
  .L801079F4:
    /* 51F4 801079F4 08200624 */  addiu      $a2, $zero, 0x2008
    /* 51F8 801079F8 03004616 */  bne        $s2, $a2, .L80107A08
    /* 51FC 801079FC 24106600 */   and       $v0, $v1, $a2
    /* 5200 80107A00 00200624 */  addiu      $a2, $zero, 0x2000
    /* 5204 80107A04 24106600 */  and        $v0, $v1, $a2
  .L80107A08:
    /* 5208 80107A08 02004010 */  beqz       $v0, .L80107A14
    /* 520C 80107A0C 01008226 */   addiu     $v0, $s4, 0x1
    /* 5210 80107A10 07005430 */  andi       $s4, $v0, 0x7
  .L80107A14:
    /* 5214 80107A14 0F80023C */  lui        $v0, %hi(D_800F4EE8)
    /* 5218 80107A18 E84E5124 */  addiu      $s1, $v0, %lo(D_800F4EE8)
    /* 521C 80107A1C A0002292 */  lbu        $v0, 0xA0($s1)
    /* 5220 80107A20 00000000 */  nop
    /* 5224 80107A24 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 5228 80107A28 07004230 */  andi       $v0, $v0, 0x7
    /* 522C 80107A2C 16008212 */  beq        $s4, $v0, .L80107A88
    /* 5230 80107A30 00000000 */   nop
    /* 5234 80107A34 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 5238 80107A38 00000000 */   nop
    /* 523C 80107A3C 01008226 */  addiu      $v0, $s4, 0x1
    /* 5240 80107A40 07004230 */  andi       $v0, $v0, 0x7
    /* 5244 80107A44 A00022A2 */  sb         $v0, 0xA0($s1)
    /* 5248 80107A48 1180113C */  lui        $s1, %hi(D_80109A68)
    /* 524C 80107A4C 689A2392 */  lbu        $v1, %lo(D_80109A68)($s1)
    /* 5250 80107A50 02000224 */  addiu      $v0, $zero, 0x2
    /* 5254 80107A54 0F006214 */  bne        $v1, $v0, .L80107A94
    /* 5258 80107A58 03000224 */   addiu     $v0, $zero, 0x3
    /* 525C 80107A5C 1180023C */  lui        $v0, %hi(D_80109A69)
    /* 5260 80107A60 699A4290 */  lbu        $v0, %lo(D_80109A69)($v0)
    /* 5264 80107A64 00000000 */  nop
    /* 5268 80107A68 06004014 */  bnez       $v0, .L80107A84
    /* 526C 80107A6C 03000224 */   addiu     $v0, $zero, 0x3
    /* 5270 80107A70 0502040C */  jal        func_80100814
    /* 5274 80107A74 00000000 */   nop
    /* 5278 80107A78 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 527C 80107A7C 21200000 */   addu      $a0, $zero, $zero
    /* 5280 80107A80 03000224 */  addiu      $v0, $zero, 0x3
  .L80107A84:
    /* 5284 80107A84 689A22A2 */  sb         $v0, %lo(D_80109A68)($s1)
  .L80107A88:
    /* 5288 80107A88 1180113C */  lui        $s1, %hi(D_80109A68)
    /* 528C 80107A8C 689A2392 */  lbu        $v1, %lo(D_80109A68)($s1)
    /* 5290 80107A90 03000224 */  addiu      $v0, $zero, 0x3
  .L80107A94:
    /* 5294 80107A94 BF036214 */  bne        $v1, $v0, .L80108994
    /* 5298 80107A98 21100000 */   addu      $v0, $zero, $zero
    /* 529C 80107A9C 74EA030C */  jal        vs_mainmenu_ready
    /* 52A0 80107AA0 00000000 */   nop
    /* 52A4 80107AA4 BA034010 */  beqz       $v0, .L80108990
    /* 52A8 80107AA8 0680023C */   lui       $v0, %hi(vs_main_buttonsState)
    /* 52AC 80107AAC 38E2428C */  lw         $v0, %lo(vs_main_buttonsState)($v0)
    /* 52B0 80107AB0 00000000 */  nop
    /* 52B4 80107AB4 0CA04230 */  andi       $v0, $v0, 0xA00C
    /* 52B8 80107AB8 04004010 */  beqz       $v0, .L80107ACC
    /* 52BC 80107ABC 01000224 */   addiu     $v0, $zero, 0x1
    /* 52C0 80107AC0 B4030016 */  bnez       $s0, .L80108994
    /* 52C4 80107AC4 21100000 */   addu      $v0, $zero, $zero
    /* 52C8 80107AC8 01000224 */  addiu      $v0, $zero, 0x1
  .L80107ACC:
    /* 52CC 80107ACC 689A22A2 */  sb         $v0, %lo(D_80109A68)($s1)
    /* 52D0 80107AD0 2E1D0408 */  j          .L801074B8
    /* 52D4 80107AD4 21800000 */   addu      $s0, $zero, $zero
    /* 52D8 80107AD8 74EA030C */  jal        vs_mainmenu_ready
    /* 52DC 80107ADC 00000000 */   nop
    /* 52E0 80107AE0 AB034010 */  beqz       $v0, .L80108990
    /* 52E4 80107AE4 1180033C */   lui       $v1, %hi(D_80109A68)
    /* 52E8 80107AE8 A5210408 */  j          .L80108694
    /* 52EC 80107AEC 01000224 */   addiu     $v0, $zero, 0x1
    /* 52F0 80107AF0 74EA030C */  jal        vs_mainmenu_ready
    /* 52F4 80107AF4 00000000 */   nop
    /* 52F8 80107AF8 A5034010 */  beqz       $v0, .L80108990
    /* 52FC 80107AFC 1180023C */   lui       $v0, %hi(D_80109A68)
    /* 5300 80107B00 64220408 */  j          .L80108990
    /* 5304 80107B04 689A40A0 */   sb        $zero, %lo(D_80109A68)($v0)
    /* 5308 80107B08 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 530C 80107B0C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 5310 80107B10 00000000 */  nop
    /* 5314 80107B14 80004230 */  andi       $v0, $v0, 0x80
    /* 5318 80107B18 03004010 */  beqz       $v0, .L80107B28
    /* 531C 80107B1C 00000000 */   nop
    /* 5320 80107B20 B800030C */  jal        vs_battle_playInvalidSfx
    /* 5324 80107B24 00000000 */   nop
  .L80107B28:
    /* 5328 80107B28 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 532C 80107B2C 00000000 */   nop
    /* 5330 80107B30 01005324 */  addiu      $s3, $v0, 0x1
    /* 5334 80107B34 96036012 */  beqz       $s3, .L80108990
    /* 5338 80107B38 1180023C */   lui       $v0, %hi(D_80109A6C)
    /* 533C 80107B3C 6C9A528C */  lw         $s2, %lo(D_80109A6C)($v0)
    /* 5340 80107B40 00000000 */  nop
    /* 5344 80107B44 04005316 */  bne        $s2, $s3, .L80107B58
    /* 5348 80107B48 1180033C */   lui       $v1, %hi(D_80109A68)
    /* 534C 80107B4C 08000224 */  addiu      $v0, $zero, 0x8
    /* 5350 80107B50 64220408 */  j          .L80108990
    /* 5354 80107B54 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
  .L80107B58:
    /* 5358 80107B58 3700601A */  blez       $s3, .L80107C38
    /* 535C 80107B5C 40101300 */   sll       $v0, $s3, 1
    /* 5360 80107B60 21105100 */  addu       $v0, $v0, $s1
    /* 5364 80107B64 FEFF5094 */  lhu        $s0, -0x2($v0)
    /* 5368 80107B68 40101200 */  sll        $v0, $s2, 1
    /* 536C 80107B6C 21105100 */  addu       $v0, $v0, $s1
    /* 5370 80107B70 FEFF4694 */  lhu        $a2, -0x2($v0)
    /* 5374 80107B74 06000224 */  addiu      $v0, $zero, 0x6
    /* 5378 80107B78 26008216 */  bne        $s4, $v0, .L80107C14
    /* 537C 80107B7C 40101300 */   sll       $v0, $s3, 1
    /* 5380 80107B80 1180093C */  lui        $t1, %hi(vs_menuD_containerData)
    /* 5384 80107B84 FFFF0526 */  addiu      $a1, $s0, -0x1
    /* 5388 80107B88 80500500 */  sll        $t2, $a1, 2
    /* 538C 80107B8C FFFFC224 */  addiu      $v0, $a2, -0x1
    /* 5390 80107B90 8C9A238D */  lw         $v1, %lo(vs_menuD_containerData)($t1)
    /* 5394 80107B94 80380200 */  sll        $a3, $v0, 2
    /* 5398 80107B98 21406A00 */  addu       $t0, $v1, $t2
    /* 539C 80107B9C 21206700 */  addu       $a0, $v1, $a3
    /* 53A0 80107BA0 00380395 */  lhu        $v1, 0x3800($t0)
    /* 53A4 80107BA4 00388294 */  lhu        $v0, 0x3800($a0)
    /* 53A8 80107BA8 00000000 */  nop
    /* 53AC 80107BAC 19006214 */  bne        $v1, $v0, .L80107C14
    /* 53B0 80107BB0 40101300 */   sll       $v0, $s3, 1
    /* 53B4 80107BB4 02388290 */  lbu        $v0, 0x3802($a0)
    /* 53B8 80107BB8 02380391 */  lbu        $v1, 0x3802($t0)
    /* 53BC 80107BBC 00000000 */  nop
    /* 53C0 80107BC0 21104300 */  addu       $v0, $v0, $v1
    /* 53C4 80107BC4 023882A0 */  sb         $v0, 0x3802($a0)
    /* 53C8 80107BC8 8C9A268D */  lw         $a2, %lo(vs_menuD_containerData)($t1)
    /* 53CC 80107BCC 00000000 */  nop
    /* 53D0 80107BD0 2110C700 */  addu       $v0, $a2, $a3
    /* 53D4 80107BD4 02384490 */  lbu        $a0, 0x3802($v0)
    /* 53D8 80107BD8 00000000 */  nop
    /* 53DC 80107BDC 6500822C */  sltiu      $v0, $a0, 0x65
    /* 53E0 80107BE0 08004014 */  bnez       $v0, .L80107C04
    /* 53E4 80107BE4 2118CA00 */   addu      $v1, $a2, $t2
    /* 53E8 80107BE8 9CFF8224 */  addiu      $v0, $a0, -0x64
    /* 53EC 80107BEC 023862A0 */  sb         $v0, 0x3802($v1)
    /* 53F0 80107BF0 8C9A228D */  lw         $v0, %lo(vs_menuD_containerData)($t1)
    /* 53F4 80107BF4 64000324 */  addiu      $v1, $zero, 0x64
    /* 53F8 80107BF8 21104700 */  addu       $v0, $v0, $a3
    /* 53FC 80107BFC 0A1F0408 */  j          .L80107C28
    /* 5400 80107C00 023843A0 */   sb        $v1, 0x3802($v0)
  .L80107C04:
    /* 5404 80107C04 600B040C */  jal        _initContainerObject
    /* 5408 80107C08 06000424 */   addiu     $a0, $zero, 0x6
    /* 540C 80107C0C 0A1F0408 */  j          .L80107C28
    /* 5410 80107C10 00000000 */   nop
  .L80107C14:
    /* 5414 80107C14 21105100 */  addu       $v0, $v0, $s1
    /* 5418 80107C18 FEFF46A4 */  sh         $a2, -0x2($v0)
    /* 541C 80107C1C 40101200 */  sll        $v0, $s2, 1
    /* 5420 80107C20 21105100 */  addu       $v0, $v0, $s1
    /* 5424 80107C24 FEFF50A4 */  sh         $s0, -0x2($v0)
  .L80107C28:
    /* 5428 80107C28 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 542C 80107C2C 21200000 */   addu      $a0, $zero, $zero
    /* 5430 80107C30 BC210408 */  j          .L801086F0
    /* 5434 80107C34 1180033C */   lui       $v1, %hi(D_80109A68)
  .L80107C38:
    /* 5438 80107C38 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 543C 80107C3C 4D026212 */  beq        $s3, $v0, .L80108574
    /* 5440 80107C40 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 5444 80107C44 65220408 */  j          .L80108994
    /* 5448 80107C48 00000000 */   nop
    /* 544C 80107C4C 0214040C */  jal        func_80105008
    /* 5450 80107C50 21200000 */   addu      $a0, $zero, $zero
    /* 5454 80107C54 21984000 */  addu       $s3, $v0, $zero
    /* 5458 80107C58 4D036012 */  beqz       $s3, .L80108990
    /* 545C 80107C5C FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 5460 80107C60 4C036212 */  beq        $s3, $v0, .L80108994
    /* 5464 80107C64 21200000 */   addu      $a0, $zero, $zero
    /* 5468 80107C68 1180023C */  lui        $v0, %hi(D_80109A7B)
    /* 546C 80107C6C 01000324 */  addiu      $v1, $zero, 0x1
    /* 5470 80107C70 9223030C */  jal        vs_battle_getMenuItem
    /* 5474 80107C74 7B9A43A0 */   sb        $v1, %lo(D_80109A7B)($v0)
    /* 5478 80107C78 21184000 */  addu       $v1, $v0, $zero
    /* 547C 80107C7C 14006584 */  lh         $a1, 0x14($v1)
    /* 5480 80107C80 14006494 */  lhu        $a0, 0x14($v1)
    /* 5484 80107C84 B500A228 */  slti       $v0, $a1, 0xB5
    /* 5488 80107C88 09004014 */  bnez       $v0, .L80107CB0
    /* 548C 80107C8C CD00A228 */   slti      $v0, $a1, 0xCD
    /* 5490 80107C90 04004014 */  bnez       $v0, .L80107CA4
    /* 5494 80107C94 02000224 */   addiu     $v0, $zero, 0x2
    /* 5498 80107C98 E8FF8224 */  addiu      $v0, $a0, -0x18
    /* 549C 80107C9C 140062A4 */  sh         $v0, 0x14($v1)
    /* 54A0 80107CA0 02000224 */  addiu      $v0, $zero, 0x2
  .L80107CA4:
    /* 54A4 80107CA4 000062A0 */  sb         $v0, 0x0($v1)
    /* 54A8 80107CA8 B4000224 */  addiu      $v0, $zero, 0xB4
    /* 54AC 80107CAC 180062A4 */  sh         $v0, 0x18($v1)
  .L80107CB0:
    /* 54B0 80107CB0 A4210408 */  j          .L80108690
    /* 54B4 80107CB4 1180033C */   lui       $v1, %hi(D_80109A68)
    /* 54B8 80107CB8 10000524 */  addiu      $a1, $zero, 0x10
    /* 54BC 80107CBC 21800000 */  addu       $s0, $zero, $zero
    /* 54C0 80107CC0 33001224 */  addiu      $s2, $zero, 0x33
    /* 54C4 80107CC4 1180023C */  lui        $v0, %hi(D_80109A6C)
    /* 54C8 80107CC8 0F80033C */  lui        $v1, %hi(vs_battle_rowTypeBuf)
    /* 54CC 80107CCC 6C9A428C */  lw         $v0, %lo(D_80109A6C)($v0)
    /* 54D0 80107CD0 844E648C */  lw         $a0, %lo(vs_battle_rowTypeBuf)($v1)
    /* 54D4 80107CD4 40100200 */  sll        $v0, $v0, 1
    /* 54D8 80107CD8 21105100 */  addu       $v0, $v0, $s1
    /* 54DC 80107CDC FEFF4394 */  lhu        $v1, -0x2($v0)
    /* 54E0 80107CE0 1180023C */  lui        $v0, %hi(D_80109A7D)
    /* 54E4 80107CE4 7D9A40A0 */  sb         $zero, %lo(D_80109A7D)($v0)
    /* 54E8 80107CE8 0733030C */  jal        vs_battle_rMemzero
    /* 54EC 80107CEC FFFF7324 */   addiu     $s3, $v1, -0x1
    /* 54F0 80107CF0 03000224 */  addiu      $v0, $zero, 0x3
    /* 54F4 80107CF4 14008212 */  beq        $s4, $v0, .L80107D48
    /* 54F8 80107CF8 0400822A */   slti      $v0, $s4, 0x4
    /* 54FC 80107CFC 05004010 */  beqz       $v0, .L80107D14
    /* 5500 80107D00 04000224 */   addiu     $v0, $zero, 0x4
    /* 5504 80107D04 09008012 */  beqz       $s4, .L80107D2C
    /* 5508 80107D08 21208002 */   addu      $a0, $s4, $zero
    /* 550C 80107D0C 6E1F0408 */  j          .L80107DB8
    /* 5510 80107D10 1180113C */   lui       $s1, %hi(vs_menuD_containerData)
  .L80107D14:
    /* 5514 80107D14 15008212 */  beq        $s4, $v0, .L80107D6C
    /* 5518 80107D18 06000224 */   addiu     $v0, $zero, 0x6
    /* 551C 80107D1C 1C008212 */  beq        $s4, $v0, .L80107D90
    /* 5520 80107D20 21208002 */   addu      $a0, $s4, $zero
    /* 5524 80107D24 6E1F0408 */  j          .L80107DB8
    /* 5528 80107D28 1180113C */   lui       $s1, %hi(vs_menuD_containerData)
  .L80107D2C:
    /* 552C 80107D2C 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 5530 80107D30 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 5534 80107D34 40191300 */  sll        $v1, $s3, 5
    /* 5538 80107D38 21104300 */  addu       $v0, $v0, $v1
    /* 553C 80107D3C 03005090 */  lbu        $s0, 0x3($v0)
    /* 5540 80107D40 6C1F0408 */  j          .L80107DB0
    /* 5544 80107D44 4A001224 */   addiu     $s2, $zero, 0x4A
  .L80107D48:
    /* 5548 80107D48 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 554C 80107D4C 40181300 */  sll        $v1, $s3, 1
    /* 5550 80107D50 21187300 */  addu       $v1, $v1, $s3
    /* 5554 80107D54 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 5558 80107D58 00190300 */  sll        $v1, $v1, 4
    /* 555C 80107D5C 21104300 */  addu       $v0, $v0, $v1
    /* 5560 80107D60 01045090 */  lbu        $s0, 0x401($v0)
    /* 5564 80107D64 6C1F0408 */  j          .L80107DB0
    /* 5568 80107D68 4A001224 */   addiu     $s2, $zero, 0x4A
  .L80107D6C:
    /* 556C 80107D6C 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 5570 80107D70 80181300 */  sll        $v1, $s3, 2
    /* 5574 80107D74 21187300 */  addu       $v1, $v1, $s3
    /* 5578 80107D78 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 557C 80107D7C C0180300 */  sll        $v1, $v1, 3
    /* 5580 80107D80 21104300 */  addu       $v0, $v0, $v1
    /* 5584 80107D84 26195090 */  lbu        $s0, 0x1926($v0)
    /* 5588 80107D88 6C1F0408 */  j          .L80107DB0
    /* 558C 80107D8C 4A001224 */   addiu     $s2, $zero, 0x4A
  .L80107D90:
    /* 5590 80107D90 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 5594 80107D94 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 5598 80107D98 80181300 */  sll        $v1, $s3, 2
    /* 559C 80107D9C 21104300 */  addu       $v0, $v0, $v1
    /* 55A0 80107DA0 00384294 */  lhu        $v0, 0x3800($v0)
    /* 55A4 80107DA4 00000000 */  nop
    /* 55A8 80107DA8 CA01422C */  sltiu      $v0, $v0, 0x1CA
    /* 55AC 80107DAC 01005038 */  xori       $s0, $v0, 0x1
  .L80107DB0:
    /* 55B0 80107DB0 21208002 */  addu       $a0, $s4, $zero
    /* 55B4 80107DB4 1180113C */  lui        $s1, %hi(vs_menuD_containerData)
  .L80107DB8:
    /* 55B8 80107DB8 8C9A268E */  lw         $a2, %lo(vs_menuD_containerData)($s1)
    /* 55BC 80107DBC 270F040C */  jal        _getParentItemIndex
    /* 55C0 80107DC0 21286002 */   addu      $a1, $s3, $zero
    /* 55C4 80107DC4 21304000 */  addu       $a2, $v0, $zero
    /* 55C8 80107DC8 0E00C010 */  beqz       $a2, .L80107E04
    /* 55CC 80107DCC 08000524 */   addiu     $a1, $zero, 0x8
    /* 55D0 80107DD0 01001024 */  addiu      $s0, $zero, 0x1
    /* 55D4 80107DD4 1180043C */  lui        $a0, %hi(_menuText)
    /* 55D8 80107DD8 FFFFC224 */  addiu      $v0, $a2, -0x1
    /* 55DC 80107DDC 8C9A238E */  lw         $v1, %lo(vs_menuD_containerData)($s1)
    /* 55E0 80107DE0 40110200 */  sll        $v0, $v0, 5
    /* 55E4 80107DE4 21186200 */  addu       $v1, $v1, $v0
    /* 55E8 80107DE8 03006290 */  lbu        $v0, 0x3($v1)
    /* 55EC 80107DEC 00000000 */  nop
    /* 55F0 80107DF0 02004014 */  bnez       $v0, .L80107DFC
    /* 55F4 80107DF4 2C958424 */   addiu     $a0, $a0, %lo(_menuText)
    /* 55F8 80107DF8 0A000524 */  addiu      $a1, $zero, 0xA
  .L80107DFC:
    /* 55FC 80107DFC 2110A400 */  addu       $v0, $a1, $a0
    /* 5600 80107E00 00005294 */  lhu        $s2, 0x0($v0)
  .L80107E04:
    /* 5604 80107E04 21208002 */  addu       $a0, $s4, $zero
    /* 5608 80107E08 1180113C */  lui        $s1, %hi(vs_menuD_containerData)
    /* 560C 80107E0C 8C9A268E */  lw         $a2, %lo(vs_menuD_containerData)($s1)
    /* 5610 80107E10 450F040C */  jal        _getSetShieldIndex
    /* 5614 80107E14 21286002 */   addu      $a1, $s3, $zero
    /* 5618 80107E18 21304000 */  addu       $a2, $v0, $zero
    /* 561C 80107E1C 1000C010 */  beqz       $a2, .L80107E60
    /* 5620 80107E20 08000524 */   addiu     $a1, $zero, 0x8
    /* 5624 80107E24 01001024 */  addiu      $s0, $zero, 0x1
    /* 5628 80107E28 1180043C */  lui        $a0, %hi(_menuText)
    /* 562C 80107E2C FFFFC324 */  addiu      $v1, $a2, -0x1
    /* 5630 80107E30 04100302 */  sllv       $v0, $v1, $s0
    /* 5634 80107E34 21104300 */  addu       $v0, $v0, $v1
    /* 5638 80107E38 8C9A238E */  lw         $v1, %lo(vs_menuD_containerData)($s1)
    /* 563C 80107E3C 00110200 */  sll        $v0, $v0, 4
    /* 5640 80107E40 21186200 */  addu       $v1, $v1, $v0
    /* 5644 80107E44 01046290 */  lbu        $v0, 0x401($v1)
    /* 5648 80107E48 00000000 */  nop
    /* 564C 80107E4C 02004014 */  bnez       $v0, .L80107E58
    /* 5650 80107E50 2C958424 */   addiu     $a0, $a0, %lo(_menuText)
    /* 5654 80107E54 0A000524 */  addiu      $a1, $zero, 0xA
  .L80107E58:
    /* 5658 80107E58 2110A400 */  addu       $v0, $a1, $a0
    /* 565C 80107E5C 00005294 */  lhu        $s2, 0x0($v0)
  .L80107E60:
    /* 5660 80107E60 05000012 */  beqz       $s0, .L80107E78
    /* 5664 80107E64 21300002 */   addu      $a2, $s0, $zero
    /* 5668 80107E68 40181200 */  sll        $v1, $s2, 1
    /* 566C 80107E6C 1180023C */  lui        $v0, %hi(_menuText)
    /* 5670 80107E70 EE1F0408 */  j          .L80107FB8
    /* 5674 80107E74 2C954224 */   addiu     $v0, $v0, %lo(_menuText)
  .L80107E78:
    /* 5678 80107E78 06000224 */  addiu      $v0, $zero, 0x6
    /* 567C 80107E7C 43008216 */  bne        $s4, $v0, .L80107F8C
    /* 5680 80107E80 21208002 */   addu      $a0, $s4, $zero
    /* 5684 80107E84 21800000 */  addu       $s0, $zero, $zero
    /* 5688 80107E88 21900002 */  addu       $s2, $s0, $zero
    /* 568C 80107E8C 1080153C */  lui        $s5, %hi(vs_menu_inventoryStorage)
    /* 5690 80107E90 B0871134 */  ori        $s1, $zero, 0x87B0
    /* 5694 80107E94 21204002 */  addu       $a0, $s2, $zero
  .L80107E98:
    /* 5698 80107E98 5C24A58E */  lw         $a1, %lo(vs_menu_inventoryStorage)($s5)
    /* 569C 80107E9C 01005226 */  addiu      $s2, $s2, 0x1
    /* 56A0 80107EA0 1C0C040C */  jal        _countContainerItems
    /* 56A4 80107EA4 2128B100 */   addu      $a1, $a1, $s1
    /* 56A8 80107EA8 21800202 */  addu       $s0, $s0, $v0
    /* 56AC 80107EAC 0700422A */  slti       $v0, $s2, 0x7
    /* 56B0 80107EB0 F9FF4014 */  bnez       $v0, .L80107E98
    /* 56B4 80107EB4 21204002 */   addu      $a0, $s2, $zero
    /* 56B8 80107EB8 680C040C */  jal        func_801031A0
    /* 56BC 80107EBC 00000000 */   nop
    /* 56C0 80107EC0 06000424 */  addiu      $a0, $zero, 0x6
    /* 56C4 80107EC4 21306002 */  addu       $a2, $s3, $zero
    /* 56C8 80107EC8 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 56CC 80107ECC 1180033C */  lui        $v1, %hi(vs_menuD_containerData)
    /* 56D0 80107ED0 5C24458C */  lw         $a1, %lo(vs_menu_inventoryStorage)($v0)
    /* 56D4 80107ED4 8C9A678C */  lw         $a3, %lo(vs_menuD_containerData)($v1)
    /* 56D8 80107ED8 AB0C040C */  jal        _copyContainerItem
    /* 56DC 80107EDC B04BA524 */   addiu     $a1, $a1, 0x4BB0
    /* 56E0 80107EE0 1180033C */  lui        $v1, %hi(D_80109A7A)
    /* 56E4 80107EE4 7A9A6390 */  lbu        $v1, %lo(D_80109A7A)($v1)
    /* 56E8 80107EE8 00000000 */  nop
    /* 56EC 80107EEC 05006014 */  bnez       $v1, .L80107F04
    /* 56F0 80107EF0 21304000 */   addu      $a2, $v0, $zero
    /* 56F4 80107EF4 4100C228 */  slti       $v0, $a2, 0x41
    /* 56F8 80107EF8 02004014 */  bnez       $v0, .L80107F04
    /* 56FC 80107EFC 00000000 */   nop
    /* 5700 80107F00 21300000 */  addu       $a2, $zero, $zero
  .L80107F04:
    /* 5704 80107F04 1C00C010 */  beqz       $a2, .L80107F78
    /* 5708 80107F08 AB001224 */   addiu     $s2, $zero, 0xAB
    /* 570C 80107F0C 40000224 */  addiu      $v0, $zero, 0x40
    /* 5710 80107F10 1A000216 */  bne        $s0, $v0, .L80107F7C
    /* 5714 80107F14 0100C62C */   sltiu     $a2, $a2, 0x1
    /* 5718 80107F18 21300000 */  addu       $a2, $zero, $zero
    /* 571C 80107F1C 00800834 */  ori        $t0, $zero, 0x8000
    /* 5720 80107F20 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 5724 80107F24 5C24458C */  lw         $a1, %lo(vs_menu_inventoryStorage)($v0)
    /* 5728 80107F28 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 572C 80107F2C 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 5730 80107F30 80181300 */  sll        $v1, $s3, 2
    /* 5734 80107F34 21104300 */  addu       $v0, $v0, $v1
    /* 5738 80107F38 02384490 */  lbu        $a0, 0x3802($v0)
    /* 573C 80107F3C 00384794 */  lhu        $a3, 0x3800($v0)
  .L80107F40:
    /* 5740 80107F40 2118A800 */  addu       $v1, $a1, $t0
    /* 5744 80107F44 B03F6294 */  lhu        $v0, 0x3FB0($v1)
    /* 5748 80107F48 00000000 */  nop
    /* 574C 80107F4C 04004714 */  bne        $v0, $a3, .L80107F60
    /* 5750 80107F50 9CFF8224 */   addiu     $v0, $a0, -0x64
    /* 5754 80107F54 B23F6390 */  lbu        $v1, 0x3FB2($v1)
    /* 5758 80107F58 00000000 */  nop
    /* 575C 80107F5C 21204300 */  addu       $a0, $v0, $v1
  .L80107F60:
    /* 5760 80107F60 0100C624 */  addiu      $a2, $a2, 0x1
    /* 5764 80107F64 0001C228 */  slti       $v0, $a2, 0x100
    /* 5768 80107F68 F5FF4014 */  bnez       $v0, .L80107F40
    /* 576C 80107F6C 0400A524 */   addiu     $a1, $a1, 0x4
    /* 5770 80107F70 01008628 */  slti       $a2, $a0, 0x1
    /* 5774 80107F74 82001224 */  addiu      $s2, $zero, 0x82
  .L80107F78:
    /* 5778 80107F78 0100C62C */  sltiu      $a2, $a2, 0x1
  .L80107F7C:
    /* 577C 80107F7C 40181200 */  sll        $v1, $s2, 1
    /* 5780 80107F80 1180023C */  lui        $v0, %hi(_menuText)
    /* 5784 80107F84 EE1F0408 */  j          .L80107FB8
    /* 5788 80107F88 2C954224 */   addiu     $v0, $v0, %lo(_menuText)
  .L80107F8C:
    /* 578C 80107F8C E119040C */  jal        func_80106784
    /* 5790 80107F90 21286002 */   addu      $a1, $s3, $zero
    /* 5794 80107F94 21304000 */  addu       $a2, $v0, $zero
    /* 5798 80107F98 1180023C */  lui        $v0, %hi(_menuText)
    /* 579C 80107F9C 2C954224 */  addiu      $v0, $v0, %lo(_menuText)
    /* 57A0 80107FA0 0500C324 */  addiu      $v1, $a2, 0x5
    /* 57A4 80107FA4 40180300 */  sll        $v1, $v1, 1
    /* 57A8 80107FA8 21186200 */  addu       $v1, $v1, $v0
    /* 57AC 80107FAC 00006394 */  lhu        $v1, 0x0($v1)
    /* 57B0 80107FB0 00000000 */  nop
    /* 57B4 80107FB4 40180300 */  sll        $v1, $v1, 1
  .L80107FB8:
    /* 57B8 80107FB8 21186200 */  addu       $v1, $v1, $v0
    /* 57BC 80107FBC 1400A3AF */  sw         $v1, 0x14($sp)
    /* 57C0 80107FC0 1180033C */  lui        $v1, %hi(_menuText)
    /* 57C4 80107FC4 1180023C */  lui        $v0, %hi(D_80109A7A)
    /* 57C8 80107FC8 7A9A4290 */  lbu        $v0, %lo(D_80109A7A)($v0)
    /* 57CC 80107FCC 2C956324 */  addiu      $v1, $v1, %lo(_menuText)
    /* 57D0 80107FD0 40200200 */  sll        $a0, $v0, 1
    /* 57D4 80107FD4 1F008224 */  addiu      $v0, $a0, 0x1F
    /* 57D8 80107FD8 40100200 */  sll        $v0, $v0, 1
    /* 57DC 80107FDC 21104300 */  addu       $v0, $v0, $v1
    /* 57E0 80107FE0 00004294 */  lhu        $v0, 0x0($v0)
    /* 57E4 80107FE4 00000000 */  nop
    /* 57E8 80107FE8 40100200 */  sll        $v0, $v0, 1
    /* 57EC 80107FEC 21104300 */  addu       $v0, $v0, $v1
    /* 57F0 80107FF0 0600C010 */  beqz       $a2, .L8010800C
    /* 57F4 80107FF4 1000A2AF */   sw        $v0, 0x10($sp)
    /* 57F8 80107FF8 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 57FC 80107FFC 844E438C */  lw         $v1, %lo(vs_battle_rowTypeBuf)($v0)
    /* 5800 80108000 01000224 */  addiu      $v0, $zero, 0x1
    /* 5804 80108004 0B200408 */  j          .L8010802C
    /* 5808 80108008 000062AC */   sw        $v0, 0x0($v1)
  .L8010800C:
    /* 580C 8010800C 20008224 */  addiu      $v0, $a0, 0x20
    /* 5810 80108010 40100200 */  sll        $v0, $v0, 1
    /* 5814 80108014 21104300 */  addu       $v0, $v0, $v1
    /* 5818 80108018 00004294 */  lhu        $v0, 0x0($v0)
    /* 581C 8010801C 00000000 */  nop
    /* 5820 80108020 40100200 */  sll        $v0, $v0, 1
    /* 5824 80108024 21104300 */  addu       $v0, $v0, $v1
    /* 5828 80108028 1400A2AF */  sw         $v0, 0x14($sp)
  .L8010802C:
    /* 582C 8010802C 1180033C */  lui        $v1, %hi(D_80109A61)
    /* 5830 80108030 01000224 */  addiu      $v0, $zero, 0x1
    /* 5834 80108034 619A62A0 */  sb         $v0, %lo(D_80109A61)($v1)
    /* 5838 80108038 FFFF8226 */  addiu      $v0, $s4, -0x1
    /* 583C 8010803C 0200422C */  sltiu      $v0, $v0, 0x2
    /* 5840 80108040 04004014 */  bnez       $v0, .L80108054
    /* 5844 80108044 01001224 */   addiu     $s2, $zero, 0x1
    /* 5848 80108048 05000224 */  addiu      $v0, $zero, 0x5
    /* 584C 8010804C 1F008216 */  bne        $s4, $v0, .L801080CC
    /* 5850 80108050 21800000 */   addu      $s0, $zero, $zero
  .L80108054:
    /* 5854 80108054 21208002 */  addu       $a0, $s4, $zero
    /* 5858 80108058 21286002 */  addu       $a1, $s3, $zero
    /* 585C 8010805C 1080113C */  lui        $s1, %hi(vs_mainMenu_itemHelp)
    /* 5860 80108060 1180103C */  lui        $s0, %hi(vs_menuD_containerData)
    /* 5864 80108064 4025228E */  lw         $v0, %lo(vs_mainMenu_itemHelp)($s1)
    /* 5868 80108068 8C9A068E */  lw         $a2, %lo(vs_menuD_containerData)($s0)
    /* 586C 8010806C 4E6A4324 */  addiu      $v1, $v0, 0x6A4E
    /* 5870 80108070 586A4224 */  addiu      $v0, $v0, 0x6A58
    /* 5874 80108074 1800A3AF */  sw         $v1, 0x18($sp)
    /* 5878 80108078 270F040C */  jal        _getParentItemIndex
    /* 587C 8010807C 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 5880 80108080 0B004014 */  bnez       $v0, .L801080B0
    /* 5884 80108084 21208002 */   addu      $a0, $s4, $zero
    /* 5888 80108088 8C9A068E */  lw         $a2, %lo(vs_menuD_containerData)($s0)
    /* 588C 8010808C 450F040C */  jal        _getSetShieldIndex
    /* 5890 80108090 21286002 */   addu      $a1, $s3, $zero
    /* 5894 80108094 06004014 */  bnez       $v0, .L801080B0
    /* 5898 80108098 0F80023C */   lui       $v0, %hi(vs_battle_rowTypeBuf)
    /* 589C 8010809C 4025238E */  lw         $v1, %lo(vs_mainMenu_itemHelp)($s1)
    /* 58A0 801080A0 844E428C */  lw         $v0, %lo(vs_battle_rowTypeBuf)($v0)
    /* 58A4 801080A4 646B6324 */  addiu      $v1, $v1, 0x6B64
    /* 58A8 801080A8 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* 58AC 801080AC 040052AC */  sw         $s2, 0x4($v0)
  .L801080B0:
    /* 58B0 801080B0 01005226 */  addiu      $s2, $s2, 0x1
    /* 58B4 801080B4 1180023C */  lui        $v0, %hi(D_80109A60)
    /* 58B8 801080B8 609A4224 */  addiu      $v0, $v0, %lo(D_80109A60)
    /* 58BC 801080BC 21104202 */  addu       $v0, $s2, $v0
    /* 58C0 801080C0 02000324 */  addiu      $v1, $zero, 0x2
    /* 58C4 801080C4 000043A0 */  sb         $v1, 0x0($v0)
    /* 58C8 801080C8 21800000 */  addu       $s0, $zero, $zero
  .L801080CC:
    /* 58CC 801080CC C0181200 */  sll        $v1, $s2, 3
    /* 58D0 801080D0 1000A527 */  addiu      $a1, $sp, 0x10
    /* 58D4 801080D4 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 58D8 801080D8 4025448C */  lw         $a0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 58DC 801080DC 2118A300 */  addu       $v1, $a1, $v1
    /* 58E0 801080E0 946A8224 */  addiu      $v0, $a0, 0x6A94
    /* 58E4 801080E4 000062AC */  sw         $v0, 0x0($v1)
    /* 58E8 801080E8 C0101200 */  sll        $v0, $s2, 3
    /* 58EC 801080EC 04004234 */  ori        $v0, $v0, 0x4
    /* 58F0 801080F0 2128A200 */  addu       $a1, $a1, $v0
    /* 58F4 801080F4 9E6A8424 */  addiu      $a0, $a0, 0x6A9E
    /* 58F8 801080F8 03000224 */  addiu      $v0, $zero, 0x3
    /* 58FC 801080FC 15008212 */  beq        $s4, $v0, .L80108154
    /* 5900 80108100 0000A4AC */   sw        $a0, 0x0($a1)
    /* 5904 80108104 0400822A */  slti       $v0, $s4, 0x4
    /* 5908 80108108 05004010 */  beqz       $v0, .L80108120
    /* 590C 8010810C 04000224 */   addiu     $v0, $zero, 0x4
    /* 5910 80108110 09008012 */  beqz       $s4, .L80108138
    /* 5914 80108114 21208002 */   addu      $a0, $s4, $zero
    /* 5918 80108118 73200408 */  j          .L801081CC
    /* 591C 8010811C 1180113C */   lui       $s1, %hi(vs_menuD_containerData)
  .L80108120:
    /* 5920 80108120 15008212 */  beq        $s4, $v0, .L80108178
    /* 5924 80108124 06000224 */   addiu     $v0, $zero, 0x6
    /* 5928 80108128 1C008212 */  beq        $s4, $v0, .L8010819C
    /* 592C 8010812C 21208002 */   addu      $a0, $s4, $zero
    /* 5930 80108130 73200408 */  j          .L801081CC
    /* 5934 80108134 1180113C */   lui       $s1, %hi(vs_menuD_containerData)
  .L80108138:
    /* 5938 80108138 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 593C 8010813C 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 5940 80108140 40191300 */  sll        $v1, $s3, 5
    /* 5944 80108144 21104300 */  addu       $v0, $v0, $v1
    /* 5948 80108148 03004290 */  lbu        $v0, 0x3($v0)
    /* 594C 8010814C 71200408 */  j          .L801081C4
    /* 5950 80108150 2B800200 */   sltu      $s0, $zero, $v0
  .L80108154:
    /* 5954 80108154 1180033C */  lui        $v1, %hi(vs_menuD_containerData)
    /* 5958 80108158 40101300 */  sll        $v0, $s3, 1
    /* 595C 8010815C 21105300 */  addu       $v0, $v0, $s3
    /* 5960 80108160 8C9A638C */  lw         $v1, %lo(vs_menuD_containerData)($v1)
    /* 5964 80108164 00110200 */  sll        $v0, $v0, 4
    /* 5968 80108168 21186200 */  addu       $v1, $v1, $v0
    /* 596C 8010816C 01046290 */  lbu        $v0, 0x401($v1)
    /* 5970 80108170 71200408 */  j          .L801081C4
    /* 5974 80108174 2B800200 */   sltu      $s0, $zero, $v0
  .L80108178:
    /* 5978 80108178 1180033C */  lui        $v1, %hi(vs_menuD_containerData)
    /* 597C 8010817C 80101300 */  sll        $v0, $s3, 2
    /* 5980 80108180 21105300 */  addu       $v0, $v0, $s3
    /* 5984 80108184 8C9A638C */  lw         $v1, %lo(vs_menuD_containerData)($v1)
    /* 5988 80108188 C0100200 */  sll        $v0, $v0, 3
    /* 598C 8010818C 21186200 */  addu       $v1, $v1, $v0
    /* 5990 80108190 26196290 */  lbu        $v0, 0x1926($v1)
    /* 5994 80108194 71200408 */  j          .L801081C4
    /* 5998 80108198 2B800200 */   sltu      $s0, $zero, $v0
  .L8010819C:
    /* 599C 8010819C 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 59A0 801081A0 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 59A4 801081A4 80181300 */  sll        $v1, $s3, 2
    /* 59A8 801081A8 21104300 */  addu       $v0, $v0, $v1
    /* 59AC 801081AC 00384294 */  lhu        $v0, 0x3800($v0)
    /* 59B0 801081B0 00000000 */  nop
    /* 59B4 801081B4 CA01422C */  sltiu      $v0, $v0, 0x1CA
    /* 59B8 801081B8 04004014 */  bnez       $v0, .L801081CC
    /* 59BC 801081BC 1180113C */   lui       $s1, %hi(vs_menuD_containerData)
    /* 59C0 801081C0 03001024 */  addiu      $s0, $zero, 0x3
  .L801081C4:
    /* 59C4 801081C4 21208002 */  addu       $a0, $s4, $zero
    /* 59C8 801081C8 1180113C */  lui        $s1, %hi(vs_menuD_containerData)
  .L801081CC:
    /* 59CC 801081CC 8C9A268E */  lw         $a2, %lo(vs_menuD_containerData)($s1)
    /* 59D0 801081D0 270F040C */  jal        _getParentItemIndex
    /* 59D4 801081D4 21286002 */   addu      $a1, $s3, $zero
    /* 59D8 801081D8 21304000 */  addu       $a2, $v0, $zero
    /* 59DC 801081DC 0900C010 */  beqz       $a2, .L80108204
    /* 59E0 801081E0 FFFFC224 */   addiu     $v0, $a2, -0x1
    /* 59E4 801081E4 8C9A238E */  lw         $v1, %lo(vs_menuD_containerData)($s1)
    /* 59E8 801081E8 40110200 */  sll        $v0, $v0, 5
    /* 59EC 801081EC 21186200 */  addu       $v1, $v1, $v0
    /* 59F0 801081F0 03006290 */  lbu        $v0, 0x3($v1)
    /* 59F4 801081F4 00000000 */  nop
    /* 59F8 801081F8 02004014 */  bnez       $v0, .L80108204
    /* 59FC 801081FC 01001024 */   addiu     $s0, $zero, 0x1
    /* 5A00 80108200 02001024 */  addiu      $s0, $zero, 0x2
  .L80108204:
    /* 5A04 80108204 21208002 */  addu       $a0, $s4, $zero
    /* 5A08 80108208 1180113C */  lui        $s1, %hi(vs_menuD_containerData)
    /* 5A0C 8010820C 8C9A268E */  lw         $a2, %lo(vs_menuD_containerData)($s1)
    /* 5A10 80108210 450F040C */  jal        _getSetShieldIndex
    /* 5A14 80108214 21286002 */   addu      $a1, $s3, $zero
    /* 5A18 80108218 21304000 */  addu       $a2, $v0, $zero
    /* 5A1C 8010821C 0B00C010 */  beqz       $a2, .L8010824C
    /* 5A20 80108220 FFFFC324 */   addiu     $v1, $a2, -0x1
    /* 5A24 80108224 40100300 */  sll        $v0, $v1, 1
    /* 5A28 80108228 21104300 */  addu       $v0, $v0, $v1
    /* 5A2C 8010822C 8C9A238E */  lw         $v1, %lo(vs_menuD_containerData)($s1)
    /* 5A30 80108230 00110200 */  sll        $v0, $v0, 4
    /* 5A34 80108234 21186200 */  addu       $v1, $v1, $v0
    /* 5A38 80108238 01046290 */  lbu        $v0, 0x401($v1)
    /* 5A3C 8010823C 00000000 */  nop
    /* 5A40 80108240 02004014 */  bnez       $v0, .L8010824C
    /* 5A44 80108244 01001024 */   addiu     $s0, $zero, 0x1
    /* 5A48 80108248 02001024 */  addiu      $s0, $zero, 0x2
  .L8010824C:
    /* 5A4C 8010824C 0C000012 */  beqz       $s0, .L80108280
    /* 5A50 80108250 40281000 */   sll       $a1, $s0, 1
    /* 5A54 80108254 01001024 */  addiu      $s0, $zero, 0x1
    /* 5A58 80108258 C0201200 */  sll        $a0, $s2, 3
    /* 5A5C 8010825C 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 5A60 80108260 4025438C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v0)
    /* 5A64 80108264 04008434 */  ori        $a0, $a0, 0x4
    /* 5A68 80108268 2128A300 */  addu       $a1, $a1, $v1
    /* 5A6C 8010826C 2E05A294 */  lhu        $v0, 0x52E($a1)
    /* 5A70 80108270 2120A403 */  addu       $a0, $sp, $a0
    /* 5A74 80108274 04100202 */  sllv       $v0, $v0, $s0
    /* 5A78 80108278 21186200 */  addu       $v1, $v1, $v0
    /* 5A7C 8010827C 100083AC */  sw         $v1, 0x10($a0)
  .L80108280:
    /* 5A80 80108280 0F80073C */  lui        $a3, %hi(vs_battle_rowTypeBuf)
    /* 5A84 80108284 80101200 */  sll        $v0, $s2, 2
    /* 5A88 80108288 844EE38C */  lw         $v1, %lo(vs_battle_rowTypeBuf)($a3)
    /* 5A8C 8010828C 01005226 */  addiu      $s2, $s2, 0x1
    /* 5A90 80108290 21104300 */  addu       $v0, $v0, $v1
    /* 5A94 80108294 000050AC */  sw         $s0, 0x0($v0)
    /* 5A98 80108298 1180023C */  lui        $v0, %hi(D_80109A60)
    /* 5A9C 8010829C 609A4624 */  addiu      $a2, $v0, %lo(D_80109A60)
    /* 5AA0 801082A0 21184602 */  addu       $v1, $s2, $a2
    /* 5AA4 801082A4 03000224 */  addiu      $v0, $zero, 0x3
    /* 5AA8 801082A8 000062A0 */  sb         $v0, 0x0($v1)
    /* 5AAC 801082AC 06000224 */  addiu      $v0, $zero, 0x6
    /* 5AB0 801082B0 21008216 */  bne        $s4, $v0, .L80108338
    /* 5AB4 801082B4 C0401200 */   sll       $t0, $s2, 3
    /* 5AB8 801082B8 C0181200 */  sll        $v1, $s2, 3
    /* 5ABC 801082BC 1000A427 */  addiu      $a0, $sp, 0x10
    /* 5AC0 801082C0 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 5AC4 801082C4 4025458C */  lw         $a1, %lo(vs_mainMenu_itemHelp)($v0)
    /* 5AC8 801082C8 21188300 */  addu       $v1, $a0, $v1
    /* 5ACC 801082CC DA6AA224 */  addiu      $v0, $a1, 0x6ADA
    /* 5AD0 801082D0 000062AC */  sw         $v0, 0x0($v1)
    /* 5AD4 801082D4 C0101200 */  sll        $v0, $s2, 3
    /* 5AD8 801082D8 04004234 */  ori        $v0, $v0, 0x4
    /* 5ADC 801082DC 21208200 */  addu       $a0, $a0, $v0
    /* 5AE0 801082E0 E86AA224 */  addiu      $v0, $a1, 0x6AE8
    /* 5AE4 801082E4 000082AC */  sw         $v0, 0x0($a0)
    /* 5AE8 801082E8 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 5AEC 801082EC 8C9A428C */  lw         $v0, %lo(vs_menuD_containerData)($v0)
    /* 5AF0 801082F0 80181300 */  sll        $v1, $s3, 2
    /* 5AF4 801082F4 21104300 */  addu       $v0, $v0, $v1
    /* 5AF8 801082F8 00384294 */  lhu        $v0, 0x3800($v0)
    /* 5AFC 801082FC 00000000 */  nop
    /* 5B00 80108300 CA01422C */  sltiu      $v0, $v0, 0x1CA
    /* 5B04 80108304 07004014 */  bnez       $v0, .L80108324
    /* 5B08 80108308 1C6AA224 */   addiu     $v0, $a1, 0x6A1C
    /* 5B0C 8010830C 844EE38C */  lw         $v1, %lo(vs_battle_rowTypeBuf)($a3)
    /* 5B10 80108310 000082AC */  sw         $v0, 0x0($a0)
    /* 5B14 80108314 80101200 */  sll        $v0, $s2, 2
    /* 5B18 80108318 21104300 */  addu       $v0, $v0, $v1
    /* 5B1C 8010831C 01000324 */  addiu      $v1, $zero, 0x1
    /* 5B20 80108320 000043AC */  sw         $v1, 0x0($v0)
  .L80108324:
    /* 5B24 80108324 01005226 */  addiu      $s2, $s2, 0x1
    /* 5B28 80108328 21184602 */  addu       $v1, $s2, $a2
    /* 5B2C 8010832C 04000224 */  addiu      $v0, $zero, 0x4
    /* 5B30 80108330 000062A0 */  sb         $v0, 0x0($v1)
    /* 5B34 80108334 C0401200 */  sll        $t0, $s2, 3
  .L80108338:
    /* 5B38 80108338 21380001 */  addu       $a3, $t0, $zero
    /* 5B3C 8010833C 01005226 */  addiu      $s2, $s2, 0x1
    /* 5B40 80108340 21204002 */  addu       $a0, $s2, $zero
    /* 5B44 80108344 1000A627 */  addiu      $a2, $sp, 0x10
    /* 5B48 80108348 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 5B4C 8010834C 2140C800 */  addu       $t0, $a2, $t0
    /* 5B50 80108350 0400E734 */  ori        $a3, $a3, 0x4
    /* 5B54 80108354 4025438C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v0)
    /* 5B58 80108358 2138C700 */  addu       $a3, $a2, $a3
    /* 5B5C 8010835C 0C6B6224 */  addiu      $v0, $v1, 0x6B0C
    /* 5B60 80108360 146B6324 */  addiu      $v1, $v1, 0x6B14
    /* 5B64 80108364 000002AD */  sw         $v0, 0x0($t0)
    /* 5B68 80108368 1180023C */  lui        $v0, %hi(D_80109A60)
    /* 5B6C 8010836C 609A4224 */  addiu      $v0, $v0, %lo(D_80109A60)
    /* 5B70 80108370 0000E3AC */  sw         $v1, 0x0($a3)
    /* 5B74 80108374 21188200 */  addu       $v1, $a0, $v0
    /* 5B78 80108378 05000224 */  addiu      $v0, $zero, 0x5
    /* 5B7C 8010837C 000062A0 */  sb         $v0, 0x0($v1)
    /* 5B80 80108380 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 5B84 80108384 844E478C */  lw         $a3, %lo(vs_battle_rowTypeBuf)($v0)
    /* 5B88 80108388 3BFC030C */  jal        vs_mainMenu_initSortUi
    /* 5B8C 8010838C 59008526 */   addiu     $a1, $s4, 0x59
    /* 5B90 80108390 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5B94 80108394 09000224 */  addiu      $v0, $zero, 0x9
    /* 5B98 80108398 64220408 */  j          .L80108990
    /* 5B9C 8010839C 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
    /* 5BA0 801083A0 D2FC030C */  jal        func_800FF348
    /* 5BA4 801083A4 00000000 */   nop
    /* 5BA8 801083A8 1080033C */  lui        $v1, %hi(D_801022C4)
    /* 5BAC 801083AC C4226590 */  lbu        $a1, %lo(D_801022C4)($v1)
    /* 5BB0 801083B0 79FE030C */  jal        vs_mainMenu_printInformation
    /* 5BB4 801083B4 21204000 */   addu      $a0, $v0, $zero
    /* 5BB8 801083B8 0FFD030C */  jal        vs_mainMenu_processItemActionMenu
    /* 5BBC 801083BC 00000000 */   nop
    /* 5BC0 801083C0 D8FC030C */  jal        vs_mainMenu_getSelectedItemAction
    /* 5BC4 801083C4 00000000 */   nop
    /* 5BC8 801083C8 01005324 */  addiu      $s3, $v0, 0x1
    /* 5BCC 801083CC 71016012 */  beqz       $s3, .L80108994
    /* 5BD0 801083D0 21100000 */   addu      $v0, $zero, $zero
    /* 5BD4 801083D4 15EA030C */  jal        func_800FA854
    /* 5BD8 801083D8 28000424 */   addiu     $a0, $zero, 0x28
    /* 5BDC 801083DC 5C00601A */  blez       $s3, .L80108550
    /* 5BE0 801083E0 00000000 */   nop
    /* 5BE4 801083E4 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 5BE8 801083E8 00000000 */   nop
    /* 5BEC 801083EC 1180023C */  lui        $v0, %hi(D_80109A60)
    /* 5BF0 801083F0 609A4224 */  addiu      $v0, $v0, %lo(D_80109A60)
    /* 5BF4 801083F4 21106202 */  addu       $v0, $s3, $v0
    /* 5BF8 801083F8 00004290 */  lbu        $v0, 0x0($v0)
    /* 5BFC 801083FC 00000000 */  nop
    /* 5C00 80108400 FFFF4324 */  addiu      $v1, $v0, -0x1
    /* 5C04 80108404 0500622C */  sltiu      $v0, $v1, 0x5
    /* 5C08 80108408 61014010 */  beqz       $v0, .L80108990
    /* 5C0C 8010840C 1080023C */   lui       $v0, %hi(jtbl_801029E8)
    /* 5C10 80108410 E8294224 */  addiu      $v0, $v0, %lo(jtbl_801029E8)
    /* 5C14 80108414 80180300 */  sll        $v1, $v1, 2
    /* 5C18 80108418 21186200 */  addu       $v1, $v1, $v0
    /* 5C1C 8010841C 0000628C */  lw         $v0, 0x0($v1)
    /* 5C20 80108420 00000000 */  nop
    /* 5C24 80108424 08004000 */  jr         $v0
    /* 5C28 80108428 00000000 */   nop
    /* 5C2C 8010842C F2FE030C */  jal        func_800FFBC8
    /* 5C30 80108430 00000000 */   nop
    /* 5C34 80108434 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 5C38 80108438 8C9A458C */  lw         $a1, %lo(vs_menuD_containerData)($v0)
    /* 5C3C 8010843C 250B040C */  jal        _getContainerIndicesOffset
    /* 5C40 80108440 21208002 */   addu      $a0, $s4, $zero
    /* 5C44 80108444 1180033C */  lui        $v1, %hi(D_80109A6C)
    /* 5C48 80108448 6C9A638C */  lw         $v1, %lo(D_80109A6C)($v1)
    /* 5C4C 8010844C 00000000 */  nop
    /* 5C50 80108450 40180300 */  sll        $v1, $v1, 1
    /* 5C54 80108454 21186200 */  addu       $v1, $v1, $v0
    /* 5C58 80108458 FEFF6594 */  lhu        $a1, -0x2($v1)
    /* 5C5C 8010845C 21208002 */  addu       $a0, $s4, $zero
    /* 5C60 80108460 521A040C */  jal        func_80106948
    /* 5C64 80108464 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 5C68 80108468 0A1F0408 */  j          .L80107C28
    /* 5C6C 8010846C 00000000 */   nop
    /* 5C70 80108470 F2FE030C */  jal        func_800FFBC8
    /* 5C74 80108474 00000000 */   nop
    /* 5C78 80108478 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 5C7C 8010847C 21200000 */   addu      $a0, $zero, $zero
    /* 5C80 80108480 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5C84 80108484 0A000224 */  addiu      $v0, $zero, 0xA
    /* 5C88 80108488 64220408 */  j          .L80108990
    /* 5C8C 8010848C 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
    /* 5C90 80108490 1180023C */  lui        $v0, %hi(D_80109A6C)
    /* 5C94 80108494 6C9A428C */  lw         $v0, %lo(D_80109A6C)($v0)
    /* 5C98 80108498 00000000 */  nop
    /* 5C9C 8010849C 40100200 */  sll        $v0, $v0, 1
    /* 5CA0 801084A0 21105100 */  addu       $v0, $v0, $s1
    /* 5CA4 801084A4 FEFF4494 */  lhu        $a0, -0x2($v0)
    /* 5CA8 801084A8 00131400 */  sll        $v0, $s4, 12
    /* 5CAC 801084AC 25908200 */  or         $s2, $a0, $v0
    /* 5CB0 801084B0 06000224 */  addiu      $v0, $zero, 0x6
    /* 5CB4 801084B4 0C008216 */  bne        $s4, $v0, .L801084E8
    /* 5CB8 801084B8 1180033C */   lui       $v1, %hi(vs_menuD_containerData)
    /* 5CBC 801084BC FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 5CC0 801084C0 8C9A638C */  lw         $v1, %lo(vs_menuD_containerData)($v1)
    /* 5CC4 801084C4 80100200 */  sll        $v0, $v0, 2
    /* 5CC8 801084C8 21186200 */  addu       $v1, $v1, $v0
    /* 5CCC 801084CC 02386290 */  lbu        $v0, 0x3802($v1)
    /* 5CD0 801084D0 00000000 */  nop
    /* 5CD4 801084D4 0200422C */  sltiu      $v0, $v0, 0x2
    /* 5CD8 801084D8 0F004014 */  bnez       $v0, .L80108518
    /* 5CDC 801084DC 21204002 */   addu      $a0, $s2, $zero
    /* 5CE0 801084E0 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 5CE4 801084E4 25904202 */  or         $s2, $s2, $v0
  .L801084E8:
    /* 5CE8 801084E8 46210408 */  j          .L80108518
    /* 5CEC 801084EC 21204002 */   addu      $a0, $s2, $zero
    /* 5CF0 801084F0 1180023C */  lui        $v0, %hi(D_80109A6C)
    /* 5CF4 801084F4 6C9A428C */  lw         $v0, %lo(D_80109A6C)($v0)
    /* 5CF8 801084F8 00000000 */  nop
    /* 5CFC 801084FC 40100200 */  sll        $v0, $v0, 1
    /* 5D00 80108500 21105100 */  addu       $v0, $v0, $s1
    /* 5D04 80108504 FEFF4494 */  lhu        $a0, -0x2($v0)
    /* 5D08 80108508 00131400 */  sll        $v0, $s4, 12
    /* 5D0C 8010850C 25208200 */  or         $a0, $a0, $v0
    /* 5D10 80108510 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 5D14 80108514 25208200 */  or         $a0, $a0, $v0
  .L80108518:
    /* 5D18 80108518 4917040C */  jal        _discardMenu
    /* 5D1C 8010851C 00000000 */   nop
    /* 5D20 80108520 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5D24 80108524 0B000224 */  addiu      $v0, $zero, 0xB
    /* 5D28 80108528 64220408 */  j          .L80108990
    /* 5D2C 8010852C 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
    /* 5D30 80108530 F2FE030C */  jal        func_800FFBC8
    /* 5D34 80108534 00000000 */   nop
    /* 5D38 80108538 B316040C */  jal        _displaySortMenu
    /* 5D3C 8010853C 01008426 */   addiu     $a0, $s4, 0x1
    /* 5D40 80108540 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5D44 80108544 0C000224 */  addiu      $v0, $zero, 0xC
    /* 5D48 80108548 64220408 */  j          .L80108990
    /* 5D4C 8010854C 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
  .L80108550:
    /* 5D50 80108550 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 5D54 80108554 00000000 */   nop
    /* 5D58 80108558 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 5D5C 8010855C 06006216 */  bne        $s3, $v0, .L80108578
    /* 5D60 80108560 1180023C */   lui       $v0, %hi(D_80109A68)
    /* 5D64 80108564 EAFE030C */  jal        func_800FFBA8
    /* 5D68 80108568 00000000 */   nop
    /* 5D6C 8010856C 65220408 */  j          .L80108994
    /* 5D70 80108570 FEFF0224 */   addiu     $v0, $zero, -0x2
  .L80108574:
    /* 5D74 80108574 1180023C */  lui        $v0, %hi(D_80109A68)
  .L80108578:
    /* 5D78 80108578 64220408 */  j          .L80108990
    /* 5D7C 8010857C 689A40A0 */   sb        $zero, %lo(D_80109A68)($v0)
    /* 5D80 80108580 74EA030C */  jal        vs_mainmenu_ready
    /* 5D84 80108584 00000000 */   nop
    /* 5D88 80108588 01014010 */  beqz       $v0, .L80108990
    /* 5D8C 8010858C 1180103C */   lui       $s0, %hi(D_80109A6C)
    /* 5D90 80108590 21208002 */  addu       $a0, $s4, $zero
    /* 5D94 80108594 6C9A028E */  lw         $v0, %lo(D_80109A6C)($s0)
    /* 5D98 80108598 1180123C */  lui        $s2, %hi(vs_menuD_containerData)
    /* 5D9C 8010859C 40100200 */  sll        $v0, $v0, 1
    /* 5DA0 801085A0 21105100 */  addu       $v0, $v0, $s1
    /* 5DA4 801085A4 FEFF4594 */  lhu        $a1, -0x2($v0)
    /* 5DA8 801085A8 8C9A468E */  lw         $a2, %lo(vs_menuD_containerData)($s2)
    /* 5DAC 801085AC 270F040C */  jal        _getParentItemIndex
    /* 5DB0 801085B0 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 5DB4 801085B4 21984000 */  addu       $s3, $v0, $zero
    /* 5DB8 801085B8 03006012 */  beqz       $s3, .L801085C8
    /* 5DBC 801085BC 21208002 */   addu      $a0, $s4, $zero
    /* 5DC0 801085C0 7B210408 */  j          .L801085EC
    /* 5DC4 801085C4 21A00000 */   addu      $s4, $zero, $zero
  .L801085C8:
    /* 5DC8 801085C8 6C9A028E */  lw         $v0, %lo(D_80109A6C)($s0)
    /* 5DCC 801085CC 03001424 */  addiu      $s4, $zero, 0x3
    /* 5DD0 801085D0 40100200 */  sll        $v0, $v0, 1
    /* 5DD4 801085D4 21105100 */  addu       $v0, $v0, $s1
    /* 5DD8 801085D8 FEFF4594 */  lhu        $a1, -0x2($v0)
    /* 5DDC 801085DC 8C9A468E */  lw         $a2, %lo(vs_menuD_containerData)($s2)
    /* 5DE0 801085E0 450F040C */  jal        _getSetShieldIndex
    /* 5DE4 801085E4 FFFFA524 */   addiu     $a1, $a1, -0x1
    /* 5DE8 801085E8 21984000 */  addu       $s3, $v0, $zero
  .L801085EC:
    /* 5DEC 801085EC 1180103C */  lui        $s0, %hi(vs_menuD_containerData)
    /* 5DF0 801085F0 8C9A058E */  lw         $a1, %lo(vs_menuD_containerData)($s0)
    /* 5DF4 801085F4 1C0C040C */  jal        _countContainerItems
    /* 5DF8 801085F8 21208002 */   addu      $a0, $s4, $zero
    /* 5DFC 801085FC 21904000 */  addu       $s2, $v0, $zero
    /* 5E00 80108600 8C9A058E */  lw         $a1, %lo(vs_menuD_containerData)($s0)
    /* 5E04 80108604 250B040C */  jal        _getContainerIndicesOffset
    /* 5E08 80108608 21208002 */   addu      $a0, $s4, $zero
    /* 5E0C 8010860C 21208002 */  addu       $a0, $s4, $zero
    /* 5E10 80108610 FFFF6526 */  addiu      $a1, $s3, -0x1
    /* 5E14 80108614 340B040C */  jal        _getContainerItemIndex
    /* 5E18 80108618 21304000 */   addu      $a2, $v0, $zero
    /* 5E1C 8010861C 21184000 */  addu       $v1, $v0, $zero
    /* 5E20 80108620 0900422A */  slti       $v0, $s2, 0x9
    /* 5E24 80108624 04004014 */  bnez       $v0, .L80108638
    /* 5E28 80108628 FFFF7324 */   addiu     $s3, $v1, -0x1
    /* 5E2C 8010862C 0800622A */  slti       $v0, $s3, 0x8
    /* 5E30 80108630 03004010 */  beqz       $v0, .L80108640
    /* 5E34 80108634 F8FF4426 */   addiu     $a0, $s2, -0x8
  .L80108638:
    /* 5E38 80108638 97210408 */  j          .L8010865C
    /* 5E3C 8010863C 21900000 */   addu      $s2, $zero, $zero
  .L80108640:
    /* 5E40 80108640 2A109300 */  slt        $v0, $a0, $s3
    /* 5E44 80108644 03004010 */  beqz       $v0, .L80108654
    /* 5E48 80108648 21908000 */   addu      $s2, $a0, $zero
    /* 5E4C 8010864C 97210408 */  j          .L8010865C
    /* 5E50 80108650 23987202 */   subu      $s3, $s3, $s2
  .L80108654:
    /* 5E54 80108654 FEFF7224 */  addiu      $s2, $v1, -0x2
    /* 5E58 80108658 01001324 */  addiu      $s3, $zero, 0x1
  .L8010865C:
    /* 5E5C 8010865C 0F80043C */  lui        $a0, %hi(D_800F4EE8)
    /* 5E60 80108660 E84E8424 */  addiu      $a0, $a0, %lo(D_800F4EE8)
    /* 5E64 80108664 01008226 */  addiu      $v0, $s4, 0x1
    /* 5E68 80108668 07004230 */  andi       $v0, $v0, 0x7
    /* 5E6C 8010866C A00082A0 */  sb         $v0, 0xA0($a0)
    /* 5E70 80108670 51008226 */  addiu      $v0, $s4, 0x51
    /* 5E74 80108674 40100200 */  sll        $v0, $v0, 1
    /* 5E78 80108678 21184400 */  addu       $v1, $v0, $a0
    /* 5E7C 8010867C 01004224 */  addiu      $v0, $v0, 0x1
    /* 5E80 80108680 21104400 */  addu       $v0, $v0, $a0
    /* 5E84 80108684 000073A0 */  sb         $s3, 0x0($v1)
    /* 5E88 80108688 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5E8C 8010868C 000052A0 */  sb         $s2, 0x0($v0)
  .L80108690:
    /* 5E90 80108690 01000224 */  addiu      $v0, $zero, 0x1
  .L80108694:
    /* 5E94 80108694 64220408 */  j          .L80108990
    /* 5E98 80108698 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
    /* 5E9C 8010869C 4917040C */  jal        _discardMenu
    /* 5EA0 801086A0 21200000 */   addu      $a0, $zero, $zero
    /* 5EA4 801086A4 21984000 */  addu       $s3, $v0, $zero
    /* 5EA8 801086A8 BA006012 */  beqz       $s3, .L80108994
    /* 5EAC 801086AC 21100000 */   addu      $v0, $zero, $zero
    /* 5EB0 801086B0 F2FE030C */  jal        func_800FFBC8
    /* 5EB4 801086B4 00000000 */   nop
    /* 5EB8 801086B8 B5210408 */  j          .L801086D4
    /* 5EBC 801086BC 00000000 */   nop
    /* 5EC0 801086C0 B316040C */  jal        _displaySortMenu
    /* 5EC4 801086C4 21200000 */   addu      $a0, $zero, $zero
    /* 5EC8 801086C8 21984000 */  addu       $s3, $v0, $zero
    /* 5ECC 801086CC B1006012 */  beqz       $s3, .L80108994
    /* 5ED0 801086D0 21100000 */   addu      $v0, $zero, $zero
  .L801086D4:
    /* 5ED4 801086D4 15EA030C */  jal        func_800FA854
    /* 5ED8 801086D8 28000424 */   addiu     $a0, $zero, 0x28
    /* 5EDC 801086DC 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 5EE0 801086E0 21200000 */   addu      $a0, $zero, $zero
    /* 5EE4 801086E4 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 5EE8 801086E8 AA006212 */  beq        $s3, $v0, .L80108994
    /* 5EEC 801086EC 1180033C */   lui       $v1, %hi(D_80109A68)
  .L801086F0:
    /* 5EF0 801086F0 04000224 */  addiu      $v0, $zero, 0x4
    /* 5EF4 801086F4 64220408 */  j          .L80108990
    /* 5EF8 801086F8 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
    /* 5EFC 801086FC 74EA030C */  jal        vs_mainmenu_ready
    /* 5F00 80108700 00000000 */   nop
    /* 5F04 80108704 A3004010 */  beqz       $v0, .L80108994
    /* 5F08 80108708 21100000 */   addu      $v0, $zero, $zero
    /* 5F0C 8010870C 8F0F010C */  jal        vs_main_allocHeapR
    /* 5F10 80108710 006C0424 */   addiu     $a0, $zero, 0x6C00
    /* 5F14 80108714 07000424 */  addiu      $a0, $zero, 0x7
    /* 5F18 80108718 21804000 */  addu       $s0, $v0, $zero
    /* 5F1C 8010871C 00641326 */  addiu      $s3, $s0, 0x6400
    /* 5F20 80108720 21286002 */  addu       $a1, $s3, $zero
    /* 5F24 80108724 00601126 */  addiu      $s1, $s0, 0x6000
    /* 5F28 80108728 21302002 */  addu       $a2, $s1, $zero
    /* 5F2C 8010872C 191B040C */  jal        func_80106C64
    /* 5F30 80108730 21380002 */   addu      $a3, $s0, $zero
    /* 5F34 80108734 21904000 */  addu       $s2, $v0, $zero
    /* 5F38 80108738 1180033C */  lui        $v1, %hi(D_80109A69)
    /* 5F3C 8010873C 0100422E */  sltiu      $v0, $s2, 0x1
    /* 5F40 80108740 0F004010 */  beqz       $v0, .L80108780
    /* 5F44 80108744 699A62A0 */   sb        $v0, %lo(D_80109A69)($v1)
    /* 5F48 80108748 1180033C */  lui        $v1, %hi(_menuText)
    /* 5F4C 8010874C 1180023C */  lui        $v0, %hi(D_80109A7A)
    /* 5F50 80108750 7A9A4290 */  lbu        $v0, %lo(D_80109A7A)($v0)
    /* 5F54 80108754 2C956324 */  addiu      $v1, $v1, %lo(_menuText)
    /* 5F58 80108758 1D004224 */  addiu      $v0, $v0, 0x1D
    /* 5F5C 8010875C 40100200 */  sll        $v0, $v0, 1
    /* 5F60 80108760 21104300 */  addu       $v0, $v0, $v1
    /* 5F64 80108764 00004494 */  lhu        $a0, 0x0($v0)
    /* 5F68 80108768 00000000 */  nop
    /* 5F6C 8010876C 40200400 */  sll        $a0, $a0, 1
    /* 5F70 80108770 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 5F74 80108774 21208300 */   addu      $a0, $a0, $v1
    /* 5F78 80108778 E8210408 */  j          .L801087A0
    /* 5F7C 8010877C 00000000 */   nop
  .L80108780:
    /* 5F80 80108780 0100023C */  lui        $v0, (0x19200 >> 16)
    /* 5F84 80108784 00924234 */  ori        $v0, $v0, (0x19200 & 0xFFFF)
    /* 5F88 80108788 21204002 */  addu       $a0, $s2, $zero
    /* 5F8C 8010878C 51008526 */  addiu      $a1, $s4, 0x51
    /* 5F90 80108790 2528A200 */  or         $a1, $a1, $v0
    /* 5F94 80108794 21306002 */  addu       $a2, $s3, $zero
    /* 5F98 80108798 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 5F9C 8010879C 21382002 */   addu      $a3, $s1, $zero
  .L801087A0:
    /* 5FA0 801087A0 180F010C */  jal        vs_main_freeHeapR
    /* 5FA4 801087A4 21200002 */   addu      $a0, $s0, $zero
    /* 5FA8 801087A8 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5FAC 801087AC 0E000224 */  addiu      $v0, $zero, 0xE
    /* 5FB0 801087B0 64220408 */  j          .L80108990
    /* 5FB4 801087B4 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
    /* 5FB8 801087B8 74EA030C */  jal        vs_mainmenu_ready
    /* 5FBC 801087BC 00000000 */   nop
    /* 5FC0 801087C0 74004010 */  beqz       $v0, .L80108994
    /* 5FC4 801087C4 21100000 */   addu      $v0, $zero, $zero
    /* 5FC8 801087C8 0502040C */  jal        func_80100814
    /* 5FCC 801087CC 00000000 */   nop
  .L801087D0:
    /* 5FD0 801087D0 AC1C040C */  jal        func_801072B0
    /* 5FD4 801087D4 01000424 */   addiu     $a0, $zero, 0x1
    /* 5FD8 801087D8 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 5FDC 801087DC 0F000224 */  addiu      $v0, $zero, 0xF
    /* 5FE0 801087E0 64220408 */  j          .L80108990
    /* 5FE4 801087E4 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
    /* 5FE8 801087E8 AC1C040C */  jal        func_801072B0
    /* 5FEC 801087EC 21200000 */   addu      $a0, $zero, $zero
    /* 5FF0 801087F0 21984000 */  addu       $s3, $v0, $zero
    /* 5FF4 801087F4 67006012 */  beqz       $s3, .L80108994
    /* 5FF8 801087F8 21100000 */   addu      $v0, $zero, $zero
    /* 5FFC 801087FC F2FE030C */  jal        func_800FFBC8
    /* 6000 80108800 00000000 */   nop
    /* 6004 80108804 07006106 */  bgez       $s3, .L80108824
    /* 6008 80108808 1180023C */   lui       $v0, %hi(D_80109A7A)
    /* 600C 8010880C FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 6010 80108810 60006212 */  beq        $s3, $v0, .L80108994
    /* 6014 80108814 1180033C */   lui       $v1, %hi(D_80109A68)
    /* 6018 80108818 05000224 */  addiu      $v0, $zero, 0x5
    /* 601C 8010881C 64220408 */  j          .L80108990
    /* 6020 80108820 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
  .L80108824:
    /* 6024 80108824 7A9A4290 */  lbu        $v0, %lo(D_80109A7A)($v0)
    /* 6028 80108828 00000000 */  nop
    /* 602C 8010882C 24004010 */  beqz       $v0, .L801088C0
    /* 6030 80108830 1080043C */   lui       $a0, %hi(vs_menu_inventoryStorage)
    /* 6034 80108834 5C24828C */  lw         $v0, %lo(vs_menu_inventoryStorage)($a0)
    /* 6038 80108838 00800334 */  ori        $v1, $zero, 0x8000
    /* 603C 8010883C 21104300 */  addu       $v0, $v0, $v1
    /* 6040 80108840 B0435294 */  lhu        $s2, 0x43B0($v0)
    /* 6044 80108844 00000000 */  nop
    /* 6048 80108848 3F004012 */  beqz       $s2, .L80108948
    /* 604C 8010884C 21980000 */   addu      $s3, $zero, $zero
    /* 6050 80108850 1180153C */  lui        $s5, %hi(D_80109A88)
    /* 6054 80108854 21988000 */  addu       $s3, $a0, $zero
    /* 6058 80108858 B0871434 */  ori        $s4, $zero, 0x87B0
    /* 605C 8010885C 038A1200 */  sra        $s1, $s2, 8
  .L80108860:
    /* 6060 80108860 10002436 */  ori        $a0, $s1, 0x10
    /* 6064 80108864 FFFF5026 */  addiu      $s0, $s2, -0x1
    /* 6068 80108868 FF001032 */  andi       $s0, $s0, 0xFF
    /* 606C 8010886C 21300002 */  addu       $a2, $s0, $zero
    /* 6070 80108870 5C24678E */  lw         $a3, %lo(vs_menu_inventoryStorage)($s3)
    /* 6074 80108874 889AA58E */  lw         $a1, %lo(D_80109A88)($s5)
    /* 6078 80108878 AB0C040C */  jal        _copyContainerItem
    /* 607C 8010887C 2138F400 */   addu      $a3, $a3, $s4
    /* 6080 80108880 21202002 */  addu       $a0, $s1, $zero
    /* 6084 80108884 5C24668E */  lw         $a2, %lo(vs_menu_inventoryStorage)($s3)
    /* 6088 80108888 21280002 */  addu       $a1, $s0, $zero
    /* 608C 8010888C 600B040C */  jal        _initContainerObject
    /* 6090 80108890 2130D400 */   addu      $a2, $a2, $s4
    /* 6094 80108894 941A040C */  jal        func_80106A50
    /* 6098 80108898 00000000 */   nop
    /* 609C 8010889C 5C24628E */  lw         $v0, %lo(vs_menu_inventoryStorage)($s3)
    /* 60A0 801088A0 00800334 */  ori        $v1, $zero, 0x8000
    /* 60A4 801088A4 21104300 */  addu       $v0, $v0, $v1
    /* 60A8 801088A8 B0435294 */  lhu        $s2, 0x43B0($v0)
    /* 60AC 801088AC 00000000 */  nop
    /* 60B0 801088B0 EBFF4016 */  bnez       $s2, .L80108860
    /* 60B4 801088B4 038A1200 */   sra       $s1, $s2, 8
    /* 60B8 801088B8 52220408 */  j          .L80108948
    /* 60BC 801088BC 21980000 */   addu      $s3, $zero, $zero
  .L801088C0:
    /* 60C0 801088C0 5C24828C */  lw         $v0, %lo(vs_menu_inventoryStorage)($a0)
    /* 60C4 801088C4 00800334 */  ori        $v1, $zero, 0x8000
    /* 60C8 801088C8 21104300 */  addu       $v0, $v0, $v1
    /* 60CC 801088CC B0435294 */  lhu        $s2, 0x43B0($v0)
    /* 60D0 801088D0 00000000 */  nop
    /* 60D4 801088D4 1C004012 */  beqz       $s2, .L80108948
    /* 60D8 801088D8 21980000 */   addu      $s3, $zero, $zero
    /* 60DC 801088DC 1180153C */  lui        $s5, %hi(D_80109A88)
    /* 60E0 801088E0 21988000 */  addu       $s3, $a0, $zero
    /* 60E4 801088E4 B0871434 */  ori        $s4, $zero, 0x87B0
    /* 60E8 801088E8 038A1200 */  sra        $s1, $s2, 8
  .L801088EC:
    /* 60EC 801088EC 10002436 */  ori        $a0, $s1, 0x10
    /* 60F0 801088F0 FFFF5026 */  addiu      $s0, $s2, -0x1
    /* 60F4 801088F4 FF001032 */  andi       $s0, $s0, 0xFF
    /* 60F8 801088F8 21300002 */  addu       $a2, $s0, $zero
    /* 60FC 801088FC 5C24678E */  lw         $a3, %lo(vs_menu_inventoryStorage)($s3)
    /* 6100 80108900 889AA58E */  lw         $a1, %lo(D_80109A88)($s5)
    /* 6104 80108904 AB0C040C */  jal        _copyContainerItem
    /* 6108 80108908 2138F400 */   addu      $a3, $a3, $s4
    /* 610C 8010890C 21202002 */  addu       $a0, $s1, $zero
    /* 6110 80108910 5C24668E */  lw         $a2, %lo(vs_menu_inventoryStorage)($s3)
    /* 6114 80108914 21280002 */  addu       $a1, $s0, $zero
    /* 6118 80108918 600B040C */  jal        _initContainerObject
    /* 611C 8010891C 2130D400 */   addu      $a2, $a2, $s4
    /* 6120 80108920 941A040C */  jal        func_80106A50
    /* 6124 80108924 00000000 */   nop
    /* 6128 80108928 5C24628E */  lw         $v0, %lo(vs_menu_inventoryStorage)($s3)
    /* 612C 8010892C 00800334 */  ori        $v1, $zero, 0x8000
    /* 6130 80108930 21104300 */  addu       $v0, $v0, $v1
    /* 6134 80108934 B0435294 */  lhu        $s2, 0x43B0($v0)
    /* 6138 80108938 00000000 */  nop
    /* 613C 8010893C EBFF4016 */  bnez       $s2, .L801088EC
    /* 6140 80108940 038A1200 */   sra       $s1, $s2, 8
    /* 6144 80108944 21980000 */  addu       $s3, $zero, $zero
  .L80108948:
    /* 6148 80108948 1180103C */  lui        $s0, %hi(D_80109A88)
    /* 614C 8010894C 21206002 */  addu       $a0, $s3, $zero
  .L80108950:
    /* 6150 80108950 889A058E */  lw         $a1, %lo(D_80109A88)($s0)
    /* 6154 80108954 F60D040C */  jal        _defragmentContainerItems
    /* 6158 80108958 01007326 */   addiu     $s3, $s3, 0x1
    /* 615C 8010895C 0700622A */  slti       $v0, $s3, 0x7
    /* 6160 80108960 FBFF4014 */  bnez       $v0, .L80108950
    /* 6164 80108964 21206002 */   addu      $a0, $s3, $zero
    /* 6168 80108968 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 616C 8010896C 21200000 */   addu      $a0, $zero, $zero
    /* 6170 80108970 1180033C */  lui        $v1, %hi(D_80109A68)
    /* 6174 80108974 11000224 */  addiu      $v0, $zero, 0x11
    /* 6178 80108978 64220408 */  j          .L80108990
    /* 617C 8010897C 689A62A0 */   sb        $v0, %lo(D_80109A68)($v1)
    /* 6180 80108980 74EA030C */  jal        vs_mainmenu_ready
    /* 6184 80108984 00000000 */   nop
    /* 6188 80108988 65220408 */  j          .L80108994
    /* 618C 8010898C 00000000 */   nop
  .L80108990:
    /* 6190 80108990 21100000 */  addu       $v0, $zero, $zero
  .L80108994:
    /* 6194 80108994 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 6198 80108998 4800B68F */  lw         $s6, 0x48($sp)
    /* 619C 8010899C 4400B58F */  lw         $s5, 0x44($sp)
    /* 61A0 801089A0 4000B48F */  lw         $s4, 0x40($sp)
    /* 61A4 801089A4 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 61A8 801089A8 3800B28F */  lw         $s2, 0x38($sp)
    /* 61AC 801089AC 3400B18F */  lw         $s1, 0x34($sp)
    /* 61B0 801089B0 3000B08F */  lw         $s0, 0x30($sp)
    /* 61B4 801089B4 0800E003 */  jr         $ra
    /* 61B8 801089B8 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_80107490
