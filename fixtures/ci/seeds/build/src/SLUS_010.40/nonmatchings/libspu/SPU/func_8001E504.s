nonmatching func_8001E504, 0x28

glabel func_8001E504
    /* ED04 8001E504 0380043C */  lui        $a0, %hi(D_80030874)
    /* ED08 8001E508 7408848C */  lw         $a0, %lo(D_80030874)($a0)
    /* ED0C 8001E50C FFF0033C */  lui        $v1, (0xF0FFFFFF >> 16)
    /* ED10 8001E510 0000828C */  lw         $v0, 0x0($a0)
    /* ED14 8001E514 FFFF6334 */  ori        $v1, $v1, (0xF0FFFFFF & 0xFFFF)
    /* ED18 8001E518 24104300 */  and        $v0, $v0, $v1
    /* ED1C 8001E51C 0022033C */  lui        $v1, (0x22000000 >> 16)
    /* ED20 8001E520 25104300 */  or         $v0, $v0, $v1
    /* ED24 8001E524 0800E003 */  jr         $ra
    /* ED28 8001E528 000082AC */   sw        $v0, 0x0($a0)
endlabel func_8001E504
