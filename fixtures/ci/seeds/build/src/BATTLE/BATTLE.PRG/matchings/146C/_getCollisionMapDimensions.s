nonmatching _getCollisionMapDimensions, 0x38

glabel _getCollisionMapDimensions
    /* 22F0C 8008B70C 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x68)
    /* 22F10 8008B710 601C428C */  lw         $v0, %lo(vs_battle_roomData + 0x68)($v0)
    /* 22F14 8008B714 00000000 */  nop
    /* 22F18 8008B718 03004014 */  bnez       $v0, .L8008B728
    /* 22F1C 8008B71C 00000000 */   nop
    /* 22F20 8008B720 0800E003 */  jr         $ra
    /* 22F24 8008B724 21100000 */   addu      $v0, $zero, $zero
  .L8008B728:
    /* 22F28 8008B728 02004384 */  lh         $v1, 0x2($v0)
    /* 22F2C 8008B72C 00004284 */  lh         $v0, 0x0($v0)
    /* 22F30 8008B730 001D0300 */  sll        $v1, $v1, 20
    /* 22F34 8008B734 00110200 */  sll        $v0, $v0, 4
    /* 22F38 8008B738 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 22F3C 8008B73C 0800E003 */  jr         $ra
    /* 22F40 8008B740 25106200 */   or        $v0, $v1, $v0
endlabel _getCollisionMapDimensions
