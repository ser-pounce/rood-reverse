nonmatching _getItemIndex, 0x4C

glabel _getItemIndex
    /* 608 80102E08 0F80063C */  lui        $a2, %hi(D_800F4EE8)
    /* 60C 80102E0C E84EC624 */  addiu      $a2, $a2, %lo(D_800F4EE8)
    /* 610 80102E10 1E008224 */  addiu      $v0, $a0, 0x1E
    /* 614 80102E14 40100200 */  sll        $v0, $v0, 1
    /* 618 80102E18 21184600 */  addu       $v1, $v0, $a2
    /* 61C 80102E1C 01004224 */  addiu      $v0, $v0, 0x1
    /* 620 80102E20 21104600 */  addu       $v0, $v0, $a2
    /* 624 80102E24 000060A0 */  sb         $zero, 0x0($v1)
    /* 628 80102E28 000045A0 */  sb         $a1, 0x0($v0)
    /* 62C 80102E2C 1080023C */  lui        $v0, %hi(vs_mainMenu_inventoryIndices)
    /* 630 80102E30 A8224224 */  addiu      $v0, $v0, %lo(vs_mainMenu_inventoryIndices)
    /* 634 80102E34 80200400 */  sll        $a0, $a0, 2
    /* 638 80102E38 21208200 */  addu       $a0, $a0, $v0
    /* 63C 80102E3C 0000828C */  lw         $v0, 0x0($a0)
    /* 640 80102E40 00000000 */  nop
    /* 644 80102E44 21104500 */  addu       $v0, $v0, $a1
    /* 648 80102E48 00004290 */  lbu        $v0, 0x0($v0)
    /* 64C 80102E4C 0800E003 */  jr         $ra
    /* 650 80102E50 00000000 */   nop
endlabel _getItemIndex
