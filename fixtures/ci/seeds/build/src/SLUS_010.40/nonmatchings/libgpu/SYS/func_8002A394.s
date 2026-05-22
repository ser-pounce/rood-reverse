nonmatching func_8002A394, 0x30

glabel func_8002A394
    /* 1AB94 8002A394 0010023C */  lui        $v0, (0x10000000 >> 16)
    /* 1AB98 8002A398 0380033C */  lui        $v1, %hi(D_8003354C)
    /* 1AB9C 8002A39C 4C35638C */  lw         $v1, %lo(D_8003354C)($v1)
    /* 1ABA0 8002A3A0 25208200 */  or         $a0, $a0, $v0
    /* 1ABA4 8002A3A4 000064AC */  sw         $a0, 0x0($v1)
    /* 1ABA8 8002A3A8 0380023C */  lui        $v0, %hi(D_80033548)
    /* 1ABAC 8002A3AC 4835428C */  lw         $v0, %lo(D_80033548)($v0)
    /* 1ABB0 8002A3B0 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 1ABB4 8002A3B4 0000428C */  lw         $v0, 0x0($v0)
    /* 1ABB8 8002A3B8 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 1ABBC 8002A3BC 0800E003 */  jr         $ra
    /* 1ABC0 8002A3C0 24104300 */   and       $v0, $v0, $v1
endlabel func_8002A394
