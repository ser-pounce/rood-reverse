nonmatching func_8007CFCC, 0x2C

glabel func_8007CFCC
    /* 147CC 8007CFCC 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 147D0 8007CFD0 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 147D4 8007CFD4 80200400 */  sll        $a0, $a0, 2
    /* 147D8 8007CFD8 21208200 */  addu       $a0, $a0, $v0
    /* 147DC 8007CFDC 0000848C */  lw         $a0, 0x0($a0)
    /* 147E0 8007CFE0 00000000 */  nop
    /* 147E4 8007CFE4 02008010 */  beqz       $a0, .L8007CFF0
    /* 147E8 8007CFE8 21100000 */   addu      $v0, $zero, $zero
    /* 147EC 8007CFEC 26008290 */  lbu        $v0, 0x26($a0)
  .L8007CFF0:
    /* 147F0 8007CFF0 0800E003 */  jr         $ra
    /* 147F4 8007CFF4 00000000 */   nop
endlabel func_8007CFCC
