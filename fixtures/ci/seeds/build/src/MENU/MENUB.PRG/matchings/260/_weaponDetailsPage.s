nonmatching _weaponDetailsPage, 0x248

glabel _weaponDetailsPage
    /* 6C4 80102EC4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6C8 80102EC8 21288000 */  addu       $a1, $a0, $zero
    /* 6CC 80102ECC 2800BFAF */  sw         $ra, 0x28($sp)
    /* 6D0 80102ED0 2400B1AF */  sw         $s1, 0x24($sp)
    /* 6D4 80102ED4 1100A010 */  beqz       $a1, .L80102F1C
    /* 6D8 80102ED8 2000B0AF */   sw        $s0, 0x20($sp)
    /* 6DC 80102EDC 1180033C */  lui        $v1, %hi(D_8010A5EE)
    /* 6E0 80102EE0 03120500 */  sra        $v0, $a1, 8
    /* 6E4 80102EE4 EEA562A0 */  sb         $v0, %lo(D_8010A5EE)($v1)
    /* 6E8 80102EE8 FF004430 */  andi       $a0, $v0, 0xFF
    /* 6EC 80102EEC 1180033C */  lui        $v1, %hi(D_8010A5EF)
    /* 6F0 80102EF0 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 6F4 80102EF4 140B040C */  jal        func_80102C50
    /* 6F8 80102EF8 EFA562A0 */   sb        $v0, %lo(D_8010A5EF)($v1)
    /* 6FC 80102EFC 21100000 */  addu       $v0, $zero, $zero
    /* 700 80102F00 1180033C */  lui        $v1, %hi(D_8010A5F0)
    /* 704 80102F04 F0A560A0 */  sb         $zero, %lo(D_8010A5F0)($v1)
    /* 708 80102F08 1180033C */  lui        $v1, %hi(D_8010A5ED)
    /* 70C 80102F0C EDA560A0 */  sb         $zero, %lo(D_8010A5ED)($v1)
    /* 710 80102F10 1180033C */  lui        $v1, %hi(D_8010A5EC)
    /* 714 80102F14 3E0C0408 */  j          .L801030F8
    /* 718 80102F18 ECA560A0 */   sb        $zero, %lo(D_8010A5EC)($v1)
  .L80102F1C:
    /* 71C 80102F1C 1180103C */  lui        $s0, %hi(D_8010A5EC)
    /* 720 80102F20 ECA50392 */  lbu        $v1, %lo(D_8010A5EC)($s0)
    /* 724 80102F24 01001124 */  addiu      $s1, $zero, 0x1
    /* 728 80102F28 20007110 */  beq        $v1, $s1, .L80102FAC
    /* 72C 80102F2C 02006228 */   slti      $v0, $v1, 0x2
    /* 730 80102F30 05004010 */  beqz       $v0, .L80102F48
    /* 734 80102F34 02000224 */   addiu     $v0, $zero, 0x2
    /* 738 80102F38 09006010 */  beqz       $v1, .L80102F60
    /* 73C 80102F3C 21100000 */   addu      $v0, $zero, $zero
    /* 740 80102F40 3E0C0408 */  j          .L801030F8
    /* 744 80102F44 00000000 */   nop
  .L80102F48:
    /* 748 80102F48 30006210 */  beq        $v1, $v0, .L8010300C
    /* 74C 80102F4C 03000224 */   addiu     $v0, $zero, 0x3
    /* 750 80102F50 64006210 */  beq        $v1, $v0, .L801030E4
    /* 754 80102F54 21100000 */   addu      $v0, $zero, $zero
    /* 758 80102F58 3E0C0408 */  j          .L801030F8
    /* 75C 80102F5C 00000000 */   nop
  .L80102F60:
    /* 760 80102F60 74EA030C */  jal        vs_mainmenu_ready
    /* 764 80102F64 00000000 */   nop
    /* 768 80102F68 62004010 */  beqz       $v0, .L801030F4
    /* 76C 80102F6C 1180023C */   lui       $v0, %hi(D_8010A5EE)
    /* 770 80102F70 EEA54490 */  lbu        $a0, %lo(D_8010A5EE)($v0)
    /* 774 80102F74 470B040C */  jal        _initMenuLayout
    /* 778 80102F78 07000524 */   addiu     $a1, $zero, 0x7
    /* 77C 80102F7C 0680033C */  lui        $v1, %hi(vs_main_inventoryIndices)
    /* 780 80102F80 1180023C */  lui        $v0, %hi(D_8010A5EF)
    /* 784 80102F84 EFA54290 */  lbu        $v0, %lo(D_8010A5EF)($v0)
    /* 788 80102F88 D8196324 */  addiu      $v1, $v1, %lo(vs_main_inventoryIndices)
    /* 78C 80102F8C 21104300 */  addu       $v0, $v0, $v1
    /* 790 80102F90 00004490 */  lbu        $a0, 0x0($v0)
    /* 794 80102F94 9CF4030C */  jal        vs_mainMenu_setUiWeaponStats
    /* 798 80102F98 00000000 */   nop
    /* 79C 80102F9C 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 7A0 80102FA0 03000424 */   addiu     $a0, $zero, 0x3
    /* 7A4 80102FA4 3D0C0408 */  j          .L801030F4
    /* 7A8 80102FA8 ECA511A2 */   sb        $s1, %lo(D_8010A5EC)($s0)
  .L80102FAC:
    /* 7AC 80102FAC 1180043C */  lui        $a0, %hi(D_8010A5ED)
    /* 7B0 80102FB0 EDA58390 */  lbu        $v1, %lo(D_8010A5ED)($a0)
    /* 7B4 80102FB4 00000000 */  nop
    /* 7B8 80102FB8 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 7BC 80102FBC 10004010 */  beqz       $v0, .L80103000
    /* 7C0 80102FC0 01006224 */   addiu     $v0, $v1, 0x1
    /* 7C4 80102FC4 EDA582A0 */  sb         $v0, %lo(D_8010A5ED)($a0)
    /* 7C8 80102FC8 FF004230 */  andi       $v0, $v0, 0xFF
    /* 7CC 80102FCC 0600422C */  sltiu      $v0, $v0, 0x6
    /* 7D0 80102FD0 48004010 */  beqz       $v0, .L801030F4
    /* 7D4 80102FD4 0680023C */   lui       $v0, %hi(vs_main_inventoryIndices)
    /* 7D8 80102FD8 1180033C */  lui        $v1, %hi(D_8010A5EF)
    /* 7DC 80102FDC D8194224 */  addiu      $v0, $v0, %lo(vs_main_inventoryIndices)
    /* 7E0 80102FE0 EFA56390 */  lbu        $v1, %lo(D_8010A5EF)($v1)
    /* 7E4 80102FE4 EDA58490 */  lbu        $a0, %lo(D_8010A5ED)($a0)
    /* 7E8 80102FE8 21186200 */  addu       $v1, $v1, $v0
    /* 7EC 80102FEC 00006590 */  lbu        $a1, 0x0($v1)
    /* 7F0 80102FF0 44F1030C */  jal        vs_mainMenu_initSetWeaponGemMenu
    /* 7F4 80102FF4 01000624 */   addiu     $a2, $zero, 0x1
    /* 7F8 80102FF8 3E0C0408 */  j          .L801030F8
    /* 7FC 80102FFC 21100000 */   addu      $v0, $zero, $zero
  .L80103000:
    /* 800 80103000 02000224 */  addiu      $v0, $zero, 0x2
    /* 804 80103004 3D0C0408 */  j          .L801030F4
    /* 808 80103008 ECA502A2 */   sb        $v0, %lo(D_8010A5EC)($s0)
  .L8010300C:
    /* 80C 8010300C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 810 80103010 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 814 80103014 00000000 */  nop
    /* 818 80103018 50004230 */  andi       $v0, $v0, 0x50
    /* 81C 8010301C 06004010 */  beqz       $v0, .L80103038
    /* 820 80103020 00000000 */   nop
    /* 824 80103024 950B040C */  jal        _initMenuLeave
    /* 828 80103028 01000424 */   addiu     $a0, $zero, 0x1
    /* 82C 8010302C 03000224 */  addiu      $v0, $zero, 0x3
    /* 830 80103030 3D0C0408 */  j          .L801030F4
    /* 834 80103034 ECA502A2 */   sb        $v0, %lo(D_8010A5EC)($s0)
  .L80103038:
    /* 838 80103038 1180103C */  lui        $s0, %hi(D_8010A5EF)
    /* 83C 8010303C EFA50592 */  lbu        $a1, %lo(D_8010A5EF)($s0)
    /* 840 80103040 980A040C */  jal        _handleItemPaging
    /* 844 80103044 21200000 */   addu      $a0, $zero, $zero
    /* 848 80103048 EFA50392 */  lbu        $v1, %lo(D_8010A5EF)($s0)
    /* 84C 8010304C 21884000 */  addu       $s1, $v0, $zero
    /* 850 80103050 28002312 */  beq        $s1, $v1, .L801030F4
    /* 854 80103054 21200000 */   addu      $a0, $zero, $zero
    /* 858 80103058 21282002 */  addu       $a1, $s1, $zero
    /* 85C 8010305C 820B040C */  jal        _getItemIndex
    /* 860 80103060 EFA511A2 */   sb        $s1, %lo(D_8010A5EF)($s0)
    /* 864 80103064 21804000 */  addu       $s0, $v0, $zero
    /* 868 80103068 40111000 */  sll        $v0, $s0, 5
    /* 86C 8010306C 0680043C */  lui        $a0, %hi(D_80060148)
    /* 870 80103070 48018424 */  addiu      $a0, $a0, %lo(D_80060148)
    /* 874 80103074 21204400 */  addu       $a0, $v0, $a0
    /* 878 80103078 1000A527 */  addiu      $a1, $sp, 0x10
    /* 87C 8010307C 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 880 80103080 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 884 80103084 82F2030C */  jal        vs_mainMenu_initUiWeapon
    /* 888 80103088 1800A627 */   addiu     $a2, $sp, 0x18
    /* 88C 8010308C 9CF4030C */  jal        vs_mainMenu_setUiWeaponStats
    /* 890 80103090 21200002 */   addu      $a0, $s0, $zero
    /* 894 80103094 1000A527 */  addiu      $a1, $sp, 0x10
    /* 898 80103098 21382002 */  addu       $a3, $s1, $zero
    /* 89C 8010309C 1180023C */  lui        $v0, %hi(D_8010A5EE)
    /* 8A0 801030A0 EEA54490 */  lbu        $a0, %lo(D_8010A5EE)($v0)
    /* 8A4 801030A4 1800A68F */  lw         $a2, 0x18($sp)
    /* 8A8 801030A8 5B0B040C */  jal        _setSubMenu
    /* 8AC 801030AC 01001024 */   addiu     $s0, $zero, 0x1
    /* 8B0 801030B0 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 8B4 801030B4 D8194224 */  addiu      $v0, $v0, %lo(vs_main_inventoryIndices)
    /* 8B8 801030B8 21882202 */  addu       $s1, $s1, $v0
    /* 8BC 801030BC 21200002 */  addu       $a0, $s0, $zero
  .L801030C0:
    /* 8C0 801030C0 00002592 */  lbu        $a1, 0x0($s1)
    /* 8C4 801030C4 21300000 */  addu       $a2, $zero, $zero
    /* 8C8 801030C8 44F1030C */  jal        vs_mainMenu_initSetWeaponGemMenu
    /* 8CC 801030CC 01001026 */   addiu     $s0, $s0, 0x1
    /* 8D0 801030D0 0600022A */  slti       $v0, $s0, 0x6
    /* 8D4 801030D4 FAFF4014 */  bnez       $v0, .L801030C0
    /* 8D8 801030D8 21200002 */   addu      $a0, $s0, $zero
    /* 8DC 801030DC 3E0C0408 */  j          .L801030F8
    /* 8E0 801030E0 21100000 */   addu      $v0, $zero, $zero
  .L801030E4:
    /* 8E4 801030E4 74EA030C */  jal        vs_mainmenu_ready
    /* 8E8 801030E8 00000000 */   nop
    /* 8EC 801030EC 3E0C0408 */  j          .L801030F8
    /* 8F0 801030F0 00000000 */   nop
  .L801030F4:
    /* 8F4 801030F4 21100000 */  addu       $v0, $zero, $zero
  .L801030F8:
    /* 8F8 801030F8 2800BF8F */  lw         $ra, 0x28($sp)
    /* 8FC 801030FC 2400B18F */  lw         $s1, 0x24($sp)
    /* 900 80103100 2000B08F */  lw         $s0, 0x20($sp)
    /* 904 80103104 0800E003 */  jr         $ra
    /* 908 80103108 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _weaponDetailsPage
