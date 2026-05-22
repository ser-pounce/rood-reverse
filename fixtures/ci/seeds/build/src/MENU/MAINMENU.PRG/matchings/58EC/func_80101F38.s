nonmatching func_80101F38, 0xDC

glabel func_80101F38
    /* 8738 80101F38 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 873C 80101F3C 1080033C */  lui        $v1, %hi(D_801023D4)
    /* 8740 80101F40 D423638C */  lw         $v1, %lo(D_801023D4)($v1)
    /* 8744 80101F44 1080023C */  lui        $v0, %hi(D_801022D8)
    /* 8748 80101F48 1000B0AF */  sw         $s0, 0x10($sp)
    /* 874C 80101F4C D822508C */  lw         $s0, %lo(D_801022D8)($v0)
    /* 8750 80101F50 03006010 */  beqz       $v1, .L80101F60
    /* 8754 80101F54 1400BFAF */   sw        $ra, 0x14($sp)
    /* 8758 80101F58 9702040C */  jal        func_80100A5C
    /* 875C 80101F5C 00000000 */   nop
  .L80101F60:
    /* 8760 80101F60 1080023C */  lui        $v0, %hi(D_801022DC)
    /* 8764 80101F64 DC224290 */  lbu        $v0, %lo(D_801022DC)($v0)
    /* 8768 80101F68 00000000 */  nop
    /* 876C 80101F6C 07004010 */  beqz       $v0, .L80101F8C
    /* 8770 80101F70 00000000 */   nop
    /* 8774 80101F74 02001026 */  addiu      $s0, $s0, 0x2
    /* 8778 80101F78 1100022A */  slti       $v0, $s0, 0x11
    /* 877C 80101F7C 07004014 */  bnez       $v0, .L80101F9C
    /* 8780 80101F80 1080023C */   lui       $v0, %hi(D_801022D8)
    /* 8784 80101F84 E7070408 */  j          .L80101F9C
    /* 8788 80101F88 10001024 */   addiu     $s0, $zero, 0x10
  .L80101F8C:
    /* 878C 80101F8C FEFF1026 */  addiu      $s0, $s0, -0x2
    /* 8790 80101F90 02000106 */  bgez       $s0, .L80101F9C
    /* 8794 80101F94 1080023C */   lui       $v0, %hi(D_801022D8)
    /* 8798 80101F98 21800000 */  addu       $s0, $zero, $zero
  .L80101F9C:
    /* 879C 80101F9C 03000012 */  beqz       $s0, .L80101FAC
    /* 87A0 80101FA0 D82250AC */   sw        $s0, %lo(D_801022D8)($v0)
    /* 87A4 80101FA4 4604040C */  jal        func_80101118
    /* 87A8 80101FA8 21200002 */   addu      $a0, $s0, $zero
  .L80101FAC:
    /* 87AC 80101FAC 0F80023C */  lui        $v0, %hi(vs_battle_shortcutInvoked)
    /* 87B0 80101FB0 6A4E4290 */  lbu        $v0, %lo(vs_battle_shortcutInvoked)($v0)
    /* 87B4 80101FB4 00000000 */  nop
    /* 87B8 80101FB8 04004014 */  bnez       $v0, .L80101FCC
    /* 87BC 80101FBC 0F80023C */   lui       $v0, %hi(vs_battle_menuItems)
    /* 87C0 80101FC0 A5FE030C */  jal        func_800FFA94
    /* 87C4 80101FC4 00000000 */   nop
    /* 87C8 80101FC8 0F80023C */  lui        $v0, %hi(vs_battle_menuItems)
  .L80101FCC:
    /* 87CC 80101FCC C0B9428C */  lw         $v0, %lo(vs_battle_menuItems)($v0)
    /* 87D0 80101FD0 00000000 */  nop
    /* 87D4 80101FD4 03004010 */  beqz       $v0, .L80101FE4
    /* 87D8 80101FD8 00000000 */   nop
    /* 87DC 80101FDC 5C06040C */  jal        func_80101970
    /* 87E0 80101FE0 00000000 */   nop
  .L80101FE4:
    /* 87E4 80101FE4 5900040C */  jal        func_80100164
    /* 87E8 80101FE8 00000000 */   nop
    /* 87EC 80101FEC F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 87F0 80101FF0 21200000 */   addu      $a0, $zero, $zero
    /* 87F4 80101FF4 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 87F8 80101FF8 21200000 */   addu      $a0, $zero, $zero
    /* 87FC 80101FFC 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 8800 80102000 21200000 */   addu      $a0, $zero, $zero
    /* 8804 80102004 1400BF8F */  lw         $ra, 0x14($sp)
    /* 8808 80102008 1000B08F */  lw         $s0, 0x10($sp)
    /* 880C 8010200C 0800E003 */  jr         $ra
    /* 8810 80102010 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80101F38
