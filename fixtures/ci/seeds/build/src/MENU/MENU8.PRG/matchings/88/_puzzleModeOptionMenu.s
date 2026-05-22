nonmatching _puzzleModeOptionMenu, 0x1A4

glabel _puzzleModeOptionMenu
    /* AB8 801032B8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* ABC 801032BC 04008010 */  beqz       $a0, .L801032D0
    /* AC0 801032C0 2800BFAF */   sw        $ra, 0x28($sp)
    /* AC4 801032C4 1080023C */  lui        $v0, %hi(D_80105D98)
    /* AC8 801032C8 120D0408 */  j          .L80103448
    /* ACC 801032CC 985D40AC */   sw        $zero, %lo(D_80105D98)($v0)
  .L801032D0:
    /* AD0 801032D0 1080023C */  lui        $v0, %hi(D_80105D98)
    /* AD4 801032D4 985D438C */  lw         $v1, %lo(D_80105D98)($v0)
    /* AD8 801032D8 01000224 */  addiu      $v0, $zero, 0x1
    /* ADC 801032DC 3C006210 */  beq        $v1, $v0, .L801033D0
    /* AE0 801032E0 02006228 */   slti      $v0, $v1, 0x2
    /* AE4 801032E4 05004010 */  beqz       $v0, .L801032FC
    /* AE8 801032E8 02000224 */   addiu     $v0, $zero, 0x2
    /* AEC 801032EC 07006010 */  beqz       $v1, .L8010330C
    /* AF0 801032F0 21100000 */   addu      $v0, $zero, $zero
    /* AF4 801032F4 130D0408 */  j          .L8010344C
    /* AF8 801032F8 00000000 */   nop
  .L801032FC:
    /* AFC 801032FC 4B006210 */  beq        $v1, $v0, .L8010342C
    /* B00 80103300 21100000 */   addu      $v0, $zero, $zero
    /* B04 80103304 130D0408 */  j          .L8010344C
    /* B08 80103308 00000000 */   nop
  .L8010330C:
    /* B0C 8010330C 74EA030C */  jal        vs_mainmenu_ready
    /* B10 80103310 00000000 */   nop
    /* B14 80103314 4C004010 */  beqz       $v0, .L80103448
    /* B18 80103318 21280000 */   addu      $a1, $zero, $zero
    /* B1C 8010331C 1080023C */  lui        $v0, %hi(_menuStrings)
    /* B20 80103320 58554B24 */  addiu      $t3, $v0, %lo(_menuStrings)
    /* B24 80103324 2000AA27 */  addiu      $t2, $sp, 0x20
    /* B28 80103328 5E000924 */  addiu      $t1, $zero, 0x5E
    /* B2C 8010332C 04000824 */  addiu      $t0, $zero, 0x4
    /* B30 80103330 1000AC27 */  addiu      $t4, $sp, 0x10
    /* B34 80103334 21388001 */  addu       $a3, $t4, $zero
    /* B38 80103338 5C000624 */  addiu      $a2, $zero, 0x5C
  .L8010333C:
    /* B3C 8010333C 21182B01 */  addu       $v1, $t1, $t3
    /* B40 80103340 04002925 */  addiu      $t1, $t1, 0x4
    /* B44 80103344 21208801 */  addu       $a0, $t4, $t0
    /* B48 80103348 08000825 */  addiu      $t0, $t0, 0x8
    /* B4C 8010334C 2110CB00 */  addu       $v0, $a2, $t3
    /* B50 80103350 0400C624 */  addiu      $a2, $a2, 0x4
    /* B54 80103354 00004294 */  lhu        $v0, 0x0($v0)
    /* B58 80103358 0100A524 */  addiu      $a1, $a1, 0x1
    /* B5C 8010335C 40100200 */  sll        $v0, $v0, 1
    /* B60 80103360 21104B00 */  addu       $v0, $v0, $t3
    /* B64 80103364 0000E2AC */  sw         $v0, 0x0($a3)
    /* B68 80103368 00006294 */  lhu        $v0, 0x0($v1)
    /* B6C 8010336C 0800E724 */  addiu      $a3, $a3, 0x8
    /* B70 80103370 40100200 */  sll        $v0, $v0, 1
    /* B74 80103374 21104B00 */  addu       $v0, $v0, $t3
    /* B78 80103378 000082AC */  sw         $v0, 0x0($a0)
    /* B7C 8010337C 000040AD */  sw         $zero, 0x0($t2)
    /* B80 80103380 0200A228 */  slti       $v0, $a1, 0x2
    /* B84 80103384 EDFF4014 */  bnez       $v0, .L8010333C
    /* B88 80103388 04004A25 */   addiu     $t2, $t2, 0x4
    /* B8C 8010338C 0680023C */  lui        $v0, %hi(vs_main_settings)
    /* B90 80103390 2000A727 */  addiu      $a3, $sp, 0x20
    /* B94 80103394 02000424 */  addiu      $a0, $zero, 0x2
    /* B98 80103398 2000428C */  lw         $v0, %lo(vs_main_settings)($v0)
    /* B9C 8010339C 1000A627 */  addiu      $a2, $sp, 0x10
    /* BA0 801033A0 42280200 */  srl        $a1, $v0, 1
    /* BA4 801033A4 0400A330 */  andi       $v1, $a1, 0x4
    /* BA8 801033A8 2118E300 */  addu       $v1, $a3, $v1
    /* BAC 801033AC 0000628C */  lw         $v0, 0x0($v1)
    /* BB0 801033B0 4C020524 */  addiu      $a1, $zero, 0x24C
    /* BB4 801033B4 04004234 */  ori        $v0, $v0, 0x4
    /* BB8 801033B8 7801040C */  jal        vs_mainmenu_setMenuRows
    /* BBC 801033BC 000062AC */   sw        $v0, 0x0($v1)
    /* BC0 801033C0 1080033C */  lui        $v1, %hi(D_80105D98)
    /* BC4 801033C4 01000224 */  addiu      $v0, $zero, 0x1
    /* BC8 801033C8 120D0408 */  j          .L80103448
    /* BCC 801033CC 985D62AC */   sw        $v0, %lo(D_80105D98)($v1)
  .L801033D0:
    /* BD0 801033D0 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* BD4 801033D4 00000000 */   nop
    /* BD8 801033D8 1080033C */  lui        $v1, %hi(D_80105D9C)
    /* BDC 801033DC 01004424 */  addiu      $a0, $v0, 0x1
    /* BE0 801033E0 19008010 */  beqz       $a0, .L80103448
    /* BE4 801033E4 9C5D64AC */   sw        $a0, %lo(D_80105D9C)($v1)
    /* BE8 801033E8 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* BEC 801033EC 09008214 */  bne        $a0, $v0, .L80103414
    /* BF0 801033F0 00000000 */   nop
    /* BF4 801033F4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* BF8 801033F8 28000424 */   addiu     $a0, $zero, 0x28
    /* BFC 801033FC EAFE030C */  jal        func_800FFBA8
    /* C00 80103400 00000000 */   nop
    /* C04 80103404 A2FE030C */  jal        func_800FFA88
    /* C08 80103408 21200000 */   addu      $a0, $zero, $zero
    /* C0C 8010340C 080D0408 */  j          .L80103420
    /* C10 80103410 1080033C */   lui       $v1, %hi(D_80105D98)
  .L80103414:
    /* C14 80103414 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* C18 80103418 07000424 */   addiu     $a0, $zero, 0x7
    /* C1C 8010341C 1080033C */  lui        $v1, %hi(D_80105D98)
  .L80103420:
    /* C20 80103420 02000224 */  addiu      $v0, $zero, 0x2
    /* C24 80103424 120D0408 */  j          .L80103448
    /* C28 80103428 985D62AC */   sw        $v0, %lo(D_80105D98)($v1)
  .L8010342C:
    /* C2C 8010342C 74EA030C */  jal        vs_mainmenu_ready
    /* C30 80103430 00000000 */   nop
    /* C34 80103434 04004010 */  beqz       $v0, .L80103448
    /* C38 80103438 1080023C */   lui       $v0, %hi(D_80105D9C)
    /* C3C 8010343C 9C5D428C */  lw         $v0, %lo(D_80105D9C)($v0)
    /* C40 80103440 130D0408 */  j          .L8010344C
    /* C44 80103444 00000000 */   nop
  .L80103448:
    /* C48 80103448 21100000 */  addu       $v0, $zero, $zero
  .L8010344C:
    /* C4C 8010344C 2800BF8F */  lw         $ra, 0x28($sp)
    /* C50 80103450 00000000 */  nop
    /* C54 80103454 0800E003 */  jr         $ra
    /* C58 80103458 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _puzzleModeOptionMenu
