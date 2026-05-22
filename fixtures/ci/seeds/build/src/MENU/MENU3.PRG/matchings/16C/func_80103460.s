nonmatching func_80103460, 0x25C

glabel func_80103460
    /* C60 80103460 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* C64 80103464 21288000 */  addu       $a1, $a0, $zero
    /* C68 80103468 2800BFAF */  sw         $ra, 0x28($sp)
    /* C6C 8010346C 2400B1AF */  sw         $s1, 0x24($sp)
    /* C70 80103470 1100A010 */  beqz       $a1, .L801034B8
    /* C74 80103474 2000B0AF */   sw        $s0, 0x20($sp)
    /* C78 80103478 1180033C */  lui        $v1, %hi(D_8010965C)
    /* C7C 8010347C 03120500 */  sra        $v0, $a1, 8
    /* C80 80103480 5C9662A0 */  sb         $v0, %lo(D_8010965C)($v1)
    /* C84 80103484 FF004430 */  andi       $a0, $v0, 0xFF
    /* C88 80103488 1180033C */  lui        $v1, %hi(D_8010965D)
    /* C8C 8010348C FFFFA224 */  addiu      $v0, $a1, -0x1
    /* C90 80103490 DE0A040C */  jal        func_80102B78
    /* C94 80103494 5D9662A0 */   sb        $v0, %lo(D_8010965D)($v1)
    /* C98 80103498 21100000 */  addu       $v0, $zero, $zero
    /* C9C 8010349C 1180033C */  lui        $v1, %hi(D_8010965E)
    /* CA0 801034A0 5E9660A0 */  sb         $zero, %lo(D_8010965E)($v1)
    /* CA4 801034A4 1180033C */  lui        $v1, %hi(D_8010965B)
    /* CA8 801034A8 5B9660A0 */  sb         $zero, %lo(D_8010965B)($v1)
    /* CAC 801034AC 1180033C */  lui        $v1, %hi(D_8010965A)
    /* CB0 801034B0 AA0D0408 */  j          .L801036A8
    /* CB4 801034B4 5A9660A0 */   sb        $zero, %lo(D_8010965A)($v1)
  .L801034B8:
    /* CB8 801034B8 1180103C */  lui        $s0, %hi(D_8010965A)
    /* CBC 801034BC 5A960392 */  lbu        $v1, %lo(D_8010965A)($s0)
    /* CC0 801034C0 01001124 */  addiu      $s1, $zero, 0x1
    /* CC4 801034C4 20007110 */  beq        $v1, $s1, .L80103548
    /* CC8 801034C8 02006228 */   slti      $v0, $v1, 0x2
    /* CCC 801034CC 05004010 */  beqz       $v0, .L801034E4
    /* CD0 801034D0 02000224 */   addiu     $v0, $zero, 0x2
    /* CD4 801034D4 09006010 */  beqz       $v1, .L801034FC
    /* CD8 801034D8 21100000 */   addu      $v0, $zero, $zero
    /* CDC 801034DC AA0D0408 */  j          .L801036A8
    /* CE0 801034E0 00000000 */   nop
  .L801034E4:
    /* CE4 801034E4 33006210 */  beq        $v1, $v0, .L801035B4
    /* CE8 801034E8 03000224 */   addiu     $v0, $zero, 0x3
    /* CEC 801034EC 69006210 */  beq        $v1, $v0, .L80103694
    /* CF0 801034F0 21100000 */   addu      $v0, $zero, $zero
    /* CF4 801034F4 AA0D0408 */  j          .L801036A8
    /* CF8 801034F8 00000000 */   nop
  .L801034FC:
    /* CFC 801034FC 74EA030C */  jal        vs_mainmenu_ready
    /* D00 80103500 00000000 */   nop
    /* D04 80103504 67004010 */  beqz       $v0, .L801036A4
    /* D08 80103508 1180023C */   lui       $v0, %hi(D_8010965C)
    /* D0C 8010350C 5C964490 */  lbu        $a0, %lo(D_8010965C)($v0)
    /* D10 80103510 110B040C */  jal        func_80102C44
    /* D14 80103514 07000524 */   addiu     $a1, $zero, 0x7
    /* D18 80103518 0680033C */  lui        $v1, %hi(vs_main_inventoryIndices)
    /* D1C 8010351C 1180023C */  lui        $v0, %hi(D_8010965D)
    /* D20 80103520 5D964290 */  lbu        $v0, %lo(D_8010965D)($v0)
    /* D24 80103524 D8196324 */  addiu      $v1, $v1, %lo(vs_main_inventoryIndices)
    /* D28 80103528 21104300 */  addu       $v0, $v0, $v1
    /* D2C 8010352C 28004490 */  lbu        $a0, 0x28($v0)
    /* D30 80103530 68F5030C */  jal        vs_mainMenu_setShieldStats
    /* D34 80103534 00000000 */   nop
    /* D38 80103538 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* D3C 8010353C 03000424 */   addiu     $a0, $zero, 0x3
    /* D40 80103540 A90D0408 */  j          .L801036A4
    /* D44 80103544 5A9611A2 */   sb        $s1, %lo(D_8010965A)($s0)
  .L80103548:
    /* D48 80103548 1180043C */  lui        $a0, %hi(D_8010965B)
    /* D4C 8010354C 5B968390 */  lbu        $v1, %lo(D_8010965B)($a0)
    /* D50 80103550 00000000 */  nop
    /* D54 80103554 0A00622C */  sltiu      $v0, $v1, 0xA
    /* D58 80103558 10004010 */  beqz       $v0, .L8010359C
    /* D5C 8010355C 01006224 */   addiu     $v0, $v1, 0x1
    /* D60 80103560 5B9682A0 */  sb         $v0, %lo(D_8010965B)($a0)
    /* D64 80103564 FF004230 */  andi       $v0, $v0, 0xFF
    /* D68 80103568 0400422C */  sltiu      $v0, $v0, 0x4
    /* D6C 8010356C 4D004010 */  beqz       $v0, .L801036A4
    /* D70 80103570 0680023C */   lui       $v0, %hi(vs_main_inventoryIndices)
    /* D74 80103574 1180033C */  lui        $v1, %hi(D_8010965D)
    /* D78 80103578 D8194224 */  addiu      $v0, $v0, %lo(vs_main_inventoryIndices)
    /* D7C 8010357C 5D966390 */  lbu        $v1, %lo(D_8010965D)($v1)
    /* D80 80103580 5B968490 */  lbu        $a0, %lo(D_8010965B)($a0)
    /* D84 80103584 21186200 */  addu       $v1, $v1, $v0
    /* D88 80103588 28006590 */  lbu        $a1, 0x28($v1)
    /* D8C 8010358C C1F1030C */  jal        vs_mainMenu_initSetShieldGemMenu
    /* D90 80103590 01000624 */   addiu     $a2, $zero, 0x1
    /* D94 80103594 AA0D0408 */  j          .L801036A8
    /* D98 80103598 21100000 */   addu      $v0, $zero, $zero
  .L8010359C:
    /* D9C 8010359C 74EA030C */  jal        vs_mainmenu_ready
    /* DA0 801035A0 00000000 */   nop
    /* DA4 801035A4 3F004010 */  beqz       $v0, .L801036A4
    /* DA8 801035A8 02000224 */   addiu     $v0, $zero, 0x2
    /* DAC 801035AC A90D0408 */  j          .L801036A4
    /* DB0 801035B0 5A9602A2 */   sb        $v0, %lo(D_8010965A)($s0)
  .L801035B4:
    /* DB4 801035B4 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* DB8 801035B8 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* DBC 801035BC 00000000 */  nop
    /* DC0 801035C0 50004230 */  andi       $v0, $v0, 0x50
    /* DC4 801035C4 06004010 */  beqz       $v0, .L801035E0
    /* DC8 801035C8 00000000 */   nop
    /* DCC 801035CC 5F0B040C */  jal        func_80102D7C
    /* DD0 801035D0 01000424 */   addiu     $a0, $zero, 0x1
    /* DD4 801035D4 03000224 */  addiu      $v0, $zero, 0x3
    /* DD8 801035D8 A90D0408 */  j          .L801036A4
    /* DDC 801035DC 5A9602A2 */   sb        $v0, %lo(D_8010965A)($s0)
  .L801035E0:
    /* DE0 801035E0 1180103C */  lui        $s0, %hi(D_8010965D)
    /* DE4 801035E4 5D960592 */  lbu        $a1, %lo(D_8010965D)($s0)
    /* DE8 801035E8 620A040C */  jal        func_80102988
    /* DEC 801035EC 03000424 */   addiu     $a0, $zero, 0x3
    /* DF0 801035F0 5D960392 */  lbu        $v1, %lo(D_8010965D)($s0)
    /* DF4 801035F4 21884000 */  addu       $s1, $v0, $zero
    /* DF8 801035F8 2A002312 */  beq        $s1, $v1, .L801036A4
    /* DFC 801035FC 03000424 */   addiu     $a0, $zero, 0x3
    /* E00 80103600 21282002 */  addu       $a1, $s1, $zero
    /* E04 80103604 4C0B040C */  jal        func_80102D30
    /* E08 80103608 5D9611A2 */   sb        $s1, %lo(D_8010965D)($s0)
    /* E0C 8010360C 21804000 */  addu       $s0, $v0, $zero
    /* E10 80103610 40101000 */  sll        $v0, $s0, 1
    /* E14 80103614 21105000 */  addu       $v0, $v0, $s0
    /* E18 80103618 00110200 */  sll        $v0, $v0, 4
    /* E1C 8010361C 0680043C */  lui        $a0, %hi(D_80060238)
    /* E20 80103620 38028424 */  addiu      $a0, $a0, %lo(D_80060238)
    /* E24 80103624 21204400 */  addu       $a0, $v0, $a0
    /* E28 80103628 1000A527 */  addiu      $a1, $sp, 0x10
    /* E2C 8010362C 0F80023C */  lui        $v0, %hi(vs_battle_stringBuf)
    /* E30 80103630 8C4E478C */  lw         $a3, %lo(vs_battle_stringBuf)($v0)
    /* E34 80103634 90F3030C */  jal        vs_mainMenu_initUiShield
    /* E38 80103638 1800A627 */   addiu     $a2, $sp, 0x18
    /* E3C 8010363C 68F5030C */  jal        vs_mainMenu_setShieldStats
    /* E40 80103640 21200002 */   addu      $a0, $s0, $zero
    /* E44 80103644 1000A527 */  addiu      $a1, $sp, 0x10
    /* E48 80103648 21382002 */  addu       $a3, $s1, $zero
    /* E4C 8010364C 1180023C */  lui        $v0, %hi(D_8010965C)
    /* E50 80103650 5C964490 */  lbu        $a0, %lo(D_8010965C)($v0)
    /* E54 80103654 1800A68F */  lw         $a2, 0x18($sp)
    /* E58 80103658 250B040C */  jal        func_80102C94
    /* E5C 8010365C 01001024 */   addiu     $s0, $zero, 0x1
    /* E60 80103660 0680023C */  lui        $v0, %hi(vs_main_inventoryIndices)
    /* E64 80103664 D8194224 */  addiu      $v0, $v0, %lo(vs_main_inventoryIndices)
    /* E68 80103668 21882202 */  addu       $s1, $s1, $v0
    /* E6C 8010366C 21200002 */  addu       $a0, $s0, $zero
  .L80103670:
    /* E70 80103670 28002592 */  lbu        $a1, 0x28($s1)
    /* E74 80103674 21300000 */  addu       $a2, $zero, $zero
    /* E78 80103678 C1F1030C */  jal        vs_mainMenu_initSetShieldGemMenu
    /* E7C 8010367C 01001026 */   addiu     $s0, $s0, 0x1
    /* E80 80103680 0400022A */  slti       $v0, $s0, 0x4
    /* E84 80103684 FAFF4014 */  bnez       $v0, .L80103670
    /* E88 80103688 21200002 */   addu      $a0, $s0, $zero
    /* E8C 8010368C AA0D0408 */  j          .L801036A8
    /* E90 80103690 21100000 */   addu      $v0, $zero, $zero
  .L80103694:
    /* E94 80103694 74EA030C */  jal        vs_mainmenu_ready
    /* E98 80103698 00000000 */   nop
    /* E9C 8010369C AA0D0408 */  j          .L801036A8
    /* EA0 801036A0 00000000 */   nop
  .L801036A4:
    /* EA4 801036A4 21100000 */  addu       $v0, $zero, $zero
  .L801036A8:
    /* EA8 801036A8 2800BF8F */  lw         $ra, 0x28($sp)
    /* EAC 801036AC 2400B18F */  lw         $s1, 0x24($sp)
    /* EB0 801036B0 2000B08F */  lw         $s0, 0x20($sp)
    /* EB4 801036B4 0800E003 */  jr         $ra
    /* EB8 801036B8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80103460
