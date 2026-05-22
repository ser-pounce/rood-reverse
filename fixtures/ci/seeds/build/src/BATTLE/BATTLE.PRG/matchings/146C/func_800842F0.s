nonmatching func_800842F0, 0x20

glabel func_800842F0
    /* 1BAF0 800842F0 FFF3033C */  lui        $v1, (0xF3FFFFFF >> 16)
    /* 1BAF4 800842F4 1C00A28C */  lw         $v0, 0x1C($a1)
    /* 1BAF8 800842F8 FFFF6334 */  ori        $v1, $v1, (0xF3FFFFFF & 0xFFFF)
    /* 1BAFC 800842FC 24104300 */  and        $v0, $v0, $v1
    /* 1BB00 80084300 0008033C */  lui        $v1, (0x8000000 >> 16)
    /* 1BB04 80084304 25104300 */  or         $v0, $v0, $v1
    /* 1BB08 80084308 0800E003 */  jr         $ra
    /* 1BB0C 8008430C 1C00A2AC */   sw        $v0, 0x1C($a1)
endlabel func_800842F0
