nonmatching func_80084370, 0x20

glabel func_80084370
    /* 1BB70 80084370 FFF3033C */  lui        $v1, (0xF3FFFFFF >> 16)
    /* 1BB74 80084374 1C00A28C */  lw         $v0, 0x1C($a1)
    /* 1BB78 80084378 FFFF6334 */  ori        $v1, $v1, (0xF3FFFFFF & 0xFFFF)
    /* 1BB7C 8008437C 24104300 */  and        $v0, $v0, $v1
    /* 1BB80 80084380 0008033C */  lui        $v1, (0x8000000 >> 16)
    /* 1BB84 80084384 25104300 */  or         $v0, $v0, $v1
    /* 1BB88 80084388 0800E003 */  jr         $ra
    /* 1BB8C 8008438C 1C00A2AC */   sw        $v0, 0x1C($a1)
endlabel func_80084370
