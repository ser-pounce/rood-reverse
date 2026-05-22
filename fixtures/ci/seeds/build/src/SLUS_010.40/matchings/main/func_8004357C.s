nonmatching func_8004357C, 0x60

glabel func_8004357C
    /* 33D7C 8004357C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 33D80 80043580 FFFF8224 */  addiu      $v0, $a0, -0x1
    /* 33D84 80043584 0200422C */  sltiu      $v0, $v0, 0x2
    /* 33D88 80043588 1400BFAF */  sw         $ra, 0x14($sp)
    /* 33D8C 8004358C 05004010 */  beqz       $v0, .L800435A4
    /* 33D90 80043590 1000B0AF */   sw        $s0, 0x10($sp)
    /* 33D94 80043594 550D010C */  jal        func_80043554
    /* 33D98 80043598 00000000 */   nop
    /* 33D9C 8004359C 730D0108 */  j          .L800435CC
    /* 33DA0 800435A0 00000000 */   nop
  .L800435A4:
    /* 33DA4 800435A4 09008014 */  bnez       $a0, .L800435CC
    /* 33DA8 800435A8 21100000 */   addu      $v0, $zero, $zero
    /* 33DAC 800435AC 21800000 */  addu       $s0, $zero, $zero
    /* 33DB0 800435B0 01001026 */  addiu      $s0, $s0, 0x1
  .L800435B4:
    /* 33DB4 800435B4 550D010C */  jal        func_80043554
    /* 33DB8 800435B8 21200002 */   addu      $a0, $s0, $zero
    /* 33DBC 800435BC 0200022A */  slti       $v0, $s0, 0x2
    /* 33DC0 800435C0 FCFF4014 */  bnez       $v0, .L800435B4
    /* 33DC4 800435C4 01001026 */   addiu     $s0, $s0, 0x1
    /* 33DC8 800435C8 01000224 */  addiu      $v0, $zero, 0x1
  .L800435CC:
    /* 33DCC 800435CC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 33DD0 800435D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 33DD4 800435D4 0800E003 */  jr         $ra
    /* 33DD8 800435D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004357C
