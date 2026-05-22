nonmatching _setMenuItemMapName, 0x5C

glabel _setMenuItemMapName
    /* 730 80102F30 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 734 80102F34 1800B0AF */  sw         $s0, 0x18($sp)
    /* 738 80102F38 2180A000 */  addu       $s0, $a1, $zero
    /* 73C 80102F3C 08000224 */  addiu      $v0, $zero, 0x8
    /* 740 80102F40 1400A4AF */  sw         $a0, 0x14($sp)
    /* 744 80102F44 0A000424 */  addiu      $a0, $zero, 0xA
    /* 748 80102F48 40010524 */  addiu      $a1, $zero, 0x140
    /* 74C 80102F4C 22000624 */  addiu      $a2, $zero, 0x22
    /* 750 80102F50 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 754 80102F54 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 758 80102F58 9723030C */  jal        vs_battle_setMenuItem
    /* 75C 80102F5C 1000A2AF */   sw        $v0, 0x10($sp)
    /* 760 80102F60 02000324 */  addiu      $v1, $zero, 0x2
    /* 764 80102F64 000043A0 */  sb         $v1, 0x0($v0)
    /* 768 80102F68 B4000324 */  addiu      $v1, $zero, 0xB4
    /* 76C 80102F6C 180043A4 */  sh         $v1, 0x18($v0)
    /* 770 80102F70 01000324 */  addiu      $v1, $zero, 0x1
    /* 774 80102F74 060043A0 */  sb         $v1, 0x6($v0)
    /* 778 80102F78 0A0050A0 */  sb         $s0, 0xA($v0)
    /* 77C 80102F7C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 780 80102F80 1800B08F */  lw         $s0, 0x18($sp)
    /* 784 80102F84 0800E003 */  jr         $ra
    /* 788 80102F88 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _setMenuItemMapName
