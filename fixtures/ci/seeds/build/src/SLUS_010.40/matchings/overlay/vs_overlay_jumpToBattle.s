nonmatching vs_overlay_jumpToBattle, 0x10

glabel vs_overlay_jumpToBattle
    /* 12C4 80010AC4 21408000 */  addu       $t0, $a0, $zero
    /* 12C8 80010AC8 00001D8D */  lw         $sp, 0x0($t0)
    /* 12CC 80010ACC 29E60108 */  j          vs_battle_exec
    /* 12D0 80010AD0 00000000 */   nop
endlabel vs_overlay_jumpToBattle
