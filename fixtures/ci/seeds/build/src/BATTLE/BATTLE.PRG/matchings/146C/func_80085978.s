nonmatching func_80085978, 0x3C

glabel func_80085978
    /* 1D178 80085978 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D17C 8008597C 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* 1D180 80085980 28194224 */  addiu      $v0, $v0, %lo(vs_battle_actors)
    /* 1D184 80085984 80280500 */  sll        $a1, $a1, 2
    /* 1D188 80085988 2128A200 */  addu       $a1, $a1, $v0
    /* 1D18C 8008598C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1D190 80085990 0000A28C */  lw         $v0, 0x0($a1)
    /* 1D194 80085994 00000000 */  nop
    /* 1D198 80085998 3C00458C */  lw         $a1, 0x3C($v0)
    /* 1D19C 8008599C D315020C */  jal        func_8008574C
    /* 1D1A0 800859A0 21300000 */   addu      $a2, $zero, $zero
    /* 1D1A4 800859A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D1A8 800859A8 00000000 */  nop
    /* 1D1AC 800859AC 0800E003 */  jr         $ra
    /* 1D1B0 800859B0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80085978
