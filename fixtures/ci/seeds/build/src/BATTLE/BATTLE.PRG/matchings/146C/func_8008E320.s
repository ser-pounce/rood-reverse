nonmatching func_8008E320, 0x50

glabel func_8008E320
    /* 25B20 8008E320 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0xA8)
    /* 25B24 8008E324 A01C458C */  lw         $a1, %lo(vs_battle_roomData + 0xA8)($v0)
    /* 25B28 8008E328 00000000 */  nop
    /* 25B2C 8008E32C 0E00A010 */  beqz       $a1, .L8008E368
    /* 25B30 8008E330 40100400 */   sll       $v0, $a0, 1
    /* 25B34 8008E334 21104400 */  addu       $v0, $v0, $a0
    /* 25B38 8008E338 C0100200 */  sll        $v0, $v0, 3
    /* 25B3C 8008E33C 23104400 */  subu       $v0, $v0, $a0
    /* 25B40 8008E340 C0100200 */  sll        $v0, $v0, 3
    /* 25B44 8008E344 2128A200 */  addu       $a1, $a1, $v0
    /* 25B48 8008E348 0400A28C */  lw         $v0, 0x4($a1)
    /* 25B4C 8008E34C 01000324 */  addiu      $v1, $zero, 0x1
    /* 25B50 8008E350 01004230 */  andi       $v0, $v0, 0x1
    /* 25B54 8008E354 04004314 */  bne        $v0, $v1, .L8008E368
    /* 25B58 8008E358 00000000 */   nop
    /* 25B5C 8008E35C 0600A294 */  lhu        $v0, 0x6($a1)
    /* 25B60 8008E360 0800E003 */  jr         $ra
    /* 25B64 8008E364 00000000 */   nop
  .L8008E368:
    /* 25B68 8008E368 0800E003 */  jr         $ra
    /* 25B6C 8008E36C FFFF0224 */   addiu     $v0, $zero, -0x1
endlabel func_8008E320
