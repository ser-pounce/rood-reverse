nonmatching func_80108EC4, 0x8CC

glabel func_80108EC4
    /* 66C4 80108EC4 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 66C8 80108EC8 4400BFAF */  sw         $ra, 0x44($sp)
    /* 66CC 80108ECC 4000B6AF */  sw         $s6, 0x40($sp)
    /* 66D0 80108ED0 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 66D4 80108ED4 3800B4AF */  sw         $s4, 0x38($sp)
    /* 66D8 80108ED8 3400B3AF */  sw         $s3, 0x34($sp)
    /* 66DC 80108EDC 3000B2AF */  sw         $s2, 0x30($sp)
    /* 66E0 80108EE0 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 66E4 80108EE4 0E008010 */  beqz       $a0, .L80108F20
    /* 66E8 80108EE8 2800B0AF */   sw        $s0, 0x28($sp)
    /* 66EC 80108EEC 8D0A040C */  jal        func_80102A34
    /* 66F0 80108EF0 05000424 */   addiu     $a0, $zero, 0x5
    /* 66F4 80108EF4 21200000 */  addu       $a0, $zero, $zero
    /* 66F8 80108EF8 1180023C */  lui        $v0, %hi(D_8010BD44)
    /* 66FC 80108EFC 4222040C */  jal        func_80108908
    /* 6700 80108F00 44BD40A4 */   sh        $zero, %lo(D_8010BD44)($v0)
    /* 6704 80108F04 21100000 */  addu       $v0, $zero, $zero
    /* 6708 80108F08 1180043C */  lui        $a0, %hi(D_8010BC6F)
    /* 670C 80108F0C 01000324 */  addiu      $v1, $zero, 0x1
    /* 6710 80108F10 6FBC83A0 */  sb         $v1, %lo(D_8010BC6F)($a0)
    /* 6714 80108F14 1180033C */  lui        $v1, %hi(D_8010BC6E)
    /* 6718 80108F18 DA250408 */  j          .L80109768
    /* 671C 80108F1C 6EBC60A0 */   sb        $zero, %lo(D_8010BC6E)($v1)
  .L80108F20:
    /* 6720 80108F20 21880000 */  addu       $s1, $zero, $zero
    /* 6724 80108F24 1180023C */  lui        $v0, %hi(D_8010BD44)
    /* 6728 80108F28 44BD4390 */  lbu        $v1, %lo(D_8010BD44)($v0)
    /* 672C 80108F2C 00000000 */  nop
    /* 6730 80108F30 04006010 */  beqz       $v1, .L80108F44
    /* 6734 80108F34 44BD4224 */   addiu     $v0, $v0, %lo(D_8010BD44)
    /* 6738 80108F38 01004290 */  lbu        $v0, 0x1($v0)
    /* 673C 80108F3C 00000000 */  nop
    /* 6740 80108F40 2B882202 */  sltu       $s1, $s1, $v0
  .L80108F44:
    /* 6744 80108F44 1180043C */  lui        $a0, %hi(D_8010BC70)
    /* 6748 80108F48 1180053C */  lui        $a1, %hi(D_8010BC6E)
    /* 674C 80108F4C 70BC8290 */  lbu        $v0, %lo(D_8010BC70)($a0)
    /* 6750 80108F50 6EBCA390 */  lbu        $v1, %lo(D_8010BC6E)($a1)
    /* 6754 80108F54 10004224 */  addiu      $v0, $v0, 0x10
    /* 6758 80108F58 70BC82A0 */  sb         $v0, %lo(D_8010BC70)($a0)
    /* 675C 80108F5C 02000224 */  addiu      $v0, $zero, 0x2
    /* 6760 80108F60 02006210 */  beq        $v1, $v0, .L80108F6C
    /* 6764 80108F64 00000000 */   nop
    /* 6768 80108F68 70BC80A0 */  sb         $zero, %lo(D_8010BC70)($a0)
  .L80108F6C:
    /* 676C 80108F6C 6EBCA390 */  lbu        $v1, %lo(D_8010BC6E)($a1)
    /* 6770 80108F70 00000000 */  nop
    /* 6774 80108F74 0700622C */  sltiu      $v0, $v1, 0x7
    /* 6778 80108F78 FA014010 */  beqz       $v0, .L80109764
    /* 677C 80108F7C 1080023C */   lui       $v0, %hi(jtbl_801028D0)
    /* 6780 80108F80 D0284224 */  addiu      $v0, $v0, %lo(jtbl_801028D0)
    /* 6784 80108F84 80180300 */  sll        $v1, $v1, 2
    /* 6788 80108F88 21186200 */  addu       $v1, $v1, $v0
    /* 678C 80108F8C 0000628C */  lw         $v0, 0x0($v1)
    /* 6790 80108F90 00000000 */  nop
    /* 6794 80108F94 08004000 */  jr         $v0
    /* 6798 80108F98 00000000 */   nop
    /* 679C 80108F9C 74EA030C */  jal        vs_mainmenu_ready
    /* 67A0 80108FA0 00000000 */   nop
    /* 67A4 80108FA4 F0014010 */  beqz       $v0, .L80109768
    /* 67A8 80108FA8 21100000 */   addu      $v0, $zero, $zero
    /* 67AC 80108FAC 8F040424 */  addiu      $a0, $zero, 0x48F
    /* 67B0 80108FB0 D40A040C */  jal        func_80102B50
    /* 67B4 80108FB4 1B000524 */   addiu     $a1, $zero, 0x1B
    /* 67B8 80108FB8 1180023C */  lui        $v0, %hi(D_8010BD14)
    /* 67BC 80108FBC 14BD5224 */  addiu      $s2, $v0, %lo(D_8010BD14)
    /* 67C0 80108FC0 04005192 */  lbu        $s1, 0x4($s2)
    /* 67C4 80108FC4 01000424 */  addiu      $a0, $zero, 0x1
    /* 67C8 80108FC8 171E040C */  jal        func_8010785C
    /* 67CC 80108FCC 21282002 */   addu      $a1, $s1, $zero
    /* 67D0 80108FD0 03002012 */  beqz       $s1, .L80108FE0
    /* 67D4 80108FD4 21204000 */   addu      $a0, $v0, $zero
    /* 67D8 80108FD8 A723040C */  jal        func_80108E9C
    /* 67DC 80108FDC 21284002 */   addu      $a1, $s2, $zero
  .L80108FE0:
    /* 67E0 80108FE0 21900000 */  addu       $s2, $zero, $zero
    /* 67E4 80108FE4 1180023C */  lui        $v0, %hi(D_8010BD44)
    /* 67E8 80108FE8 44BD5624 */  addiu      $s6, $v0, %lo(D_8010BD44)
    /* 67EC 80108FEC 0680023C */  lui        $v0, %hi(D_80060238)
    /* 67F0 80108FF0 38025524 */  addiu      $s5, $v0, %lo(D_80060238)
    /* 67F4 80108FF4 1080143C */  lui        $s4, %hi(vs_mainMenu_itemNames)
    /* 67F8 80108FF8 22001324 */  addiu      $s3, $zero, 0x22
  .L80108FFC:
    /* 67FC 80108FFC 21105602 */  addu       $v0, $s2, $s6
    /* 6800 80109000 00005190 */  lbu        $s1, 0x0($v0)
    /* 6804 80109004 00000000 */  nop
    /* 6808 80109008 04002012 */  beqz       $s1, .L8010901C
    /* 680C 8010900C 40101100 */   sll       $v0, $s1, 1
    /* 6810 80109010 21105100 */  addu       $v0, $v0, $s1
    /* 6814 80109014 00110200 */  sll        $v0, $v0, 4
    /* 6818 80109018 21805500 */  addu       $s0, $v0, $s5
  .L8010901C:
    /* 681C 8010901C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 6820 80109020 0B004426 */  addiu      $a0, $s2, 0xB
    /* 6824 80109024 05002016 */  bnez       $s1, .L8010903C
    /* 6828 80109028 21306002 */   addu      $a2, $s3, $zero
    /* 682C 8010902C 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 6830 80109030 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 6834 80109034 16240408 */  j          .L80109058
    /* 6838 80109038 72084224 */   addiu     $v0, $v0, 0x872
  .L8010903C:
    /* 683C 8010903C 04000292 */  lbu        $v0, 0x4($s0)
    /* 6840 80109040 00000000 */  nop
    /* 6844 80109044 40180200 */  sll        $v1, $v0, 1
    /* 6848 80109048 21186200 */  addu       $v1, $v1, $v0
    /* 684C 8010904C 9C22828E */  lw         $v0, %lo(vs_mainMenu_itemNames)($s4)
    /* 6850 80109050 C0180300 */  sll        $v1, $v1, 3
    /* 6854 80109054 21104300 */  addu       $v0, $v0, $v1
  .L80109058:
    /* 6858 80109058 1400A2AF */  sw         $v0, 0x14($sp)
    /* 685C 8010905C 4E010524 */  addiu      $a1, $zero, 0x14E
    /* 6860 80109060 9723030C */  jal        vs_battle_setMenuItem
    /* 6864 80109064 97000724 */   addiu     $a3, $zero, 0x97
    /* 6868 80109068 21204000 */  addu       $a0, $v0, $zero
    /* 686C 8010906C 02000224 */  addiu      $v0, $zero, 0x2
    /* 6870 80109070 000082A0 */  sb         $v0, 0x0($a0)
    /* 6874 80109074 A9000224 */  addiu      $v0, $zero, 0xA9
    /* 6878 80109078 04002016 */  bnez       $s1, .L8010908C
    /* 687C 8010907C 180082A4 */   sh        $v0, 0x18($a0)
    /* 6880 80109080 01000224 */  addiu      $v0, $zero, 0x1
    /* 6884 80109084 25240408 */  j          .L80109094
    /* 6888 80109088 0A0082A0 */   sb        $v0, 0xA($a0)
  .L8010908C:
    /* 688C 8010908C A723040C */  jal        func_80108E9C
    /* 6890 80109090 21280002 */   addu      $a1, $s0, $zero
  .L80109094:
    /* 6894 80109094 01005226 */  addiu      $s2, $s2, 0x1
    /* 6898 80109098 0200422A */  slti       $v0, $s2, 0x2
    /* 689C 8010909C D7FF4014 */  bnez       $v0, .L80108FFC
    /* 68A0 801090A0 10007326 */   addiu     $s3, $s3, 0x10
    /* 68A4 801090A4 02000324 */  addiu      $v1, $zero, 0x2
    /* 68A8 801090A8 1180023C */  lui        $v0, %hi(D_8010BC6E)
    /* 68AC 801090AC D9250408 */  j          .L80109764
    /* 68B0 801090B0 6EBC43A0 */   sb        $v1, %lo(D_8010BC6E)($v0)
    /* 68B4 801090B4 74EA030C */  jal        vs_mainmenu_ready
    /* 68B8 801090B8 00000000 */   nop
    /* 68BC 801090BC E9004010 */  beqz       $v0, .L80109464
    /* 68C0 801090C0 0680103C */   lui       $s0, %hi(vs_main_buttonsPressed)
    /* 68C4 801090C4 D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 68C8 801090C8 00000000 */  nop
    /* 68CC 801090CC 10004230 */  andi       $v0, $v0, 0x10
    /* 68D0 801090D0 9B014014 */  bnez       $v0, .L80109740
    /* 68D4 801090D4 00000000 */   nop
    /* 68D8 801090D8 04002012 */  beqz       $s1, .L801090EC
    /* 68DC 801090DC 1180023C */   lui       $v0, %hi(D_8010BC70)
    /* 68E0 801090E0 70BC4590 */  lbu        $a1, %lo(D_8010BC70)($v0)
    /* 68E4 801090E4 5A0A040C */  jal        func_80102968
    /* 68E8 801090E8 02000424 */   addiu     $a0, $zero, 0x2
  .L801090EC:
    /* 68EC 801090EC D0E1038E */  lw         $v1, %lo(vs_main_buttonsPressed)($s0)
    /* 68F0 801090F0 00000000 */  nop
    /* 68F4 801090F4 40006230 */  andi       $v0, $v1, 0x40
    /* 68F8 801090F8 2B004010 */  beqz       $v0, .L801091A8
    /* 68FC 801090FC 00086230 */   andi      $v0, $v1, 0x800
    /* 6900 80109100 AE0A040C */  jal        func_80102AB8
    /* 6904 80109104 05000424 */   addiu     $a0, $zero, 0x5
    /* 6908 80109108 21904000 */  addu       $s2, $v0, $zero
    /* 690C 8010910C 8C014012 */  beqz       $s2, .L80109740
    /* 6910 80109110 00000000 */   nop
    /* 6914 80109114 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 6918 80109118 00000000 */   nop
    /* 691C 8010911C 21204002 */  addu       $a0, $s2, $zero
    /* 6920 80109120 1180023C */  lui        $v0, %hi(D_8010BC6F)
    /* 6924 80109124 6FBC52A0 */  sb         $s2, %lo(D_8010BC6F)($v0)
    /* 6928 80109128 1180023C */  lui        $v0, %hi(D_8010BD44)
    /* 692C 8010912C 44BD4224 */  addiu      $v0, $v0, %lo(D_8010BD44)
    /* 6930 80109130 21104202 */  addu       $v0, $s2, $v0
    /* 6934 80109134 4222040C */  jal        func_80108908
    /* 6938 80109138 FFFF40A0 */   sb        $zero, -0x1($v0)
    /* 693C 8010913C 0A004426 */  addiu      $a0, $s2, 0xA
    /* 6940 80109140 A9000524 */  addiu      $a1, $zero, 0xA9
    /* 6944 80109144 00311200 */  sll        $a2, $s2, 4
    /* 6948 80109148 1200C624 */  addiu      $a2, $a2, 0x12
    /* 694C 8010914C 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 6950 80109150 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 6954 80109154 97000724 */  addiu      $a3, $zero, 0x97
    /* 6958 80109158 1000A0AF */  sw         $zero, 0x10($sp)
    /* 695C 8010915C 72084224 */  addiu      $v0, $v0, 0x872
    /* 6960 80109160 9723030C */  jal        vs_battle_setMenuItem
    /* 6964 80109164 1400A2AF */   sw        $v0, 0x14($sp)
    /* 6968 80109168 21204000 */  addu       $a0, $v0, $zero
    /* 696C 8010916C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6970 80109170 060082A0 */  sb         $v0, 0x6($a0)
    /* 6974 80109174 0A0082A0 */  sb         $v0, 0xA($a0)
    /* 6978 80109178 1180023C */  lui        $v0, %hi(D_8010BD14)
    /* 697C 8010917C 14BD5024 */  addiu      $s0, $v0, %lo(D_8010BD14)
    /* 6980 80109180 04001192 */  lbu        $s1, 0x4($s0)
    /* 6984 80109184 01000424 */  addiu      $a0, $zero, 0x1
    /* 6988 80109188 F71D040C */  jal        func_801077DC
    /* 698C 8010918C 21282002 */   addu      $a1, $s1, $zero
    /* 6990 80109190 74012012 */  beqz       $s1, .L80109764
    /* 6994 80109194 21204000 */   addu      $a0, $v0, $zero
    /* 6998 80109198 A723040C */  jal        func_80108E9C
    /* 699C 8010919C 21280002 */   addu      $a1, $s0, $zero
    /* 69A0 801091A0 DA250408 */  j          .L80109768
    /* 69A4 801091A4 21100000 */   addu      $v0, $zero, $zero
  .L801091A8:
    /* 69A8 801091A8 12004010 */  beqz       $v0, .L801091F4
    /* 69AC 801091AC 1180033C */   lui       $v1, %hi(D_8010BC6F)
    /* 69B0 801091B0 11002012 */  beqz       $s1, .L801091F8
    /* 69B4 801091B4 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 69B8 801091B8 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 69BC 801091BC 1180103C */   lui       $s0, %hi(D_8010BC6F)
    /* 69C0 801091C0 6FBC0492 */  lbu        $a0, %lo(D_8010BC6F)($s0)
    /* 69C4 801091C4 9223030C */  jal        vs_battle_getMenuItem
    /* 69C8 801091C8 0A008424 */   addiu     $a0, $a0, 0xA
    /* 69CC 801091CC 03000424 */  addiu      $a0, $zero, 0x3
    /* 69D0 801091D0 060040A0 */  sb         $zero, 0x6($v0)
    /* 69D4 801091D4 21108000 */  addu       $v0, $a0, $zero
    /* 69D8 801091D8 1180033C */  lui        $v1, %hi(D_8010BC6E)
    /* 69DC 801091DC 6FBC02A2 */  sb         $v0, %lo(D_8010BC6F)($s0)
    /* 69E0 801091E0 04000224 */  addiu      $v0, $zero, 0x4
    /* 69E4 801091E4 4222040C */  jal        func_80108908
    /* 69E8 801091E8 6EBC62A0 */   sb        $v0, %lo(D_8010BC6E)($v1)
    /* 69EC 801091EC DA250408 */  j          .L80109768
    /* 69F0 801091F0 21100000 */   addu      $v0, $zero, $zero
  .L801091F4:
    /* 69F4 801091F4 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
  .L801091F8:
    /* 69F8 801091F8 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 69FC 801091FC 6FBC7290 */  lbu        $s2, %lo(D_8010BC6F)($v1)
    /* 6A00 80109200 20004230 */  andi       $v0, $v0, 0x20
    /* 6A04 80109204 15004010 */  beqz       $v0, .L8010925C
    /* 6A08 80109208 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 6A0C 8010920C 05004016 */  bnez       $s2, .L80109224
    /* 6A10 80109210 00000000 */   nop
    /* 6A14 80109214 B800030C */  jal        vs_battle_playInvalidSfx
    /* 6A18 80109218 00000000 */   nop
    /* 6A1C 8010921C 97240408 */  j          .L8010925C
    /* 6A20 80109220 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
  .L80109224:
    /* 6A24 80109224 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 6A28 80109228 03001024 */   addiu     $s0, $zero, 0x3
    /* 6A2C 8010922C 04005016 */  bne        $s2, $s0, .L80109240
    /* 6A30 80109230 1180033C */   lui       $v1, %hi(D_8010BC6E)
    /* 6A34 80109234 04000224 */  addiu      $v0, $zero, 0x4
    /* 6A38 80109238 D9250408 */  j          .L80109764
    /* 6A3C 8010923C 6EBC62A0 */   sb        $v0, %lo(D_8010BC6E)($v1)
  .L80109240:
    /* 6A40 80109240 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 6A44 80109244 28000424 */   addiu     $a0, $zero, 0x28
    /* 6A48 80109248 B522040C */  jal        func_80108AD4
    /* 6A4C 8010924C 21204002 */   addu      $a0, $s2, $zero
    /* 6A50 80109250 1180023C */  lui        $v0, %hi(D_8010BC6E)
    /* 6A54 80109254 D9250408 */  j          .L80109764
    /* 6A58 80109258 6EBC50A0 */   sb        $s0, %lo(D_8010BC6E)($v0)
  .L8010925C:
    /* 6A5C 8010925C DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 6A60 80109260 00000000 */  nop
    /* 6A64 80109264 00104230 */  andi       $v0, $v0, 0x1000
    /* 6A68 80109268 04004010 */  beqz       $v0, .L8010927C
    /* 6A6C 8010926C 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 6A70 80109270 02004016 */  bnez       $s2, .L8010927C
    /* 6A74 80109274 FFFF5226 */   addiu     $s2, $s2, -0x1
    /* 6A78 80109278 02003226 */  addiu      $s2, $s1, 0x2
  .L8010927C:
    /* 6A7C 8010927C DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 6A80 80109280 00000000 */  nop
    /* 6A84 80109284 00404230 */  andi       $v0, $v0, 0x4000
    /* 6A88 80109288 04004010 */  beqz       $v0, .L8010929C
    /* 6A8C 8010928C 02002226 */   addiu     $v0, $s1, 0x2
    /* 6A90 80109290 02004216 */  bne        $s2, $v0, .L8010929C
    /* 6A94 80109294 01005226 */   addiu     $s2, $s2, 0x1
    /* 6A98 80109298 21900000 */  addu       $s2, $zero, $zero
  .L8010929C:
    /* 6A9C 8010929C 1180103C */  lui        $s0, %hi(D_8010BC6F)
    /* 6AA0 801092A0 6FBC0292 */  lbu        $v0, %lo(D_8010BC6F)($s0)
    /* 6AA4 801092A4 00000000 */  nop
    /* 6AA8 801092A8 06004212 */  beq        $s2, $v0, .L801092C4
    /* 6AAC 801092AC 01001124 */   addiu     $s1, $zero, 0x1
    /* 6AB0 801092B0 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 6AB4 801092B4 00000000 */   nop
    /* 6AB8 801092B8 6FBC12A2 */  sb         $s2, %lo(D_8010BC6F)($s0)
    /* 6ABC 801092BC 4222040C */  jal        func_80108908
    /* 6AC0 801092C0 FF004432 */   andi      $a0, $s2, 0xFF
  .L801092C4:
    /* 6AC4 801092C4 21A00002 */  addu       $s4, $s0, $zero
    /* 6AC8 801092C8 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 6ACC 801092CC 21804000 */  addu       $s0, $v0, $zero
    /* 6AD0 801092D0 1180023C */  lui        $v0, %hi(D_8010BD44)
    /* 6AD4 801092D4 44BD5324 */  addiu      $s3, $v0, %lo(D_8010BD44)
    /* 6AD8 801092D8 1180023C */  lui        $v0, %hi(D_8010BD18)
    /* 6ADC 801092DC 18BD4290 */  lbu        $v0, %lo(D_8010BD18)($v0)
    /* 6AE0 801092E0 844E038E */  lw         $v1, %lo(vs_battle_rowTypeBuf)($s0)
    /* 6AE4 801092E4 2B105100 */  sltu       $v0, $v0, $s1
    /* 6AE8 801092E8 000062AC */  sw         $v0, 0x0($v1)
  .L801092EC:
    /* 6AEC 801092EC 9223030C */  jal        vs_battle_getMenuItem
    /* 6AF0 801092F0 0A002426 */   addiu     $a0, $s1, 0xA
    /* 6AF4 801092F4 80201100 */  sll        $a0, $s1, 2
    /* 6AF8 801092F8 6FBC8392 */  lbu        $v1, %lo(D_8010BC6F)($s4)
    /* 6AFC 801092FC 21283302 */  addu       $a1, $s1, $s3
    /* 6B00 80109300 26182302 */  xor        $v1, $s1, $v1
    /* 6B04 80109304 01003126 */  addiu      $s1, $s1, 0x1
    /* 6B08 80109308 0100632C */  sltiu      $v1, $v1, 0x1
    /* 6B0C 8010930C 060043A0 */  sb         $v1, 0x6($v0)
    /* 6B10 80109310 844E038E */  lw         $v1, %lo(vs_battle_rowTypeBuf)($s0)
    /* 6B14 80109314 FFFFA290 */  lbu        $v0, -0x1($a1)
    /* 6B18 80109318 21208300 */  addu       $a0, $a0, $v1
    /* 6B1C 8010931C 0100422C */  sltiu      $v0, $v0, 0x1
    /* 6B20 80109320 000082AC */  sw         $v0, 0x0($a0)
    /* 6B24 80109324 0300222A */  slti       $v0, $s1, 0x3
    /* 6B28 80109328 F0FF4014 */  bnez       $v0, .L801092EC
    /* 6B2C 8010932C 21204002 */   addu      $a0, $s2, $zero
    /* 6B30 80109330 10000524 */  addiu      $a1, $zero, 0x10
    /* 6B34 80109334 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 6B38 80109338 844E438C */  lw         $v1, %lo(vs_battle_rowTypeBuf)($v0)
    /* 6B3C 8010933C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6B40 80109340 79FE030C */  jal        vs_mainMenu_printInformation
    /* 6B44 80109344 0C0062AC */   sw        $v0, 0xC($v1)
    /* 6B48 80109348 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 6B4C 8010934C A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 6B50 80109350 00000000 */  nop
    /* 6B54 80109354 C2086224 */  addiu      $v0, $v1, 0x8C2
    /* 6B58 80109358 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 6B5C 8010935C 0300422A */  slti       $v0, $s2, 0x3
    /* 6B60 80109360 07004010 */  beqz       $v0, .L80109380
    /* 6B64 80109364 00000000 */   nop
    /* 6B68 80109368 1500401E */  bgtz       $s2, .L801093C0
    /* 6B6C 8010936C 1180023C */   lui       $v0, %hi(D_8010BD44)
    /* 6B70 80109370 08004012 */  beqz       $s2, .L80109394
    /* 6B74 80109374 1180023C */   lui       $v0, %hi(D_8010BD14)
    /* 6B78 80109378 06250408 */  j          .L80109418
    /* 6B7C 8010937C 00000000 */   nop
  .L80109380:
    /* 6B80 80109380 03000224 */  addiu      $v0, $zero, 0x3
    /* 6B84 80109384 23004212 */  beq        $s2, $v0, .L80109414
    /* 6B88 80109388 3C076224 */   addiu     $v0, $v1, 0x73C
    /* 6B8C 8010938C 06250408 */  j          .L80109418
    /* 6B90 80109390 00000000 */   nop
  .L80109394:
    /* 6B94 80109394 14BD4424 */  addiu      $a0, $v0, %lo(D_8010BD14)
    /* 6B98 80109398 04008290 */  lbu        $v0, 0x4($a0)
    /* 6B9C 8010939C 00000000 */  nop
    /* 6BA0 801093A0 1D004010 */  beqz       $v0, .L80109418
    /* 6BA4 801093A4 1800A527 */   addiu     $a1, $sp, 0x18
    /* 6BA8 801093A8 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 6BAC 801093AC 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 6BB0 801093B0 A722040C */  jal        func_80108A9C
    /* 6BB4 801093B4 2000A627 */   addiu     $a2, $sp, 0x20
    /* 6BB8 801093B8 06250408 */  j          .L80109418
    /* 6BBC 801093BC 00000000 */   nop
  .L801093C0:
    /* 6BC0 801093C0 44BD4224 */  addiu      $v0, $v0, %lo(D_8010BD44)
    /* 6BC4 801093C4 21104202 */  addu       $v0, $s2, $v0
    /* 6BC8 801093C8 FFFF5190 */  lbu        $s1, -0x1($v0)
    /* 6BCC 801093CC 00000000 */  nop
    /* 6BD0 801093D0 11002012 */  beqz       $s1, .L80109418
    /* 6BD4 801093D4 40101100 */   sll       $v0, $s1, 1
    /* 6BD8 801093D8 21105100 */  addu       $v0, $v0, $s1
    /* 6BDC 801093DC 00110200 */  sll        $v0, $v0, 4
    /* 6BE0 801093E0 0680033C */  lui        $v1, %hi(D_80060238)
    /* 6BE4 801093E4 38026324 */  addiu      $v1, $v1, %lo(D_80060238)
    /* 6BE8 801093E8 21804300 */  addu       $s0, $v0, $v1
    /* 6BEC 801093EC 21200002 */  addu       $a0, $s0, $zero
    /* 6BF0 801093F0 1800A527 */  addiu      $a1, $sp, 0x18
    /* 6BF4 801093F4 2C00118E */  lw         $s1, 0x2C($s0)
    /* 6BF8 801093F8 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 6BFC 801093FC 2C0000AE */  sw         $zero, 0x2C($s0)
    /* 6C00 80109400 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 6C04 80109404 A722040C */  jal        func_80108A9C
    /* 6C08 80109408 2000A627 */   addiu     $a2, $sp, 0x20
    /* 6C0C 8010940C 06250408 */  j          .L80109418
    /* 6C10 80109410 2C0011AE */   sw        $s1, 0x2C($s0)
  .L80109414:
    /* 6C14 80109414 1C00A2AF */  sw         $v0, 0x1C($sp)
  .L80109418:
    /* 6C18 80109418 1C00A48F */  lw         $a0, 0x1C($sp)
    /* 6C1C 8010941C 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 6C20 80109420 00000000 */   nop
    /* 6C24 80109424 00111200 */  sll        $v0, $s2, 4
    /* 6C28 80109428 0A004224 */  addiu      $v0, $v0, 0xA
    /* 6C2C 8010942C 00140200 */  sll        $v0, $v0, 16
    /* 6C30 80109430 02004016 */  bnez       $s2, .L8010943C
    /* 6C34 80109434 9B005134 */   ori       $s1, $v0, 0x9B
    /* 6C38 80109438 F2FF3126 */  addiu      $s1, $s1, -0xE
  .L8010943C:
    /* 6C3C 8010943C 03000224 */  addiu      $v0, $zero, 0x3
    /* 6C40 80109440 03004216 */  bne        $s2, $v0, .L80109450
    /* 6C44 80109444 1180103C */   lui       $s0, %hi(D_8010BB75)
    /* 6C48 80109448 FCFF023C */  lui        $v0, (0xFFFC0000 >> 16)
    /* 6C4C 8010944C 21882202 */  addu       $s1, $s1, $v0
  .L80109450:
    /* 6C50 80109450 75BB0492 */  lbu        $a0, %lo(D_8010BB75)($s0)
    /* 6C54 80109454 37FF030C */  jal        func_800FFCDC
    /* 6C58 80109458 21282002 */   addu      $a1, $s1, $zero
    /* 6C5C 8010945C D9250408 */  j          .L80109764
    /* 6C60 80109460 75BB02A2 */   sb        $v0, %lo(D_8010BB75)($s0)
  .L80109464:
    /* 6C64 80109464 1180023C */  lui        $v0, %hi(D_8010BC70)
    /* 6C68 80109468 D9250408 */  j          .L80109764
    /* 6C6C 8010946C 70BC40A0 */   sb        $zero, %lo(D_8010BC70)($v0)
    /* 6C70 80109470 B522040C */  jal        func_80108AD4
    /* 6C74 80109474 21200000 */   addu      $a0, $zero, $zero
    /* 6C78 80109478 21904000 */  addu       $s2, $v0, $zero
    /* 6C7C 8010947C B9004012 */  beqz       $s2, .L80109764
    /* 6C80 80109480 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 6C84 80109484 AE004212 */  beq        $s2, $v0, .L80109740
    /* 6C88 80109488 00000000 */   nop
    /* 6C8C 8010948C 2000401A */  blez       $s2, .L80109510
    /* 6C90 80109490 1180103C */   lui       $s0, %hi(D_8010BC6F)
    /* 6C94 80109494 6FBC0292 */  lbu        $v0, %lo(D_8010BC6F)($s0)
    /* 6C98 80109498 1180133C */  lui        $s3, %hi(D_8010BD44)
    /* 6C9C 8010949C FFFF5124 */  addiu      $s1, $v0, -0x1
    /* 6CA0 801094A0 44BD6226 */  addiu      $v0, $s3, %lo(D_8010BD44)
    /* 6CA4 801094A4 21182202 */  addu       $v1, $s1, $v0
    /* 6CA8 801094A8 00006290 */  lbu        $v0, 0x0($v1)
    /* 6CAC 801094AC 00000000 */  nop
    /* 6CB0 801094B0 06004216 */  bne        $s2, $v0, .L801094CC
    /* 6CB4 801094B4 21202002 */   addu      $a0, $s1, $zero
    /* 6CB8 801094B8 000060A0 */  sb         $zero, 0x0($v1)
    /* 6CBC 801094BC AE0A040C */  jal        func_80102AB8
    /* 6CC0 801094C0 21202002 */   addu      $a0, $s1, $zero
    /* 6CC4 801094C4 41250408 */  j          .L80109504
    /* 6CC8 801094C8 1180023C */   lui       $v0, %hi(D_8010BC6F)
  .L801094CC:
    /* 6CCC 801094CC 8D0A040C */  jal        func_80102A34
    /* 6CD0 801094D0 000072A0 */   sb        $s2, 0x0($v1)
    /* 6CD4 801094D4 6FBC0292 */  lbu        $v0, %lo(D_8010BC6F)($s0)
    /* 6CD8 801094D8 00000000 */  nop
    /* 6CDC 801094DC 01004224 */  addiu      $v0, $v0, 0x1
    /* 6CE0 801094E0 6FBC02A2 */  sb         $v0, %lo(D_8010BC6F)($s0)
    /* 6CE4 801094E4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6CE8 801094E8 06002216 */  bne        $s1, $v0, .L80109504
    /* 6CEC 801094EC 1180023C */   lui       $v0, %hi(D_8010BC6F)
    /* 6CF0 801094F0 44BD6292 */  lbu        $v0, %lo(D_8010BD44)($s3)
    /* 6CF4 801094F4 00000000 */  nop
    /* 6CF8 801094F8 02004014 */  bnez       $v0, .L80109504
    /* 6CFC 801094FC 1180023C */   lui       $v0, %hi(D_8010BC6F)
    /* 6D00 80109500 6FBC11A2 */  sb         $s1, %lo(D_8010BC6F)($s0)
  .L80109504:
    /* 6D04 80109504 6FBC4490 */  lbu        $a0, %lo(D_8010BC6F)($v0)
    /* 6D08 80109508 4222040C */  jal        func_80108908
    /* 6D0C 8010950C 00000000 */   nop
  .L80109510:
    /* 6D10 80109510 1180033C */  lui        $v1, %hi(D_8010BC6E)
    /* 6D14 80109514 01000224 */  addiu      $v0, $zero, 0x1
    /* 6D18 80109518 D9250408 */  j          .L80109764
    /* 6D1C 8010951C 6EBC62A0 */   sb        $v0, %lo(D_8010BC6E)($v1)
    /* 6D20 80109520 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 6D24 80109524 02000424 */   addiu     $a0, $zero, 0x2
    /* 6D28 80109528 900B040C */  jal        func_80102E40
    /* 6D2C 8010952C 02000424 */   addiu     $a0, $zero, 0x2
    /* 6D30 80109530 21880000 */  addu       $s1, $zero, $zero
    /* 6D34 80109534 21902002 */  addu       $s2, $s1, $zero
    /* 6D38 80109538 1180023C */  lui        $v0, %hi(D_8010BD44)
    /* 6D3C 8010953C 44BD4624 */  addiu      $a2, $v0, %lo(D_8010BD44)
    /* 6D40 80109540 0680023C */  lui        $v0, %hi(D_80060238)
    /* 6D44 80109544 38024524 */  addiu      $a1, $v0, %lo(D_80060238)
    /* 6D48 80109548 21104602 */  addu       $v0, $s2, $a2
  .L8010954C:
    /* 6D4C 8010954C 00004390 */  lbu        $v1, 0x0($v0)
    /* 6D50 80109550 21200000 */  addu       $a0, $zero, $zero
    /* 6D54 80109554 40100300 */  sll        $v0, $v1, 1
    /* 6D58 80109558 21104300 */  addu       $v0, $v0, $v1
    /* 6D5C 8010955C 00110200 */  sll        $v0, $v0, 4
    /* 6D60 80109560 21804500 */  addu       $s0, $v0, $a1
    /* 6D64 80109564 01000292 */  lbu        $v0, 0x1($s0)
    /* 6D68 80109568 10000392 */  lbu        $v1, 0x10($s0)
    /* 6D6C 8010956C 00000000 */  nop
    /* 6D70 80109570 08006010 */  beqz       $v1, .L80109594
    /* 6D74 80109574 25882202 */   or        $s1, $s1, $v0
    /* 6D78 80109578 21100402 */  addu       $v0, $s0, $a0
  .L8010957C:
    /* 6D7C 8010957C 2C004290 */  lbu        $v0, 0x2C($v0)
    /* 6D80 80109580 01008424 */  addiu      $a0, $a0, 0x1
    /* 6D84 80109584 25882202 */  or         $s1, $s1, $v0
    /* 6D88 80109588 2A108300 */  slt        $v0, $a0, $v1
    /* 6D8C 8010958C FBFF4014 */  bnez       $v0, .L8010957C
    /* 6D90 80109590 21100402 */   addu      $v0, $s0, $a0
  .L80109594:
    /* 6D94 80109594 01005226 */  addiu      $s2, $s2, 0x1
    /* 6D98 80109598 0200422A */  slti       $v0, $s2, 0x2
    /* 6D9C 8010959C EBFF4014 */  bnez       $v0, .L8010954C
    /* 6DA0 801095A0 21104602 */   addu      $v0, $s2, $a2
    /* 6DA4 801095A4 04002016 */  bnez       $s1, .L801095B8
    /* 6DA8 801095A8 1080023C */   lui       $v0, %hi(vs_mainMenu_menu12Text)
    /* 6DAC 801095AC A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 6DB0 801095B0 71250408 */  j          .L801095C4
    /* 6DB4 801095B4 56084424 */   addiu     $a0, $v0, 0x856
  .L801095B8:
    /* 6DB8 801095B8 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 6DBC 801095BC 00000000 */  nop
    /* 6DC0 801095C0 4E094424 */  addiu      $a0, $v0, 0x94E
  .L801095C4:
    /* 6DC4 801095C4 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 6DC8 801095C8 00000000 */   nop
    /* 6DCC 801095CC 1180033C */  lui        $v1, %hi(D_8010BC6E)
    /* 6DD0 801095D0 05000224 */  addiu      $v0, $zero, 0x5
    /* 6DD4 801095D4 D9250408 */  j          .L80109764
    /* 6DD8 801095D8 6EBC62A0 */   sb        $v0, %lo(D_8010BC6E)($v1)
    /* 6DDC 801095DC 900B040C */  jal        func_80102E40
    /* 6DE0 801095E0 21200000 */   addu      $a0, $zero, $zero
    /* 6DE4 801095E4 21904000 */  addu       $s2, $v0, $zero
    /* 6DE8 801095E8 5E004012 */  beqz       $s2, .L80109764
    /* 6DEC 801095EC 02000224 */   addiu     $v0, $zero, 0x2
    /* 6DF0 801095F0 4C004212 */  beq        $s2, $v0, .L80109724
    /* 6DF4 801095F4 0300422A */   slti      $v0, $s2, 0x3
    /* 6DF8 801095F8 05004010 */  beqz       $v0, .L80109610
    /* 6DFC 801095FC 01000224 */   addiu     $v0, $zero, 0x1
    /* 6E00 80109600 08004212 */  beq        $s2, $v0, .L80109624
    /* 6E04 80109604 21100000 */   addu      $v0, $zero, $zero
    /* 6E08 80109608 DA250408 */  j          .L80109768
    /* 6E0C 8010960C 00000000 */   nop
  .L80109610:
    /* 6E10 80109610 03000224 */  addiu      $v0, $zero, 0x3
    /* 6E14 80109614 4A004212 */  beq        $s2, $v0, .L80109740
    /* 6E18 80109618 21100000 */   addu      $v0, $zero, $zero
    /* 6E1C 8010961C DA250408 */  j          .L80109768
    /* 6E20 80109620 00000000 */   nop
  .L80109624:
    /* 6E24 80109624 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 6E28 80109628 6216010C */  jal        vs_main_playSfxDefault
    /* 6E2C 8010962C 18000524 */   addiu     $a1, $zero, 0x18
    /* 6E30 80109630 F2FE030C */  jal        func_800FFBC8
    /* 6E34 80109634 21900000 */   addu      $s2, $zero, $zero
    /* 6E38 80109638 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 6E3C 8010963C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 6E40 80109640 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 6E44 80109644 04000424 */   addiu     $a0, $zero, 0x4
    /* 6E48 80109648 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 6E4C 8010964C 28000424 */   addiu     $a0, $zero, 0x28
    /* 6E50 80109650 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 6E54 80109654 21200000 */   addu      $a0, $zero, $zero
    /* 6E58 80109658 1180023C */  lui        $v0, %hi(D_8010BD44)
    /* 6E5C 8010965C 44BD5524 */  addiu      $s5, $v0, %lo(D_8010BD44)
    /* 6E60 80109660 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 6E64 80109664 68015424 */  addiu      $s4, $v0, %lo(vs_battle_inventory)
    /* 6E68 80109668 1180133C */  lui        $s3, %hi(D_8010BC6E)
  .L8010966C:
    /* 6E6C 8010966C 21105502 */  addu       $v0, $s2, $s5
    /* 6E70 80109670 00005190 */  lbu        $s1, 0x0($v0)
    /* 6E74 80109674 00000000 */  nop
    /* 6E78 80109678 FFFF3026 */  addiu      $s0, $s1, -0x1
    /* 6E7C 8010967C 40101000 */  sll        $v0, $s0, 1
    /* 6E80 80109680 21105000 */  addu       $v0, $v0, $s0
    /* 6E84 80109684 00110200 */  sll        $v0, $v0, 4
    /* 6E88 80109688 21105400 */  addu       $v0, $v0, $s4
    /* 6E8C 8010968C 01014290 */  lbu        $v0, 0x101($v0)
    /* 6E90 80109690 00000000 */  nop
    /* 6E94 80109694 05004010 */  beqz       $v0, .L801096AC
    /* 6E98 80109698 00000000 */   nop
    /* 6E9C 8010969C E8F8030C */  jal        vs_mainMenu_unequipShield
    /* 6EA0 801096A0 00000000 */   nop
    /* 6EA4 801096A4 06000224 */  addiu      $v0, $zero, 0x6
    /* 6EA8 801096A8 6EBC62A2 */  sb         $v0, %lo(D_8010BC6E)($s3)
  .L801096AC:
    /* 6EAC 801096AC B30C040C */  jal        _disassembleShield
    /* 6EB0 801096B0 21200002 */   addu      $a0, $s0, $zero
    /* 6EB4 801096B4 03000424 */  addiu      $a0, $zero, 0x3
    /* 6EB8 801096B8 F8F8030C */  jal        vs_mainMenu_initItem
    /* 6EBC 801096BC 21282002 */   addu      $a1, $s1, $zero
    /* 6EC0 801096C0 01005226 */  addiu      $s2, $s2, 0x1
    /* 6EC4 801096C4 0200422A */  slti       $v0, $s2, 0x2
    /* 6EC8 801096C8 E8FF4014 */  bnez       $v0, .L8010966C
    /* 6ECC 801096CC 1180053C */   lui       $a1, %hi(D_8010BD14)
    /* 6ED0 801096D0 14BDA524 */  addiu      $a1, $a1, %lo(D_8010BD14)
    /* 6ED4 801096D4 1180023C */  lui        $v0, %hi(D_8010BD44)
    /* 6ED8 801096D8 30000624 */  addiu      $a2, $zero, 0x30
    /* 6EDC 801096DC 44BD5290 */  lbu        $s2, %lo(D_8010BD44)($v0)
    /* 6EE0 801096E0 0680023C */  lui        $v0, %hi(D_80060238)
    /* 6EE4 801096E4 38024224 */  addiu      $v0, $v0, %lo(D_80060238)
    /* 6EE8 801096E8 40181200 */  sll        $v1, $s2, 1
    /* 6EEC 801096EC 21187200 */  addu       $v1, $v1, $s2
    /* 6EF0 801096F0 00190300 */  sll        $v1, $v1, 4
    /* 6EF4 801096F4 21806200 */  addu       $s0, $v1, $v0
    /* 6EF8 801096F8 7000030C */  jal        vs_battle_copyAligned
    /* 6EFC 801096FC 21200002 */   addu      $a0, $s0, $zero
    /* 6F00 80109700 03000424 */  addiu      $a0, $zero, 0x3
    /* 6F04 80109704 2CFA030C */  jal        vs_mainMenu_rebuildInventory
    /* 6F08 80109708 000012A2 */   sb        $s2, 0x0($s0)
    /* 6F0C 8010970C 1180023C */  lui        $v0, %hi(D_8010BC6E)
    /* 6F10 80109710 6EBC4290 */  lbu        $v0, %lo(D_8010BC6E)($v0)
    /* 6F14 80109714 00000000 */  nop
    /* 6F18 80109718 06004238 */  xori       $v0, $v0, 0x6
    /* 6F1C 8010971C DA250408 */  j          .L80109768
    /* 6F20 80109720 2B100200 */   sltu      $v0, $zero, $v0
  .L80109724:
    /* 6F24 80109724 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 6F28 80109728 00000000 */   nop
    /* 6F2C 8010972C A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 6F30 80109730 01000424 */   addiu     $a0, $zero, 0x1
    /* 6F34 80109734 1180023C */  lui        $v0, %hi(D_8010BC6E)
    /* 6F38 80109738 D9250408 */  j          .L80109764
    /* 6F3C 8010973C 6EBC52A0 */   sb        $s2, %lo(D_8010BC6E)($v0)
  .L80109740:
    /* 6F40 80109740 E00C040C */  jal        func_80103380
    /* 6F44 80109744 01000424 */   addiu     $a0, $zero, 0x1
    /* 6F48 80109748 DA250408 */  j          .L80109768
    /* 6F4C 8010974C 00000000 */   nop
    /* 6F50 80109750 962E040C */  jal        func_8010BA58
    /* 6F54 80109754 01000424 */   addiu     $a0, $zero, 0x1
    /* 6F58 80109758 21184000 */  addu       $v1, $v0, $zero
    /* 6F5C 8010975C 02006010 */  beqz       $v1, .L80109768
    /* 6F60 80109760 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80109764:
    /* 6F64 80109764 21100000 */  addu       $v0, $zero, $zero
  .L80109768:
    /* 6F68 80109768 4400BF8F */  lw         $ra, 0x44($sp)
    /* 6F6C 8010976C 4000B68F */  lw         $s6, 0x40($sp)
    /* 6F70 80109770 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 6F74 80109774 3800B48F */  lw         $s4, 0x38($sp)
    /* 6F78 80109778 3400B38F */  lw         $s3, 0x34($sp)
    /* 6F7C 8010977C 3000B28F */  lw         $s2, 0x30($sp)
    /* 6F80 80109780 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 6F84 80109784 2800B08F */  lw         $s0, 0x28($sp)
    /* 6F88 80109788 0800E003 */  jr         $ra
    /* 6F8C 8010978C 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_80108EC4
