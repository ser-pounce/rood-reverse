nonmatching vs_battle_getEquippedShieldDp, 0x30

glabel vs_battle_getEquippedShieldDp
    /* 1B01C 8008381C 0F80033C */  lui        $v1, %hi(vs_battle_actors)
    /* 1B020 80083820 0000A290 */  lbu        $v0, 0x0($a1)
    /* 1B024 80083824 28196324 */  addiu      $v1, $v1, %lo(vs_battle_actors)
    /* 1B028 80083828 80100200 */  sll        $v0, $v0, 2
    /* 1B02C 8008382C 21104300 */  addu       $v0, $v0, $v1
    /* 1B030 80083830 0000428C */  lw         $v0, 0x0($v0)
    /* 1B034 80083834 00000000 */  nop
    /* 1B038 80083838 3C00428C */  lw         $v0, 0x3C($v0)
    /* 1B03C 8008383C 00000000 */  nop
    /* 1B040 80083840 B0024284 */  lh         $v0, 0x2B0($v0)
    /* 1B044 80083844 0800E003 */  jr         $ra
    /* 1B048 80083848 00000000 */   nop
endlabel vs_battle_getEquippedShieldDp
