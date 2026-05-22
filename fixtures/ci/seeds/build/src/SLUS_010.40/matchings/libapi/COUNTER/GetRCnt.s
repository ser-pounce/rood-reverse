nonmatching GetRCnt, 0x38

glabel GetRCnt
    /* 172C0 80026AC0 FFFF8330 */  andi       $v1, $a0, 0xFFFF
    /* 172C4 80026AC4 03006228 */  slti       $v0, $v1, 0x3
    /* 172C8 80026AC8 08004010 */  beqz       $v0, .L80026AEC
    /* 172CC 80026ACC 00190300 */   sll       $v1, $v1, 4
    /* 172D0 80026AD0 0380023C */  lui        $v0, %hi(_rootCounter0)
    /* 172D4 80026AD4 3828428C */  lw         $v0, %lo(_rootCounter0)($v0)
    /* 172D8 80026AD8 00000000 */  nop
    /* 172DC 80026ADC 21186200 */  addu       $v1, $v1, $v0
    /* 172E0 80026AE0 00006294 */  lhu        $v0, 0x0($v1)
    /* 172E4 80026AE4 BC9A0008 */  j          .L80026AF0
    /* 172E8 80026AE8 00000000 */   nop
  .L80026AEC:
    /* 172EC 80026AEC 21100000 */  addu       $v0, $zero, $zero
  .L80026AF0:
    /* 172F0 80026AF0 0800E003 */  jr         $ra
    /* 172F4 80026AF4 00000000 */   nop
endlabel GetRCnt
