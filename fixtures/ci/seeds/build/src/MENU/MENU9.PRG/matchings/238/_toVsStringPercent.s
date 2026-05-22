nonmatching _toVsStringPercent, 0x84

glabel _toVsStringPercent
    /* 455C 80106D5C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4560 80106D60 2130A000 */  addu       $a2, $a1, $zero
    /* 4564 80106D64 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4568 80106D68 21808000 */  addu       $s0, $a0, $zero
    /* 456C 80106D6C 1080053C */  lui        $a1, %hi(D_801029AC)
    /* 4570 80106D70 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4574 80106D74 BD9B000C */  jal        sprintf
    /* 4578 80106D78 AC29A524 */   addiu     $a1, $a1, %lo(D_801029AC)
    /* 457C 80106D7C A59B000C */  jal        strlen
    /* 4580 80106D80 21200002 */   addu      $a0, $s0, $zero
    /* 4584 80106D84 21284000 */  addu       $a1, $v0, $zero
    /* 4588 80106D88 0900A018 */  blez       $a1, .L80106DB0
    /* 458C 80106D8C 21200000 */   addu      $a0, $zero, $zero
    /* 4590 80106D90 21100402 */  addu       $v0, $s0, $a0
  .L80106D94:
    /* 4594 80106D94 00004390 */  lbu        $v1, 0x0($v0)
    /* 4598 80106D98 01008424 */  addiu      $a0, $a0, 0x1
    /* 459C 80106D9C D0FF6324 */  addiu      $v1, $v1, -0x30
    /* 45A0 80106DA0 000043A0 */  sb         $v1, 0x0($v0)
    /* 45A4 80106DA4 2A108500 */  slt        $v0, $a0, $a1
    /* 45A8 80106DA8 FAFF4014 */  bnez       $v0, .L80106D94
    /* 45AC 80106DAC 21100402 */   addu      $v0, $s0, $a0
  .L80106DB0:
    /* 45B0 80106DB0 21800502 */  addu       $s0, $s0, $a1
    /* 45B4 80106DB4 1180023C */  lui        $v0, %hi(D_8010989C)
    /* 45B8 80106DB8 9C984A24 */  addiu      $t2, $v0, %lo(D_8010989C)
    /* 45BC 80106DBC 03004789 */  lwl        $a3, 0x3($t2)
    /* 45C0 80106DC0 00004799 */  lwr        $a3, 0x0($t2)
    /* 45C4 80106DC4 00000000 */  nop
    /* 45C8 80106DC8 030007AA */  swl        $a3, 0x3($s0)
    /* 45CC 80106DCC 000007BA */  swr        $a3, 0x0($s0)
    /* 45D0 80106DD0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 45D4 80106DD4 1000B08F */  lw         $s0, 0x10($sp)
    /* 45D8 80106DD8 0800E003 */  jr         $ra
    /* 45DC 80106DDC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _toVsStringPercent
