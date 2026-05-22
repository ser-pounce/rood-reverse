nonmatching func_800D5550, 0x14

glabel func_800D5550
    /* 6CD50 800D5550 40280500 */  sll        $a1, $a1, 1
    /* 6CD54 800D5554 21288500 */  addu       $a1, $a0, $a1
    /* 6CD58 800D5558 0400A294 */  lhu        $v0, 0x4($a1)
    /* 6CD5C 800D555C 0800E003 */  jr         $ra
    /* 6CD60 800D5560 21108200 */   addu      $v0, $a0, $v0
endlabel func_800D5550
