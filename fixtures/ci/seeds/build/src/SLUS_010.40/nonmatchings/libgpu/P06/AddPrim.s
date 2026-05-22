nonmatching AddPrim, 0x3C

glabel AddPrim
    /* 1BCD4 8002B4D4 FF00063C */  lui        $a2, (0xFFFFFF >> 16)
    /* 1BCD8 8002B4D8 FFFFC634 */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* 1BCDC 8002B4DC 00FF073C */  lui        $a3, (0xFF000000 >> 16)
    /* 1BCE0 8002B4E0 0000A38C */  lw         $v1, 0x0($a1)
    /* 1BCE4 8002B4E4 0000828C */  lw         $v0, 0x0($a0)
    /* 1BCE8 8002B4E8 24186700 */  and        $v1, $v1, $a3
    /* 1BCEC 8002B4EC 24104600 */  and        $v0, $v0, $a2
    /* 1BCF0 8002B4F0 25186200 */  or         $v1, $v1, $v0
    /* 1BCF4 8002B4F4 0000A3AC */  sw         $v1, 0x0($a1)
    /* 1BCF8 8002B4F8 0000828C */  lw         $v0, 0x0($a0)
    /* 1BCFC 8002B4FC 2428A600 */  and        $a1, $a1, $a2
    /* 1BD00 8002B500 24104700 */  and        $v0, $v0, $a3
    /* 1BD04 8002B504 25104500 */  or         $v0, $v0, $a1
    /* 1BD08 8002B508 0800E003 */  jr         $ra
    /* 1BD0C 8002B50C 000082AC */   sw        $v0, 0x0($a0)
endlabel AddPrim
    /* 1BD10 8002B510 00000000 */  nop
