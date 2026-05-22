nonmatching _handleMenu, 0x177C

glabel _handleMenu
    /* B7C 8010337C 1180023C */  lui        $v0, %hi(_menuState)
    /* B80 80103380 3CA4438C */  lw         $v1, %lo(_menuState)($v0)
    /* B84 80103384 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* B88 80103388 4800BFAF */  sw         $ra, 0x48($sp)
    /* B8C 8010338C 4400B1AF */  sw         $s1, 0x44($sp)
    /* B90 80103390 1C00622C */  sltiu      $v0, $v1, 0x1C
    /* B94 80103394 D2054010 */  beqz       $v0, .L80104AE0
    /* B98 80103398 4000B0AF */   sw        $s0, 0x40($sp)
    /* B9C 8010339C 1080023C */  lui        $v0, %hi(jtbl_80102898)
    /* BA0 801033A0 98284224 */  addiu      $v0, $v0, %lo(jtbl_80102898)
    /* BA4 801033A4 80180300 */  sll        $v1, $v1, 2
    /* BA8 801033A8 21186200 */  addu       $v1, $v1, $v0
    /* BAC 801033AC 0000628C */  lw         $v0, 0x0($v1)
    /* BB0 801033B0 00000000 */  nop
    /* BB4 801033B4 08004000 */  jr         $v0
    /* BB8 801033B8 00000000 */   nop
    /* BBC 801033BC FF070424 */  addiu      $a0, $zero, 0x7FF
    /* BC0 801033C0 0501040C */  jal        func_80100414
    /* BC4 801033C4 80000524 */   addiu     $a1, $zero, 0x80
    /* BC8 801033C8 1180033C */  lui        $v1, %hi(_menuState)
    /* BCC 801033CC 3CA4628C */  lw         $v0, %lo(_menuState)($v1)
    /* BD0 801033D0 B7120408 */  j          .L80104ADC
    /* BD4 801033D4 01004224 */   addiu     $v0, $v0, 0x1
    /* BD8 801033D8 89E6030C */  jal        func_800F9A24
    /* BDC 801033DC 21200000 */   addu      $a0, $zero, $zero
    /* BE0 801033E0 3220040C */  jal        func_801080C8
    /* BE4 801033E4 00000000 */   nop
    /* BE8 801033E8 21200000 */  addu       $a0, $zero, $zero
    /* BEC 801033EC 21288000 */  addu       $a1, $a0, $zero
    /* BF0 801033F0 1180033C */  lui        $v1, %hi(D_8010A444)
    /* BF4 801033F4 50010224 */  addiu      $v0, $zero, 0x150
    /* BF8 801033F8 44A462AC */  sw         $v0, %lo(D_8010A444)($v1)
    /* BFC 801033FC 1180033C */  lui        $v1, %hi(D_8010A44E)
    /* C00 80103400 6B000224 */  addiu      $v0, $zero, 0x6B
    /* C04 80103404 4EA462A4 */  sh         $v0, %lo(D_8010A44E)($v1)
    /* C08 80103408 0F80023C */  lui        $v0, %hi(D_800F453C)
    /* C0C 8010340C 1180033C */  lui        $v1, %hi(D_8010A430)
    /* C10 80103410 3C45428C */  lw         $v0, %lo(D_800F453C)($v0)
    /* C14 80103414 F8000724 */  addiu      $a3, $zero, 0xF8
    /* C18 80103418 56064694 */  lhu        $a2, 0x656($v0)
    /* C1C 8010341C 400F0224 */  addiu      $v0, $zero, 0xF40
    /* C20 80103420 30A462A4 */  sh         $v0, %lo(D_8010A430)($v1)
    /* C24 80103424 30A46324 */  addiu      $v1, $v1, %lo(D_8010A430)
    /* C28 80103428 470E0224 */  addiu      $v0, $zero, 0xE47
    /* C2C 8010342C 020062A4 */  sh         $v0, 0x2($v1)
    /* C30 80103430 10000224 */  addiu      $v0, $zero, 0x10
    /* C34 80103434 040060A4 */  sh         $zero, 0x4($v1)
    /* C38 80103438 1000A2AF */  sw         $v0, 0x10($sp)
    /* C3C 8010343C 01000224 */  addiu      $v0, $zero, 0x1
    /* C40 80103440 1400A2AF */  sw         $v0, 0x14($sp)
    /* C44 80103444 0B000224 */  addiu      $v0, $zero, 0xB
    /* C48 80103448 1800A2AF */  sw         $v0, 0x18($sp)
    /* C4C 8010344C F8000224 */  addiu      $v0, $zero, 0xF8
    /* C50 80103450 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* C54 80103454 1180023C */  lui        $v0, %hi(D_8010A44C)
    /* C58 80103458 4CA446A4 */  sh         $a2, %lo(D_8010A44C)($v0)
    /* C5C 8010345C C233030C */  jal        vs_battle_initTextBox
    /* C60 80103460 0B000624 */   addiu     $a2, $zero, 0xB
    /* C64 80103464 1180033C */  lui        $v1, %hi(_rankText)
    /* C68 80103468 1180023C */  lui        $v0, %hi(_characterRank)
    /* C6C 8010346C 64A44294 */  lhu        $v0, %lo(_characterRank)($v0)
    /* C70 80103470 64856324 */  addiu      $v1, $v1, %lo(_rankText)
    /* C74 80103474 40100200 */  sll        $v0, $v0, 1
    /* C78 80103478 21104300 */  addu       $v0, $v0, $v1
    /* C7C 8010347C 00004594 */  lhu        $a1, 0x0($v0)
    /* C80 80103480 21200000 */  addu       $a0, $zero, $zero
    /* C84 80103484 40280500 */  sll        $a1, $a1, 1
    /* C88 80103488 FC1A030C */  jal        vs_battle_setTextBox
    /* C8C 8010348C 2128A300 */   addu      $a1, $a1, $v1
    /* C90 80103490 F412040C */  jal        _initStringsAndGetSelectedRow
    /* C94 80103494 01000424 */   addiu     $a0, $zero, 0x1
    /* C98 80103498 450F0408 */  j          .L80103D14
    /* C9C 8010349C 1180043C */   lui       $a0, %hi(_menuState)
    /* CA0 801034A0 1180103C */  lui        $s0, %hi(D_8010A220)
    /* CA4 801034A4 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* CA8 801034A8 4B15040C */  jal        func_8010552C
    /* CAC 801034AC 00000000 */   nop
    /* CB0 801034B0 20A2028E */  lw         $v0, %lo(D_8010A220)($s0)
    /* CB4 801034B4 00000000 */  nop
    /* CB8 801034B8 08004228 */  slti       $v0, $v0, 0x8
    /* CBC 801034BC 0D004010 */  beqz       $v0, .L801034F4
    /* CC0 801034C0 00000000 */   nop
    /* CC4 801034C4 7D33030C */  jal        vs_battle_getTextBox
    /* CC8 801034C8 21200000 */   addu      $a0, $zero, $zero
    /* CCC 801034CC 21204000 */  addu       $a0, $v0, $zero
    /* CD0 801034D0 16008294 */  lhu        $v0, 0x16($a0)
    /* CD4 801034D4 20A2038E */  lw         $v1, %lo(D_8010A220)($s0)
    /* CD8 801034D8 FAFF4224 */  addiu      $v0, $v0, -0x6
    /* CDC 801034DC 160082A4 */  sh         $v0, 0x16($a0)
    /* CE0 801034E0 12008294 */  lhu        $v0, 0x12($a0)
    /* CE4 801034E4 01006324 */  addiu      $v1, $v1, 0x1
    /* CE8 801034E8 20A203AE */  sw         $v1, %lo(D_8010A220)($s0)
    /* CEC 801034EC FAFF4224 */  addiu      $v0, $v0, -0x6
    /* CF0 801034F0 120082A4 */  sh         $v0, 0x12($a0)
  .L801034F4:
    /* CF4 801034F4 F412040C */  jal        _initStringsAndGetSelectedRow
    /* CF8 801034F8 21200000 */   addu      $a0, $zero, $zero
    /* CFC 801034FC 21184000 */  addu       $v1, $v0, $zero
    /* D00 80103500 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* D04 80103504 76056210 */  beq        $v1, $v0, .L80104AE0
    /* D08 80103508 FDFF0224 */   addiu     $v0, $zero, -0x3
    /* D0C 8010350C 04006214 */  bne        $v1, $v0, .L80103520
    /* D10 80103510 02000224 */   addiu     $v0, $zero, 0x2
    /* D14 80103514 1180033C */  lui        $v1, %hi(D_8010A440)
    /* D18 80103518 600D0408 */  j          .L80103580
    /* D1C 8010351C 40A462AC */   sw        $v0, %lo(D_8010A440)($v1)
  .L80103520:
    /* D20 80103520 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* D24 80103524 04006214 */  bne        $v1, $v0, .L80103538
    /* D28 80103528 01000224 */   addiu     $v0, $zero, 0x1
    /* D2C 8010352C 1180033C */  lui        $v1, %hi(D_8010A440)
    /* D30 80103530 600D0408 */  j          .L80103580
    /* D34 80103534 40A462AC */   sw        $v0, %lo(D_8010A440)($v1)
  .L80103538:
    /* D38 80103538 03000224 */  addiu      $v0, $zero, 0x3
    /* D3C 8010353C 0E006214 */  bne        $v1, $v0, .L80103578
    /* D40 80103540 1080103C */   lui       $s0, %hi(_monBinFile)
    /* D44 80103544 18281026 */  addiu      $s0, $s0, %lo(_monBinFile)
    /* D48 80103548 0400048E */  lw         $a0, 0x4($s0)
    /* D4C 8010354C 8F0F010C */  jal        vs_main_allocHeapR
    /* D50 80103550 00000000 */   nop
    /* D54 80103554 21200002 */  addu       $a0, $s0, $zero
    /* D58 80103558 1180103C */  lui        $s0, %hi(_monBinData)
    /* D5C 8010355C C412010C */  jal        vs_main_allocateCdQueueSlot
    /* D60 80103560 70A402AE */   sw        $v0, %lo(_monBinData)($s0)
    /* D64 80103564 21204000 */  addu       $a0, $v0, $zero
    /* D68 80103568 70A4058E */  lw         $a1, %lo(_monBinData)($s0)
    /* D6C 8010356C 1180023C */  lui        $v0, %hi(_monBinCdQueueSlot)
    /* D70 80103570 F112010C */  jal        vs_main_cdEnqueue
    /* D74 80103574 6CA444AC */   sw        $a0, %lo(_monBinCdQueueSlot)($v0)
  .L80103578:
    /* D78 80103578 1180023C */  lui        $v0, %hi(D_8010A440)
    /* D7C 8010357C 40A440AC */  sw         $zero, %lo(D_8010A440)($v0)
  .L80103580:
    /* D80 80103580 21200000 */  addu       $a0, $zero, $zero
    /* D84 80103584 0F80023C */  lui        $v0, %hi(D_800F4EE8)
    /* D88 80103588 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* D8C 8010358C 02004390 */  lbu        $v1, 0x2($v0)
    /* D90 80103590 03004290 */  lbu        $v0, 0x3($v0)
    /* D94 80103594 0F80053C */  lui        $a1, %hi(D_800F1BF7)
    /* D98 80103598 21186200 */  addu       $v1, $v1, $v0
    /* D9C 8010359C 1934030C */  jal        vs_battle_dismissTextBox
    /* DA0 801035A0 F71BA3A0 */   sb        $v1, %lo(D_800F1BF7)($a1)
    /* DA4 801035A4 1180033C */  lui        $v1, %hi(_menuState)
    /* DA8 801035A8 3CA4628C */  lw         $v0, %lo(_menuState)($v1)
    /* DAC 801035AC B7120408 */  j          .L80104ADC
    /* DB0 801035B0 01004224 */   addiu     $v0, $v0, 0x1
    /* DB4 801035B4 1180103C */  lui        $s0, %hi(D_8010A220)
    /* DB8 801035B8 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* DBC 801035BC 4B15040C */  jal        func_8010552C
    /* DC0 801035C0 00000000 */   nop
    /* DC4 801035C4 20A2028E */  lw         $v0, %lo(D_8010A220)($s0)
    /* DC8 801035C8 00000000 */  nop
    /* DCC 801035CC 0F004018 */  blez       $v0, .L8010360C
    /* DD0 801035D0 00000000 */   nop
    /* DD4 801035D4 7D33030C */  jal        vs_battle_getTextBox
    /* DD8 801035D8 21200000 */   addu      $a0, $zero, $zero
    /* DDC 801035DC 21204000 */  addu       $a0, $v0, $zero
    /* DE0 801035E0 07008010 */  beqz       $a0, .L80103600
    /* DE4 801035E4 00000000 */   nop
    /* DE8 801035E8 16008294 */  lhu        $v0, 0x16($a0)
    /* DEC 801035EC 12008394 */  lhu        $v1, 0x12($a0)
    /* DF0 801035F0 06004224 */  addiu      $v0, $v0, 0x6
    /* DF4 801035F4 06006324 */  addiu      $v1, $v1, 0x6
    /* DF8 801035F8 160082A4 */  sh         $v0, 0x16($a0)
    /* DFC 801035FC 120083A4 */  sh         $v1, 0x12($a0)
  .L80103600:
    /* E00 80103600 20A2028E */  lw         $v0, %lo(D_8010A220)($s0)
    /* E04 80103604 59120408 */  j          .L80104964
    /* E08 80103608 FFFF4224 */   addiu     $v0, $v0, -0x1
  .L8010360C:
    /* E0C 8010360C 83E7030C */  jal        func_800F9E0C
    /* E10 80103610 1180103C */   lui       $s0, %hi(D_8010A440)
    /* E14 80103614 40A4028E */  lw         $v0, %lo(D_8010A440)($s0)
    /* E18 80103618 00000000 */  nop
    /* E1C 8010361C 08004014 */  bnez       $v0, .L80103640
    /* E20 80103620 0F80023C */   lui       $v0, %hi(D_800F1BF7)
    /* E24 80103624 F71B4390 */  lbu        $v1, %lo(D_800F1BF7)($v0)
    /* E28 80103628 1180043C */  lui        $a0, %hi(_menuState)
    /* E2C 8010362C 40100300 */  sll        $v0, $v1, 1
    /* E30 80103630 21104300 */  addu       $v0, $v0, $v1
    /* E34 80103634 04004224 */  addiu      $v0, $v0, 0x4
    /* E38 80103638 B8120408 */  j          .L80104AE0
    /* E3C 8010363C 3CA482AC */   sw        $v0, %lo(_menuState)($a0)
  .L80103640:
    /* E40 80103640 BE12040C */  jal        func_80104AF8
    /* E44 80103644 00000000 */   nop
    /* E48 80103648 40A4028E */  lw         $v0, %lo(D_8010A440)($s0)
    /* E4C 8010364C B9120408 */  j          .L80104AE4
    /* E50 80103650 00000000 */   nop
    /* E54 80103654 F2FE030C */  jal        func_800FFBC8
    /* E58 80103658 00000000 */   nop
    /* E5C 8010365C AE15040C */  jal        func_801056B8
    /* E60 80103660 00000000 */   nop
    /* E64 80103664 310E0408 */  j          .L801038C4
    /* E68 80103668 1180023C */   lui       $v0, %hi(_menuState)
    /* E6C 8010366C 0F80103C */  lui        $s0, %hi(vs_battle_menu9CursorMemory)
    /* E70 80103670 F01B1126 */  addiu      $s1, $s0, %lo(vs_battle_menu9CursorMemory)
    /* E74 80103674 01002292 */  lbu        $v0, 0x1($s1)
    /* E78 80103678 00000000 */  nop
    /* E7C 8010367C 11004014 */  bnez       $v0, .L801036C4
    /* E80 80103680 00000000 */   nop
    /* E84 80103684 F01B0292 */  lbu        $v0, %lo(vs_battle_menu9CursorMemory)($s0)
    /* E88 80103688 00000000 */  nop
    /* E8C 8010368C 0D004014 */  bnez       $v0, .L801036C4
    /* E90 80103690 0680023C */   lui       $v0, %hi(vs_main_buttonsPressed)
    /* E94 80103694 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* E98 80103698 00000000 */  nop
    /* E9C 8010369C 00104230 */  andi       $v0, $v0, 0x1000
    /* EA0 801036A0 08004010 */  beqz       $v0, .L801036C4
    /* EA4 801036A4 7E000424 */   addiu     $a0, $zero, 0x7E
    /* EA8 801036A8 6216010C */  jal        vs_main_playSfxDefault
    /* EAC 801036AC 04000524 */   addiu     $a1, $zero, 0x4
    /* EB0 801036B0 18000224 */  addiu      $v0, $zero, 0x18
    /* EB4 801036B4 F01B02A2 */  sb         $v0, %lo(vs_battle_menu9CursorMemory)($s0)
    /* EB8 801036B8 07000224 */  addiu      $v0, $zero, 0x7
    /* EBC 801036BC FB0D0408 */  j          .L801037EC
    /* EC0 801036C0 010022A2 */   sb        $v0, 0x1($s1)
  .L801036C4:
    /* EC4 801036C4 01002392 */  lbu        $v1, 0x1($s1)
    /* EC8 801036C8 07000224 */  addiu      $v0, $zero, 0x7
    /* ECC 801036CC 11006214 */  bne        $v1, $v0, .L80103714
    /* ED0 801036D0 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* ED4 801036D4 F01B0392 */  lbu        $v1, %lo(vs_battle_menu9CursorMemory)($s0)
    /* ED8 801036D8 18000224 */  addiu      $v0, $zero, 0x18
    /* EDC 801036DC 0D006214 */  bne        $v1, $v0, .L80103714
    /* EE0 801036E0 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* EE4 801036E4 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* EE8 801036E8 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* EEC 801036EC 00000000 */  nop
    /* EF0 801036F0 00404230 */  andi       $v0, $v0, 0x4000
    /* EF4 801036F4 06004010 */  beqz       $v0, .L80103710
    /* EF8 801036F8 7E000424 */   addiu     $a0, $zero, 0x7E
    /* EFC 801036FC 6216010C */  jal        vs_main_playSfxDefault
    /* F00 80103700 04000524 */   addiu     $a1, $zero, 0x4
    /* F04 80103704 F01B00A2 */  sb         $zero, %lo(vs_battle_menu9CursorMemory)($s0)
    /* F08 80103708 FB0D0408 */  j          .L801037EC
    /* F0C 8010370C 010020A2 */   sb        $zero, 0x1($s1)
  .L80103710:
    /* F10 80103710 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L80103714:
    /* F14 80103714 DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* F18 80103718 00000000 */  nop
    /* F1C 8010371C 00106230 */  andi       $v0, $v1, 0x1000
    /* F20 80103720 1A004010 */  beqz       $v0, .L8010378C
    /* F24 80103724 0F80043C */   lui       $a0, %hi(vs_battle_menu9CursorMemory)
    /* F28 80103728 F01B9024 */  addiu      $s0, $a0, %lo(vs_battle_menu9CursorMemory)
    /* F2C 8010372C 01000592 */  lbu        $a1, 0x1($s0)
    /* F30 80103730 00000000 */  nop
    /* F34 80103734 FF00A330 */  andi       $v1, $a1, 0xFF
    /* F38 80103738 0200622C */  sltiu      $v0, $v1, 0x2
    /* F3C 8010373C 09004014 */  bnez       $v0, .L80103764
    /* F40 80103740 00000000 */   nop
    /* F44 80103744 7E000424 */  addiu      $a0, $zero, 0x7E
    /* F48 80103748 6216010C */  jal        vs_main_playSfxDefault
    /* F4C 8010374C 04000524 */   addiu     $a1, $zero, 0x4
    /* F50 80103750 01000292 */  lbu        $v0, 0x1($s0)
    /* F54 80103754 00000000 */  nop
    /* F58 80103758 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* F5C 8010375C FB0D0408 */  j          .L801037EC
    /* F60 80103760 010002A2 */   sb        $v0, 0x1($s0)
  .L80103764:
    /* F64 80103764 F01B8290 */  lbu        $v0, %lo(vs_battle_menu9CursorMemory)($a0)
    /* F68 80103768 00000000 */  nop
    /* F6C 8010376C 03004010 */  beqz       $v0, .L8010377C
    /* F70 80103770 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* F74 80103774 F80D0408 */  j          .L801037E0
    /* F78 80103778 F01B82A0 */   sb        $v0, %lo(vs_battle_menu9CursorMemory)($a0)
  .L8010377C:
    /* F7C 8010377C 1B006010 */  beqz       $v1, .L801037EC
    /* F80 80103780 FFFFA224 */   addiu     $v0, $a1, -0x1
    /* F84 80103784 F80D0408 */  j          .L801037E0
    /* F88 80103788 010002A2 */   sb        $v0, 0x1($s0)
  .L8010378C:
    /* F8C 8010378C 00406230 */  andi       $v0, $v1, 0x4000
    /* F90 80103790 16004010 */  beqz       $v0, .L801037EC
    /* F94 80103794 0F80063C */   lui       $a2, %hi(vs_battle_menu9CursorMemory)
    /* F98 80103798 F01BC724 */  addiu      $a3, $a2, %lo(vs_battle_menu9CursorMemory)
    /* F9C 8010379C 0100E490 */  lbu        $a0, 0x1($a3)
    /* FA0 801037A0 00000000 */  nop
    /* FA4 801037A4 FF008530 */  andi       $a1, $a0, 0xFF
    /* FA8 801037A8 0600A22C */  sltiu      $v0, $a1, 0x6
    /* FAC 801037AC 0B004014 */  bnez       $v0, .L801037DC
    /* FB0 801037B0 01008224 */   addiu     $v0, $a0, 0x1
    /* FB4 801037B4 F01BC390 */  lbu        $v1, %lo(vs_battle_menu9CursorMemory)($a2)
    /* FB8 801037B8 00000000 */  nop
    /* FBC 801037BC 1800622C */  sltiu      $v0, $v1, 0x18
    /* FC0 801037C0 03004010 */  beqz       $v0, .L801037D0
    /* FC4 801037C4 01006224 */   addiu     $v0, $v1, 0x1
    /* FC8 801037C8 F80D0408 */  j          .L801037E0
    /* FCC 801037CC F01BC2A0 */   sb        $v0, %lo(vs_battle_menu9CursorMemory)($a2)
  .L801037D0:
    /* FD0 801037D0 0700A22C */  sltiu      $v0, $a1, 0x7
    /* FD4 801037D4 05004010 */  beqz       $v0, .L801037EC
    /* FD8 801037D8 01008224 */   addiu     $v0, $a0, 0x1
  .L801037DC:
    /* FDC 801037DC 0100E2A0 */  sb         $v0, 0x1($a3)
  .L801037E0:
    /* FE0 801037E0 7E000424 */  addiu      $a0, $zero, 0x7E
    /* FE4 801037E4 6216010C */  jal        vs_main_playSfxDefault
    /* FE8 801037E8 04000524 */   addiu     $a1, $zero, 0x4
  .L801037EC:
    /* FEC 801037EC 0680103C */  lui        $s0, %hi(vs_main_buttonsPressed)
    /* FF0 801037F0 D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* FF4 801037F4 00000000 */  nop
    /* FF8 801037F8 50004230 */  andi       $v0, $v0, 0x50
    /* FFC 801037FC 12004010 */  beqz       $v0, .L80103848
    /* 1000 80103800 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 1004 80103804 6216010C */  jal        vs_main_playSfxDefault
    /* 1008 80103808 06000524 */   addiu     $a1, $zero, 0x6
    /* 100C 8010380C EAFE030C */  jal        func_800FFBA8
    /* 1010 80103810 00000000 */   nop
    /* 1014 80103814 1180023C */  lui        $v0, %hi(_menuState)
    /* 1018 80103818 3CA4438C */  lw         $v1, %lo(_menuState)($v0)
    /* 101C 8010381C D0E1048E */  lw         $a0, %lo(vs_main_buttonsPressed)($s0)
    /* 1020 80103820 01006324 */  addiu      $v1, $v1, 0x1
    /* 1024 80103824 10008430 */  andi       $a0, $a0, 0x10
    /* 1028 80103828 05008010 */  beqz       $a0, .L80103840
    /* 102C 8010382C 3CA443AC */   sw        $v1, %lo(_menuState)($v0)
    /* 1030 80103830 1180033C */  lui        $v1, %hi(D_8010A440)
    /* 1034 80103834 01000224 */  addiu      $v0, $zero, 0x1
    /* 1038 80103838 120E0408 */  j          .L80103848
    /* 103C 8010383C 40A462AC */   sw        $v0, %lo(D_8010A440)($v1)
  .L80103840:
    /* 1040 80103840 1180023C */  lui        $v0, %hi(D_8010A440)
    /* 1044 80103844 40A440AC */  sw         $zero, %lo(D_8010A440)($v0)
  .L80103848:
    /* 1048 80103848 1180103C */  lui        $s0, %hi(D_8010A220)
    /* 104C 8010384C 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 1050 80103850 E715040C */  jal        func_8010579C
    /* 1054 80103854 00000000 */   nop
    /* 1058 80103858 20A2038E */  lw         $v1, %lo(D_8010A220)($s0)
    /* 105C 8010385C 00000000 */  nop
    /* 1060 80103860 08006228 */  slti       $v0, $v1, 0x8
    /* 1064 80103864 9E044010 */  beqz       $v0, .L80104AE0
    /* 1068 80103868 01006224 */   addiu     $v0, $v1, 0x1
    /* 106C 8010386C B8120408 */  j          .L80104AE0
    /* 1070 80103870 20A202AE */   sw        $v0, %lo(D_8010A220)($s0)
    /* 1074 80103874 1180103C */  lui        $s0, %hi(D_8010A220)
    /* 1078 80103878 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 107C 8010387C E715040C */  jal        func_8010579C
    /* 1080 80103880 00000000 */   nop
    /* 1084 80103884 20A2028E */  lw         $v0, %lo(D_8010A220)($s0)
    /* 1088 80103888 00000000 */  nop
    /* 108C 8010388C 3504401C */  bgtz       $v0, .L80104964
    /* 1090 80103890 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 1094 80103894 1180023C */  lui        $v0, %hi(D_8010A440)
    /* 1098 80103898 40A4428C */  lw         $v0, %lo(D_8010A440)($v0)
    /* 109C 8010389C 00000000 */  nop
    /* 10A0 801038A0 0A044014 */  bnez       $v0, .L801048CC
    /* 10A4 801038A4 1180033C */   lui       $v1, %hi(_menuState)
    /* 10A8 801038A8 B7120408 */  j          .L80104ADC
    /* 10AC 801038AC 01000224 */   addiu     $v0, $zero, 0x1
    /* 10B0 801038B0 F2FE030C */  jal        func_800FFBC8
    /* 10B4 801038B4 00000000 */   nop
    /* 10B8 801038B8 E019040C */  jal        func_80106780
    /* 10BC 801038BC 00000000 */   nop
    /* 10C0 801038C0 1180023C */  lui        $v0, %hi(_menuState)
  .L801038C4:
    /* 10C4 801038C4 3CA4438C */  lw         $v1, %lo(_menuState)($v0)
    /* 10C8 801038C8 1180043C */  lui        $a0, %hi(D_8010A220)
    /* 10CC 801038CC 20A280AC */  sw         $zero, %lo(D_8010A220)($a0)
    /* 10D0 801038D0 01006324 */  addiu      $v1, $v1, 0x1
    /* 10D4 801038D4 B8120408 */  j          .L80104AE0
    /* 10D8 801038D8 3CA443AC */   sw        $v1, %lo(_menuState)($v0)
    /* 10DC 801038DC 0F80023C */  lui        $v0, %hi(vs_battle_menu9CursorMemory)
    /* 10E0 801038E0 F01B5024 */  addiu      $s0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 10E4 801038E4 05000292 */  lbu        $v0, 0x5($s0)
    /* 10E8 801038E8 00000000 */  nop
    /* 10EC 801038EC 13004014 */  bnez       $v0, .L8010393C
    /* 10F0 801038F0 0F80023C */   lui       $v0, %hi(vs_battle_menu9CursorMemory)
    /* 10F4 801038F4 04000292 */  lbu        $v0, 0x4($s0)
    /* 10F8 801038F8 00000000 */  nop
    /* 10FC 801038FC 0F004014 */  bnez       $v0, .L8010393C
    /* 1100 80103900 0F80023C */   lui       $v0, %hi(vs_battle_menu9CursorMemory)
    /* 1104 80103904 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 1108 80103908 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 110C 8010390C 00000000 */  nop
    /* 1110 80103910 00104230 */  andi       $v0, $v0, 0x1000
    /* 1114 80103914 08004010 */  beqz       $v0, .L80103938
    /* 1118 80103918 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 111C 8010391C 6216010C */  jal        vs_main_playSfxDefault
    /* 1120 80103920 04000524 */   addiu     $a1, $zero, 0x4
    /* 1124 80103924 0F000224 */  addiu      $v0, $zero, 0xF
    /* 1128 80103928 040002A2 */  sb         $v0, 0x4($s0)
    /* 112C 8010392C 07000224 */  addiu      $v0, $zero, 0x7
    /* 1130 80103930 9A0E0408 */  j          .L80103A68
    /* 1134 80103934 050002A2 */   sb        $v0, 0x5($s0)
  .L80103938:
    /* 1138 80103938 0F80023C */  lui        $v0, %hi(vs_battle_menu9CursorMemory)
  .L8010393C:
    /* 113C 8010393C F01B5024 */  addiu      $s0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 1140 80103940 05000392 */  lbu        $v1, 0x5($s0)
    /* 1144 80103944 07000224 */  addiu      $v0, $zero, 0x7
    /* 1148 80103948 11006214 */  bne        $v1, $v0, .L80103990
    /* 114C 8010394C 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 1150 80103950 04000392 */  lbu        $v1, 0x4($s0)
    /* 1154 80103954 0F000224 */  addiu      $v0, $zero, 0xF
    /* 1158 80103958 0D006214 */  bne        $v1, $v0, .L80103990
    /* 115C 8010395C 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 1160 80103960 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 1164 80103964 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 1168 80103968 00000000 */  nop
    /* 116C 8010396C 00404230 */  andi       $v0, $v0, 0x4000
    /* 1170 80103970 06004010 */  beqz       $v0, .L8010398C
    /* 1174 80103974 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 1178 80103978 6216010C */  jal        vs_main_playSfxDefault
    /* 117C 8010397C 04000524 */   addiu     $a1, $zero, 0x4
    /* 1180 80103980 040000A2 */  sb         $zero, 0x4($s0)
    /* 1184 80103984 9A0E0408 */  j          .L80103A68
    /* 1188 80103988 050000A2 */   sb        $zero, 0x5($s0)
  .L8010398C:
    /* 118C 8010398C 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L80103990:
    /* 1190 80103990 DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 1194 80103994 00000000 */  nop
    /* 1198 80103998 00106230 */  andi       $v0, $v1, 0x1000
    /* 119C 8010399C 1A004010 */  beqz       $v0, .L80103A08
    /* 11A0 801039A0 0F80023C */   lui       $v0, %hi(vs_battle_menu9CursorMemory)
    /* 11A4 801039A4 F01B5024 */  addiu      $s0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 11A8 801039A8 05000492 */  lbu        $a0, 0x5($s0)
    /* 11AC 801039AC 00000000 */  nop
    /* 11B0 801039B0 FF008330 */  andi       $v1, $a0, 0xFF
    /* 11B4 801039B4 0200622C */  sltiu      $v0, $v1, 0x2
    /* 11B8 801039B8 09004014 */  bnez       $v0, .L801039E0
    /* 11BC 801039BC 00000000 */   nop
    /* 11C0 801039C0 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 11C4 801039C4 6216010C */  jal        vs_main_playSfxDefault
    /* 11C8 801039C8 04000524 */   addiu     $a1, $zero, 0x4
    /* 11CC 801039CC 05000292 */  lbu        $v0, 0x5($s0)
    /* 11D0 801039D0 00000000 */  nop
    /* 11D4 801039D4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 11D8 801039D8 9A0E0408 */  j          .L80103A68
    /* 11DC 801039DC 050002A2 */   sb        $v0, 0x5($s0)
  .L801039E0:
    /* 11E0 801039E0 04000292 */  lbu        $v0, 0x4($s0)
    /* 11E4 801039E4 00000000 */  nop
    /* 11E8 801039E8 03004010 */  beqz       $v0, .L801039F8
    /* 11EC 801039EC FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 11F0 801039F0 970E0408 */  j          .L80103A5C
    /* 11F4 801039F4 040002A2 */   sb        $v0, 0x4($s0)
  .L801039F8:
    /* 11F8 801039F8 1B006010 */  beqz       $v1, .L80103A68
    /* 11FC 801039FC FFFF8224 */   addiu     $v0, $a0, -0x1
    /* 1200 80103A00 970E0408 */  j          .L80103A5C
    /* 1204 80103A04 050002A2 */   sb        $v0, 0x5($s0)
  .L80103A08:
    /* 1208 80103A08 00406230 */  andi       $v0, $v1, 0x4000
    /* 120C 80103A0C 16004010 */  beqz       $v0, .L80103A68
    /* 1210 80103A10 0F80023C */   lui       $v0, %hi(vs_battle_menu9CursorMemory)
    /* 1214 80103A14 F01B4624 */  addiu      $a2, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 1218 80103A18 0500C490 */  lbu        $a0, 0x5($a2)
    /* 121C 80103A1C 00000000 */  nop
    /* 1220 80103A20 FF008530 */  andi       $a1, $a0, 0xFF
    /* 1224 80103A24 0600A22C */  sltiu      $v0, $a1, 0x6
    /* 1228 80103A28 0B004014 */  bnez       $v0, .L80103A58
    /* 122C 80103A2C 01008224 */   addiu     $v0, $a0, 0x1
    /* 1230 80103A30 0400C390 */  lbu        $v1, 0x4($a2)
    /* 1234 80103A34 00000000 */  nop
    /* 1238 80103A38 0F00622C */  sltiu      $v0, $v1, 0xF
    /* 123C 80103A3C 03004010 */  beqz       $v0, .L80103A4C
    /* 1240 80103A40 01006224 */   addiu     $v0, $v1, 0x1
    /* 1244 80103A44 970E0408 */  j          .L80103A5C
    /* 1248 80103A48 0400C2A0 */   sb        $v0, 0x4($a2)
  .L80103A4C:
    /* 124C 80103A4C 0700A22C */  sltiu      $v0, $a1, 0x7
    /* 1250 80103A50 05004010 */  beqz       $v0, .L80103A68
    /* 1254 80103A54 01008224 */   addiu     $v0, $a0, 0x1
  .L80103A58:
    /* 1258 80103A58 0500C2A0 */  sb         $v0, 0x5($a2)
  .L80103A5C:
    /* 125C 80103A5C 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 1260 80103A60 6216010C */  jal        vs_main_playSfxDefault
    /* 1264 80103A64 04000524 */   addiu     $a1, $zero, 0x4
  .L80103A68:
    /* 1268 80103A68 0680103C */  lui        $s0, %hi(vs_main_buttonsPressed)
    /* 126C 80103A6C D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 1270 80103A70 00000000 */  nop
    /* 1274 80103A74 50004230 */  andi       $v0, $v0, 0x50
    /* 1278 80103A78 12004010 */  beqz       $v0, .L80103AC4
    /* 127C 80103A7C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 1280 80103A80 6216010C */  jal        vs_main_playSfxDefault
    /* 1284 80103A84 06000524 */   addiu     $a1, $zero, 0x6
    /* 1288 80103A88 EAFE030C */  jal        func_800FFBA8
    /* 128C 80103A8C 00000000 */   nop
    /* 1290 80103A90 1180023C */  lui        $v0, %hi(_menuState)
    /* 1294 80103A94 3CA4438C */  lw         $v1, %lo(_menuState)($v0)
    /* 1298 80103A98 D0E1048E */  lw         $a0, %lo(vs_main_buttonsPressed)($s0)
    /* 129C 80103A9C 01006324 */  addiu      $v1, $v1, 0x1
    /* 12A0 80103AA0 10008430 */  andi       $a0, $a0, 0x10
    /* 12A4 80103AA4 05008010 */  beqz       $a0, .L80103ABC
    /* 12A8 80103AA8 3CA443AC */   sw        $v1, %lo(_menuState)($v0)
    /* 12AC 80103AAC 1180033C */  lui        $v1, %hi(D_8010A440)
    /* 12B0 80103AB0 01000224 */  addiu      $v0, $zero, 0x1
    /* 12B4 80103AB4 B10E0408 */  j          .L80103AC4
    /* 12B8 80103AB8 40A462AC */   sw        $v0, %lo(D_8010A440)($v1)
  .L80103ABC:
    /* 12BC 80103ABC 1180023C */  lui        $v0, %hi(D_8010A440)
    /* 12C0 80103AC0 40A440AC */  sw         $zero, %lo(D_8010A440)($v0)
  .L80103AC4:
    /* 12C4 80103AC4 1180103C */  lui        $s0, %hi(D_8010A220)
    /* 12C8 80103AC8 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 12CC 80103ACC 021A040C */  jal        func_80106808
    /* 12D0 80103AD0 00000000 */   nop
    /* 12D4 80103AD4 20A2038E */  lw         $v1, %lo(D_8010A220)($s0)
    /* 12D8 80103AD8 00000000 */  nop
    /* 12DC 80103ADC 08006228 */  slti       $v0, $v1, 0x8
    /* 12E0 80103AE0 FF034010 */  beqz       $v0, .L80104AE0
    /* 12E4 80103AE4 01006224 */   addiu     $v0, $v1, 0x1
    /* 12E8 80103AE8 B8120408 */  j          .L80104AE0
    /* 12EC 80103AEC 20A202AE */   sw        $v0, %lo(D_8010A220)($s0)
    /* 12F0 80103AF0 1180103C */  lui        $s0, %hi(D_8010A220)
    /* 12F4 80103AF4 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 12F8 80103AF8 021A040C */  jal        func_80106808
    /* 12FC 80103AFC 00000000 */   nop
    /* 1300 80103B00 20A2028E */  lw         $v0, %lo(D_8010A220)($s0)
    /* 1304 80103B04 00000000 */  nop
    /* 1308 80103B08 9603401C */  bgtz       $v0, .L80104964
    /* 130C 80103B0C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 1310 80103B10 1180023C */  lui        $v0, %hi(D_8010A440)
    /* 1314 80103B14 40A4428C */  lw         $v0, %lo(D_8010A440)($v0)
    /* 1318 80103B18 00000000 */  nop
    /* 131C 80103B1C 6B034014 */  bnez       $v0, .L801048CC
    /* 1320 80103B20 1180033C */   lui       $v1, %hi(_menuState)
    /* 1324 80103B24 B7120408 */  j          .L80104ADC
    /* 1328 80103B28 01000224 */   addiu     $v0, $zero, 0x1
    /* 132C 80103B2C F2FE030C */  jal        func_800FFBC8
    /* 1330 80103B30 00000000 */   nop
    /* 1334 80103B34 E71B040C */  jal        func_80106F9C
    /* 1338 80103B38 00000000 */   nop
    /* 133C 80103B3C 1180033C */  lui        $v1, %hi(_menuState)
    /* 1340 80103B40 3CA4628C */  lw         $v0, %lo(_menuState)($v1)
    /* 1344 80103B44 B7120408 */  j          .L80104ADC
    /* 1348 80103B48 01004224 */   addiu     $v0, $v0, 0x1
    /* 134C 80103B4C 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 1350 80103B50 DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 1354 80103B54 00000000 */  nop
    /* 1358 80103B58 00106230 */  andi       $v0, $v1, 0x1000
    /* 135C 80103B5C 08004010 */  beqz       $v0, .L80103B80
    /* 1360 80103B60 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 1364 80103B64 6216010C */  jal        vs_main_playSfxDefault
    /* 1368 80103B68 04000524 */   addiu     $a1, $zero, 0x4
    /* 136C 80103B6C 0F80033C */  lui        $v1, %hi(vs_battle_menu9CursorMemory)
    /* 1370 80103B70 F01B6324 */  addiu      $v1, $v1, %lo(vs_battle_menu9CursorMemory)
    /* 1374 80103B74 06006290 */  lbu        $v0, 0x6($v1)
    /* 1378 80103B78 EA0E0408 */  j          .L80103BA8
    /* 137C 80103B7C FFFF4224 */   addiu     $v0, $v0, -0x1
  .L80103B80:
    /* 1380 80103B80 00406230 */  andi       $v0, $v1, 0x4000
    /* 1384 80103B84 0B004010 */  beqz       $v0, .L80103BB4
    /* 1388 80103B88 0680103C */   lui       $s0, %hi(vs_main_buttonsPressed)
    /* 138C 80103B8C 6216010C */  jal        vs_main_playSfxDefault
    /* 1390 80103B90 04000524 */   addiu     $a1, $zero, 0x4
    /* 1394 80103B94 0F80033C */  lui        $v1, %hi(vs_battle_menu9CursorMemory)
    /* 1398 80103B98 F01B6324 */  addiu      $v1, $v1, %lo(vs_battle_menu9CursorMemory)
    /* 139C 80103B9C 06006290 */  lbu        $v0, 0x6($v1)
    /* 13A0 80103BA0 00000000 */  nop
    /* 13A4 80103BA4 01004224 */  addiu      $v0, $v0, 0x1
  .L80103BA8:
    /* 13A8 80103BA8 07004230 */  andi       $v0, $v0, 0x7
    /* 13AC 80103BAC 060062A0 */  sb         $v0, 0x6($v1)
    /* 13B0 80103BB0 0680103C */  lui        $s0, %hi(vs_main_buttonsPressed)
  .L80103BB4:
    /* 13B4 80103BB4 D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 13B8 80103BB8 00000000 */  nop
    /* 13BC 80103BBC 50004230 */  andi       $v0, $v0, 0x50
    /* 13C0 80103BC0 14004010 */  beqz       $v0, .L80103C14
    /* 13C4 80103BC4 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 13C8 80103BC8 6216010C */  jal        vs_main_playSfxDefault
    /* 13CC 80103BCC 06000524 */   addiu     $a1, $zero, 0x6
    /* 13D0 80103BD0 EAFE030C */  jal        func_800FFBA8
    /* 13D4 80103BD4 00000000 */   nop
    /* 13D8 80103BD8 241C040C */  jal        func_80107090
    /* 13DC 80103BDC 00000000 */   nop
    /* 13E0 80103BE0 1180023C */  lui        $v0, %hi(_menuState)
    /* 13E4 80103BE4 3CA4438C */  lw         $v1, %lo(_menuState)($v0)
    /* 13E8 80103BE8 D0E1048E */  lw         $a0, %lo(vs_main_buttonsPressed)($s0)
    /* 13EC 80103BEC 01006324 */  addiu      $v1, $v1, 0x1
    /* 13F0 80103BF0 10008430 */  andi       $a0, $a0, 0x10
    /* 13F4 80103BF4 05008010 */  beqz       $a0, .L80103C0C
    /* 13F8 80103BF8 3CA443AC */   sw        $v1, %lo(_menuState)($v0)
    /* 13FC 80103BFC 1180033C */  lui        $v1, %hi(D_8010A440)
    /* 1400 80103C00 01000224 */  addiu      $v0, $zero, 0x1
    /* 1404 80103C04 050F0408 */  j          .L80103C14
    /* 1408 80103C08 40A462AC */   sw        $v0, %lo(D_8010A440)($v1)
  .L80103C0C:
    /* 140C 80103C0C 1180023C */  lui        $v0, %hi(D_8010A440)
    /* 1410 80103C10 40A440AC */  sw         $zero, %lo(D_8010A440)($v0)
  .L80103C14:
    /* 1414 80103C14 1180103C */  lui        $s0, %hi(D_8010A220)
    /* 1418 80103C18 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 141C 80103C1C 481C040C */  jal        func_80107120
    /* 1420 80103C20 00000000 */   nop
    /* 1424 80103C24 20A2038E */  lw         $v1, %lo(D_8010A220)($s0)
    /* 1428 80103C28 00000000 */  nop
    /* 142C 80103C2C 08006228 */  slti       $v0, $v1, 0x8
    /* 1430 80103C30 AB034010 */  beqz       $v0, .L80104AE0
    /* 1434 80103C34 01006224 */   addiu     $v0, $v1, 0x1
    /* 1438 80103C38 B8120408 */  j          .L80104AE0
    /* 143C 80103C3C 20A202AE */   sw        $v0, %lo(D_8010A220)($s0)
    /* 1440 80103C40 1180113C */  lui        $s1, %hi(D_8010A220)
    /* 1444 80103C44 20A2248E */  lw         $a0, %lo(D_8010A220)($s1)
    /* 1448 80103C48 481C040C */  jal        func_80107120
    /* 144C 80103C4C 00000000 */   nop
    /* 1450 80103C50 20A2228E */  lw         $v0, %lo(D_8010A220)($s1)
    /* 1454 80103C54 00000000 */  nop
    /* 1458 80103C58 03004018 */  blez       $v0, .L80103C68
    /* 145C 80103C5C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 1460 80103C60 B8120408 */  j          .L80104AE0
    /* 1464 80103C64 20A222AE */   sw        $v0, %lo(D_8010A220)($s1)
  .L80103C68:
    /* 1468 80103C68 20A220AE */  sw         $zero, %lo(D_8010A220)($s1)
    /* 146C 80103C6C 1180023C */  lui        $v0, %hi(_gazetteRows)
    /* 1470 80103C70 30A25024 */  addiu      $s0, $v0, %lo(_gazetteRows)
  .L80103C74:
    /* 1474 80103C74 02000292 */  lbu        $v0, 0x2($s0)
    /* 1478 80103C78 00000000 */  nop
    /* 147C 80103C7C 04004014 */  bnez       $v0, .L80103C90
    /* 1480 80103C80 00000000 */   nop
    /* 1484 80103C84 20A2248E */  lw         $a0, %lo(D_8010A220)($s1)
    /* 1488 80103C88 E4FE030C */  jal        vs_mainMenu_deactivateMenuItem
    /* 148C 80103C8C 00000000 */   nop
  .L80103C90:
    /* 1490 80103C90 20A2228E */  lw         $v0, %lo(D_8010A220)($s1)
    /* 1494 80103C94 00000000 */  nop
    /* 1498 80103C98 01004224 */  addiu      $v0, $v0, 0x1
    /* 149C 80103C9C 20A222AE */  sw         $v0, %lo(D_8010A220)($s1)
    /* 14A0 80103CA0 08004228 */  slti       $v0, $v0, 0x8
    /* 14A4 80103CA4 F3FF4014 */  bnez       $v0, .L80103C74
    /* 14A8 80103CA8 10001026 */   addiu     $s0, $s0, 0x10
    /* 14AC 80103CAC 1180023C */  lui        $v0, %hi(D_8010A440)
    /* 14B0 80103CB0 40A4438C */  lw         $v1, %lo(D_8010A440)($v0)
    /* 14B4 80103CB4 1180023C */  lui        $v0, %hi(D_8010A220)
    /* 14B8 80103CB8 04036014 */  bnez       $v1, .L801048CC
    /* 14BC 80103CBC 20A240AC */   sw        $zero, %lo(D_8010A220)($v0)
    /* 14C0 80103CC0 1180033C */  lui        $v1, %hi(_menuState)
    /* 14C4 80103CC4 B7120408 */  j          .L80104ADC
    /* 14C8 80103CC8 01000224 */   addiu     $v0, $zero, 0x1
    /* 14CC 80103CCC 1180023C */  lui        $v0, %hi(_monBinCdQueueSlot)
    /* 14D0 80103CD0 6CA4448C */  lw         $a0, %lo(_monBinCdQueueSlot)($v0)
    /* 14D4 80103CD4 00000000 */  nop
    /* 14D8 80103CD8 00008384 */  lh         $v1, 0x0($a0)
    /* 14DC 80103CDC 04000224 */  addiu      $v0, $zero, 0x4
    /* 14E0 80103CE0 80036214 */  bne        $v1, $v0, .L80104AE4
    /* 14E4 80103CE4 21100000 */   addu      $v0, $zero, $zero
    /* 14E8 80103CE8 E012010C */  jal        vs_main_freeCdQueueSlot
    /* 14EC 80103CEC 00000000 */   nop
    /* 14F0 80103CF0 1180023C */  lui        $v0, %hi(_monBinData)
    /* 14F4 80103CF4 70A4428C */  lw         $v0, %lo(_monBinData)($v0)
    /* 14F8 80103CF8 1180033C */  lui        $v1, %hi(_enemyDescriptions)
    /* 14FC 80103CFC C8194224 */  addiu      $v0, $v0, 0x19C8
    /* 1500 80103D00 F2FE030C */  jal        func_800FFBC8
    /* 1504 80103D04 74A462AC */   sw        $v0, %lo(_enemyDescriptions)($v1)
    /* 1508 80103D08 6317040C */  jal        func_80105D8C
    /* 150C 80103D0C 00000000 */   nop
    /* 1510 80103D10 1180043C */  lui        $a0, %hi(_menuState)
  .L80103D14:
    /* 1514 80103D14 3CA4828C */  lw         $v0, %lo(_menuState)($a0)
    /* 1518 80103D18 1180033C */  lui        $v1, %hi(D_8010A220)
    /* 151C 80103D1C 20A260AC */  sw         $zero, %lo(D_8010A220)($v1)
    /* 1520 80103D20 01004224 */  addiu      $v0, $v0, 0x1
    /* 1524 80103D24 B8120408 */  j          .L80104AE0
    /* 1528 80103D28 3CA482AC */   sw        $v0, %lo(_menuState)($a0)
    /* 152C 80103D2C 0F80023C */  lui        $v0, %hi(vs_battle_menu9CursorMemory)
    /* 1530 80103D30 F01B5024 */  addiu      $s0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 1534 80103D34 03000292 */  lbu        $v0, 0x3($s0)
    /* 1538 80103D38 00000000 */  nop
    /* 153C 80103D3C 13004014 */  bnez       $v0, .L80103D8C
    /* 1540 80103D40 0F80023C */   lui       $v0, %hi(vs_battle_menu9CursorMemory)
    /* 1544 80103D44 02000292 */  lbu        $v0, 0x2($s0)
    /* 1548 80103D48 00000000 */  nop
    /* 154C 80103D4C 0F004014 */  bnez       $v0, .L80103D8C
    /* 1550 80103D50 0F80023C */   lui       $v0, %hi(vs_battle_menu9CursorMemory)
    /* 1554 80103D54 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 1558 80103D58 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 155C 80103D5C 00000000 */  nop
    /* 1560 80103D60 00104230 */  andi       $v0, $v0, 0x1000
    /* 1564 80103D64 08004010 */  beqz       $v0, .L80103D88
    /* 1568 80103D68 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 156C 80103D6C 6216010C */  jal        vs_main_playSfxDefault
    /* 1570 80103D70 04000524 */   addiu     $a1, $zero, 0x4
    /* 1574 80103D74 46000224 */  addiu      $v0, $zero, 0x46
    /* 1578 80103D78 020002A2 */  sb         $v0, 0x2($s0)
    /* 157C 80103D7C 07000224 */  addiu      $v0, $zero, 0x7
    /* 1580 80103D80 AE0F0408 */  j          .L80103EB8
    /* 1584 80103D84 030002A2 */   sb        $v0, 0x3($s0)
  .L80103D88:
    /* 1588 80103D88 0F80023C */  lui        $v0, %hi(vs_battle_menu9CursorMemory)
  .L80103D8C:
    /* 158C 80103D8C F01B5024 */  addiu      $s0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 1590 80103D90 03000392 */  lbu        $v1, 0x3($s0)
    /* 1594 80103D94 07000224 */  addiu      $v0, $zero, 0x7
    /* 1598 80103D98 11006214 */  bne        $v1, $v0, .L80103DE0
    /* 159C 80103D9C 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 15A0 80103DA0 02000392 */  lbu        $v1, 0x2($s0)
    /* 15A4 80103DA4 46000224 */  addiu      $v0, $zero, 0x46
    /* 15A8 80103DA8 0D006214 */  bne        $v1, $v0, .L80103DE0
    /* 15AC 80103DAC 0680023C */   lui       $v0, %hi(vs_main_buttonRepeat)
    /* 15B0 80103DB0 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 15B4 80103DB4 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 15B8 80103DB8 00000000 */  nop
    /* 15BC 80103DBC 00404230 */  andi       $v0, $v0, 0x4000
    /* 15C0 80103DC0 06004010 */  beqz       $v0, .L80103DDC
    /* 15C4 80103DC4 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 15C8 80103DC8 6216010C */  jal        vs_main_playSfxDefault
    /* 15CC 80103DCC 04000524 */   addiu     $a1, $zero, 0x4
    /* 15D0 80103DD0 020000A2 */  sb         $zero, 0x2($s0)
    /* 15D4 80103DD4 AE0F0408 */  j          .L80103EB8
    /* 15D8 80103DD8 030000A2 */   sb        $zero, 0x3($s0)
  .L80103DDC:
    /* 15DC 80103DDC 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
  .L80103DE0:
    /* 15E0 80103DE0 DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* 15E4 80103DE4 00000000 */  nop
    /* 15E8 80103DE8 00106230 */  andi       $v0, $v1, 0x1000
    /* 15EC 80103DEC 1A004010 */  beqz       $v0, .L80103E58
    /* 15F0 80103DF0 0F80023C */   lui       $v0, %hi(vs_battle_menu9CursorMemory)
    /* 15F4 80103DF4 F01B5024 */  addiu      $s0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 15F8 80103DF8 03000492 */  lbu        $a0, 0x3($s0)
    /* 15FC 80103DFC 00000000 */  nop
    /* 1600 80103E00 FF008330 */  andi       $v1, $a0, 0xFF
    /* 1604 80103E04 0200622C */  sltiu      $v0, $v1, 0x2
    /* 1608 80103E08 09004014 */  bnez       $v0, .L80103E30
    /* 160C 80103E0C 00000000 */   nop
    /* 1610 80103E10 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 1614 80103E14 6216010C */  jal        vs_main_playSfxDefault
    /* 1618 80103E18 04000524 */   addiu     $a1, $zero, 0x4
    /* 161C 80103E1C 03000292 */  lbu        $v0, 0x3($s0)
    /* 1620 80103E20 00000000 */  nop
    /* 1624 80103E24 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1628 80103E28 AE0F0408 */  j          .L80103EB8
    /* 162C 80103E2C 030002A2 */   sb        $v0, 0x3($s0)
  .L80103E30:
    /* 1630 80103E30 02000292 */  lbu        $v0, 0x2($s0)
    /* 1634 80103E34 00000000 */  nop
    /* 1638 80103E38 03004010 */  beqz       $v0, .L80103E48
    /* 163C 80103E3C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 1640 80103E40 AB0F0408 */  j          .L80103EAC
    /* 1644 80103E44 020002A2 */   sb        $v0, 0x2($s0)
  .L80103E48:
    /* 1648 80103E48 1B006010 */  beqz       $v1, .L80103EB8
    /* 164C 80103E4C FFFF8224 */   addiu     $v0, $a0, -0x1
    /* 1650 80103E50 AB0F0408 */  j          .L80103EAC
    /* 1654 80103E54 030002A2 */   sb        $v0, 0x3($s0)
  .L80103E58:
    /* 1658 80103E58 00406230 */  andi       $v0, $v1, 0x4000
    /* 165C 80103E5C 16004010 */  beqz       $v0, .L80103EB8
    /* 1660 80103E60 0F80023C */   lui       $v0, %hi(vs_battle_menu9CursorMemory)
    /* 1664 80103E64 F01B4624 */  addiu      $a2, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 1668 80103E68 0300C490 */  lbu        $a0, 0x3($a2)
    /* 166C 80103E6C 00000000 */  nop
    /* 1670 80103E70 FF008530 */  andi       $a1, $a0, 0xFF
    /* 1674 80103E74 0600A22C */  sltiu      $v0, $a1, 0x6
    /* 1678 80103E78 0B004014 */  bnez       $v0, .L80103EA8
    /* 167C 80103E7C 01008224 */   addiu     $v0, $a0, 0x1
    /* 1680 80103E80 0200C390 */  lbu        $v1, 0x2($a2)
    /* 1684 80103E84 00000000 */  nop
    /* 1688 80103E88 4600622C */  sltiu      $v0, $v1, 0x46
    /* 168C 80103E8C 03004010 */  beqz       $v0, .L80103E9C
    /* 1690 80103E90 01006224 */   addiu     $v0, $v1, 0x1
    /* 1694 80103E94 AB0F0408 */  j          .L80103EAC
    /* 1698 80103E98 0200C2A0 */   sb        $v0, 0x2($a2)
  .L80103E9C:
    /* 169C 80103E9C 0700A22C */  sltiu      $v0, $a1, 0x7
    /* 16A0 80103EA0 05004010 */  beqz       $v0, .L80103EB8
    /* 16A4 80103EA4 01008224 */   addiu     $v0, $a0, 0x1
  .L80103EA8:
    /* 16A8 80103EA8 0300C2A0 */  sb         $v0, 0x3($a2)
  .L80103EAC:
    /* 16AC 80103EAC 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 16B0 80103EB0 6216010C */  jal        vs_main_playSfxDefault
    /* 16B4 80103EB4 04000524 */   addiu     $a1, $zero, 0x4
  .L80103EB8:
    /* 16B8 80103EB8 0680103C */  lui        $s0, %hi(vs_main_buttonsPressed)
    /* 16BC 80103EBC D0E1038E */  lw         $v1, %lo(vs_main_buttonsPressed)($s0)
    /* 16C0 80103EC0 00000000 */  nop
    /* 16C4 80103EC4 20006230 */  andi       $v0, $v1, 0x20
    /* 16C8 80103EC8 2D004010 */  beqz       $v0, .L80103F80
    /* 16CC 80103ECC 0F80023C */   lui       $v0, %hi(vs_battle_menu9CursorMemory)
    /* 16D0 80103ED0 F01B5024 */  addiu      $s0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 16D4 80103ED4 02000392 */  lbu        $v1, 0x2($s0)
    /* 16D8 80103ED8 03000292 */  lbu        $v0, 0x3($s0)
    /* 16DC 80103EDC 1180113C */  lui        $s1, %hi(_monBinData)
    /* 16E0 80103EE0 21186200 */  addu       $v1, $v1, $v0
    /* 16E4 80103EE4 40100300 */  sll        $v0, $v1, 1
    /* 16E8 80103EE8 21104300 */  addu       $v0, $v0, $v1
    /* 16EC 80103EEC 80100200 */  sll        $v0, $v0, 2
    /* 16F0 80103EF0 23104300 */  subu       $v0, $v0, $v1
    /* 16F4 80103EF4 70A4238E */  lw         $v1, %lo(_monBinData)($s1)
    /* 16F8 80103EF8 80100200 */  sll        $v0, $v0, 2
    /* 16FC 80103EFC 21104300 */  addu       $v0, $v0, $v1
    /* 1700 80103F00 0C004290 */  lbu        $v0, 0xC($v0)
    /* 1704 80103F04 00000000 */  nop
    /* 1708 80103F08 19004010 */  beqz       $v0, .L80103F70
    /* 170C 80103F0C 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 1710 80103F10 6216010C */  jal        vs_main_playSfxDefault
    /* 1714 80103F14 05000524 */   addiu     $a1, $zero, 0x5
    /* 1718 80103F18 02000392 */  lbu        $v1, 0x2($s0)
    /* 171C 80103F1C 03000292 */  lbu        $v0, 0x3($s0)
    /* 1720 80103F20 00000000 */  nop
    /* 1724 80103F24 21186200 */  addu       $v1, $v1, $v0
    /* 1728 80103F28 40100300 */  sll        $v0, $v1, 1
    /* 172C 80103F2C 21104300 */  addu       $v0, $v0, $v1
    /* 1730 80103F30 80100200 */  sll        $v0, $v0, 2
    /* 1734 80103F34 23104300 */  subu       $v0, $v0, $v1
    /* 1738 80103F38 70A4238E */  lw         $v1, %lo(_monBinData)($s1)
    /* 173C 80103F3C 80100200 */  sll        $v0, $v0, 2
    /* 1740 80103F40 21104300 */  addu       $v0, $v0, $v1
    /* 1744 80103F44 00004484 */  lh         $a0, 0x0($v0)
    /* 1748 80103F48 EF1F040C */  jal        func_80107FBC
    /* 174C 80103F4C 1180103C */   lui       $s0, %hi(D_8010A220)
    /* 1750 80103F50 1180053C */  lui        $a1, %hi(_menuState)
    /* 1754 80103F54 1180043C */  lui        $a0, %hi(D_8010A440)
    /* 1758 80103F58 3CA4A28C */  lw         $v0, %lo(_menuState)($a1)
    /* 175C 80103F5C 02000324 */  addiu      $v1, $zero, 0x2
    /* 1760 80103F60 40A483AC */  sw         $v1, %lo(D_8010A440)($a0)
    /* 1764 80103F64 01004224 */  addiu      $v0, $v0, 0x1
    /* 1768 80103F68 F50F0408 */  j          .L80103FD4
    /* 176C 80103F6C 3CA4A2AC */   sw        $v0, %lo(_menuState)($a1)
  .L80103F70:
    /* 1770 80103F70 6216010C */  jal        vs_main_playSfxDefault
    /* 1774 80103F74 07000524 */   addiu     $a1, $zero, 0x7
    /* 1778 80103F78 F50F0408 */  j          .L80103FD4
    /* 177C 80103F7C 1180103C */   lui       $s0, %hi(D_8010A220)
  .L80103F80:
    /* 1780 80103F80 50006230 */  andi       $v0, $v1, 0x50
    /* 1784 80103F84 12004010 */  beqz       $v0, .L80103FD0
    /* 1788 80103F88 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 178C 80103F8C 6216010C */  jal        vs_main_playSfxDefault
    /* 1790 80103F90 06000524 */   addiu     $a1, $zero, 0x6
    /* 1794 80103F94 EAFE030C */  jal        func_800FFBA8
    /* 1798 80103F98 00000000 */   nop
    /* 179C 80103F9C 1180023C */  lui        $v0, %hi(_menuState)
    /* 17A0 80103FA0 3CA4438C */  lw         $v1, %lo(_menuState)($v0)
    /* 17A4 80103FA4 D0E1048E */  lw         $a0, %lo(vs_main_buttonsPressed)($s0)
    /* 17A8 80103FA8 01006324 */  addiu      $v1, $v1, 0x1
    /* 17AC 80103FAC 10008430 */  andi       $a0, $a0, 0x10
    /* 17B0 80103FB0 05008010 */  beqz       $a0, .L80103FC8
    /* 17B4 80103FB4 3CA443AC */   sw        $v1, %lo(_menuState)($v0)
    /* 17B8 80103FB8 1180033C */  lui        $v1, %hi(D_8010A440)
    /* 17BC 80103FBC 01000224 */  addiu      $v0, $zero, 0x1
    /* 17C0 80103FC0 F40F0408 */  j          .L80103FD0
    /* 17C4 80103FC4 40A462AC */   sw        $v0, %lo(D_8010A440)($v1)
  .L80103FC8:
    /* 17C8 80103FC8 1180023C */  lui        $v0, %hi(D_8010A440)
    /* 17CC 80103FCC 40A440AC */  sw         $zero, %lo(D_8010A440)($v0)
  .L80103FD0:
    /* 17D0 80103FD0 1180103C */  lui        $s0, %hi(D_8010A220)
  .L80103FD4:
    /* 17D4 80103FD4 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 17D8 80103FD8 C017040C */  jal        func_80105F00
    /* 17DC 80103FDC 00000000 */   nop
    /* 17E0 80103FE0 20A2038E */  lw         $v1, %lo(D_8010A220)($s0)
    /* 17E4 80103FE4 00000000 */  nop
    /* 17E8 80103FE8 08006228 */  slti       $v0, $v1, 0x8
    /* 17EC 80103FEC BC024010 */  beqz       $v0, .L80104AE0
    /* 17F0 80103FF0 01006224 */   addiu     $v0, $v1, 0x1
    /* 17F4 80103FF4 B8120408 */  j          .L80104AE0
    /* 17F8 80103FF8 20A202AE */   sw        $v0, %lo(D_8010A220)($s0)
    /* 17FC 80103FFC 1180103C */  lui        $s0, %hi(D_8010A220)
    /* 1800 80104000 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 1804 80104004 C017040C */  jal        func_80105F00
    /* 1808 80104008 00000000 */   nop
    /* 180C 8010400C 20A2028E */  lw         $v0, %lo(D_8010A220)($s0)
    /* 1810 80104010 00000000 */  nop
    /* 1814 80104014 5302401C */  bgtz       $v0, .L80104964
    /* 1818 80104018 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 181C 8010401C 1180023C */  lui        $v0, %hi(D_8010A440)
    /* 1820 80104020 40A4438C */  lw         $v1, %lo(D_8010A440)($v0)
    /* 1824 80104024 02000224 */  addiu      $v0, $zero, 0x2
    /* 1828 80104028 04006214 */  bne        $v1, $v0, .L8010403C
    /* 182C 8010402C 01001024 */   addiu     $s0, $zero, 0x1
    /* 1830 80104030 1180033C */  lui        $v1, %hi(_menuState)
    /* 1834 80104034 B7120408 */  j          .L80104ADC
    /* 1838 80104038 13000224 */   addiu     $v0, $zero, 0x13
  .L8010403C:
    /* 183C 8010403C 20027010 */  beq        $v1, $s0, .L801048C0
    /* 1840 80104040 1180023C */   lui       $v0, %hi(_monBinData)
    /* 1844 80104044 70A4448C */  lw         $a0, %lo(_monBinData)($v0)
    /* 1848 80104048 180F010C */  jal        vs_main_freeHeapR
    /* 184C 8010404C 00000000 */   nop
    /* 1850 80104050 1180023C */  lui        $v0, %hi(_menuState)
    /* 1854 80104054 B8120408 */  j          .L80104AE0
    /* 1858 80104058 3CA450AC */   sw        $s0, %lo(_menuState)($v0)
    /* 185C 8010405C 0F80023C */  lui        $v0, %hi(vs_battle_menu9CursorMemory)
    /* 1860 80104060 F01B4224 */  addiu      $v0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 1864 80104064 02004390 */  lbu        $v1, 0x2($v0)
    /* 1868 80104068 03004290 */  lbu        $v0, 0x3($v0)
    /* 186C 8010406C 1180043C */  lui        $a0, %hi(_monBinData)
    /* 1870 80104070 21186200 */  addu       $v1, $v1, $v0
    /* 1874 80104074 40100300 */  sll        $v0, $v1, 1
    /* 1878 80104078 21104300 */  addu       $v0, $v0, $v1
    /* 187C 8010407C 80100200 */  sll        $v0, $v0, 2
    /* 1880 80104080 23104300 */  subu       $v0, $v0, $v1
    /* 1884 80104084 70A4838C */  lw         $v1, %lo(_monBinData)($a0)
    /* 1888 80104088 80100200 */  sll        $v0, $v0, 2
    /* 188C 8010408C 21104300 */  addu       $v0, $v0, $v1
    /* 1890 80104090 00004484 */  lh         $a0, 0x0($v0)
    /* 1894 80104094 EF1F040C */  jal        func_80107FBC
    /* 1898 80104098 00000000 */   nop
    /* 189C 8010409C 91024014 */  bnez       $v0, .L80104AE4
    /* 18A0 801040A0 21100000 */   addu      $v0, $zero, $zero
    /* 18A4 801040A4 0F80023C */  lui        $v0, %hi(D_800F453C)
    /* 18A8 801040A8 3C45448C */  lw         $a0, %lo(D_800F453C)($v0)
    /* 18AC 801040AC 00000000 */  nop
    /* 18B0 801040B0 56068394 */  lhu        $v1, 0x656($a0)
    /* 18B4 801040B4 3E068494 */  lhu        $a0, 0x63E($a0)
    /* 18B8 801040B8 1180023C */  lui        $v0, %hi(D_8010A44C)
    /* 18BC 801040BC 4CA443A4 */  sh         $v1, %lo(D_8010A44C)($v0)
    /* 18C0 801040C0 1180023C */  lui        $v0, %hi(D_8010A44E)
    /* 18C4 801040C4 4EA444A4 */  sh         $a0, %lo(D_8010A44E)($v0)
    /* 18C8 801040C8 1180043C */  lui        $a0, %hi(D_8010A444)
    /* 18CC 801040CC 001C0300 */  sll        $v1, $v1, 16
    /* 18D0 801040D0 831B0300 */  sra        $v1, $v1, 14
    /* 18D4 801040D4 80026228 */  slti       $v0, $v1, 0x280
    /* 18D8 801040D8 03004010 */  beqz       $v0, .L801040E8
    /* 18DC 801040DC 44A483AC */   sw        $v1, %lo(D_8010A444)($a0)
    /* 18E0 801040E0 3E100408 */  j          .L801040F8
    /* 18E4 801040E4 80020224 */   addiu     $v0, $zero, 0x280
  .L801040E8:
    /* 18E8 801040E8 01186228 */  slti       $v0, $v1, 0x1801
    /* 18EC 801040EC 04004014 */  bnez       $v0, .L80104100
    /* 18F0 801040F0 1180033C */   lui       $v1, %hi(D_8010A430)
    /* 18F4 801040F4 00180224 */  addiu      $v0, $zero, 0x1800
  .L801040F8:
    /* 18F8 801040F8 44A482AC */  sw         $v0, %lo(D_8010A444)($a0)
    /* 18FC 801040FC 1180033C */  lui        $v1, %hi(D_8010A430)
  .L80104100:
    /* 1900 80104100 30A46424 */  addiu      $a0, $v1, %lo(D_8010A430)
    /* 1904 80104104 00010224 */  addiu      $v0, $zero, 0x100
    /* 1908 80104108 020082A4 */  sh         $v0, 0x2($a0)
    /* 190C 8010410C 1180023C */  lui        $v0, %hi(D_8010A448)
    /* 1910 80104110 48A440AC */  sw         $zero, %lo(D_8010A448)($v0)
    /* 1914 80104114 0F80023C */  lui        $v0, %hi(vs_battle_menu9CursorMemory)
    /* 1918 80104118 F01B4224 */  addiu      $v0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 191C 8010411C 30A460A4 */  sh         $zero, %lo(D_8010A430)($v1)
    /* 1920 80104120 040080A4 */  sh         $zero, 0x4($a0)
    /* 1924 80104124 02004390 */  lbu        $v1, 0x2($v0)
    /* 1928 80104128 03004290 */  lbu        $v0, 0x3($v0)
    /* 192C 8010412C 1180043C */  lui        $a0, %hi(D_8010A450)
    /* 1930 80104130 21186200 */  addu       $v1, $v1, $v0
    /* 1934 80104134 D012040C */  jal        func_80104B40
    /* 1938 80104138 50A483A4 */   sh        $v1, %lo(D_8010A450)($a0)
    /* 193C 8010413C 1180023C */  lui        $v0, %hi(D_8010A45C)
    /* 1940 80104140 5CA4448C */  lw         $a0, %lo(D_8010A45C)($v0)
    /* 1944 80104144 8E0A040C */  jal        func_80102A38
    /* 1948 80104148 0100842C */   sltiu     $a0, $a0, 0x1
    /* 194C 8010414C 1180033C */  lui        $v1, %hi(_menuState)
    /* 1950 80104150 3CA4628C */  lw         $v0, %lo(_menuState)($v1)
    /* 1954 80104154 B7120408 */  j          .L80104ADC
    /* 1958 80104158 01004224 */   addiu     $v0, $v0, 0x1
    /* 195C 8010415C 1180023C */  lui        $v0, %hi(D_8010A450)
    /* 1960 80104160 1180043C */  lui        $a0, %hi(_monBinData)
    /* 1964 80104164 50A44384 */  lh         $v1, %lo(D_8010A450)($v0)
    /* 1968 80104168 70A4848C */  lw         $a0, %lo(_monBinData)($a0)
    /* 196C 8010416C 40100300 */  sll        $v0, $v1, 1
    /* 1970 80104170 21104300 */  addu       $v0, $v0, $v1
    /* 1974 80104174 80100200 */  sll        $v0, $v0, 2
    /* 1978 80104178 23104300 */  subu       $v0, $v0, $v1
    /* 197C 8010417C 80100200 */  sll        $v0, $v0, 2
    /* 1980 80104180 21104400 */  addu       $v0, $v0, $a0
    /* 1984 80104184 0D004290 */  lbu        $v0, 0xD($v0)
    /* 1988 80104188 00000000 */  nop
    /* 198C 8010418C 09004310 */  beq        $v0, $v1, .L801041B4
    /* 1990 80104190 1180033C */   lui       $v1, %hi(D_8010A438)
    /* 1994 80104194 38A4628C */  lw         $v0, %lo(D_8010A438)($v1)
    /* 1998 80104198 21200000 */  addu       $a0, $zero, $zero
    /* 199C 8010419C 01004224 */  addiu      $v0, $v0, 0x1
    /* 19A0 801041A0 0F004230 */  andi       $v0, $v0, 0xF
    /* 19A4 801041A4 A61E040C */  jal        func_80107A98
    /* 19A8 801041A8 38A462AC */   sw        $v0, %lo(D_8010A438)($v1)
    /* 19AC 801041AC A61E040C */  jal        func_80107A98
    /* 19B0 801041B0 01000424 */   addiu     $a0, $zero, 0x1
  .L801041B4:
    /* 19B4 801041B4 0680103C */  lui        $s0, %hi(vs_main_buttonsPressed)
    /* 19B8 801041B8 D0E1028E */  lw         $v0, %lo(vs_main_buttonsPressed)($s0)
    /* 19BC 801041BC 00000000 */  nop
    /* 19C0 801041C0 50004230 */  andi       $v0, $v0, 0x50
    /* 19C4 801041C4 19004010 */  beqz       $v0, .L8010422C
    /* 19C8 801041C8 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 19CC 801041CC 6216010C */  jal        vs_main_playSfxDefault
    /* 19D0 801041D0 06000524 */   addiu     $a1, $zero, 0x6
    /* 19D4 801041D4 1180023C */  lui        $v0, %hi(D_8010A45C)
    /* 19D8 801041D8 5CA4428C */  lw         $v0, %lo(D_8010A45C)($v0)
    /* 19DC 801041DC 00000000 */  nop
    /* 19E0 801041E0 04004010 */  beqz       $v0, .L801041F4
    /* 19E4 801041E4 1180023C */   lui       $v0, %hi(_menuState)
    /* 19E8 801041E8 8E0A040C */  jal        func_80102A38
    /* 19EC 801041EC 01000424 */   addiu     $a0, $zero, 0x1
    /* 19F0 801041F0 1180023C */  lui        $v0, %hi(_menuState)
  .L801041F4:
    /* 19F4 801041F4 3CA4438C */  lw         $v1, %lo(_menuState)($v0)
    /* 19F8 801041F8 D0E1048E */  lw         $a0, %lo(vs_main_buttonsPressed)($s0)
    /* 19FC 801041FC 01006324 */  addiu      $v1, $v1, 0x1
    /* 1A00 80104200 10008430 */  andi       $a0, $a0, 0x10
    /* 1A04 80104204 07008010 */  beqz       $a0, .L80104224
    /* 1A08 80104208 3CA443AC */   sw        $v1, %lo(_menuState)($v0)
    /* 1A0C 8010420C EAFE030C */  jal        func_800FFBA8
    /* 1A10 80104210 00000000 */   nop
    /* 1A14 80104214 1180033C */  lui        $v1, %hi(D_8010A440)
    /* 1A18 80104218 01000224 */  addiu      $v0, $zero, 0x1
    /* 1A1C 8010421C 8B100408 */  j          .L8010422C
    /* 1A20 80104220 40A462AC */   sw        $v0, %lo(D_8010A440)($v1)
  .L80104224:
    /* 1A24 80104224 1180023C */  lui        $v0, %hi(D_8010A440)
    /* 1A28 80104228 40A440AC */  sw         $zero, %lo(D_8010A440)($v0)
  .L8010422C:
    /* 1A2C 8010422C 8000023C */  lui        $v0, (0x808080 >> 16)
    /* 1A30 80104230 80804234 */  ori        $v0, $v0, (0x808080 & 0xFFFF)
    /* 1A34 80104234 1180073C */  lui        $a3, %hi(D_8010A458)
    /* 1A38 80104238 1180063C */  lui        $a2, %hi(D_8010A454)
    /* 1A3C 8010423C 58A4E2AC */  sw         $v0, %lo(D_8010A458)($a3)
    /* 1A40 80104240 54A4C2AC */  sw         $v0, %lo(D_8010A454)($a2)
    /* 1A44 80104244 0680023C */  lui        $v0, %hi(vs_main_stickPosBuf)
    /* 1A48 80104248 C0DF438C */  lw         $v1, %lo(vs_main_stickPosBuf)($v0)
    /* 1A4C 8010424C C0DF4524 */  addiu      $a1, $v0, %lo(vs_main_stickPosBuf)
    /* 1A50 80104250 80FF6324 */  addiu      $v1, $v1, -0x80
    /* 1A54 80104254 02006104 */  bgez       $v1, .L80104260
    /* 1A58 80104258 21106000 */   addu      $v0, $v1, $zero
    /* 1A5C 8010425C 23100200 */  negu       $v0, $v0
  .L80104260:
    /* 1A60 80104260 41004228 */  slti       $v0, $v0, 0x41
    /* 1A64 80104264 0B004010 */  beqz       $v0, .L80104294
    /* 1A68 80104268 2000023C */   lui       $v0, (0x202020 >> 16)
    /* 1A6C 8010426C 0400A28C */  lw         $v0, 0x4($a1)
    /* 1A70 80104270 00000000 */  nop
    /* 1A74 80104274 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 1A78 80104278 02004104 */  bgez       $v0, .L80104284
    /* 1A7C 8010427C 00000000 */   nop
    /* 1A80 80104280 23100200 */  negu       $v0, $v0
  .L80104284:
    /* 1A84 80104284 41004228 */  slti       $v0, $v0, 0x41
    /* 1A88 80104288 20004014 */  bnez       $v0, .L8010430C
    /* 1A8C 8010428C 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* 1A90 80104290 2000023C */  lui        $v0, (0x202020 >> 16)
  .L80104294:
    /* 1A94 80104294 20204234 */  ori        $v0, $v0, (0x202020 & 0xFFFF)
    /* 1A98 80104298 54A4C2AC */  sw         $v0, %lo(D_8010A454)($a2)
    /* 1A9C 8010429C C0FF6228 */  slti       $v0, $v1, -0x40
    /* 1AA0 801042A0 06004010 */  beqz       $v0, .L801042BC
    /* 1AA4 801042A4 00000000 */   nop
    /* 1AA8 801042A8 1180033C */  lui        $v1, %hi(D_8010A430)
    /* 1AAC 801042AC 30A46324 */  addiu      $v1, $v1, %lo(D_8010A430)
    /* 1AB0 801042B0 02006294 */  lhu        $v0, 0x2($v1)
    /* 1AB4 801042B4 B7100408 */  j          .L801042DC
    /* 1AB8 801042B8 C0FF4224 */   addiu     $v0, $v0, -0x40
  .L801042BC:
    /* 1ABC 801042BC 41006228 */  slti       $v0, $v1, 0x41
    /* 1AC0 801042C0 08004014 */  bnez       $v0, .L801042E4
    /* 1AC4 801042C4 0680023C */   lui       $v0, %hi(D_8005DFC4)
    /* 1AC8 801042C8 1180033C */  lui        $v1, %hi(D_8010A430)
    /* 1ACC 801042CC 30A46324 */  addiu      $v1, $v1, %lo(D_8010A430)
    /* 1AD0 801042D0 02006294 */  lhu        $v0, 0x2($v1)
    /* 1AD4 801042D4 00000000 */  nop
    /* 1AD8 801042D8 40004224 */  addiu      $v0, $v0, 0x40
  .L801042DC:
    /* 1ADC 801042DC 020062A4 */  sh         $v0, 0x2($v1)
    /* 1AE0 801042E0 0680023C */  lui        $v0, %hi(D_8005DFC4)
  .L801042E4:
    /* 1AE4 801042E4 C4DF428C */  lw         $v0, %lo(D_8005DFC4)($v0)
    /* 1AE8 801042E8 00000000 */  nop
    /* 1AEC 801042EC 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 1AF0 801042F0 C0FF6228 */  slti       $v0, $v1, -0x40
    /* 1AF4 801042F4 39004010 */  beqz       $v0, .L801043DC
    /* 1AF8 801042F8 00000000 */   nop
    /* 1AFC 801042FC 1180033C */  lui        $v1, %hi(D_8010A430)
    /* 1B00 80104300 30A46294 */  lhu        $v0, %lo(D_8010A430)($v1)
    /* 1B04 80104304 FD100408 */  j          .L801043F4
    /* 1B08 80104308 40004224 */   addiu     $v0, $v0, 0x40
  .L8010430C:
    /* 1B0C 8010430C C0E1448C */  lw         $a0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 1B10 80104310 00000000 */  nop
    /* 1B14 80104314 01008230 */  andi       $v0, $a0, 0x1
    /* 1B18 80104318 65004010 */  beqz       $v0, .L801044B0
    /* 1B1C 8010431C 2000023C */   lui       $v0, (0x202020 >> 16)
    /* 1B20 80104320 0800A38C */  lw         $v1, 0x8($a1)
    /* 1B24 80104324 20204234 */  ori        $v0, $v0, (0x202020 & 0xFFFF)
    /* 1B28 80104328 54A4C2AC */  sw         $v0, %lo(D_8010A454)($a2)
    /* 1B2C 8010432C 80FF6324 */  addiu      $v1, $v1, -0x80
    /* 1B30 80104330 02006104 */  bgez       $v1, .L8010433C
    /* 1B34 80104334 21106000 */   addu      $v0, $v1, $zero
    /* 1B38 80104338 23100200 */  negu       $v0, $v0
  .L8010433C:
    /* 1B3C 8010433C 41004228 */  slti       $v0, $v0, 0x41
    /* 1B40 80104340 0B004010 */  beqz       $v0, .L80104370
    /* 1B44 80104344 C0FF6228 */   slti      $v0, $v1, -0x40
    /* 1B48 80104348 0C00A28C */  lw         $v0, 0xC($a1)
    /* 1B4C 8010434C 00000000 */  nop
    /* 1B50 80104350 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 1B54 80104354 02004104 */  bgez       $v0, .L80104360
    /* 1B58 80104358 00000000 */   nop
    /* 1B5C 8010435C 23100200 */  negu       $v0, $v0
  .L80104360:
    /* 1B60 80104360 41004228 */  slti       $v0, $v0, 0x41
    /* 1B64 80104364 25004014 */  bnez       $v0, .L801043FC
    /* 1B68 80104368 00108230 */   andi      $v0, $a0, 0x1000
    /* 1B6C 8010436C C0FF6228 */  slti       $v0, $v1, -0x40
  .L80104370:
    /* 1B70 80104370 06004010 */  beqz       $v0, .L8010438C
    /* 1B74 80104374 00000000 */   nop
    /* 1B78 80104378 1180033C */  lui        $v1, %hi(D_8010A430)
    /* 1B7C 8010437C 30A46324 */  addiu      $v1, $v1, %lo(D_8010A430)
    /* 1B80 80104380 02006294 */  lhu        $v0, 0x2($v1)
    /* 1B84 80104384 EB100408 */  j          .L801043AC
    /* 1B88 80104388 C0FF4224 */   addiu     $v0, $v0, -0x40
  .L8010438C:
    /* 1B8C 8010438C 41006228 */  slti       $v0, $v1, 0x41
    /* 1B90 80104390 08004014 */  bnez       $v0, .L801043B4
    /* 1B94 80104394 0680023C */   lui       $v0, %hi(D_8005DFCC)
    /* 1B98 80104398 1180033C */  lui        $v1, %hi(D_8010A430)
    /* 1B9C 8010439C 30A46324 */  addiu      $v1, $v1, %lo(D_8010A430)
    /* 1BA0 801043A0 02006294 */  lhu        $v0, 0x2($v1)
    /* 1BA4 801043A4 00000000 */  nop
    /* 1BA8 801043A8 40004224 */  addiu      $v0, $v0, 0x40
  .L801043AC:
    /* 1BAC 801043AC 020062A4 */  sh         $v0, 0x2($v1)
    /* 1BB0 801043B0 0680023C */  lui        $v0, %hi(D_8005DFCC)
  .L801043B4:
    /* 1BB4 801043B4 CCDF428C */  lw         $v0, %lo(D_8005DFCC)($v0)
    /* 1BB8 801043B8 00000000 */  nop
    /* 1BBC 801043BC 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 1BC0 801043C0 C0FF6228 */  slti       $v0, $v1, -0x40
    /* 1BC4 801043C4 05004010 */  beqz       $v0, .L801043DC
    /* 1BC8 801043C8 00000000 */   nop
    /* 1BCC 801043CC 1180033C */  lui        $v1, %hi(D_8010A430)
    /* 1BD0 801043D0 30A46294 */  lhu        $v0, %lo(D_8010A430)($v1)
    /* 1BD4 801043D4 FD100408 */  j          .L801043F4
    /* 1BD8 801043D8 40004224 */   addiu     $v0, $v0, 0x40
  .L801043DC:
    /* 1BDC 801043DC 41006228 */  slti       $v0, $v1, 0x41
    /* 1BE0 801043E0 26004014 */  bnez       $v0, .L8010447C
    /* 1BE4 801043E4 1180033C */   lui       $v1, %hi(D_8010A430)
    /* 1BE8 801043E8 30A46294 */  lhu        $v0, %lo(D_8010A430)($v1)
    /* 1BEC 801043EC 00000000 */  nop
    /* 1BF0 801043F0 C0FF4224 */  addiu      $v0, $v0, -0x40
  .L801043F4:
    /* 1BF4 801043F4 1E110408 */  j          .L80104478
    /* 1BF8 801043F8 30A462A4 */   sh        $v0, %lo(D_8010A430)($v1)
  .L801043FC:
    /* 1BFC 801043FC 04004010 */  beqz       $v0, .L80104410
    /* 1C00 80104400 1180033C */   lui       $v1, %hi(D_8010A430)
    /* 1C04 80104404 30A46294 */  lhu        $v0, %lo(D_8010A430)($v1)
    /* 1C08 80104408 0A110408 */  j          .L80104428
    /* 1C0C 8010440C 40004224 */   addiu     $v0, $v0, 0x40
  .L80104410:
    /* 1C10 80104410 00408230 */  andi       $v0, $a0, 0x4000
    /* 1C14 80104414 06004010 */  beqz       $v0, .L80104430
    /* 1C18 80104418 0680023C */   lui       $v0, %hi(vs_main_buttonsPreviousState)
    /* 1C1C 8010441C 30A46294 */  lhu        $v0, %lo(D_8010A430)($v1)
    /* 1C20 80104420 00000000 */  nop
    /* 1C24 80104424 C0FF4224 */  addiu      $v0, $v0, -0x40
  .L80104428:
    /* 1C28 80104428 30A462A4 */  sh         $v0, %lo(D_8010A430)($v1)
    /* 1C2C 8010442C 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
  .L80104430:
    /* 1C30 80104430 C0E1438C */  lw         $v1, %lo(vs_main_buttonsPreviousState)($v0)
    /* 1C34 80104434 00000000 */  nop
    /* 1C38 80104438 00206230 */  andi       $v0, $v1, 0x2000
    /* 1C3C 8010443C 06004010 */  beqz       $v0, .L80104458
    /* 1C40 80104440 00000000 */   nop
    /* 1C44 80104444 1180033C */  lui        $v1, %hi(D_8010A430)
    /* 1C48 80104448 30A46324 */  addiu      $v1, $v1, %lo(D_8010A430)
    /* 1C4C 8010444C 02006294 */  lhu        $v0, 0x2($v1)
    /* 1C50 80104450 1D110408 */  j          .L80104474
    /* 1C54 80104454 40004224 */   addiu     $v0, $v0, 0x40
  .L80104458:
    /* 1C58 80104458 00806230 */  andi       $v0, $v1, 0x8000
    /* 1C5C 8010445C 06004010 */  beqz       $v0, .L80104478
    /* 1C60 80104460 1180033C */   lui       $v1, %hi(D_8010A430)
    /* 1C64 80104464 30A46324 */  addiu      $v1, $v1, %lo(D_8010A430)
    /* 1C68 80104468 02006294 */  lhu        $v0, 0x2($v1)
    /* 1C6C 8010446C 00000000 */  nop
    /* 1C70 80104470 C0FF4224 */  addiu      $v0, $v0, -0x40
  .L80104474:
    /* 1C74 80104474 020062A4 */  sh         $v0, 0x2($v1)
  .L80104478:
    /* 1C78 80104478 1180033C */  lui        $v1, %hi(D_8010A430)
  .L8010447C:
    /* 1C7C 8010447C 30A46284 */  lh         $v0, %lo(D_8010A430)($v1)
    /* 1C80 80104480 00000000 */  nop
    /* 1C84 80104484 05004104 */  bgez       $v0, .L8010449C
    /* 1C88 80104488 01044228 */   slti      $v0, $v0, 0x401
    /* 1C8C 8010448C 30A460A4 */  sh         $zero, %lo(D_8010A430)($v1)
    /* 1C90 80104490 30A46284 */  lh         $v0, %lo(D_8010A430)($v1)
    /* 1C94 80104494 00000000 */  nop
    /* 1C98 80104498 01044228 */  slti       $v0, $v0, 0x401
  .L8010449C:
    /* 1C9C 8010449C 42004014 */  bnez       $v0, .L801045A8
    /* 1CA0 801044A0 0680113C */   lui       $s1, %hi(vs_main_buttonsPressed)
    /* 1CA4 801044A4 00040224 */  addiu      $v0, $zero, 0x400
    /* 1CA8 801044A8 6A110408 */  j          .L801045A8
    /* 1CAC 801044AC 30A462A4 */   sh        $v0, %lo(D_8010A430)($v1)
  .L801044B0:
    /* 1CB0 801044B0 02008230 */  andi       $v0, $a0, 0x2
    /* 1CB4 801044B4 3B004010 */  beqz       $v0, .L801045A4
    /* 1CB8 801044B8 2000033C */   lui       $v1, (0x202020 >> 16)
    /* 1CBC 801044BC 0800A28C */  lw         $v0, 0x8($a1)
    /* 1CC0 801044C0 20206334 */  ori        $v1, $v1, (0x202020 & 0xFFFF)
    /* 1CC4 801044C4 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 1CC8 801044C8 02004104 */  bgez       $v0, .L801044D4
    /* 1CCC 801044CC 00000000 */   nop
    /* 1CD0 801044D0 23100200 */  negu       $v0, $v0
  .L801044D4:
    /* 1CD4 801044D4 41004228 */  slti       $v0, $v0, 0x41
    /* 1CD8 801044D8 0A004010 */  beqz       $v0, .L80104504
    /* 1CDC 801044DC 58A4E3AC */   sw        $v1, %lo(D_8010A458)($a3)
    /* 1CE0 801044E0 0C00A28C */  lw         $v0, 0xC($a1)
    /* 1CE4 801044E4 00000000 */  nop
    /* 1CE8 801044E8 80FF4224 */  addiu      $v0, $v0, -0x80
    /* 1CEC 801044EC 02004104 */  bgez       $v0, .L801044F8
    /* 1CF0 801044F0 00000000 */   nop
    /* 1CF4 801044F4 23100200 */  negu       $v0, $v0
  .L801044F8:
    /* 1CF8 801044F8 41004228 */  slti       $v0, $v0, 0x41
    /* 1CFC 801044FC 12004014 */  bnez       $v0, .L80104548
    /* 1D00 80104500 00108230 */   andi      $v0, $a0, 0x1000
  .L80104504:
    /* 1D04 80104504 0C00A28C */  lw         $v0, 0xC($a1)
    /* 1D08 80104508 00000000 */  nop
    /* 1D0C 8010450C 80FF4324 */  addiu      $v1, $v0, -0x80
    /* 1D10 80104510 C0FF6228 */  slti       $v0, $v1, -0x40
    /* 1D14 80104514 05004010 */  beqz       $v0, .L8010452C
    /* 1D18 80104518 00000000 */   nop
    /* 1D1C 8010451C 1180033C */  lui        $v1, %hi(D_8010A444)
    /* 1D20 80104520 44A4628C */  lw         $v0, %lo(D_8010A444)($v1)
    /* 1D24 80104524 5D110408 */  j          .L80104574
    /* 1D28 80104528 FCFF4224 */   addiu     $v0, $v0, -0x4
  .L8010452C:
    /* 1D2C 8010452C 41006228 */  slti       $v0, $v1, 0x41
    /* 1D30 80104530 12004014 */  bnez       $v0, .L8010457C
    /* 1D34 80104534 1180043C */   lui       $a0, %hi(D_8010A444)
    /* 1D38 80104538 1180033C */  lui        $v1, %hi(D_8010A444)
    /* 1D3C 8010453C 44A4628C */  lw         $v0, %lo(D_8010A444)($v1)
    /* 1D40 80104540 5D110408 */  j          .L80104574
    /* 1D44 80104544 04004224 */   addiu     $v0, $v0, 0x4
  .L80104548:
    /* 1D48 80104548 04004010 */  beqz       $v0, .L8010455C
    /* 1D4C 8010454C 1180033C */   lui       $v1, %hi(D_8010A444)
    /* 1D50 80104550 44A4628C */  lw         $v0, %lo(D_8010A444)($v1)
    /* 1D54 80104554 5D110408 */  j          .L80104574
    /* 1D58 80104558 C0FF4224 */   addiu     $v0, $v0, -0x40
  .L8010455C:
    /* 1D5C 8010455C 00408230 */  andi       $v0, $a0, 0x4000
    /* 1D60 80104560 06004010 */  beqz       $v0, .L8010457C
    /* 1D64 80104564 1180043C */   lui       $a0, %hi(D_8010A444)
    /* 1D68 80104568 44A4628C */  lw         $v0, %lo(D_8010A444)($v1)
    /* 1D6C 8010456C 00000000 */  nop
    /* 1D70 80104570 40004224 */  addiu      $v0, $v0, 0x40
  .L80104574:
    /* 1D74 80104574 44A462AC */  sw         $v0, %lo(D_8010A444)($v1)
    /* 1D78 80104578 1180043C */  lui        $a0, %hi(D_8010A444)
  .L8010457C:
    /* 1D7C 8010457C 44A4838C */  lw         $v1, %lo(D_8010A444)($a0)
    /* 1D80 80104580 00000000 */  nop
    /* 1D84 80104584 80026228 */  slti       $v0, $v1, 0x280
    /* 1D88 80104588 05004014 */  bnez       $v0, .L801045A0
    /* 1D8C 8010458C 80020224 */   addiu     $v0, $zero, 0x280
    /* 1D90 80104590 01186228 */  slti       $v0, $v1, 0x1801
    /* 1D94 80104594 04004014 */  bnez       $v0, .L801045A8
    /* 1D98 80104598 0680113C */   lui       $s1, %hi(vs_main_buttonsPressed)
    /* 1D9C 8010459C 00180224 */  addiu      $v0, $zero, 0x1800
  .L801045A0:
    /* 1DA0 801045A0 44A482AC */  sw         $v0, %lo(D_8010A444)($a0)
  .L801045A4:
    /* 1DA4 801045A4 0680113C */  lui        $s1, %hi(vs_main_buttonsPressed)
  .L801045A8:
    /* 1DA8 801045A8 D0E1228E */  lw         $v0, %lo(vs_main_buttonsPressed)($s1)
    /* 1DAC 801045AC 00000000 */  nop
    /* 1DB0 801045B0 00014230 */  andi       $v0, $v0, 0x100
    /* 1DB4 801045B4 08004010 */  beqz       $v0, .L801045D8
    /* 1DB8 801045B8 1180103C */   lui       $s0, %hi(D_8010A45C)
    /* 1DBC 801045BC 5CA4048E */  lw         $a0, %lo(D_8010A45C)($s0)
    /* 1DC0 801045C0 8E0A040C */  jal        func_80102A38
    /* 1DC4 801045C4 00000000 */   nop
    /* 1DC8 801045C8 5CA4028E */  lw         $v0, %lo(D_8010A45C)($s0)
    /* 1DCC 801045CC 00000000 */  nop
    /* 1DD0 801045D0 01004238 */  xori       $v0, $v0, 0x1
    /* 1DD4 801045D4 5CA402AE */  sw         $v0, %lo(D_8010A45C)($s0)
  .L801045D8:
    /* 1DD8 801045D8 0680023C */  lui        $v0, %hi(vs_main_buttonsPreviousState)
    /* 1DDC 801045DC C0E1428C */  lw         $v0, %lo(vs_main_buttonsPreviousState)($v0)
    /* 1DE0 801045E0 0C000324 */  addiu      $v1, $zero, 0xC
    /* 1DE4 801045E4 0C004230 */  andi       $v0, $v0, 0xC
    /* 1DE8 801045E8 66004310 */  beq        $v0, $v1, .L80104784
    /* 1DEC 801045EC 1180103C */   lui       $s0, %hi(D_8010A220)
    /* 1DF0 801045F0 D0E1228E */  lw         $v0, %lo(vs_main_buttonsPressed)($s1)
    /* 1DF4 801045F4 00000000 */  nop
    /* 1DF8 801045F8 24104300 */  and        $v0, $v0, $v1
    /* 1DFC 801045FC 02004010 */  beqz       $v0, .L80104608
    /* 1E00 80104600 1180023C */   lui       $v0, %hi(D_8010A452)
    /* 1E04 80104604 52A440A4 */  sh         $zero, %lo(D_8010A452)($v0)
  .L80104608:
    /* 1E08 80104608 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 1E0C 8010460C DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 1E10 80104610 00000000 */  nop
    /* 1E14 80104614 08004230 */  andi       $v0, $v0, 0x8
    /* 1E18 80104618 2A004010 */  beqz       $v0, .L801046C4
    /* 1E1C 8010461C 1180023C */   lui       $v0, %hi(D_8010A452)
    /* 1E20 80104620 52A44284 */  lh         $v0, %lo(D_8010A452)($v0)
    /* 1E24 80104624 00000000 */  nop
    /* 1E28 80104628 21004014 */  bnez       $v0, .L801046B0
    /* 1E2C 8010462C 1180033C */   lui       $v1, %hi(D_8010A452)
    /* 1E30 80104630 1180103C */  lui        $s0, %hi(D_8010A450)
    /* 1E34 80104634 1180113C */  lui        $s1, %hi(_monBinData)
    /* 1E38 80104638 50A40386 */  lh         $v1, %lo(D_8010A450)($s0)
    /* 1E3C 8010463C 70A4248E */  lw         $a0, %lo(_monBinData)($s1)
    /* 1E40 80104640 40100300 */  sll        $v0, $v1, 1
    /* 1E44 80104644 21104300 */  addu       $v0, $v0, $v1
    /* 1E48 80104648 80100200 */  sll        $v0, $v0, 2
    /* 1E4C 8010464C 23104300 */  subu       $v0, $v0, $v1
    /* 1E50 80104650 80100200 */  sll        $v0, $v0, 2
    /* 1E54 80104654 21104400 */  addu       $v0, $v0, $a0
    /* 1E58 80104658 0E004290 */  lbu        $v0, 0xE($v0)
    /* 1E5C 8010465C 00000000 */  nop
    /* 1E60 80104660 12004310 */  beq        $v0, $v1, .L801046AC
    /* 1E64 80104664 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 1E68 80104668 6216010C */  jal        vs_main_playSfxDefault
    /* 1E6C 8010466C 0B000524 */   addiu     $a1, $zero, 0xB
    /* 1E70 80104670 50A40386 */  lh         $v1, %lo(D_8010A450)($s0)
    /* 1E74 80104674 00000000 */  nop
    /* 1E78 80104678 40100300 */  sll        $v0, $v1, 1
    /* 1E7C 8010467C 21104300 */  addu       $v0, $v0, $v1
    /* 1E80 80104680 80100200 */  sll        $v0, $v0, 2
    /* 1E84 80104684 23104300 */  subu       $v0, $v0, $v1
    /* 1E88 80104688 70A4238E */  lw         $v1, %lo(_monBinData)($s1)
    /* 1E8C 8010468C 80100200 */  sll        $v0, $v0, 2
    /* 1E90 80104690 21104300 */  addu       $v0, $v0, $v1
    /* 1E94 80104694 1180033C */  lui        $v1, %hi(D_8010A448)
    /* 1E98 80104698 0E004490 */  lbu        $a0, 0xE($v0)
    /* 1E9C 8010469C 08000224 */  addiu      $v0, $zero, 0x8
    /* 1EA0 801046A0 48A462AC */  sw         $v0, %lo(D_8010A448)($v1)
    /* 1EA4 801046A4 D012040C */  jal        func_80104B40
    /* 1EA8 801046A8 50A404A6 */   sh        $a0, %lo(D_8010A450)($s0)
  .L801046AC:
    /* 1EAC 801046AC 1180033C */  lui        $v1, %hi(D_8010A452)
  .L801046B0:
    /* 1EB0 801046B0 52A46294 */  lhu        $v0, %lo(D_8010A452)($v1)
    /* 1EB4 801046B4 00000000 */  nop
    /* 1EB8 801046B8 01004224 */  addiu      $v0, $v0, 0x1
    /* 1EBC 801046BC 03004230 */  andi       $v0, $v0, 0x3
    /* 1EC0 801046C0 52A462A4 */  sh         $v0, %lo(D_8010A452)($v1)
  .L801046C4:
    /* 1EC4 801046C4 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* 1EC8 801046C8 DCDF428C */  lw         $v0, %lo(vs_main_buttonRepeat)($v0)
    /* 1ECC 801046CC 00000000 */  nop
    /* 1ED0 801046D0 04004230 */  andi       $v0, $v0, 0x4
    /* 1ED4 801046D4 2A004010 */  beqz       $v0, .L80104780
    /* 1ED8 801046D8 1180023C */   lui       $v0, %hi(D_8010A452)
    /* 1EDC 801046DC 52A44284 */  lh         $v0, %lo(D_8010A452)($v0)
    /* 1EE0 801046E0 00000000 */  nop
    /* 1EE4 801046E4 21004014 */  bnez       $v0, .L8010476C
    /* 1EE8 801046E8 1180033C */   lui       $v1, %hi(D_8010A452)
    /* 1EEC 801046EC 1180103C */  lui        $s0, %hi(D_8010A450)
    /* 1EF0 801046F0 1180113C */  lui        $s1, %hi(_monBinData)
    /* 1EF4 801046F4 50A40386 */  lh         $v1, %lo(D_8010A450)($s0)
    /* 1EF8 801046F8 70A4248E */  lw         $a0, %lo(_monBinData)($s1)
    /* 1EFC 801046FC 40100300 */  sll        $v0, $v1, 1
    /* 1F00 80104700 21104300 */  addu       $v0, $v0, $v1
    /* 1F04 80104704 80100200 */  sll        $v0, $v0, 2
    /* 1F08 80104708 23104300 */  subu       $v0, $v0, $v1
    /* 1F0C 8010470C 80100200 */  sll        $v0, $v0, 2
    /* 1F10 80104710 21104400 */  addu       $v0, $v0, $a0
    /* 1F14 80104714 0D004290 */  lbu        $v0, 0xD($v0)
    /* 1F18 80104718 00000000 */  nop
    /* 1F1C 8010471C 12004310 */  beq        $v0, $v1, .L80104768
    /* 1F20 80104720 7E000424 */   addiu     $a0, $zero, 0x7E
    /* 1F24 80104724 6216010C */  jal        vs_main_playSfxDefault
    /* 1F28 80104728 0B000524 */   addiu     $a1, $zero, 0xB
    /* 1F2C 8010472C 50A40386 */  lh         $v1, %lo(D_8010A450)($s0)
    /* 1F30 80104730 00000000 */  nop
    /* 1F34 80104734 40100300 */  sll        $v0, $v1, 1
    /* 1F38 80104738 21104300 */  addu       $v0, $v0, $v1
    /* 1F3C 8010473C 80100200 */  sll        $v0, $v0, 2
    /* 1F40 80104740 23104300 */  subu       $v0, $v0, $v1
    /* 1F44 80104744 70A4238E */  lw         $v1, %lo(_monBinData)($s1)
    /* 1F48 80104748 80100200 */  sll        $v0, $v0, 2
    /* 1F4C 8010474C 21104300 */  addu       $v0, $v0, $v1
    /* 1F50 80104750 1180033C */  lui        $v1, %hi(D_8010A448)
    /* 1F54 80104754 0D004490 */  lbu        $a0, 0xD($v0)
    /* 1F58 80104758 04000224 */  addiu      $v0, $zero, 0x4
    /* 1F5C 8010475C 48A462AC */  sw         $v0, %lo(D_8010A448)($v1)
    /* 1F60 80104760 D012040C */  jal        func_80104B40
    /* 1F64 80104764 50A404A6 */   sh        $a0, %lo(D_8010A450)($s0)
  .L80104768:
    /* 1F68 80104768 1180033C */  lui        $v1, %hi(D_8010A452)
  .L8010476C:
    /* 1F6C 8010476C 52A46294 */  lhu        $v0, %lo(D_8010A452)($v1)
    /* 1F70 80104770 00000000 */  nop
    /* 1F74 80104774 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F78 80104778 03004230 */  andi       $v0, $v0, 0x3
    /* 1F7C 8010477C 52A462A4 */  sh         $v0, %lo(D_8010A452)($v1)
  .L80104780:
    /* 1F80 80104780 1180103C */  lui        $s0, %hi(D_8010A220)
  .L80104784:
    /* 1F84 80104784 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 1F88 80104788 7E18040C */  jal        func_801061F8
    /* 1F8C 8010478C 21280000 */   addu      $a1, $zero, $zero
    /* 1F90 80104790 20A2028E */  lw         $v0, %lo(D_8010A220)($s0)
    /* 1F94 80104794 00000000 */  nop
    /* 1F98 80104798 08004228 */  slti       $v0, $v0, 0x8
    /* 1F9C 8010479C 0E004010 */  beqz       $v0, .L801047D8
    /* 1FA0 801047A0 0580023C */   lui       $v0, %hi(vs_main_buttonsReleased)
    /* 1FA4 801047A4 7D33030C */  jal        vs_battle_getTextBox
    /* 1FA8 801047A8 21200000 */   addu      $a0, $zero, $zero
    /* 1FAC 801047AC 21204000 */  addu       $a0, $v0, $zero
    /* 1FB0 801047B0 14008294 */  lhu        $v0, 0x14($a0)
    /* 1FB4 801047B4 20A2038E */  lw         $v1, %lo(D_8010A220)($s0)
    /* 1FB8 801047B8 F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 1FBC 801047BC 140082A4 */  sh         $v0, 0x14($a0)
    /* 1FC0 801047C0 10008294 */  lhu        $v0, 0x10($a0)
    /* 1FC4 801047C4 01006324 */  addiu      $v1, $v1, 0x1
    /* 1FC8 801047C8 20A203AE */  sw         $v1, %lo(D_8010A220)($s0)
    /* 1FCC 801047CC F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 1FD0 801047D0 100082A4 */  sh         $v0, 0x10($a0)
    /* 1FD4 801047D4 0580023C */  lui        $v0, %hi(vs_main_buttonsReleased)
  .L801047D8:
    /* 1FD8 801047D8 1180043C */  lui        $a0, %hi(D_8010A448)
    /* 1FDC 801047DC 785C428C */  lw         $v0, %lo(vs_main_buttonsReleased)($v0)
    /* 1FE0 801047E0 48A4838C */  lw         $v1, %lo(D_8010A448)($a0)
    /* 1FE4 801047E4 00000000 */  nop
    /* 1FE8 801047E8 24104300 */  and        $v0, $v0, $v1
    /* 1FEC 801047EC BC004010 */  beqz       $v0, .L80104AE0
    /* 1FF0 801047F0 08000224 */   addiu     $v0, $zero, 0x8
    /* 1FF4 801047F4 03006214 */  bne        $v1, $v0, .L80104804
    /* 1FF8 801047F8 00000000 */   nop
    /* 1FFC 801047FC 02120408 */  j          .L80104808
    /* 2000 80104800 01000224 */   addiu     $v0, $zero, 0x1
  .L80104804:
    /* 2004 80104804 02000224 */  addiu      $v0, $zero, 0x2
  .L80104808:
    /* 2008 80104808 48A482AC */  sw         $v0, %lo(D_8010A448)($a0)
    /* 200C 8010480C 2000033C */  lui        $v1, (0x202020 >> 16)
    /* 2010 80104810 20206334 */  ori        $v1, $v1, (0x202020 & 0xFFFF)
    /* 2014 80104814 1180023C */  lui        $v0, %hi(D_8010A458)
    /* 2018 80104818 58A443AC */  sw         $v1, %lo(D_8010A458)($v0)
    /* 201C 8010481C 1180023C */  lui        $v0, %hi(D_8010A454)
    /* 2020 80104820 54A443AC */  sw         $v1, %lo(D_8010A454)($v0)
    /* 2024 80104824 1180033C */  lui        $v1, %hi(_menuState)
    /* 2028 80104828 B7120408 */  j          .L80104ADC
    /* 202C 8010482C 19000224 */   addiu     $v0, $zero, 0x19
    /* 2030 80104830 2000033C */  lui        $v1, (0x202020 >> 16)
    /* 2034 80104834 20206334 */  ori        $v1, $v1, (0x202020 & 0xFFFF)
    /* 2038 80104838 21280000 */  addu       $a1, $zero, $zero
    /* 203C 8010483C 1180103C */  lui        $s0, %hi(D_8010A220)
    /* 2040 80104840 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 2044 80104844 1180023C */  lui        $v0, %hi(D_8010A458)
    /* 2048 80104848 58A443AC */  sw         $v1, %lo(D_8010A458)($v0)
    /* 204C 8010484C 1180023C */  lui        $v0, %hi(D_8010A454)
    /* 2050 80104850 7E18040C */  jal        func_801061F8
    /* 2054 80104854 54A443AC */   sw        $v1, %lo(D_8010A454)($v0)
    /* 2058 80104858 20A2028E */  lw         $v0, %lo(D_8010A220)($s0)
    /* 205C 8010485C 00000000 */  nop
    /* 2060 80104860 0F004018 */  blez       $v0, .L801048A0
    /* 2064 80104864 00000000 */   nop
    /* 2068 80104868 7D33030C */  jal        vs_battle_getTextBox
    /* 206C 8010486C 21200000 */   addu      $a0, $zero, $zero
    /* 2070 80104870 21204000 */  addu       $a0, $v0, $zero
    /* 2074 80104874 07008010 */  beqz       $a0, .L80104894
    /* 2078 80104878 00000000 */   nop
    /* 207C 8010487C 14008294 */  lhu        $v0, 0x14($a0)
    /* 2080 80104880 10008394 */  lhu        $v1, 0x10($a0)
    /* 2084 80104884 10004224 */  addiu      $v0, $v0, 0x10
    /* 2088 80104888 10006324 */  addiu      $v1, $v1, 0x10
    /* 208C 8010488C 140082A4 */  sh         $v0, 0x14($a0)
    /* 2090 80104890 100083A4 */  sh         $v1, 0x10($a0)
  .L80104894:
    /* 2094 80104894 20A2028E */  lw         $v0, %lo(D_8010A220)($s0)
    /* 2098 80104898 59120408 */  j          .L80104964
    /* 209C 8010489C FFFF4224 */   addiu     $v0, $v0, -0x1
  .L801048A0:
    /* 20A0 801048A0 2620040C */  jal        func_80108098
    /* 20A4 801048A4 00000000 */   nop
    /* 20A8 801048A8 1180023C */  lui        $v0, %hi(D_8010A440)
    /* 20AC 801048AC 40A4428C */  lw         $v0, %lo(D_8010A440)($v0)
    /* 20B0 801048B0 00000000 */  nop
    /* 20B4 801048B4 09004010 */  beqz       $v0, .L801048DC
    /* 20B8 801048B8 00000000 */   nop
    /* 20BC 801048BC 1180023C */  lui        $v0, %hi(_monBinData)
  .L801048C0:
    /* 20C0 801048C0 70A4448C */  lw         $a0, %lo(_monBinData)($v0)
    /* 20C4 801048C4 180F010C */  jal        vs_main_freeHeapR
    /* 20C8 801048C8 00000000 */   nop
  .L801048CC:
    /* 20CC 801048CC BE12040C */  jal        func_80104AF8
    /* 20D0 801048D0 00000000 */   nop
    /* 20D4 801048D4 B9120408 */  j          .L80104AE4
    /* 20D8 801048D8 02000224 */   addiu     $v0, $zero, 0x2
  .L801048DC:
    /* 20DC 801048DC 0F80023C */  lui        $v0, %hi(vs_battle_menu9CursorMemory)
    /* 20E0 801048E0 F01B4224 */  addiu      $v0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 20E4 801048E4 02004390 */  lbu        $v1, 0x2($v0)
    /* 20E8 801048E8 03004290 */  lbu        $v0, 0x3($v0)
    /* 20EC 801048EC 00000000 */  nop
    /* 20F0 801048F0 21186200 */  addu       $v1, $v1, $v0
    /* 20F4 801048F4 1180023C */  lui        $v0, %hi(_enemyDescriptions)
    /* 20F8 801048F8 74A4458C */  lw         $a1, %lo(_enemyDescriptions)($v0)
    /* 20FC 801048FC 40100300 */  sll        $v0, $v1, 1
    /* 2100 80104900 21104500 */  addu       $v0, $v0, $a1
    /* 2104 80104904 00004494 */  lhu        $a0, 0x0($v0)
    /* 2108 80104908 1180023C */  lui        $v0, %hi(D_8010A450)
    /* 210C 8010490C 50A443A4 */  sh         $v1, %lo(D_8010A450)($v0)
    /* 2110 80104910 40200400 */  sll        $a0, $a0, 1
    /* 2114 80104914 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 2118 80104918 2120A400 */   addu      $a0, $a1, $a0
    /* 211C 8010491C 1180033C */  lui        $v1, %hi(_menuState)
    /* 2120 80104920 B7120408 */  j          .L80104ADC
    /* 2124 80104924 0E000224 */   addiu     $v0, $zero, 0xE
    /* 2128 80104928 A61E040C */  jal        func_80107A98
    /* 212C 8010492C 02000424 */   addiu     $a0, $zero, 0x2
    /* 2130 80104930 A61E040C */  jal        func_80107A98
    /* 2134 80104934 03000424 */   addiu     $a0, $zero, 0x3
    /* 2138 80104938 1180103C */  lui        $s0, %hi(D_8010A220)
    /* 213C 8010493C 1180023C */  lui        $v0, %hi(D_8010A448)
    /* 2140 80104940 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 2144 80104944 48A4458C */  lw         $a1, %lo(D_8010A448)($v0)
    /* 2148 80104948 7E18040C */  jal        func_801061F8
    /* 214C 8010494C 00000000 */   nop
    /* 2150 80104950 20A2028E */  lw         $v0, %lo(D_8010A220)($s0)
    /* 2154 80104954 00000000 */  nop
    /* 2158 80104958 04004018 */  blez       $v0, .L8010496C
    /* 215C 8010495C 00000000 */   nop
    /* 2160 80104960 FFFF4224 */  addiu      $v0, $v0, -0x1
  .L80104964:
    /* 2164 80104964 B8120408 */  j          .L80104AE0
    /* 2168 80104968 20A202AE */   sw        $v0, %lo(D_8010A220)($s0)
  .L8010496C:
    /* 216C 8010496C 2620040C */  jal        func_80108098
    /* 2170 80104970 00000000 */   nop
    /* 2174 80104974 1180023C */  lui        $v0, %hi(D_8010A450)
    /* 2178 80104978 50A44384 */  lh         $v1, %lo(D_8010A450)($v0)
    /* 217C 8010497C 1180043C */  lui        $a0, %hi(_monBinData)
    /* 2180 80104980 40100300 */  sll        $v0, $v1, 1
    /* 2184 80104984 21104300 */  addu       $v0, $v0, $v1
    /* 2188 80104988 80100200 */  sll        $v0, $v0, 2
    /* 218C 8010498C 23104300 */  subu       $v0, $v0, $v1
    /* 2190 80104990 70A4838C */  lw         $v1, %lo(_monBinData)($a0)
    /* 2194 80104994 80100200 */  sll        $v0, $v0, 2
    /* 2198 80104998 21104300 */  addu       $v0, $v0, $v1
    /* 219C 8010499C 00004484 */  lh         $a0, 0x0($v0)
    /* 21A0 801049A0 EF1F040C */  jal        func_80107FBC
    /* 21A4 801049A4 00000000 */   nop
    /* 21A8 801049A8 1180033C */  lui        $v1, %hi(_menuState)
    /* 21AC 801049AC 3CA4628C */  lw         $v0, %lo(_menuState)($v1)
    /* 21B0 801049B0 B7120408 */  j          .L80104ADC
    /* 21B4 801049B4 01004224 */   addiu     $v0, $v0, 0x1
    /* 21B8 801049B8 A61E040C */  jal        func_80107A98
    /* 21BC 801049BC 02000424 */   addiu     $a0, $zero, 0x2
    /* 21C0 801049C0 A61E040C */  jal        func_80107A98
    /* 21C4 801049C4 03000424 */   addiu     $a0, $zero, 0x3
    /* 21C8 801049C8 1180023C */  lui        $v0, %hi(D_8010A220)
    /* 21CC 801049CC 20A2448C */  lw         $a0, %lo(D_8010A220)($v0)
    /* 21D0 801049D0 7E18040C */  jal        func_801061F8
    /* 21D4 801049D4 03000524 */   addiu     $a1, $zero, 0x3
    /* 21D8 801049D8 0F80023C */  lui        $v0, %hi(vs_battle_menu9CursorMemory)
    /* 21DC 801049DC F01B4224 */  addiu      $v0, $v0, %lo(vs_battle_menu9CursorMemory)
    /* 21E0 801049E0 02004390 */  lbu        $v1, 0x2($v0)
    /* 21E4 801049E4 03004290 */  lbu        $v0, 0x3($v0)
    /* 21E8 801049E8 1180043C */  lui        $a0, %hi(_monBinData)
    /* 21EC 801049EC 21186200 */  addu       $v1, $v1, $v0
    /* 21F0 801049F0 40100300 */  sll        $v0, $v1, 1
    /* 21F4 801049F4 21104300 */  addu       $v0, $v0, $v1
    /* 21F8 801049F8 80100200 */  sll        $v0, $v0, 2
    /* 21FC 801049FC 23104300 */  subu       $v0, $v0, $v1
    /* 2200 80104A00 70A4838C */  lw         $v1, %lo(_monBinData)($a0)
    /* 2204 80104A04 80100200 */  sll        $v0, $v0, 2
    /* 2208 80104A08 21104300 */  addu       $v0, $v0, $v1
    /* 220C 80104A0C 00004484 */  lh         $a0, 0x0($v0)
    /* 2210 80104A10 EF1F040C */  jal        func_80107FBC
    /* 2214 80104A14 00000000 */   nop
    /* 2218 80104A18 32004014 */  bnez       $v0, .L80104AE4
    /* 221C 80104A1C 21100000 */   addu      $v0, $zero, $zero
    /* 2220 80104A20 0F80023C */  lui        $v0, %hi(D_800F453C)
    /* 2224 80104A24 3C45448C */  lw         $a0, %lo(D_800F453C)($v0)
    /* 2228 80104A28 00000000 */  nop
    /* 222C 80104A2C 56068394 */  lhu        $v1, 0x656($a0)
    /* 2230 80104A30 3E068494 */  lhu        $a0, 0x63E($a0)
    /* 2234 80104A34 1180023C */  lui        $v0, %hi(D_8010A44C)
    /* 2238 80104A38 4CA443A4 */  sh         $v1, %lo(D_8010A44C)($v0)
    /* 223C 80104A3C 1180023C */  lui        $v0, %hi(D_8010A44E)
    /* 2240 80104A40 4EA444A4 */  sh         $a0, %lo(D_8010A44E)($v0)
    /* 2244 80104A44 1180043C */  lui        $a0, %hi(D_8010A444)
    /* 2248 80104A48 001C0300 */  sll        $v1, $v1, 16
    /* 224C 80104A4C 831B0300 */  sra        $v1, $v1, 14
    /* 2250 80104A50 80026228 */  slti       $v0, $v1, 0x280
    /* 2254 80104A54 03004010 */  beqz       $v0, .L80104A64
    /* 2258 80104A58 44A483AC */   sw        $v1, %lo(D_8010A444)($a0)
    /* 225C 80104A5C 9D120408 */  j          .L80104A74
    /* 2260 80104A60 80020224 */   addiu     $v0, $zero, 0x280
  .L80104A64:
    /* 2264 80104A64 01186228 */  slti       $v0, $v1, 0x1801
    /* 2268 80104A68 04004014 */  bnez       $v0, .L80104A7C
    /* 226C 80104A6C 1180033C */   lui       $v1, %hi(_menuState)
    /* 2270 80104A70 00180224 */  addiu      $v0, $zero, 0x1800
  .L80104A74:
    /* 2274 80104A74 44A482AC */  sw         $v0, %lo(D_8010A444)($a0)
    /* 2278 80104A78 1180033C */  lui        $v1, %hi(_menuState)
  .L80104A7C:
    /* 227C 80104A7C 3CA4628C */  lw         $v0, %lo(_menuState)($v1)
    /* 2280 80104A80 B7120408 */  j          .L80104ADC
    /* 2284 80104A84 01004224 */   addiu     $v0, $v0, 0x1
    /* 2288 80104A88 A61E040C */  jal        func_80107A98
    /* 228C 80104A8C 02000424 */   addiu     $a0, $zero, 0x2
    /* 2290 80104A90 A61E040C */  jal        func_80107A98
    /* 2294 80104A94 03000424 */   addiu     $a0, $zero, 0x3
    /* 2298 80104A98 1180103C */  lui        $s0, %hi(D_8010A220)
    /* 229C 80104A9C 1180113C */  lui        $s1, %hi(D_8010A448)
    /* 22A0 80104AA0 03000524 */  addiu      $a1, $zero, 0x3
    /* 22A4 80104AA4 48A4228E */  lw         $v0, %lo(D_8010A448)($s1)
    /* 22A8 80104AA8 20A2048E */  lw         $a0, %lo(D_8010A220)($s0)
    /* 22AC 80104AAC 7E18040C */  jal        func_801061F8
    /* 22B0 80104AB0 2328A200 */   subu      $a1, $a1, $v0
    /* 22B4 80104AB4 20A2038E */  lw         $v1, %lo(D_8010A220)($s0)
    /* 22B8 80104AB8 00000000 */  nop
    /* 22BC 80104ABC 08006228 */  slti       $v0, $v1, 0x8
    /* 22C0 80104AC0 03004010 */  beqz       $v0, .L80104AD0
    /* 22C4 80104AC4 01006224 */   addiu     $v0, $v1, 0x1
    /* 22C8 80104AC8 B8120408 */  j          .L80104AE0
    /* 22CC 80104ACC 20A202AE */   sw        $v0, %lo(D_8010A220)($s0)
  .L80104AD0:
    /* 22D0 80104AD0 1180033C */  lui        $v1, %hi(_menuState)
    /* 22D4 80104AD4 14000224 */  addiu      $v0, $zero, 0x14
    /* 22D8 80104AD8 48A420AE */  sw         $zero, %lo(D_8010A448)($s1)
  .L80104ADC:
    /* 22DC 80104ADC 3CA462AC */  sw         $v0, %lo(_menuState)($v1)
  .L80104AE0:
    /* 22E0 80104AE0 21100000 */  addu       $v0, $zero, $zero
  .L80104AE4:
    /* 22E4 80104AE4 4800BF8F */  lw         $ra, 0x48($sp)
    /* 22E8 80104AE8 4400B18F */  lw         $s1, 0x44($sp)
    /* 22EC 80104AEC 4000B08F */  lw         $s0, 0x40($sp)
    /* 22F0 80104AF0 0800E003 */  jr         $ra
    /* 22F4 80104AF4 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel _handleMenu
