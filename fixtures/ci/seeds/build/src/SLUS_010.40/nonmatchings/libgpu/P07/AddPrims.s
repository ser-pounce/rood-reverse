nonmatching AddPrims, 0x3C

glabel AddPrims
    /* 1BD14 8002B514 FF00073C */  lui        $a3, (0xFFFFFF >> 16)
    /* 1BD18 8002B518 FFFFE734 */  ori        $a3, $a3, (0xFFFFFF & 0xFFFF)
    /* 1BD1C 8002B51C 00FF083C */  lui        $t0, (0xFF000000 >> 16)
    /* 1BD20 8002B520 0000C38C */  lw         $v1, 0x0($a2)
    /* 1BD24 8002B524 0000828C */  lw         $v0, 0x0($a0)
    /* 1BD28 8002B528 24186800 */  and        $v1, $v1, $t0
    /* 1BD2C 8002B52C 24104700 */  and        $v0, $v0, $a3
    /* 1BD30 8002B530 25186200 */  or         $v1, $v1, $v0
    /* 1BD34 8002B534 0000C3AC */  sw         $v1, 0x0($a2)
    /* 1BD38 8002B538 0000828C */  lw         $v0, 0x0($a0)
    /* 1BD3C 8002B53C 2428A700 */  and        $a1, $a1, $a3
    /* 1BD40 8002B540 24104800 */  and        $v0, $v0, $t0
    /* 1BD44 8002B544 25104500 */  or         $v0, $v0, $a1
    /* 1BD48 8002B548 0800E003 */  jr         $ra
    /* 1BD4C 8002B54C 000082AC */   sw        $v0, 0x0($a0)
endlabel AddPrims
    /* 1BD50 8002B550 00000000 */  nop
