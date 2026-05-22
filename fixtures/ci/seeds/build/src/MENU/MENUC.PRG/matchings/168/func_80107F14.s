nonmatching func_80107F14, 0x8D0

glabel func_80107F14
    /* 5714 80107F14 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 5718 80107F18 4400BFAF */  sw         $ra, 0x44($sp)
    /* 571C 80107F1C 4000B6AF */  sw         $s6, 0x40($sp)
    /* 5720 80107F20 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 5724 80107F24 3800B4AF */  sw         $s4, 0x38($sp)
    /* 5728 80107F28 3400B3AF */  sw         $s3, 0x34($sp)
    /* 572C 80107F2C 3000B2AF */  sw         $s2, 0x30($sp)
    /* 5730 80107F30 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 5734 80107F34 0E008010 */  beqz       $a0, .L80107F70
    /* 5738 80107F38 2800B0AF */   sw        $s0, 0x28($sp)
    /* 573C 80107F3C 8D0A040C */  jal        func_80102A34
    /* 5740 80107F40 05000424 */   addiu     $a0, $zero, 0x5
    /* 5744 80107F44 21200000 */  addu       $a0, $zero, $zero
    /* 5748 80107F48 1180023C */  lui        $v0, %hi(D_8010BD10)
    /* 574C 80107F4C 251E040C */  jal        func_80107894
    /* 5750 80107F50 10BD40A4 */   sh        $zero, %lo(D_8010BD10)($v0)
    /* 5754 80107F54 21100000 */  addu       $v0, $zero, $zero
    /* 5758 80107F58 1180043C */  lui        $a0, %hi(D_8010BC63)
    /* 575C 80107F5C 01000324 */  addiu      $v1, $zero, 0x1
    /* 5760 80107F60 63BC83A0 */  sb         $v1, %lo(D_8010BC63)($a0)
    /* 5764 80107F64 1180033C */  lui        $v1, %hi(D_8010BC62)
    /* 5768 80107F68 EF210408 */  j          .L801087BC
    /* 576C 80107F6C 62BC60A0 */   sb        $zero, %lo(D_8010BC62)($v1)
  .L80107F70:
    /* 5770 80107F70 21880000 */  addu       $s1, $zero, $zero
    /* 5774 80107F74 1180023C */  lui        $v0, %hi(D_8010BD10)
    /* 5778 80107F78 10BD4390 */  lbu        $v1, %lo(D_8010BD10)($v0)
    /* 577C 80107F7C 00000000 */  nop
    /* 5780 80107F80 04006010 */  beqz       $v1, .L80107F94
    /* 5784 80107F84 10BD4224 */   addiu     $v0, $v0, %lo(D_8010BD10)
    /* 5788 80107F88 01004290 */  lbu        $v0, 0x1($v0)
    /* 578C 80107F8C 00000000 */  nop
    /* 5790 80107F90 2B882202 */  sltu       $s1, $s1, $v0
  .L80107F94:
    /* 5794 80107F94 1180043C */  lui        $a0, %hi(D_8010BC64)
    /* 5798 80107F98 1180053C */  lui        $a1, %hi(D_8010BC62)
    /* 579C 80107F9C 64BC8290 */  lbu        $v0, %lo(D_8010BC64)($a0)
    /* 57A0 80107FA0 62BCA390 */  lbu        $v1, %lo(D_8010BC62)($a1)
    /* 57A4 80107FA4 10004224 */  addiu      $v0, $v0, 0x10
    /* 57A8 80107FA8 64BC82A0 */  sb         $v0, %lo(D_8010BC64)($a0)
    /* 57AC 80107FAC 02000224 */  addiu      $v0, $zero, 0x2
    /* 57B0 80107FB0 02006210 */  beq        $v1, $v0, .L80107FBC
    /* 57B4 80107FB4 00000000 */   nop
    /* 57B8 80107FB8 64BC80A0 */  sb         $zero, %lo(D_8010BC64)($a0)
  .L80107FBC:
    /* 57BC 80107FBC 62BCA390 */  lbu        $v1, %lo(D_8010BC62)($a1)
    /* 57C0 80107FC0 00000000 */  nop
    /* 57C4 80107FC4 0700622C */  sltiu      $v0, $v1, 0x7
    /* 57C8 80107FC8 FB014010 */  beqz       $v0, .L801087B8
    /* 57CC 80107FCC 1080023C */   lui       $v0, %hi(jtbl_801028B0)
    /* 57D0 80107FD0 B0284224 */  addiu      $v0, $v0, %lo(jtbl_801028B0)
    /* 57D4 80107FD4 80180300 */  sll        $v1, $v1, 2
    /* 57D8 80107FD8 21186200 */  addu       $v1, $v1, $v0
    /* 57DC 80107FDC 0000628C */  lw         $v0, 0x0($v1)
    /* 57E0 80107FE0 00000000 */  nop
    /* 57E4 80107FE4 08004000 */  jr         $v0
    /* 57E8 80107FE8 00000000 */   nop
    /* 57EC 80107FEC 74EA030C */  jal        vs_mainmenu_ready
    /* 57F0 80107FF0 00000000 */   nop
    /* 57F4 80107FF4 F1014010 */  beqz       $v0, .L801087BC
    /* 57F8 80107FF8 21100000 */   addu      $v0, $zero, $zero
    /* 57FC 80107FFC 87040424 */  addiu      $a0, $zero, 0x487
    /* 5800 80108000 D40A040C */  jal        func_80102B50
    /* 5804 80108004 18000524 */   addiu     $a1, $zero, 0x18
    /* 5808 80108008 1180023C */  lui        $v0, %hi(D_8010BCE4)
    /* 580C 8010800C E4BC5190 */  lbu        $s1, %lo(D_8010BCE4)($v0)
    /* 5810 80108010 21200000 */  addu       $a0, $zero, $zero
    /* 5814 80108014 E4BC5024 */  addiu      $s0, $v0, %lo(D_8010BCE4)
    /* 5818 80108018 171E040C */  jal        func_8010785C
    /* 581C 8010801C 21282002 */   addu      $a1, $s1, $zero
    /* 5820 80108020 03002012 */  beqz       $s1, .L80108030
    /* 5824 80108024 21204000 */   addu      $a0, $v0, $zero
    /* 5828 80108028 AF1F040C */  jal        func_80107EBC
    /* 582C 8010802C 21280002 */   addu      $a1, $s0, $zero
  .L80108030:
    /* 5830 80108030 21800000 */  addu       $s0, $zero, $zero
    /* 5834 80108034 1180023C */  lui        $v0, %hi(D_8010BD10)
    /* 5838 80108038 10BD5624 */  addiu      $s6, $v0, %lo(D_8010BD10)
    /* 583C 8010803C 0680023C */  lui        $v0, %hi(D_800603BC)
    /* 5840 80108040 BC035524 */  addiu      $s5, $v0, %lo(D_800603BC)
    /* 5844 80108044 1080143C */  lui        $s4, %hi(vs_mainMenu_itemNames)
    /* 5848 80108048 22001224 */  addiu      $s2, $zero, 0x22
  .L8010804C:
    /* 584C 8010804C 21101602 */  addu       $v0, $s0, $s6
    /* 5850 80108050 00005190 */  lbu        $s1, 0x0($v0)
    /* 5854 80108054 00000000 */  nop
    /* 5858 80108058 06002012 */  beqz       $s1, .L80108074
    /* 585C 8010805C 40101100 */   sll       $v0, $s1, 1
    /* 5860 80108060 21105100 */  addu       $v0, $v0, $s1
    /* 5864 80108064 80100200 */  sll        $v0, $v0, 2
    /* 5868 80108068 23105100 */  subu       $v0, $v0, $s1
    /* 586C 8010806C 80100200 */  sll        $v0, $v0, 2
    /* 5870 80108070 21985500 */  addu       $s3, $v0, $s5
  .L80108074:
    /* 5874 80108074 1000A0AF */  sw         $zero, 0x10($sp)
    /* 5878 80108078 0B000426 */  addiu      $a0, $s0, 0xB
    /* 587C 8010807C 05002016 */  bnez       $s1, .L80108094
    /* 5880 80108080 21304002 */   addu      $a2, $s2, $zero
    /* 5884 80108084 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 5888 80108088 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 588C 8010808C 2C200408 */  j          .L801080B0
    /* 5890 80108090 6C084224 */   addiu     $v0, $v0, 0x86C
  .L80108094:
    /* 5894 80108094 00006292 */  lbu        $v0, 0x0($s3)
    /* 5898 80108098 00000000 */  nop
    /* 589C 8010809C 40180200 */  sll        $v1, $v0, 1
    /* 58A0 801080A0 21186200 */  addu       $v1, $v1, $v0
    /* 58A4 801080A4 9C22828E */  lw         $v0, %lo(vs_mainMenu_itemNames)($s4)
    /* 58A8 801080A8 C0180300 */  sll        $v1, $v1, 3
    /* 58AC 801080AC 21104300 */  addu       $v0, $v0, $v1
  .L801080B0:
    /* 58B0 801080B0 1400A2AF */  sw         $v0, 0x14($sp)
    /* 58B4 801080B4 4E010524 */  addiu      $a1, $zero, 0x14E
    /* 58B8 801080B8 9723030C */  jal        vs_battle_setMenuItem
    /* 58BC 801080BC 97000724 */   addiu     $a3, $zero, 0x97
    /* 58C0 801080C0 21204000 */  addu       $a0, $v0, $zero
    /* 58C4 801080C4 02000224 */  addiu      $v0, $zero, 0x2
    /* 58C8 801080C8 000082A0 */  sb         $v0, 0x0($a0)
    /* 58CC 801080CC A9000224 */  addiu      $v0, $zero, 0xA9
    /* 58D0 801080D0 04002016 */  bnez       $s1, .L801080E4
    /* 58D4 801080D4 180082A4 */   sh        $v0, 0x18($a0)
    /* 58D8 801080D8 01000224 */  addiu      $v0, $zero, 0x1
    /* 58DC 801080DC 3B200408 */  j          .L801080EC
    /* 58E0 801080E0 0A0082A0 */   sb        $v0, 0xA($a0)
  .L801080E4:
    /* 58E4 801080E4 AF1F040C */  jal        func_80107EBC
    /* 58E8 801080E8 21286002 */   addu      $a1, $s3, $zero
  .L801080EC:
    /* 58EC 801080EC 01001026 */  addiu      $s0, $s0, 0x1
    /* 58F0 801080F0 0200022A */  slti       $v0, $s0, 0x2
    /* 58F4 801080F4 D5FF4014 */  bnez       $v0, .L8010804C
    /* 58F8 801080F8 10005226 */   addiu     $s2, $s2, 0x10
    /* 58FC 801080FC 02000324 */  addiu      $v1, $zero, 0x2
    /* 5900 80108100 1180023C */  lui        $v0, %hi(D_8010BC62)
    /* 5904 80108104 EE210408 */  j          .L801087B8
    /* 5908 80108108 62BC43A0 */   sb        $v1, %lo(D_8010BC62)($v0)
    /* 590C 8010810C 74EA030C */  jal        vs_mainmenu_ready
    /* 5910 80108110 00000000 */   nop
    /* 5914 80108114 E3004010 */  beqz       $v0, .L801084A4
    /* 5918 80108118 0680103C */   lui       $s0, %hi(vs_main_buttonsPressed)
    /* 591C 8010811C D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 5920 80108120 00000000 */  nop
    /* 5924 80108124 10004230 */  andi       $v0, $v0, 0x10
    /* 5928 80108128 9A014014 */  bnez       $v0, .L80108794
    /* 592C 8010812C 00000000 */   nop
    /* 5930 80108130 04002012 */  beqz       $s1, .L80108144
    /* 5934 80108134 1180023C */   lui       $v0, %hi(D_8010BC64)
    /* 5938 80108138 64BC4590 */  lbu        $a1, %lo(D_8010BC64)($v0)
    /* 593C 8010813C 5A0A040C */  jal        func_80102968
    /* 5940 80108140 02000424 */   addiu     $a0, $zero, 0x2
  .L80108144:
    /* 5944 80108144 D0E1038E */  lw         $v1, %lo(vs_main_buttonsPressed)($s0)
    /* 5948 80108148 00000000 */  nop
    /* 594C 8010814C 40006230 */  andi       $v0, $v1, 0x40
    /* 5950 80108150 2B004010 */  beqz       $v0, .L80108200
    /* 5954 80108154 00086230 */   andi      $v0, $v1, 0x800
    /* 5958 80108158 AE0A040C */  jal        func_80102AB8
    /* 595C 8010815C 05000424 */   addiu     $a0, $zero, 0x5
    /* 5960 80108160 21804000 */  addu       $s0, $v0, $zero
    /* 5964 80108164 8B010012 */  beqz       $s0, .L80108794
    /* 5968 80108168 00000000 */   nop
    /* 596C 8010816C BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 5970 80108170 00000000 */   nop
    /* 5974 80108174 21200002 */  addu       $a0, $s0, $zero
    /* 5978 80108178 1180023C */  lui        $v0, %hi(D_8010BC63)
    /* 597C 8010817C 63BC50A0 */  sb         $s0, %lo(D_8010BC63)($v0)
    /* 5980 80108180 1180023C */  lui        $v0, %hi(D_8010BD10)
    /* 5984 80108184 10BD4224 */  addiu      $v0, $v0, %lo(D_8010BD10)
    /* 5988 80108188 21100202 */  addu       $v0, $s0, $v0
    /* 598C 8010818C 251E040C */  jal        func_80107894
    /* 5990 80108190 FFFF40A0 */   sb        $zero, -0x1($v0)
    /* 5994 80108194 0A000426 */  addiu      $a0, $s0, 0xA
    /* 5998 80108198 A9000524 */  addiu      $a1, $zero, 0xA9
    /* 599C 8010819C 00311000 */  sll        $a2, $s0, 4
    /* 59A0 801081A0 1200C624 */  addiu      $a2, $a2, 0x12
    /* 59A4 801081A4 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 59A8 801081A8 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 59AC 801081AC 97000724 */  addiu      $a3, $zero, 0x97
    /* 59B0 801081B0 1000A0AF */  sw         $zero, 0x10($sp)
    /* 59B4 801081B4 6C084224 */  addiu      $v0, $v0, 0x86C
    /* 59B8 801081B8 9723030C */  jal        vs_battle_setMenuItem
    /* 59BC 801081BC 1400A2AF */   sw        $v0, 0x14($sp)
    /* 59C0 801081C0 21204000 */  addu       $a0, $v0, $zero
    /* 59C4 801081C4 01000224 */  addiu      $v0, $zero, 0x1
    /* 59C8 801081C8 060082A0 */  sb         $v0, 0x6($a0)
    /* 59CC 801081CC 0A0082A0 */  sb         $v0, 0xA($a0)
    /* 59D0 801081D0 1180023C */  lui        $v0, %hi(D_8010BCE4)
    /* 59D4 801081D4 21200000 */  addu       $a0, $zero, $zero
    /* 59D8 801081D8 E4BC5190 */  lbu        $s1, %lo(D_8010BCE4)($v0)
    /* 59DC 801081DC E4BC5024 */  addiu      $s0, $v0, %lo(D_8010BCE4)
    /* 59E0 801081E0 F71D040C */  jal        func_801077DC
    /* 59E4 801081E4 21282002 */   addu      $a1, $s1, $zero
    /* 59E8 801081E8 73012012 */  beqz       $s1, .L801087B8
    /* 59EC 801081EC 21204000 */   addu      $a0, $v0, $zero
    /* 59F0 801081F0 AF1F040C */  jal        func_80107EBC
    /* 59F4 801081F4 21280002 */   addu      $a1, $s0, $zero
    /* 59F8 801081F8 EF210408 */  j          .L801087BC
    /* 59FC 801081FC 21100000 */   addu      $v0, $zero, $zero
  .L80108200:
    /* 5A00 80108200 12004010 */  beqz       $v0, .L8010824C
    /* 5A04 80108204 1180033C */   lui       $v1, %hi(D_8010BC63)
    /* 5A08 80108208 11002012 */  beqz       $s1, .L80108250
    /* 5A0C 8010820C 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* 5A10 80108210 BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 5A14 80108214 1180103C */   lui       $s0, %hi(D_8010BC63)
    /* 5A18 80108218 63BC0492 */  lbu        $a0, %lo(D_8010BC63)($s0)
    /* 5A1C 8010821C 9223030C */  jal        vs_battle_getMenuItem
    /* 5A20 80108220 0A008424 */   addiu     $a0, $a0, 0xA
    /* 5A24 80108224 03000424 */  addiu      $a0, $zero, 0x3
    /* 5A28 80108228 060040A0 */  sb         $zero, 0x6($v0)
    /* 5A2C 8010822C 21108000 */  addu       $v0, $a0, $zero
    /* 5A30 80108230 1180033C */  lui        $v1, %hi(D_8010BC62)
    /* 5A34 80108234 63BC02A2 */  sb         $v0, %lo(D_8010BC63)($s0)
    /* 5A38 80108238 04000224 */  addiu      $v0, $zero, 0x4
    /* 5A3C 8010823C 251E040C */  jal        func_80107894
    /* 5A40 80108240 62BC62A0 */   sb        $v0, %lo(D_8010BC62)($v1)
    /* 5A44 80108244 EF210408 */  j          .L801087BC
    /* 5A48 80108248 21100000 */   addu      $v0, $zero, $zero
  .L8010824C:
    /* 5A4C 8010824C 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
  .L80108250:
    /* 5A50 80108250 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 5A54 80108254 63BC7090 */  lbu        $s0, %lo(D_8010BC63)($v1)
    /* 5A58 80108258 20004230 */  andi       $v0, $v0, 0x20
    /* 5A5C 8010825C 15004010 */  beqz       $v0, .L801082B4
    /* 5A60 80108260 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 5A64 80108264 05000016 */  bnez       $s0, .L8010827C
    /* 5A68 80108268 00000000 */   nop
    /* 5A6C 8010826C B800030C */  jal        vs_battle_playInvalidSfx
    /* 5A70 80108270 00000000 */   nop
    /* 5A74 80108274 AD200408 */  j          .L801082B4
    /* 5A78 80108278 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
  .L8010827C:
    /* 5A7C 8010827C BC00030C */  jal        vs_battle_playMenuSelectSfx
    /* 5A80 80108280 03001124 */   addiu     $s1, $zero, 0x3
    /* 5A84 80108284 04001116 */  bne        $s0, $s1, .L80108298
    /* 5A88 80108288 1180033C */   lui       $v1, %hi(D_8010BC62)
    /* 5A8C 8010828C 04000224 */  addiu      $v0, $zero, 0x4
    /* 5A90 80108290 EE210408 */  j          .L801087B8
    /* 5A94 80108294 62BC62A0 */   sb        $v0, %lo(D_8010BC62)($v1)
  .L80108298:
    /* 5A98 80108298 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 5A9C 8010829C 28000424 */   addiu     $a0, $zero, 0x28
    /* 5AA0 801082A0 B51E040C */  jal        func_80107AD4
    /* 5AA4 801082A4 21200002 */   addu      $a0, $s0, $zero
    /* 5AA8 801082A8 1180023C */  lui        $v0, %hi(D_8010BC62)
    /* 5AAC 801082AC EE210408 */  j          .L801087B8
    /* 5AB0 801082B0 62BC51A0 */   sb        $s1, %lo(D_8010BC62)($v0)
  .L801082B4:
    /* 5AB4 801082B4 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 5AB8 801082B8 00000000 */  nop
    /* 5ABC 801082BC 00104230 */  andi       $v0, $v0, 0x1000
    /* 5AC0 801082C0 04004010 */  beqz       $v0, .L801082D4
    /* 5AC4 801082C4 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 5AC8 801082C8 02000016 */  bnez       $s0, .L801082D4
    /* 5ACC 801082CC FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 5AD0 801082D0 02003026 */  addiu      $s0, $s1, 0x2
  .L801082D4:
    /* 5AD4 801082D4 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 5AD8 801082D8 00000000 */  nop
    /* 5ADC 801082DC 00404230 */  andi       $v0, $v0, 0x4000
    /* 5AE0 801082E0 04004010 */  beqz       $v0, .L801082F4
    /* 5AE4 801082E4 02002226 */   addiu     $v0, $s1, 0x2
    /* 5AE8 801082E8 02000216 */  bne        $s0, $v0, .L801082F4
    /* 5AEC 801082EC 01001026 */   addiu     $s0, $s0, 0x1
    /* 5AF0 801082F0 21800000 */  addu       $s0, $zero, $zero
  .L801082F4:
    /* 5AF4 801082F4 1180123C */  lui        $s2, %hi(D_8010BC63)
    /* 5AF8 801082F8 63BC4292 */  lbu        $v0, %lo(D_8010BC63)($s2)
    /* 5AFC 801082FC 00000000 */  nop
    /* 5B00 80108300 06000212 */  beq        $s0, $v0, .L8010831C
    /* 5B04 80108304 01001124 */   addiu     $s1, $zero, 0x1
    /* 5B08 80108308 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 5B0C 8010830C 00000000 */   nop
    /* 5B10 80108310 63BC50A2 */  sb         $s0, %lo(D_8010BC63)($s2)
    /* 5B14 80108314 251E040C */  jal        func_80107894
    /* 5B18 80108318 FF000432 */   andi      $a0, $s0, 0xFF
  .L8010831C:
    /* 5B1C 8010831C 21A04002 */  addu       $s4, $s2, $zero
    /* 5B20 80108320 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 5B24 80108324 21904000 */  addu       $s2, $v0, $zero
    /* 5B28 80108328 1180023C */  lui        $v0, %hi(D_8010BD10)
    /* 5B2C 8010832C 10BD5324 */  addiu      $s3, $v0, %lo(D_8010BD10)
    /* 5B30 80108330 1180023C */  lui        $v0, %hi(D_8010BCE4)
    /* 5B34 80108334 E4BC4290 */  lbu        $v0, %lo(D_8010BCE4)($v0)
    /* 5B38 80108338 844E438E */  lw         $v1, %lo(vs_battle_rowTypeBuf)($s2)
    /* 5B3C 8010833C 2B105100 */  sltu       $v0, $v0, $s1
    /* 5B40 80108340 000062AC */  sw         $v0, 0x0($v1)
  .L80108344:
    /* 5B44 80108344 9223030C */  jal        vs_battle_getMenuItem
    /* 5B48 80108348 0A002426 */   addiu     $a0, $s1, 0xA
    /* 5B4C 8010834C 80201100 */  sll        $a0, $s1, 2
    /* 5B50 80108350 63BC8392 */  lbu        $v1, %lo(D_8010BC63)($s4)
    /* 5B54 80108354 21283302 */  addu       $a1, $s1, $s3
    /* 5B58 80108358 26182302 */  xor        $v1, $s1, $v1
    /* 5B5C 8010835C 01003126 */  addiu      $s1, $s1, 0x1
    /* 5B60 80108360 0100632C */  sltiu      $v1, $v1, 0x1
    /* 5B64 80108364 060043A0 */  sb         $v1, 0x6($v0)
    /* 5B68 80108368 844E438E */  lw         $v1, %lo(vs_battle_rowTypeBuf)($s2)
    /* 5B6C 8010836C FFFFA290 */  lbu        $v0, -0x1($a1)
    /* 5B70 80108370 21208300 */  addu       $a0, $a0, $v1
    /* 5B74 80108374 0100422C */  sltiu      $v0, $v0, 0x1
    /* 5B78 80108378 000082AC */  sw         $v0, 0x0($a0)
    /* 5B7C 8010837C 0300222A */  slti       $v0, $s1, 0x3
    /* 5B80 80108380 F0FF4014 */  bnez       $v0, .L80108344
    /* 5B84 80108384 21200002 */   addu      $a0, $s0, $zero
    /* 5B88 80108388 10000524 */  addiu      $a1, $zero, 0x10
    /* 5B8C 8010838C 0F80023C */  lui        $v0, %hi(vs_battle_rowTypeBuf)
    /* 5B90 80108390 844E438C */  lw         $v1, %lo(vs_battle_rowTypeBuf)($v0)
    /* 5B94 80108394 01000224 */  addiu      $v0, $zero, 0x1
    /* 5B98 80108398 79FE030C */  jal        vs_mainMenu_printInformation
    /* 5B9C 8010839C 0C0062AC */   sw        $v0, 0xC($v1)
    /* 5BA0 801083A0 1080023C */  lui        $v0, %hi(vs_mainMenu_menu12Text)
    /* 5BA4 801083A4 A424438C */  lw         $v1, %lo(vs_mainMenu_menu12Text)($v0)
    /* 5BA8 801083A8 00000000 */  nop
    /* 5BAC 801083AC B2086224 */  addiu      $v0, $v1, 0x8B2
    /* 5BB0 801083B0 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5BB4 801083B4 0300022A */  slti       $v0, $s0, 0x3
    /* 5BB8 801083B8 07004010 */  beqz       $v0, .L801083D8
    /* 5BBC 801083BC 00000000 */   nop
    /* 5BC0 801083C0 1000001E */  bgtz       $s0, .L80108404
    /* 5BC4 801083C4 1180023C */   lui       $v0, %hi(D_8010BD10)
    /* 5BC8 801083C8 08000012 */  beqz       $s0, .L801083EC
    /* 5BCC 801083CC 1180023C */   lui       $v0, %hi(D_8010BCE4)
    /* 5BD0 801083D0 16210408 */  j          .L80108458
    /* 5BD4 801083D4 00000000 */   nop
  .L801083D8:
    /* 5BD8 801083D8 03000224 */  addiu      $v0, $zero, 0x3
    /* 5BDC 801083DC 1D000212 */  beq        $s0, $v0, .L80108454
    /* 5BE0 801083E0 3C076224 */   addiu     $v0, $v1, 0x73C
    /* 5BE4 801083E4 16210408 */  j          .L80108458
    /* 5BE8 801083E8 00000000 */   nop
  .L801083EC:
    /* 5BEC 801083EC E4BC4390 */  lbu        $v1, %lo(D_8010BCE4)($v0)
    /* 5BF0 801083F0 00000000 */  nop
    /* 5BF4 801083F4 18006010 */  beqz       $v1, .L80108458
    /* 5BF8 801083F8 E4BC4424 */   addiu     $a0, $v0, %lo(D_8010BCE4)
    /* 5BFC 801083FC 0F210408 */  j          .L8010843C
    /* 5C00 80108400 1800A527 */   addiu     $a1, $sp, 0x18
  .L80108404:
    /* 5C04 80108404 10BD4224 */  addiu      $v0, $v0, %lo(D_8010BD10)
    /* 5C08 80108408 21100202 */  addu       $v0, $s0, $v0
    /* 5C0C 8010840C FFFF5190 */  lbu        $s1, -0x1($v0)
    /* 5C10 80108410 00000000 */  nop
    /* 5C14 80108414 10002012 */  beqz       $s1, .L80108458
    /* 5C18 80108418 40201100 */   sll       $a0, $s1, 1
    /* 5C1C 8010841C 21209100 */  addu       $a0, $a0, $s1
    /* 5C20 80108420 80200400 */  sll        $a0, $a0, 2
    /* 5C24 80108424 23209100 */  subu       $a0, $a0, $s1
    /* 5C28 80108428 80200400 */  sll        $a0, $a0, 2
    /* 5C2C 8010842C 0680023C */  lui        $v0, %hi(D_800603BC)
    /* 5C30 80108430 BC034224 */  addiu      $v0, $v0, %lo(D_800603BC)
    /* 5C34 80108434 21208200 */  addu       $a0, $a0, $v0
    /* 5C38 80108438 1800A527 */  addiu      $a1, $sp, 0x18
  .L8010843C:
    /* 5C3C 8010843C 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* 5C40 80108440 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* 5C44 80108444 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* 5C48 80108448 2000A627 */   addiu     $a2, $sp, 0x20
    /* 5C4C 8010844C 16210408 */  j          .L80108458
    /* 5C50 80108450 00000000 */   nop
  .L80108454:
    /* 5C54 80108454 1C00A2AF */  sw         $v0, 0x1C($sp)
  .L80108458:
    /* 5C58 80108458 1C00A48F */  lw         $a0, 0x1C($sp)
    /* 5C5C 8010845C 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 5C60 80108460 00000000 */   nop
    /* 5C64 80108464 00111000 */  sll        $v0, $s0, 4
    /* 5C68 80108468 0A004224 */  addiu      $v0, $v0, 0xA
    /* 5C6C 8010846C 00140200 */  sll        $v0, $v0, 16
    /* 5C70 80108470 02000016 */  bnez       $s0, .L8010847C
    /* 5C74 80108474 9B005134 */   ori       $s1, $v0, 0x9B
    /* 5C78 80108478 F2FF3126 */  addiu      $s1, $s1, -0xE
  .L8010847C:
    /* 5C7C 8010847C 03000224 */  addiu      $v0, $zero, 0x3
    /* 5C80 80108480 03000216 */  bne        $s0, $v0, .L80108490
    /* 5C84 80108484 1180103C */   lui       $s0, %hi(D_8010BB74)
    /* 5C88 80108488 FCFF023C */  lui        $v0, (0xFFFC0000 >> 16)
    /* 5C8C 8010848C 21882202 */  addu       $s1, $s1, $v0
  .L80108490:
    /* 5C90 80108490 74BB0492 */  lbu        $a0, %lo(D_8010BB74)($s0)
    /* 5C94 80108494 37FF030C */  jal        func_800FFCDC
    /* 5C98 80108498 21282002 */   addu      $a1, $s1, $zero
    /* 5C9C 8010849C EE210408 */  j          .L801087B8
    /* 5CA0 801084A0 74BB02A2 */   sb        $v0, %lo(D_8010BB74)($s0)
  .L801084A4:
    /* 5CA4 801084A4 1180023C */  lui        $v0, %hi(D_8010BC64)
    /* 5CA8 801084A8 EE210408 */  j          .L801087B8
    /* 5CAC 801084AC 64BC40A0 */   sb        $zero, %lo(D_8010BC64)($v0)
    /* 5CB0 801084B0 B51E040C */  jal        func_80107AD4
    /* 5CB4 801084B4 21200000 */   addu      $a0, $zero, $zero
    /* 5CB8 801084B8 21804000 */  addu       $s0, $v0, $zero
    /* 5CBC 801084BC BE000012 */  beqz       $s0, .L801087B8
    /* 5CC0 801084C0 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 5CC4 801084C4 B3000212 */  beq        $s0, $v0, .L80108794
    /* 5CC8 801084C8 00000000 */   nop
    /* 5CCC 801084CC 2000001A */  blez       $s0, .L80108550
    /* 5CD0 801084D0 1180123C */   lui       $s2, %hi(D_8010BC63)
    /* 5CD4 801084D4 63BC4292 */  lbu        $v0, %lo(D_8010BC63)($s2)
    /* 5CD8 801084D8 1180133C */  lui        $s3, %hi(D_8010BD10)
    /* 5CDC 801084DC FFFF5124 */  addiu      $s1, $v0, -0x1
    /* 5CE0 801084E0 10BD6226 */  addiu      $v0, $s3, %lo(D_8010BD10)
    /* 5CE4 801084E4 21182202 */  addu       $v1, $s1, $v0
    /* 5CE8 801084E8 00006290 */  lbu        $v0, 0x0($v1)
    /* 5CEC 801084EC 00000000 */  nop
    /* 5CF0 801084F0 06000216 */  bne        $s0, $v0, .L8010850C
    /* 5CF4 801084F4 21202002 */   addu      $a0, $s1, $zero
    /* 5CF8 801084F8 000060A0 */  sb         $zero, 0x0($v1)
    /* 5CFC 801084FC AE0A040C */  jal        func_80102AB8
    /* 5D00 80108500 21202002 */   addu      $a0, $s1, $zero
    /* 5D04 80108504 51210408 */  j          .L80108544
    /* 5D08 80108508 1180023C */   lui       $v0, %hi(D_8010BC63)
  .L8010850C:
    /* 5D0C 8010850C 8D0A040C */  jal        func_80102A34
    /* 5D10 80108510 000070A0 */   sb        $s0, 0x0($v1)
    /* 5D14 80108514 63BC4292 */  lbu        $v0, %lo(D_8010BC63)($s2)
    /* 5D18 80108518 00000000 */  nop
    /* 5D1C 8010851C 01004224 */  addiu      $v0, $v0, 0x1
    /* 5D20 80108520 63BC42A2 */  sb         $v0, %lo(D_8010BC63)($s2)
    /* 5D24 80108524 01000224 */  addiu      $v0, $zero, 0x1
    /* 5D28 80108528 06002216 */  bne        $s1, $v0, .L80108544
    /* 5D2C 8010852C 1180023C */   lui       $v0, %hi(D_8010BC63)
    /* 5D30 80108530 10BD6292 */  lbu        $v0, %lo(D_8010BD10)($s3)
    /* 5D34 80108534 00000000 */  nop
    /* 5D38 80108538 02004014 */  bnez       $v0, .L80108544
    /* 5D3C 8010853C 1180023C */   lui       $v0, %hi(D_8010BC63)
    /* 5D40 80108540 63BC51A2 */  sb         $s1, %lo(D_8010BC63)($s2)
  .L80108544:
    /* 5D44 80108544 63BC4490 */  lbu        $a0, %lo(D_8010BC63)($v0)
    /* 5D48 80108548 251E040C */  jal        func_80107894
    /* 5D4C 8010854C 00000000 */   nop
  .L80108550:
    /* 5D50 80108550 1180033C */  lui        $v1, %hi(D_8010BC62)
    /* 5D54 80108554 01000224 */  addiu      $v0, $zero, 0x1
    /* 5D58 80108558 EE210408 */  j          .L801087B8
    /* 5D5C 8010855C 62BC62A0 */   sb        $v0, %lo(D_8010BC62)($v1)
    /* 5D60 80108560 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 5D64 80108564 02000424 */   addiu     $a0, $zero, 0x2
    /* 5D68 80108568 900B040C */  jal        func_80102E40
    /* 5D6C 8010856C 02000424 */   addiu     $a0, $zero, 0x2
    /* 5D70 80108570 21880000 */  addu       $s1, $zero, $zero
    /* 5D74 80108574 21802002 */  addu       $s0, $s1, $zero
    /* 5D78 80108578 0680023C */  lui        $v0, %hi(vs_battle_inventory)
    /* 5D7C 8010857C 68014524 */  addiu      $a1, $v0, %lo(vs_battle_inventory)
    /* 5D80 80108580 1180023C */  lui        $v0, %hi(D_8010BD10)
    /* 5D84 80108584 10BD4424 */  addiu      $a0, $v0, %lo(D_8010BD10)
    /* 5D88 80108588 21100402 */  addu       $v0, $s0, $a0
  .L8010858C:
    /* 5D8C 8010858C 00004390 */  lbu        $v1, 0x0($v0)
    /* 5D90 80108590 00000000 */  nop
    /* 5D94 80108594 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 5D98 80108598 40100300 */  sll        $v0, $v1, 1
    /* 5D9C 8010859C 21104300 */  addu       $v0, $v0, $v1
    /* 5DA0 801085A0 80100200 */  sll        $v0, $v0, 2
    /* 5DA4 801085A4 23104300 */  subu       $v0, $v0, $v1
    /* 5DA8 801085A8 80100200 */  sll        $v0, $v0, 2
    /* 5DAC 801085AC 21104500 */  addu       $v0, $v0, $a1
    /* 5DB0 801085B0 AA024290 */  lbu        $v0, 0x2AA($v0)
    /* 5DB4 801085B4 01001026 */  addiu      $s0, $s0, 0x1
    /* 5DB8 801085B8 25882202 */  or         $s1, $s1, $v0
    /* 5DBC 801085BC 0200022A */  slti       $v0, $s0, 0x2
    /* 5DC0 801085C0 F2FF4014 */  bnez       $v0, .L8010858C
    /* 5DC4 801085C4 21100402 */   addu      $v0, $s0, $a0
    /* 5DC8 801085C8 04002016 */  bnez       $s1, .L801085DC
    /* 5DCC 801085CC 1080023C */   lui       $v0, %hi(vs_mainMenu_menu12Text)
    /* 5DD0 801085D0 A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 5DD4 801085D4 7A210408 */  j          .L801085E8
    /* 5DD8 801085D8 56084424 */   addiu     $a0, $v0, 0x856
  .L801085DC:
    /* 5DDC 801085DC A424428C */  lw         $v0, %lo(vs_mainMenu_menu12Text)($v0)
    /* 5DE0 801085E0 00000000 */  nop
    /* 5DE4 801085E4 4E094424 */  addiu      $a0, $v0, 0x94E
  .L801085E8:
    /* 5DE8 801085E8 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 5DEC 801085EC 00000000 */   nop
    /* 5DF0 801085F0 1180033C */  lui        $v1, %hi(D_8010BC62)
    /* 5DF4 801085F4 05000224 */  addiu      $v0, $zero, 0x5
    /* 5DF8 801085F8 EE210408 */  j          .L801087B8
    /* 5DFC 801085FC 62BC62A0 */   sb        $v0, %lo(D_8010BC62)($v1)
    /* 5E00 80108600 900B040C */  jal        func_80102E40
    /* 5E04 80108604 21200000 */   addu      $a0, $zero, $zero
    /* 5E08 80108608 21804000 */  addu       $s0, $v0, $zero
    /* 5E0C 8010860C 6A000012 */  beqz       $s0, .L801087B8
    /* 5E10 80108610 02000224 */   addiu     $v0, $zero, 0x2
    /* 5E14 80108614 58000212 */  beq        $s0, $v0, .L80108778
    /* 5E18 80108618 0300022A */   slti      $v0, $s0, 0x3
    /* 5E1C 8010861C 05004010 */  beqz       $v0, .L80108634
    /* 5E20 80108620 01000224 */   addiu     $v0, $zero, 0x1
    /* 5E24 80108624 08000212 */  beq        $s0, $v0, .L80108648
    /* 5E28 80108628 21100000 */   addu      $v0, $zero, $zero
    /* 5E2C 8010862C EF210408 */  j          .L801087BC
    /* 5E30 80108630 00000000 */   nop
  .L80108634:
    /* 5E34 80108634 03000224 */  addiu      $v0, $zero, 0x3
    /* 5E38 80108638 56000212 */  beq        $s0, $v0, .L80108794
    /* 5E3C 8010863C 21100000 */   addu      $v0, $zero, $zero
    /* 5E40 80108640 EF210408 */  j          .L801087BC
    /* 5E44 80108644 00000000 */   nop
  .L80108648:
    /* 5E48 80108648 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 5E4C 8010864C 6216010C */  jal        vs_main_playSfxDefault
    /* 5E50 80108650 18000524 */   addiu     $a1, $zero, 0x18
    /* 5E54 80108654 F2FE030C */  jal        func_800FFBC8
    /* 5E58 80108658 00000000 */   nop
    /* 5E5C 8010865C F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 5E60 80108660 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 5E64 80108664 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 5E68 80108668 04000424 */   addiu     $a0, $zero, 0x4
    /* 5E6C 8010866C 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 5E70 80108670 28000424 */   addiu     $a0, $zero, 0x28
    /* 5E74 80108674 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 5E78 80108678 21200000 */   addu      $a0, $zero, $zero
    /* 5E7C 8010867C 0680023C */  lui        $v0, %hi(D_800603BC)
    /* 5E80 80108680 BC035524 */  addiu      $s5, $v0, %lo(D_800603BC)
    /* 5E84 80108684 ACFDB626 */  addiu      $s6, $s5, -0x254
    /* 5E88 80108688 1180023C */  lui        $v0, %hi(D_8010BD10)
    /* 5E8C 8010868C 10BD5424 */  addiu      $s4, $v0, %lo(D_8010BD10)
    /* 5E90 80108690 21908002 */  addu       $s2, $s4, $zero
  .L80108694:
    /* 5E94 80108694 00004392 */  lbu        $v1, 0x0($s2)
    /* 5E98 80108698 00000000 */  nop
    /* 5E9C 8010869C 40100300 */  sll        $v0, $v1, 1
    /* 5EA0 801086A0 21104300 */  addu       $v0, $v0, $v1
    /* 5EA4 801086A4 80100200 */  sll        $v0, $v0, 2
    /* 5EA8 801086A8 23104300 */  subu       $v0, $v0, $v1
    /* 5EAC 801086AC 80100200 */  sll        $v0, $v0, 2
    /* 5EB0 801086B0 21985500 */  addu       $s3, $v0, $s5
    /* 5EB4 801086B4 2A007192 */  lbu        $s1, 0x2A($s3)
    /* 5EB8 801086B8 00000000 */  nop
    /* 5EBC 801086BC 10002012 */  beqz       $s1, .L80108700
    /* 5EC0 801086C0 01000424 */   addiu     $a0, $zero, 0x1
    /* 5EC4 801086C4 FFFF3026 */  addiu      $s0, $s1, -0x1
    /* 5EC8 801086C8 40111000 */  sll        $v0, $s0, 5
    /* 5ECC 801086CC 21105600 */  addu       $v0, $v0, $s6
    /* 5ED0 801086D0 03004290 */  lbu        $v0, 0x3($v0)
    /* 5ED4 801086D4 00000000 */  nop
    /* 5ED8 801086D8 06004010 */  beqz       $v0, .L801086F4
    /* 5EDC 801086DC 00000000 */   nop
    /* 5EE0 801086E0 D8F8030C */  jal        vs_mainMenu_unequipAllWeapons
    /* 5EE4 801086E4 00000000 */   nop
    /* 5EE8 801086E8 1180033C */  lui        $v1, %hi(D_8010BC62)
    /* 5EEC 801086EC 06000224 */  addiu      $v0, $zero, 0x6
    /* 5EF0 801086F0 62BC62A0 */  sb         $v0, %lo(D_8010BC62)($v1)
  .L801086F4:
    /* 5EF4 801086F4 1B0C040C */  jal        _disassembleWeapon
    /* 5EF8 801086F8 21200002 */   addu      $a0, $s0, $zero
    /* 5EFC 801086FC 01000424 */  addiu      $a0, $zero, 0x1
  .L80108700:
    /* 5F00 80108700 00004592 */  lbu        $a1, 0x0($s2)
    /* 5F04 80108704 F8F8030C */  jal        vs_mainMenu_initItem
    /* 5F08 80108708 21904402 */   addu      $s2, $s2, $a0
    /* 5F0C 8010870C 02008226 */  addiu      $v0, $s4, 0x2
    /* 5F10 80108710 2A104202 */  slt        $v0, $s2, $v0
    /* 5F14 80108714 DFFF4014 */  bnez       $v0, .L80108694
    /* 5F18 80108718 1180053C */   lui       $a1, %hi(D_8010BCE4)
    /* 5F1C 8010871C E4BCA524 */  addiu      $a1, $a1, %lo(D_8010BCE4)
    /* 5F20 80108720 1180023C */  lui        $v0, %hi(D_8010BD10)
    /* 5F24 80108724 2C000624 */  addiu      $a2, $zero, 0x2C
    /* 5F28 80108728 0680033C */  lui        $v1, %hi(D_800603BC)
    /* 5F2C 8010872C 10BD5090 */  lbu        $s0, %lo(D_8010BD10)($v0)
    /* 5F30 80108730 BC036324 */  addiu      $v1, $v1, %lo(D_800603BC)
    /* 5F34 80108734 40101000 */  sll        $v0, $s0, 1
    /* 5F38 80108738 21105000 */  addu       $v0, $v0, $s0
    /* 5F3C 8010873C 80100200 */  sll        $v0, $v0, 2
    /* 5F40 80108740 23105000 */  subu       $v0, $v0, $s0
    /* 5F44 80108744 80100200 */  sll        $v0, $v0, 2
    /* 5F48 80108748 21984300 */  addu       $s3, $v0, $v1
    /* 5F4C 8010874C 7000030C */  jal        vs_battle_copyAligned
    /* 5F50 80108750 21206002 */   addu      $a0, $s3, $zero
    /* 5F54 80108754 01000424 */  addiu      $a0, $zero, 0x1
    /* 5F58 80108758 2CFA030C */  jal        vs_mainMenu_rebuildInventory
    /* 5F5C 8010875C 2B0070A2 */   sb        $s0, 0x2B($s3)
    /* 5F60 80108760 1180023C */  lui        $v0, %hi(D_8010BC62)
    /* 5F64 80108764 62BC4290 */  lbu        $v0, %lo(D_8010BC62)($v0)
    /* 5F68 80108768 00000000 */  nop
    /* 5F6C 8010876C 06004238 */  xori       $v0, $v0, 0x6
    /* 5F70 80108770 EF210408 */  j          .L801087BC
    /* 5F74 80108774 2B100200 */   sltu      $v0, $zero, $v0
  .L80108778:
    /* 5F78 80108778 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 5F7C 8010877C 00000000 */   nop
    /* 5F80 80108780 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 5F84 80108784 01000424 */   addiu     $a0, $zero, 0x1
    /* 5F88 80108788 1180023C */  lui        $v0, %hi(D_8010BC62)
    /* 5F8C 8010878C EE210408 */  j          .L801087B8
    /* 5F90 80108790 62BC50A0 */   sb        $s0, %lo(D_8010BC62)($v0)
  .L80108794:
    /* 5F94 80108794 E00C040C */  jal        func_80103380
    /* 5F98 80108798 01000424 */   addiu     $a0, $zero, 0x1
    /* 5F9C 8010879C EF210408 */  j          .L801087BC
    /* 5FA0 801087A0 00000000 */   nop
    /* 5FA4 801087A4 962E040C */  jal        func_8010BA58
    /* 5FA8 801087A8 21200000 */   addu      $a0, $zero, $zero
    /* 5FAC 801087AC 21184000 */  addu       $v1, $v0, $zero
    /* 5FB0 801087B0 02006010 */  beqz       $v1, .L801087BC
    /* 5FB4 801087B4 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L801087B8:
    /* 5FB8 801087B8 21100000 */  addu       $v0, $zero, $zero
  .L801087BC:
    /* 5FBC 801087BC 4400BF8F */  lw         $ra, 0x44($sp)
    /* 5FC0 801087C0 4000B68F */  lw         $s6, 0x40($sp)
    /* 5FC4 801087C4 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 5FC8 801087C8 3800B48F */  lw         $s4, 0x38($sp)
    /* 5FCC 801087CC 3400B38F */  lw         $s3, 0x34($sp)
    /* 5FD0 801087D0 3000B28F */  lw         $s2, 0x30($sp)
    /* 5FD4 801087D4 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 5FD8 801087D8 2800B08F */  lw         $s0, 0x28($sp)
    /* 5FDC 801087DC 0800E003 */  jr         $ra
    /* 5FE0 801087E0 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_80107F14
