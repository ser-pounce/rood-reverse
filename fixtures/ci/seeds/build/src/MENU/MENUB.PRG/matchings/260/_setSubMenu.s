nonmatching _setSubMenu, 0x9C

glabel _setSubMenu
    /* 56C 80102D6C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 570 80102D70 2000B2AF */  sw         $s2, 0x20($sp)
    /* 574 80102D74 21908000 */  addu       $s2, $a0, $zero
    /* 578 80102D78 2400B3AF */  sw         $s3, 0x24($sp)
    /* 57C 80102D7C 2198A000 */  addu       $s3, $a1, $zero
    /* 580 80102D80 1800B0AF */  sw         $s0, 0x18($sp)
    /* 584 80102D84 2180C000 */  addu       $s0, $a2, $zero
    /* 588 80102D88 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 58C 80102D8C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 590 80102D90 BE00030C */  jal        vs_battle_playMenuChangeSfx
    /* 594 80102D94 2188E000 */   addu      $s1, $a3, $zero
    /* 598 80102D98 21204002 */  addu       $a0, $s2, $zero
    /* 59C 80102D9C 9B000524 */  addiu      $a1, $zero, 0x9B
    /* 5A0 80102DA0 12000624 */  addiu      $a2, $zero, 0x12
    /* 5A4 80102DA4 1000A0AF */  sw         $zero, 0x10($sp)
    /* 5A8 80102DA8 0000628E */  lw         $v0, 0x0($s3)
    /* 5AC 80102DAC A5000724 */  addiu      $a3, $zero, 0xA5
    /* 5B0 80102DB0 9723030C */  jal        vs_battle_setMenuItem
    /* 5B4 80102DB4 1400A2AF */   sw        $v0, 0x14($sp)
    /* 5B8 80102DB8 01000324 */  addiu      $v1, $zero, 0x1
    /* 5BC 80102DBC 060043A0 */  sb         $v1, 0x6($v0)
    /* 5C0 80102DC0 821E1000 */  srl        $v1, $s0, 26
    /* 5C4 80102DC4 02841000 */  srl        $s0, $s0, 16
    /* 5C8 80102DC8 07001032 */  andi       $s0, $s0, 0x7
    /* 5CC 80102DCC 090043A0 */  sb         $v1, 0x9($v0)
    /* 5D0 80102DD0 0C0050A0 */  sb         $s0, 0xC($v0)
    /* 5D4 80102DD4 0400648E */  lw         $a0, 0x4($s3)
    /* 5D8 80102DD8 01FF030C */  jal        vs_mainmenu_setInformationMessage
    /* 5DC 80102DDC 01003126 */   addiu     $s1, $s1, 0x1
    /* 5E0 80102DE0 9223030C */  jal        vs_battle_getMenuItem
    /* 5E4 80102DE4 1F000424 */   addiu     $a0, $zero, 0x1F
    /* 5E8 80102DE8 0E0051A4 */  sh         $s1, 0xE($v0)
    /* 5EC 80102DEC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 5F0 80102DF0 2400B38F */  lw         $s3, 0x24($sp)
    /* 5F4 80102DF4 2000B28F */  lw         $s2, 0x20($sp)
    /* 5F8 80102DF8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 5FC 80102DFC 1800B08F */  lw         $s0, 0x18($sp)
    /* 600 80102E00 0800E003 */  jr         $ra
    /* 604 80102E04 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _setSubMenu
