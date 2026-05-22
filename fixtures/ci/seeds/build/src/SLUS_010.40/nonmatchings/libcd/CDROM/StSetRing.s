nonmatching StSetRing, 0x2C

glabel StSetRing
    /* 10B84 80020384 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10B88 80020388 1000BFAF */  sw         $ra, 0x10($sp)
    /* 10B8C 8002038C 0480013C */  lui        $at, %hi(D_80039C48)
    /* 10B90 80020390 489C24AC */  sw         $a0, %lo(D_80039C48)($at)
    /* 10B94 80020394 0480013C */  lui        $at, %hi(D_80039C4C)
    /* 10B98 80020398 4D88000C */  jal        StClearRing
    /* 10B9C 8002039C 4C9C25AC */   sw        $a1, %lo(D_80039C4C)($at)
    /* 10BA0 800203A0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 10BA4 800203A4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 10BA8 800203A8 0800E003 */  jr         $ra
    /* 10BAC 800203AC 00000000 */   nop
endlabel StSetRing
    /* 10BB0 800203B0 00000000 */  nop
