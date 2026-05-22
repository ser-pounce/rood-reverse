nonmatching _discardMenu, 0x740

glabel _discardMenu
    /* 3524 80105D24 A0FFBD27 */  addiu      $sp, $sp, -0x60
    /* 3528 80105D28 21288000 */  addu       $a1, $a0, $zero
    /* 352C 80105D2C 5800BFAF */  sw         $ra, 0x58($sp)
    /* 3530 80105D30 5400B3AF */  sw         $s3, 0x54($sp)
    /* 3534 80105D34 5000B2AF */  sw         $s2, 0x50($sp)
    /* 3538 80105D38 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 353C 80105D3C 1B00A010 */  beqz       $a1, .L80105DAC
    /* 3540 80105D40 4800B0AF */   sw        $s0, 0x48($sp)
    /* 3544 80105D44 01000424 */  addiu      $a0, $zero, 0x1
    /* 3548 80105D48 1180103C */  lui        $s0, %hi(_discardType)
    /* 354C 80105D4C 03140500 */  sra        $v0, $a1, 16
    /* 3550 80105D50 1180033C */  lui        $v1, %hi(_discardItemCategory)
    /* 3554 80105D54 519A02A2 */  sb         $v0, %lo(_discardType)($s0)
    /* 3558 80105D58 03130500 */  sra        $v0, $a1, 12
    /* 355C 80105D5C 0F004230 */  andi       $v0, $v0, 0xF
    /* 3560 80105D60 4F9A62A0 */  sb         $v0, %lo(_discardItemCategory)($v1)
    /* 3564 80105D64 1180033C */  lui        $v1, %hi(_discardIndex)
    /* 3568 80105D68 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 356C 80105D6C 8123030C */  jal        func_800C8E04
    /* 3570 80105D70 509A62A0 */   sb        $v0, %lo(_discardIndex)($v1)
    /* 3574 80105D74 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 3578 80105D78 519A0292 */  lbu        $v0, %lo(_discardType)($s0)
    /* 357C 80105D7C 4025638C */  lw         $v1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 3580 80105D80 40100200 */  sll        $v0, $v0, 1
    /* 3584 80105D84 21104300 */  addu       $v0, $v0, $v1
    /* 3588 80105D88 54044494 */  lhu        $a0, 0x454($v0)
    /* 358C 80105D8C 00000000 */  nop
    /* 3590 80105D90 40200400 */  sll        $a0, $a0, 1
    /* 3594 80105D94 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 3598 80105D98 21206400 */   addu      $a0, $v1, $a0
    /* 359C 80105D9C 21100000 */  addu       $v0, $zero, $zero
    /* 35A0 80105DA0 1180033C */  lui        $v1, %hi(D_80109A4E)
    /* 35A4 80105DA4 12190408 */  j          .L80106448
    /* 35A8 80105DA8 4E9A60A0 */   sb        $zero, %lo(D_80109A4E)($v1)
  .L80105DAC:
    /* 35AC 80105DAC 1180023C */  lui        $v0, %hi(D_80109A4E)
    /* 35B0 80105DB0 4E9A4390 */  lbu        $v1, %lo(D_80109A4E)($v0)
    /* 35B4 80105DB4 00000000 */  nop
    /* 35B8 80105DB8 0800622C */  sltiu      $v0, $v1, 0x8
    /* 35BC 80105DBC A1014010 */  beqz       $v0, .L80106444
    /* 35C0 80105DC0 1080023C */   lui       $v0, %hi(jtbl_801028F0)
    /* 35C4 80105DC4 F0284224 */  addiu      $v0, $v0, %lo(jtbl_801028F0)
    /* 35C8 80105DC8 80180300 */  sll        $v1, $v1, 2
    /* 35CC 80105DCC 21186200 */  addu       $v1, $v1, $v0
    /* 35D0 80105DD0 0000628C */  lw         $v0, 0x0($v1)
    /* 35D4 80105DD4 00000000 */  nop
    /* 35D8 80105DD8 08004000 */  jr         $v0
    /* 35DC 80105DDC 00000000 */   nop
    /* 35E0 80105DE0 0F80023C */  lui        $v0, %hi(D_800F5130)
    /* 35E4 80105DE4 3051428C */  lw         $v0, %lo(D_800F5130)($v0)
    /* 35E8 80105DE8 00000000 */  nop
    /* 35EC 80105DEC 82170200 */  srl        $v0, $v0, 30
    /* 35F0 80105DF0 01004230 */  andi       $v0, $v0, 0x1
    /* 35F4 80105DF4 94014010 */  beqz       $v0, .L80106448
    /* 35F8 80105DF8 21100000 */   addu      $v0, $zero, $zero
    /* 35FC 80105DFC 74EA030C */  jal        vs_mainmenu_ready
    /* 3600 80105E00 00000000 */   nop
    /* 3604 80105E04 8F014010 */  beqz       $v0, .L80106444
    /* 3608 80105E08 1180023C */   lui       $v0, %hi(_discardType)
    /* 360C 80105E0C 519A4290 */  lbu        $v0, %lo(_discardType)($v0)
    /* 3610 80105E10 1180033C */  lui        $v1, %hi(D_80109A4E)
    /* 3614 80105E14 01004230 */  andi       $v0, $v0, 0x1
    /* 3618 80105E18 01004224 */  addiu      $v0, $v0, 0x1
    /* 361C 80105E1C 11190408 */  j          .L80106444
    /* 3620 80105E20 4E9A62A0 */   sb        $v0, %lo(D_80109A4E)($v1)
    /* 3624 80105E24 21880000 */  addu       $s1, $zero, $zero
    /* 3628 80105E28 2800A827 */  addiu      $t0, $sp, 0x28
    /* 362C 80105E2C 04000724 */  addiu      $a3, $zero, 0x4
    /* 3630 80105E30 1800A927 */  addiu      $t1, $sp, 0x18
    /* 3634 80105E34 21302001 */  addu       $a2, $t1, $zero
    /* 3638 80105E38 1080033C */  lui        $v1, %hi(vs_mainMenu_itemHelp)
    /* 363C 80105E3C 1180023C */  lui        $v0, %hi(_discardType)
    /* 3640 80105E40 519A4290 */  lbu        $v0, %lo(_discardType)($v0)
    /* 3644 80105E44 4025658C */  lw         $a1, %lo(vs_mainMenu_itemHelp)($v1)
    /* 3648 80105E48 40100200 */  sll        $v0, $v0, 1
    /* 364C 80105E4C 21504500 */  addu       $t2, $v0, $a1
    /* 3650 80105E50 2120A000 */  addu       $a0, $a1, $zero
  .L80105E54:
    /* 3654 80105E54 21182701 */  addu       $v1, $t1, $a3
    /* 3658 80105E58 0800E724 */  addiu      $a3, $a3, 0x8
    /* 365C 80105E5C 50048294 */  lhu        $v0, 0x450($a0)
    /* 3660 80105E60 02008424 */  addiu      $a0, $a0, 0x2
    /* 3664 80105E64 01003126 */  addiu      $s1, $s1, 0x1
    /* 3668 80105E68 40100200 */  sll        $v0, $v0, 1
    /* 366C 80105E6C 2110A200 */  addu       $v0, $a1, $v0
    /* 3670 80105E70 0000C2AC */  sw         $v0, 0x0($a2)
    /* 3674 80105E74 54044295 */  lhu        $v0, 0x454($t2)
    /* 3678 80105E78 0800C624 */  addiu      $a2, $a2, 0x8
    /* 367C 80105E7C 40100200 */  sll        $v0, $v0, 1
    /* 3680 80105E80 2110A200 */  addu       $v0, $a1, $v0
    /* 3684 80105E84 000062AC */  sw         $v0, 0x0($v1)
    /* 3688 80105E88 000000AD */  sw         $zero, 0x0($t0)
    /* 368C 80105E8C 0200222A */  slti       $v0, $s1, 0x2
    /* 3690 80105E90 F0FF4014 */  bnez       $v0, .L80105E54
    /* 3694 80105E94 04000825 */   addiu     $t0, $t0, 0x4
    /* 3698 80105E98 02000424 */  addiu      $a0, $zero, 0x2
    /* 369C 80105E9C 04000524 */  addiu      $a1, $zero, 0x4
    /* 36A0 80105EA0 1800A627 */  addiu      $a2, $sp, 0x18
    /* 36A4 80105EA4 3BFC030C */  jal        vs_mainMenu_initSortUi
    /* 36A8 80105EA8 2800A727 */   addiu     $a3, $sp, 0x28
    /* 36AC 80105EAC 1180033C */  lui        $v1, %hi(D_80109A4E)
    /* 36B0 80105EB0 03000224 */  addiu      $v0, $zero, 0x3
    /* 36B4 80105EB4 11190408 */  j          .L80106444
    /* 36B8 80105EB8 4E9A62A0 */   sb        $v0, %lo(D_80109A4E)($v1)
    /* 36BC 80105EBC 1180033C */  lui        $v1, %hi(vs_menuD_containerData)
    /* 36C0 80105EC0 1180023C */  lui        $v0, %hi(_discardIndex)
    /* 36C4 80105EC4 509A4290 */  lbu        $v0, %lo(_discardIndex)($v0)
    /* 36C8 80105EC8 8C9A638C */  lw         $v1, %lo(vs_menuD_containerData)($v1)
    /* 36CC 80105ECC 80100200 */  sll        $v0, $v0, 2
    /* 36D0 80105ED0 21186200 */  addu       $v1, $v1, $v0
    /* 36D4 80105ED4 02386390 */  lbu        $v1, 0x3802($v1)
    /* 36D8 80105ED8 1180023C */  lui        $v0, %hi(_discardMaxAmount)
    /* 36DC 80105EDC 549A43A0 */  sb         $v1, %lo(_discardMaxAmount)($v0)
    /* 36E0 80105EE0 1533030C */  jal        vs_battle_toBCD
    /* 36E4 80105EE4 FF006430 */   andi      $a0, $v1, 0xFF
    /* 36E8 80105EE8 21884000 */  addu       $s1, $v0, $zero
    /* 36EC 80105EEC 03211100 */  sra        $a0, $s1, 4
    /* 36F0 80105EF0 1180103C */  lui        $s0, %hi(discardCountTemplate)
    /* 36F4 80105EF4 F8991026 */  addiu      $s0, $s0, %lo(discardCountTemplate)
    /* 36F8 80105EF8 0F002232 */  andi       $v0, $s1, 0xF
    /* 36FC 80105EFC 1533030C */  jal        vs_battle_toBCD
    /* 3700 80105F00 080002A2 */   sb        $v0, 0x8($s0)
    /* 3704 80105F04 21884000 */  addu       $s1, $v0, $zero
    /* 3708 80105F08 0F002232 */  andi       $v0, $s1, 0xF
    /* 370C 80105F0C 03191100 */  sra        $v1, $s1, 4
    /* 3710 80105F10 02001124 */  addiu      $s1, $zero, 0x2
    /* 3714 80105F14 070002A2 */  sb         $v0, 0x7($s0)
    /* 3718 80105F18 060003A2 */  sb         $v1, 0x6($s0)
    /* 371C 80105F1C 21103002 */  addu       $v0, $s1, $s0
  .L80105F20:
    /* 3720 80105F20 000040A0 */  sb         $zero, 0x0($v0)
    /* 3724 80105F24 01003126 */  addiu      $s1, $s1, 0x1
    /* 3728 80105F28 0500222A */  slti       $v0, $s1, 0x5
    /* 372C 80105F2C FCFF4014 */  bnez       $v0, .L80105F20
    /* 3730 80105F30 21103002 */   addu      $v0, $s1, $s0
    /* 3734 80105F34 22000424 */  addiu      $a0, $zero, 0x22
    /* 3738 80105F38 82FF0524 */  addiu      $a1, $zero, -0x7E
    /* 373C 80105F3C 82000624 */  addiu      $a2, $zero, 0x82
    /* 3740 80105F40 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 3744 80105F44 1180023C */  lui        $v0, %hi(discardCountTemplate)
    /* 3748 80105F48 F8994224 */  addiu      $v0, $v0, %lo(discardCountTemplate)
    /* 374C 80105F4C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 3750 80105F50 9723030C */  jal        vs_battle_setMenuItem
    /* 3754 80105F54 1400A2AF */   sw        $v0, 0x14($sp)
    /* 3758 80105F58 05000324 */  addiu      $v1, $zero, 0x5
    /* 375C 80105F5C 000043A0 */  sb         $v1, 0x0($v0)
    /* 3760 80105F60 180040A4 */  sh         $zero, 0x18($v0)
    /* 3764 80105F64 1180023C */  lui        $v0, %hi(_discardBulkStep)
    /* 3768 80105F68 529A40A0 */  sb         $zero, %lo(_discardBulkStep)($v0)
    /* 376C 80105F6C 1180023C */  lui        $v0, %hi(_discardAmount)
    /* 3770 80105F70 1180033C */  lui        $v1, %hi(D_80109A4E)
    /* 3774 80105F74 539A40A0 */  sb         $zero, %lo(_discardAmount)($v0)
    /* 3778 80105F78 04000224 */  addiu      $v0, $zero, 0x4
    /* 377C 80105F7C 11190408 */  j          .L80106444
    /* 3780 80105F80 4E9A62A0 */   sb        $v0, %lo(D_80109A4E)($v1)
    /* 3784 80105F84 0FFD030C */  jal        vs_mainMenu_processItemActionMenu
    /* 3788 80105F88 00000000 */   nop
    /* 378C 80105F8C D8FC030C */  jal        vs_mainMenu_getSelectedItemAction
    /* 3790 80105F90 00000000 */   nop
    /* 3794 80105F94 01005124 */  addiu      $s1, $v0, 0x1
    /* 3798 80105F98 2A012012 */  beqz       $s1, .L80106444
    /* 379C 80105F9C 01000224 */   addiu     $v0, $zero, 0x1
    /* 37A0 80105FA0 24012216 */  bne        $s1, $v0, .L80106434
    /* 37A4 80105FA4 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 37A8 80105FA8 6216010C */  jal        vs_main_playSfxDefault
    /* 37AC 80105FAC 1C000524 */   addiu     $a1, $zero, 0x1C
    /* 37B0 80105FB0 1180023C */  lui        $v0, %hi(_discardItemCategory)
    /* 37B4 80105FB4 4F9A4490 */  lbu        $a0, %lo(_discardItemCategory)($v0)
    /* 37B8 80105FB8 1180023C */  lui        $v0, %hi(_discardIndex)
    /* 37BC 80105FBC 509A4590 */  lbu        $a1, %lo(_discardIndex)($v0)
    /* 37C0 80105FC0 1180023C */  lui        $v0, %hi(vs_menuD_containerData)
    /* 37C4 80105FC4 8C9A468C */  lw         $a2, %lo(vs_menuD_containerData)($v0)
    /* 37C8 80105FC8 600B040C */  jal        _initContainerObject
    /* 37CC 80105FCC 00000000 */   nop
    /* 37D0 80105FD0 12190408 */  j          .L80106448
    /* 37D4 80105FD4 21102002 */   addu      $v0, $s1, $zero
    /* 37D8 80105FD8 74EA030C */  jal        vs_mainmenu_ready
    /* 37DC 80105FDC 00000000 */   nop
    /* 37E0 80105FE0 18014010 */  beqz       $v0, .L80106444
    /* 37E4 80105FE4 02001124 */   addiu     $s1, $zero, 0x2
    /* 37E8 80105FE8 1180023C */  lui        $v0, %hi(discardCountTemplate)
    /* 37EC 80105FEC F8994424 */  addiu      $a0, $v0, %lo(discardCountTemplate)
    /* 37F0 80105FF0 8F000324 */  addiu      $v1, $zero, 0x8F
    /* 37F4 80105FF4 21102402 */  addu       $v0, $s1, $a0
  .L80105FF8:
    /* 37F8 80105FF8 000043A0 */  sb         $v1, 0x0($v0)
    /* 37FC 80105FFC 01003126 */  addiu      $s1, $s1, 0x1
    /* 3800 80106000 0500222A */  slti       $v0, $s1, 0x5
    /* 3804 80106004 FCFF4014 */  bnez       $v0, .L80105FF8
    /* 3808 80106008 21102402 */   addu      $v0, $s1, $a0
    /* 380C 8010600C 22000424 */  addiu      $a0, $zero, 0x22
    /* 3810 80106010 21280000 */  addu       $a1, $zero, $zero
    /* 3814 80106014 82000624 */  addiu      $a2, $zero, 0x82
    /* 3818 80106018 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 381C 8010601C 1180023C */  lui        $v0, %hi(discardCountTemplate)
    /* 3820 80106020 F8994224 */  addiu      $v0, $v0, %lo(discardCountTemplate)
    /* 3824 80106024 1000A0AF */  sw         $zero, 0x10($sp)
    /* 3828 80106028 9723030C */  jal        vs_battle_setMenuItem
    /* 382C 8010602C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 3830 80106030 1180033C */  lui        $v1, %hi(D_80109A4E)
    /* 3834 80106034 05000224 */  addiu      $v0, $zero, 0x5
    /* 3838 80106038 4E9A62A0 */  sb         $v0, %lo(D_80109A4E)($v1)
    /* 383C 8010603C 0680123C */  lui        $s2, %hi(vs_main_buttonsPressed)
    /* 3840 80106040 D0E1428E */  lw         $v0, %lo(vs_main_buttonsPressed)($s2)
    /* 3844 80106044 00000000 */  nop
    /* 3848 80106048 70004230 */  andi       $v0, $v0, 0x70
    /* 384C 8010604C 32004010 */  beqz       $v0, .L80106118
    /* 3850 80106050 1180133C */   lui       $s3, %hi(_discardAmount)
    /* 3854 80106054 539A6492 */  lbu        $a0, %lo(_discardAmount)($s3)
    /* 3858 80106058 1533030C */  jal        vs_battle_toBCD
    /* 385C 8010605C 1180103C */   lui       $s0, %hi(discardCountTemplate)
    /* 3860 80106060 21884000 */  addu       $s1, $v0, $zero
    /* 3864 80106064 03211100 */  sra        $a0, $s1, 4
    /* 3868 80106068 F8991026 */  addiu      $s0, $s0, %lo(discardCountTemplate)
    /* 386C 8010606C 0F002232 */  andi       $v0, $s1, 0xF
    /* 3870 80106070 1533030C */  jal        vs_battle_toBCD
    /* 3874 80106074 040002A2 */   sb        $v0, 0x4($s0)
    /* 3878 80106078 21884000 */  addu       $s1, $v0, $zero
    /* 387C 8010607C 22000424 */  addiu      $a0, $zero, 0x22
    /* 3880 80106080 21280000 */  addu       $a1, $zero, $zero
    /* 3884 80106084 82000624 */  addiu      $a2, $zero, 0x82
    /* 3888 80106088 7E000724 */  addiu      $a3, $zero, 0x7E
    /* 388C 8010608C 0F002232 */  andi       $v0, $s1, 0xF
    /* 3890 80106090 030002A2 */  sb         $v0, 0x3($s0)
    /* 3894 80106094 03111100 */  sra        $v0, $s1, 4
    /* 3898 80106098 020002A2 */  sb         $v0, 0x2($s0)
    /* 389C 8010609C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 38A0 801060A0 9723030C */  jal        vs_battle_setMenuItem
    /* 38A4 801060A4 1400B0AF */   sw        $s0, 0x14($sp)
    /* 38A8 801060A8 D0E1428E */  lw         $v0, %lo(vs_main_buttonsPressed)($s2)
    /* 38AC 801060AC 00000000 */  nop
    /* 38B0 801060B0 50004230 */  andi       $v0, $v0, 0x50
    /* 38B4 801060B4 0A004010 */  beqz       $v0, .L801060E0
    /* 38B8 801060B8 00000000 */   nop
    /* 38BC 801060BC BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 38C0 801060C0 00000000 */   nop
    /* 38C4 801060C4 D0E1438E */  lw         $v1, %lo(vs_main_buttonsPressed)($s2)
    /* 38C8 801060C8 00000000 */  nop
    /* 38CC 801060CC 10006330 */  andi       $v1, $v1, 0x10
    /* 38D0 801060D0 DD006014 */  bnez       $v1, .L80106448
    /* 38D4 801060D4 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 38D8 801060D8 12190408 */  j          .L80106448
    /* 38DC 801060DC FFFF0224 */   addiu     $v0, $zero, -0x1
  .L801060E0:
    /* 38E0 801060E0 539A6292 */  lbu        $v0, %lo(_discardAmount)($s3)
    /* 38E4 801060E4 00000000 */  nop
    /* 38E8 801060E8 05004014 */  bnez       $v0, .L80106100
    /* 38EC 801060EC 00000000 */   nop
    /* 38F0 801060F0 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 38F4 801060F4 00000000 */   nop
    /* 38F8 801060F8 12190408 */  j          .L80106448
    /* 38FC 801060FC FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80106100:
    /* 3900 80106100 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 3904 80106104 00000000 */   nop
    /* 3908 80106108 1180033C */  lui        $v1, %hi(D_80109A4E)
    /* 390C 8010610C 06000224 */  addiu      $v0, $zero, 0x6
    /* 3910 80106110 11190408 */  j          .L80106444
    /* 3914 80106114 4E9A62A0 */   sb        $v0, %lo(D_80109A4E)($v1)
  .L80106118:
    /* 3918 80106118 1180023C */  lui        $v0, %hi(_discardAmount)
    /* 391C 8010611C 0680033C */  lui        $v1, %hi(vs_main_buttonRepeat)
    /* 3920 80106120 539A4690 */  lbu        $a2, %lo(_discardAmount)($v0)
    /* 3924 80106124 DCDF628C */  lw         $v0, %lo(vs_main_buttonRepeat)($v1)
    /* 3928 80106128 2120C000 */  addu       $a0, $a2, $zero
    /* 392C 8010612C 00104330 */  andi       $v1, $v0, 0x1000
    /* 3930 80106130 00404230 */  andi       $v0, $v0, 0x4000
    /* 3934 80106134 02004010 */  beqz       $v0, .L80106140
    /* 3938 80106138 2B880300 */   sltu      $s1, $zero, $v1
    /* 393C 8010613C FFFF3126 */  addiu      $s1, $s1, -0x1
  .L80106140:
    /* 3940 80106140 01000224 */  addiu      $v0, $zero, 0x1
    /* 3944 80106144 09002216 */  bne        $s1, $v0, .L8010616C
    /* 3948 80106148 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 394C 8010614C 1180033C */  lui        $v1, %hi(_discardSteps)
    /* 3950 80106150 1180023C */  lui        $v0, %hi(_discardBulkStep)
    /* 3954 80106154 529A4290 */  lbu        $v0, %lo(_discardBulkStep)($v0)
    /* 3958 80106158 049A6324 */  addiu      $v1, $v1, %lo(_discardSteps)
    /* 395C 8010615C 21104300 */  addu       $v0, $v0, $v1
    /* 3960 80106160 00004290 */  lbu        $v0, 0x0($v0)
    /* 3964 80106164 64180408 */  j          .L80106190
    /* 3968 80106168 2120C200 */   addu      $a0, $a2, $v0
  .L8010616C:
    /* 396C 8010616C 08002216 */  bne        $s1, $v0, .L80106190
    /* 3970 80106170 1180033C */   lui       $v1, %hi(_discardSteps)
    /* 3974 80106174 1180023C */  lui        $v0, %hi(_discardBulkStep)
    /* 3978 80106178 529A4290 */  lbu        $v0, %lo(_discardBulkStep)($v0)
    /* 397C 8010617C 049A6324 */  addiu      $v1, $v1, %lo(_discardSteps)
    /* 3980 80106180 21104300 */  addu       $v0, $v0, $v1
    /* 3984 80106184 00004290 */  lbu        $v0, 0x0($v0)
    /* 3988 80106188 00000000 */  nop
    /* 398C 8010618C 2320C200 */  subu       $a0, $a2, $v0
  .L80106190:
    /* 3990 80106190 08008004 */  bltz       $a0, .L801061B4
    /* 3994 80106194 1180023C */   lui       $v0, %hi(_discardMaxAmount)
    /* 3998 80106198 549A4290 */  lbu        $v0, %lo(_discardMaxAmount)($v0)
    /* 399C 8010619C 00000000 */  nop
    /* 39A0 801061A0 2A104400 */  slt        $v0, $v0, $a0
    /* 39A4 801061A4 04004014 */  bnez       $v0, .L801061B8
    /* 39A8 801061A8 1180053C */   lui       $a1, %hi(_discardBulkStep)
    /* 39AC 801061AC 1180023C */  lui        $v0, %hi(_discardAmount)
    /* 39B0 801061B0 539A44A0 */  sb         $a0, %lo(_discardAmount)($v0)
  .L801061B4:
    /* 39B4 801061B4 1180053C */  lui        $a1, %hi(_discardBulkStep)
  .L801061B8:
    /* 39B8 801061B8 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 39BC 801061BC DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 39C0 801061C0 529AA490 */  lbu        $a0, %lo(_discardBulkStep)($a1)
    /* 39C4 801061C4 00206230 */  andi       $v0, $v1, 0x2000
    /* 39C8 801061C8 02004010 */  beqz       $v0, .L801061D4
    /* 39CC 801061CC 21880000 */   addu      $s1, $zero, $zero
    /* 39D0 801061D0 FFFF1124 */  addiu      $s1, $zero, -0x1
  .L801061D4:
    /* 39D4 801061D4 00806230 */  andi       $v0, $v1, 0x8000
    /* 39D8 801061D8 02004010 */  beqz       $v0, .L801061E4
    /* 39DC 801061DC 01000224 */   addiu     $v0, $zero, 0x1
    /* 39E0 801061E0 01003126 */  addiu      $s1, $s1, 0x1
  .L801061E4:
    /* 39E4 801061E4 0E002216 */  bne        $s1, $v0, .L80106220
    /* 39E8 801061E8 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 39EC 801061EC FF008330 */  andi       $v1, $a0, 0xFF
    /* 39F0 801061F0 02000224 */  addiu      $v0, $zero, 0x2
    /* 39F4 801061F4 16006214 */  bne        $v1, $v0, .L80106250
    /* 39F8 801061F8 01008224 */   addiu     $v0, $a0, 0x1
    /* 39FC 801061FC 1180053C */  lui        $a1, %hi(_discardAmount)
    /* 3A00 80106200 1180023C */  lui        $v0, %hi(_discardMaxAmount)
    /* 3A04 80106204 549A4390 */  lbu        $v1, %lo(_discardMaxAmount)($v0)
    /* 3A08 80106208 539AA290 */  lbu        $v0, %lo(_discardAmount)($a1)
    /* 3A0C 8010620C 00000000 */  nop
    /* 3A10 80106210 11004310 */  beq        $v0, $v1, .L80106258
    /* 3A14 80106214 1180023C */   lui       $v0, %hi(_discardBulkStep)
    /* 3A18 80106218 96180408 */  j          .L80106258
    /* 3A1C 8010621C 539AA3A0 */   sb        $v1, %lo(_discardAmount)($a1)
  .L80106220:
    /* 3A20 80106220 0D002216 */  bne        $s1, $v0, .L80106258
    /* 3A24 80106224 1180023C */   lui       $v0, %hi(_discardBulkStep)
    /* 3A28 80106228 FF008230 */  andi       $v0, $a0, 0xFF
    /* 3A2C 8010622C 08004014 */  bnez       $v0, .L80106250
    /* 3A30 80106230 FFFF8224 */   addiu     $v0, $a0, -0x1
    /* 3A34 80106234 1180033C */  lui        $v1, %hi(_discardAmount)
    /* 3A38 80106238 539A6290 */  lbu        $v0, %lo(_discardAmount)($v1)
    /* 3A3C 8010623C 00000000 */  nop
    /* 3A40 80106240 05004010 */  beqz       $v0, .L80106258
    /* 3A44 80106244 1180023C */   lui       $v0, %hi(_discardBulkStep)
    /* 3A48 80106248 96180408 */  j          .L80106258
    /* 3A4C 8010624C 539A60A0 */   sb        $zero, %lo(_discardAmount)($v1)
  .L80106250:
    /* 3A50 80106250 529AA2A0 */  sb         $v0, %lo(_discardBulkStep)($a1)
    /* 3A54 80106254 1180023C */  lui        $v0, %hi(_discardBulkStep)
  .L80106258:
    /* 3A58 80106258 529A4290 */  lbu        $v0, %lo(_discardBulkStep)($v0)
    /* 3A5C 8010625C 00000000 */  nop
    /* 3A60 80106260 05008214 */  bne        $a0, $v0, .L80106278
    /* 3A64 80106264 1180023C */   lui       $v0, %hi(_discardAmount)
    /* 3A68 80106268 539A4290 */  lbu        $v0, %lo(_discardAmount)($v0)
    /* 3A6C 8010626C 00000000 */  nop
    /* 3A70 80106270 0300C210 */  beq        $a2, $v0, .L80106280
    /* 3A74 80106274 00000000 */   nop
  .L80106278:
    /* 3A78 80106278 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 3A7C 8010627C 00000000 */   nop
  .L80106280:
    /* 3A80 80106280 841C030C */  jal        func_800C7210
    /* 3A84 80106284 05000424 */   addiu     $a0, $zero, 0x5
    /* 3A88 80106288 1180023C */  lui        $v0, %hi(_discardAmount)
    /* 3A8C 8010628C 539A4490 */  lbu        $a0, %lo(_discardAmount)($v0)
    /* 3A90 80106290 1533030C */  jal        vs_battle_toBCD
    /* 3A94 80106294 801F103C */   lui       $s0, %hi(D_1F800000)
    /* 3A98 80106298 21884000 */  addu       $s1, $v0, $zero
    /* 3A9C 8010629C 0F002432 */  andi       $a0, $s1, 0xF
    /* 3AA0 801062A0 42000524 */  addiu      $a1, $zero, 0x42
    /* 3AA4 801062A4 00001026 */  addiu      $s0, $s0, %lo(D_1F800000)
    /* 3AA8 801062A8 0800078E */  lw         $a3, 0x8($s0)
    /* 3AAC 801062AC 82000624 */  addiu      $a2, $zero, 0x82
    /* 3AB0 801062B0 3E1C030C */  jal        vs_battle_printVariableWidthFontChar
    /* 3AB4 801062B4 F4FFE724 */   addiu     $a3, $a3, -0xC
    /* 3AB8 801062B8 1533030C */  jal        vs_battle_toBCD
    /* 3ABC 801062BC 03211100 */   sra       $a0, $s1, 4
    /* 3AC0 801062C0 21884000 */  addu       $s1, $v0, $zero
    /* 3AC4 801062C4 0F002432 */  andi       $a0, $s1, 0xF
    /* 3AC8 801062C8 3C000524 */  addiu      $a1, $zero, 0x3C
    /* 3ACC 801062CC 0800078E */  lw         $a3, 0x8($s0)
    /* 3AD0 801062D0 82000624 */  addiu      $a2, $zero, 0x82
    /* 3AD4 801062D4 3E1C030C */  jal        vs_battle_printVariableWidthFontChar
    /* 3AD8 801062D8 F4FFE724 */   addiu     $a3, $a3, -0xC
    /* 3ADC 801062DC 03211100 */  sra        $a0, $s1, 4
    /* 3AE0 801062E0 36000524 */  addiu      $a1, $zero, 0x36
    /* 3AE4 801062E4 0800078E */  lw         $a3, 0x8($s0)
    /* 3AE8 801062E8 82000624 */  addiu      $a2, $zero, 0x82
    /* 3AEC 801062EC 3E1C030C */  jal        vs_battle_printVariableWidthFontChar
    /* 3AF0 801062F0 F4FFE724 */   addiu     $a3, $a3, -0xC
    /* 3AF4 801062F4 1180103C */  lui        $s0, %hi(D_80109A07)
    /* 3AF8 801062F8 1180023C */  lui        $v0, %hi(_discardBulkStep)
    /* 3AFC 801062FC 36000524 */  addiu      $a1, $zero, 0x36
    /* 3B00 80106300 529A4390 */  lbu        $v1, %lo(_discardBulkStep)($v0)
    /* 3B04 80106304 079A0492 */  lbu        $a0, %lo(D_80109A07)($s0)
    /* 3B08 80106308 40100300 */  sll        $v0, $v1, 1
    /* 3B0C 8010630C 21104300 */  addu       $v0, $v0, $v1
    /* 3B10 80106310 40100200 */  sll        $v0, $v0, 1
    /* 3B14 80106314 2328A200 */  subu       $a1, $a1, $v0
    /* 3B18 80106318 7200023C */  lui        $v0, (0x720000 >> 16)
    /* 3B1C 8010631C 37FF030C */  jal        func_800FFCDC
    /* 3B20 80106320 2528A200 */   or        $a1, $a1, $v0
    /* 3B24 80106324 11190408 */  j          .L80106444
    /* 3B28 80106328 079A02A2 */   sb        $v0, %lo(D_80109A07)($s0)
    /* 3B2C 8010632C 74EA030C */  jal        vs_mainmenu_ready
    /* 3B30 80106330 00000000 */   nop
    /* 3B34 80106334 43004010 */  beqz       $v0, .L80106444
    /* 3B38 80106338 21880000 */   addu      $s1, $zero, $zero
    /* 3B3C 8010633C 4000A727 */  addiu      $a3, $sp, 0x40
    /* 3B40 80106340 04000624 */  addiu      $a2, $zero, 0x4
    /* 3B44 80106344 3000A927 */  addiu      $t1, $sp, 0x30
    /* 3B48 80106348 1080023C */  lui        $v0, %hi(vs_mainMenu_itemHelp)
    /* 3B4C 8010634C 4025488C */  lw         $t0, %lo(vs_mainMenu_itemHelp)($v0)
    /* 3B50 80106350 21282001 */  addu       $a1, $t1, $zero
    /* 3B54 80106354 925C0A25 */  addiu      $t2, $t0, 0x5C92
    /* 3B58 80106358 21200001 */  addu       $a0, $t0, $zero
  .L8010635C:
    /* 3B5C 8010635C 21182601 */  addu       $v1, $t1, $a2
    /* 3B60 80106360 0800C624 */  addiu      $a2, $a2, 0x8
    /* 3B64 80106364 50048294 */  lhu        $v0, 0x450($a0)
    /* 3B68 80106368 02008424 */  addiu      $a0, $a0, 0x2
    /* 3B6C 8010636C 01003126 */  addiu      $s1, $s1, 0x1
    /* 3B70 80106370 40100200 */  sll        $v0, $v0, 1
    /* 3B74 80106374 21100201 */  addu       $v0, $t0, $v0
    /* 3B78 80106378 0000A2AC */  sw         $v0, 0x0($a1)
    /* 3B7C 8010637C 00006AAC */  sw         $t2, 0x0($v1)
    /* 3B80 80106380 0000E0AC */  sw         $zero, 0x0($a3)
    /* 3B84 80106384 0400E724 */  addiu      $a3, $a3, 0x4
    /* 3B88 80106388 0200222A */  slti       $v0, $s1, 0x2
    /* 3B8C 8010638C F3FF4014 */  bnez       $v0, .L8010635C
    /* 3B90 80106390 0800A524 */   addiu     $a1, $a1, 0x8
    /* 3B94 80106394 02000424 */  addiu      $a0, $zero, 0x2
    /* 3B98 80106398 04000524 */  addiu      $a1, $zero, 0x4
    /* 3B9C 8010639C 3000A627 */  addiu      $a2, $sp, 0x30
    /* 3BA0 801063A0 3BFC030C */  jal        vs_mainMenu_initSortUi
    /* 3BA4 801063A4 4000A727 */   addiu     $a3, $sp, 0x40
    /* 3BA8 801063A8 1180033C */  lui        $v1, %hi(D_80109A4E)
    /* 3BAC 801063AC 07000224 */  addiu      $v0, $zero, 0x7
    /* 3BB0 801063B0 11190408 */  j          .L80106444
    /* 3BB4 801063B4 4E9A62A0 */   sb        $v0, %lo(D_80109A4E)($v1)
    /* 3BB8 801063B8 0FFD030C */  jal        vs_mainMenu_processItemActionMenu
    /* 3BBC 801063BC 00000000 */   nop
    /* 3BC0 801063C0 D8FC030C */  jal        vs_mainMenu_getSelectedItemAction
    /* 3BC4 801063C4 00000000 */   nop
    /* 3BC8 801063C8 01005124 */  addiu      $s1, $v0, 0x1
    /* 3BCC 801063CC 1D002012 */  beqz       $s1, .L80106444
    /* 3BD0 801063D0 01000224 */   addiu     $v0, $zero, 0x1
    /* 3BD4 801063D4 17002216 */  bne        $s1, $v0, .L80106434
    /* 3BD8 801063D8 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 3BDC 801063DC 6216010C */  jal        vs_main_playSfxDefault
    /* 3BE0 801063E0 1C000524 */   addiu     $a1, $zero, 0x1C
    /* 3BE4 801063E4 1180033C */  lui        $v1, %hi(vs_menuD_containerData)
    /* 3BE8 801063E8 1180023C */  lui        $v0, %hi(_discardIndex)
    /* 3BEC 801063EC 509A4590 */  lbu        $a1, %lo(_discardIndex)($v0)
    /* 3BF0 801063F0 8C9A668C */  lw         $a2, %lo(vs_menuD_containerData)($v1)
    /* 3BF4 801063F4 80100500 */  sll        $v0, $a1, 2
    /* 3BF8 801063F8 2120C200 */  addu       $a0, $a2, $v0
    /* 3BFC 801063FC 1180023C */  lui        $v0, %hi(_discardAmount)
    /* 3C00 80106400 02388390 */  lbu        $v1, 0x3802($a0)
    /* 3C04 80106404 539A4290 */  lbu        $v0, %lo(_discardAmount)($v0)
    /* 3C08 80106408 00000000 */  nop
    /* 3C0C 8010640C 07006214 */  bne        $v1, $v0, .L8010642C
    /* 3C10 80106410 23106200 */   subu      $v0, $v1, $v0
    /* 3C14 80106414 1180023C */  lui        $v0, %hi(_discardItemCategory)
    /* 3C18 80106418 4F9A4490 */  lbu        $a0, %lo(_discardItemCategory)($v0)
    /* 3C1C 8010641C 600B040C */  jal        _initContainerObject
    /* 3C20 80106420 00000000 */   nop
    /* 3C24 80106424 12190408 */  j          .L80106448
    /* 3C28 80106428 21102002 */   addu      $v0, $s1, $zero
  .L8010642C:
    /* 3C2C 8010642C 0F190408 */  j          .L8010643C
    /* 3C30 80106430 023882A0 */   sb        $v0, 0x3802($a0)
  .L80106434:
    /* 3C34 80106434 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 3C38 80106438 00000000 */   nop
  .L8010643C:
    /* 3C3C 8010643C 12190408 */  j          .L80106448
    /* 3C40 80106440 21102002 */   addu      $v0, $s1, $zero
  .L80106444:
    /* 3C44 80106444 21100000 */  addu       $v0, $zero, $zero
  .L80106448:
    /* 3C48 80106448 5800BF8F */  lw         $ra, 0x58($sp)
    /* 3C4C 8010644C 5400B38F */  lw         $s3, 0x54($sp)
    /* 3C50 80106450 5000B28F */  lw         $s2, 0x50($sp)
    /* 3C54 80106454 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 3C58 80106458 4800B08F */  lw         $s0, 0x48($sp)
    /* 3C5C 8010645C 0800E003 */  jr         $ra
    /* 3C60 80106460 6000BD27 */   addiu     $sp, $sp, 0x60
endlabel _discardMenu
