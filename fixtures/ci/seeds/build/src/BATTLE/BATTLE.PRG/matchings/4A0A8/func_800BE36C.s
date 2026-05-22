nonmatching func_800BE36C, 0x34

glabel func_800BE36C
    /* 55B6C 800BE36C 0F80033C */  lui        $v1, %hi(D_800F4BA4)
    /* 55B70 800BE370 A44B628C */  lw         $v0, %lo(D_800F4BA4)($v1)
    /* 55B74 800BE374 00000000 */  nop
    /* 55B78 800BE378 060044A0 */  sb         $a0, 0x6($v0)
    /* 55B7C 800BE37C A44B628C */  lw         $v0, %lo(D_800F4BA4)($v1)
    /* 55B80 800BE380 00000000 */  nop
    /* 55B84 800BE384 070040A0 */  sb         $zero, 0x7($v0)
    /* 55B88 800BE388 A44B628C */  lw         $v0, %lo(D_800F4BA4)($v1)
    /* 55B8C 800BE38C 00000000 */  nop
    /* 55B90 800BE390 BA0045A0 */  sb         $a1, 0xBA($v0)
    /* 55B94 800BE394 A44B628C */  lw         $v0, %lo(D_800F4BA4)($v1)
    /* 55B98 800BE398 0800E003 */  jr         $ra
    /* 55B9C 800BE39C BB0040A0 */   sb        $zero, 0xBB($v0)
endlabel func_800BE36C
