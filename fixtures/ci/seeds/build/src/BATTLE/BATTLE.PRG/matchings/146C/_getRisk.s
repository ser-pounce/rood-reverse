nonmatching _getRisk, 0x30

glabel _getRisk
    /* 1B0BC 800838BC 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1B0C0 800838C0 0000C290 */  lbu        $v0, 0x0($a2)
    /* 1B0C4 800838C4 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1B0C8 800838C8 80100200 */  sll        $v0, $v0, 2
    /* 1B0CC 800838CC 21104300 */  addu       $v0, $v0, $v1
    /* 1B0D0 800838D0 0000428C */  lw         $v0, 0x0($v0)
    /* 1B0D4 800838D4 00000000 */  nop
    /* 1B0D8 800838D8 3C00428C */  lw         $v0, 0x3C($v0)
    /* 1B0DC 800838DC 00000000 */  nop
    /* 1B0E0 800838E0 20004284 */  lh         $v0, 0x20($v0)
    /* 1B0E4 800838E4 0800E003 */  jr         $ra
    /* 1B0E8 800838E8 00000000 */   nop
endlabel _getRisk
