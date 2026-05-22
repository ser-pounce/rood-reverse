nonmatching vs_battle_getShort, 0x34

glabel vs_battle_getShort
    /* 57600 800BFE00 01008230 */  andi       $v0, $a0, 0x1
    /* 57604 800BFE04 08004010 */  beqz       $v0, .L800BFE28
    /* 57608 800BFE08 00000000 */   nop
    /* 5760C 800BFE0C 01008390 */  lbu        $v1, 0x1($a0)
    /* 57610 800BFE10 00008290 */  lbu        $v0, 0x0($a0)
    /* 57614 800BFE14 001A0300 */  sll        $v1, $v1, 8
    /* 57618 800BFE18 25104300 */  or         $v0, $v0, $v1
    /* 5761C 800BFE1C 00140200 */  sll        $v0, $v0, 16
    /* 57620 800BFE20 0800E003 */  jr         $ra
    /* 57624 800BFE24 03140200 */   sra       $v0, $v0, 16
  .L800BFE28:
    /* 57628 800BFE28 00008284 */  lh         $v0, 0x0($a0)
    /* 5762C 800BFE2C 0800E003 */  jr         $ra
    /* 57630 800BFE30 00000000 */   nop
endlabel vs_battle_getShort
