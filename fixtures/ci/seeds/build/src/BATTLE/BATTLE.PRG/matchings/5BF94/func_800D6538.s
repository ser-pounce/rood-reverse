nonmatching func_800D6538, 0x1C

glabel func_800D6538
    /* 6DD38 800D6538 4C0D838C */  lw         $v1, 0xD4C($a0)
    /* 6DD3C 800D653C 00000000 */  nop
    /* 6DD40 800D6540 01006290 */  lbu        $v0, 0x1($v1)
    /* 6DD44 800D6544 00000000 */  nop
    /* 6DD48 800D6548 01004234 */  ori        $v0, $v0, 0x1
    /* 6DD4C 800D654C 0800E003 */  jr         $ra
    /* 6DD50 800D6550 010062A0 */   sb        $v0, 0x1($v1)
endlabel func_800D6538
