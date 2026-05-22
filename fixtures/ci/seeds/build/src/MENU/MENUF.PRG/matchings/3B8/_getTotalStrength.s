nonmatching _getTotalStrength, 0x20

glabel _getTotalStrength
    /* 66A8 80108EA8 0F80023C */  lui        $v0, %hi(vs_battle_characterState)
    /* 66AC 80108EAC FC19428C */  lw         $v0, %lo(vs_battle_characterState)($v0)
    /* 66B0 80108EB0 00000000 */  nop
    /* 66B4 80108EB4 3C00428C */  lw         $v0, 0x3C($v0)
    /* 66B8 80108EB8 00000000 */  nop
    /* 66BC 80108EBC 24004294 */  lhu        $v0, 0x24($v0)
    /* 66C0 80108EC0 0800E003 */  jr         $ra
    /* 66C4 80108EC4 00000000 */   nop
endlabel _getTotalStrength
