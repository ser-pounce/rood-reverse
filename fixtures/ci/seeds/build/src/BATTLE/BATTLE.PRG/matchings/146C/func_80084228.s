nonmatching func_80084228, 0x20

glabel func_80084228
    /* 1BA28 80084228 FFF3033C */  lui        $v1, (0xF3FFFFFF >> 16)
    /* 1BA2C 8008422C 1C00A28C */  lw         $v0, 0x1C($a1)
    /* 1BA30 80084230 FFFF6334 */  ori        $v1, $v1, (0xF3FFFFFF & 0xFFFF)
    /* 1BA34 80084234 24104300 */  and        $v0, $v0, $v1
    /* 1BA38 80084238 0008033C */  lui        $v1, (0x8000000 >> 16)
    /* 1BA3C 8008423C 25104300 */  or         $v0, $v0, $v1
    /* 1BA40 80084240 0800E003 */  jr         $ra
    /* 1BA44 80084244 1C00A2AC */   sw        $v0, 0x1C($a1)
endlabel func_80084228
