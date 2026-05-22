nonmatching _dismissAllTextBoxes, 0x50

glabel _dismissAllTextBoxes
    /* 62A68 800CB268 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 62A6C 800CB26C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 62A70 800CB270 01001124 */  addiu      $s1, $zero, 0x1
    /* 62A74 800CB274 1000B0AF */  sw         $s0, 0x10($sp)
    /* 62A78 800CB278 21800000 */  addu       $s0, $zero, $zero
    /* 62A7C 800CB27C 1800BFAF */  sw         $ra, 0x18($sp)
  .L800CB280:
    /* 62A80 800CB280 1934030C */  jal        vs_battle_dismissTextBox
    /* 62A84 800CB284 21200002 */   addu      $a0, $s0, $zero
    /* 62A88 800CB288 02004010 */  beqz       $v0, .L800CB294
    /* 62A8C 800CB28C 00000000 */   nop
    /* 62A90 800CB290 21880000 */  addu       $s1, $zero, $zero
  .L800CB294:
    /* 62A94 800CB294 01001026 */  addiu      $s0, $s0, 0x1
    /* 62A98 800CB298 0800022A */  slti       $v0, $s0, 0x8
    /* 62A9C 800CB29C F8FF4014 */  bnez       $v0, .L800CB280
    /* 62AA0 800CB2A0 21102002 */   addu      $v0, $s1, $zero
    /* 62AA4 800CB2A4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 62AA8 800CB2A8 1400B18F */  lw         $s1, 0x14($sp)
    /* 62AAC 800CB2AC 1000B08F */  lw         $s0, 0x10($sp)
    /* 62AB0 800CB2B0 0800E003 */  jr         $ra
    /* 62AB4 800CB2B4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _dismissAllTextBoxes
