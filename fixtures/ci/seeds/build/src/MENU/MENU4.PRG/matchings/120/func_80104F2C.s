nonmatching func_80104F2C, 0x54

glabel func_80104F2C
    /* 272C 80104F2C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2730 80104F30 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2734 80104F34 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2738 80104F38 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 273C 80104F3C 21808000 */   addu      $s0, $a0, $zero
    /* 2740 80104F40 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 2744 80104F44 28000424 */   addiu     $a0, $zero, 0x28
    /* 2748 80104F48 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 274C 80104F4C 21200000 */   addu      $a0, $zero, $zero
    /* 2750 80104F50 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 2754 80104F54 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 2758 80104F58 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 275C 80104F5C 02000424 */   addiu     $a0, $zero, 0x2
    /* 2760 80104F60 03000012 */  beqz       $s0, .L80104F70
    /* 2764 80104F64 00000000 */   nop
    /* 2768 80104F68 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 276C 80104F6C 04000424 */   addiu     $a0, $zero, 0x4
  .L80104F70:
    /* 2770 80104F70 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2774 80104F74 1000B08F */  lw         $s0, 0x10($sp)
    /* 2778 80104F78 0800E003 */  jr         $ra
    /* 277C 80104F7C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80104F2C
