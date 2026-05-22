nonmatching func_8001E4DC, 0x28

glabel func_8001E4DC
    /* ECDC 8001E4DC 0380043C */  lui        $a0, %hi(D_80030874)
    /* ECE0 8001E4E0 7408848C */  lw         $a0, %lo(D_80030874)($a0)
    /* ECE4 8001E4E4 FFF0033C */  lui        $v1, (0xF0FFFFFF >> 16)
    /* ECE8 8001E4E8 0000828C */  lw         $v0, 0x0($a0)
    /* ECEC 8001E4EC FFFF6334 */  ori        $v1, $v1, (0xF0FFFFFF & 0xFFFF)
    /* ECF0 8001E4F0 24104300 */  and        $v0, $v0, $v1
    /* ECF4 8001E4F4 0020033C */  lui        $v1, (0x20000000 >> 16)
    /* ECF8 8001E4F8 25104300 */  or         $v0, $v0, $v1
    /* ECFC 8001E4FC 0800E003 */  jr         $ra
    /* ED00 8001E500 000082AC */   sw        $v0, 0x0($a0)
endlabel func_8001E4DC
