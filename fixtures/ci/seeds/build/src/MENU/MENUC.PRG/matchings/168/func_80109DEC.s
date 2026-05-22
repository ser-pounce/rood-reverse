nonmatching func_80109DEC, 0x850

glabel func_80109DEC
    /* 75EC 80109DEC B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 75F0 80109DF0 4400BFAF */  sw         $ra, 0x44($sp)
    /* 75F4 80109DF4 4000B6AF */  sw         $s6, 0x40($sp)
    /* 75F8 80109DF8 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 75FC 80109DFC 3800B4AF */  sw         $s4, 0x38($sp)
    /* 7600 80109E00 3400B3AF */  sw         $s3, 0x34($sp)
    /* 7604 80109E04 3000B2AF */  sw         $s2, 0x30($sp)
    /* 7608 80109E08 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 760C 80109E0C 0E008010 */  beqz       $a0, .L80109E48
    /* 7610 80109E10 2800B0AF */   sw        $s0, 0x28($sp)
    /* 7614 80109E14 8D0A040C */  jal        func_80102A34
    /* 7618 80109E18 05000424 */   addiu     $a0, $zero, 0x5
    /* 761C 80109E1C 21200000 */  addu       $a0, $zero, $zero
    /* 7620 80109E20 1180023C */  lui        $v0, %hi(D_8010BD7C)
    /* 7624 80109E24 E425040C */  jal        func_80109790
    /* 7628 80109E28 7CBD40A4 */   sh        $zero, %lo(D_8010BD7C)($v0)
    /* 762C 80109E2C 21100000 */  addu       $v0, $zero, $zero
    /* 7630 80109E30 1180043C */  lui        $a0, %hi(D_8010BC7B)
    /* 7634 80109E34 01000324 */  addiu      $v1, $zero, 0x1
    /* 7638 80109E38 7BBC83A0 */  sb         $v1, %lo(D_8010BC7B)($a0)
    /* 763C 80109E3C 1180033C */  lui        $v1, %hi(D_8010BC7A)
    /* 7640 80109E40 85290408 */  j          .L8010A614
    /* 7644 80109E44 7ABC60A0 */   sb        $zero, %lo(D_8010BC7A)($v1)
  .L80109E48:
    /* 7648 80109E48 21880000 */  addu       $s1, $zero, $zero
    /* 764C 80109E4C 1180023C */  lui        $v0, %hi(D_8010BD7C)
    /* 7650 80109E50 7CBD4390 */  lbu        $v1, %lo(D_8010BD7C)($v0)
    /* 7654 80109E54 00000000 */  nop
    /* 7658 80109E58 04006010 */  beqz       $v1, .L80109E6C
    /* 765C 80109E5C 7CBD4224 */   addiu     $v0, $v0, %lo(D_8010BD7C)
    /* 7660 80109E60 01004290 */  lbu        $v0, 0x1($v0)
    /* 7664 80109E64 00000000 */  nop
    /* 7668 80109E68 2B882202 */  sltu       $s1, $s1, $v0
  .L80109E6C:
    /* 766C 80109E6C 1180043C */  lui        $a0, %hi(D_8010BC7C)
    /* 7670 80109E70 1180053C */  lui        $a1, %hi(D_8010BC7A)
    /* 7674 80109E74 7CBC8290 */  lbu        $v0, %lo(D_8010BC7C)($a0)
    /* 7678 80109E78 7ABCA390 */  lbu        $v1, %lo(D_8010BC7A)($a1)
    /* 767C 80109E7C 10004224 */  addiu      $v0, $v0, 0x10
    /* 7680 80109E80 7CBC82A0 */  sb         $v0, %lo(D_8010BC7C)($a0)
    /* 7684 80109E84 02000224 */  addiu      $v0, $zero, 0x2
    /* 7688 80109E88 02006210 */  beq        $v1, $v0, .L80109E94
    /* 768C 80109E8C 00000000 */   nop
    /* 7690 80109E90 7CBC80A0 */  sb         $zero, %lo(D_8010BC7C)($a0)
  .L80109E94:
    /* 7694 80109E94 7ABCA390 */  lbu        $v1, %lo(D_8010BC7A)($a1)
    /* 7698 80109E98 00000000 */  nop
    /* 769C 80109E9C 0600622C */  sltiu      $v0, $v1, 0x6
    /* 76A0 80109EA0 DB014010 */  beqz       $v0, .L8010A610
    /* 76A4 80109EA4 1080023C */   lui       $v0, %hi(jtbl_801028F0)
    /* 76A8 80109EA8 F0284224 */  addiu      $v0, $v0, %lo(jtbl_801028F0)
    /* 76AC 80109EAC 80180300 */  sll        $v1, $v1, 2
    /* 76B0 80109EB0 21186200 */  addu       $v1, $v1, $v0
    /* 76B4 80109EB4 0000628C */  lw         $v0, 0x0($v1)
    /* 76B8 80109EB8 00000000 */  nop
    /* 76BC 80109EBC 08004000 */  jr         $v0
    /* 76C0 80109EC0 00000000 */   nop
    /* 76C4 80109EC4 74EA030C */  jal        vs_mainmenu_ready
    /* 76C8 80109EC8 00000000 */   nop
    /* 76CC 80109ECC D0014010 */  beqz       $v0, .L8010A610
    /* 76D0 80109ED0 97040424 */   addiu     $a0, $zero, 0x497
    /* 76D4 80109ED4 D40A040C */  jal        func_80102B50
    /* 76D8 80109ED8 1C000524 */   addiu     $a1, $zero, 0x1C
    /* 76DC 80109EDC 1180023C */  lui        $v0, %hi(D_8010BD54)
    /* 76E0 80109EE0 54BD5190 */  lbu        $s1, %lo(D_8010BD54)($v0)
    /* 76E4 80109EE4 02000424 */  addiu      $a0, $zero, 0x2
    /* 76E8 80109EE8 54BD5024 */  addiu      $s0, $v0, %lo(D_8010BD54)
    /* 76EC 80109EEC 171E040C */  jal        func_8010785C
    /* 76F0 80109EF0 21282002 */   addu      $a1, $s1, $zero
    /* 76F4 80109EF4 03002012 */  beqz       $s1, .L80109F04
    /* 76F8 80109EF8 21204000 */   addu      $a0, $v0, $zero
    /* 76FC 80109EFC 6F27040C */  jal        func_80109DBC
    /* 7700 80109F00 21280002 */   addu      $a1, $s0, $zero
  .L80109F04:
    /* 7704 80109F04 21800000 */  addu       $s0, $zero, $zero
    /* 7708 80109F08 1180023C */  lui        $v0, %hi(D_8010BD7C)
    /* 770C 80109F0C 7CBD5624 */  addiu      $s6, $v0, %lo(D_8010BD7C)
    /* 7710 80109F10 0680023C */  lui        $v0, %hi(D_80060780)
    /* 7714 80109F14 80075524 */  addiu      $s5, $v0, %lo(D_80060780)
    /* 7718 80109F18 1080143C */  lui        $s4, %hi(vs_mainMenu_itemNames)
    /* 771C 80109F1C 22001224 */  addiu      $s2, $zero, 0x22
  .L80109F20:
    /* 7720 80109F20 21101602 */  addu       $v0, $s0, $s6
    /* 7724 80109F24 00005190 */  lbu        $s1, 0x0($v0)
    /* 7728 80109F28 00000000 */  nop
    /* 772C 80109F2C 04002012 */  beqz       $s1, .L80109F40
    /* 7730 80109F30 80101100 */   sll       $v0, $s1, 2
    /* 7734 80109F34 21105100 */  addu       $v0, $v0, $s1
    /* 7738 80109F38 C0100200 */  sll        $v0, $v0, 3
    /* 773C 80109F3C 21985500 */  addu       $s3, $v0, $s5
  .L80109F40:
    /* 7740 80109F40 1000A0AF */  sw         $zero, 0x10($sp)
    /* 7744 80109F44 0B000426 */  addiu      $a0, $s0, 0xB
    /* 7748 80109F48 05002016 */  bnez       $s1, .L80109F60
    /* 774C 80109F4C 21304002 */   addu      $a2, $s2, $zero
    /* 7750 80109F50 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 7754 80109F54 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 7758 80109F58 DF270408 */  j          .L80109F7C
    /* 775C 80109F5C 7A084224 */   addiu     $v0, $v0, 0x87A
  .L80109F60:
    /* 7760 80109F60 00006292 */  lbu        $v0, 0x0($s3)
    /* 7764 80109F64 00000000 */  nop
    /* 7768 80109F68 40180200 */  sll        $v1, $v0, 1
    /* 776C 80109F6C 21186200 */  addu       $v1, $v1, $v0
    /* 7770 80109F70 9C22828E */  lw         $v0, %lo(vs_mainMenu_itemNames)($s4)
    /* 7774 80109F74 C0180300 */  sll        $v1, $v1, 3
    /* 7778 80109F78 21104300 */  addu       $v0, $v0, $v1
  .L80109F7C:
    /* 777C 80109F7C 1400A2AF */  sw         $v0, 0x14($sp)
    /* 7780 80109F80 4E010524 */  addiu      $a1, $zero, 0x14E
    /* 7784 80109F84 9723030C */  jal        vs_battle_setMenuItem
    /* 7788 80109F88 97000724 */   addiu     $a3, $zero, 0x97
    /* 778C 80109F8C 21204000 */  addu       $a0, $v0, $zero
    /* 7790 80109F90 02000224 */  addiu      $v0, $zero, 0x2
    /* 7794 80109F94 000082A0 */  sb         $v0, 0x0($a0)
    /* 7798 80109F98 A9000224 */  addiu      $v0, $zero, 0xA9
    /* 779C 80109F9C 04002016 */  bnez       $s1, .L80109FB0
    /* 77A0 80109FA0 180082A4 */   sh        $v0, 0x18($a0)
    /* 77A4 80109FA4 01000224 */  addiu      $v0, $zero, 0x1
    /* 77A8 80109FA8 EE270408 */  j          .L80109FB8
    /* 77AC 80109FAC 0A0082A0 */   sb        $v0, 0xA($a0)
  .L80109FB0:
    /* 77B0 80109FB0 6F27040C */  jal        func_80109DBC
    /* 77B4 80109FB4 21286002 */   addu      $a1, $s3, $zero
  .L80109FB8:
    /* 77B8 80109FB8 01001026 */  addiu      $s0, $s0, 0x1
    /* 77BC 80109FBC 0200022A */  slti       $v0, $s0, 0x2
    /* 77C0 80109FC0 D7FF4014 */  bnez       $v0, .L80109F20
    /* 77C4 80109FC4 10005226 */   addiu     $s2, $s2, 0x10
    /* 77C8 80109FC8 02000324 */  addiu      $v1, $zero, 0x2
    /* 77CC 80109FCC 1180023C */  lui        $v0, %hi(D_8010BC7A)
    /* 77D0 80109FD0 84290408 */  j          .L8010A610
    /* 77D4 80109FD4 7ABC43A0 */   sb        $v1, %lo(D_8010BC7A)($v0)
    /* 77D8 80109FD8 74EA030C */  jal        vs_mainmenu_ready
    /* 77DC 80109FDC 00000000 */   nop
    /* 77E0 80109FE0 E1004010 */  beqz       $v0, .L8010A368
    /* 77E4 80109FE4 0680103C */   lui       $s0, %hi(vs_main_buttonsPressed)
    /* 77E8 80109FE8 D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 77EC 80109FEC 00000000 */  nop
    /* 77F0 80109FF0 10004230 */  andi       $v0, $v0, 0x10
    /* 77F4 80109FF4 82014014 */  bnez       $v0, .L8010A600
    /* 77F8 80109FF8 00000000 */   nop
    /* 77FC 80109FFC 04002012 */  beqz       $s1, .L8010A010
    /* 7800 8010A000 1180023C */   lui       $v0, %hi(D_8010BC7C)
    /* 7804 8010A004 7CBC4590 */  lbu        $a1, %lo(D_8010BC7C)($v0)
    /* 7808 8010A008 5A0A040C */  jal        func_80102968
    /* 780C 8010A00C 02000424 */   addiu     $a0, $zero, 0x2
  .L8010A010:
    /* 7810 8010A010 D0E1038E */  lw         $v1, %lo(vs_main_buttonsPressed)($s0)
    /* 7814 8010A014 00000000 */  nop
    /* 7818 8010A018 40006230 */  andi       $v0, $v1, 0x40
    /* 781C 8010A01C 2B004010 */  beqz       $v0, .L8010A0CC
    /* 7820 8010A020 00086230 */   andi      $v0, $v1, 0x800
    /* 7824 8010A024 AE0A040C */  jal        func_80102AB8
    /* 7828 8010A028 05000424 */   addiu     $a0, $zero, 0x5
    /* 782C 8010A02C 21804000 */  addu       $s0, $v0, $zero
    /* 7830 8010A030 73010012 */  beqz       $s0, .L8010A600
    /* 7834 8010A034 00000000 */   nop
    /* 7838 8010A038 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 783C 8010A03C 00000000 */   nop
    /* 7840 8010A040 21200002 */  addu       $a0, $s0, $zero
    /* 7844 8010A044 1180023C */  lui        $v0, %hi(D_8010BC7B)
    /* 7848 8010A048 7BBC50A0 */  sb         $s0, %lo(D_8010BC7B)($v0)
    /* 784C 8010A04C 1180023C */  lui        $v0, %hi(D_8010BD7C)
    /* 7850 8010A050 7CBD4224 */  addiu      $v0, $v0, %lo(D_8010BD7C)
    /* 7854 8010A054 21100202 */  addu       $v0, $s0, $v0
    /* 7858 8010A058 E425040C */  jal        func_80109790
    /* 785C 8010A05C FFFF40A0 */   sb        $zero, -0x1($v0)
    /* 7860 8010A060 0A000426 */  addiu      $a0, $s0, 0xA
    /* 7864 8010A064 A9000524 */  addiu      $a1, $zero, 0xA9
    /* 7868 8010A068 00311000 */  sll        $a2, $s0, 4
    /* 786C 8010A06C 1200C624 */  addiu      $a2, $a2, 0x12
    /* 7870 8010A070 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 7874 8010A074 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 7878 8010A078 97000724 */  addiu      $a3, $zero, 0x97
    /* 787C 8010A07C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 7880 8010A080 7A084224 */  addiu      $v0, $v0, 0x87A
    /* 7884 8010A084 9723030C */  jal        vs_battle_setMenuItem
    /* 7888 8010A088 1400A2AF */   sw        $v0, 0x14($sp)
    /* 788C 8010A08C 21204000 */  addu       $a0, $v0, $zero
    /* 7890 8010A090 01000224 */  addiu      $v0, $zero, 0x1
    /* 7894 8010A094 060082A0 */  sb         $v0, 0x6($a0)
    /* 7898 8010A098 0A0082A0 */  sb         $v0, 0xA($a0)
    /* 789C 8010A09C 1180023C */  lui        $v0, %hi(D_8010BD54)
    /* 78A0 8010A0A0 02000424 */  addiu      $a0, $zero, 0x2
    /* 78A4 8010A0A4 54BD5190 */  lbu        $s1, %lo(D_8010BD54)($v0)
    /* 78A8 8010A0A8 54BD5024 */  addiu      $s0, $v0, %lo(D_8010BD54)
    /* 78AC 8010A0AC F71D040C */  jal        func_801077DC
    /* 78B0 8010A0B0 21282002 */   addu      $a1, $s1, $zero
    /* 78B4 8010A0B4 56012012 */  beqz       $s1, .L8010A610
    /* 78B8 8010A0B8 21204000 */   addu      $a0, $v0, $zero
    /* 78BC 8010A0BC 6F27040C */  jal        func_80109DBC
    /* 78C0 8010A0C0 21280002 */   addu      $a1, $s0, $zero
    /* 78C4 8010A0C4 85290408 */  j          .L8010A614
    /* 78C8 8010A0C8 21100000 */   addu      $v0, $zero, $zero
  .L8010A0CC:
    /* 78CC 8010A0CC 12004010 */  beqz       $v0, .L8010A118
    /* 78D0 8010A0D0 1180033C */   lui       $v1, %hi(D_8010BC7B)
    /* 78D4 8010A0D4 11002012 */  beqz       $s1, .L8010A11C
    /* 78D8 8010A0D8 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 78DC 8010A0DC BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 78E0 8010A0E0 1180103C */   lui       $s0, %hi(D_8010BC7B)
    /* 78E4 8010A0E4 7BBC0492 */  lbu        $a0, %lo(D_8010BC7B)($s0)
    /* 78E8 8010A0E8 9223030C */  jal        vs_battle_getMenuItem
    /* 78EC 8010A0EC 0A008424 */   addiu     $a0, $a0, 0xA
    /* 78F0 8010A0F0 03000424 */  addiu      $a0, $zero, 0x3
    /* 78F4 8010A0F4 060040A0 */  sb         $zero, 0x6($v0)
    /* 78F8 8010A0F8 21108000 */  addu       $v0, $a0, $zero
    /* 78FC 8010A0FC 1180033C */  lui        $v1, %hi(D_8010BC7A)
    /* 7900 8010A100 7BBC02A2 */  sb         $v0, %lo(D_8010BC7B)($s0)
    /* 7904 8010A104 04000224 */  addiu      $v0, $zero, 0x4
    /* 7908 8010A108 E425040C */  jal        func_80109790
    /* 790C 8010A10C 7ABC62A0 */   sb        $v0, %lo(D_8010BC7A)($v1)
    /* 7910 8010A110 85290408 */  j          .L8010A614
    /* 7914 8010A114 21100000 */   addu      $v0, $zero, $zero
  .L8010A118:
    /* 7918 8010A118 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
  .L8010A11C:
    /* 791C 8010A11C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 7920 8010A120 7BBC7090 */  lbu        $s0, %lo(D_8010BC7B)($v1)
    /* 7924 8010A124 20004230 */  andi       $v0, $v0, 0x20
    /* 7928 8010A128 15004010 */  beqz       $v0, .L8010A180
    /* 792C 8010A12C 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 7930 8010A130 05000016 */  bnez       $s0, .L8010A148
    /* 7934 8010A134 00000000 */   nop
    /* 7938 8010A138 B800030C */  jal        vs_battle_playInvalidSfx
    /* 793C 8010A13C 00000000 */   nop
    /* 7940 8010A140 60280408 */  j          .L8010A180
    /* 7944 8010A144 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
  .L8010A148:
    /* 7948 8010A148 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 794C 8010A14C 03001124 */   addiu     $s1, $zero, 0x3
    /* 7950 8010A150 04001116 */  bne        $s0, $s1, .L8010A164
    /* 7954 8010A154 1180033C */   lui       $v1, %hi(D_8010BC7A)
    /* 7958 8010A158 04000224 */  addiu      $v0, $zero, 0x4
    /* 795C 8010A15C 84290408 */  j          .L8010A610
    /* 7960 8010A160 7ABC62A0 */   sb        $v0, %lo(D_8010BC7A)($v1)
  .L8010A164:
    /* 7964 8010A164 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 7968 8010A168 28000424 */   addiu     $a0, $zero, 0x28
    /* 796C 8010A16C 7F26040C */  jal        func_801099FC
    /* 7970 8010A170 21200002 */   addu      $a0, $s0, $zero
    /* 7974 8010A174 1180023C */  lui        $v0, %hi(D_8010BC7A)
    /* 7978 8010A178 84290408 */  j          .L8010A610
    /* 797C 8010A17C 7ABC51A0 */   sb        $s1, %lo(D_8010BC7A)($v0)
  .L8010A180:
    /* 7980 8010A180 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 7984 8010A184 00000000 */  nop
    /* 7988 8010A188 00104230 */  andi       $v0, $v0, 0x1000
    /* 798C 8010A18C 04004010 */  beqz       $v0, .L8010A1A0
    /* 7990 8010A190 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 7994 8010A194 02000016 */  bnez       $s0, .L8010A1A0
    /* 7998 8010A198 FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 799C 8010A19C 02003026 */  addiu      $s0, $s1, 0x2
  .L8010A1A0:
    /* 79A0 8010A1A0 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 79A4 8010A1A4 00000000 */  nop
    /* 79A8 8010A1A8 00404230 */  andi       $v0, $v0, 0x4000
    /* 79AC 8010A1AC 04004010 */  beqz       $v0, .L8010A1C0
    /* 79B0 8010A1B0 02002226 */   addiu     $v0, $s1, 0x2
    /* 79B4 8010A1B4 02000216 */  bne        $s0, $v0, .L8010A1C0
    /* 79B8 8010A1B8 01001026 */   addiu     $s0, $s0, 0x1
    /* 79BC 8010A1BC 21800000 */  addu       $s0, $zero, $zero
  .L8010A1C0:
    /* 79C0 8010A1C0 1180123C */  lui        $s2, %hi(D_8010BC7B)
    /* 79C4 8010A1C4 7BBC4292 */  lbu        $v0, %lo(D_8010BC7B)($s2)
    /* 79C8 8010A1C8 00000000 */  nop
    /* 79CC 8010A1CC 06000212 */  beq        $s0, $v0, .L8010A1E8
    /* 79D0 8010A1D0 01001124 */   addiu     $s1, $zero, 0x1
    /* 79D4 8010A1D4 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 79D8 8010A1D8 00000000 */   nop
    /* 79DC 8010A1DC 7BBC50A2 */  sb         $s0, %lo(D_8010BC7B)($s2)
    /* 79E0 8010A1E0 E425040C */  jal        func_80109790
    /* 79E4 8010A1E4 FF000432 */   andi      $a0, $s0, 0xFF
  .L8010A1E8:
    /* 79E8 8010A1E8 21A04002 */  addu       $s4, $s2, $zero
    /* 79EC 8010A1EC 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 79F0 8010A1F0 21904000 */  addu       $s2, $v0, $zero
    /* 79F4 8010A1F4 1180023C */  lui        $v0, %hi(D_8010BD7C)
    /* 79F8 8010A1F8 7CBD5324 */  addiu      $s3, $v0, %lo(D_8010BD7C)
    /* 79FC 8010A1FC 1180023C */  lui        $v0, %hi(D_8010BD54)
    /* 7A00 8010A200 54BD4290 */  lbu        $v0, %lo(D_8010BD54)($v0)
    /* 7A04 8010A204 844E438E */  lw         $v1, %lo(vs_battle_rowTypeBuf)($s2)
    /* 7A08 8010A208 2B105100 */  sltu       $v0, $v0, $s1
    /* 7A0C 8010A20C 000062AC */  sw         $v0, 0x0($v1)
  .L8010A210:
    /* 7A10 8010A210 9223030C */  jal        vs_battle_getMenuItem
    /* 7A14 8010A214 0A002426 */   addiu     $a0, $s1, 0xA
    /* 7A18 8010A218 80201100 */  sll        $a0, $s1, 2
    /* 7A1C 8010A21C 7BBC8392 */  lbu        $v1, %lo(D_8010BC7B)($s4)
    /* 7A20 8010A220 21283302 */  addu       $a1, $s1, $s3
    /* 7A24 8010A224 26182302 */  xor        $v1, $s1, $v1
    /* 7A28 8010A228 01003126 */  addiu      $s1, $s1, 0x1
    /* 7A2C 8010A22C 0100632C */  sltiu      $v1, $v1, 0x1
    /* 7A30 8010A230 060043A0 */  sb         $v1, 0x6($v0)
    /* 7A34 8010A234 844E438E */  lw         $v1, %lo(vs_battle_rowTypeBuf)($s2)
    /* 7A38 8010A238 FFFFA290 */  lbu        $v0, -0x1($a1)
    /* 7A3C 8010A23C 21208300 */  addu       $a0, $a0, $v1
    /* 7A40 8010A240 0100422C */  sltiu      $v0, $v0, 0x1
    /* 7A44 8010A244 000082AC */  sw         $v0, 0x0($a0)
    /* 7A48 8010A248 0300222A */  slti       $v0, $s1, 0x3
    /* 7A4C 8010A24C F0FF4014 */  bnez       $v0, .L8010A210
    /* 7A50 8010A250 21200002 */   addu      $a0, $s0, $zero
    /* 7A54 8010A254 10000524 */  addiu      $a1, $zero, 0x10
    /* 7A58 8010A258 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 7A5C 8010A25C 844E438C */  lw         $v1, %lo(vs_battle_rowTypeBuf)($v0)
    /* 7A60 8010A260 01000224 */  addiu      $v0, $zero, 0x1
    /* 7A64 8010A264 79FE030C */  jal        vs_mainMenu_printInformation
    /* 7A68 8010A268 0C0062AC */   sw        $v0, 0xC($v1)
    /* 7A6C 8010A26C 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 7A70 8010A270 A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 7A74 8010A274 00000000 */  nop
    /* 7A78 8010A278 D4086224 */  addiu      $v0, $v1, 0x8D4
    /* 7A7C 8010A27C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 7A80 8010A280 0300022A */  slti       $v0, $s0, 0x3
    /* 7A84 8010A284 07004010 */  beqz       $v0, .L8010A2A4
    /* 7A88 8010A288 00000000 */   nop
    /* 7A8C 8010A28C 1000001E */  bgtz       $s0, .L8010A2D0
    /* 7A90 8010A290 1180023C */   lui       $v0, %hi(D_8010BD7C)
    /* 7A94 8010A294 08000012 */  beqz       $s0, .L8010A2B8
    /* 7A98 8010A298 1180023C */   lui       $v0, %hi(D_8010BD54)
    /* 7A9C 8010A29C C7280408 */  j          .L8010A31C
    /* 7AA0 8010A2A0 00000000 */   nop
  .L8010A2A4:
    /* 7AA4 8010A2A4 03000224 */  addiu      $v0, $zero, 0x3
    /* 7AA8 8010A2A8 1B000212 */  beq        $s0, $v0, .L8010A318
    /* 7AAC 8010A2AC 3C076224 */   addiu     $v0, $v1, 0x73C
    /* 7AB0 8010A2B0 C7280408 */  j          .L8010A31C
    /* 7AB4 8010A2B4 00000000 */   nop
  .L8010A2B8:
    /* 7AB8 8010A2B8 54BD4390 */  lbu        $v1, %lo(D_8010BD54)($v0)
    /* 7ABC 8010A2BC 00000000 */  nop
    /* 7AC0 8010A2C0 16006010 */  beqz       $v1, .L8010A31C
    /* 7AC4 8010A2C4 54BD4424 */   addiu     $a0, $v0, %lo(D_8010BD54)
    /* 7AC8 8010A2C8 C0280408 */  j          .L8010A300
    /* 7ACC 8010A2CC 1800A527 */   addiu     $a1, $sp, 0x18
  .L8010A2D0:
    /* 7AD0 8010A2D0 7CBD4224 */  addiu      $v0, $v0, %lo(D_8010BD7C)
    /* 7AD4 8010A2D4 21100202 */  addu       $v0, $s0, $v0
    /* 7AD8 8010A2D8 FFFF5190 */  lbu        $s1, -0x1($v0)
    /* 7ADC 8010A2DC 00000000 */  nop
    /* 7AE0 8010A2E0 0E002012 */  beqz       $s1, .L8010A31C
    /* 7AE4 8010A2E4 80101100 */   sll       $v0, $s1, 2
    /* 7AE8 8010A2E8 21105100 */  addu       $v0, $v0, $s1
    /* 7AEC 8010A2EC C0100200 */  sll        $v0, $v0, 3
    /* 7AF0 8010A2F0 0680043C */  lui        $a0, %hi(D_80060780)
    /* 7AF4 8010A2F4 80078424 */  addiu      $a0, $a0, %lo(D_80060780)
    /* 7AF8 8010A2F8 21204400 */  addu       $a0, $v0, $a0
    /* 7AFC 8010A2FC 1800A527 */  addiu      $a1, $sp, 0x18
  .L8010A300:
    /* 7B00 8010A300 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 7B04 8010A304 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 7B08 8010A308 21F4030C */  jal        vs_mainMenu_initUiArmor
    /* 7B0C 8010A30C 2000A627 */   addiu     $a2, $sp, 0x20
    /* 7B10 8010A310 C7280408 */  j          .L8010A31C
    /* 7B14 8010A314 00000000 */   nop
  .L8010A318:
    /* 7B18 8010A318 1C00A2AF */  sw         $v0, 0x1C($sp)
  .L8010A31C:
    /* 7B1C 8010A31C 1C00A48F */  lw         $a0, 0x1C($sp)
    /* 7B20 8010A320 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 7B24 8010A324 00000000 */   nop
    /* 7B28 8010A328 00111000 */  sll        $v0, $s0, 4
    /* 7B2C 8010A32C 0A004224 */  addiu      $v0, $v0, 0xA
    /* 7B30 8010A330 00140200 */  sll        $v0, $v0, 16
    /* 7B34 8010A334 02000016 */  bnez       $s0, .L8010A340
    /* 7B38 8010A338 9B005134 */   ori       $s1, $v0, 0x9B
    /* 7B3C 8010A33C F2FF3126 */  addiu      $s1, $s1, -0xE
  .L8010A340:
    /* 7B40 8010A340 03000224 */  addiu      $v0, $zero, 0x3
    /* 7B44 8010A344 03000216 */  bne        $s0, $v0, .L8010A354
    /* 7B48 8010A348 1180103C */   lui       $s0, %hi(D_8010BB76)
    /* 7B4C 8010A34C FCFF023C */  lui        $v0, (0xFFFC0000 >> 16)
    /* 7B50 8010A350 21882202 */  addu       $s1, $s1, $v0
  .L8010A354:
    /* 7B54 8010A354 76BB0492 */  lbu        $a0, %lo(D_8010BB76)($s0)
    /* 7B58 8010A358 37FF030C */  jal        func_800FFCDC
    /* 7B5C 8010A35C 21282002 */   addu      $a1, $s1, $zero
    /* 7B60 8010A360 84290408 */  j          .L8010A610
    /* 7B64 8010A364 76BB02A2 */   sb        $v0, %lo(D_8010BB76)($s0)
  .L8010A368:
    /* 7B68 8010A368 1180023C */  lui        $v0, %hi(D_8010BC7C)
    /* 7B6C 8010A36C 84290408 */  j          .L8010A610
    /* 7B70 8010A370 7CBC40A0 */   sb        $zero, %lo(D_8010BC7C)($v0)
    /* 7B74 8010A374 7F26040C */  jal        func_801099FC
    /* 7B78 8010A378 21200000 */   addu      $a0, $zero, $zero
    /* 7B7C 8010A37C 21804000 */  addu       $s0, $v0, $zero
    /* 7B80 8010A380 A3000012 */  beqz       $s0, .L8010A610
    /* 7B84 8010A384 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 7B88 8010A388 9D000212 */  beq        $s0, $v0, .L8010A600
    /* 7B8C 8010A38C 00000000 */   nop
    /* 7B90 8010A390 2000001A */  blez       $s0, .L8010A414
    /* 7B94 8010A394 1180123C */   lui       $s2, %hi(D_8010BC7B)
    /* 7B98 8010A398 7BBC4292 */  lbu        $v0, %lo(D_8010BC7B)($s2)
    /* 7B9C 8010A39C 1180133C */  lui        $s3, %hi(D_8010BD7C)
    /* 7BA0 8010A3A0 FFFF5124 */  addiu      $s1, $v0, -0x1
    /* 7BA4 8010A3A4 7CBD6226 */  addiu      $v0, $s3, %lo(D_8010BD7C)
    /* 7BA8 8010A3A8 21182202 */  addu       $v1, $s1, $v0
    /* 7BAC 8010A3AC 00006290 */  lbu        $v0, 0x0($v1)
    /* 7BB0 8010A3B0 00000000 */  nop
    /* 7BB4 8010A3B4 06000216 */  bne        $s0, $v0, .L8010A3D0
    /* 7BB8 8010A3B8 21202002 */   addu      $a0, $s1, $zero
    /* 7BBC 8010A3BC 000060A0 */  sb         $zero, 0x0($v1)
    /* 7BC0 8010A3C0 AE0A040C */  jal        func_80102AB8
    /* 7BC4 8010A3C4 21202002 */   addu      $a0, $s1, $zero
    /* 7BC8 8010A3C8 02290408 */  j          .L8010A408
    /* 7BCC 8010A3CC 1180023C */   lui       $v0, %hi(D_8010BC7B)
  .L8010A3D0:
    /* 7BD0 8010A3D0 8D0A040C */  jal        func_80102A34
    /* 7BD4 8010A3D4 000070A0 */   sb        $s0, 0x0($v1)
    /* 7BD8 8010A3D8 7BBC4292 */  lbu        $v0, %lo(D_8010BC7B)($s2)
    /* 7BDC 8010A3DC 00000000 */  nop
    /* 7BE0 8010A3E0 01004224 */  addiu      $v0, $v0, 0x1
    /* 7BE4 8010A3E4 7BBC42A2 */  sb         $v0, %lo(D_8010BC7B)($s2)
    /* 7BE8 8010A3E8 01000224 */  addiu      $v0, $zero, 0x1
    /* 7BEC 8010A3EC 06002216 */  bne        $s1, $v0, .L8010A408
    /* 7BF0 8010A3F0 1180023C */   lui       $v0, %hi(D_8010BC7B)
    /* 7BF4 8010A3F4 7CBD6292 */  lbu        $v0, %lo(D_8010BD7C)($s3)
    /* 7BF8 8010A3F8 00000000 */  nop
    /* 7BFC 8010A3FC 02004014 */  bnez       $v0, .L8010A408
    /* 7C00 8010A400 1180023C */   lui       $v0, %hi(D_8010BC7B)
    /* 7C04 8010A404 7BBC51A2 */  sb         $s1, %lo(D_8010BC7B)($s2)
  .L8010A408:
    /* 7C08 8010A408 7BBC4490 */  lbu        $a0, %lo(D_8010BC7B)($v0)
    /* 7C0C 8010A40C E425040C */  jal        func_80109790
    /* 7C10 8010A410 00000000 */   nop
  .L8010A414:
    /* 7C14 8010A414 1180033C */  lui        $v1, %hi(D_8010BC7A)
    /* 7C18 8010A418 01000224 */  addiu      $v0, $zero, 0x1
    /* 7C1C 8010A41C 84290408 */  j          .L8010A610
    /* 7C20 8010A420 7ABC62A0 */   sb        $v0, %lo(D_8010BC7A)($v1)
    /* 7C24 8010A424 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 7C28 8010A428 02000424 */   addiu     $a0, $zero, 0x2
    /* 7C2C 8010A42C 900B040C */  jal        func_80102E40
    /* 7C30 8010A430 02000424 */   addiu     $a0, $zero, 0x2
    /* 7C34 8010A434 21880000 */  addu       $s1, $zero, $zero
    /* 7C38 8010A438 21802002 */  addu       $s0, $s1, $zero
    /* 7C3C 8010A43C 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 7C40 8010A440 68014524 */  addiu      $a1, $v0, %lo(vs_battle_inventory)
    /* 7C44 8010A444 1180023C */  lui        $v0, %hi(D_8010BD7C)
    /* 7C48 8010A448 7CBD4424 */  addiu      $a0, $v0, %lo(D_8010BD7C)
    /* 7C4C 8010A44C 21100402 */  addu       $v0, $s0, $a0
  .L8010A450:
    /* 7C50 8010A450 00004390 */  lbu        $v1, 0x0($v0)
    /* 7C54 8010A454 00000000 */  nop
    /* 7C58 8010A458 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 7C5C 8010A45C 80100300 */  sll        $v0, $v1, 2
    /* 7C60 8010A460 21104300 */  addu       $v0, $v0, $v1
    /* 7C64 8010A464 C0100200 */  sll        $v0, $v0, 3
    /* 7C68 8010A468 21104500 */  addu       $v0, $v0, $a1
    /* 7C6C 8010A46C 66064290 */  lbu        $v0, 0x666($v0)
    /* 7C70 8010A470 01001026 */  addiu      $s0, $s0, 0x1
    /* 7C74 8010A474 25882202 */  or         $s1, $s1, $v0
    /* 7C78 8010A478 0200022A */  slti       $v0, $s0, 0x2
    /* 7C7C 8010A47C F4FF4014 */  bnez       $v0, .L8010A450
    /* 7C80 8010A480 21100402 */   addu      $v0, $s0, $a0
    /* 7C84 8010A484 04002016 */  bnez       $s1, .L8010A498
    /* 7C88 8010A488 1080023C */   lui       $v0, %hi(vs_mainMenu_menu12Text)
    /* 7C8C 8010A48C A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 7C90 8010A490 29290408 */  j          .L8010A4A4
    /* 7C94 8010A494 56084424 */   addiu     $a0, $v0, 0x856
  .L8010A498:
    /* 7C98 8010A498 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 7C9C 8010A49C 00000000 */  nop
    /* 7CA0 8010A4A0 4E094424 */  addiu      $a0, $v0, 0x94E
  .L8010A4A4:
    /* 7CA4 8010A4A4 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 7CA8 8010A4A8 00000000 */   nop
    /* 7CAC 8010A4AC 1180033C */  lui        $v1, %hi(D_8010BC7A)
    /* 7CB0 8010A4B0 05000224 */  addiu      $v0, $zero, 0x5
    /* 7CB4 8010A4B4 84290408 */  j          .L8010A610
    /* 7CB8 8010A4B8 7ABC62A0 */   sb        $v0, %lo(D_8010BC7A)($v1)
    /* 7CBC 8010A4BC 900B040C */  jal        func_80102E40
    /* 7CC0 8010A4C0 21200000 */   addu      $a0, $zero, $zero
    /* 7CC4 8010A4C4 21804000 */  addu       $s0, $v0, $zero
    /* 7CC8 8010A4C8 51000012 */  beqz       $s0, .L8010A610
    /* 7CCC 8010A4CC 02000224 */   addiu     $v0, $zero, 0x2
    /* 7CD0 8010A4D0 44000212 */  beq        $s0, $v0, .L8010A5E4
    /* 7CD4 8010A4D4 0300022A */   slti      $v0, $s0, 0x3
    /* 7CD8 8010A4D8 05004010 */  beqz       $v0, .L8010A4F0
    /* 7CDC 8010A4DC 01000224 */   addiu     $v0, $zero, 0x1
    /* 7CE0 8010A4E0 08000212 */  beq        $s0, $v0, .L8010A504
    /* 7CE4 8010A4E4 21100000 */   addu      $v0, $zero, $zero
    /* 7CE8 8010A4E8 85290408 */  j          .L8010A614
    /* 7CEC 8010A4EC 00000000 */   nop
  .L8010A4F0:
    /* 7CF0 8010A4F0 03000224 */  addiu      $v0, $zero, 0x3
    /* 7CF4 8010A4F4 42000212 */  beq        $s0, $v0, .L8010A600
    /* 7CF8 8010A4F8 21100000 */   addu      $v0, $zero, $zero
    /* 7CFC 8010A4FC 85290408 */  j          .L8010A614
    /* 7D00 8010A500 00000000 */   nop
  .L8010A504:
    /* 7D04 8010A504 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 7D08 8010A508 6216010C */  jal        vs_main_playSfxDefault
    /* 7D0C 8010A50C 18000524 */   addiu     $a1, $zero, 0x18
    /* 7D10 8010A510 F2FE030C */  jal        func_800FFBC8
    /* 7D14 8010A514 21800000 */   addu      $s0, $zero, $zero
    /* 7D18 8010A518 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 7D1C 8010A51C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 7D20 8010A520 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 7D24 8010A524 04000424 */   addiu     $a0, $zero, 0x4
    /* 7D28 8010A528 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 7D2C 8010A52C 28000424 */   addiu     $a0, $zero, 0x28
    /* 7D30 8010A530 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 7D34 8010A534 21200000 */   addu      $a0, $zero, $zero
    /* 7D38 8010A538 1180023C */  lui        $v0, %hi(D_8010BD7C)
    /* 7D3C 8010A53C 7CBD5524 */  addiu      $s5, $v0, %lo(D_8010BD7C)
    /* 7D40 8010A540 0680023C */  lui        $v0, %hi(D_80060780)
    /* 7D44 8010A544 80075424 */  addiu      $s4, $v0, %lo(D_80060780)
    /* 7D48 8010A548 21901502 */  addu       $s2, $s0, $s5
  .L8010A54C:
    /* 7D4C 8010A54C 00004392 */  lbu        $v1, 0x0($s2)
    /* 7D50 8010A550 00000000 */  nop
    /* 7D54 8010A554 80100300 */  sll        $v0, $v1, 2
    /* 7D58 8010A558 21104300 */  addu       $v0, $v0, $v1
    /* 7D5C 8010A55C C0100200 */  sll        $v0, $v0, 3
    /* 7D60 8010A560 21985400 */  addu       $s3, $v0, $s4
    /* 7D64 8010A564 26007192 */  lbu        $s1, 0x26($s3)
    /* 7D68 8010A568 00000000 */  nop
    /* 7D6C 8010A56C 04002012 */  beqz       $s1, .L8010A580
    /* 7D70 8010A570 FFFF2426 */   addiu     $a0, $s1, -0x1
    /* 7D74 8010A574 2EAD010C */  jal        vs_battle_equipArmor
    /* 7D78 8010A578 21280000 */   addu      $a1, $zero, $zero
    /* 7D7C 8010A57C 260060A2 */  sb         $zero, 0x26($s3)
  .L8010A580:
    /* 7D80 8010A580 04000424 */  addiu      $a0, $zero, 0x4
    /* 7D84 8010A584 00004592 */  lbu        $a1, 0x0($s2)
    /* 7D88 8010A588 F8F8030C */  jal        vs_mainMenu_initItem
    /* 7D8C 8010A58C 01001026 */   addiu     $s0, $s0, 0x1
    /* 7D90 8010A590 0200022A */  slti       $v0, $s0, 0x2
    /* 7D94 8010A594 EDFF4014 */  bnez       $v0, .L8010A54C
    /* 7D98 8010A598 21901502 */   addu      $s2, $s0, $s5
    /* 7D9C 8010A59C 1180053C */  lui        $a1, %hi(D_8010BD54)
    /* 7DA0 8010A5A0 54BDA524 */  addiu      $a1, $a1, %lo(D_8010BD54)
    /* 7DA4 8010A5A4 1180023C */  lui        $v0, %hi(D_8010BD7C)
    /* 7DA8 8010A5A8 28000624 */  addiu      $a2, $zero, 0x28
    /* 7DAC 8010A5AC 7CBD5090 */  lbu        $s0, %lo(D_8010BD7C)($v0)
    /* 7DB0 8010A5B0 0680023C */  lui        $v0, %hi(D_80060780)
    /* 7DB4 8010A5B4 80074224 */  addiu      $v0, $v0, %lo(D_80060780)
    /* 7DB8 8010A5B8 80181000 */  sll        $v1, $s0, 2
    /* 7DBC 8010A5BC 21187000 */  addu       $v1, $v1, $s0
    /* 7DC0 8010A5C0 C0180300 */  sll        $v1, $v1, 3
    /* 7DC4 8010A5C4 21986200 */  addu       $s3, $v1, $v0
    /* 7DC8 8010A5C8 7000030C */  jal        vs_battle_copyAligned
    /* 7DCC 8010A5CC 21206002 */   addu      $a0, $s3, $zero
    /* 7DD0 8010A5D0 04000424 */  addiu      $a0, $zero, 0x4
    /* 7DD4 8010A5D4 2CFA030C */  jal        vs_mainMenu_rebuildInventory
    /* 7DD8 8010A5D8 270070A2 */   sb        $s0, 0x27($s3)
    /* 7DDC 8010A5DC 85290408 */  j          .L8010A614
    /* 7DE0 8010A5E0 01000224 */   addiu     $v0, $zero, 0x1
  .L8010A5E4:
    /* 7DE4 8010A5E4 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 7DE8 8010A5E8 00000000 */   nop
    /* 7DEC 8010A5EC A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 7DF0 8010A5F0 01000424 */   addiu     $a0, $zero, 0x1
    /* 7DF4 8010A5F4 1180023C */  lui        $v0, %hi(D_8010BC7A)
    /* 7DF8 8010A5F8 84290408 */  j          .L8010A610
    /* 7DFC 8010A5FC 7ABC50A0 */   sb        $s0, %lo(D_8010BC7A)($v0)
  .L8010A600:
    /* 7E00 8010A600 E00C040C */  jal        func_80103380
    /* 7E04 8010A604 01000424 */   addiu     $a0, $zero, 0x1
    /* 7E08 8010A608 85290408 */  j          .L8010A614
    /* 7E0C 8010A60C 00000000 */   nop
  .L8010A610:
    /* 7E10 8010A610 21100000 */  addu       $v0, $zero, $zero
  .L8010A614:
    /* 7E14 8010A614 4400BF8F */  lw         $ra, 0x44($sp)
    /* 7E18 8010A618 4000B68F */  lw         $s6, 0x40($sp)
    /* 7E1C 8010A61C 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 7E20 8010A620 3800B48F */  lw         $s4, 0x38($sp)
    /* 7E24 8010A624 3400B38F */  lw         $s3, 0x34($sp)
    /* 7E28 8010A628 3000B28F */  lw         $s2, 0x30($sp)
    /* 7E2C 8010A62C 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 7E30 8010A630 2800B08F */  lw         $s0, 0x28($sp)
    /* 7E34 8010A634 0800E003 */  jr         $ra
    /* 7E38 8010A638 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_80109DEC
