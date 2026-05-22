nonmatching func_800D1E20, 0xC

glabel func_800D1E20
    /* 69620 800D1E20 0F80023C */  lui        $v0, %hi(D_800F55E8)
    /* 69624 800D1E24 0800E003 */  jr         $ra
    /* 69628 800D1E28 E85544AC */   sw        $a0, %lo(D_800F55E8)($v0)
endlabel func_800D1E20
