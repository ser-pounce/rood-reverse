nonmatching SetSemiTrans, 0x28

glabel SetSemiTrans
    /* 1BD74 8002B574 0400A010 */  beqz       $a1, .L8002B588
    /* 1BD78 8002B578 00000000 */   nop
    /* 1BD7C 8002B57C 07008290 */  lbu        $v0, 0x7($a0)
    /* 1BD80 8002B580 65AD0008 */  j          .L8002B594
    /* 1BD84 8002B584 02004234 */   ori       $v0, $v0, 0x2
  .L8002B588:
    /* 1BD88 8002B588 07008290 */  lbu        $v0, 0x7($a0)
    /* 1BD8C 8002B58C 00000000 */  nop
    /* 1BD90 8002B590 FD004230 */  andi       $v0, $v0, 0xFD
  .L8002B594:
    /* 1BD94 8002B594 0800E003 */  jr         $ra
    /* 1BD98 8002B598 070082A0 */   sb        $v0, 0x7($a0)
endlabel SetSemiTrans
    /* 1BD9C 8002B59C 00000000 */  nop
    /* 1BDA0 8002B5A0 00000000 */  nop
