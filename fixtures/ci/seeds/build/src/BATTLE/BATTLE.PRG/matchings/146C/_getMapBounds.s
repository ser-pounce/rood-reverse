nonmatching _getMapBounds, 0x20

glabel _getMapBounds
    /* 22F44 8008B744 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0xC0)
    /* 22F48 8008B748 B81C438C */  lw         $v1, %lo(vs_battle_roomData + 0xC0)($v0)
    /* 22F4C 8008B74C 00000000 */  nop
    /* 22F50 8008B750 02006014 */  bnez       $v1, .L8008B75C
    /* 22F54 8008B754 21106000 */   addu      $v0, $v1, $zero
    /* 22F58 8008B758 21100000 */  addu       $v0, $zero, $zero
  .L8008B75C:
    /* 22F5C 8008B75C 0800E003 */  jr         $ra
    /* 22F60 8008B760 00000000 */   nop
endlabel _getMapBounds
