nonmatching func_800C7210, 0x20

glabel func_800C7210
    /* 5EA10 800C7210 0F80023C */  lui        $v0, %hi(_fontTable)
    /* 5EA14 800C7214 0F80033C */  lui        $v1, %hi(_fontBrightness)
    /* 5EA18 800C7218 B94C40A0 */  sb         $zero, %lo(_fontTable)($v0)
    /* 5EA1C 800C721C 80010224 */  addiu      $v0, $zero, 0x180
    /* 5EA20 800C7220 BC4C62AC */  sw         $v0, %lo(_fontBrightness)($v1)
    /* 5EA24 800C7224 0F80023C */  lui        $v0, %hi(D_800F4CB8)
    /* 5EA28 800C7228 0800E003 */  jr         $ra
    /* 5EA2C 800C722C B84C44A0 */   sb        $a0, %lo(D_800F4CB8)($v0)
endlabel func_800C7210
