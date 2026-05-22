nonmatching vs_battle_getCameraPosition, 0x2C

glabel vs_battle_getCameraPosition
    /* 123EC 8007ABEC 801F023C */  lui        $v0, %hi(D_1F800000)
    /* 123F0 8007ABF0 00004224 */  addiu      $v0, $v0, %lo(D_1F800000)
    /* 123F4 8007ABF4 3400438C */  lw         $v1, 0x34($v0)
    /* 123F8 8007ABF8 00000000 */  nop
    /* 123FC 8007ABFC 000083AC */  sw         $v1, 0x0($a0)
    /* 12400 8007AC00 3800438C */  lw         $v1, 0x38($v0)
    /* 12404 8007AC04 00000000 */  nop
    /* 12408 8007AC08 040083AC */  sw         $v1, 0x4($a0)
    /* 1240C 8007AC0C 3C00428C */  lw         $v0, 0x3C($v0)
    /* 12410 8007AC10 0800E003 */  jr         $ra
    /* 12414 8007AC14 080082AC */   sw        $v0, 0x8($a0)
endlabel vs_battle_getCameraPosition
