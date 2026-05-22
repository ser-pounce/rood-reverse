nonmatching vs_menu1_exec, 0x208

glabel vs_menu1_exec
    /* A70 80103270 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* A74 80103274 1000B0AF */  sw         $s0, 0x10($sp)
    /* A78 80103278 21808000 */  addu       $s0, $a0, $zero
    /* A7C 8010327C 1400BFAF */  sw         $ra, 0x14($sp)
    /* A80 80103280 00000292 */  lbu        $v0, 0x0($s0)
    /* A84 80103284 00000000 */  nop
    /* A88 80103288 FDFF4324 */  addiu      $v1, $v0, -0x3
    /* A8C 8010328C 0800622C */  sltiu      $v0, $v1, 0x8
    /* A90 80103290 74004010 */  beqz       $v0, .L80103464
    /* A94 80103294 1080023C */   lui       $v0, %hi(jtbl_80102810)
    /* A98 80103298 10284224 */  addiu      $v0, $v0, %lo(jtbl_80102810)
    /* A9C 8010329C 80180300 */  sll        $v1, $v1, 2
    /* AA0 801032A0 21186200 */  addu       $v1, $v1, $v0
    /* AA4 801032A4 0000628C */  lw         $v0, 0x0($v1)
    /* AA8 801032A8 00000000 */  nop
    /* AAC 801032AC 08004000 */  jr         $v0
    /* AB0 801032B0 00000000 */   nop
    /* AB4 801032B4 74EA030C */  jal        vs_mainmenu_ready
    /* AB8 801032B8 00000000 */   nop
    /* ABC 801032BC 6A004010 */  beqz       $v0, .L80103468
    /* AC0 801032C0 21100000 */   addu      $v0, $zero, $zero
    /* AC4 801032C4 F2FE030C */  jal        func_800FFBC8
    /* AC8 801032C8 00000000 */   nop
    /* ACC 801032CC 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* AD0 801032D0 FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* AD4 801032D4 00000000 */  nop
    /* AD8 801032D8 25004390 */  lbu        $v1, 0x25($v0)
    /* ADC 801032DC 1080023C */  lui        $v0, %hi(D_80104518)
    /* AE0 801032E0 184543AC */  sw         $v1, %lo(D_80104518)($v0)
    /* AE4 801032E4 1080023C */  lui        $v0, %hi(D_80104518)
    /* AE8 801032E8 1845448C */  lw         $a0, %lo(D_80104518)($v0)
    /* AEC 801032EC C30C0408 */  j          .L8010330C
    /* AF0 801032F0 00000000 */   nop
    /* AF4 801032F4 7F0C040C */  jal        _setMenuTitle
    /* AF8 801032F8 00000000 */   nop
    /* AFC 801032FC 1080023C */  lui        $v0, %hi(D_80104518)
    /* B00 80103300 1845448C */  lw         $a0, %lo(D_80104518)($v0)
    /* B04 80103304 00000000 */  nop
    /* B08 80103308 10008434 */  ori        $a0, $a0, 0x10
  .L8010330C:
    /* B0C 8010330C 930A040C */  jal        _drawArtsList
    /* B10 80103310 00000000 */   nop
    /* B14 80103314 06000224 */  addiu      $v0, $zero, 0x6
    /* B18 80103318 190D0408 */  j          .L80103464
    /* B1C 8010331C 000002A2 */   sb        $v0, 0x0($s0)
    /* B20 80103320 930A040C */  jal        _drawArtsList
    /* B24 80103324 21200000 */   addu      $a0, $zero, $zero
    /* B28 80103328 21184000 */  addu       $v1, $v0, $zero
    /* B2C 8010332C 4E006010 */  beqz       $v1, .L80103468
    /* B30 80103330 21100000 */   addu      $v0, $zero, $zero
    /* B34 80103334 10006018 */  blez       $v1, .L80103378
    /* B38 80103338 FFFF0234 */   ori       $v0, $zero, 0xFFFF
    /* B3C 8010333C 07006214 */  bne        $v1, $v0, .L8010335C
    /* B40 80103340 0F80023C */   lui       $v0, %hi(D_800F4E98 + 0x4)
    /* B44 80103344 07000224 */  addiu      $v0, $zero, 0x7
    /* B48 80103348 000002A2 */  sb         $v0, 0x0($s0)
    /* B4C 8010334C DA0B040C */  jal        _drawWeaponTypeList
    /* B50 80103350 01000424 */   addiu     $a0, $zero, 0x1
    /* B54 80103354 1A0D0408 */  j          .L80103468
    /* B58 80103358 21100000 */   addu      $v0, $zero, $zero
  .L8010335C:
    /* B5C 8010335C 9C4E43AC */  sw         $v1, %lo(D_800F4E98 + 0x4)($v0)
    /* B60 80103360 0F80033C */  lui        $v1, %hi(vs_battle_executeAbilityType)
    /* B64 80103364 05000224 */  addiu      $v0, $zero, 0x5
    /* B68 80103368 C25162A0 */  sb         $v0, %lo(vs_battle_executeAbilityType)($v1)
    /* B6C 8010336C 09000224 */  addiu      $v0, $zero, 0x9
    /* B70 80103370 190D0408 */  j          .L80103464
    /* B74 80103374 000002A2 */   sb        $v0, 0x0($s0)
  .L80103378:
    /* B78 80103378 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* B7C 8010337C 0A006210 */  beq        $v1, $v0, .L801033A8
    /* B80 80103380 08000224 */   addiu     $v0, $zero, 0x8
    /* B84 80103384 190D0408 */  j          .L80103464
    /* B88 80103388 000002A2 */   sb        $v0, 0x0($s0)
    /* B8C 8010338C DA0B040C */  jal        _drawWeaponTypeList
    /* B90 80103390 21200000 */   addu      $a0, $zero, $zero
    /* B94 80103394 21184000 */  addu       $v1, $v0, $zero
    /* B98 80103398 32006010 */  beqz       $v1, .L80103464
    /* B9C 8010339C FEFF0224 */   addiu     $v0, $zero, -0x2
    /* BA0 801033A0 04006214 */  bne        $v1, $v0, .L801033B4
    /* BA4 801033A4 00000000 */   nop
  .L801033A8:
    /* BA8 801033A8 0A000224 */  addiu      $v0, $zero, 0xA
    /* BAC 801033AC 190D0408 */  j          .L80103464
    /* BB0 801033B0 000002A2 */   sb        $v0, 0x0($s0)
  .L801033B4:
    /* BB4 801033B4 02006018 */  blez       $v1, .L801033C0
    /* BB8 801033B8 1080023C */   lui       $v0, %hi(D_80104518)
    /* BBC 801033BC 184543AC */  sw         $v1, %lo(D_80104518)($v0)
  .L801033C0:
    /* BC0 801033C0 04000224 */  addiu      $v0, $zero, 0x4
    /* BC4 801033C4 190D0408 */  j          .L80103464
    /* BC8 801033C8 000002A2 */   sb        $v0, 0x0($s0)
    /* BCC 801033CC EAFE030C */  jal        func_800FFBA8
    /* BD0 801033D0 00000000 */   nop
    /* BD4 801033D4 A2FE030C */  jal        func_800FFA88
    /* BD8 801033D8 21200000 */   addu      $a0, $zero, $zero
    /* BDC 801033DC 74EA030C */  jal        vs_mainmenu_ready
    /* BE0 801033E0 00000000 */   nop
    /* BE4 801033E4 1F004010 */  beqz       $v0, .L80103464
    /* BE8 801033E8 01000224 */   addiu     $v0, $zero, 0x1
    /* BEC 801033EC 1A0D0408 */  j          .L80103468
    /* BF0 801033F0 000000A2 */   sb        $zero, 0x0($s0)
    /* BF4 801033F4 74EA030C */  jal        vs_mainmenu_ready
    /* BF8 801033F8 00000000 */   nop
    /* BFC 801033FC 19004010 */  beqz       $v0, .L80103464
    /* C00 80103400 01000224 */   addiu     $v0, $zero, 0x1
    /* C04 80103404 0F80043C */  lui        $a0, %hi(D_800F4E98 + 0x2)
    /* C08 80103408 06000324 */  addiu      $v1, $zero, 0x6
    /* C0C 8010340C 9A4E83A4 */  sh         $v1, %lo(D_800F4E98 + 0x2)($a0)
    /* C10 80103410 0F80033C */  lui        $v1, %hi(vs_battle_menuState)
    /* C14 80103414 C0516590 */  lbu        $a1, %lo(vs_battle_menuState)($v1)
    /* C18 80103418 02000424 */  addiu      $a0, $zero, 0x2
    /* C1C 8010341C C05164A0 */  sb         $a0, %lo(vs_battle_menuState)($v1)
    /* C20 80103420 C0516324 */  addiu      $v1, $v1, %lo(vs_battle_menuState)
    /* C24 80103424 010065A0 */  sb         $a1, 0x1($v1)
    /* C28 80103428 1A0D0408 */  j          .L80103468
    /* C2C 8010342C 000000A2 */   sb        $zero, 0x0($s0)
    /* C30 80103430 EAFE030C */  jal        func_800FFBA8
    /* C34 80103434 00000000 */   nop
    /* C38 80103438 A2FE030C */  jal        func_800FFA88
    /* C3C 8010343C 21200000 */   addu      $a0, $zero, $zero
    /* C40 80103440 74EA030C */  jal        vs_mainmenu_ready
    /* C44 80103444 00000000 */   nop
    /* C48 80103448 06004010 */  beqz       $v0, .L80103464
    /* C4C 8010344C 01000224 */   addiu     $v0, $zero, 0x1
    /* C50 80103450 0F80043C */  lui        $a0, %hi(vs_battle_menuState)
    /* C54 80103454 02000324 */  addiu      $v1, $zero, 0x2
    /* C58 80103458 C05183A0 */  sb         $v1, %lo(vs_battle_menuState)($a0)
    /* C5C 8010345C 1A0D0408 */  j          .L80103468
    /* C60 80103460 000000A2 */   sb        $zero, 0x0($s0)
  .L80103464:
    /* C64 80103464 21100000 */  addu       $v0, $zero, $zero
  .L80103468:
    /* C68 80103468 1400BF8F */  lw         $ra, 0x14($sp)
    /* C6C 8010346C 1000B08F */  lw         $s0, 0x10($sp)
    /* C70 80103470 0800E003 */  jr         $ra
    /* C74 80103474 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_menu1_exec
