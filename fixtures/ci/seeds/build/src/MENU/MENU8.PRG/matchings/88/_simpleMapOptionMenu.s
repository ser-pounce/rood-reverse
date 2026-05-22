nonmatching _simpleMapOptionMenu, 0x1D4

glabel _simpleMapOptionMenu
    /* 88 80102888 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 8C 8010288C 04008010 */  beqz       $a0, .L801028A0
    /* 90 80102890 3800BFAF */   sw        $ra, 0x38($sp)
    /* 94 80102894 1080023C */  lui        $v0, %hi(D_80105D68)
    /* 98 80102898 920A0408 */  j          .L80102A48
    /* 9C 8010289C 685D40AC */   sw        $zero, %lo(D_80105D68)($v0)
  .L801028A0:
    /* A0 801028A0 1080023C */  lui        $v0, %hi(D_80105D68)
    /* A4 801028A4 685D438C */  lw         $v1, %lo(D_80105D68)($v0)
    /* A8 801028A8 01000224 */  addiu      $v0, $zero, 0x1
    /* AC 801028AC 48006210 */  beq        $v1, $v0, .L801029D0
    /* B0 801028B0 02006228 */   slti      $v0, $v1, 0x2
    /* B4 801028B4 05004010 */  beqz       $v0, .L801028CC
    /* B8 801028B8 02000224 */   addiu     $v0, $zero, 0x2
    /* BC 801028BC 07006010 */  beqz       $v1, .L801028DC
    /* C0 801028C0 21100000 */   addu      $v0, $zero, $zero
    /* C4 801028C4 930A0408 */  j          .L80102A4C
    /* C8 801028C8 00000000 */   nop
  .L801028CC:
    /* CC 801028CC 57006210 */  beq        $v1, $v0, .L80102A2C
    /* D0 801028D0 21100000 */   addu      $v0, $zero, $zero
    /* D4 801028D4 930A0408 */  j          .L80102A4C
    /* D8 801028D8 00000000 */   nop
  .L801028DC:
    /* DC 801028DC 74EA030C */  jal        vs_mainmenu_ready
    /* E0 801028E0 00000000 */   nop
    /* E4 801028E4 58004010 */  beqz       $v0, .L80102A48
    /* E8 801028E8 21280000 */   addu      $a1, $zero, $zero
    /* EC 801028EC 1080023C */  lui        $v0, %hi(_menuStrings)
    /* F0 801028F0 58554B24 */  addiu      $t3, $v0, %lo(_menuStrings)
    /* F4 801028F4 2800AA27 */  addiu      $t2, $sp, 0x28
    /* F8 801028F8 2A000924 */  addiu      $t1, $zero, 0x2A
    /* FC 801028FC 04000824 */  addiu      $t0, $zero, 0x4
    /* 100 80102900 1000AC27 */  addiu      $t4, $sp, 0x10
    /* 104 80102904 21388001 */  addu       $a3, $t4, $zero
    /* 108 80102908 28000624 */  addiu      $a2, $zero, 0x28
  .L8010290C:
    /* 10C 8010290C 21182B01 */  addu       $v1, $t1, $t3
    /* 110 80102910 04002925 */  addiu      $t1, $t1, 0x4
    /* 114 80102914 21208801 */  addu       $a0, $t4, $t0
    /* 118 80102918 08000825 */  addiu      $t0, $t0, 0x8
    /* 11C 8010291C 2110CB00 */  addu       $v0, $a2, $t3
    /* 120 80102920 0400C624 */  addiu      $a2, $a2, 0x4
    /* 124 80102924 00004294 */  lhu        $v0, 0x0($v0)
    /* 128 80102928 0100A524 */  addiu      $a1, $a1, 0x1
    /* 12C 8010292C 40100200 */  sll        $v0, $v0, 1
    /* 130 80102930 21104B00 */  addu       $v0, $v0, $t3
    /* 134 80102934 0000E2AC */  sw         $v0, 0x0($a3)
    /* 138 80102938 00006294 */  lhu        $v0, 0x0($v1)
    /* 13C 8010293C 0800E724 */  addiu      $a3, $a3, 0x8
    /* 140 80102940 40100200 */  sll        $v0, $v0, 1
    /* 144 80102944 21104B00 */  addu       $v0, $v0, $t3
    /* 148 80102948 000082AC */  sw         $v0, 0x0($a0)
    /* 14C 8010294C 000040AD */  sw         $zero, 0x0($t2)
    /* 150 80102950 0300A228 */  slti       $v0, $a1, 0x3
    /* 154 80102954 EDFF4014 */  bnez       $v0, .L8010290C
    /* 158 80102958 04004A25 */   addiu     $t2, $t2, 0x4
    /* 15C 8010295C 21280000 */  addu       $a1, $zero, $zero
    /* 160 80102960 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 164 80102964 20004724 */  addiu      $a3, $v0, %lo(vs_main_settings)
    /* 168 80102968 1080023C */  lui        $v0, %hi(_simpleMapValues)
    /* 16C 8010296C 645D4624 */  addiu      $a2, $v0, %lo(_simpleMapValues)
    /* 170 80102970 2800A427 */  addiu      $a0, $sp, 0x28
  .L80102974:
    /* 174 80102974 2110A600 */  addu       $v0, $a1, $a2
    /* 178 80102978 0900E390 */  lbu        $v1, 0x9($a3)
    /* 17C 8010297C 00004290 */  lbu        $v0, 0x0($v0)
    /* 180 80102980 00000000 */  nop
    /* 184 80102984 05006214 */  bne        $v1, $v0, .L8010299C
    /* 188 80102988 00000000 */   nop
    /* 18C 8010298C 0000828C */  lw         $v0, 0x0($a0)
    /* 190 80102990 00000000 */  nop
    /* 194 80102994 04004234 */  ori        $v0, $v0, 0x4
    /* 198 80102998 000082AC */  sw         $v0, 0x0($a0)
  .L8010299C:
    /* 19C 8010299C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 1A0 801029A0 0300A228 */  slti       $v0, $a1, 0x3
    /* 1A4 801029A4 F3FF4014 */  bnez       $v0, .L80102974
    /* 1A8 801029A8 04008424 */   addiu     $a0, $a0, 0x4
    /* 1AC 801029AC 03000424 */  addiu      $a0, $zero, 0x3
    /* 1B0 801029B0 46020524 */  addiu      $a1, $zero, 0x246
    /* 1B4 801029B4 1000A627 */  addiu      $a2, $sp, 0x10
    /* 1B8 801029B8 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 1BC 801029BC 2800A727 */   addiu     $a3, $sp, 0x28
    /* 1C0 801029C0 1080033C */  lui        $v1, %hi(D_80105D68)
    /* 1C4 801029C4 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C8 801029C8 920A0408 */  j          .L80102A48
    /* 1CC 801029CC 685D62AC */   sw        $v0, %lo(D_80105D68)($v1)
  .L801029D0:
    /* 1D0 801029D0 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 1D4 801029D4 00000000 */   nop
    /* 1D8 801029D8 1080033C */  lui        $v1, %hi(D_80105D6C)
    /* 1DC 801029DC 01004424 */  addiu      $a0, $v0, 0x1
    /* 1E0 801029E0 19008010 */  beqz       $a0, .L80102A48
    /* 1E4 801029E4 6C5D64AC */   sw        $a0, %lo(D_80105D6C)($v1)
    /* 1E8 801029E8 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 1EC 801029EC 09008214 */  bne        $a0, $v0, .L80102A14
    /* 1F0 801029F0 00000000 */   nop
    /* 1F4 801029F4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1F8 801029F8 28000424 */   addiu     $a0, $zero, 0x28
    /* 1FC 801029FC EAFE030C */  jal        func_800FFBA8
    /* 200 80102A00 00000000 */   nop
    /* 204 80102A04 A2FE030C */  jal        func_800FFA88
    /* 208 80102A08 21200000 */   addu      $a0, $zero, $zero
    /* 20C 80102A0C 880A0408 */  j          .L80102A20
    /* 210 80102A10 1080033C */   lui       $v1, %hi(D_80105D68)
  .L80102A14:
    /* 214 80102A14 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 218 80102A18 07000424 */   addiu     $a0, $zero, 0x7
    /* 21C 80102A1C 1080033C */  lui        $v1, %hi(D_80105D68)
  .L80102A20:
    /* 220 80102A20 02000224 */  addiu      $v0, $zero, 0x2
    /* 224 80102A24 920A0408 */  j          .L80102A48
    /* 228 80102A28 685D62AC */   sw        $v0, %lo(D_80105D68)($v1)
  .L80102A2C:
    /* 22C 80102A2C 74EA030C */  jal        vs_mainmenu_ready
    /* 230 80102A30 00000000 */   nop
    /* 234 80102A34 04004010 */  beqz       $v0, .L80102A48
    /* 238 80102A38 1080023C */   lui       $v0, %hi(D_80105D6C)
    /* 23C 80102A3C 6C5D428C */  lw         $v0, %lo(D_80105D6C)($v0)
    /* 240 80102A40 930A0408 */  j          .L80102A4C
    /* 244 80102A44 00000000 */   nop
  .L80102A48:
    /* 248 80102A48 21100000 */  addu       $v0, $zero, $zero
  .L80102A4C:
    /* 24C 80102A4C 3800BF8F */  lw         $ra, 0x38($sp)
    /* 250 80102A50 00000000 */  nop
    /* 254 80102A54 0800E003 */  jr         $ra
    /* 258 80102A58 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel _simpleMapOptionMenu
