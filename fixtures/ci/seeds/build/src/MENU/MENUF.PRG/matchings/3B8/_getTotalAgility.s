nonmatching _getTotalAgility, 0x20

glabel _getTotalAgility
    /* 66E8 80108EE8 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 66EC 80108EEC FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 66F0 80108EF0 00000000 */  nop
    /* 66F4 80108EF4 3C00428C */  lw         $v0, 0x3C($v0)
    /* 66F8 80108EF8 00000000 */  nop
    /* 66FC 80108EFC 2C004294 */  lhu        $v0, 0x2C($v0)
    /* 6700 80108F00 0800E003 */  jr         $ra
    /* 6704 80108F04 00000000 */   nop
endlabel _getTotalAgility
