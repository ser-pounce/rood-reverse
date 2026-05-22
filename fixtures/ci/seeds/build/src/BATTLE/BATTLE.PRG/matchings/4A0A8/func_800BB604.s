nonmatching func_800BB604, 0x64

glabel func_800BB604
    /* 52E04 800BB604 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 52E08 800BB608 1400B1AF */  sw         $s1, 0x14($sp)
    /* 52E0C 800BB60C 21880000 */  addu       $s1, $zero, $zero
    /* 52E10 800BB610 1000B0AF */  sw         $s0, 0x10($sp)
    /* 52E14 800BB614 21802002 */  addu       $s0, $s1, $zero
    /* 52E18 800BB618 1800BFAF */  sw         $ra, 0x18($sp)
  .L800BB61C:
    /* 52E1C 800BB61C 1934030C */  jal        vs_battle_dismissTextBox
    /* 52E20 800BB620 21200002 */   addu      $a0, $s0, $zero
    /* 52E24 800BB624 02004010 */  beqz       $v0, .L800BB630
    /* 52E28 800BB628 00000000 */   nop
    /* 52E2C 800BB62C 01003126 */  addiu      $s1, $s1, 0x1
  .L800BB630:
    /* 52E30 800BB630 01001026 */  addiu      $s0, $s0, 0x1
    /* 52E34 800BB634 0800022A */  slti       $v0, $s0, 0x8
    /* 52E38 800BB638 F8FF4014 */  bnez       $v0, .L800BB61C
    /* 52E3C 800BB63C 00000000 */   nop
    /* 52E40 800BB640 04002016 */  bnez       $s1, .L800BB654
    /* 52E44 800BB644 01000224 */   addiu     $v0, $zero, 0x1
    /* 52E48 800BB648 DBF0010C */  jal        func_8007C36C
    /* 52E4C 800BB64C 02000424 */   addiu     $a0, $zero, 0x2
    /* 52E50 800BB650 02000224 */  addiu      $v0, $zero, 0x2
  .L800BB654:
    /* 52E54 800BB654 1800BF8F */  lw         $ra, 0x18($sp)
    /* 52E58 800BB658 1400B18F */  lw         $s1, 0x14($sp)
    /* 52E5C 800BB65C 1000B08F */  lw         $s0, 0x10($sp)
    /* 52E60 800BB660 0800E003 */  jr         $ra
    /* 52E64 800BB664 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BB604
