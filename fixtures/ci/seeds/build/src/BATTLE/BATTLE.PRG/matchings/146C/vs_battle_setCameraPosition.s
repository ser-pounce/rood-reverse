nonmatching vs_battle_setCameraPosition, 0x28

glabel vs_battle_setCameraPosition
    /* 12418 8007AC18 801F033C */  lui        $v1, %hi(D_1F800000)
    /* 1241C 8007AC1C 0000828C */  lw         $v0, 0x0($a0)
    /* 12420 8007AC20 00006324 */  addiu      $v1, $v1, %lo(D_1F800000)
    /* 12424 8007AC24 340062AC */  sw         $v0, 0x34($v1)
    /* 12428 8007AC28 0400828C */  lw         $v0, 0x4($a0)
    /* 1242C 8007AC2C 00000000 */  nop
    /* 12430 8007AC30 380062AC */  sw         $v0, 0x38($v1)
    /* 12434 8007AC34 0800828C */  lw         $v0, 0x8($a0)
    /* 12438 8007AC38 0800E003 */  jr         $ra
    /* 1243C 8007AC3C 3C0062AC */   sw        $v0, 0x3C($v1)
endlabel vs_battle_setCameraPosition
