nonmatching _getTotalIntelligence, 0x20

glabel _getTotalIntelligence
    /* 66C8 80108EC8 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 66CC 80108ECC FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 66D0 80108ED0 00000000 */  nop
    /* 66D4 80108ED4 3C00428C */  lw         $v0, 0x3C($v0)
    /* 66D8 80108ED8 00000000 */  nop
    /* 66DC 80108EDC 28004294 */  lhu        $v0, 0x28($v0)
    /* 66E0 80108EE0 0800E003 */  jr         $ra
    /* 66E4 80108EE4 00000000 */   nop
endlabel _getTotalIntelligence
