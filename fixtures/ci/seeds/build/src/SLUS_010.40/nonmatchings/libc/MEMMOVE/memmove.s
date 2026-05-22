nonmatching memmove, 0x6C

glabel memmove
    /* 17F94 80027794 21388000 */  addu       $a3, $a0, $zero
    /* 17F98 80027798 2B10E500 */  sltu       $v0, $a3, $a1
    /* 17F9C 8002779C 0C004014 */  bnez       $v0, .L800277D0
    /* 17FA0 800277A0 2110C000 */   addu      $v0, $a2, $zero
    /* 17FA4 800277A4 13004018 */  blez       $v0, .L800277F4
    /* 17FA8 800277A8 FFFFC624 */   addiu     $a2, $a2, -0x1
  .L800277AC:
    /* 17FAC 800277AC 2120E600 */  addu       $a0, $a3, $a2
    /* 17FB0 800277B0 2110A600 */  addu       $v0, $a1, $a2
    /* 17FB4 800277B4 2118C000 */  addu       $v1, $a2, $zero
    /* 17FB8 800277B8 00004290 */  lbu        $v0, 0x0($v0)
    /* 17FBC 800277BC FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 17FC0 800277C0 FAFF601C */  bgtz       $v1, .L800277AC
    /* 17FC4 800277C4 000082A0 */   sb        $v0, 0x0($a0)
    /* 17FC8 800277C8 FE9D0008 */  j          .L800277F8
    /* 17FCC 800277CC 2110E000 */   addu      $v0, $a3, $zero
  .L800277D0:
    /* 17FD0 800277D0 08004018 */  blez       $v0, .L800277F4
    /* 17FD4 800277D4 FFFFC624 */   addiu     $a2, $a2, -0x1
  .L800277D8:
    /* 17FD8 800277D8 0000A290 */  lbu        $v0, 0x0($a1)
    /* 17FDC 800277DC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 17FE0 800277E0 2118C000 */  addu       $v1, $a2, $zero
    /* 17FE4 800277E4 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 17FE8 800277E8 0000E2A0 */  sb         $v0, 0x0($a3)
    /* 17FEC 800277EC FAFF601C */  bgtz       $v1, .L800277D8
    /* 17FF0 800277F0 0100E724 */   addiu     $a3, $a3, 0x1
  .L800277F4:
    /* 17FF4 800277F4 2110E000 */  addu       $v0, $a3, $zero
  .L800277F8:
    /* 17FF8 800277F8 0800E003 */  jr         $ra
    /* 17FFC 800277FC 00000000 */   nop
endlabel memmove
    /* 18000 80027800 00000000 */  nop
