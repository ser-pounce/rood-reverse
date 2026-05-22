nonmatching func_80108C6C, 0x8C0

glabel func_80108C6C
    /* 646C 80108C6C C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 6470 80108C70 2400B3AF */  sw         $s3, 0x24($sp)
    /* 6474 80108C74 21988000 */  addu       $s3, $a0, $zero
    /* 6478 80108C78 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 647C 80108C7C 8C9A438C */  lw         $v1, %lo(vs_menuD_containerData)($v0)
    /* 6480 80108C80 1080023C */  lui        $v0, %hi(vs_mainMenu_weapons)
    /* 6484 80108C84 1080043C */  lui        $a0, %hi(vs_mainMenu_blades)
    /* 6488 80108C88 3800BFAF */  sw         $ra, 0x38($sp)
    /* 648C 80108C8C 3400B7AF */  sw         $s7, 0x34($sp)
    /* 6490 80108C90 3000B6AF */  sw         $s6, 0x30($sp)
    /* 6494 80108C94 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 6498 80108C98 2800B4AF */  sw         $s4, 0x28($sp)
    /* 649C 80108C9C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 64A0 80108CA0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 64A4 80108CA4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 64A8 80108CA8 702443AC */  sw         $v1, %lo(vs_mainMenu_weapons)($v0)
    /* 64AC 80108CAC 000A6224 */  addiu      $v0, $v1, 0xA00
    /* 64B0 80108CB0 642482AC */  sw         $v0, %lo(vs_mainMenu_blades)($a0)
    /* 64B4 80108CB4 1080043C */  lui        $a0, %hi(vs_mainMenu_grips)
    /* 64B8 80108CB8 00156224 */  addiu      $v0, $v1, 0x1500
    /* 64BC 80108CBC 602482AC */  sw         $v0, %lo(vs_mainMenu_grips)($a0)
    /* 64C0 80108CC0 1080043C */  lui        $a0, %hi(vs_mainMenu_shields)
    /* 64C4 80108CC4 00046224 */  addiu      $v0, $v1, 0x400
    /* 64C8 80108CC8 6C2482AC */  sw         $v0, %lo(vs_mainMenu_shields)($a0)
    /* 64CC 80108CCC 1080043C */  lui        $a0, %hi(vs_mainMenu_armor)
    /* 64D0 80108CD0 00196224 */  addiu      $v0, $v1, 0x1900
    /* 64D4 80108CD4 682482AC */  sw         $v0, %lo(vs_mainMenu_armor)($a0)
    /* 64D8 80108CD8 1080023C */  lui        $v0, %hi(vs_mainMenu_gems)
    /* 64DC 80108CDC 00236324 */  addiu      $v1, $v1, 0x2300
    /* 64E0 80108CE0 582443AC */  sw         $v1, %lo(vs_mainMenu_gems)($v0)
    /* 64E4 80108CE4 00006392 */  lbu        $v1, 0x0($s3)
    /* 64E8 80108CE8 00000000 */  nop
    /* 64EC 80108CEC 0700622C */  sltiu      $v0, $v1, 0x7
    /* 64F0 80108CF0 B3004010 */  beqz       $v0, .L80108FC0
    /* 64F4 80108CF4 1080023C */   lui       $v0, %hi(jtbl_80102A18)
    /* 64F8 80108CF8 182A4224 */  addiu      $v0, $v0, %lo(jtbl_80102A18)
    /* 64FC 80108CFC 80180300 */  sll        $v1, $v1, 2
    /* 6500 80108D00 21186200 */  addu       $v1, $v1, $v0
    /* 6504 80108D04 0000628C */  lw         $v0, 0x0($v1)
    /* 6508 80108D08 00000000 */  nop
    /* 650C 80108D0C 08004000 */  jr         $v0
    /* 6510 80108D10 00000000 */   nop
    /* 6514 80108D14 73F9030C */  jal        vs_mainMenu_loadItemNames
    /* 6518 80108D18 01000424 */   addiu     $a0, $zero, 0x1
    /* 651C 80108D1C F2FE030C */  jal        func_800FFBC8
    /* 6520 80108D20 00000000 */   nop
    /* 6524 80108D24 540F040C */  jal        func_80103D50
    /* 6528 80108D28 21200000 */   addu      $a0, $zero, $zero
    /* 652C 80108D2C 003C0624 */  addiu      $a2, $zero, 0x3C00
    /* 6530 80108D30 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 6534 80108D34 5C24458C */  lw         $a1, %lo(vs_menu_inventoryStorage)($v0)
    /* 6538 80108D38 30C40434 */  ori        $a0, $zero, 0xC430
    /* 653C 80108D3C 2120A400 */  addu       $a0, $a1, $a0
    /* 6540 80108D40 7800030C */  jal        vs_battle_memcpy
    /* 6544 80108D44 B00FA524 */   addiu     $a1, $a1, 0xFB0
    /* 6548 80108D48 6B0E040C */  jal        _copyInventoryToContainer
    /* 654C 80108D4C 00000000 */   nop
    /* 6550 80108D50 21100000 */  addu       $v0, $zero, $zero
    /* 6554 80108D54 1180033C */  lui        $v1, %hi(D_80109A79)
    /* 6558 80108D58 799A60A0 */  sb         $zero, %lo(D_80109A79)($v1)
    /* 655C 80108D5C 1180033C */  lui        $v1, %hi(D_80109A78)
    /* 6560 80108D60 789A60A0 */  sb         $zero, %lo(D_80109A78)($v1)
    /* 6564 80108D64 1180033C */  lui        $v1, %hi(D_80109A7E)
    /* 6568 80108D68 7E9A60A0 */  sb         $zero, %lo(D_80109A7E)($v1)
    /* 656C 80108D6C 1180033C */  lui        $v1, %hi(D_80109A7F)
    /* 6570 80108D70 7F9A60A0 */  sb         $zero, %lo(D_80109A7F)($v1)
    /* 6574 80108D74 1180033C */  lui        $v1, %hi(D_80109A80)
    /* 6578 80108D78 809A60A0 */  sb         $zero, %lo(D_80109A80)($v1)
    /* 657C 80108D7C 01000324 */  addiu      $v1, $zero, 0x1
    /* 6580 80108D80 40250408 */  j          .L80109500
    /* 6584 80108D84 000063A2 */   sb        $v1, 0x0($s3)
    /* 6588 80108D88 73F9030C */  jal        vs_mainMenu_loadItemNames
    /* 658C 80108D8C 21200000 */   addu      $a0, $zero, $zero
    /* 6590 80108D90 00006392 */  lbu        $v1, 0x0($s3)
    /* 6594 80108D94 00000000 */  nop
    /* 6598 80108D98 21186200 */  addu       $v1, $v1, $v0
    /* 659C 80108D9C F0230408 */  j          .L80108FC0
    /* 65A0 80108DA0 000063A2 */   sb        $v1, 0x0($s3)
    /* 65A4 80108DA4 1180033C */  lui        $v1, %hi(D_80109A78)
    /* 65A8 80108DA8 789A6290 */  lbu        $v0, %lo(D_80109A78)($v1)
    /* 65AC 80108DAC 00000000 */  nop
    /* 65B0 80108DB0 03004010 */  beqz       $v0, .L80108DC0
    /* 65B4 80108DB4 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 65B8 80108DB8 F0230408 */  j          .L80108FC0
    /* 65BC 80108DBC 789A62A0 */   sb        $v0, %lo(D_80109A78)($v1)
  .L80108DC0:
    /* 65C0 80108DC0 6F22040C */  jal        func_801089BC
    /* 65C4 80108DC4 01000424 */   addiu     $a0, $zero, 0x1
    /* 65C8 80108DC8 03000224 */  addiu      $v0, $zero, 0x3
    /* 65CC 80108DCC F0230408 */  j          .L80108FC0
    /* 65D0 80108DD0 000062A2 */   sb        $v0, 0x0($s3)
    /* 65D4 80108DD4 6F22040C */  jal        func_801089BC
    /* 65D8 80108DD8 21200000 */   addu      $a0, $zero, $zero
    /* 65DC 80108DDC 1180103C */  lui        $s0, %hi(D_80109A74)
    /* 65E0 80108DE0 77004010 */  beqz       $v0, .L80108FC0
    /* 65E4 80108DE4 749A02AE */   sw        $v0, %lo(D_80109A74)($s0)
    /* 65E8 80108DE8 0300422C */  sltiu      $v0, $v0, 0x3
    /* 65EC 80108DEC 2F004010 */  beqz       $v0, .L80108EAC
    /* 65F0 80108DF0 06000224 */   addiu     $v0, $zero, 0x6
    /* 65F4 80108DF4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 65F8 80108DF8 21200000 */   addu      $a0, $zero, $zero
    /* 65FC 80108DFC 21200000 */  addu       $a0, $zero, $zero
    /* 6600 80108E00 B4000524 */  addiu      $a1, $zero, 0xB4
    /* 6604 80108E04 12000624 */  addiu      $a2, $zero, 0x12
    /* 6608 80108E08 08000224 */  addiu      $v0, $zero, 0x8
    /* 660C 80108E0C 1180033C */  lui        $v1, %hi(_menuText)
    /* 6610 80108E10 1000A2AF */  sw         $v0, 0x10($sp)
    /* 6614 80108E14 749A028E */  lw         $v0, %lo(D_80109A74)($s0)
    /* 6618 80108E18 2C956324 */  addiu      $v1, $v1, %lo(_menuText)
    /* 661C 80108E1C 0F004224 */  addiu      $v0, $v0, 0xF
    /* 6620 80108E20 40100200 */  sll        $v0, $v0, 1
    /* 6624 80108E24 21104300 */  addu       $v0, $v0, $v1
    /* 6628 80108E28 00004294 */  lhu        $v0, 0x0($v0)
    /* 662C 80108E2C 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 6630 80108E30 40100200 */  sll        $v0, $v0, 1
    /* 6634 80108E34 21104300 */  addu       $v0, $v0, $v1
    /* 6638 80108E38 9723030C */  jal        vs_battle_setMenuItem
    /* 663C 80108E3C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 6640 80108E40 01000324 */  addiu      $v1, $zero, 0x1
    /* 6644 80108E44 060043A0 */  sb         $v1, 0x6($v0)
    /* 6648 80108E48 04000224 */  addiu      $v0, $zero, 0x4
    /* 664C 80108E4C F0230408 */  j          .L80108FC0
    /* 6650 80108E50 000062A2 */   sb        $v0, 0x0($s3)
    /* 6654 80108E54 74EA030C */  jal        vs_mainmenu_ready
    /* 6658 80108E58 00000000 */   nop
    /* 665C 80108E5C 58004010 */  beqz       $v0, .L80108FC0
    /* 6660 80108E60 1180023C */   lui       $v0, %hi(D_80109A74)
    /* 6664 80108E64 749A448C */  lw         $a0, %lo(D_80109A74)($v0)
    /* 6668 80108E68 241D040C */  jal        func_80107490
    /* 666C 80108E6C 00000000 */   nop
    /* 6670 80108E70 05000224 */  addiu      $v0, $zero, 0x5
    /* 6674 80108E74 F0230408 */  j          .L80108FC0
    /* 6678 80108E78 000062A2 */   sb        $v0, 0x0($s3)
    /* 667C 80108E7C 241D040C */  jal        func_80107490
    /* 6680 80108E80 21200000 */   addu      $a0, $zero, $zero
    /* 6684 80108E84 1180103C */  lui        $s0, %hi(D_80109A74)
    /* 6688 80108E88 4D004010 */  beqz       $v0, .L80108FC0
    /* 668C 80108E8C 749A02AE */   sw        $v0, %lo(D_80109A74)($s0)
    /* 6690 80108E90 540F040C */  jal        func_80103D50
    /* 6694 80108E94 21200000 */   addu      $a0, $zero, $zero
    /* 6698 80108E98 749A038E */  lw         $v1, %lo(D_80109A74)($s0)
    /* 669C 80108E9C FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 66A0 80108EA0 04006214 */  bne        $v1, $v0, .L80108EB4
    /* 66A4 80108EA4 21200000 */   addu      $a0, $zero, $zero
    /* 66A8 80108EA8 06000224 */  addiu      $v0, $zero, 0x6
  .L80108EAC:
    /* 66AC 80108EAC F0230408 */  j          .L80108FC0
    /* 66B0 80108EB0 000062A2 */   sb        $v0, 0x0($s3)
  .L80108EB4:
    /* 66B4 80108EB4 B4000524 */  addiu      $a1, $zero, 0xB4
    /* 66B8 80108EB8 12000624 */  addiu      $a2, $zero, 0x12
    /* 66BC 80108EBC 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 66C0 80108EC0 08000224 */  addiu      $v0, $zero, 0x8
    /* 66C4 80108EC4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 66C8 80108EC8 1180023C */  lui        $v0, %hi(D_80109572)
    /* 66CC 80108ECC 72954224 */  addiu      $v0, $v0, %lo(D_80109572)
    /* 66D0 80108ED0 9723030C */  jal        vs_battle_setMenuItem
    /* 66D4 80108ED4 1400A2AF */   sw        $v0, 0x14($sp)
    /* 66D8 80108ED8 01000324 */  addiu      $v1, $zero, 0x1
    /* 66DC 80108EDC 060043A0 */  sb         $v1, 0x6($v0)
    /* 66E0 80108EE0 1180033C */  lui        $v1, %hi(D_80109A78)
    /* 66E4 80108EE4 05000224 */  addiu      $v0, $zero, 0x5
    /* 66E8 80108EE8 789A62A0 */  sb         $v0, %lo(D_80109A78)($v1)
    /* 66EC 80108EEC 02000224 */  addiu      $v0, $zero, 0x2
    /* 66F0 80108EF0 F0230408 */  j          .L80108FC0
    /* 66F4 80108EF4 000062A2 */   sb        $v0, 0x0($s3)
    /* 66F8 80108EF8 A5F9030C */  jal        vs_mainMenu_ensureItemNamesLoaded
    /* 66FC 80108EFC 00000000 */   nop
    /* 6700 80108F00 30004010 */  beqz       $v0, .L80108FC4
    /* 6704 80108F04 1180023C */   lui       $v0, %hi(D_80109A7B)
    /* 6708 80108F08 C80E040C */  jal        _copyContainerToInventory
    /* 670C 80108F0C 21900000 */   addu      $s2, $zero, $zero
    /* 6710 80108F10 1080113C */  lui        $s1, %hi(vs_menu_inventoryStorage)
    /* 6714 80108F14 30C41034 */  ori        $s0, $zero, 0xC430
    /* 6718 80108F18 21204002 */  addu       $a0, $s2, $zero
  .L80108F1C:
    /* 671C 80108F1C 5C24258E */  lw         $a1, %lo(vs_menu_inventoryStorage)($s1)
    /* 6720 80108F20 01005226 */  addiu      $s2, $s2, 0x1
    /* 6724 80108F24 F60D040C */  jal        _defragmentContainerItems
    /* 6728 80108F28 2128B000 */   addu      $a1, $a1, $s0
    /* 672C 80108F2C 0700422A */  slti       $v0, $s2, 0x7
    /* 6730 80108F30 FAFF4014 */  bnez       $v0, .L80108F1C
    /* 6734 80108F34 21204002 */   addu      $a0, $s2, $zero
    /* 6738 80108F38 21900000 */  addu       $s2, $zero, $zero
    /* 673C 80108F3C 1080113C */  lui        $s1, %hi(vs_menu_inventoryStorage)
    /* 6740 80108F40 30C41034 */  ori        $s0, $zero, 0xC430
  .L80108F44:
    /* 6744 80108F44 5C24258E */  lw         $a1, %lo(vs_menu_inventoryStorage)($s1)
    /* 6748 80108F48 21204002 */  addu       $a0, $s2, $zero
    /* 674C 80108F4C 1C0C040C */  jal        _countContainerItems
    /* 6750 80108F50 2128B000 */   addu      $a1, $a1, $s0
    /* 6754 80108F54 05004014 */  bnez       $v0, .L80108F6C
    /* 6758 80108F58 21200000 */   addu      $a0, $zero, $zero
    /* 675C 80108F5C 01005226 */  addiu      $s2, $s2, 0x1
    /* 6760 80108F60 0700422A */  slti       $v0, $s2, 0x7
    /* 6764 80108F64 F7FF4014 */  bnez       $v0, .L80108F44
    /* 6768 80108F68 00000000 */   nop
  .L80108F6C:
    /* 676C 80108F6C 0680053C */  lui        $a1, %hi(vs_main_settings)
    /* 6770 80108F70 2000A38C */  lw         $v1, %lo(vs_main_settings)($a1)
    /* 6774 80108F74 EFFF0224 */  addiu      $v0, $zero, -0x11
    /* 6778 80108F78 24186200 */  and        $v1, $v1, $v0
    /* 677C 80108F7C 0700423A */  xori       $v0, $s2, 0x7
    /* 6780 80108F80 0100422C */  sltiu      $v0, $v0, 0x1
    /* 6784 80108F84 00110200 */  sll        $v0, $v0, 4
    /* 6788 80108F88 25186200 */  or         $v1, $v1, $v0
    /* 678C 80108F8C 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 6790 80108F90 2000A3AC */   sw        $v1, %lo(vs_main_settings)($a1)
    /* 6794 80108F94 0F80053C */  lui        $a1, %hi(vs_battle_menuState)
    /* 6798 80108F98 C051A624 */  addiu      $a2, $a1, %lo(vs_battle_menuState)
    /* 679C 80108F9C 1180023C */  lui        $v0, %hi(D_80109A74)
    /* 67A0 80108FA0 749A4390 */  lbu        $v1, %lo(D_80109A74)($v0)
    /* 67A4 80108FA4 21100000 */  addu       $v0, $zero, $zero
    /* 67A8 80108FA8 0100C490 */  lbu        $a0, 0x1($a2)
    /* 67AC 80108FAC 02006324 */  addiu      $v1, $v1, 0x2
    /* 67B0 80108FB0 C051A4A0 */  sb         $a0, %lo(vs_battle_menuState)($a1)
    /* 67B4 80108FB4 0100C3A0 */  sb         $v1, 0x1($a2)
    /* 67B8 80108FB8 40250408 */  j          .L80109500
    /* 67BC 80108FBC 000060A2 */   sb        $zero, 0x0($s3)
  .L80108FC0:
    /* 67C0 80108FC0 1180023C */  lui        $v0, %hi(D_80109A7B)
  .L80108FC4:
    /* 67C4 80108FC4 7B9A4290 */  lbu        $v0, %lo(D_80109A7B)($v0)
    /* 67C8 80108FC8 00000000 */  nop
    /* 67CC 80108FCC 10004010 */  beqz       $v0, .L80109010
    /* 67D0 80108FD0 1180043C */   lui       $a0, %hi(D_80109A7E)
    /* 67D4 80108FD4 7E9A8390 */  lbu        $v1, %lo(D_80109A7E)($a0)
    /* 67D8 80108FD8 00000000 */  nop
    /* 67DC 80108FDC 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 67E0 80108FE0 02004010 */  beqz       $v0, .L80108FEC
    /* 67E4 80108FE4 01006224 */   addiu     $v0, $v1, 0x1
    /* 67E8 80108FE8 7E9A82A0 */  sb         $v0, %lo(D_80109A7E)($a0)
  .L80108FEC:
    /* 67EC 80108FEC 0F80023C */  lui        $v0, %hi(vs_battle_rowAnimationSteps)
    /* 67F0 80108FF0 C8BB4224 */  addiu      $v0, $v0, %lo(vs_battle_rowAnimationSteps)
    /* 67F4 80108FF4 7E9A8490 */  lbu        $a0, %lo(D_80109A7E)($a0)
    /* 67F8 80108FF8 0A000324 */  addiu      $v1, $zero, 0xA
    /* 67FC 80108FFC 23186400 */  subu       $v1, $v1, $a0
    /* 6800 80109000 21186200 */  addu       $v1, $v1, $v0
    /* 6804 80109004 00007290 */  lbu        $s2, 0x0($v1)
    /* 6808 80109008 0F240408 */  j          .L8010903C
    /* 680C 8010900C 1180023C */   lui       $v0, %hi(D_80109A7E)
  .L80109010:
    /* 6810 80109010 1180033C */  lui        $v1, %hi(D_80109A7E)
    /* 6814 80109014 7E9A6290 */  lbu        $v0, %lo(D_80109A7E)($v1)
    /* 6818 80109018 00000000 */  nop
    /* 681C 8010901C 02004010 */  beqz       $v0, .L80109028
    /* 6820 80109020 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6824 80109024 7E9A62A0 */  sb         $v0, %lo(D_80109A7E)($v1)
  .L80109028:
    /* 6828 80109028 7E9A6390 */  lbu        $v1, %lo(D_80109A7E)($v1)
    /* 682C 8010902C 0A000224 */  addiu      $v0, $zero, 0xA
    /* 6830 80109030 23104300 */  subu       $v0, $v0, $v1
    /* 6834 80109034 40910200 */  sll        $s2, $v0, 5
    /* 6838 80109038 1180023C */  lui        $v0, %hi(D_80109A7E)
  .L8010903C:
    /* 683C 8010903C 7E9A4290 */  lbu        $v0, %lo(D_80109A7E)($v0)
    /* 6840 80109040 00000000 */  nop
    /* 6844 80109044 4F004010 */  beqz       $v0, .L80109184
    /* 6848 80109048 1180023C */   lui       $v0, %hi(D_80109A81)
    /* 684C 8010904C 819A4290 */  lbu        $v0, %lo(D_80109A81)($v0)
    /* 6850 80109050 00000000 */  nop
    /* 6854 80109054 4C004014 */  bnez       $v0, .L80109188
    /* 6858 80109058 1180023C */   lui       $v0, %hi(D_80109A7C)
    /* 685C 8010905C 00006392 */  lbu        $v1, 0x0($s3)
    /* 6860 80109060 06000224 */  addiu      $v0, $zero, 0x6
    /* 6864 80109064 47006210 */  beq        $v1, $v0, .L80109184
    /* 6868 80109068 21380000 */   addu      $a3, $zero, $zero
    /* 686C 8010906C 0F80023C */  lui        $v0, %hi(D_800F4EE8 + 0xA0)
    /* 6870 80109070 08000324 */  addiu      $v1, $zero, 0x8
    /* 6874 80109074 B4004526 */  addiu      $a1, $s2, 0xB4
    /* 6878 80109078 884F4290 */  lbu        $v0, %lo(D_800F4EE8 + 0xA0)($v0)
    /* 687C 8010907C 07001224 */  addiu      $s2, $zero, 0x7
    /* 6880 80109080 1000A3AF */  sw         $v1, 0x10($sp)
    /* 6884 80109084 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6888 80109088 07005130 */  andi       $s1, $v0, 0x7
    /* 688C 8010908C 1180023C */  lui        $v0, %hi(_menuText)
    /* 6890 80109090 05003216 */  bne        $s1, $s2, .L801090A8
    /* 6894 80109094 2C954324 */   addiu     $v1, $v0, %lo(_menuText)
    /* 6898 80109098 1180023C */  lui        $v0, %hi(D_80109A7A)
    /* 689C 8010909C 7A9A4290 */  lbu        $v0, %lo(D_80109A7A)($v0)
    /* 68A0 801090A0 00000000 */  nop
    /* 68A4 801090A4 2B38E200 */  sltu       $a3, $a3, $v0
  .L801090A8:
    /* 68A8 801090A8 1F000424 */  addiu      $a0, $zero, 0x1F
    /* 68AC 801090AC 22000624 */  addiu      $a2, $zero, 0x22
    /* 68B0 801090B0 1200E224 */  addiu      $v0, $a3, 0x12
    /* 68B4 801090B4 21102202 */  addu       $v0, $s1, $v0
    /* 68B8 801090B8 40100200 */  sll        $v0, $v0, 1
    /* 68BC 801090BC 21104300 */  addu       $v0, $v0, $v1
    /* 68C0 801090C0 00004294 */  lhu        $v0, 0x0($v0)
    /* 68C4 801090C4 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 68C8 801090C8 40100200 */  sll        $v0, $v0, 1
    /* 68CC 801090CC 21104300 */  addu       $v0, $v0, $v1
    /* 68D0 801090D0 9723030C */  jal        vs_battle_setMenuItem
    /* 68D4 801090D4 1400A2AF */   sw        $v0, 0x14($sp)
    /* 68D8 801090D8 21804000 */  addu       $s0, $v0, $zero
    /* 68DC 801090DC 01000224 */  addiu      $v0, $zero, 0x1
    /* 68E0 801090E0 13003216 */  bne        $s1, $s2, .L80109130
    /* 68E4 801090E4 060002A2 */   sb        $v0, 0x6($s0)
    /* 68E8 801090E8 21900000 */  addu       $s2, $zero, $zero
    /* 68EC 801090EC 00800434 */  ori        $a0, $zero, 0x8000
    /* 68F0 801090F0 1080023C */  lui        $v0, %hi(vs_menu_inventoryStorage)
    /* 68F4 801090F4 5C24438C */  lw         $v1, %lo(vs_menu_inventoryStorage)($v0)
  .L801090F8:
    /* 68F8 801090F8 00000000 */  nop
    /* 68FC 801090FC 21106400 */  addu       $v0, $v1, $a0
    /* 6900 80109100 B0434294 */  lhu        $v0, 0x43B0($v0)
    /* 6904 80109104 00000000 */  nop
    /* 6908 80109108 06004010 */  beqz       $v0, .L80109124
    /* 690C 8010910C 40000224 */   addiu     $v0, $zero, 0x40
    /* 6910 80109110 01005226 */  addiu      $s2, $s2, 0x1
    /* 6914 80109114 4000422A */  slti       $v0, $s2, 0x40
    /* 6918 80109118 F7FF4014 */  bnez       $v0, .L801090F8
    /* 691C 8010911C 02006324 */   addiu     $v1, $v1, 0x2
    /* 6920 80109120 40000224 */  addiu      $v0, $zero, 0x40
  .L80109124:
    /* 6924 80109124 120002A6 */  sh         $v0, 0x12($s0)
    /* 6928 80109128 61240408 */  j          .L80109184
    /* 692C 8010912C 100012A6 */   sh        $s2, 0x10($s0)
  .L80109130:
    /* 6930 80109130 1180023C */  lui        $v0, %hi(D_80109A7A)
    /* 6934 80109134 7A9A4290 */  lbu        $v0, %lo(D_80109A7A)($v0)
    /* 6938 80109138 00000000 */  nop
    /* 693C 8010913C 06004010 */  beqz       $v0, .L80109158
    /* 6940 80109140 1080023C */   lui       $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 6944 80109144 A0224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 6948 80109148 21102202 */  addu       $v0, $s1, $v0
    /* 694C 8010914C 00004390 */  lbu        $v1, 0x0($v0)
    /* 6950 80109150 5C240408 */  j          .L80109170
    /* 6954 80109154 1180023C */   lui       $v0, %hi(vs_menuD_containerData)
  .L80109158:
    /* 6958 80109158 1180033C */  lui        $v1, %hi(_containerItemCapacities)
    /* 695C 8010915C 44996324 */  addiu      $v1, $v1, %lo(_containerItemCapacities)
    /* 6960 80109160 40101100 */  sll        $v0, $s1, 1
    /* 6964 80109164 21104300 */  addu       $v0, $v0, $v1
    /* 6968 80109168 00004394 */  lhu        $v1, 0x0($v0)
    /* 696C 8010916C 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
  .L80109170:
    /* 6970 80109170 8C9A458C */  lw         $a1, %lo(vs_menuD_containerData)($v0)
    /* 6974 80109174 21202002 */  addu       $a0, $s1, $zero
    /* 6978 80109178 1C0C040C */  jal        _countContainerItems
    /* 697C 8010917C 120003A6 */   sh        $v1, 0x12($s0)
    /* 6980 80109180 100002A6 */  sh         $v0, 0x10($s0)
  .L80109184:
    /* 6984 80109184 1180023C */  lui        $v0, %hi(D_80109A7C)
  .L80109188:
    /* 6988 80109188 7C9A4290 */  lbu        $v0, %lo(D_80109A7C)($v0)
    /* 698C 8010918C 00000000 */  nop
    /* 6990 80109190 08004010 */  beqz       $v0, .L801091B4
    /* 6994 80109194 1180043C */   lui       $a0, %hi(D_80109A7F)
    /* 6998 80109198 7F9A8390 */  lbu        $v1, %lo(D_80109A7F)($a0)
    /* 699C 8010919C 00000000 */  nop
    /* 69A0 801091A0 0400622C */  sltiu      $v0, $v1, 0x4
    /* 69A4 801091A4 09004010 */  beqz       $v0, .L801091CC
    /* 69A8 801091A8 01006224 */   addiu     $v0, $v1, 0x1
    /* 69AC 801091AC 73240408 */  j          .L801091CC
    /* 69B0 801091B0 7F9A82A0 */   sb        $v0, %lo(D_80109A7F)($a0)
  .L801091B4:
    /* 69B4 801091B4 1180033C */  lui        $v1, %hi(D_80109A7F)
    /* 69B8 801091B8 7F9A6290 */  lbu        $v0, %lo(D_80109A7F)($v1)
    /* 69BC 801091BC 00000000 */  nop
    /* 69C0 801091C0 02004010 */  beqz       $v0, .L801091CC
    /* 69C4 801091C4 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 69C8 801091C8 7F9A62A0 */  sb         $v0, %lo(D_80109A7F)($v1)
  .L801091CC:
    /* 69CC 801091CC 1180023C */  lui        $v0, %hi(D_80109A7F)
    /* 69D0 801091D0 7F9A4490 */  lbu        $a0, %lo(D_80109A7F)($v0)
    /* 69D4 801091D4 1180023C */  lui        $v0, %hi(D_80109A81)
    /* 69D8 801091D8 819A4590 */  lbu        $a1, %lo(D_80109A81)($v0)
    /* 69DC 801091DC 890F040C */  jal        func_80103E24
    /* 69E0 801091E0 00000000 */   nop
    /* 69E4 801091E4 1180023C */  lui        $v0, %hi(D_80109A7D)
    /* 69E8 801091E8 7D9A4290 */  lbu        $v0, %lo(D_80109A7D)($v0)
    /* 69EC 801091EC 00000000 */  nop
    /* 69F0 801091F0 16004010 */  beqz       $v0, .L8010924C
    /* 69F4 801091F4 1180103C */   lui       $s0, %hi(D_80109A80)
    /* 69F8 801091F8 809A0292 */  lbu        $v0, %lo(D_80109A80)($s0)
    /* 69FC 801091FC 00000000 */  nop
    /* 6A00 80109200 03004014 */  bnez       $v0, .L80109210
    /* 6A04 80109204 00000000 */   nop
    /* 6A08 80109208 9C0C040C */  jal        func_80103270
    /* 6A0C 8010920C 00000000 */   nop
  .L80109210:
    /* 6A10 80109210 809A0392 */  lbu        $v1, %lo(D_80109A80)($s0)
    /* 6A14 80109214 00000000 */  nop
    /* 6A18 80109218 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 6A1C 8010921C 02004010 */  beqz       $v0, .L80109228
    /* 6A20 80109220 01006224 */   addiu     $v0, $v1, 0x1
    /* 6A24 80109224 809A02A2 */  sb         $v0, %lo(D_80109A80)($s0)
  .L80109228:
    /* 6A28 80109228 0F80023C */  lui        $v0, %hi(vs_battle_rowAnimationSteps)
    /* 6A2C 8010922C C8BB4224 */  addiu      $v0, $v0, %lo(vs_battle_rowAnimationSteps)
    /* 6A30 80109230 809A0492 */  lbu        $a0, %lo(D_80109A80)($s0)
    /* 6A34 80109234 0A000324 */  addiu      $v1, $zero, 0xA
    /* 6A38 80109238 23186400 */  subu       $v1, $v1, $a0
    /* 6A3C 8010923C 21186200 */  addu       $v1, $v1, $v0
    /* 6A40 80109240 00007290 */  lbu        $s2, 0x0($v1)
    /* 6A44 80109244 9E240408 */  j          .L80109278
    /* 6A48 80109248 1180023C */   lui       $v0, %hi(D_80109A80)
  .L8010924C:
    /* 6A4C 8010924C 1180033C */  lui        $v1, %hi(D_80109A80)
    /* 6A50 80109250 809A6290 */  lbu        $v0, %lo(D_80109A80)($v1)
    /* 6A54 80109254 00000000 */  nop
    /* 6A58 80109258 02004010 */  beqz       $v0, .L80109264
    /* 6A5C 8010925C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6A60 80109260 809A62A0 */  sb         $v0, %lo(D_80109A80)($v1)
  .L80109264:
    /* 6A64 80109264 809A6390 */  lbu        $v1, %lo(D_80109A80)($v1)
    /* 6A68 80109268 0A000224 */  addiu      $v0, $zero, 0xA
    /* 6A6C 8010926C 23104300 */  subu       $v0, $v0, $v1
    /* 6A70 80109270 40910200 */  sll        $s2, $v0, 5
    /* 6A74 80109274 1180023C */  lui        $v0, %hi(D_80109A80)
  .L80109278:
    /* 6A78 80109278 809A4290 */  lbu        $v0, %lo(D_80109A80)($v0)
    /* 6A7C 8010927C 00000000 */  nop
    /* 6A80 80109280 9E004010 */  beqz       $v0, .L801094FC
    /* 6A84 80109284 10000224 */   addiu     $v0, $zero, 0x10
    /* 6A88 80109288 23905200 */  subu       $s2, $v0, $s2
    /* 6A8C 8010928C 21204002 */  addu       $a0, $s2, $zero
    /* 6A90 80109290 26000524 */  addiu      $a1, $zero, 0x26
    /* 6A94 80109294 90000624 */  addiu      $a2, $zero, 0x90
    /* 6A98 80109298 D100040C */  jal        vs_mainMenu_drawButtonUiBackground
    /* 6A9C 8010929C 0A000724 */   addiu     $a3, $zero, 0xA
    /* 6AA0 801092A0 21204002 */  addu       $a0, $s2, $zero
    /* 6AA4 801092A4 36000524 */  addiu      $a1, $zero, 0x36
    /* 6AA8 801092A8 48000624 */  addiu      $a2, $zero, 0x48
    /* 6AAC 801092AC D100040C */  jal        vs_mainMenu_drawButtonUiBackground
    /* 6AB0 801092B0 0A000724 */   addiu     $a3, $zero, 0xA
    /* 6AB4 801092B4 01000424 */  addiu      $a0, $zero, 0x1
    /* 6AB8 801092B8 F8FF5026 */  addiu      $s0, $s2, -0x8
    /* 6ABC 801092BC 21280002 */  addu       $a1, $s0, $zero
    /* 6AC0 801092C0 24000624 */  addiu      $a2, $zero, 0x24
    /* 6AC4 801092C4 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 6AC8 801092C8 21380000 */   addu      $a3, $zero, $zero
    /* 6ACC 801092CC 21200000 */  addu       $a0, $zero, $zero
    /* 6AD0 801092D0 40004526 */  addiu      $a1, $s2, 0x40
    /* 6AD4 801092D4 24000624 */  addiu      $a2, $zero, 0x24
    /* 6AD8 801092D8 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 6ADC 801092DC 21388000 */   addu      $a3, $a0, $zero
    /* 6AE0 801092E0 03000424 */  addiu      $a0, $zero, 0x3
    /* 6AE4 801092E4 21280002 */  addu       $a1, $s0, $zero
    /* 6AE8 801092E8 34000624 */  addiu      $a2, $zero, 0x34
    /* 6AEC 801092EC 1AFF030C */  jal        vs_mainmenu_drawButton
    /* 6AF0 801092F0 21380000 */   addu      $a3, $zero, $zero
    /* 6AF4 801092F4 0C004226 */  addiu      $v0, $s2, 0xC
    /* 6AF8 801092F8 FFFF5330 */  andi       $s3, $v0, 0xFFFF
    /* 6AFC 801092FC 2000023C */  lui        $v0, (0x202020 >> 16)
    /* 6B00 80109300 20204234 */  ori        $v0, $v0, (0x202020 & 0xFFFF)
    /* 6B04 80109304 1080043C */  lui        $a0, %hi(D_80102A00)
    /* 6B08 80109308 002A8424 */  addiu      $a0, $a0, %lo(D_80102A00)
    /* 6B0C 8010930C 2600113C */  lui        $s1, (0x260000 >> 16)
    /* 6B10 80109310 25287102 */  or         $a1, $s3, $s1
    /* 6B14 80109314 1180103C */  lui        $s0, %hi(D_80109A7D)
    /* 6B18 80109318 7D9A0692 */  lbu        $a2, %lo(D_80109A7D)($s0)
    /* 6B1C 8010931C 21380000 */  addu       $a3, $zero, $zero
    /* 6B20 80109320 0300C630 */  andi       $a2, $a2, 0x3
    /* 6B24 80109324 5019030C */  jal        vs_battle_renderTextRawColor
    /* 6B28 80109328 0430C200 */   sllv      $a2, $v0, $a2
    /* 6B2C 8010932C 1080043C */  lui        $a0, %hi(D_80102A08)
    /* 6B30 80109330 082A8424 */  addiu      $a0, $a0, %lo(D_80102A08)
    /* 6B34 80109334 48006526 */  addiu      $a1, $s3, 0x48
    /* 6B38 80109338 2528B100 */  or         $a1, $a1, $s1
    /* 6B3C 8010933C 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 6B40 80109340 21300000 */   addu      $a2, $zero, $zero
    /* 6B44 80109344 8000023C */  lui        $v0, (0x808080 >> 16)
    /* 6B48 80109348 80804234 */  ori        $v0, $v0, (0x808080 & 0xFFFF)
    /* 6B4C 8010934C 1080043C */  lui        $a0, %hi(D_80102A10)
    /* 6B50 80109350 102A8424 */  addiu      $a0, $a0, %lo(D_80102A10)
    /* 6B54 80109354 3600053C */  lui        $a1, (0x360000 >> 16)
    /* 6B58 80109358 25286502 */  or         $a1, $s3, $a1
    /* 6B5C 8010935C 7D9A0692 */  lbu        $a2, %lo(D_80109A7D)($s0)
    /* 6B60 80109360 21380000 */  addu       $a3, $zero, $zero
    /* 6B64 80109364 82300600 */  srl        $a2, $a2, 2
    /* 6B68 80109368 5019030C */  jal        vs_battle_renderTextRawColor
    /* 6B6C 8010936C 0730C200 */   srav      $a2, $v0, $a2
    /* 6B70 80109370 7D9A0292 */  lbu        $v0, %lo(D_80109A7D)($s0)
    /* 6B74 80109374 00000000 */  nop
    /* 6B78 80109378 82100200 */  srl        $v0, $v0, 2
    /* 6B7C 8010937C 0B004010 */  beqz       $v0, .L801093AC
    /* 6B80 80109380 1180043C */   lui       $a0, %hi(D_80109A79)
    /* 6B84 80109384 799A8390 */  lbu        $v1, %lo(D_80109A79)($a0)
    /* 6B88 80109388 00000000 */  nop
    /* 6B8C 8010938C 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 6B90 80109390 03004010 */  beqz       $v0, .L801093A0
    /* 6B94 80109394 00000000 */   nop
    /* 6B98 80109398 01006224 */  addiu      $v0, $v1, 0x1
    /* 6B9C 8010939C 799A82A0 */  sb         $v0, %lo(D_80109A79)($a0)
  .L801093A0:
    /* 6BA0 801093A0 799A8290 */  lbu        $v0, %lo(D_80109A79)($a0)
    /* 6BA4 801093A4 F6240408 */  j          .L801093D8
    /* 6BA8 801093A8 40110200 */   sll       $v0, $v0, 5
  .L801093AC:
    /* 6BAC 801093AC 1180033C */  lui        $v1, %hi(D_80109A79)
    /* 6BB0 801093B0 799A6290 */  lbu        $v0, %lo(D_80109A79)($v1)
    /* 6BB4 801093B4 00000000 */  nop
    /* 6BB8 801093B8 02004010 */  beqz       $v0, .L801093C4
    /* 6BBC 801093BC FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6BC0 801093C0 799A62A0 */  sb         $v0, %lo(D_80109A79)($v1)
  .L801093C4:
    /* 6BC4 801093C4 0F80023C */  lui        $v0, %hi(vs_battle_rowAnimationSteps)
    /* 6BC8 801093C8 799A6390 */  lbu        $v1, %lo(D_80109A79)($v1)
    /* 6BCC 801093CC C8BB4224 */  addiu      $v0, $v0, %lo(vs_battle_rowAnimationSteps)
    /* 6BD0 801093D0 21186200 */  addu       $v1, $v1, $v0
    /* 6BD4 801093D4 00006290 */  lbu        $v0, 0x0($v1)
  .L801093D8:
    /* 6BD8 801093D8 00000000 */  nop
    /* 6BDC 801093DC 23904202 */  subu       $s2, $s2, $v0
    /* 6BE0 801093E0 4C00053C */  lui        $a1, (0x4C0000 >> 16)
    /* 6BE4 801093E4 21284502 */  addu       $a1, $s2, $a1
    /* 6BE8 801093E8 21300000 */  addu       $a2, $zero, $zero
    /* 6BEC 801093EC 2198C000 */  addu       $s3, $a2, $zero
    /* 6BF0 801093F0 5800163C */  lui        $s6, (0x580070 >> 16)
    /* 6BF4 801093F4 7000D636 */  ori        $s6, $s6, (0x580070 & 0xFFFF)
    /* 6BF8 801093F8 5800153C */  lui        $s5, (0x580008 >> 16)
    /* 6BFC 801093FC 1180033C */  lui        $v1, %hi(D_80109A08)
    /* 6C00 80109400 1180023C */  lui        $v0, %hi(D_80109A7A)
    /* 6C04 80109404 7A9A4290 */  lbu        $v0, %lo(D_80109A7A)($v0)
    /* 6C08 80109408 089A6324 */  addiu      $v1, $v1, %lo(D_80109A08)
    /* 6C0C 8010940C 80100200 */  sll        $v0, $v0, 2
    /* 6C10 80109410 21104300 */  addu       $v0, $v0, $v1
    /* 6C14 80109414 0000448C */  lw         $a0, 0x0($v0)
    /* 6C18 80109418 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 6C1C 8010941C 0800B536 */   ori       $s5, $s5, (0x580008 & 0xFFFF)
    /* 6C20 80109420 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryItemCapacities)
    /* 6C24 80109424 A0225724 */  addiu      $s7, $v0, %lo(vs_mainMenu_inventoryItemCapacities)
    /* 6C28 80109428 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 6C2C 8010942C 44995424 */  addiu      $s4, $v0, %lo(_containerItemCapacities)
    /* 6C30 80109430 1180023C */  lui        $v0, %hi(D_80109A10)
    /* 6C34 80109434 109A5124 */  addiu      $s1, $v0, %lo(D_80109A10)
  .L80109438:
    /* 6C38 80109438 21285502 */  addu       $a1, $s2, $s5
    /* 6C3C 8010943C 0000248E */  lw         $a0, 0x0($s1)
    /* 6C40 80109440 21300000 */  addu       $a2, $zero, $zero
    /* 6C44 80109444 0A1A030C */  jal        vs_battle_renderTextRaw
    /* 6C48 80109448 01008424 */   addiu     $a0, $a0, 0x1
    /* 6C4C 8010944C 06000224 */  addiu      $v0, $zero, 0x6
    /* 6C50 80109450 1E006212 */  beq        $s3, $v0, .L801094CC
    /* 6C54 80109454 1180023C */   lui       $v0, %hi(D_80109A88)
    /* 6C58 80109458 889A458C */  lw         $a1, %lo(D_80109A88)($v0)
    /* 6C5C 8010945C 1C0C040C */  jal        _countContainerItems
    /* 6C60 80109460 21206002 */   addu      $a0, $s3, $zero
    /* 6C64 80109464 21206002 */  addu       $a0, $s3, $zero
    /* 6C68 80109468 1080033C */  lui        $v1, %hi(vs_menu_inventoryStorage)
    /* 6C6C 8010946C B0870534 */  ori        $a1, $zero, 0x87B0
    /* 6C70 80109470 5C24638C */  lw         $v1, %lo(vs_menu_inventoryStorage)($v1)
    /* 6C74 80109474 21804000 */  addu       $s0, $v0, $zero
    /* 6C78 80109478 1C0C040C */  jal        _countContainerItems
    /* 6C7C 8010947C 21286500 */   addu      $a1, $v1, $a1
    /* 6C80 80109480 1180033C */  lui        $v1, %hi(D_80109A7A)
    /* 6C84 80109484 7A9A6390 */  lbu        $v1, %lo(D_80109A7A)($v1)
    /* 6C88 80109488 00000000 */  nop
    /* 6C8C 8010948C 04006010 */  beqz       $v1, .L801094A0
    /* 6C90 80109490 21300202 */   addu      $a2, $s0, $v0
    /* 6C94 80109494 00008496 */  lhu        $a0, 0x0($s4)
    /* 6C98 80109498 2A250408 */  j          .L801094A8
    /* 6C9C 8010949C 00000000 */   nop
  .L801094A0:
    /* 6CA0 801094A0 21107702 */  addu       $v0, $s3, $s7
    /* 6CA4 801094A4 00004490 */  lbu        $a0, 0x0($v0)
  .L801094A8:
    /* 6CA8 801094A8 1919040C */  jal        func_80106464
    /* 6CAC 801094AC 21285602 */   addu      $a1, $s2, $s6
    /* 6CB0 801094B0 0C00023C */  lui        $v0, (0xC0000 >> 16)
    /* 6CB4 801094B4 21B0C202 */  addu       $s6, $s6, $v0
    /* 6CB8 801094B8 02009426 */  addiu      $s4, $s4, 0x2
    /* 6CBC 801094BC 21A8A202 */  addu       $s5, $s5, $v0
    /* 6CC0 801094C0 04003126 */  addiu      $s1, $s1, 0x4
    /* 6CC4 801094C4 0E250408 */  j          .L80109438
    /* 6CC8 801094C8 01007326 */   addiu     $s3, $s3, 0x1
  .L801094CC:
    /* 6CCC 801094CC 1180023C */  lui        $v0, %hi(D_80109A7A)
    /* 6CD0 801094D0 7A9A4290 */  lbu        $v0, %lo(D_80109A7A)($v0)
    /* 6CD4 801094D4 00000000 */  nop
    /* 6CD8 801094D8 02004010 */  beqz       $v0, .L801094E4
    /* 6CDC 801094DC 40000424 */   addiu     $a0, $zero, 0x40
    /* 6CE0 801094E0 00010424 */  addiu      $a0, $zero, 0x100
  .L801094E4:
    /* 6CE4 801094E4 A000053C */  lui        $a1, (0xA00070 >> 16)
    /* 6CE8 801094E8 7000A534 */  ori        $a1, $a1, (0xA00070 & 0xFFFF)
    /* 6CEC 801094EC 1180023C */  lui        $v0, %hi(D_80109A82)
    /* 6CF0 801094F0 829A4694 */  lhu        $a2, %lo(D_80109A82)($v0)
    /* 6CF4 801094F4 1919040C */  jal        func_80106464
    /* 6CF8 801094F8 21284502 */   addu      $a1, $s2, $a1
  .L801094FC:
    /* 6CFC 801094FC 21100000 */  addu       $v0, $zero, $zero
  .L80109500:
    /* 6D00 80109500 3800BF8F */  lw         $ra, 0x38($sp)
    /* 6D04 80109504 3400B78F */  lw         $s7, 0x34($sp)
    /* 6D08 80109508 3000B68F */  lw         $s6, 0x30($sp)
    /* 6D0C 8010950C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 6D10 80109510 2800B48F */  lw         $s4, 0x28($sp)
    /* 6D14 80109514 2400B38F */  lw         $s3, 0x24($sp)
    /* 6D18 80109518 2000B28F */  lw         $s2, 0x20($sp)
    /* 6D1C 8010951C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6D20 80109520 1800B08F */  lw         $s0, 0x18($sp)
    /* 6D24 80109524 0800E003 */  jr         $ra
    /* 6D28 80109528 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80108C6C
