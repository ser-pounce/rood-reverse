nonmatching func_80102E48, 0x54

glabel func_80102E48
    /* 648 80102E48 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 64C 80102E4C 09000224 */  addiu      $v0, $zero, 0x9
    /* 650 80102E50 1400A4AF */  sw         $a0, 0x14($sp)
    /* 654 80102E54 0A000424 */  addiu      $a0, $zero, 0xA
    /* 658 80102E58 40010524 */  addiu      $a1, $zero, 0x140
    /* 65C 80102E5C 22000624 */  addiu      $a2, $zero, 0x22
    /* 660 80102E60 8C000724 */  addiu      $a3, $zero, 0x8C
    /* 664 80102E64 1800BFAF */  sw         $ra, 0x18($sp)
    /* 668 80102E68 9723030C */  jal        vs_battle_setMenuItem
    /* 66C 80102E6C 1000A2AF */   sw        $v0, 0x10($sp)
    /* 670 80102E70 02000324 */  addiu      $v1, $zero, 0x2
    /* 674 80102E74 000043A0 */  sb         $v1, 0x0($v0)
    /* 678 80102E78 B4000324 */  addiu      $v1, $zero, 0xB4
    /* 67C 80102E7C 180043A4 */  sh         $v1, 0x18($v0)
    /* 680 80102E80 01000324 */  addiu      $v1, $zero, 0x1
    /* 684 80102E84 060043A0 */  sb         $v1, 0x6($v0)
    /* 688 80102E88 0A0043A0 */  sb         $v1, 0xA($v0)
    /* 68C 80102E8C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 690 80102E90 00000000 */  nop
    /* 694 80102E94 0800E003 */  jr         $ra
    /* 698 80102E98 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80102E48
