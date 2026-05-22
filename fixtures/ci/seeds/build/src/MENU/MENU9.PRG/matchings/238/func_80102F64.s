nonmatching func_80102F64, 0x54

glabel func_80102F64
    /* 764 80102F64 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 768 80102F68 09000224 */  addiu      $v0, $zero, 0x9
    /* 76C 80102F6C 1400A4AF */  sw         $a0, 0x14($sp)
    /* 770 80102F70 0A000424 */  addiu      $a0, $zero, 0xA
    /* 774 80102F74 40010524 */  addiu      $a1, $zero, 0x140
    /* 778 80102F78 22000624 */  addiu      $a2, $zero, 0x22
    /* 77C 80102F7C 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 780 80102F80 1800BFAF */  sw         $ra, 0x18($sp)
    /* 784 80102F84 9723030C */  jal        vs_battle_setMenuItem
    /* 788 80102F88 1000A2AF */   sw        $v0, 0x10($sp)
    /* 78C 80102F8C 02000324 */  addiu      $v1, $zero, 0x2
    /* 790 80102F90 000043A0 */  sb         $v1, 0x0($v0)
    /* 794 80102F94 B4000324 */  addiu      $v1, $zero, 0xB4
    /* 798 80102F98 180043A4 */  sh         $v1, 0x18($v0)
    /* 79C 80102F9C 01000324 */  addiu      $v1, $zero, 0x1
    /* 7A0 80102FA0 060043A0 */  sb         $v1, 0x6($v0)
    /* 7A4 80102FA4 0A0043A0 */  sb         $v1, 0xA($v0)
    /* 7A8 80102FA8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 7AC 80102FAC 00000000 */  nop
    /* 7B0 80102FB0 0800E003 */  jr         $ra
    /* 7B4 80102FB4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80102F64
