nonmatching _bladeDetailsPage, 0x1EC

glabel _bladeDetailsPage
    /* 90C 8010310C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 910 80103110 21288000 */  addu       $a1, $a0, $zero
    /* 914 80103114 2800BFAF */  sw         $ra, 0x28($sp)
    /* 918 80103118 2400B1AF */  sw         $s1, 0x24($sp)
    /* 91C 8010311C 1000A010 */  beqz       $a1, .L80103160
    /* 920 80103120 2000B0AF */   sw        $s0, 0x20($sp)
    /* 924 80103124 1180033C */  lui        $v1, %hi(D_8010A5F3)
    /* 928 80103128 03120500 */  sra        $v0, $a1, 8
    /* 92C 8010312C F3A562A0 */  sb         $v0, %lo(D_8010A5F3)($v1)
    /* 930 80103130 FF004430 */  andi       $a0, $v0, 0xFF
    /* 934 80103134 1180033C */  lui        $v1, %hi(D_8010A5F4)
    /* 938 80103138 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 93C 8010313C 140B040C */  jal        func_80102C50
    /* 940 80103140 F4A562A0 */   sb        $v0, %lo(D_8010A5F4)($v1)
    /* 944 80103144 21100000 */  addu       $v0, $zero, $zero
    /* 948 80103148 1180043C */  lui        $a0, %hi(D_8010A5F2)
    /* 94C 8010314C 0A000324 */  addiu      $v1, $zero, 0xA
    /* 950 80103150 F2A583A0 */  sb         $v1, %lo(D_8010A5F2)($a0)
    /* 954 80103154 1180033C */  lui        $v1, %hi(D_8010A5F1)
    /* 958 80103158 B90C0408 */  j          .L801032E4
    /* 95C 8010315C F1A560A0 */   sb        $zero, %lo(D_8010A5F1)($v1)
  .L80103160:
    /* 960 80103160 1180103C */  lui        $s0, %hi(D_8010A5F1)
    /* 964 80103164 F1A50392 */  lbu        $v1, %lo(D_8010A5F1)($s0)
    /* 968 80103168 01001124 */  addiu      $s1, $zero, 0x1
    /* 96C 8010316C 20007110 */  beq        $v1, $s1, .L801031F0
    /* 970 80103170 02006228 */   slti      $v0, $v1, 0x2
    /* 974 80103174 05004010 */  beqz       $v0, .L8010318C
    /* 978 80103178 02000224 */   addiu     $v0, $zero, 0x2
    /* 97C 8010317C 09006010 */  beqz       $v1, .L801031A4
    /* 980 80103180 21100000 */   addu      $v0, $zero, $zero
    /* 984 80103184 B90C0408 */  j          .L801032E4
    /* 988 80103188 00000000 */   nop
  .L8010318C:
    /* 98C 8010318C 22006210 */  beq        $v1, $v0, .L80103218
    /* 990 80103190 03000224 */   addiu     $v0, $zero, 0x3
    /* 994 80103194 4E006210 */  beq        $v1, $v0, .L801032D0
    /* 998 80103198 21100000 */   addu      $v0, $zero, $zero
    /* 99C 8010319C B90C0408 */  j          .L801032E4
    /* 9A0 801031A0 00000000 */   nop
  .L801031A4:
    /* 9A4 801031A4 74EA030C */  jal        vs_mainmenu_ready
    /* 9A8 801031A8 00000000 */   nop
    /* 9AC 801031AC 4C004010 */  beqz       $v0, .L801032E0
    /* 9B0 801031B0 1180023C */   lui       $v0, %hi(D_8010A5F3)
    /* 9B4 801031B4 F3A54490 */  lbu        $a0, %lo(D_8010A5F3)($v0)
    /* 9B8 801031B8 470B040C */  jal        _initMenuLayout
    /* 9BC 801031BC 03000524 */   addiu     $a1, $zero, 0x3
    /* 9C0 801031C0 0680033C */  lui        $v1, %hi(vs_main_inventoryIndices)
    /* 9C4 801031C4 1180023C */  lui        $v0, %hi(D_8010A5F4)
    /* 9C8 801031C8 F4A54290 */  lbu        $v0, %lo(D_8010A5F4)($v0)
    /* 9CC 801031CC D8196324 */  addiu      $v1, $v1, %lo(vs_main_inventoryIndices)
    /* 9D0 801031D0 21104300 */  addu       $v0, $v0, $v1
    /* 9D4 801031D4 08004490 */  lbu        $a0, 0x8($v0)
    /* 9D8 801031D8 01F5030C */  jal        vs_mainMenu_setUiBladeStats
    /* 9DC 801031DC 00000000 */   nop
    /* 9E0 801031E0 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 9E4 801031E4 03000424 */   addiu     $a0, $zero, 0x3
    /* 9E8 801031E8 B80C0408 */  j          .L801032E0
    /* 9EC 801031EC F1A511A2 */   sb        $s1, %lo(D_8010A5F1)($s0)
  .L801031F0:
    /* 9F0 801031F0 1180033C */  lui        $v1, %hi(D_8010A5F2)
    /* 9F4 801031F4 F2A56290 */  lbu        $v0, %lo(D_8010A5F2)($v1)
    /* 9F8 801031F8 00000000 */  nop
    /* 9FC 801031FC 03004010 */  beqz       $v0, .L8010320C
    /* A00 80103200 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* A04 80103204 B80C0408 */  j          .L801032E0
    /* A08 80103208 F2A562A0 */   sb        $v0, %lo(D_8010A5F2)($v1)
  .L8010320C:
    /* A0C 8010320C 02000224 */  addiu      $v0, $zero, 0x2
    /* A10 80103210 B80C0408 */  j          .L801032E0
    /* A14 80103214 F1A502A2 */   sb        $v0, %lo(D_8010A5F1)($s0)
  .L80103218:
    /* A18 80103218 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* A1C 8010321C D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* A20 80103220 00000000 */  nop
    /* A24 80103224 50004230 */  andi       $v0, $v0, 0x50
    /* A28 80103228 06004010 */  beqz       $v0, .L80103244
    /* A2C 8010322C 00000000 */   nop
    /* A30 80103230 950B040C */  jal        _initMenuLeave
    /* A34 80103234 01000424 */   addiu     $a0, $zero, 0x1
    /* A38 80103238 03000224 */  addiu      $v0, $zero, 0x3
    /* A3C 8010323C B80C0408 */  j          .L801032E0
    /* A40 80103240 F1A502A2 */   sb        $v0, %lo(D_8010A5F1)($s0)
  .L80103244:
    /* A44 80103244 1180103C */  lui        $s0, %hi(D_8010A5F4)
    /* A48 80103248 F4A50592 */  lbu        $a1, %lo(D_8010A5F4)($s0)
    /* A4C 8010324C 980A040C */  jal        _handleItemPaging
    /* A50 80103250 01000424 */   addiu     $a0, $zero, 0x1
    /* A54 80103254 F4A50392 */  lbu        $v1, %lo(D_8010A5F4)($s0)
    /* A58 80103258 21884000 */  addu       $s1, $v0, $zero
    /* A5C 8010325C 20002312 */  beq        $s1, $v1, .L801032E0
    /* A60 80103260 01000424 */   addiu     $a0, $zero, 0x1
    /* A64 80103264 21282002 */  addu       $a1, $s1, $zero
    /* A68 80103268 820B040C */  jal        _getItemIndex
    /* A6C 8010326C F4A511A2 */   sb        $s1, %lo(D_8010A5F4)($s0)
    /* A70 80103270 21804000 */  addu       $s0, $v0, $zero
    /* A74 80103274 40201000 */  sll        $a0, $s0, 1
    /* A78 80103278 21209000 */  addu       $a0, $a0, $s0
    /* A7C 8010327C 80200400 */  sll        $a0, $a0, 2
    /* A80 80103280 23209000 */  subu       $a0, $a0, $s0
    /* A84 80103284 80200400 */  sll        $a0, $a0, 2
    /* A88 80103288 0680023C */  lui        $v0, %hi(D_800603BC)
    /* A8C 8010328C BC034224 */  addiu      $v0, $v0, %lo(D_800603BC)
    /* A90 80103290 21208200 */  addu       $a0, $a0, $v0
    /* A94 80103294 1000A527 */  addiu      $a1, $sp, 0x10
    /* A98 80103298 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* A9C 8010329C 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* AA0 801032A0 A9F2030C */  jal        vs_mainMenu_setUiBlade
    /* AA4 801032A4 1800A627 */   addiu     $a2, $sp, 0x18
    /* AA8 801032A8 01F5030C */  jal        vs_mainMenu_setUiBladeStats
    /* AAC 801032AC 21200002 */   addu      $a0, $s0, $zero
    /* AB0 801032B0 1000A527 */  addiu      $a1, $sp, 0x10
    /* AB4 801032B4 1180023C */  lui        $v0, %hi(D_8010A5F3)
    /* AB8 801032B8 F3A54490 */  lbu        $a0, %lo(D_8010A5F3)($v0)
    /* ABC 801032BC 1800A68F */  lw         $a2, 0x18($sp)
    /* AC0 801032C0 5B0B040C */  jal        _setSubMenu
    /* AC4 801032C4 21382002 */   addu      $a3, $s1, $zero
    /* AC8 801032C8 B90C0408 */  j          .L801032E4
    /* ACC 801032CC 21100000 */   addu      $v0, $zero, $zero
  .L801032D0:
    /* AD0 801032D0 74EA030C */  jal        vs_mainmenu_ready
    /* AD4 801032D4 00000000 */   nop
    /* AD8 801032D8 B90C0408 */  j          .L801032E4
    /* ADC 801032DC 00000000 */   nop
  .L801032E0:
    /* AE0 801032E0 21100000 */  addu       $v0, $zero, $zero
  .L801032E4:
    /* AE4 801032E4 2800BF8F */  lw         $ra, 0x28($sp)
    /* AE8 801032E8 2400B18F */  lw         $s1, 0x24($sp)
    /* AEC 801032EC 2000B08F */  lw         $s0, 0x20($sp)
    /* AF0 801032F0 0800E003 */  jr         $ra
    /* AF4 801032F4 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _bladeDetailsPage
