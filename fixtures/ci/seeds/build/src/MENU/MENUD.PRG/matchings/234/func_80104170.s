nonmatching func_80104170, 0x70

glabel func_80104170
    /* 1970 80104170 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1974 80104174 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1978 80104178 1400BFAF */  sw         $ra, 0x14($sp)
    /* 197C 8010417C BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 1980 80104180 21808000 */   addu      $s0, $a0, $zero
    /* 1984 80104184 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 1988 80104188 28000424 */   addiu     $a0, $zero, 0x28
    /* 198C 8010418C 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 1990 80104190 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 1994 80104194 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 1998 80104198 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 199C 8010419C A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 19A0 801041A0 02000424 */   addiu     $a0, $zero, 0x2
    /* 19A4 801041A4 1180033C */  lui        $v1, %hi(D_80109A81)
    /* 19A8 801041A8 02000224 */  addiu      $v0, $zero, 0x2
    /* 19AC 801041AC 819A62A0 */  sb         $v0, %lo(D_80109A81)($v1)
    /* 19B0 801041B0 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 19B4 801041B4 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 19B8 801041B8 1180033C */  lui        $v1, %hi(D_80109A84)
    /* 19BC 801041BC 10004230 */  andi       $v0, $v0, 0x10
    /* 19C0 801041C0 03000012 */  beqz       $s0, .L801041D0
    /* 19C4 801041C4 849A62AC */   sw        $v0, %lo(D_80109A84)($v1)
    /* 19C8 801041C8 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 19CC 801041CC 04000424 */   addiu     $a0, $zero, 0x4
  .L801041D0:
    /* 19D0 801041D0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 19D4 801041D4 1000B08F */  lw         $s0, 0x10($sp)
    /* 19D8 801041D8 0800E003 */  jr         $ra
    /* 19DC 801041DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80104170
