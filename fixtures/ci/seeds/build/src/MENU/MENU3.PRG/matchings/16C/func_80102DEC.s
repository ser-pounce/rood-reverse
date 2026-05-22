nonmatching func_80102DEC, 0x248

glabel func_80102DEC
    /* 5EC 80102DEC D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5F0 80102DF0 21288000 */  addu       $a1, $a0, $zero
    /* 5F4 80102DF4 2800BFAF */  sw         $ra, 0x28($sp)
    /* 5F8 80102DF8 2400B1AF */  sw         $s1, 0x24($sp)
    /* 5FC 80102DFC 1100A010 */  beqz       $a1, .L80102E44
    /* 600 80102E00 2000B0AF */   sw        $s0, 0x20($sp)
    /* 604 80102E04 1180033C */  lui        $v1, %hi(D_8010964E)
    /* 608 80102E08 03120500 */  sra        $v0, $a1, 8
    /* 60C 80102E0C 4E9662A0 */  sb         $v0, %lo(D_8010964E)($v1)
    /* 610 80102E10 FF004430 */  andi       $a0, $v0, 0xFF
    /* 614 80102E14 1180033C */  lui        $v1, %hi(D_8010964F)
    /* 618 80102E18 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 61C 80102E1C DE0A040C */  jal        func_80102B78
    /* 620 80102E20 4F9662A0 */   sb        $v0, %lo(D_8010964F)($v1)
    /* 624 80102E24 21100000 */  addu       $v0, $zero, $zero
    /* 628 80102E28 1180033C */  lui        $v1, %hi(D_80109650)
    /* 62C 80102E2C 509660A0 */  sb         $zero, %lo(D_80109650)($v1)
    /* 630 80102E30 1180033C */  lui        $v1, %hi(D_8010964D)
    /* 634 80102E34 4D9660A0 */  sb         $zero, %lo(D_8010964D)($v1)
    /* 638 80102E38 1180033C */  lui        $v1, %hi(D_8010964C)
    /* 63C 80102E3C 080C0408 */  j          .L80103020
    /* 640 80102E40 4C9660A0 */   sb        $zero, %lo(D_8010964C)($v1)
  .L80102E44:
    /* 644 80102E44 1180103C */  lui        $s0, %hi(D_8010964C)
    /* 648 80102E48 4C960392 */  lbu        $v1, %lo(D_8010964C)($s0)
    /* 64C 80102E4C 01001124 */  addiu      $s1, $zero, 0x1
    /* 650 80102E50 20007110 */  beq        $v1, $s1, .L80102ED4
    /* 654 80102E54 02006228 */   slti      $v0, $v1, 0x2
    /* 658 80102E58 05004010 */  beqz       $v0, .L80102E70
    /* 65C 80102E5C 02000224 */   addiu     $v0, $zero, 0x2
    /* 660 80102E60 09006010 */  beqz       $v1, .L80102E88
    /* 664 80102E64 21100000 */   addu      $v0, $zero, $zero
    /* 668 80102E68 080C0408 */  j          .L80103020
    /* 66C 80102E6C 00000000 */   nop
  .L80102E70:
    /* 670 80102E70 30006210 */  beq        $v1, $v0, .L80102F34
    /* 674 80102E74 03000224 */   addiu     $v0, $zero, 0x3
    /* 678 80102E78 64006210 */  beq        $v1, $v0, .L8010300C
    /* 67C 80102E7C 21100000 */   addu      $v0, $zero, $zero
    /* 680 80102E80 080C0408 */  j          .L80103020
    /* 684 80102E84 00000000 */   nop
  .L80102E88:
    /* 688 80102E88 74EA030C */  jal        vs_mainmenu_ready
    /* 68C 80102E8C 00000000 */   nop
    /* 690 80102E90 62004010 */  beqz       $v0, .L8010301C
    /* 694 80102E94 1180023C */   lui       $v0, %hi(D_8010964E)
    /* 698 80102E98 4E964490 */  lbu        $a0, %lo(D_8010964E)($v0)
    /* 69C 80102E9C 110B040C */  jal        func_80102C44
    /* 6A0 80102EA0 07000524 */   addiu     $a1, $zero, 0x7
    /* 6A4 80102EA4 0680033C */  lui        $v1, %hi(vs_main_inventoryIndices)
    /* 6A8 80102EA8 1180023C */  lui        $v0, %hi(D_8010964F)
    /* 6AC 80102EAC 4F964290 */  lbu        $v0, %lo(D_8010964F)($v0)
    /* 6B0 80102EB0 D8196324 */  addiu      $v1, $v1, %lo(vs_main_inventoryIndices)
    /* 6B4 80102EB4 21104300 */  addu       $v0, $v0, $v1
    /* 6B8 80102EB8 00004490 */  lbu        $a0, 0x0($v0)
    /* 6BC 80102EBC 9CF4030C */  jal        vs_mainMenu_setUiWeaponStats
    /* 6C0 80102EC0 00000000 */   nop
    /* 6C4 80102EC4 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 6C8 80102EC8 03000424 */   addiu     $a0, $zero, 0x3
    /* 6CC 80102ECC 070C0408 */  j          .L8010301C
    /* 6D0 80102ED0 4C9611A2 */   sb        $s1, %lo(D_8010964C)($s0)
  .L80102ED4:
    /* 6D4 80102ED4 1180043C */  lui        $a0, %hi(D_8010964D)
    /* 6D8 80102ED8 4D968390 */  lbu        $v1, %lo(D_8010964D)($a0)
    /* 6DC 80102EDC 00000000 */  nop
    /* 6E0 80102EE0 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 6E4 80102EE4 10004010 */  beqz       $v0, .L80102F28
    /* 6E8 80102EE8 01006224 */   addiu     $v0, $v1, 0x1
    /* 6EC 80102EEC 4D9682A0 */  sb         $v0, %lo(D_8010964D)($a0)
    /* 6F0 80102EF0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 6F4 80102EF4 0600422C */  sltiu      $v0, $v0, 0x6
    /* 6F8 80102EF8 48004010 */  beqz       $v0, .L8010301C
    /* 6FC 80102EFC 0680023C */   lui       $v0, %hi(vs_main_inventoryIndices)
    /* 700 80102F00 1180033C */  lui        $v1, %hi(D_8010964F)
    /* 704 80102F04 D8194224 */  addiu      $v0, $v0, %lo(vs_main_inventoryIndices)
    /* 708 80102F08 4F966390 */  lbu        $v1, %lo(D_8010964F)($v1)
    /* 70C 80102F0C 4D968490 */  lbu        $a0, %lo(D_8010964D)($a0)
    /* 710 80102F10 21186200 */  addu       $v1, $v1, $v0
    /* 714 80102F14 00006590 */  lbu        $a1, 0x0($v1)
    /* 718 80102F18 44F1030C */  jal        vs_mainMenu_initSetWeaponGemMenu
    /* 71C 80102F1C 01000624 */   addiu     $a2, $zero, 0x1
    /* 720 80102F20 080C0408 */  j          .L80103020
    /* 724 80102F24 21100000 */   addu      $v0, $zero, $zero
  .L80102F28:
    /* 728 80102F28 02000224 */  addiu      $v0, $zero, 0x2
    /* 72C 80102F2C 070C0408 */  j          .L8010301C
    /* 730 80102F30 4C9602A2 */   sb        $v0, %lo(D_8010964C)($s0)
  .L80102F34:
    /* 734 80102F34 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 738 80102F38 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 73C 80102F3C 00000000 */  nop
    /* 740 80102F40 50004230 */  andi       $v0, $v0, 0x50
    /* 744 80102F44 06004010 */  beqz       $v0, .L80102F60
    /* 748 80102F48 00000000 */   nop
    /* 74C 80102F4C 5F0B040C */  jal        func_80102D7C
    /* 750 80102F50 01000424 */   addiu     $a0, $zero, 0x1
    /* 754 80102F54 03000224 */  addiu      $v0, $zero, 0x3
    /* 758 80102F58 070C0408 */  j          .L8010301C
    /* 75C 80102F5C 4C9602A2 */   sb        $v0, %lo(D_8010964C)($s0)
  .L80102F60:
    /* 760 80102F60 1180103C */  lui        $s0, %hi(D_8010964F)
    /* 764 80102F64 4F960592 */  lbu        $a1, %lo(D_8010964F)($s0)
    /* 768 80102F68 620A040C */  jal        func_80102988
    /* 76C 80102F6C 21200000 */   addu      $a0, $zero, $zero
    /* 770 80102F70 4F960392 */  lbu        $v1, %lo(D_8010964F)($s0)
    /* 774 80102F74 21884000 */  addu       $s1, $v0, $zero
    /* 778 80102F78 28002312 */  beq        $s1, $v1, .L8010301C
    /* 77C 80102F7C 21200000 */   addu      $a0, $zero, $zero
    /* 780 80102F80 21282002 */  addu       $a1, $s1, $zero
    /* 784 80102F84 4C0B040C */  jal        func_80102D30
    /* 788 80102F88 4F9611A2 */   sb        $s1, %lo(D_8010964F)($s0)
    /* 78C 80102F8C 21804000 */  addu       $s0, $v0, $zero
    /* 790 80102F90 40111000 */  sll        $v0, $s0, 5
    /* 794 80102F94 0680043C */  lui        $a0, %hi(D_80060148)
    /* 798 80102F98 48018424 */  addiu      $a0, $a0, %lo(D_80060148)
    /* 79C 80102F9C 21204400 */  addu       $a0, $v0, $a0
    /* 7A0 80102FA0 1000A527 */  addiu      $a1, $sp, 0x10
    /* 7A4 80102FA4 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 7A8 80102FA8 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 7AC 80102FAC 82F2030C */  jal        vs_mainMenu_initUiWeapon
    /* 7B0 80102FB0 1800A627 */   addiu     $a2, $sp, 0x18
    /* 7B4 80102FB4 9CF4030C */  jal        vs_mainMenu_setUiWeaponStats
    /* 7B8 80102FB8 21200002 */   addu      $a0, $s0, $zero
    /* 7BC 80102FBC 1000A527 */  addiu      $a1, $sp, 0x10
    /* 7C0 80102FC0 21382002 */  addu       $a3, $s1, $zero
    /* 7C4 80102FC4 1180023C */  lui        $v0, %hi(D_8010964E)
    /* 7C8 80102FC8 4E964490 */  lbu        $a0, %lo(D_8010964E)($v0)
    /* 7CC 80102FCC 1800A68F */  lw         $a2, 0x18($sp)
    /* 7D0 80102FD0 250B040C */  jal        func_80102C94
    /* 7D4 80102FD4 01001024 */   addiu     $s0, $zero, 0x1
    /* 7D8 80102FD8 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* 7DC 80102FDC D8194224 */  addiu      $v0, $v0, %lo(vs_main_inventoryIndices)
    /* 7E0 80102FE0 21882202 */  addu       $s1, $s1, $v0
    /* 7E4 80102FE4 21200002 */  addu       $a0, $s0, $zero
  .L80102FE8:
    /* 7E8 80102FE8 00002592 */  lbu        $a1, 0x0($s1)
    /* 7EC 80102FEC 21300000 */  addu       $a2, $zero, $zero
    /* 7F0 80102FF0 44F1030C */  jal        vs_mainMenu_initSetWeaponGemMenu
    /* 7F4 80102FF4 01001026 */   addiu     $s0, $s0, 0x1
    /* 7F8 80102FF8 0600022A */  slti       $v0, $s0, 0x6
    /* 7FC 80102FFC FAFF4014 */  bnez       $v0, .L80102FE8
    /* 800 80103000 21200002 */   addu      $a0, $s0, $zero
    /* 804 80103004 080C0408 */  j          .L80103020
    /* 808 80103008 21100000 */   addu      $v0, $zero, $zero
  .L8010300C:
    /* 80C 8010300C 74EA030C */  jal        vs_mainmenu_ready
    /* 810 80103010 00000000 */   nop
    /* 814 80103014 080C0408 */  j          .L80103020
    /* 818 80103018 00000000 */   nop
  .L8010301C:
    /* 81C 8010301C 21100000 */  addu       $v0, $zero, $zero
  .L80103020:
    /* 820 80103020 2800BF8F */  lw         $ra, 0x28($sp)
    /* 824 80103024 2400B18F */  lw         $s1, 0x24($sp)
    /* 828 80103028 2000B08F */  lw         $s0, 0x20($sp)
    /* 82C 8010302C 0800E003 */  jr         $ra
    /* 830 80103030 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80102DEC
