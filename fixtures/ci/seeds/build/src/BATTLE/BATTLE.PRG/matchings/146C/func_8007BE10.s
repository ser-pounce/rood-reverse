nonmatching func_8007BE10, 0x10

glabel func_8007BE10
    /* 13610 8007BE10 21108000 */  addu       $v0, $a0, $zero
    /* 13614 8007BE14 0F80033C */  lui        $v1, %hi(D_800F18B0)
    /* 13618 8007BE18 0800E003 */  jr         $ra
    /* 1361C 8007BE1C B01862AC */   sw        $v0, %lo(D_800F18B0)($v1)
endlabel func_8007BE10
