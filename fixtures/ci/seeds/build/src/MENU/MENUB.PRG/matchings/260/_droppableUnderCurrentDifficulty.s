nonmatching _droppableUnderCurrentDifficulty, 0x18

glabel _droppableUnderCurrentDifficulty
    /* 5EDC 801086DC 0680023C */  lui        $v0, %hi(vs_main_stateFlags + 0x1)
    /* 5EE0 801086E0 99154290 */  lbu        $v0, %lo(vs_main_stateFlags + 0x1)($v0)
    /* 5EE4 801086E4 00000000 */  nop
    /* 5EE8 801086E8 01004224 */  addiu      $v0, $v0, 0x1
    /* 5EEC 801086EC 0800E003 */  jr         $ra
    /* 5EF0 801086F0 24108200 */   and       $v0, $a0, $v0
endlabel _droppableUnderCurrentDifficulty
