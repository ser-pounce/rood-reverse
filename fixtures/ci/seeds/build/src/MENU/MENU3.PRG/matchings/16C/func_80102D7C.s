nonmatching func_80102D7C, 0x70

glabel func_80102D7C
    /* 57C 80102D7C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 580 80102D80 1000B0AF */  sw         $s0, 0x10($sp)
    /* 584 80102D84 1400BFAF */  sw         $ra, 0x14($sp)
    /* 588 80102D88 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 58C 80102D8C 21808000 */   addu      $s0, $a0, $zero
    /* 590 80102D90 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 594 80102D94 28000424 */   addiu     $a0, $zero, 0x28
    /* 598 80102D98 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 59C 80102D9C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 5A0 80102DA0 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 5A4 80102DA4 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 5A8 80102DA8 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 5AC 80102DAC 02000424 */   addiu     $a0, $zero, 0x2
    /* 5B0 80102DB0 1180033C */  lui        $v1, %hi(D_80109717)
    /* 5B4 80102DB4 02000224 */  addiu      $v0, $zero, 0x2
    /* 5B8 80102DB8 179762A0 */  sb         $v0, %lo(D_80109717)($v1)
    /* 5BC 80102DBC 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 5C0 80102DC0 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 5C4 80102DC4 1180033C */  lui        $v1, %hi(D_80109718)
    /* 5C8 80102DC8 10004230 */  andi       $v0, $v0, 0x10
    /* 5CC 80102DCC 03000012 */  beqz       $s0, .L80102DDC
    /* 5D0 80102DD0 189762AC */   sw        $v0, %lo(D_80109718)($v1)
    /* 5D4 80102DD4 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 5D8 80102DD8 04000424 */   addiu     $a0, $zero, 0x4
  .L80102DDC:
    /* 5DC 80102DDC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5E0 80102DE0 1000B08F */  lw         $s0, 0x10($sp)
    /* 5E4 80102DE4 0800E003 */  jr         $ra
    /* 5E8 80102DE8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102D7C
