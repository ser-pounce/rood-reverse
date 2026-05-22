nonmatching func_8008AB80, 0x38

glabel func_8008AB80
    /* 22380 8008AB80 0F80023C */  lui        $v0, %hi(vs_battle_roomData)
    /* 22384 8008AB84 F81B4524 */  addiu      $a1, $v0, %lo(vs_battle_roomData)
    /* 22388 8008AB88 F81B4390 */  lbu        $v1, %lo(vs_battle_roomData)($v0)
    /* 2238C 8008AB8C 01000224 */  addiu      $v0, $zero, 0x1
    /* 22390 8008AB90 07006214 */  bne        $v1, $v0, .L8008ABB0
    /* 22394 8008AB94 00000000 */   nop
    /* 22398 8008AB98 0200A284 */  lh         $v0, 0x2($a1)
    /* 2239C 8008AB9C 00000000 */  nop
    /* 223A0 8008ABA0 03004414 */  bne        $v0, $a0, .L8008ABB0
    /* 223A4 8008ABA4 01000224 */   addiu     $v0, $zero, 0x1
    /* 223A8 8008ABA8 0800E003 */  jr         $ra
    /* 223AC 8008ABAC 0100A3A0 */   sb        $v1, 0x1($a1)
  .L8008ABB0:
    /* 223B0 8008ABB0 0800E003 */  jr         $ra
    /* 223B4 8008ABB4 21100000 */   addu      $v0, $zero, $zero
endlabel func_8008AB80
