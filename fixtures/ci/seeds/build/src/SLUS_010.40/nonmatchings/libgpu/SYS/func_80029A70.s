nonmatching func_80029A70, 0x80

glabel func_80029A70
    /* 1A270 80029A70 03008014 */  bnez       $a0, .L80029A80
    /* 1A274 80029A74 F0FFBD27 */   addiu     $sp, $sp, -0x10
    /* 1A278 80029A78 BAA60008 */  j          .L80029AE8
    /* 1A27C 80029A7C 21100000 */   addu      $v0, $zero, $zero
  .L80029A80:
    /* 1A280 80029A80 00008590 */  lbu        $a1, 0x0($a0)
    /* 1A284 80029A84 00000000 */  nop
    /* 1A288 80029A88 C2280500 */  srl        $a1, $a1, 3
    /* 1A28C 80029A8C 0000A5AF */  sw         $a1, 0x0($sp)
    /* 1A290 80029A90 04008684 */  lh         $a2, 0x4($a0)
    /* 1A294 80029A94 00000000 */  nop
    /* 1A298 80029A98 23300600 */  negu       $a2, $a2
    /* 1A29C 80029A9C FF00C630 */  andi       $a2, $a2, 0xFF
    /* 1A2A0 80029AA0 C3300600 */  sra        $a2, $a2, 3
    /* 1A2A4 80029AA4 0800A6AF */  sw         $a2, 0x8($sp)
    /* 1A2A8 80029AA8 02008290 */  lbu        $v0, 0x2($a0)
    /* 1A2AC 80029AAC 802A0500 */  sll        $a1, $a1, 10
    /* 1A2B0 80029AB0 C2100200 */  srl        $v0, $v0, 3
    /* 1A2B4 80029AB4 0400A2AF */  sw         $v0, 0x4($sp)
    /* 1A2B8 80029AB8 C0130200 */  sll        $v0, $v0, 15
    /* 1A2BC 80029ABC 06008384 */  lh         $v1, 0x6($a0)
    /* 1A2C0 80029AC0 00E2043C */  lui        $a0, (0xE2000000 >> 16)
    /* 1A2C4 80029AC4 2528A400 */  or         $a1, $a1, $a0
    /* 1A2C8 80029AC8 25104500 */  or         $v0, $v0, $a1
    /* 1A2CC 80029ACC 23180300 */  negu       $v1, $v1
    /* 1A2D0 80029AD0 FF006330 */  andi       $v1, $v1, 0xFF
    /* 1A2D4 80029AD4 C3180300 */  sra        $v1, $v1, 3
    /* 1A2D8 80029AD8 40210300 */  sll        $a0, $v1, 5
    /* 1A2DC 80029ADC 25104400 */  or         $v0, $v0, $a0
    /* 1A2E0 80029AE0 25104600 */  or         $v0, $v0, $a2
    /* 1A2E4 80029AE4 0C00A3AF */  sw         $v1, 0xC($sp)
  .L80029AE8:
    /* 1A2E8 80029AE8 0800E003 */  jr         $ra
    /* 1A2EC 80029AEC 1000BD27 */   addiu     $sp, $sp, 0x10
endlabel func_80029A70
