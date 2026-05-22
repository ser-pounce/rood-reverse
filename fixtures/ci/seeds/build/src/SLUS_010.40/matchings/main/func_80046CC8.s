nonmatching func_80046CC8, 0x90

glabel func_80046CC8
    /* 374C8 80046CC8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 374CC 80046CCC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 374D0 80046CD0 2180A000 */  addu       $s0, $a1, $zero
    /* 374D4 80046CD4 0580023C */  lui        $v0, %hi(_clutState)
    /* 374D8 80046CD8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 374DC 80046CDC 585D5124 */  addiu      $s1, $v0, %lo(_clutState)
    /* 374E0 80046CE0 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 374E4 80046CE4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 374E8 80046CE8 02002296 */  lhu        $v0, 0x2($s1)
    /* 374EC 80046CEC 00000000 */  nop
    /* 374F0 80046CF0 13004010 */  beqz       $v0, .L80046D40
    /* 374F4 80046CF4 2190C000 */   addu      $s2, $a2, $zero
    /* 374F8 80046CF8 201B010C */  jal        vs_main_loadClutTransition
    /* 374FC 80046CFC 00000000 */   nop
    /* 37500 80046D00 21200000 */  addu       $a0, $zero, $zero
    /* 37504 80046D04 21382002 */  addu       $a3, $s1, $zero
    /* 37508 80046D08 21304002 */  addu       $a2, $s2, $zero
    /* 3750C 80046D0C C0101000 */  sll        $v0, $s0, 3
    /* 37510 80046D10 21105000 */  addu       $v0, $v0, $s0
    /* 37514 80046D14 001A0200 */  sll        $v1, $v0, 8
    /* 37518 80046D18 21104300 */  addu       $v0, $v0, $v1
    /* 3751C 80046D1C 21285000 */  addu       $a1, $v0, $s0
  .L80046D20:
    /* 37520 80046D20 0000C394 */  lhu        $v1, 0x0($a2)
    /* 37524 80046D24 0200C624 */  addiu      $a2, $a2, 0x2
    /* 37528 80046D28 2110A700 */  addu       $v0, $a1, $a3
    /* 3752C 80046D2C 01008424 */  addiu      $a0, $a0, 0x1
    /* 37530 80046D30 0E0743A4 */  sh         $v1, 0x70E($v0)
    /* 37534 80046D34 00018228 */  slti       $v0, $a0, 0x100
    /* 37538 80046D38 F9FF4014 */  bnez       $v0, .L80046D20
    /* 3753C 80046D3C 0200A524 */   addiu     $a1, $a1, 0x2
  .L80046D40:
    /* 37540 80046D40 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 37544 80046D44 1800B28F */  lw         $s2, 0x18($sp)
    /* 37548 80046D48 1400B18F */  lw         $s1, 0x14($sp)
    /* 3754C 80046D4C 1000B08F */  lw         $s0, 0x10($sp)
    /* 37550 80046D50 0800E003 */  jr         $ra
    /* 37554 80046D54 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80046CC8
