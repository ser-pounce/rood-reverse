nonmatching func_801034BC, 0x14C

glabel func_801034BC
    /* CBC 801034BC 0680023C */  lui        $v0, %hi(vs_main_buttonRepeat)
    /* CC0 801034C0 DCDF438C */  lw         $v1, %lo(vs_main_buttonRepeat)($v0)
    /* CC4 801034C4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* CC8 801034C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* CCC 801034CC 21808000 */  addu       $s0, $a0, $zero
    /* CD0 801034D0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* CD4 801034D4 2198A000 */  addu       $s3, $a1, $zero
    /* CD8 801034D8 1400B1AF */  sw         $s1, 0x14($sp)
    /* CDC 801034DC 21880000 */  addu       $s1, $zero, $zero
    /* CE0 801034E0 1800B2AF */  sw         $s2, 0x18($sp)
    /* CE4 801034E4 21900002 */  addu       $s2, $s0, $zero
    /* CE8 801034E8 2400BFAF */  sw         $ra, 0x24($sp)
    /* CEC 801034EC 00106230 */  andi       $v0, $v1, 0x1000
    /* CF0 801034F0 03004010 */  beqz       $v0, .L80103500
    /* CF4 801034F4 2000B4AF */   sw        $s4, 0x20($sp)
    /* CF8 801034F8 4C0D0408 */  j          .L80103530
    /* CFC 801034FC 01001124 */   addiu     $s1, $zero, 0x1
  .L80103500:
    /* D00 80103500 00406230 */  andi       $v0, $v1, 0x4000
    /* D04 80103504 03004010 */  beqz       $v0, .L80103514
    /* D08 80103508 00806230 */   andi      $v0, $v1, 0x8000
    /* D0C 8010350C 4C0D0408 */  j          .L80103530
    /* D10 80103510 02001124 */   addiu     $s1, $zero, 0x2
  .L80103514:
    /* D14 80103514 03004010 */  beqz       $v0, .L80103524
    /* D18 80103518 00206230 */   andi      $v0, $v1, 0x2000
    /* D1C 8010351C 4C0D0408 */  j          .L80103530
    /* D20 80103520 03001124 */   addiu     $s1, $zero, 0x3
  .L80103524:
    /* D24 80103524 02004010 */  beqz       $v0, .L80103530
    /* D28 80103528 00000000 */   nop
    /* D2C 8010352C 04001124 */  addiu      $s1, $zero, 0x4
  .L80103530:
    /* D30 80103530 07002012 */  beqz       $s1, .L80103550
    /* D34 80103534 1080033C */   lui       $v1, %hi(vs_mainMenu_equipmentDetailNavigationMap)
    /* D38 80103538 4C216324 */  addiu      $v1, $v1, %lo(vs_mainMenu_equipmentDetailNavigationMap)
    /* D3C 8010353C 80101200 */  sll        $v0, $s2, 2
    /* D40 80103540 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* D44 80103544 21102202 */  addu       $v0, $s1, $v0
    /* D48 80103548 21104300 */  addu       $v0, $v0, $v1
    /* D4C 8010354C 00005090 */  lbu        $s0, 0x0($v0)
  .L80103550:
    /* D50 80103550 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentDetailNavigationMap)
    /* D54 80103554 4C215424 */  addiu      $s4, $v0, %lo(vs_mainMenu_equipmentDetailNavigationMap)
    /* D58 80103558 21200002 */  addu       $a0, $s0, $zero
  .L8010355C:
    /* D5C 8010355C 070D040C */  jal        func_8010341C
    /* D60 80103560 21286002 */   addu      $a1, $s3, $zero
    /* D64 80103564 20004014 */  bnez       $v0, .L801035E8
    /* D68 80103568 21100002 */   addu      $v0, $s0, $zero
    /* D6C 8010356C 17005016 */  bne        $s2, $s0, .L801035CC
    /* D70 80103570 80101000 */   sll       $v0, $s0, 2
    /* D74 80103574 FEFF0226 */  addiu      $v0, $s0, -0x2
    /* D78 80103578 0E00422C */  sltiu      $v0, $v0, 0xE
    /* D7C 8010357C 0B004010 */  beqz       $v0, .L801035AC
    /* D80 80103580 01001026 */   addiu     $s0, $s0, 0x1
    /* D84 80103584 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* D88 80103588 FFFF1026 */  addiu      $s0, $s0, -0x1
  .L8010358C:
    /* D8C 8010358C 21200002 */  addu       $a0, $s0, $zero
    /* D90 80103590 070D040C */  jal        func_8010341C
    /* D94 80103594 21286002 */   addu      $a1, $s3, $zero
    /* D98 80103598 FCFF4010 */  beqz       $v0, .L8010358C
    /* D9C 8010359C FFFF1026 */   addiu     $s0, $s0, -0x1
    /* DA0 801035A0 01001026 */  addiu      $s0, $s0, 0x1
    /* DA4 801035A4 7A0D0408 */  j          .L801035E8
    /* DA8 801035A8 21100002 */   addu      $v0, $s0, $zero
  .L801035AC:
    /* DAC 801035AC 21200002 */  addu       $a0, $s0, $zero
    /* DB0 801035B0 070D040C */  jal        func_8010341C
    /* DB4 801035B4 21286002 */   addu      $a1, $s3, $zero
    /* DB8 801035B8 FCFF4010 */  beqz       $v0, .L801035AC
    /* DBC 801035BC 01001026 */   addiu     $s0, $s0, 0x1
    /* DC0 801035C0 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* DC4 801035C4 7A0D0408 */  j          .L801035E8
    /* DC8 801035C8 21100002 */   addu      $v0, $s0, $zero
  .L801035CC:
    /* DCC 801035CC 21900002 */  addu       $s2, $s0, $zero
    /* DD0 801035D0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* DD4 801035D4 21102202 */  addu       $v0, $s1, $v0
    /* DD8 801035D8 21105400 */  addu       $v0, $v0, $s4
    /* DDC 801035DC 00005090 */  lbu        $s0, 0x0($v0)
    /* DE0 801035E0 570D0408 */  j          .L8010355C
    /* DE4 801035E4 21200002 */   addu      $a0, $s0, $zero
  .L801035E8:
    /* DE8 801035E8 2400BF8F */  lw         $ra, 0x24($sp)
    /* DEC 801035EC 2000B48F */  lw         $s4, 0x20($sp)
    /* DF0 801035F0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* DF4 801035F4 1800B28F */  lw         $s2, 0x18($sp)
    /* DF8 801035F8 1400B18F */  lw         $s1, 0x14($sp)
    /* DFC 801035FC 1000B08F */  lw         $s0, 0x10($sp)
    /* E00 80103600 0800E003 */  jr         $ra
    /* E04 80103604 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_801034BC
