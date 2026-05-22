nonmatching _getContainerItemIndex, 0x58

glabel _getContainerItemIndex
    /* 4D0 80102CD0 1180023C */  lui        $v0, %hi(_containerItemCapacities)
    /* 4D4 80102CD4 44994224 */  addiu      $v0, $v0, %lo(_containerItemCapacities)
    /* 4D8 80102CD8 40200400 */  sll        $a0, $a0, 1
    /* 4DC 80102CDC 21208200 */  addu       $a0, $a0, $v0
    /* 4E0 80102CE0 00008294 */  lhu        $v0, 0x0($a0)
    /* 4E4 80102CE4 00000000 */  nop
    /* 4E8 80102CE8 0B004010 */  beqz       $v0, .L80102D18
    /* 4EC 80102CEC 21180000 */   addu      $v1, $zero, $zero
    /* 4F0 80102CF0 0100A524 */  addiu      $a1, $a1, 0x1
    /* 4F4 80102CF4 21204000 */  addu       $a0, $v0, $zero
  .L80102CF8:
    /* 4F8 80102CF8 0000C294 */  lhu        $v0, 0x0($a2)
    /* 4FC 80102CFC 00000000 */  nop
    /* 500 80102D00 07004510 */  beq        $v0, $a1, .L80102D20
    /* 504 80102D04 01006224 */   addiu     $v0, $v1, 0x1
    /* 508 80102D08 01006324 */  addiu      $v1, $v1, 0x1
    /* 50C 80102D0C 2A106400 */  slt        $v0, $v1, $a0
    /* 510 80102D10 F9FF4014 */  bnez       $v0, .L80102CF8
    /* 514 80102D14 0200C624 */   addiu     $a2, $a2, 0x2
  .L80102D18:
    /* 518 80102D18 0800E003 */  jr         $ra
    /* 51C 80102D1C 21100000 */   addu      $v0, $zero, $zero
  .L80102D20:
    /* 520 80102D20 0800E003 */  jr         $ra
    /* 524 80102D24 00000000 */   nop
endlabel _getContainerItemIndex
