nonmatching func_8010839C, 0x5C

glabel func_8010839C
    /* 5B9C 8010839C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5BA0 801083A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 5BA4 801083A4 21808000 */  addu       $s0, $a0, $zero
    /* 5BA8 801083A8 2120A000 */  addu       $a0, $a1, $zero
    /* 5BAC 801083AC 2128C000 */  addu       $a1, $a2, $zero
    /* 5BB0 801083B0 BFFF0626 */  addiu      $a2, $s0, -0x41
    /* 5BB4 801083B4 0700C22C */  sltiu      $v0, $a2, 0x7
    /* 5BB8 801083B8 05004010 */  beqz       $v0, .L801083D0
    /* 5BBC 801083BC 1400BFAF */   sw        $ra, 0x14($sp)
    /* 5BC0 801083C0 EF39020C */  jal        func_8008E7BC
    /* 5BC4 801083C4 00000000 */   nop
    /* 5BC8 801083C8 07004014 */  bnez       $v0, .L801083E8
    /* 5BCC 801083CC 21100000 */   addu      $v0, $zero, $zero
  .L801083D0:
    /* 5BD0 801083D0 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 5BD4 801083D4 98154224 */  addiu      $v0, $v0, %lo(vs_main_stateFlags)
    /* 5BD8 801083D8 21100202 */  addu       $v0, $s0, $v0
    /* 5BDC 801083DC 3F034290 */  lbu        $v0, 0x33F($v0)
    /* 5BE0 801083E0 00000000 */  nop
    /* 5BE4 801083E4 0200422C */  sltiu      $v0, $v0, 0x2
  .L801083E8:
    /* 5BE8 801083E8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 5BEC 801083EC 1000B08F */  lw         $s0, 0x10($sp)
    /* 5BF0 801083F0 0800E003 */  jr         $ra
    /* 5BF4 801083F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8010839C
