nonmatching func_80103684, 0xC2C

glabel func_80103684
    /* E84 80103684 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* E88 80103688 21200000 */  addu       $a0, $zero, $zero
    /* E8C 8010368C 21288000 */  addu       $a1, $a0, $zero
    /* E90 80103690 21308000 */  addu       $a2, $a0, $zero
    /* E94 80103694 3400BFAF */  sw         $ra, 0x34($sp)
    /* E98 80103698 3000B4AF */  sw         $s4, 0x30($sp)
    /* E9C 8010369C 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* EA0 801036A0 2800B2AF */  sw         $s2, 0x28($sp)
    /* EA4 801036A4 2400B1AF */  sw         $s1, 0x24($sp)
    /* EA8 801036A8 5605010C */  jal        SetFarColor
    /* EAC 801036AC 2000B0AF */   sw        $s0, 0x20($sp)
    /* EB0 801036B0 1180033C */  lui        $v1, %hi(D_80108E48)
    /* EB4 801036B4 BC000224 */  addiu      $v0, $zero, 0xBC
    /* EB8 801036B8 488E62AC */  sw         $v0, %lo(D_80108E48)($v1)
    /* EBC 801036BC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* EC0 801036C0 1180033C */  lui        $v1, %hi(_currentRoomIndex)
    /* EC4 801036C4 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* EC8 801036C8 648D738C */  lw         $s3, %lo(_currentRoomIndex)($v1)
    /* ECC 801036CC 00014230 */  andi       $v0, $v0, 0x100
    /* ED0 801036D0 05004010 */  beqz       $v0, .L801036E8
    /* ED4 801036D4 1180033C */   lui       $v1, %hi(D_80108D8C)
    /* ED8 801036D8 8C8D628C */  lw         $v0, %lo(D_80108D8C)($v1)
    /* EDC 801036DC 00000000 */  nop
    /* EE0 801036E0 01004238 */  xori       $v0, $v0, 0x1
    /* EE4 801036E4 8C8D62AC */  sw         $v0, %lo(D_80108D8C)($v1)
  .L801036E8:
    /* EE8 801036E8 0680033C */  lui        $v1, %hi(vs_main_stateFlags)
    /* EEC 801036EC 1180023C */  lui        $v0, %hi(_currentScene)
    /* EF0 801036F0 808D428C */  lw         $v0, %lo(_currentScene)($v0)
    /* EF4 801036F4 98156324 */  addiu      $v1, $v1, %lo(vs_main_stateFlags)
    /* EF8 801036F8 21104300 */  addu       $v0, $v0, $v1
    /* EFC 801036FC 35014290 */  lbu        $v0, 0x135($v0)
    /* F00 80103700 00000000 */  nop
    /* F04 80103704 03004010 */  beqz       $v0, .L80103714
    /* F08 80103708 FE070424 */   addiu     $a0, $zero, 0x7FE
    /* F0C 8010370C CC0D0408 */  j          .L80103730
    /* F10 80103710 80000524 */   addiu     $a1, $zero, 0x80
  .L80103714:
    /* F14 80103714 1180023C */  lui        $v0, %hi(D_80108D68)
    /* F18 80103718 688D458C */  lw         $a1, %lo(D_80108D68)($v0)
    /* F1C 8010371C 00000000 */  nop
    /* F20 80103720 8000A524 */  addiu      $a1, $a1, 0x80
    /* F24 80103724 C2170500 */  srl        $v0, $a1, 31
    /* F28 80103728 2128A200 */  addu       $a1, $a1, $v0
    /* F2C 8010372C 43280500 */  sra        $a1, $a1, 1
  .L80103730:
    /* F30 80103730 0501040C */  jal        func_80100414
    /* F34 80103734 00000000 */   nop
    /* F38 80103738 1180023C */  lui        $v0, %hi(D_80108D60)
    /* F3C 8010373C 608D448C */  lw         $a0, %lo(D_80108D60)($v0)
    /* F40 80103740 01000224 */  addiu      $v0, $zero, 0x1
    /* F44 80103744 03008210 */  beq        $a0, $v0, .L80103754
    /* F48 80103748 1180033C */   lui       $v1, %hi(D_80108D9C)
    /* F4C 8010374C 05000224 */  addiu      $v0, $zero, 0x5
    /* F50 80103750 9C8D62A4 */  sh         $v0, %lo(D_80108D9C)($v1)
  .L80103754:
    /* F54 80103754 0600822C */  sltiu      $v0, $a0, 0x6
    /* F58 80103758 C5024010 */  beqz       $v0, .L80104270
    /* F5C 8010375C 1080023C */   lui       $v0, %hi(jtbl_80102C60)
    /* F60 80103760 602C4224 */  addiu      $v0, $v0, %lo(jtbl_80102C60)
    /* F64 80103764 80180400 */  sll        $v1, $a0, 2
    /* F68 80103768 21186200 */  addu       $v1, $v1, $v0
    /* F6C 8010376C 0000628C */  lw         $v0, 0x0($v1)
    /* F70 80103770 00000000 */  nop
    /* F74 80103774 08004000 */  jr         $v0
    /* F78 80103778 00000000 */   nop
    /* F7C 8010377C 1180053C */  lui        $a1, %hi(D_80108D68)
    /* F80 80103780 688DA48C */  lw         $a0, %lo(D_80108D68)($a1)
    /* F84 80103784 00000000 */  nop
    /* F88 80103788 21008228 */  slti       $v0, $a0, 0x21
    /* F8C 8010378C 05004014 */  bnez       $v0, .L801037A4
    /* F90 80103790 3C000624 */   addiu     $a2, $zero, 0x3C
    /* F94 80103794 1180023C */  lui        $v0, %hi(_geomOffsetX)
    /* F98 80103798 708D438C */  lw         $v1, %lo(_geomOffsetX)($v0)
    /* F9C 8010379C 49100408 */  j          .L80104124
    /* FA0 801037A0 F0FF8424 */   addiu     $a0, $a0, -0x10
  .L801037A4:
    /* FA4 801037A4 21200000 */  addu       $a0, $zero, $zero
    /* FA8 801037A8 21288000 */  addu       $a1, $a0, $zero
    /* FAC 801037AC 10000224 */  addiu      $v0, $zero, 0x10
    /* FB0 801037B0 1000A2AF */  sw         $v0, 0x10($sp)
    /* FB4 801037B4 01000224 */  addiu      $v0, $zero, 0x1
    /* FB8 801037B8 1400A2AF */  sw         $v0, 0x14($sp)
    /* FBC 801037BC 2110C000 */  addu       $v0, $a2, $zero
    /* FC0 801037C0 1800A2AF */  sw         $v0, 0x18($sp)
    /* FC4 801037C4 E0000224 */  addiu      $v0, $zero, 0xE0
    /* FC8 801037C8 21384000 */  addu       $a3, $v0, $zero
    /* FCC 801037CC C233030C */  jal        vs_battle_initTextBox
    /* FD0 801037D0 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* FD4 801037D4 21200000 */  addu       $a0, $zero, $zero
    /* FD8 801037D8 1180023C */  lui        $v0, %hi(_currentRoomIndex)
    /* FDC 801037DC 648D428C */  lw         $v0, %lo(_currentRoomIndex)($v0)
    /* FE0 801037E0 1180033C */  lui        $v1, %hi(_roomNamesTable)
    /* FE4 801037E4 C0280200 */  sll        $a1, $v0, 3
    /* FE8 801037E8 2128A200 */  addu       $a1, $a1, $v0
    /* FEC 801037EC 988D628C */  lw         $v0, %lo(_roomNamesTable)($v1)
    /* FF0 801037F0 80280500 */  sll        $a1, $a1, 2
    /* FF4 801037F4 FC1A030C */  jal        vs_battle_setTextBox
    /* FF8 801037F8 21284500 */   addu      $a1, $v0, $a1
    /* FFC 801037FC 1180033C */  lui        $v1, %hi(D_80108D60)
    /* 1000 80103800 608D628C */  lw         $v0, %lo(D_80108D60)($v1)
    /* 1004 80103804 99100408 */  j          .L80104264
    /* 1008 80103808 01004224 */   addiu     $v0, $v0, 0x1
    /* 100C 8010380C 1180023C */  lui        $v0, %hi(D_80108D8C)
    /* 1010 80103810 1180103C */  lui        $s0, %hi(D_80108D94)
    /* 1014 80103814 8C8D448C */  lw         $a0, %lo(D_80108D8C)($v0)
    /* 1018 80103818 948D028E */  lw         $v0, %lo(D_80108D94)($s0)
    /* 101C 8010381C 00000000 */  nop
    /* 1020 80103820 04008210 */  beq        $a0, $v0, .L80103834
    /* 1024 80103824 21900000 */   addu      $s2, $zero, $zero
    /* 1028 80103828 948D04AE */  sw         $a0, %lo(D_80108D94)($s0)
    /* 102C 8010382C 360B040C */  jal        func_80102CD8
    /* 1030 80103830 0100842C */   sltiu     $a0, $a0, 0x1
  .L80103834:
    /* 1034 80103834 0680113C */  lui        $s1, %hi(vs_main_buttonsPressed)
    /* 1038 80103838 D0E1238E */  lw         $v1, %lo(vs_main_buttonsPressed)($s1)
    /* 103C 8010383C 00000000 */  nop
    /* 1040 80103840 20006230 */  andi       $v0, $v1, 0x20
    /* 1044 80103844 10004010 */  beqz       $v0, .L80103888
    /* 1048 80103848 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 104C 8010384C 05001224 */  addiu      $s2, $zero, 0x5
    /* 1050 80103850 6216010C */  jal        vs_main_playSfxDefault
    /* 1054 80103854 21284002 */   addu      $a1, $s2, $zero
    /* 1058 80103858 1180023C */  lui        $v0, %hi(D_80108D60)
    /* 105C 8010385C 948D048E */  lw         $a0, %lo(D_80108D94)($s0)
    /* 1060 80103860 02000324 */  addiu      $v1, $zero, 0x2
    /* 1064 80103864 04008010 */  beqz       $a0, .L80103878
    /* 1068 80103868 608D43AC */   sw        $v1, %lo(D_80108D60)($v0)
    /* 106C 8010386C 948D00AE */  sw         $zero, %lo(D_80108D94)($s0)
    /* 1070 80103870 360B040C */  jal        func_80102CD8
    /* 1074 80103874 01000424 */   addiu     $a0, $zero, 0x1
  .L80103878:
    /* 1078 80103878 4711040C */  jal        func_8010451C
    /* 107C 8010387C 01000424 */   addiu     $a0, $zero, 0x1
    /* 1080 80103880 E70F0408 */  j          .L80103F9C
    /* 1084 80103884 1180023C */   lui       $v0, %hi(D_80108D9C)
  .L80103888:
    /* 1088 80103888 50006230 */  andi       $v0, $v1, 0x50
    /* 108C 8010388C 11004010 */  beqz       $v0, .L801038D4
    /* 1090 80103890 0680033C */   lui       $v1, %hi(vs_main_stateFlags)
    /* 1094 80103894 6216010C */  jal        vs_main_playSfxDefault
    /* 1098 80103898 06000524 */   addiu     $a1, $zero, 0x6
    /* 109C 8010389C D0E1228E */  lw         $v0, %lo(vs_main_buttonsPressed)($s1)
    /* 10A0 801038A0 00000000 */  nop
    /* 10A4 801038A4 10004230 */  andi       $v0, $v0, 0x10
    /* 10A8 801038A8 03004010 */  beqz       $v0, .L801038B8
    /* 10AC 801038AC 1180033C */   lui       $v1, %hi(D_80108E44)
    /* 10B0 801038B0 02000224 */  addiu      $v0, $zero, 0x2
    /* 10B4 801038B4 448E62AC */  sw         $v0, %lo(D_80108E44)($v1)
  .L801038B8:
    /* 10B8 801038B8 1180033C */  lui        $v1, %hi(D_80108D60)
    /* 10BC 801038BC 03000224 */  addiu      $v0, $zero, 0x3
    /* 10C0 801038C0 608D62AC */  sw         $v0, %lo(D_80108D60)($v1)
    /* 10C4 801038C4 1934030C */  jal        vs_battle_dismissTextBox
    /* 10C8 801038C8 21200000 */   addu      $a0, $zero, $zero
    /* 10CC 801038CC E70F0408 */  j          .L80103F9C
    /* 10D0 801038D0 1180023C */   lui       $v0, %hi(D_80108D9C)
  .L801038D4:
    /* 10D4 801038D4 1180023C */  lui        $v0, %hi(_currentScene)
    /* 10D8 801038D8 808D428C */  lw         $v0, %lo(_currentScene)($v0)
    /* 10DC 801038DC 98156324 */  addiu      $v1, $v1, %lo(vs_main_stateFlags)
    /* 10E0 801038E0 21104300 */  addu       $v0, $v0, $v1
    /* 10E4 801038E4 35014290 */  lbu        $v0, 0x135($v0)
    /* 10E8 801038E8 00000000 */  nop
    /* 10EC 801038EC 03004010 */  beqz       $v0, .L801038FC
    /* 10F0 801038F0 0680023C */   lui       $v0, %hi(vs_main_stickPosBuf)
    /* 10F4 801038F4 E60F0408 */  j          .L80103F98
    /* 10F8 801038F8 05001224 */   addiu     $s2, $zero, 0x5
  .L801038FC:
    /* 10FC 801038FC C0DF438C */  lw         $v1, %lo(vs_main_stickPosBuf)($v0)
    /* 1100 80103900 C0DF4524 */  addiu      $a1, $v0, %lo(vs_main_stickPosBuf)
    /* 1104 80103904 80FF6324 */  addiu      $v1, $v1, -0x80
    /* 1108 80103908 02006104 */  bgez       $v1, .L80103914
    /* 110C 8010390C 21106000 */   addu      $v0, $v1, $zero
    /* 1110 80103910 23100200 */  negu       $v0, $v0
  .L80103914:
    /* 1114 80103914 41004228 */  slti       $v0, $v0, 0x41
    /* 1118 80103918 0B004010 */  beqz       $v0, .L80103948
    /* 111C 8010391C C0FF6228 */   slti      $v0, $v1, -0x40
    /* 1120 80103920 0400A28C */  lw         $v0, 0x4($a1)
    /* 1124 80103924 00000000 */  nop
    /* 1128 80103928 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 112C 8010392C 02004104 */  bgez       $v0, .L80103938
    /* 1130 80103930 00000000 */   nop
    /* 1134 80103934 23100200 */  negu       $v0, $v0
  .L80103938:
    /* 1138 80103938 41004228 */  slti       $v0, $v0, 0x41
    /* 113C 8010393C 2B004014 */  bnez       $v0, .L801039EC
    /* 1140 80103940 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* 1144 80103944 C0FF6228 */  slti       $v0, $v1, -0x40
  .L80103948:
    /* 1148 80103948 06004010 */  beqz       $v0, .L80103964
    /* 114C 8010394C 03001224 */   addiu     $s2, $zero, 0x3
    /* 1150 80103950 1180033C */  lui        $v1, %hi(D_80108DA4)
    /* 1154 80103954 A48D6324 */  addiu      $v1, $v1, %lo(D_80108DA4)
    /* 1158 80103958 02006294 */  lhu        $v0, 0x2($v1)
    /* 115C 8010395C 610E0408 */  j          .L80103984
    /* 1160 80103960 C0FF4224 */   addiu     $v0, $v0, -0x40
  .L80103964:
    /* 1164 80103964 41006228 */  slti       $v0, $v1, 0x41
    /* 1168 80103968 08004014 */  bnez       $v0, .L8010398C
    /* 116C 8010396C 0680023C */   lui       $v0, %hi(D_8005DFC4)
    /* 1170 80103970 1180033C */  lui        $v1, %hi(D_80108DA4)
    /* 1174 80103974 A48D6324 */  addiu      $v1, $v1, %lo(D_80108DA4)
    /* 1178 80103978 02006294 */  lhu        $v0, 0x2($v1)
    /* 117C 8010397C 00000000 */  nop
    /* 1180 80103980 40004224 */  addiu      $v0, $v0, 0x40
  .L80103984:
    /* 1184 80103984 020062A4 */  sh         $v0, 0x2($v1)
    /* 1188 80103988 0680023C */  lui        $v0, %hi(D_8005DFC4)
  .L8010398C:
    /* 118C 8010398C C4DF428C */  lw         $v0, %lo(D_8005DFC4)($v0)
    /* 1190 80103990 00000000 */  nop
    /* 1194 80103994 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 1198 80103998 C0FF6228 */  slti       $v0, $v1, -0x40
    /* 119C 8010399C 05004010 */  beqz       $v0, .L801039B4
    /* 11A0 801039A0 00000000 */   nop
    /* 11A4 801039A4 1180033C */  lui        $v1, %hi(D_80108DA4)
    /* 11A8 801039A8 A48D6294 */  lhu        $v0, %lo(D_80108DA4)($v1)
    /* 11AC 801039AC 730E0408 */  j          .L801039CC
    /* 11B0 801039B0 40004224 */   addiu     $v0, $v0, 0x40
  .L801039B4:
    /* 11B4 801039B4 41006228 */  slti       $v0, $v1, 0x41
    /* 11B8 801039B8 06004014 */  bnez       $v0, .L801039D4
    /* 11BC 801039BC 1180033C */   lui       $v1, %hi(D_80108DA4)
    /* 11C0 801039C0 A48D6294 */  lhu        $v0, %lo(D_80108DA4)($v1)
    /* 11C4 801039C4 00000000 */  nop
    /* 11C8 801039C8 C0FF4224 */  addiu      $v0, $v0, -0x40
  .L801039CC:
    /* 11CC 801039CC A48D62A4 */  sh         $v0, %lo(D_80108DA4)($v1)
    /* 11D0 801039D0 1180033C */  lui        $v1, %hi(D_80108DA4)
  .L801039D4:
    /* 11D4 801039D4 A48D6284 */  lh         $v0, %lo(D_80108DA4)($v1)
    /* 11D8 801039D8 00000000 */  nop
    /* 11DC 801039DC 42004004 */  bltz       $v0, .L80103AE8
    /* 11E0 801039E0 01044228 */   slti      $v0, $v0, 0x401
    /* 11E4 801039E4 BC0E0408 */  j          .L80103AF0
    /* 11E8 801039E8 00000000 */   nop
  .L801039EC:
    /* 11EC 801039EC C0E1448C */  lw         $a0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 11F0 801039F0 00000000 */  nop
    /* 11F4 801039F4 01008230 */  andi       $v0, $a0, 0x1
    /* 11F8 801039F8 68004010 */  beqz       $v0, .L80103B9C
    /* 11FC 801039FC 02008230 */   andi      $v0, $a0, 0x2
    /* 1200 80103A00 0800A28C */  lw         $v0, 0x8($a1)
    /* 1204 80103A04 00000000 */  nop
    /* 1208 80103A08 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 120C 80103A0C 02006104 */  bgez       $v1, .L80103A18
    /* 1210 80103A10 21106000 */   addu      $v0, $v1, $zero
    /* 1214 80103A14 23100200 */  negu       $v0, $v0
  .L80103A18:
    /* 1218 80103A18 41004228 */  slti       $v0, $v0, 0x41
    /* 121C 80103A1C 0A004010 */  beqz       $v0, .L80103A48
    /* 1220 80103A20 03001224 */   addiu     $s2, $zero, 0x3
    /* 1224 80103A24 0C00A28C */  lw         $v0, 0xC($a1)
    /* 1228 80103A28 00000000 */  nop
    /* 122C 80103A2C 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 1230 80103A30 02004104 */  bgez       $v0, .L80103A3C
    /* 1234 80103A34 00000000 */   nop
    /* 1238 80103A38 23100200 */  negu       $v0, $v0
  .L80103A3C:
    /* 123C 80103A3C 41004228 */  slti       $v0, $v0, 0x41
    /* 1240 80103A40 30004014 */  bnez       $v0, .L80103B04
    /* 1244 80103A44 00808230 */   andi      $v0, $a0, 0x8000
  .L80103A48:
    /* 1248 80103A48 C0FF6228 */  slti       $v0, $v1, -0x40
    /* 124C 80103A4C 06004010 */  beqz       $v0, .L80103A68
    /* 1250 80103A50 00000000 */   nop
    /* 1254 80103A54 1180033C */  lui        $v1, %hi(D_80108DA4)
    /* 1258 80103A58 A48D6324 */  addiu      $v1, $v1, %lo(D_80108DA4)
    /* 125C 80103A5C 02006294 */  lhu        $v0, 0x2($v1)
    /* 1260 80103A60 A20E0408 */  j          .L80103A88
    /* 1264 80103A64 C0FF4224 */   addiu     $v0, $v0, -0x40
  .L80103A68:
    /* 1268 80103A68 41006228 */  slti       $v0, $v1, 0x41
    /* 126C 80103A6C 08004014 */  bnez       $v0, .L80103A90
    /* 1270 80103A70 0680023C */   lui       $v0, %hi(D_8005DFCC)
    /* 1274 80103A74 1180033C */  lui        $v1, %hi(D_80108DA4)
    /* 1278 80103A78 A48D6324 */  addiu      $v1, $v1, %lo(D_80108DA4)
    /* 127C 80103A7C 02006294 */  lhu        $v0, 0x2($v1)
    /* 1280 80103A80 00000000 */  nop
    /* 1284 80103A84 40004224 */  addiu      $v0, $v0, 0x40
  .L80103A88:
    /* 1288 80103A88 020062A4 */  sh         $v0, 0x2($v1)
    /* 128C 80103A8C 0680023C */  lui        $v0, %hi(D_8005DFCC)
  .L80103A90:
    /* 1290 80103A90 CCDF428C */  lw         $v0, %lo(D_8005DFCC)($v0)
    /* 1294 80103A94 00000000 */  nop
    /* 1298 80103A98 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 129C 80103A9C C0FF6228 */  slti       $v0, $v1, -0x40
    /* 12A0 80103AA0 05004010 */  beqz       $v0, .L80103AB8
    /* 12A4 80103AA4 00000000 */   nop
    /* 12A8 80103AA8 1180033C */  lui        $v1, %hi(D_80108DA4)
    /* 12AC 80103AAC A48D6294 */  lhu        $v0, %lo(D_80108DA4)($v1)
    /* 12B0 80103AB0 B40E0408 */  j          .L80103AD0
    /* 12B4 80103AB4 40004224 */   addiu     $v0, $v0, 0x40
  .L80103AB8:
    /* 12B8 80103AB8 41006228 */  slti       $v0, $v1, 0x41
    /* 12BC 80103ABC 06004014 */  bnez       $v0, .L80103AD8
    /* 12C0 80103AC0 1180033C */   lui       $v1, %hi(D_80108DA4)
    /* 12C4 80103AC4 A48D6294 */  lhu        $v0, %lo(D_80108DA4)($v1)
    /* 12C8 80103AC8 00000000 */  nop
    /* 12CC 80103ACC C0FF4224 */  addiu      $v0, $v0, -0x40
  .L80103AD0:
    /* 12D0 80103AD0 A48D62A4 */  sh         $v0, %lo(D_80108DA4)($v1)
    /* 12D4 80103AD4 1180033C */  lui        $v1, %hi(D_80108DA4)
  .L80103AD8:
    /* 12D8 80103AD8 A48D6284 */  lh         $v0, %lo(D_80108DA4)($v1)
    /* 12DC 80103ADC 00000000 */  nop
    /* 12E0 80103AE0 03004104 */  bgez       $v0, .L80103AF0
    /* 12E4 80103AE4 01044228 */   slti      $v0, $v0, 0x401
  .L80103AE8:
    /* 12E8 80103AE8 E60F0408 */  j          .L80103F98
    /* 12EC 80103AEC A48D60A4 */   sh        $zero, %lo(D_80108DA4)($v1)
  .L80103AF0:
    /* 12F0 80103AF0 2A014014 */  bnez       $v0, .L80103F9C
    /* 12F4 80103AF4 1180023C */   lui       $v0, %hi(D_80108D9C)
    /* 12F8 80103AF8 00040224 */  addiu      $v0, $zero, 0x400
    /* 12FC 80103AFC E60F0408 */  j          .L80103F98
    /* 1300 80103B00 A48D62A4 */   sh        $v0, %lo(D_80108DA4)($v1)
  .L80103B04:
    /* 1304 80103B04 05004010 */  beqz       $v0, .L80103B1C
    /* 1308 80103B08 1180033C */   lui       $v1, %hi(D_80108DA4)
    /* 130C 80103B0C A48D6324 */  addiu      $v1, $v1, %lo(D_80108DA4)
    /* 1310 80103B10 02006294 */  lhu        $v0, 0x2($v1)
    /* 1314 80103B14 CD0E0408 */  j          .L80103B34
    /* 1318 80103B18 C0FF4224 */   addiu     $v0, $v0, -0x40
  .L80103B1C:
    /* 131C 80103B1C 00208230 */  andi       $v0, $a0, 0x2000
    /* 1320 80103B20 05004010 */  beqz       $v0, .L80103B38
    /* 1324 80103B24 A48D6324 */   addiu     $v1, $v1, %lo(D_80108DA4)
    /* 1328 80103B28 02006294 */  lhu        $v0, 0x2($v1)
    /* 132C 80103B2C 00000000 */  nop
    /* 1330 80103B30 40004224 */  addiu      $v0, $v0, 0x40
  .L80103B34:
    /* 1334 80103B34 020062A4 */  sh         $v0, 0x2($v1)
  .L80103B38:
    /* 1338 80103B38 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 133C 80103B3C C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 1340 80103B40 00000000 */  nop
    /* 1344 80103B44 00404230 */  andi       $v0, $v0, 0x4000
    /* 1348 80103B48 07004010 */  beqz       $v0, .L80103B68
    /* 134C 80103B4C 1180043C */   lui       $a0, %hi(D_80108DA4)
    /* 1350 80103B50 A48D8284 */  lh         $v0, %lo(D_80108DA4)($a0)
    /* 1354 80103B54 A48D8394 */  lhu        $v1, %lo(D_80108DA4)($a0)
    /* 1358 80103B58 03004018 */  blez       $v0, .L80103B68
    /* 135C 80103B5C C0FF6224 */   addiu     $v0, $v1, -0x40
    /* 1360 80103B60 E60F0408 */  j          .L80103F98
    /* 1364 80103B64 A48D82A4 */   sh        $v0, %lo(D_80108DA4)($a0)
  .L80103B68:
    /* 1368 80103B68 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 136C 80103B6C C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 1370 80103B70 00000000 */  nop
    /* 1374 80103B74 00104230 */  andi       $v0, $v0, 0x1000
    /* 1378 80103B78 07014010 */  beqz       $v0, .L80103F98
    /* 137C 80103B7C 1180043C */   lui       $a0, %hi(D_80108DA4)
    /* 1380 80103B80 A48D8284 */  lh         $v0, %lo(D_80108DA4)($a0)
    /* 1384 80103B84 A48D8394 */  lhu        $v1, %lo(D_80108DA4)($a0)
    /* 1388 80103B88 00044228 */  slti       $v0, $v0, 0x400
    /* 138C 80103B8C 02014010 */  beqz       $v0, .L80103F98
    /* 1390 80103B90 40006224 */   addiu     $v0, $v1, 0x40
    /* 1394 80103B94 E60F0408 */  j          .L80103F98
    /* 1398 80103B98 A48D82A4 */   sh        $v0, %lo(D_80108DA4)($a0)
  .L80103B9C:
    /* 139C 80103B9C 4A004010 */  beqz       $v0, .L80103CC8
    /* 13A0 80103BA0 00088230 */   andi      $v0, $a0, 0x800
    /* 13A4 80103BA4 0800A28C */  lw         $v0, 0x8($a1)
    /* 13A8 80103BA8 00000000 */  nop
    /* 13AC 80103BAC 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 13B0 80103BB0 02004104 */  bgez       $v0, .L80103BBC
    /* 13B4 80103BB4 00000000 */   nop
    /* 13B8 80103BB8 23100200 */  negu       $v0, $v0
  .L80103BBC:
    /* 13BC 80103BBC 41004228 */  slti       $v0, $v0, 0x41
    /* 13C0 80103BC0 0A004010 */  beqz       $v0, .L80103BEC
    /* 13C4 80103BC4 02001224 */   addiu     $s2, $zero, 0x2
    /* 13C8 80103BC8 0C00A28C */  lw         $v0, 0xC($a1)
    /* 13CC 80103BCC 00000000 */  nop
    /* 13D0 80103BD0 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 13D4 80103BD4 02004104 */  bgez       $v0, .L80103BE0
    /* 13D8 80103BD8 00000000 */   nop
    /* 13DC 80103BDC 23100200 */  negu       $v0, $v0
  .L80103BE0:
    /* 13E0 80103BE0 41004228 */  slti       $v0, $v0, 0x41
    /* 13E4 80103BE4 21004014 */  bnez       $v0, .L80103C6C
    /* 13E8 80103BE8 00108230 */   andi      $v0, $a0, 0x1000
  .L80103BEC:
    /* 13EC 80103BEC 0C00A28C */  lw         $v0, 0xC($a1)
    /* 13F0 80103BF0 00000000 */  nop
    /* 13F4 80103BF4 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 13F8 80103BF8 C0FF6228 */  slti       $v0, $v1, -0x40
    /* 13FC 80103BFC 05004010 */  beqz       $v0, .L80103C14
    /* 1400 80103C00 00000000 */   nop
    /* 1404 80103C04 1180033C */  lui        $v1, %hi(D_80108D7C)
    /* 1408 80103C08 7C8D628C */  lw         $v0, %lo(D_80108D7C)($v1)
    /* 140C 80103C0C 0C0F0408 */  j          .L80103C30
    /* 1410 80103C10 F0FF4224 */   addiu     $v0, $v0, -0x10
  .L80103C14:
    /* 1414 80103C14 41006228 */  slti       $v0, $v1, 0x41
    /* 1418 80103C18 07004014 */  bnez       $v0, .L80103C38
    /* 141C 80103C1C 1180043C */   lui       $a0, %hi(D_80108D7C)
    /* 1420 80103C20 1180033C */  lui        $v1, %hi(D_80108D7C)
    /* 1424 80103C24 7C8D628C */  lw         $v0, %lo(D_80108D7C)($v1)
    /* 1428 80103C28 00000000 */  nop
    /* 142C 80103C2C 10004224 */  addiu      $v0, $v0, 0x10
  .L80103C30:
    /* 1430 80103C30 7C8D62AC */  sw         $v0, %lo(D_80108D7C)($v1)
    /* 1434 80103C34 1180043C */  lui        $a0, %hi(D_80108D7C)
  .L80103C38:
    /* 1438 80103C38 7C8D838C */  lw         $v1, %lo(D_80108D7C)($a0)
    /* 143C 80103C3C 00000000 */  nop
    /* 1440 80103C40 00026228 */  slti       $v0, $v1, 0x200
    /* 1444 80103C44 03004010 */  beqz       $v0, .L80103C54
    /* 1448 80103C48 00020224 */   addiu     $v0, $zero, 0x200
    /* 144C 80103C4C E60F0408 */  j          .L80103F98
    /* 1450 80103C50 7C8D82AC */   sw        $v0, %lo(D_80108D7C)($a0)
  .L80103C54:
    /* 1454 80103C54 01046228 */  slti       $v0, $v1, 0x401
    /* 1458 80103C58 D0004014 */  bnez       $v0, .L80103F9C
    /* 145C 80103C5C 1180023C */   lui       $v0, %hi(D_80108D9C)
    /* 1460 80103C60 00040224 */  addiu      $v0, $zero, 0x400
    /* 1464 80103C64 E60F0408 */  j          .L80103F98
    /* 1468 80103C68 7C8D82AC */   sw        $v0, %lo(D_80108D7C)($a0)
  .L80103C6C:
    /* 146C 80103C6C 09004010 */  beqz       $v0, .L80103C94
    /* 1470 80103C70 1180043C */   lui       $a0, %hi(D_80108D7C)
    /* 1474 80103C74 7C8D838C */  lw         $v1, %lo(D_80108D7C)($a0)
    /* 1478 80103C78 00000000 */  nop
    /* 147C 80103C7C 01026228 */  slti       $v0, $v1, 0x201
    /* 1480 80103C80 05004014 */  bnez       $v0, .L80103C98
    /* 1484 80103C84 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* 1488 80103C88 F0FF6224 */  addiu      $v0, $v1, -0x10
    /* 148C 80103C8C E60F0408 */  j          .L80103F98
    /* 1490 80103C90 7C8D82AC */   sw        $v0, %lo(D_80108D7C)($a0)
  .L80103C94:
    /* 1494 80103C94 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
  .L80103C98:
    /* 1498 80103C98 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 149C 80103C9C 00000000 */  nop
    /* 14A0 80103CA0 00404230 */  andi       $v0, $v0, 0x4000
    /* 14A4 80103CA4 BC004010 */  beqz       $v0, .L80103F98
    /* 14A8 80103CA8 1180043C */   lui       $a0, %hi(D_80108D7C)
    /* 14AC 80103CAC 7C8D838C */  lw         $v1, %lo(D_80108D7C)($a0)
    /* 14B0 80103CB0 00000000 */  nop
    /* 14B4 80103CB4 00046228 */  slti       $v0, $v1, 0x400
    /* 14B8 80103CB8 B7004010 */  beqz       $v0, .L80103F98
    /* 14BC 80103CBC 10006224 */   addiu     $v0, $v1, 0x10
    /* 14C0 80103CC0 E60F0408 */  j          .L80103F98
    /* 14C4 80103CC4 7C8D82AC */   sw        $v0, %lo(D_80108D7C)($a0)
  .L80103CC8:
    /* 14C8 80103CC8 1A004010 */  beqz       $v0, .L80103D34
    /* 14CC 80103CCC 0F80103C */   lui       $s0, %hi(vs_battle_sceneBuffer)
    /* 14D0 80103CD0 1180023C */  lui        $v0, %hi(_geomOffsetX)
    /* 14D4 80103CD4 708D40AC */  sw         $zero, %lo(_geomOffsetX)($v0)
    /* 14D8 80103CD8 1180023C */  lui        $v0, %hi(_geomOffsetY)
    /* 14DC 80103CDC 1180033C */  lui        $v1, %hi(D_80108D7C)
    /* 14E0 80103CE0 748D40AC */  sw         $zero, %lo(_geomOffsetY)($v0)
    /* 14E4 80103CE4 00030224 */  addiu      $v0, $zero, 0x300
    /* 14E8 80103CE8 7C8D62AC */  sw         $v0, %lo(D_80108D7C)($v1)
    /* 14EC 80103CEC 1180033C */  lui        $v1, %hi(D_80108DA4)
    /* 14F0 80103CF0 38020224 */  addiu      $v0, $zero, 0x238
    /* 14F4 80103CF4 A48D62A4 */  sh         $v0, %lo(D_80108DA4)($v1)
    /* 14F8 80103CF8 A48D6324 */  addiu      $v1, $v1, %lo(D_80108DA4)
    /* 14FC 80103CFC 00080224 */  addiu      $v0, $zero, 0x800
    /* 1500 80103D00 801F053C */  lui        $a1, (0x1F800058 >> 16)
    /* 1504 80103D04 5800A594 */  lhu        $a1, (0x1F800058 & 0xFFFF)($a1)
    /* 1508 80103D08 C01B048E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s0)
    /* 150C 80103D0C 23104500 */  subu       $v0, $v0, $a1
    /* 1510 80103D10 5C19040C */  jal        _getCurrentRoomIndex
    /* 1514 80103D14 020062A4 */   sh        $v0, 0x2($v1)
    /* 1518 80103D18 21284000 */  addu       $a1, $v0, $zero
    /* 151C 80103D1C C01B048E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s0)
    /* 1520 80103D20 1180023C */  lui        $v0, %hi(_currentRoomIndex)
    /* 1524 80103D24 C616040C */  jal        _snapMapToRoom
    /* 1528 80103D28 648D45AC */   sw        $a1, %lo(_currentRoomIndex)($v0)
    /* 152C 80103D2C E70F0408 */  j          .L80103F9C
    /* 1530 80103D30 1180023C */   lui       $v0, %hi(D_80108D9C)
  .L80103D34:
    /* 1534 80103D34 0800A28C */  lw         $v0, 0x8($a1)
    /* 1538 80103D38 00000000 */  nop
    /* 153C 80103D3C 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 1540 80103D40 02006104 */  bgez       $v1, .L80103D4C
    /* 1544 80103D44 21106000 */   addu      $v0, $v1, $zero
    /* 1548 80103D48 23100200 */  negu       $v0, $v0
  .L80103D4C:
    /* 154C 80103D4C 41004228 */  slti       $v0, $v0, 0x41
    /* 1550 80103D50 0B004010 */  beqz       $v0, .L80103D80
    /* 1554 80103D54 C0FF6228 */   slti      $v0, $v1, -0x40
    /* 1558 80103D58 0C00A28C */  lw         $v0, 0xC($a1)
    /* 155C 80103D5C 00000000 */  nop
    /* 1560 80103D60 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 1564 80103D64 02004104 */  bgez       $v0, .L80103D70
    /* 1568 80103D68 00000000 */   nop
    /* 156C 80103D6C 23100200 */  negu       $v0, $v0
  .L80103D70:
    /* 1570 80103D70 41004228 */  slti       $v0, $v0, 0x41
    /* 1574 80103D74 38004014 */  bnez       $v0, .L80103E58
    /* 1578 80103D78 00108230 */   andi      $v0, $a0, 0x1000
    /* 157C 80103D7C C0FF6228 */  slti       $v0, $v1, -0x40
  .L80103D80:
    /* 1580 80103D80 05004010 */  beqz       $v0, .L80103D98
    /* 1584 80103D84 00000000 */   nop
    /* 1588 80103D88 1180033C */  lui        $v1, %hi(_geomOffsetX)
    /* 158C 80103D8C 708D628C */  lw         $v0, %lo(_geomOffsetX)($v1)
    /* 1590 80103D90 6D0F0408 */  j          .L80103DB4
    /* 1594 80103D94 FCFF4224 */   addiu     $v0, $v0, -0x4
  .L80103D98:
    /* 1598 80103D98 41006228 */  slti       $v0, $v1, 0x41
    /* 159C 80103D9C 07004014 */  bnez       $v0, .L80103DBC
    /* 15A0 80103DA0 0680023C */   lui       $v0, %hi(D_8005DFCC)
    /* 15A4 80103DA4 1180033C */  lui        $v1, %hi(_geomOffsetX)
    /* 15A8 80103DA8 708D628C */  lw         $v0, %lo(_geomOffsetX)($v1)
    /* 15AC 80103DAC 00000000 */  nop
    /* 15B0 80103DB0 04004224 */  addiu      $v0, $v0, 0x4
  .L80103DB4:
    /* 15B4 80103DB4 708D62AC */  sw         $v0, %lo(_geomOffsetX)($v1)
    /* 15B8 80103DB8 0680023C */  lui        $v0, %hi(D_8005DFCC)
  .L80103DBC:
    /* 15BC 80103DBC CCDF428C */  lw         $v0, %lo(D_8005DFCC)($v0)
    /* 15C0 80103DC0 00000000 */  nop
    /* 15C4 80103DC4 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 15C8 80103DC8 C0FF6228 */  slti       $v0, $v1, -0x40
    /* 15CC 80103DCC 05004010 */  beqz       $v0, .L80103DE4
    /* 15D0 80103DD0 00000000 */   nop
    /* 15D4 80103DD4 1180033C */  lui        $v1, %hi(_geomOffsetY)
    /* 15D8 80103DD8 748D628C */  lw         $v0, %lo(_geomOffsetY)($v1)
    /* 15DC 80103DDC 800F0408 */  j          .L80103E00
    /* 15E0 80103DE0 FCFF4224 */   addiu     $v0, $v0, -0x4
  .L80103DE4:
    /* 15E4 80103DE4 41006228 */  slti       $v0, $v1, 0x41
    /* 15E8 80103DE8 07004014 */  bnez       $v0, .L80103E08
    /* 15EC 80103DEC 1180043C */   lui       $a0, %hi(_geomOffsetY)
    /* 15F0 80103DF0 1180033C */  lui        $v1, %hi(_geomOffsetY)
    /* 15F4 80103DF4 748D628C */  lw         $v0, %lo(_geomOffsetY)($v1)
    /* 15F8 80103DF8 00000000 */  nop
    /* 15FC 80103DFC 04004224 */  addiu      $v0, $v0, 0x4
  .L80103E00:
    /* 1600 80103E00 748D62AC */  sw         $v0, %lo(_geomOffsetY)($v1)
    /* 1604 80103E04 1180043C */  lui        $a0, %hi(_geomOffsetY)
  .L80103E08:
    /* 1608 80103E08 748D838C */  lw         $v1, %lo(_geomOffsetY)($a0)
    /* 160C 80103E0C 00000000 */  nop
    /* 1610 80103E10 B0FF6228 */  slti       $v0, $v1, -0x50
    /* 1614 80103E14 04004014 */  bnez       $v0, .L80103E28
    /* 1618 80103E18 B0FF0224 */   addiu     $v0, $zero, -0x50
    /* 161C 80103E1C 51006228 */  slti       $v0, $v1, 0x51
    /* 1620 80103E20 02004014 */  bnez       $v0, .L80103E2C
    /* 1624 80103E24 50000224 */   addiu     $v0, $zero, 0x50
  .L80103E28:
    /* 1628 80103E28 748D82AC */  sw         $v0, %lo(_geomOffsetY)($a0)
  .L80103E2C:
    /* 162C 80103E2C 1180043C */  lui        $a0, %hi(_geomOffsetX)
    /* 1630 80103E30 708D838C */  lw         $v1, %lo(_geomOffsetX)($a0)
    /* 1634 80103E34 00000000 */  nop
    /* 1638 80103E38 A0FF6228 */  slti       $v0, $v1, -0x60
    /* 163C 80103E3C 33004014 */  bnez       $v0, .L80103F0C
    /* 1640 80103E40 A0FF0224 */   addiu     $v0, $zero, -0x60
    /* 1644 80103E44 61006228 */  slti       $v0, $v1, 0x61
    /* 1648 80103E48 32004014 */  bnez       $v0, .L80103F14
    /* 164C 80103E4C 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* 1650 80103E50 C30F0408 */  j          .L80103F0C
    /* 1654 80103E54 60000224 */   addiu     $v0, $zero, 0x60
  .L80103E58:
    /* 1658 80103E58 08004010 */  beqz       $v0, .L80103E7C
    /* 165C 80103E5C 1180043C */   lui       $a0, %hi(_geomOffsetY)
    /* 1660 80103E60 748D838C */  lw         $v1, %lo(_geomOffsetY)($a0)
    /* 1664 80103E64 00000000 */  nop
    /* 1668 80103E68 B1FF6228 */  slti       $v0, $v1, -0x4F
    /* 166C 80103E6C 04004014 */  bnez       $v0, .L80103E80
    /* 1670 80103E70 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* 1674 80103E74 AA0F0408 */  j          .L80103EA8
    /* 1678 80103E78 FCFF6224 */   addiu     $v0, $v1, -0x4
  .L80103E7C:
    /* 167C 80103E7C 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
  .L80103E80:
    /* 1680 80103E80 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 1684 80103E84 00000000 */  nop
    /* 1688 80103E88 00404230 */  andi       $v0, $v0, 0x4000
    /* 168C 80103E8C 07004010 */  beqz       $v0, .L80103EAC
    /* 1690 80103E90 1180043C */   lui       $a0, %hi(_geomOffsetY)
    /* 1694 80103E94 748D838C */  lw         $v1, %lo(_geomOffsetY)($a0)
    /* 1698 80103E98 00000000 */  nop
    /* 169C 80103E9C 50006228 */  slti       $v0, $v1, 0x50
    /* 16A0 80103EA0 02004010 */  beqz       $v0, .L80103EAC
    /* 16A4 80103EA4 04006224 */   addiu     $v0, $v1, 0x4
  .L80103EA8:
    /* 16A8 80103EA8 748D82AC */  sw         $v0, %lo(_geomOffsetY)($a0)
  .L80103EAC:
    /* 16AC 80103EAC 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 16B0 80103EB0 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 16B4 80103EB4 00000000 */  nop
    /* 16B8 80103EB8 00804230 */  andi       $v0, $v0, 0x8000
    /* 16BC 80103EBC 08004010 */  beqz       $v0, .L80103EE0
    /* 16C0 80103EC0 1180043C */   lui       $a0, %hi(_geomOffsetX)
    /* 16C4 80103EC4 708D838C */  lw         $v1, %lo(_geomOffsetX)($a0)
    /* 16C8 80103EC8 00000000 */  nop
    /* 16CC 80103ECC A1FF6228 */  slti       $v0, $v1, -0x5F
    /* 16D0 80103ED0 04004014 */  bnez       $v0, .L80103EE4
    /* 16D4 80103ED4 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* 16D8 80103ED8 C30F0408 */  j          .L80103F0C
    /* 16DC 80103EDC FCFF6224 */   addiu     $v0, $v1, -0x4
  .L80103EE0:
    /* 16E0 80103EE0 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
  .L80103EE4:
    /* 16E4 80103EE4 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 16E8 80103EE8 00000000 */  nop
    /* 16EC 80103EEC 00204230 */  andi       $v0, $v0, 0x2000
    /* 16F0 80103EF0 07004010 */  beqz       $v0, .L80103F10
    /* 16F4 80103EF4 1180043C */   lui       $a0, %hi(_geomOffsetX)
    /* 16F8 80103EF8 708D838C */  lw         $v1, %lo(_geomOffsetX)($a0)
    /* 16FC 80103EFC 00000000 */  nop
    /* 1700 80103F00 60006228 */  slti       $v0, $v1, 0x60
    /* 1704 80103F04 02004010 */  beqz       $v0, .L80103F10
    /* 1708 80103F08 04006224 */   addiu     $v0, $v1, 0x4
  .L80103F0C:
    /* 170C 80103F0C 708D82AC */  sw         $v0, %lo(_geomOffsetX)($a0)
  .L80103F10:
    /* 1710 80103F10 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
  .L80103F14:
    /* 1714 80103F14 C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 1718 80103F18 0C000324 */  addiu      $v1, $zero, 0xC
    /* 171C 80103F1C 0C004230 */  andi       $v0, $v0, 0xC
    /* 1720 80103F20 11004310 */  beq        $v0, $v1, .L80103F68
    /* 1724 80103F24 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 1728 80103F28 DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 172C 80103F2C 00000000 */  nop
    /* 1730 80103F30 08006230 */  andi       $v0, $v1, 0x8
    /* 1734 80103F34 04004014 */  bnez       $v0, .L80103F48
    /* 1738 80103F38 01000424 */   addiu     $a0, $zero, 0x1
    /* 173C 80103F3C 04006230 */  andi       $v0, $v1, 0x4
    /* 1740 80103F40 09004010 */  beqz       $v0, .L80103F68
    /* 1744 80103F44 FFFF0424 */   addiu     $a0, $zero, -0x1
  .L80103F48:
    /* 1748 80103F48 8619040C */  jal        _updateRoomIndex
    /* 174C 80103F4C 00000000 */   nop
    /* 1750 80103F50 0F80023C */  lui        $v0, %hi(vs_battle_sceneBuffer)
    /* 1754 80103F54 C01B448C */  lw         $a0, %lo(vs_battle_sceneBuffer)($v0)
    /* 1758 80103F58 1180023C */  lui        $v0, %hi(_currentRoomIndex)
    /* 175C 80103F5C 648D458C */  lw         $a1, %lo(_currentRoomIndex)($v0)
    /* 1760 80103F60 4F17040C */  jal        _setCenterpoint
    /* 1764 80103F64 00000000 */   nop
  .L80103F68:
    /* 1768 80103F68 1180023C */  lui        $v0, %hi(_currentRoomIndex)
    /* 176C 80103F6C 648D438C */  lw         $v1, %lo(_currentRoomIndex)($v0)
    /* 1770 80103F70 00000000 */  nop
    /* 1774 80103F74 08006312 */  beq        $s3, $v1, .L80103F98
    /* 1778 80103F78 21200000 */   addu      $a0, $zero, $zero
    /* 177C 80103F7C 1180023C */  lui        $v0, %hi(_roomNamesTable)
    /* 1780 80103F80 C0280300 */  sll        $a1, $v1, 3
    /* 1784 80103F84 2128A300 */  addu       $a1, $a1, $v1
    /* 1788 80103F88 988D428C */  lw         $v0, %lo(_roomNamesTable)($v0)
    /* 178C 80103F8C 80280500 */  sll        $a1, $a1, 2
    /* 1790 80103F90 FC1A030C */  jal        vs_battle_setTextBox
    /* 1794 80103F94 21284500 */   addu      $a1, $v0, $a1
  .L80103F98:
    /* 1798 80103F98 1180023C */  lui        $v0, %hi(D_80108D9C)
  .L80103F9C:
    /* 179C 80103F9C 9A100408 */  j          .L80104268
    /* 17A0 80103FA0 9C8D52A4 */   sh        $s2, %lo(D_80108D9C)($v0)
    /* 17A4 80103FA4 AC10040C */  jal        func_801042B0
    /* 17A8 80103FA8 00000000 */   nop
    /* 17AC 80103FAC 4711040C */  jal        func_8010451C
    /* 17B0 80103FB0 21200000 */   addu      $a0, $zero, $zero
    /* 17B4 80103FB4 1180033C */  lui        $v1, %hi(D_80108D84)
    /* 17B8 80103FB8 21204000 */  addu       $a0, $v0, $zero
    /* 17BC 80103FBC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 17C0 80103FC0 AB008210 */  beq        $a0, $v0, .L80104270
    /* 17C4 80103FC4 848D64AC */   sw        $a0, %lo(D_80108D84)($v1)
    /* 17C8 80103FC8 FDFF0224 */  addiu      $v0, $zero, -0x3
    /* 17CC 80103FCC 0B008214 */  bne        $a0, $v0, .L80103FFC
    /* 17D0 80103FD0 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 17D4 80103FD4 21200000 */  addu       $a0, $zero, $zero
    /* 17D8 80103FD8 1180033C */  lui        $v1, %hi(D_80108D60)
    /* 17DC 80103FDC 03000224 */  addiu      $v0, $zero, 0x3
    /* 17E0 80103FE0 608D62AC */  sw         $v0, %lo(D_80108D60)($v1)
    /* 17E4 80103FE4 1180033C */  lui        $v1, %hi(D_80108E44)
    /* 17E8 80103FE8 02000224 */  addiu      $v0, $zero, 0x2
    /* 17EC 80103FEC 1934030C */  jal        vs_battle_dismissTextBox
    /* 17F0 80103FF0 448E62AC */   sw        $v0, %lo(D_80108E44)($v1)
    /* 17F4 80103FF4 9D100408 */  j          .L80104274
    /* 17F8 80103FF8 1180053C */   lui       $a1, %hi(D_80108D6C)
  .L80103FFC:
    /* 17FC 80103FFC 14008214 */  bne        $a0, $v0, .L80104050
    /* 1800 80104000 1180023C */   lui       $v0, %hi(D_80108DC4)
    /* 1804 80104004 1180033C */  lui        $v1, %hi(D_80108D60)
    /* 1808 80104008 01000224 */  addiu      $v0, $zero, 0x1
    /* 180C 8010400C 1180063C */  lui        $a2, %hi(_mapNames)
    /* 1810 80104010 608D62AC */  sw         $v0, %lo(D_80108D60)($v1)
    /* 1814 80104014 1180023C */  lui        $v0, %hi(_currentScene)
    /* 1818 80104018 FC83C624 */  addiu      $a2, $a2, %lo(_mapNames)
    /* 181C 8010401C 808D458C */  lw         $a1, %lo(_currentScene)($v0)
    /* 1820 80104020 1180023C */  lui        $v0, %hi(D_80108D90)
    /* 1824 80104024 908D428C */  lw         $v0, %lo(D_80108D90)($v0)
    /* 1828 80104028 40180500 */  sll        $v1, $a1, 1
    /* 182C 8010402C 21186600 */  addu       $v1, $v1, $a2
    /* 1830 80104030 2628A200 */  xor        $a1, $a1, $v0
    /* 1834 80104034 00006494 */  lhu        $a0, 0x0($v1)
    /* 1838 80104038 0100A52C */  sltiu      $a1, $a1, 0x1
    /* 183C 8010403C 40200400 */  sll        $a0, $a0, 1
    /* 1840 80104040 CC0B040C */  jal        _setMenuItemMapName
    /* 1844 80104044 21208600 */   addu      $a0, $a0, $a2
    /* 1848 80104048 9D100408 */  j          .L80104274
    /* 184C 8010404C 1180053C */   lui       $a1, %hi(D_80108D6C)
  .L80104050:
    /* 1850 80104050 C48D4224 */  addiu      $v0, $v0, %lo(D_80108DC4)
    /* 1854 80104054 80180400 */  sll        $v1, $a0, 2
    /* 1858 80104058 21186200 */  addu       $v1, $v1, $v0
    /* 185C 8010405C 1080113C */  lui        $s1, %hi(_sceneArmFiles)
    /* 1860 80104060 002B3126 */  addiu      $s1, $s1, %lo(_sceneArmFiles)
    /* 1864 80104064 0000668C */  lw         $a2, 0x0($v1)
    /* 1868 80104068 0680033C */  lui        $v1, %hi(vs_main_stateFlags)
    /* 186C 8010406C 1180103C */  lui        $s0, %hi(_currentScene)
    /* 1870 80104070 C0100600 */  sll        $v0, $a2, 3
    /* 1874 80104074 21105100 */  addu       $v0, $v0, $s1
    /* 1878 80104078 0400448C */  lw         $a0, 0x4($v0)
    /* 187C 8010407C 808D028E */  lw         $v0, %lo(_currentScene)($s0)
    /* 1880 80104080 98156324 */  addiu      $v1, $v1, %lo(vs_main_stateFlags)
    /* 1884 80104084 21104300 */  addu       $v0, $v0, $v1
    /* 1888 80104088 1180033C */  lui        $v1, %hi(D_80108D60)
    /* 188C 8010408C 35014590 */  lbu        $a1, 0x135($v0)
    /* 1890 80104090 04000224 */  addiu      $v0, $zero, 0x4
    /* 1894 80104094 608D62AC */  sw         $v0, %lo(D_80108D60)($v1)
    /* 1898 80104098 1180023C */  lui        $v0, %hi(D_80108D88)
    /* 189C 8010409C 808D06AE */  sw         $a2, %lo(_currentScene)($s0)
    /* 18A0 801040A0 8F0F010C */  jal        vs_main_allocHeapR
    /* 18A4 801040A4 888D45AC */   sw        $a1, %lo(D_80108D88)($v0)
    /* 18A8 801040A8 808D048E */  lw         $a0, %lo(_currentScene)($s0)
    /* 18AC 801040AC 1180103C */  lui        $s0, %hi(D_80108DC0)
    /* 18B0 801040B0 C08D02AE */  sw         $v0, %lo(D_80108DC0)($s0)
    /* 18B4 801040B4 C0200400 */  sll        $a0, $a0, 3
    /* 18B8 801040B8 C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 18BC 801040BC 21209100 */   addu      $a0, $a0, $s1
    /* 18C0 801040C0 21204000 */  addu       $a0, $v0, $zero
    /* 18C4 801040C4 C08D058E */  lw         $a1, %lo(D_80108DC0)($s0)
    /* 18C8 801040C8 1180023C */  lui        $v0, %hi(_sceneCdQueueSlot)
    /* 18CC 801040CC F112010C */  jal        vs_main_cdEnqueue
    /* 18D0 801040D0 BC8D44AC */   sw        $a0, %lo(_sceneCdQueueSlot)($v0)
    /* 18D4 801040D4 9D100408 */  j          .L80104274
    /* 18D8 801040D8 1180053C */   lui       $a1, %hi(D_80108D6C)
    /* 18DC 801040DC 1180023C */  lui        $v0, %hi(D_80108D9E)
    /* 18E0 801040E0 1180053C */  lui        $a1, %hi(D_80108D68)
    /* 18E4 801040E4 688DA48C */  lw         $a0, %lo(D_80108D68)($a1)
    /* 18E8 801040E8 02000324 */  addiu      $v1, $zero, 0x2
    /* 18EC 801040EC 9E8D43A4 */  sh         $v1, %lo(D_80108D9E)($v0)
    /* 18F0 801040F0 80008228 */  slti       $v0, $a0, 0x80
    /* 18F4 801040F4 09004014 */  bnez       $v0, .L8010411C
    /* 18F8 801040F8 1180023C */   lui       $v0, %hi(_geomOffsetX)
    /* 18FC 801040FC 0F80103C */  lui        $s0, %hi(vs_battle_sceneBuffer)
    /* 1900 80104100 C01B048E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s0)
    /* 1904 80104104 180F010C */  jal        vs_main_freeHeapR
    /* 1908 80104108 00000000 */   nop
    /* 190C 8010410C 1180023C */  lui        $v0, %hi(D_80108E44)
    /* 1910 80104110 448E428C */  lw         $v0, %lo(D_80108E44)($v0)
    /* 1914 80104114 A4100408 */  j          .L80104290
    /* 1918 80104118 C01B00AE */   sw        $zero, %lo(vs_battle_sceneBuffer)($s0)
  .L8010411C:
    /* 191C 8010411C 708D438C */  lw         $v1, %lo(_geomOffsetX)($v0)
    /* 1920 80104120 10008424 */  addiu      $a0, $a0, 0x10
  .L80104124:
    /* 1924 80104124 688DA4AC */  sw         $a0, %lo(D_80108D68)($a1)
    /* 1928 80104128 40006324 */  addiu      $v1, $v1, 0x40
    /* 192C 8010412C 9A100408 */  j          .L80104268
    /* 1930 80104130 708D43AC */   sw        $v1, %lo(_geomOffsetX)($v0)
    /* 1934 80104134 1180143C */  lui        $s4, %hi(_geomOffsetX)
    /* 1938 80104138 1180023C */  lui        $v0, %hi(_sceneCdQueueSlot)
    /* 193C 8010413C 708D838E */  lw         $v1, %lo(_geomOffsetX)($s4)
    /* 1940 80104140 BC8D448C */  lw         $a0, %lo(_sceneCdQueueSlot)($v0)
    /* 1944 80104144 40006524 */  addiu      $a1, $v1, 0x40
    /* 1948 80104148 00008384 */  lh         $v1, 0x0($a0)
    /* 194C 8010414C 04000224 */  addiu      $v0, $zero, 0x4
    /* 1950 80104150 45006214 */  bne        $v1, $v0, .L80104268
    /* 1954 80104154 708D85AE */   sw        $a1, %lo(_geomOffsetX)($s4)
    /* 1958 80104158 8001A228 */  slti       $v0, $a1, 0x180
    /* 195C 8010415C 42004014 */  bnez       $v0, .L80104268
    /* 1960 80104160 1180023C */   lui       $v0, %hi(D_80108D88)
    /* 1964 80104164 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 1968 80104168 888D40AC */   sw        $zero, %lo(D_80108D88)($v0)
    /* 196C 8010416C 0F80113C */  lui        $s1, %hi(vs_battle_sceneBuffer)
    /* 1970 80104170 C01B248E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s1)
    /* 1974 80104174 180F010C */  jal        vs_main_freeHeapR
    /* 1978 80104178 1080103C */   lui       $s0, %hi(_sceneArmFiles)
    /* 197C 8010417C 1180123C */  lui        $s2, %hi(_currentScene)
    /* 1980 80104180 808D428E */  lw         $v0, %lo(_currentScene)($s2)
    /* 1984 80104184 002B1026 */  addiu      $s0, $s0, %lo(_sceneArmFiles)
    /* 1988 80104188 C0100200 */  sll        $v0, $v0, 3
    /* 198C 8010418C 21105000 */  addu       $v0, $v0, $s0
    /* 1990 80104190 0400448C */  lw         $a0, 0x4($v0)
    /* 1994 80104194 8F0F010C */  jal        vs_main_allocHeapR
    /* 1998 80104198 1180133C */   lui       $s3, %hi(D_80108DC0)
    /* 199C 8010419C 808D438E */  lw         $v1, %lo(_currentScene)($s2)
    /* 19A0 801041A0 C08D658E */  lw         $a1, %lo(D_80108DC0)($s3)
    /* 19A4 801041A4 C0180300 */  sll        $v1, $v1, 3
    /* 19A8 801041A8 21187000 */  addu       $v1, $v1, $s0
    /* 19AC 801041AC 0400668C */  lw         $a2, 0x4($v1)
    /* 19B0 801041B0 21204000 */  addu       $a0, $v0, $zero
    /* 19B4 801041B4 2C24010C */  jal        vs_main_memcpy
    /* 19B8 801041B8 C01B24AE */   sw        $a0, %lo(vs_battle_sceneBuffer)($s1)
    /* 19BC 801041BC C08D648E */  lw         $a0, %lo(D_80108DC0)($s3)
    /* 19C0 801041C0 180F010C */  jal        vs_main_freeHeapR
    /* 19C4 801041C4 1180123C */   lui       $s2, %hi(_roomNamesTable)
    /* 19C8 801041C8 C01B248E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s1)
    /* 19CC 801041CC D363020C */  jal        vs_battle_initSceneAndGetRoomNames
    /* 19D0 801041D0 1180103C */   lui       $s0, %hi(_currentRoomIndex)
    /* 19D4 801041D4 C01B248E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s1)
    /* 19D8 801041D8 362D020C */  jal        vs_battle_setRoomsUnk0
    /* 19DC 801041DC 988D42AE */   sw        $v0, %lo(_roomNamesTable)($s2)
    /* 19E0 801041E0 C01B248E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s1)
    /* 19E4 801041E4 3818040C */  jal        _scaleRoomVertices
    /* 19E8 801041E8 04000524 */   addiu     $a1, $zero, 0x4
    /* 19EC 801041EC C01B248E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s1)
    /* 19F0 801041F0 5C19040C */  jal        _getCurrentRoomIndex
    /* 19F4 801041F4 00000000 */   nop
    /* 19F8 801041F8 21284000 */  addu       $a1, $v0, $zero
    /* 19FC 801041FC C01B248E */  lw         $a0, %lo(vs_battle_sceneBuffer)($s1)
    /* 1A00 80104200 C616040C */  jal        _snapMapToRoom
    /* 1A04 80104204 648D05AE */   sw        $a1, %lo(_currentRoomIndex)($s0)
    /* 1A08 80104208 648D028E */  lw         $v0, %lo(_currentRoomIndex)($s0)
    /* 1A0C 8010420C 21200000 */  addu       $a0, $zero, $zero
    /* 1A10 80104210 C0280200 */  sll        $a1, $v0, 3
    /* 1A14 80104214 2128A200 */  addu       $a1, $a1, $v0
    /* 1A18 80104218 988D428E */  lw         $v0, %lo(_roomNamesTable)($s2)
    /* 1A1C 8010421C 80280500 */  sll        $a1, $a1, 2
    /* 1A20 80104220 FC1A030C */  jal        vs_battle_setTextBox
    /* 1A24 80104224 21284500 */   addu      $a1, $v0, $a1
    /* 1A28 80104228 80FE0224 */  addiu      $v0, $zero, -0x180
    /* 1A2C 8010422C 708D82AE */  sw         $v0, %lo(_geomOffsetX)($s4)
    /* 1A30 80104230 1180023C */  lui        $v0, %hi(_geomOffsetY)
    /* 1A34 80104234 1180033C */  lui        $v1, %hi(D_80108D60)
    /* 1A38 80104238 748D40AC */  sw         $zero, %lo(_geomOffsetY)($v0)
    /* 1A3C 8010423C 99100408 */  j          .L80104264
    /* 1A40 80104240 05000224 */   addiu     $v0, $zero, 0x5
    /* 1A44 80104244 1180033C */  lui        $v1, %hi(_geomOffsetX)
    /* 1A48 80104248 708D628C */  lw         $v0, %lo(_geomOffsetX)($v1)
    /* 1A4C 8010424C 00000000 */  nop
    /* 1A50 80104250 40004224 */  addiu      $v0, $v0, 0x40
    /* 1A54 80104254 04004004 */  bltz       $v0, .L80104268
    /* 1A58 80104258 708D62AC */   sw        $v0, %lo(_geomOffsetX)($v1)
    /* 1A5C 8010425C 1180033C */  lui        $v1, %hi(D_80108D60)
    /* 1A60 80104260 01000224 */  addiu      $v0, $zero, 0x1
  .L80104264:
    /* 1A64 80104264 608D62AC */  sw         $v0, %lo(D_80108D60)($v1)
  .L80104268:
    /* 1A68 80104268 AC10040C */  jal        func_801042B0
    /* 1A6C 8010426C 00000000 */   nop
  .L80104270:
    /* 1A70 80104270 1180053C */  lui        $a1, %hi(D_80108D6C)
  .L80104274:
    /* 1A74 80104274 0F80033C */  lui        $v1, %hi(vs_battle_sceneBuffer)
    /* 1A78 80104278 6C8DA28C */  lw         $v0, %lo(D_80108D6C)($a1)
    /* 1A7C 8010427C C01B648C */  lw         $a0, %lo(vs_battle_sceneBuffer)($v1)
    /* 1A80 80104280 01004224 */  addiu      $v0, $v0, 0x1
    /* 1A84 80104284 B017040C */  jal        _smoothMapToCenterpoint
    /* 1A88 80104288 6C8DA2AC */   sw        $v0, %lo(D_80108D6C)($a1)
    /* 1A8C 8010428C 21100000 */  addu       $v0, $zero, $zero
  .L80104290:
    /* 1A90 80104290 3400BF8F */  lw         $ra, 0x34($sp)
    /* 1A94 80104294 3000B48F */  lw         $s4, 0x30($sp)
    /* 1A98 80104298 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 1A9C 8010429C 2800B28F */  lw         $s2, 0x28($sp)
    /* 1AA0 801042A0 2400B18F */  lw         $s1, 0x24($sp)
    /* 1AA4 801042A4 2000B08F */  lw         $s0, 0x20($sp)
    /* 1AA8 801042A8 0800E003 */  jr         $ra
    /* 1AAC 801042AC 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80103684
