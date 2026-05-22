nonmatching _soundOptionMenu, 0x1A0

glabel _soundOptionMenu
    /* C5C 8010345C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* C60 80103460 04008010 */  beqz       $a0, .L80103474
    /* C64 80103464 2800BFAF */   sw        $ra, 0x28($sp)
    /* C68 80103468 1080023C */  lui        $v0, %hi(D_80105DA0)
    /* C6C 8010346C 7A0D0408 */  j          .L801035E8
    /* C70 80103470 A05D40AC */   sw        $zero, %lo(D_80105DA0)($v0)
  .L80103474:
    /* C74 80103474 1080023C */  lui        $v0, %hi(D_80105DA0)
    /* C78 80103478 A05D438C */  lw         $v1, %lo(D_80105DA0)($v0)
    /* C7C 8010347C 01000224 */  addiu      $v0, $zero, 0x1
    /* C80 80103480 3B006210 */  beq        $v1, $v0, .L80103570
    /* C84 80103484 02006228 */   slti      $v0, $v1, 0x2
    /* C88 80103488 05004010 */  beqz       $v0, .L801034A0
    /* C8C 8010348C 02000224 */   addiu     $v0, $zero, 0x2
    /* C90 80103490 07006010 */  beqz       $v1, .L801034B0
    /* C94 80103494 21100000 */   addu      $v0, $zero, $zero
    /* C98 80103498 7B0D0408 */  j          .L801035EC
    /* C9C 8010349C 00000000 */   nop
  .L801034A0:
    /* CA0 801034A0 4A006210 */  beq        $v1, $v0, .L801035CC
    /* CA4 801034A4 21100000 */   addu      $v0, $zero, $zero
    /* CA8 801034A8 7B0D0408 */  j          .L801035EC
    /* CAC 801034AC 00000000 */   nop
  .L801034B0:
    /* CB0 801034B0 74EA030C */  jal        vs_mainmenu_ready
    /* CB4 801034B4 00000000 */   nop
    /* CB8 801034B8 4B004010 */  beqz       $v0, .L801035E8
    /* CBC 801034BC 21280000 */   addu      $a1, $zero, $zero
    /* CC0 801034C0 1080023C */  lui        $v0, %hi(_menuStrings)
    /* CC4 801034C4 58554B24 */  addiu      $t3, $v0, %lo(_menuStrings)
    /* CC8 801034C8 2000AA27 */  addiu      $t2, $sp, 0x20
    /* CCC 801034CC 66000924 */  addiu      $t1, $zero, 0x66
    /* CD0 801034D0 04000824 */  addiu      $t0, $zero, 0x4
    /* CD4 801034D4 1000AC27 */  addiu      $t4, $sp, 0x10
    /* CD8 801034D8 21388001 */  addu       $a3, $t4, $zero
    /* CDC 801034DC 64000624 */  addiu      $a2, $zero, 0x64
  .L801034E0:
    /* CE0 801034E0 21182B01 */  addu       $v1, $t1, $t3
    /* CE4 801034E4 04002925 */  addiu      $t1, $t1, 0x4
    /* CE8 801034E8 21208801 */  addu       $a0, $t4, $t0
    /* CEC 801034EC 08000825 */  addiu      $t0, $t0, 0x8
    /* CF0 801034F0 2110CB00 */  addu       $v0, $a2, $t3
    /* CF4 801034F4 0400C624 */  addiu      $a2, $a2, 0x4
    /* CF8 801034F8 00004294 */  lhu        $v0, 0x0($v0)
    /* CFC 801034FC 0100A524 */  addiu      $a1, $a1, 0x1
    /* D00 80103500 40100200 */  sll        $v0, $v0, 1
    /* D04 80103504 21104B00 */  addu       $v0, $v0, $t3
    /* D08 80103508 0000E2AC */  sw         $v0, 0x0($a3)
    /* D0C 8010350C 00006294 */  lhu        $v0, 0x0($v1)
    /* D10 80103510 0800E724 */  addiu      $a3, $a3, 0x8
    /* D14 80103514 40100200 */  sll        $v0, $v0, 1
    /* D18 80103518 21104B00 */  addu       $v0, $v0, $t3
    /* D1C 8010351C 000082AC */  sw         $v0, 0x0($a0)
    /* D20 80103520 000040AD */  sw         $zero, 0x0($t2)
    /* D24 80103524 0200A228 */  slti       $v0, $a1, 0x2
    /* D28 80103528 EDFF4014 */  bnez       $v0, .L801034E0
    /* D2C 8010352C 04004A25 */   addiu     $t2, $t2, 0x4
    /* D30 80103530 0680023C */  lui        $v0, %hi(D_8006002A)
    /* D34 80103534 2000A727 */  addiu      $a3, $sp, 0x20
    /* D38 80103538 02000424 */  addiu      $a0, $zero, 0x2
    /* D3C 8010353C 2A004590 */  lbu        $a1, %lo(D_8006002A)($v0)
    /* D40 80103540 1000A627 */  addiu      $a2, $sp, 0x10
    /* D44 80103544 80180500 */  sll        $v1, $a1, 2
    /* D48 80103548 2118E300 */  addu       $v1, $a3, $v1
    /* D4C 8010354C 0000628C */  lw         $v0, 0x0($v1)
    /* D50 80103550 4D020524 */  addiu      $a1, $zero, 0x24D
    /* D54 80103554 04004234 */  ori        $v0, $v0, 0x4
    /* D58 80103558 7801040C */  jal        vs_mainmenu_setMenuRows
    /* D5C 8010355C 000062AC */   sw        $v0, 0x0($v1)
    /* D60 80103560 1080033C */  lui        $v1, %hi(D_80105DA0)
    /* D64 80103564 01000224 */  addiu      $v0, $zero, 0x1
    /* D68 80103568 7A0D0408 */  j          .L801035E8
    /* D6C 8010356C A05D62AC */   sw        $v0, %lo(D_80105DA0)($v1)
  .L80103570:
    /* D70 80103570 3202040C */  jal        vs_mainmenu_getSelectedRow
    /* D74 80103574 00000000 */   nop
    /* D78 80103578 1080033C */  lui        $v1, %hi(D_80105DA4)
    /* D7C 8010357C 01004424 */  addiu      $a0, $v0, 0x1
    /* D80 80103580 19008010 */  beqz       $a0, .L801035E8
    /* D84 80103584 A45D64AC */   sw        $a0, %lo(D_80105DA4)($v1)
    /* D88 80103588 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* D8C 8010358C 09008214 */  bne        $a0, $v0, .L801035B4
    /* D90 80103590 00000000 */   nop
    /* D94 80103594 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* D98 80103598 28000424 */   addiu     $a0, $zero, 0x28
    /* D9C 8010359C EAFE030C */  jal        func_800FFBA8
    /* DA0 801035A0 00000000 */   nop
    /* DA4 801035A4 A2FE030C */  jal        func_800FFA88
    /* DA8 801035A8 21200000 */   addu      $a0, $zero, $zero
    /* DAC 801035AC 700D0408 */  j          .L801035C0
    /* DB0 801035B0 1080033C */   lui       $v1, %hi(D_80105DA0)
  .L801035B4:
    /* DB4 801035B4 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* DB8 801035B8 07000424 */   addiu     $a0, $zero, 0x7
    /* DBC 801035BC 1080033C */  lui        $v1, %hi(D_80105DA0)
  .L801035C0:
    /* DC0 801035C0 02000224 */  addiu      $v0, $zero, 0x2
    /* DC4 801035C4 7A0D0408 */  j          .L801035E8
    /* DC8 801035C8 A05D62AC */   sw        $v0, %lo(D_80105DA0)($v1)
  .L801035CC:
    /* DCC 801035CC 74EA030C */  jal        vs_mainmenu_ready
    /* DD0 801035D0 00000000 */   nop
    /* DD4 801035D4 04004010 */  beqz       $v0, .L801035E8
    /* DD8 801035D8 1080023C */   lui       $v0, %hi(D_80105DA4)
    /* DDC 801035DC A45D428C */  lw         $v0, %lo(D_80105DA4)($v0)
    /* DE0 801035E0 7B0D0408 */  j          .L801035EC
    /* DE4 801035E4 00000000 */   nop
  .L801035E8:
    /* DE8 801035E8 21100000 */  addu       $v0, $zero, $zero
  .L801035EC:
    /* DEC 801035EC 2800BF8F */  lw         $ra, 0x28($sp)
    /* DF0 801035F0 00000000 */  nop
    /* DF4 801035F4 0800E003 */  jr         $ra
    /* DF8 801035F8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _soundOptionMenu
