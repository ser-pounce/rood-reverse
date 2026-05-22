nonmatching _memcardEventHandler, 0x254

glabel _memcardEventHandler
    /* BDC 801033DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* BE0 801033E0 21188000 */  addu       $v1, $a0, $zero
    /* BE4 801033E4 1400BFAF */  sw         $ra, 0x14($sp)
    /* BE8 801033E8 0B006010 */  beqz       $v1, .L80103418
    /* BEC 801033EC 1000B0AF */   sw        $s0, 0x10($sp)
    /* BF0 801033F0 21100000 */  addu       $v0, $zero, $zero
    /* BF4 801033F4 1180043C */  lui        $a0, %hi(_memcardEventHandlerPort)
    /* BF8 801033F8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* BFC 801033FC 00190300 */  sll        $v1, $v1, 4
    /* C00 80103400 81AA83A0 */  sb         $v1, %lo(_memcardEventHandlerPort)($a0)
    /* C04 80103404 1180033C */  lui        $v1, %hi(_memcardEventHandlerState)
    /* C08 80103408 80AA60A0 */  sb         $zero, %lo(_memcardEventHandlerState)($v1)
    /* C0C 8010340C 1180033C */  lui        $v1, %hi(_memcardEventHandlerInitTimeout)
    /* C10 80103410 880D0408 */  j          .L80103620
    /* C14 80103414 82AA60A0 */   sb        $zero, %lo(_memcardEventHandlerInitTimeout)($v1)
  .L80103418:
    /* C18 80103418 1180023C */  lui        $v0, %hi(_memcardEventHandlerState)
    /* C1C 8010341C 80AA4390 */  lbu        $v1, %lo(_memcardEventHandlerState)($v0)
    /* C20 80103420 00000000 */  nop
    /* C24 80103424 0600622C */  sltiu      $v0, $v1, 0x6
    /* C28 80103428 7C004010 */  beqz       $v0, .L8010361C
    /* C2C 8010342C 1080023C */   lui       $v0, %hi(jtbl_80102828)
    /* C30 80103430 28284224 */  addiu      $v0, $v0, %lo(jtbl_80102828)
    /* C34 80103434 80180300 */  sll        $v1, $v1, 2
    /* C38 80103438 21186200 */  addu       $v1, $v1, $v0
    /* C3C 8010343C 0000628C */  lw         $v0, 0x0($v1)
    /* C40 80103440 00000000 */  nop
    /* C44 80103444 08004000 */  jr         $v0
    /* C48 80103448 00000000 */   nop
    /* C4C 8010344C 1180033C */  lui        $v1, %hi(_memcardEventHandlerInitTimeout)
    /* C50 80103450 82AA6290 */  lbu        $v0, %lo(_memcardEventHandlerInitTimeout)($v1)
    /* C54 80103454 00000000 */  nop
    /* C58 80103458 01004224 */  addiu      $v0, $v0, 0x1
    /* C5C 8010345C 82AA62A0 */  sb         $v0, %lo(_memcardEventHandlerInitTimeout)($v1)
    /* C60 80103460 FF004230 */  andi       $v0, $v0, 0xFF
    /* C64 80103464 0400422C */  sltiu      $v0, $v0, 0x4
    /* C68 80103468 6D004010 */  beqz       $v0, .L80103620
    /* C6C 8010346C 02000224 */   addiu     $v0, $zero, 0x2
    /* C70 80103470 B70A040C */  jal        _resetMemcardEvents
    /* C74 80103474 21200000 */   addu      $a0, $zero, $zero
    /* C78 80103478 1180023C */  lui        $v0, %hi(_memcardEventHandlerPort)
    /* C7C 8010347C 81AA4490 */  lbu        $a0, %lo(_memcardEventHandlerPort)($v0)
    /* C80 80103480 2DBA000C */  jal        _card_info
    /* C84 80103484 00000000 */   nop
    /* C88 80103488 64004010 */  beqz       $v0, .L8010361C
    /* C8C 8010348C 1180033C */   lui       $v1, %hi(_memcardEventHandlerState)
    /* C90 80103490 01000224 */  addiu      $v0, $zero, 0x1
    /* C94 80103494 80AA62A0 */  sb         $v0, %lo(_memcardEventHandlerState)($v1)
    /* C98 80103498 1180023C */  lui        $v0, %hi(_memcardEventHandlerTimeout)
    /* C9C 8010349C 83AA40A0 */  sb         $zero, %lo(_memcardEventHandlerTimeout)($v0)
    /* CA0 801034A0 1180023C */  lui        $v0, %hi(_memcardEventHandlerEventType)
    /* CA4 801034A4 84AA40A0 */  sb         $zero, %lo(_memcardEventHandlerEventType)($v0)
    /* CA8 801034A8 980A040C */  jal        _testMemcardEvents
    /* CAC 801034AC 21200000 */   addu      $a0, $zero, $zero
    /* CB0 801034B0 21184000 */  addu       $v1, $v0, $zero
    /* CB4 801034B4 0500622C */  sltiu      $v0, $v1, 0x5
    /* CB8 801034B8 58004010 */  beqz       $v0, .L8010361C
    /* CBC 801034BC 1080023C */   lui       $v0, %hi(jtbl_80102840)
    /* CC0 801034C0 40284224 */  addiu      $v0, $v0, %lo(jtbl_80102840)
    /* CC4 801034C4 80180300 */  sll        $v1, $v1, 2
    /* CC8 801034C8 21186200 */  addu       $v1, $v1, $v0
    /* CCC 801034CC 0000628C */  lw         $v0, 0x0($v1)
    /* CD0 801034D0 00000000 */  nop
    /* CD4 801034D4 08004000 */  jr         $v0
    /* CD8 801034D8 00000000 */   nop
    /* CDC 801034DC 1180033C */  lui        $v1, %hi(_memcardEventHandlerState)
    /* CE0 801034E0 02000224 */  addiu      $v0, $zero, 0x2
    /* CE4 801034E4 870D0408 */  j          .L8010361C
    /* CE8 801034E8 80AA62A0 */   sb        $v0, %lo(_memcardEventHandlerState)($v1)
    /* CEC 801034EC B70A040C */  jal        _resetMemcardEvents
    /* CF0 801034F0 04000424 */   addiu     $a0, $zero, 0x4
    /* CF4 801034F4 1180023C */  lui        $v0, %hi(_memcardEventHandlerPort)
    /* CF8 801034F8 81AA4490 */  lbu        $a0, %lo(_memcardEventHandlerPort)($v0)
    /* CFC 801034FC 35BA000C */  jal        _card_clear
    /* D00 80103500 00000000 */   nop
    /* D04 80103504 45004010 */  beqz       $v0, .L8010361C
    /* D08 80103508 1180033C */   lui       $v1, %hi(_memcardEventHandlerState)
    /* D0C 8010350C 03000224 */  addiu      $v0, $zero, 0x3
    /* D10 80103510 80AA62A0 */  sb         $v0, %lo(_memcardEventHandlerState)($v1)
    /* D14 80103514 1180023C */  lui        $v0, %hi(_memcardEventHandlerTimeout)
    /* D18 80103518 1180033C */  lui        $v1, %hi(_memcardEventHandlerEventType)
    /* D1C 8010351C 83AA40A0 */  sb         $zero, %lo(_memcardEventHandlerTimeout)($v0)
    /* D20 80103520 04000224 */  addiu      $v0, $zero, 0x4
    /* D24 80103524 84AA62A0 */  sb         $v0, %lo(_memcardEventHandlerEventType)($v1)
    /* D28 80103528 04001024 */  addiu      $s0, $zero, 0x4
  .L8010352C:
    /* D2C 8010352C 980A040C */  jal        _testMemcardEvents
    /* D30 80103530 04000424 */   addiu     $a0, $zero, 0x4
    /* D34 80103534 21184000 */  addu       $v1, $v0, $zero
    /* D38 80103538 FCFF7010 */  beq        $v1, $s0, .L8010352C
    /* D3C 8010353C 00000000 */   nop
    /* D40 80103540 05006014 */  bnez       $v1, .L80103558
    /* D44 80103544 00000000 */   nop
    /* D48 80103548 1180033C */  lui        $v1, %hi(_memcardEventHandlerState)
    /* D4C 8010354C 04000224 */  addiu      $v0, $zero, 0x4
    /* D50 80103550 870D0408 */  j          .L8010361C
    /* D54 80103554 80AA62A0 */   sb        $v0, %lo(_memcardEventHandlerState)($v1)
  .L80103558:
    /* D58 80103558 30006004 */  bltz       $v1, .L8010361C
    /* D5C 8010355C 04006228 */   slti      $v0, $v1, 0x4
    /* D60 80103560 2E004010 */  beqz       $v0, .L8010361C
    /* D64 80103564 1180023C */   lui       $v0, %hi(_memcardEventHandlerState)
    /* D68 80103568 870D0408 */  j          .L8010361C
    /* D6C 8010356C 80AA40A0 */   sb        $zero, %lo(_memcardEventHandlerState)($v0)
    /* D70 80103570 B70A040C */  jal        _resetMemcardEvents
    /* D74 80103574 21200000 */   addu      $a0, $zero, $zero
    /* D78 80103578 1180023C */  lui        $v0, %hi(_memcardEventHandlerPort)
    /* D7C 8010357C 81AA4490 */  lbu        $a0, %lo(_memcardEventHandlerPort)($v0)
    /* D80 80103580 31BA000C */  jal        _card_load
    /* D84 80103584 00000000 */   nop
    /* D88 80103588 24004010 */  beqz       $v0, .L8010361C
    /* D8C 8010358C 1180023C */   lui       $v0, %hi(_memcardEventHandlerState)
    /* D90 80103590 05000324 */  addiu      $v1, $zero, 0x5
    /* D94 80103594 80AA43A0 */  sb         $v1, %lo(_memcardEventHandlerState)($v0)
    /* D98 80103598 1180023C */  lui        $v0, %hi(_memcardEventHandlerTimeout)
    /* D9C 8010359C 83AA40A0 */  sb         $zero, %lo(_memcardEventHandlerTimeout)($v0)
    /* DA0 801035A0 980A040C */  jal        _testMemcardEvents
    /* DA4 801035A4 21200000 */   addu      $a0, $zero, $zero
    /* DA8 801035A8 21184000 */  addu       $v1, $v0, $zero
    /* DAC 801035AC 0500622C */  sltiu      $v0, $v1, 0x5
    /* DB0 801035B0 1A004010 */  beqz       $v0, .L8010361C
    /* DB4 801035B4 1080023C */   lui       $v0, %hi(jtbl_80102858)
    /* DB8 801035B8 58284224 */  addiu      $v0, $v0, %lo(jtbl_80102858)
    /* DBC 801035BC 80180300 */  sll        $v1, $v1, 2
    /* DC0 801035C0 21186200 */  addu       $v1, $v1, $v0
    /* DC4 801035C4 0000628C */  lw         $v0, 0x0($v1)
    /* DC8 801035C8 00000000 */  nop
    /* DCC 801035CC 08004000 */  jr         $v0
    /* DD0 801035D0 00000000 */   nop
    /* DD4 801035D4 1180023C */  lui        $v0, %hi(_memcardEventHandlerEventType)
    /* DD8 801035D8 84AA4290 */  lbu        $v0, %lo(_memcardEventHandlerEventType)($v0)
    /* DDC 801035DC 880D0408 */  j          .L80103620
    /* DE0 801035E0 01004224 */   addiu     $v0, $v0, 0x1
    /* DE4 801035E4 1180023C */  lui        $v0, %hi(_memcardEventHandlerEventType)
    /* DE8 801035E8 84AA4290 */  lbu        $v0, %lo(_memcardEventHandlerEventType)($v0)
    /* DEC 801035EC 880D0408 */  j          .L80103620
    /* DF0 801035F0 03004224 */   addiu     $v0, $v0, 0x3
    /* DF4 801035F4 1180023C */  lui        $v0, %hi(_memcardEventHandlerTimeout)
    /* DF8 801035F8 83AA4390 */  lbu        $v1, %lo(_memcardEventHandlerTimeout)($v0)
    /* DFC 801035FC 00000000 */  nop
    /* E00 80103600 01006424 */  addiu      $a0, $v1, 0x1
    /* E04 80103604 FF006330 */  andi       $v1, $v1, 0xFF
    /* E08 80103608 4100632C */  sltiu      $v1, $v1, 0x41
    /* E0C 8010360C 03006014 */  bnez       $v1, .L8010361C
    /* E10 80103610 83AA44A0 */   sb        $a0, %lo(_memcardEventHandlerTimeout)($v0)
    /* E14 80103614 1180023C */  lui        $v0, %hi(_memcardEventHandlerState)
    /* E18 80103618 80AA40A0 */  sb         $zero, %lo(_memcardEventHandlerState)($v0)
  .L8010361C:
    /* E1C 8010361C 21100000 */  addu       $v0, $zero, $zero
  .L80103620:
    /* E20 80103620 1400BF8F */  lw         $ra, 0x14($sp)
    /* E24 80103624 1000B08F */  lw         $s0, 0x10($sp)
    /* E28 80103628 0800E003 */  jr         $ra
    /* E2C 8010362C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _memcardEventHandler
