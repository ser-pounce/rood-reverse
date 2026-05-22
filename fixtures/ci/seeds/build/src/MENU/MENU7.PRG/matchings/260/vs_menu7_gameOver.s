nonmatching vs_menu7_gameOver, 0x354

glabel vs_menu7_gameOver
    /* 64E8 80108CE8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 64EC 80108CEC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 64F0 80108CF0 21888000 */  addu       $s1, $a0, $zero
    /* 64F4 80108CF4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 64F8 80108CF8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 64FC 80108CFC 00002392 */  lbu        $v1, 0x0($s1)
    /* 6500 80108D00 00000000 */  nop
    /* 6504 80108D04 0800622C */  sltiu      $v0, $v1, 0x8
    /* 6508 80108D08 C3004010 */  beqz       $v0, .L80109018
    /* 650C 80108D0C 1080023C */   lui       $v0, %hi(jtbl_801029A8)
    /* 6510 80108D10 A8294224 */  addiu      $v0, $v0, %lo(jtbl_801029A8)
    /* 6514 80108D14 80180300 */  sll        $v1, $v1, 2
    /* 6518 80108D18 21186200 */  addu       $v1, $v1, $v0
    /* 651C 80108D1C 0000628C */  lw         $v0, 0x0($v1)
    /* 6520 80108D20 00000000 */  nop
    /* 6524 80108D24 08004000 */  jr         $v0
    /* 6528 80108D28 00000000 */   nop
    /* 652C 80108D2C 1F000424 */  addiu      $a0, $zero, 0x1F
    /* 6530 80108D30 01000524 */  addiu      $a1, $zero, 0x1
    /* 6534 80108D34 2AF8010C */  jal        func_8007E0A8
    /* 6538 80108D38 06000624 */   addiu     $a2, $zero, 0x6
    /* 653C 80108D3C 3729020C */  jal        func_8008A4DC
    /* 6540 80108D40 21200000 */   addu      $a0, $zero, $zero
    /* 6544 80108D44 01000424 */  addiu      $a0, $zero, 0x1
    /* 6548 80108D48 1180033C */  lui        $v1, %hi(D_8010AD80)
    /* 654C 80108D4C 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 6550 80108D50 20004B24 */  addiu      $t3, $v0, %lo(vs_main_settings)
    /* 6554 80108D54 80AD6A24 */  addiu      $t2, $v1, %lo(D_8010AD80)
    /* 6558 80108D58 0000688D */  lw         $t0, 0x0($t3)
    /* 655C 80108D5C 0400698D */  lw         $t1, 0x4($t3)
    /* 6560 80108D60 000048AD */  sw         $t0, 0x0($t2)
    /* 6564 80108D64 040049AD */  sw         $t1, 0x4($t2)
    /* 6568 80108D68 0800688D */  lw         $t0, 0x8($t3)
    /* 656C 80108D6C 0C00698D */  lw         $t1, 0xC($t3)
    /* 6570 80108D70 080048AD */  sw         $t0, 0x8($t2)
    /* 6574 80108D74 0C0049AD */  sw         $t1, 0xC($t2)
    /* 6578 80108D78 1000688D */  lw         $t0, 0x10($t3)
    /* 657C 80108D7C 1400698D */  lw         $t1, 0x14($t3)
    /* 6580 80108D80 100048AD */  sw         $t0, 0x10($t2)
    /* 6584 80108D84 140049AD */  sw         $t1, 0x14($t2)
    /* 6588 80108D88 1800688D */  lw         $t0, 0x18($t3)
    /* 658C 80108D8C 1C00698D */  lw         $t1, 0x1C($t3)
    /* 6590 80108D90 180048AD */  sw         $t0, 0x18($t2)
    /* 6594 80108D94 1C0049AD */  sw         $t1, 0x1C($t2)
    /* 6598 80108D98 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0x1)
    /* 659C 80108D9C 99154390 */  lbu        $v1, %lo(vs_main_stateFlags + 0x1)($v0)
    /* 65A0 80108DA0 1180023C */  lui        $v0, %hi(_difficulty)
    /* 65A4 80108DA4 B721040C */  jal        _initGameOver
    /* 65A8 80108DA8 A4AD43AC */   sw        $v1, %lo(_difficulty)($v0)
    /* 65AC 80108DAC 01000224 */  addiu      $v0, $zero, 0x1
    /* 65B0 80108DB0 06240408 */  j          .L80109018
    /* 65B4 80108DB4 000022A2 */   sb        $v0, 0x0($s1)
    /* 65B8 80108DB8 B721040C */  jal        _initGameOver
    /* 65BC 80108DBC 21200000 */   addu      $a0, $zero, $zero
    /* 65C0 80108DC0 95004010 */  beqz       $v0, .L80109018
    /* 65C4 80108DC4 02000224 */   addiu     $v0, $zero, 0x2
    /* 65C8 80108DC8 000022A2 */  sb         $v0, 0x0($s1)
    /* 65CC 80108DCC 2D22040C */  jal        _displayGameOverScreen
    /* 65D0 80108DD0 01000424 */   addiu     $a0, $zero, 0x1
    /* 65D4 80108DD4 2D22040C */  jal        _displayGameOverScreen
    /* 65D8 80108DD8 21200000 */   addu      $a0, $zero, $zero
    /* 65DC 80108DDC 21804000 */  addu       $s0, $v0, $zero
    /* 65E0 80108DE0 8D000012 */  beqz       $s0, .L80109018
    /* 65E4 80108DE4 1180023C */   lui       $v0, %hi(D_8010ADA0)
    /* 65E8 80108DE8 10000324 */  addiu      $v1, $zero, 0x10
    /* 65EC 80108DEC A0AD43AC */  sw         $v1, %lo(D_8010ADA0)($v0)
    /* 65F0 80108DF0 02000224 */  addiu      $v0, $zero, 0x2
    /* 65F4 80108DF4 45000212 */  beq        $s0, $v0, .L80108F0C
    /* 65F8 80108DF8 0680033C */   lui       $v1, %hi(vs_main_stateFlags)
    /* 65FC 80108DFC 98156224 */  addiu      $v0, $v1, %lo(vs_main_stateFlags)
    /* 6600 80108E00 AB005090 */  lbu        $s0, 0xAB($v0)
    /* 6604 80108E04 00000000 */  nop
    /* 6608 80108E08 FFFF0226 */  addiu      $v0, $s0, -0x1
    /* 660C 80108E0C 0200422C */  sltiu      $v0, $v0, 0x2
    /* 6610 80108E10 0A004010 */  beqz       $v0, .L80108E3C
    /* 6614 80108E14 03000224 */   addiu     $v0, $zero, 0x3
    /* 6618 80108E18 98156290 */  lbu        $v0, %lo(vs_main_stateFlags)($v1)
    /* 661C 80108E1C 00000000 */  nop
    /* 6620 80108E20 06004014 */  bnez       $v0, .L80108E3C
    /* 6624 80108E24 03000224 */   addiu     $v0, $zero, 0x3
    /* 6628 80108E28 6C21040C */  jal        func_801085B0
    /* 662C 80108E2C 21200002 */   addu      $a0, $s0, $zero
    /* 6630 80108E30 06000224 */  addiu      $v0, $zero, 0x6
    /* 6634 80108E34 06240408 */  j          .L80109018
    /* 6638 80108E38 000022A2 */   sb        $v0, 0x0($s1)
  .L80108E3C:
    /* 663C 80108E3C 06240408 */  j          .L80109018
    /* 6640 80108E40 000022A2 */   sb        $v0, 0x0($s1)
    /* 6644 80108E44 F110040C */  jal        _initMemcard
    /* 6648 80108E48 01000424 */   addiu     $a0, $zero, 0x1
    /* 664C 80108E4C 5613040C */  jal        _initFileMenu
    /* 6650 80108E50 1180103C */   lui       $s0, %hi(D_8010AB80)
    /* 6654 80108E54 1000A427 */  addiu      $a0, $sp, 0x10
    /* 6658 80108E58 80AB1026 */  addiu      $s0, $s0, %lo(D_8010AB80)
    /* 665C 80108E5C 21280002 */  addu       $a1, $s0, $zero
    /* 6660 80108E60 80020224 */  addiu      $v0, $zero, 0x280
    /* 6664 80108E64 1000A2A7 */  sh         $v0, 0x10($sp)
    /* 6668 80108E68 FF010224 */  addiu      $v0, $zero, 0x1FF
    /* 666C 80108E6C 1200A2A7 */  sh         $v0, 0x12($sp)
    /* 6670 80108E70 00010224 */  addiu      $v0, $zero, 0x100
    /* 6674 80108E74 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 6678 80108E78 01000224 */  addiu      $v0, $zero, 0x1
    /* 667C 80108E7C 57A2000C */  jal        StoreImage
    /* 6680 80108E80 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 6684 80108E84 94A1000C */  jal        DrawSync
    /* 6688 80108E88 21200000 */   addu      $a0, $zero, $zero
    /* 668C 80108E8C 21200002 */  addu       $a0, $s0, $zero
    /* 6690 80108E90 03000524 */  addiu      $a1, $zero, 0x3
    /* 6694 80108E94 21300000 */  addu       $a2, $zero, $zero
    /* 6698 80108E98 9922010C */  jal        vs_main_loadClut
    /* 669C 80108E9C 00010724 */   addiu     $a3, $zero, 0x100
    /* 66A0 80108EA0 04000224 */  addiu      $v0, $zero, 0x4
    /* 66A4 80108EA4 06240408 */  j          .L80109018
    /* 66A8 80108EA8 000022A2 */   sb        $v0, 0x0($s1)
    /* 66AC 80108EAC F110040C */  jal        _initMemcard
    /* 66B0 80108EB0 21200000 */   addu      $a0, $zero, $zero
    /* 66B4 80108EB4 59004010 */  beqz       $v0, .L8010901C
    /* 66B8 80108EB8 0680033C */   lui       $v1, %hi(vs_main_stateFlags + 0xA4)
    /* 66BC 80108EBC 7720040C */  jal        _loadFileMenu
    /* 66C0 80108EC0 02000424 */   addiu     $a0, $zero, 0x2
    /* 66C4 80108EC4 05000224 */  addiu      $v0, $zero, 0x5
    /* 66C8 80108EC8 CD230408 */  j          .L80108F34
    /* 66CC 80108ECC 000022A2 */   sb        $v0, 0x0($s1)
    /* 66D0 80108ED0 6EA1000C */  jal        SetDispMask
    /* 66D4 80108ED4 01000424 */   addiu     $a0, $zero, 0x1
    /* 66D8 80108ED8 7720040C */  jal        _loadFileMenu
    /* 66DC 80108EDC 21200000 */   addu      $a0, $zero, $zero
    /* 66E0 80108EE0 21804000 */  addu       $s0, $v0, $zero
    /* 66E4 80108EE4 13000012 */  beqz       $s0, .L80108F34
    /* 66E8 80108EE8 00000000 */   nop
    /* 66EC 80108EEC 8611040C */  jal        _shutdownMemcard
    /* 66F0 80108EF0 00000000 */   nop
    /* 66F4 80108EF4 6EA1000C */  jal        SetDispMask
    /* 66F8 80108EF8 21200000 */   addu      $a0, $zero, $zero
    /* 66FC 80108EFC 06000106 */  bgez       $s0, .L80108F18
    /* 6700 80108F00 1180023C */   lui       $v0, %hi(D_8010ADA0)
    /* 6704 80108F04 01000324 */  addiu      $v1, $zero, 0x1
    /* 6708 80108F08 A0AD43AC */  sw         $v1, %lo(D_8010ADA0)($v0)
  .L80108F0C:
    /* 670C 80108F0C 07000224 */  addiu      $v0, $zero, 0x7
    /* 6710 80108F10 06240408 */  j          .L80109018
    /* 6714 80108F14 000022A2 */   sb        $v0, 0x0($s1)
  .L80108F18:
    /* 6718 80108F18 1015010C */  jal        vs_main_freeMusic
    /* 671C 80108F1C 01000424 */   addiu     $a0, $zero, 0x1
    /* 6720 80108F20 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0xA4)
    /* 6724 80108F24 0809010C */  jal        vs_main_jumpToBattle
    /* 6728 80108F28 3C1640A0 */   sb        $zero, %lo(vs_main_stateFlags + 0xA4)($v0)
    /* 672C 80108F2C 07240408 */  j          .L8010901C
    /* 6730 80108F30 0680033C */   lui       $v1, %hi(vs_main_stateFlags + 0xA4)
  .L80108F34:
    /* 6734 80108F34 2018040C */  jal        _drawFileMenuBg
    /* 6738 80108F38 00000000 */   nop
    /* 673C 80108F3C 0680023C */  lui        $v0, %hi(vs_main_frameBuf)
    /* 6740 80108F40 10E2448C */  lw         $a0, %lo(vs_main_frameBuf)($v0)
    /* 6744 80108F44 F916040C */  jal        _drawFileMenu
    /* 6748 80108F48 00000000 */   nop
    /* 674C 80108F4C 07240408 */  j          .L8010901C
    /* 6750 80108F50 0680033C */   lui       $v1, %hi(vs_main_stateFlags + 0xA4)
    /* 6754 80108F54 6C21040C */  jal        func_801085B0
    /* 6758 80108F58 21200000 */   addu      $a0, $zero, $zero
    /* 675C 80108F5C 2E004010 */  beqz       $v0, .L80109018
    /* 6760 80108F60 01000424 */   addiu     $a0, $zero, 0x1
    /* 6764 80108F64 0680113C */  lui        $s1, %hi(vs_main_settings)
    /* 6768 80108F68 1180023C */  lui        $v0, %hi(D_8010AD80)
    /* 676C 80108F6C 0680103C */  lui        $s0, %hi(vs_main_stateFlags)
    /* 6770 80108F70 80AD4B24 */  addiu      $t3, $v0, %lo(D_8010AD80)
    /* 6774 80108F74 20002A26 */  addiu      $t2, $s1, %lo(vs_main_settings)
    /* 6778 80108F78 0000688D */  lw         $t0, 0x0($t3)
    /* 677C 80108F7C 0400698D */  lw         $t1, 0x4($t3)
    /* 6780 80108F80 000048AD */  sw         $t0, 0x0($t2)
    /* 6784 80108F84 040049AD */  sw         $t1, 0x4($t2)
    /* 6788 80108F88 0800688D */  lw         $t0, 0x8($t3)
    /* 678C 80108F8C 0C00698D */  lw         $t1, 0xC($t3)
    /* 6790 80108F90 080048AD */  sw         $t0, 0x8($t2)
    /* 6794 80108F94 0C0049AD */  sw         $t1, 0xC($t2)
    /* 6798 80108F98 1000688D */  lw         $t0, 0x10($t3)
    /* 679C 80108F9C 1400698D */  lw         $t1, 0x14($t3)
    /* 67A0 80108FA0 100048AD */  sw         $t0, 0x10($t2)
    /* 67A4 80108FA4 140049AD */  sw         $t1, 0x14($t2)
    /* 67A8 80108FA8 1800688D */  lw         $t0, 0x18($t3)
    /* 67AC 80108FAC 1C00698D */  lw         $t1, 0x1C($t3)
    /* 67B0 80108FB0 180048AD */  sw         $t0, 0x18($t2)
    /* 67B4 80108FB4 1C0049AD */  sw         $t1, 0x1C($t2)
    /* 67B8 80108FB8 1180023C */  lui        $v0, %hi(_difficulty)
    /* 67BC 80108FBC 98151026 */  addiu      $s0, $s0, %lo(vs_main_stateFlags)
    /* 67C0 80108FC0 A4AD4290 */  lbu        $v0, %lo(_difficulty)($v0)
    /* 67C4 80108FC4 20003126 */  addiu      $s1, $s1, %lo(vs_main_settings)
    /* 67C8 80108FC8 1015010C */  jal        vs_main_freeMusic
    /* 67CC 80108FCC 010002A2 */   sb        $v0, 0x1($s0)
    /* 67D0 80108FD0 0A002492 */  lbu        $a0, 0xA($s1)
    /* 67D4 80108FD4 2F1A010C */  jal        vs_main_setMonoSound
    /* 67D8 80108FD8 00000000 */   nop
    /* 67DC 80108FDC 0809010C */  jal        vs_main_jumpToBattle
    /* 67E0 80108FE0 A40000A2 */   sb        $zero, 0xA4($s0)
    /* 67E4 80108FE4 07240408 */  j          .L8010901C
    /* 67E8 80108FE8 0680033C */   lui       $v1, %hi(vs_main_stateFlags + 0xA4)
    /* 67EC 80108FEC 1180033C */  lui        $v1, %hi(D_8010ADA0)
    /* 67F0 80108FF0 A0AD628C */  lw         $v0, %lo(D_8010ADA0)($v1)
    /* 67F4 80108FF4 00000000 */  nop
    /* 67F8 80108FF8 03004010 */  beqz       $v0, .L80109008
    /* 67FC 80108FFC FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6800 80109000 06240408 */  j          .L80109018
    /* 6804 80109004 A0AD62AC */   sw        $v0, %lo(D_8010ADA0)($v1)
  .L80109008:
    /* 6808 80109008 1015010C */  jal        vs_main_freeMusic
    /* 680C 8010900C 01000424 */   addiu     $a0, $zero, 0x1
    /* 6810 80109010 D908010C */  jal        vs_main_resetGame
    /* 6814 80109014 00000000 */   nop
  .L80109018:
    /* 6818 80109018 0680033C */  lui        $v1, %hi(vs_main_stateFlags + 0xA4)
  .L8010901C:
    /* 681C 8010901C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6820 80109020 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6824 80109024 1800B08F */  lw         $s0, 0x18($sp)
    /* 6828 80109028 01000224 */  addiu      $v0, $zero, 0x1
    /* 682C 8010902C 3C1662A0 */  sb         $v0, %lo(vs_main_stateFlags + 0xA4)($v1)
    /* 6830 80109030 21100000 */  addu       $v0, $zero, $zero
    /* 6834 80109034 0800E003 */  jr         $ra
    /* 6838 80109038 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel vs_menu7_gameOver
