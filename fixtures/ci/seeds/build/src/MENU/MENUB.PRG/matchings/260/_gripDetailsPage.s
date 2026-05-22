nonmatching _gripDetailsPage, 0x240

glabel _gripDetailsPage
    /* AF8 801032F8 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* AFC 801032FC 21288000 */  addu       $a1, $a0, $zero
    /* B00 80103300 2800BFAF */  sw         $ra, 0x28($sp)
    /* B04 80103304 2400B1AF */  sw         $s1, 0x24($sp)
    /* B08 80103308 1100A010 */  beqz       $a1, .L80103350
    /* B0C 8010330C 2000B0AF */   sw        $s0, 0x20($sp)
    /* B10 80103310 1180033C */  lui        $v1, %hi(D_8010A5F7)
    /* B14 80103314 03120500 */  sra        $v0, $a1, 8
    /* B18 80103318 F7A562A0 */  sb         $v0, %lo(D_8010A5F7)($v1)
    /* B1C 8010331C FF004430 */  andi       $a0, $v0, 0xFF
    /* B20 80103320 1180033C */  lui        $v1, %hi(D_8010A5F8)
    /* B24 80103324 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* B28 80103328 140B040C */  jal        func_80102C50
    /* B2C 8010332C F8A562A0 */   sb        $v0, %lo(D_8010A5F8)($v1)
    /* B30 80103330 21100000 */  addu       $v0, $zero, $zero
    /* B34 80103334 1180033C */  lui        $v1, %hi(D_8010A5F9)
    /* B38 80103338 F9A560A0 */  sb         $zero, %lo(D_8010A5F9)($v1)
    /* B3C 8010333C 1180033C */  lui        $v1, %hi(D_8010A5F6)
    /* B40 80103340 F6A560A0 */  sb         $zero, %lo(D_8010A5F6)($v1)
    /* B44 80103344 1180033C */  lui        $v1, %hi(D_8010A5F5)
    /* B48 80103348 490D0408 */  j          .L80103524
    /* B4C 8010334C F5A560A0 */   sb        $zero, %lo(D_8010A5F5)($v1)
  .L80103350:
    /* B50 80103350 1180103C */  lui        $s0, %hi(D_8010A5F5)
    /* B54 80103354 F5A50392 */  lbu        $v1, %lo(D_8010A5F5)($s0)
    /* B58 80103358 01001124 */  addiu      $s1, $zero, 0x1
    /* B5C 8010335C 1E007110 */  beq        $v1, $s1, .L801033D8
    /* B60 80103360 02006228 */   slti      $v0, $v1, 0x2
    /* B64 80103364 05004010 */  beqz       $v0, .L8010337C
    /* B68 80103368 02000224 */   addiu     $v0, $zero, 0x2
    /* B6C 8010336C 09006010 */  beqz       $v1, .L80103394
    /* B70 80103370 21100000 */   addu      $v0, $zero, $zero
    /* B74 80103374 490D0408 */  j          .L80103524
    /* B78 80103378 00000000 */   nop
  .L8010337C:
    /* B7C 8010337C 21006210 */  beq        $v1, $v0, .L80103404
    /* B80 80103380 03000224 */   addiu     $v0, $zero, 0x3
    /* B84 80103384 62006210 */  beq        $v1, $v0, .L80103510
    /* B88 80103388 21100000 */   addu      $v0, $zero, $zero
    /* B8C 8010338C 490D0408 */  j          .L80103524
    /* B90 80103390 00000000 */   nop
  .L80103394:
    /* B94 80103394 74EA030C */  jal        vs_mainmenu_ready
    /* B98 80103398 00000000 */   nop
    /* B9C 8010339C 60004010 */  beqz       $v0, .L80103520
    /* BA0 801033A0 1180023C */   lui       $v0, %hi(D_8010A5F7)
    /* BA4 801033A4 F7A54490 */  lbu        $a0, %lo(D_8010A5F7)($v0)
    /* BA8 801033A8 470B040C */  jal        _initMenuLayout
    /* BAC 801033AC 04000524 */   addiu     $a1, $zero, 0x4
    /* BB0 801033B0 0680033C */  lui        $v1, %hi(vs_main_inventoryIndices)
    /* BB4 801033B4 1180023C */  lui        $v0, %hi(D_8010A5F8)
    /* BB8 801033B8 F8A54290 */  lbu        $v0, %lo(D_8010A5F8)($v0)
    /* BBC 801033BC D8196324 */  addiu      $v1, $v1, %lo(vs_main_inventoryIndices)
    /* BC0 801033C0 21104300 */  addu       $v0, $v0, $v1
    /* BC4 801033C4 18004490 */  lbu        $a0, 0x18($v0)
    /* BC8 801033C8 41F5030C */  jal        vs_mainMenu_setUiGripStats
    /* BCC 801033CC 00000000 */   nop
    /* BD0 801033D0 480D0408 */  j          .L80103520
    /* BD4 801033D4 F5A511A2 */   sb        $s1, %lo(D_8010A5F5)($s0)
  .L801033D8:
    /* BD8 801033D8 1180043C */  lui        $a0, %hi(D_8010A5F6)
    /* BDC 801033DC F6A58390 */  lbu        $v1, %lo(D_8010A5F6)($a0)
    /* BE0 801033E0 00000000 */  nop
    /* BE4 801033E4 0A00622C */  sltiu      $v0, $v1, 0xA
    /* BE8 801033E8 03004010 */  beqz       $v0, .L801033F8
    /* BEC 801033EC 01006224 */   addiu     $v0, $v1, 0x1
    /* BF0 801033F0 480D0408 */  j          .L80103520
    /* BF4 801033F4 F6A582A0 */   sb        $v0, %lo(D_8010A5F6)($a0)
  .L801033F8:
    /* BF8 801033F8 02000224 */  addiu      $v0, $zero, 0x2
    /* BFC 801033FC 480D0408 */  j          .L80103520
    /* C00 80103400 F5A502A2 */   sb        $v0, %lo(D_8010A5F5)($s0)
  .L80103404:
    /* C04 80103404 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* C08 80103408 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* C0C 8010340C 00000000 */  nop
    /* C10 80103410 50004230 */  andi       $v0, $v0, 0x50
    /* C14 80103414 06004010 */  beqz       $v0, .L80103430
    /* C18 80103418 00000000 */   nop
    /* C1C 8010341C 950B040C */  jal        _initMenuLeave
    /* C20 80103420 21200000 */   addu      $a0, $zero, $zero
    /* C24 80103424 03000224 */  addiu      $v0, $zero, 0x3
    /* C28 80103428 290D0408 */  j          .L801034A4
    /* C2C 8010342C F5A502A2 */   sb        $v0, %lo(D_8010A5F5)($s0)
  .L80103430:
    /* C30 80103430 1180103C */  lui        $s0, %hi(D_8010A5F8)
    /* C34 80103434 F8A50592 */  lbu        $a1, %lo(D_8010A5F8)($s0)
    /* C38 80103438 980A040C */  jal        _handleItemPaging
    /* C3C 8010343C 02000424 */   addiu     $a0, $zero, 0x2
    /* C40 80103440 F8A50392 */  lbu        $v1, %lo(D_8010A5F8)($s0)
    /* C44 80103444 21884000 */  addu       $s1, $v0, $zero
    /* C48 80103448 16002312 */  beq        $s1, $v1, .L801034A4
    /* C4C 8010344C 02000424 */   addiu     $a0, $zero, 0x2
    /* C50 80103450 21282002 */  addu       $a1, $s1, $zero
    /* C54 80103454 820B040C */  jal        _getItemIndex
    /* C58 80103458 F8A511A2 */   sb        $s1, %lo(D_8010A5F8)($s0)
    /* C5C 8010345C 21804000 */  addu       $s0, $v0, $zero
    /* C60 80103460 00111000 */  sll        $v0, $s0, 4
    /* C64 80103464 0680043C */  lui        $a0, %hi(D_80060698)
    /* C68 80103468 98068424 */  addiu      $a0, $a0, %lo(D_80060698)
    /* C6C 8010346C 21204400 */  addu       $a0, $v0, $a0
    /* C70 80103470 1000A527 */  addiu      $a1, $sp, 0x10
    /* C74 80103474 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* C78 80103478 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* C7C 8010347C 03F3030C */  jal        vs_mainMenu_setUiGrip
    /* C80 80103480 1800A627 */   addiu     $a2, $sp, 0x18
    /* C84 80103484 41F5030C */  jal        vs_mainMenu_setUiGripStats
    /* C88 80103488 21200002 */   addu      $a0, $s0, $zero
    /* C8C 8010348C 1000A527 */  addiu      $a1, $sp, 0x10
    /* C90 80103490 1180023C */  lui        $v0, %hi(D_8010A5F7)
    /* C94 80103494 F7A54490 */  lbu        $a0, %lo(D_8010A5F7)($v0)
    /* C98 80103498 1800A68F */  lw         $a2, 0x18($sp)
    /* C9C 8010349C 5B0B040C */  jal        _setSubMenu
    /* CA0 801034A0 21382002 */   addu      $a3, $s1, $zero
  .L801034A4:
    /* CA4 801034A4 16010424 */  addiu      $a0, $zero, 0x116
    /* CA8 801034A8 00010524 */  addiu      $a1, $zero, 0x100
    /* CAC 801034AC 20000624 */  addiu      $a2, $zero, 0x20
    /* CB0 801034B0 1180103C */  lui        $s0, %hi(D_8010A510)
    /* CB4 801034B4 0680073C */  lui        $a3, %hi(vs_battle_inventory)
    /* CB8 801034B8 0680033C */  lui        $v1, %hi(vs_main_inventoryIndices)
    /* CBC 801034BC 1180023C */  lui        $v0, %hi(D_8010A5F8)
    /* CC0 801034C0 F8A54290 */  lbu        $v0, %lo(D_8010A5F8)($v0)
    /* CC4 801034C4 D8196324 */  addiu      $v1, $v1, %lo(vs_main_inventoryIndices)
    /* CC8 801034C8 21104300 */  addu       $v0, $v0, $v1
    /* CCC 801034CC 18004290 */  lbu        $v0, 0x18($v0)
    /* CD0 801034D0 6801E724 */  addiu      $a3, $a3, %lo(vs_battle_inventory)
    /* CD4 801034D4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* CD8 801034D8 00110200 */  sll        $v0, $v0, 4
    /* CDC 801034DC 21104700 */  addu       $v0, $v0, $a3
    /* CE0 801034E0 44054290 */  lbu        $v0, 0x544($v0)
    /* CE4 801034E4 10A5038E */  lw         $v1, %lo(D_8010A510)($s0)
    /* CE8 801034E8 30004224 */  addiu      $v0, $v0, 0x30
    /* CEC 801034EC 0100040C */  jal        vs_mainMenu_drawRowIcon
    /* CF0 801034F0 060062A0 */   sb        $v0, 0x6($v1)
    /* CF4 801034F4 2400053C */  lui        $a1, (0x240118 >> 16)
    /* CF8 801034F8 1801A534 */  ori        $a1, $a1, (0x240118 & 0xFFFF)
    /* CFC 801034FC 10A5048E */  lw         $a0, %lo(D_8010A510)($s0)
    /* D00 80103500 0A1A030C */  jal        vs_battle_renderTextRaw
    /* D04 80103504 21300000 */   addu      $a2, $zero, $zero
    /* D08 80103508 490D0408 */  j          .L80103524
    /* D0C 8010350C 21100000 */   addu      $v0, $zero, $zero
  .L80103510:
    /* D10 80103510 74EA030C */  jal        vs_mainmenu_ready
    /* D14 80103514 00000000 */   nop
    /* D18 80103518 490D0408 */  j          .L80103524
    /* D1C 8010351C 00000000 */   nop
  .L80103520:
    /* D20 80103520 21100000 */  addu       $v0, $zero, $zero
  .L80103524:
    /* D24 80103524 2800BF8F */  lw         $ra, 0x28($sp)
    /* D28 80103528 2400B18F */  lw         $s1, 0x24($sp)
    /* D2C 8010352C 2000B08F */  lw         $s0, 0x20($sp)
    /* D30 80103530 0800E003 */  jr         $ra
    /* D34 80103534 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _gripDetailsPage
