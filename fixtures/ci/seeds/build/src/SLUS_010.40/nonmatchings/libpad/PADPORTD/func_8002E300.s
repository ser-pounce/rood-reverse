nonmatching func_8002E300, 0x20

glabel func_8002E300
    /* 1EB00 8002E300 0480023C */  lui        $v0, %hi(D_8003FCC0)
    /* 1EB04 8002E304 C0FC4224 */  addiu      $v0, $v0, %lo(D_8003FCC0)
    /* 1EB08 8002E308 F0008430 */  andi       $a0, $a0, 0xF0
    /* 1EB0C 8002E30C 02008010 */  beqz       $a0, .L8002E318
    /* 1EB10 8002E310 00000000 */   nop
    /* 1EB14 8002E314 F0004224 */  addiu      $v0, $v0, 0xF0
  .L8002E318:
    /* 1EB18 8002E318 0800E003 */  jr         $ra
    /* 1EB1C 8002E31C 00000000 */   nop
endlabel func_8002E300
    /* 1EB20 8002E320 00000000 */  nop
