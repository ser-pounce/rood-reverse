nonmatching func_80102E3C, 0x84

glabel func_80102E3C
    /* 63C 80102E3C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 640 80102E40 21308000 */  addu       $a2, $a0, $zero
    /* 644 80102E44 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 648 80102E48 04000324 */  addiu      $v1, $zero, 0x4
    /* 64C 80102E4C 21200000 */  addu       $a0, $zero, $zero
    /* 650 80102E50 452543A0 */  sb         $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 654 80102E54 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 658 80102E58 C0244724 */  addiu      $a3, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 65C 80102E5C 40000524 */  addiu      $a1, $zero, 0x40
    /* 660 80102E60 1000BFAF */  sw         $ra, 0x10($sp)
  .L80102E64:
    /* 664 80102E64 2118A700 */  addu       $v1, $a1, $a3
    /* 668 80102E68 2110C400 */  addu       $v0, $a2, $a0
    /* 66C 80102E6C 1C004290 */  lbu        $v0, 0x1C($v0)
    /* 670 80102E70 01008424 */  addiu      $a0, $a0, 0x1
    /* 674 80102E74 00160200 */  sll        $v0, $v0, 24
    /* 678 80102E78 03160200 */  sra        $v0, $v0, 24
    /* 67C 80102E7C 000062A4 */  sh         $v0, 0x0($v1)
    /* 680 80102E80 04008228 */  slti       $v0, $a0, 0x4
    /* 684 80102E84 F7FF4014 */  bnez       $v0, .L80102E64
    /* 688 80102E88 0200A524 */   addiu     $a1, $a1, 0x2
    /* 68C 80102E8C 0500C480 */  lb         $a0, 0x5($a2)
    /* 690 80102E90 0600C580 */  lb         $a1, 0x6($a2)
    /* 694 80102E94 0700C680 */  lb         $a2, 0x7($a2)
    /* 698 80102E98 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 69C 80102E9C 01000724 */   addiu     $a3, $zero, 0x1
    /* 6A0 80102EA0 E3EE030C */  jal        func_800FBB8C
    /* 6A4 80102EA4 04000424 */   addiu     $a0, $zero, 0x4
    /* 6A8 80102EA8 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 6AC 80102EAC 08000424 */   addiu     $a0, $zero, 0x8
    /* 6B0 80102EB0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6B4 80102EB4 00000000 */  nop
    /* 6B8 80102EB8 0800E003 */  jr         $ra
    /* 6BC 80102EBC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102E3C
