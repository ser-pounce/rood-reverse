nonmatching func_800CFB80, 0x78

glabel func_800CFB80
    /* 67380 800CFB80 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 67384 800CFB84 1000B0AF */  sw         $s0, 0x10($sp)
    /* 67388 800CFB88 21808000 */  addu       $s0, $a0, $zero
    /* 6738C 800CFB8C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 67390 800CFB90 2188A000 */  addu       $s1, $a1, $zero
    /* 67394 800CFB94 12001112 */  beq        $s0, $s1, .L800CFBE0
    /* 67398 800CFB98 1800BFAF */   sw        $ra, 0x18($sp)
    /* 6739C 800CFB9C 2A103002 */  slt        $v0, $s1, $s0
    /* 673A0 800CFBA0 08004010 */  beqz       $v0, .L800CFBC4
    /* 673A4 800CFBA4 00000000 */   nop
    /* 673A8 800CFBA8 B19B000C */  jal        rand
    /* 673AC 800CFBAC 00000000 */   nop
    /* 673B0 800CFBB0 23181102 */  subu       $v1, $s0, $s1
    /* 673B4 800CFBB4 1A004300 */  div        $zero, $v0, $v1
    /* 673B8 800CFBB8 10180000 */  mfhi       $v1
    /* 673BC 800CFBBC F93E0308 */  j          .L800CFBE4
    /* 673C0 800CFBC0 21107100 */   addu      $v0, $v1, $s1
  .L800CFBC4:
    /* 673C4 800CFBC4 B19B000C */  jal        rand
    /* 673C8 800CFBC8 00000000 */   nop
    /* 673CC 800CFBCC 23183002 */  subu       $v1, $s1, $s0
    /* 673D0 800CFBD0 1A004300 */  div        $zero, $v0, $v1
    /* 673D4 800CFBD4 10180000 */  mfhi       $v1
    /* 673D8 800CFBD8 F93E0308 */  j          .L800CFBE4
    /* 673DC 800CFBDC 21107000 */   addu      $v0, $v1, $s0
  .L800CFBE0:
    /* 673E0 800CFBE0 21100002 */  addu       $v0, $s0, $zero
  .L800CFBE4:
    /* 673E4 800CFBE4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 673E8 800CFBE8 1400B18F */  lw         $s1, 0x14($sp)
    /* 673EC 800CFBEC 1000B08F */  lw         $s0, 0x10($sp)
    /* 673F0 800CFBF0 0800E003 */  jr         $ra
    /* 673F4 800CFBF4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800CFB80
