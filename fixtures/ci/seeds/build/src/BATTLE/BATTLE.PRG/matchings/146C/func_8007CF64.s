nonmatching func_8007CF64, 0x1C

glabel func_8007CF64
    /* 14764 8007CF64 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 14768 8007CF68 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 1476C 8007CF6C 80200400 */  sll        $a0, $a0, 2
    /* 14770 8007CF70 21208200 */  addu       $a0, $a0, $v0
    /* 14774 8007CF74 0000828C */  lw         $v0, 0x0($a0)
    /* 14778 8007CF78 0800E003 */  jr         $ra
    /* 1477C 8007CF7C 00000000 */   nop
endlabel func_8007CF64
