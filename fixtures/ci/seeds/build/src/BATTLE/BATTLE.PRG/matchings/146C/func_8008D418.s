nonmatching func_8008D418, 0x20

glabel func_8008D418
    /* 24C18 8008D418 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x8C)
    /* 24C1C 8008D41C 841C438C */  lw         $v1, %lo(vs_battle_roomData + 0x8C)($v0)
    /* 24C20 8008D420 00000000 */  nop
    /* 24C24 8008D424 52006284 */  lh         $v0, 0x52($v1)
    /* 24C28 8008D428 54006384 */  lh         $v1, 0x54($v1)
    /* 24C2C 8008D42C 00140200 */  sll        $v0, $v0, 16
    /* 24C30 8008D430 0800E003 */  jr         $ra
    /* 24C34 8008D434 25104300 */   or        $v0, $v0, $v1
endlabel func_8008D418
