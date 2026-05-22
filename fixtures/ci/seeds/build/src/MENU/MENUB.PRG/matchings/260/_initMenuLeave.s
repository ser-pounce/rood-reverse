nonmatching _initMenuLeave, 0x70

glabel _initMenuLeave
    /* 654 80102E54 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 658 80102E58 1000B0AF */  sw         $s0, 0x10($sp)
    /* 65C 80102E5C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 660 80102E60 BA00030C */  jal        vs_battle_playMenuLeaveSfx
    /* 664 80102E64 21808000 */   addu      $s0, $a0, $zero
    /* 668 80102E68 38EA030C */  jal        vs_mainMenu_clearMenuExcept
    /* 66C 80102E6C 28000424 */   addiu     $a0, $zero, 0x28
    /* 670 80102E70 04EA030C */  jal        vs_mainMenu_menuItemFlyoutLeft
    /* 674 80102E74 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 678 80102E78 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 67C 80102E7C FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 680 80102E80 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 684 80102E84 02000424 */   addiu     $a0, $zero, 0x2
    /* 688 80102E88 1180033C */  lui        $v1, %hi(D_8010A6BF)
    /* 68C 80102E8C 02000224 */  addiu      $v0, $zero, 0x2
    /* 690 80102E90 BFA662A0 */  sb         $v0, %lo(D_8010A6BF)($v1)
    /* 694 80102E94 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 698 80102E98 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 69C 80102E9C 1180033C */  lui        $v1, %hi(_exitToBattle)
    /* 6A0 80102EA0 10004230 */  andi       $v0, $v0, 0x10
    /* 6A4 80102EA4 03000012 */  beqz       $s0, .L80102EB4
    /* 6A8 80102EA8 C0A662AC */   sw        $v0, %lo(_exitToBattle)($v1)
    /* 6AC 80102EAC 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 6B0 80102EB0 04000424 */   addiu     $a0, $zero, 0x4
  .L80102EB4:
    /* 6B4 80102EB4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6B8 80102EB8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6BC 80102EBC 0800E003 */  jr         $ra
    /* 6C0 80102EC0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _initMenuLeave
