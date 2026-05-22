nonmatching _abilityTimingOptionMenu, 0x1B0

glabel _abilityTimingOptionMenu
    /* 25C 80102A5C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 260 80102A60 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 264 80102A64 04008010 */  beqz       $a0, .L80102A78
    /* 268 80102A68 2800B0AF */   sw        $s0, 0x28($sp)
    /* 26C 80102A6C 1080023C */  lui        $v0, %hi(D_80105D70)
    /* 270 80102A70 FE0A0408 */  j          .L80102BF8
    /* 274 80102A74 705D40AC */   sw        $zero, %lo(D_80105D70)($v0)
  .L80102A78:
    /* 278 80102A78 1080023C */  lui        $v0, %hi(D_80105D70)
    /* 27C 80102A7C 705D438C */  lw         $v1, %lo(D_80105D70)($v0)
    /* 280 80102A80 01000224 */  addiu      $v0, $zero, 0x1
    /* 284 80102A84 3E006210 */  beq        $v1, $v0, .L80102B80
    /* 288 80102A88 02006228 */   slti      $v0, $v1, 0x2
    /* 28C 80102A8C 05004010 */  beqz       $v0, .L80102AA4
    /* 290 80102A90 02000224 */   addiu     $v0, $zero, 0x2
    /* 294 80102A94 07006010 */  beqz       $v1, .L80102AB4
    /* 298 80102A98 21100000 */   addu      $v0, $zero, $zero
    /* 29C 80102A9C FF0A0408 */  j          .L80102BFC
    /* 2A0 80102AA0 00000000 */   nop
  .L80102AA4:
    /* 2A4 80102AA4 4D006210 */  beq        $v1, $v0, .L80102BDC
    /* 2A8 80102AA8 21100000 */   addu      $v0, $zero, $zero
    /* 2AC 80102AAC FF0A0408 */  j          .L80102BFC
    /* 2B0 80102AB0 00000000 */   nop
  .L80102AB4:
    /* 2B4 80102AB4 74EA030C */  jal        vs_mainmenu_ready
    /* 2B8 80102AB8 00000000 */   nop
    /* 2BC 80102ABC 4E004010 */  beqz       $v0, .L80102BF8
    /* 2C0 80102AC0 21280000 */   addu      $a1, $zero, $zero
    /* 2C4 80102AC4 1080023C */  lui        $v0, %hi(_menuStrings)
    /* 2C8 80102AC8 58554B24 */  addiu      $t3, $v0, %lo(_menuStrings)
    /* 2CC 80102ACC 2000AA27 */  addiu      $t2, $sp, 0x20
    /* 2D0 80102AD0 36000924 */  addiu      $t1, $zero, 0x36
    /* 2D4 80102AD4 04000824 */  addiu      $t0, $zero, 0x4
    /* 2D8 80102AD8 1000AC27 */  addiu      $t4, $sp, 0x10
    /* 2DC 80102ADC 21388001 */  addu       $a3, $t4, $zero
    /* 2E0 80102AE0 34000624 */  addiu      $a2, $zero, 0x34
  .L80102AE4:
    /* 2E4 80102AE4 21182B01 */  addu       $v1, $t1, $t3
    /* 2E8 80102AE8 04002925 */  addiu      $t1, $t1, 0x4
    /* 2EC 80102AEC 21208801 */  addu       $a0, $t4, $t0
    /* 2F0 80102AF0 08000825 */  addiu      $t0, $t0, 0x8
    /* 2F4 80102AF4 2110CB00 */  addu       $v0, $a2, $t3
    /* 2F8 80102AF8 0400C624 */  addiu      $a2, $a2, 0x4
    /* 2FC 80102AFC 00004294 */  lhu        $v0, 0x0($v0)
    /* 300 80102B00 0100A524 */  addiu      $a1, $a1, 0x1
    /* 304 80102B04 40100200 */  sll        $v0, $v0, 1
    /* 308 80102B08 21104B00 */  addu       $v0, $v0, $t3
    /* 30C 80102B0C 0000E2AC */  sw         $v0, 0x0($a3)
    /* 310 80102B10 00006294 */  lhu        $v0, 0x0($v1)
    /* 314 80102B14 0800E724 */  addiu      $a3, $a3, 0x8
    /* 318 80102B18 40100200 */  sll        $v0, $v0, 1
    /* 31C 80102B1C 21104B00 */  addu       $v0, $v0, $t3
    /* 320 80102B20 000082AC */  sw         $v0, 0x0($a0)
    /* 324 80102B24 000040AD */  sw         $zero, 0x0($t2)
    /* 328 80102B28 0200A228 */  slti       $v0, $a1, 0x2
    /* 32C 80102B2C EDFF4014 */  bnez       $v0, .L80102AE4
    /* 330 80102B30 04004A25 */   addiu     $t2, $t2, 0x4
    /* 334 80102B34 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* 338 80102B38 01001024 */  addiu      $s0, $zero, 0x1
    /* 33C 80102B3C 2000A727 */  addiu      $a3, $sp, 0x20
    /* 340 80102B40 02000424 */  addiu      $a0, $zero, 0x2
    /* 344 80102B44 2000428C */  lw         $v0, %lo(vs_main_settings)($v0)
    /* 348 80102B48 1000A627 */  addiu      $a2, $sp, 0x10
    /* 34C 80102B4C 42110200 */  srl        $v0, $v0, 5
    /* 350 80102B50 01004230 */  andi       $v0, $v0, 0x1
    /* 354 80102B54 23280202 */  subu       $a1, $s0, $v0
    /* 358 80102B58 80180500 */  sll        $v1, $a1, 2
    /* 35C 80102B5C 2118E300 */  addu       $v1, $a3, $v1
    /* 360 80102B60 0000628C */  lw         $v0, 0x0($v1)
    /* 364 80102B64 47020524 */  addiu      $a1, $zero, 0x247
    /* 368 80102B68 04004234 */  ori        $v0, $v0, 0x4
    /* 36C 80102B6C 7801040C */  jal        vs_mainmenu_setMenuRows
    /* 370 80102B70 000062AC */   sw        $v0, 0x0($v1)
    /* 374 80102B74 1080023C */  lui        $v0, %hi(D_80105D70)
    /* 378 80102B78 FE0A0408 */  j          .L80102BF8
    /* 37C 80102B7C 705D50AC */   sw        $s0, %lo(D_80105D70)($v0)
  .L80102B80:
    /* 380 80102B80 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* 384 80102B84 00000000 */   nop
    /* 388 80102B88 1080033C */  lui        $v1, %hi(D_80105D74)
    /* 38C 80102B8C 01004424 */  addiu      $a0, $v0, 0x1
    /* 390 80102B90 19008010 */  beqz       $a0, .L80102BF8
    /* 394 80102B94 745D64AC */   sw        $a0, %lo(D_80105D74)($v1)
    /* 398 80102B98 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 39C 80102B9C 09008214 */  bne        $a0, $v0, .L80102BC4
    /* 3A0 80102BA0 00000000 */   nop
    /* 3A4 80102BA4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 3A8 80102BA8 28000424 */   addiu     $a0, $zero, 0x28
    /* 3AC 80102BAC EAFE030C */  jal        func_800FFBA8
    /* 3B0 80102BB0 00000000 */   nop
    /* 3B4 80102BB4 A2FE030C */  jal        func_800FFA88
    /* 3B8 80102BB8 21200000 */   addu      $a0, $zero, $zero
    /* 3BC 80102BBC F40A0408 */  j          .L80102BD0
    /* 3C0 80102BC0 1080033C */   lui       $v1, %hi(D_80105D70)
  .L80102BC4:
    /* 3C4 80102BC4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 3C8 80102BC8 07000424 */   addiu     $a0, $zero, 0x7
    /* 3CC 80102BCC 1080033C */  lui        $v1, %hi(D_80105D70)
  .L80102BD0:
    /* 3D0 80102BD0 02000224 */  addiu      $v0, $zero, 0x2
    /* 3D4 80102BD4 FE0A0408 */  j          .L80102BF8
    /* 3D8 80102BD8 705D62AC */   sw        $v0, %lo(D_80105D70)($v1)
  .L80102BDC:
    /* 3DC 80102BDC 74EA030C */  jal        vs_mainmenu_ready
    /* 3E0 80102BE0 00000000 */   nop
    /* 3E4 80102BE4 04004010 */  beqz       $v0, .L80102BF8
    /* 3E8 80102BE8 1080023C */   lui       $v0, %hi(D_80105D74)
    /* 3EC 80102BEC 745D428C */  lw         $v0, %lo(D_80105D74)($v0)
    /* 3F0 80102BF0 FF0A0408 */  j          .L80102BFC
    /* 3F4 80102BF4 00000000 */   nop
  .L80102BF8:
    /* 3F8 80102BF8 21100000 */  addu       $v0, $zero, $zero
  .L80102BFC:
    /* 3FC 80102BFC 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 400 80102C00 2800B08F */  lw         $s0, 0x28($sp)
    /* 404 80102C04 0800E003 */  jr         $ra
    /* 408 80102C08 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _abilityTimingOptionMenu
