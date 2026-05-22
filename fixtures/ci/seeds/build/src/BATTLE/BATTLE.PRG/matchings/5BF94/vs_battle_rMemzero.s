nonmatching vs_battle_rMemzero, 0x18

glabel vs_battle_rMemzero
    /* 6441C 800CCC1C 21108500 */  addu       $v0, $a0, $a1
  .L800CCC20:
    /* 64420 800CCC20 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* 64424 800CCC24 FEFF8214 */  bne        $a0, $v0, .L800CCC20
    /* 64428 800CCC28 000040AC */   sw        $zero, 0x0($v0)
    /* 6442C 800CCC2C 0800E003 */  jr         $ra
    /* 64430 800CCC30 00000000 */   nop
endlabel vs_battle_rMemzero
