nonmatching _setContainerItemIndex, 0x58

glabel _setContainerItemIndex
    /* 528 80102D28 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 52C 80102D2C 44994224 */  addiu      $v0, $v0, %lo(_containerItemCapacities)
    /* 530 80102D30 40200400 */  sll        $a0, $a0, 1
    /* 534 80102D34 21208200 */  addu       $a0, $a0, $v0
    /* 538 80102D38 00008294 */  lhu        $v0, 0x0($a0)
    /* 53C 80102D3C 00000000 */  nop
    /* 540 80102D40 0D004010 */  beqz       $v0, .L80102D78
    /* 544 80102D44 21180000 */   addu      $v1, $zero, $zero
    /* 548 80102D48 0100A524 */  addiu      $a1, $a1, 0x1
  .L80102D4C:
    /* 54C 80102D4C 0000C294 */  lhu        $v0, 0x0($a2)
    /* 550 80102D50 00000000 */  nop
    /* 554 80102D54 03004014 */  bnez       $v0, .L80102D64
    /* 558 80102D58 01006324 */   addiu     $v1, $v1, 0x1
    /* 55C 80102D5C 0800E003 */  jr         $ra
    /* 560 80102D60 0000C5A4 */   sh        $a1, 0x0($a2)
  .L80102D64:
    /* 564 80102D64 00008294 */  lhu        $v0, 0x0($a0)
    /* 568 80102D68 00000000 */  nop
    /* 56C 80102D6C 2A106200 */  slt        $v0, $v1, $v0
    /* 570 80102D70 F6FF4014 */  bnez       $v0, .L80102D4C
    /* 574 80102D74 0200C624 */   addiu     $a2, $a2, 0x2
  .L80102D78:
    /* 578 80102D78 0800E003 */  jr         $ra
    /* 57C 80102D7C 00000000 */   nop
endlabel _setContainerItemIndex
