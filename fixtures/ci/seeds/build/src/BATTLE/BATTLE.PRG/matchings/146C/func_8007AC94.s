nonmatching func_8007AC94, 0xC

glabel func_8007AC94
    /* 12494 8007AC94 801F023C */  lui        $v0, (0x1F80005C >> 16)
    /* 12498 8007AC98 0800E003 */  jr         $ra
    /* 1249C 8007AC9C 5C0044AC */   sw        $a0, (0x1F80005C & 0xFFFF)($v0)
endlabel func_8007AC94
