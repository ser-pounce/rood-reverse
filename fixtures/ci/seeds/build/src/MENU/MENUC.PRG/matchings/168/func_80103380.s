nonmatching func_80103380, 0x7C

glabel func_80103380
    /* B80 80103380 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B84 80103384 1000B0AF */  sw         $s0, 0x10($sp)
    /* B88 80103388 1400BFAF */  sw         $ra, 0x14($sp)
    /* B8C 8010338C BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* B90 80103390 21808000 */   addu      $s0, $a0, $zero
    /* B94 80103394 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* B98 80103398 28000424 */   addiu     $a0, $zero, 0x28
    /* B9C 8010339C 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* BA0 801033A0 21200000 */   addu      $a0, $zero, $zero
    /* BA4 801033A4 07000012 */  beqz       $s0, .L801033C4
    /* BA8 801033A8 00000000 */   nop
    /* BAC 801033AC F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* BB0 801033B0 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* BB4 801033B4 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* BB8 801033B8 02000424 */   addiu     $a0, $zero, 0x2
    /* BBC 801033BC 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* BC0 801033C0 04000424 */   addiu     $a0, $zero, 0x4
  .L801033C4:
    /* BC4 801033C4 A2FE030C */  jal        func_800FFA88
    /* BC8 801033C8 02000424 */   addiu     $a0, $zero, 0x2
    /* BCC 801033CC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* BD0 801033D0 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* BD4 801033D4 00000000 */  nop
    /* BD8 801033D8 10004230 */  andi       $v0, $v0, 0x10
    /* BDC 801033DC 02004010 */  beqz       $v0, .L801033E8
    /* BE0 801033E0 FFFF0324 */   addiu     $v1, $zero, -0x1
    /* BE4 801033E4 FEFF0324 */  addiu      $v1, $zero, -0x2
  .L801033E8:
    /* BE8 801033E8 1400BF8F */  lw         $ra, 0x14($sp)
    /* BEC 801033EC 1000B08F */  lw         $s0, 0x10($sp)
    /* BF0 801033F0 21106000 */  addu       $v0, $v1, $zero
    /* BF4 801033F4 0800E003 */  jr         $ra
    /* BF8 801033F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80103380
