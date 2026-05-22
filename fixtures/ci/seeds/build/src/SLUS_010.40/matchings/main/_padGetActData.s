nonmatching _padGetActData, 0x2C

glabel _padGetActData
    /* 33B88 80043388 0580033C */  lui        $v1, %hi(_portInfo)
    /* 33B8C 8004338C 90016324 */  addiu      $v1, $v1, %lo(_portInfo)
    /* 33B90 80043390 40100400 */  sll        $v0, $a0, 1
    /* 33B94 80043394 21104400 */  addu       $v0, $v0, $a0
    /* 33B98 80043398 80100200 */  sll        $v0, $v0, 2
    /* 33B9C 8004339C 23104400 */  subu       $v0, $v0, $a0
    /* 33BA0 800433A0 2128A200 */  addu       $a1, $a1, $v0
    /* 33BA4 800433A4 2128A300 */  addu       $a1, $a1, $v1
    /* 33BA8 800433A8 0800A290 */  lbu        $v0, 0x8($a1)
    /* 33BAC 800433AC 0800E003 */  jr         $ra
    /* 33BB0 800433B0 00000000 */   nop
endlabel _padGetActData
