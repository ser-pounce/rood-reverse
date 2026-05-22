nonmatching ResetRCnt, 0x34

glabel ResetRCnt
    /* 1735C 80026B5C FFFF8330 */  andi       $v1, $a0, 0xFFFF
    /* 17360 80026B60 03006228 */  slti       $v0, $v1, 0x3
    /* 17364 80026B64 07004010 */  beqz       $v0, .L80026B84
    /* 17368 80026B68 01000224 */   addiu     $v0, $zero, 0x1
    /* 1736C 80026B6C 0380043C */  lui        $a0, %hi(_rootCounter0)
    /* 17370 80026B70 3828848C */  lw         $a0, %lo(_rootCounter0)($a0)
    /* 17374 80026B74 00190300 */  sll        $v1, $v1, 4
    /* 17378 80026B78 21186400 */  addu       $v1, $v1, $a0
    /* 1737C 80026B7C E29A0008 */  j          .L80026B88
    /* 17380 80026B80 000060A4 */   sh        $zero, 0x0($v1)
  .L80026B84:
    /* 17384 80026B84 21100000 */  addu       $v0, $zero, $zero
  .L80026B88:
    /* 17388 80026B88 0800E003 */  jr         $ra
    /* 1738C 80026B8C 00000000 */   nop
endlabel ResetRCnt
    /* 17390 80026B90 00000000 */  nop
