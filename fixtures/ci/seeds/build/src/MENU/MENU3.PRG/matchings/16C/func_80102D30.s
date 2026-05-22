nonmatching func_80102D30, 0x4C

glabel func_80102D30
    /* 530 80102D30 0F80063C */  lui        $a2, %hi(D_800F4EE8)
    /* 534 80102D34 E84EC624 */  addiu      $a2, $a2, %lo(D_800F4EE8)
    /* 538 80102D38 1E008224 */  addiu      $v0, $a0, 0x1E
    /* 53C 80102D3C 40100200 */  sll        $v0, $v0, 1
    /* 540 80102D40 21184600 */  addu       $v1, $v0, $a2
    /* 544 80102D44 01004224 */  addiu      $v0, $v0, 0x1
    /* 548 80102D48 21104600 */  addu       $v0, $v0, $a2
    /* 54C 80102D4C 000060A0 */  sb         $zero, 0x0($v1)
    /* 550 80102D50 000045A0 */  sb         $a1, 0x0($v0)
    /* 554 80102D54 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryIndices)
    /* 558 80102D58 A8224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryIndices)
    /* 55C 80102D5C 80200400 */  sll        $a0, $a0, 2
    /* 560 80102D60 21208200 */  addu       $a0, $a0, $v0
    /* 564 80102D64 0000828C */  lw         $v0, 0x0($a0)
    /* 568 80102D68 00000000 */  nop
    /* 56C 80102D6C 21104500 */  addu       $v0, $v0, $a1
    /* 570 80102D70 00004290 */  lbu        $v0, 0x0($v0)
    /* 574 80102D74 0800E003 */  jr         $ra
    /* 578 80102D78 00000000 */   nop
endlabel func_80102D30
