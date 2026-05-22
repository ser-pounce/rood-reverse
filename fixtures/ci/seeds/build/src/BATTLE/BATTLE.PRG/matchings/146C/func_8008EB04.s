nonmatching func_8008EB04, 0x20

glabel func_8008EB04
    /* 26304 8008EB04 0F80023C */  lui        $v0, %hi(D_800F1DCA)
    /* 26308 8008EB08 CA1D4290 */  lbu        $v0, %lo(D_800F1DCA)($v0)
    /* 2630C 8008EB0C 00000000 */  nop
    /* 26310 8008EB10 000082AC */  sw         $v0, 0x0($a0)
    /* 26314 8008EB14 0F80023C */  lui        $v0, %hi(D_800F1DC4)
    /* 26318 8008EB18 C41D4284 */  lh         $v0, %lo(D_800F1DC4)($v0)
    /* 2631C 8008EB1C 0800E003 */  jr         $ra
    /* 26320 8008EB20 0000A2AC */   sw        $v0, 0x0($a1)
endlabel func_8008EB04
