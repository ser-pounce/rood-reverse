nonmatching func_80102EC0, 0xA4

glabel func_80102EC0
    /* 6C0 80102EC0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C4 80102EC4 21408000 */  addu       $t0, $a0, $zero
    /* 6C8 80102EC8 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentSubtype)
    /* 6CC 80102ECC 40000324 */  addiu      $v1, $zero, 0x40
    /* 6D0 80102ED0 21280000 */  addu       $a1, $zero, $zero
    /* 6D4 80102ED4 20000724 */  addiu      $a3, $zero, 0x20
    /* 6D8 80102ED8 452543A0 */  sb         $v1, %lo(vs_mainMenu_equipmentSubtype)($v0)
    /* 6DC 80102EDC 1080023C */  lui        $v0, %hi(vs_mainMenu_equipmentStats)
    /* 6E0 80102EE0 C0244924 */  addiu      $t1, $v0, %lo(vs_mainMenu_equipmentStats)
    /* 6E4 80102EE4 21302001 */  addu       $a2, $t1, $zero
    /* 6E8 80102EE8 1000BFAF */  sw         $ra, 0x10($sp)
  .L80102EEC:
    /* 6EC 80102EEC 2120E900 */  addu       $a0, $a3, $t1
    /* 6F0 80102EF0 0200E724 */  addiu      $a3, $a3, 0x2
    /* 6F4 80102EF4 0700A330 */  andi       $v1, $a1, 0x7
    /* 6F8 80102EF8 21180301 */  addu       $v1, $t0, $v1
    /* 6FC 80102EFC 20006290 */  lbu        $v0, 0x20($v1)
    /* 700 80102F00 0100A524 */  addiu      $a1, $a1, 0x1
    /* 704 80102F04 00160200 */  sll        $v0, $v0, 24
    /* 708 80102F08 03160200 */  sra        $v0, $v0, 24
    /* 70C 80102F0C 0000C2A4 */  sh         $v0, 0x0($a2)
    /* 710 80102F10 28006290 */  lbu        $v0, 0x28($v1)
    /* 714 80102F14 00000000 */  nop
    /* 718 80102F18 00160200 */  sll        $v0, $v0, 24
    /* 71C 80102F1C 03160200 */  sra        $v0, $v0, 24
    /* 720 80102F20 000082A4 */  sh         $v0, 0x0($a0)
    /* 724 80102F24 1000A228 */  slti       $v0, $a1, 0x10
    /* 728 80102F28 F0FF4014 */  bnez       $v0, .L80102EEC
    /* 72C 80102F2C 0200C624 */   addiu     $a2, $a2, 0x2
    /* 730 80102F30 05000481 */  lb         $a0, 0x5($t0)
    /* 734 80102F34 06000581 */  lb         $a1, 0x6($t0)
    /* 738 80102F38 07000681 */  lb         $a2, 0x7($t0)
    /* 73C 80102F3C 4AEF030C */  jal        vs_mainMenu_setStrIntAgi
    /* 740 80102F40 01000724 */   addiu     $a3, $zero, 0x1
    /* 744 80102F44 E3EE030C */  jal        func_800FBB8C
    /* 748 80102F48 03000424 */   addiu     $a0, $zero, 0x3
    /* 74C 80102F4C 9AF0030C */  jal        vs_mainMenu_drawDpPpbars
    /* 750 80102F50 08000424 */   addiu     $a0, $zero, 0x8
    /* 754 80102F54 1000BF8F */  lw         $ra, 0x10($sp)
    /* 758 80102F58 00000000 */  nop
    /* 75C 80102F5C 0800E003 */  jr         $ra
    /* 760 80102F60 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102EC0
