nonmatching vs_battle_getCurrentRoomId, 0x30

glabel vs_battle_getCurrentRoomId
    /* 14074 8007C874 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14078 8007C878 0F80023C */  lui        $v0, %hi(_zoneContext)
    /* 1407C 8007C87C 8018448C */  lw         $a0, %lo(_zoneContext)($v0)
    /* 14080 8007C880 80184324 */  addiu      $v1, $v0, %lo(_zoneContext)
    /* 14084 8007C884 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14088 8007C888 3400658C */  lw         $a1, 0x34($v1)
    /* 1408C 8007C88C 07F2010C */  jal        _getLocationId
    /* 14090 8007C890 00000000 */   nop
    /* 14094 8007C894 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14098 8007C898 00000000 */  nop
    /* 1409C 8007C89C 0800E003 */  jr         $ra
    /* 140A0 8007C8A0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_getCurrentRoomId
