nonmatching TermPrim, 0x18

glabel TermPrim
    /* 1BD54 8002B554 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 1BD58 8002B558 0000828C */  lw         $v0, 0x0($a0)
    /* 1BD5C 8002B55C FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 1BD60 8002B560 25104300 */  or         $v0, $v0, $v1
    /* 1BD64 8002B564 0800E003 */  jr         $ra
    /* 1BD68 8002B568 000082AC */   sw        $v0, 0x0($a0)
endlabel TermPrim
    /* 1BD6C 8002B56C 00000000 */  nop
    /* 1BD70 8002B570 00000000 */  nop
