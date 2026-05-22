nonmatching func_8008B2C0, 0x20

glabel func_8008B2C0
    /* 22AC0 8008B2C0 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 22AC4 8008B2C4 F81B4390 */  lbu        $v1, %lo(vs_battle_roomData)($v0)
    /* 22AC8 8008B2C8 00000000 */  nop
    /* 22ACC 8008B2CC 02006010 */  beqz       $v1, .L8008B2D8
    /* 22AD0 8008B2D0 F81B4224 */   addiu     $v0, $v0, %lo(vs_battle_roomData)
    /* 22AD4 8008B2D4 010044A0 */  sb         $a0, 0x1($v0)
  .L8008B2D8:
    /* 22AD8 8008B2D8 0800E003 */  jr         $ra
    /* 22ADC 8008B2DC 00000000 */   nop
endlabel func_8008B2C0
