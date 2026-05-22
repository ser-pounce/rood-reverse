nonmatching Sound_Cmd_C8_unk, 0x34

glabel Sound_Cmd_C8_unk
    /* 7F64 80017764 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7F68 80017768 0380023C */  lui        $v0, %hi(g_Sound_CdVolumeFadeLength)
    /* 7F6C 8001776C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7F70 80017770 4C7840A4 */  sh         $zero, %lo(g_Sound_CdVolumeFadeLength)($v0)
    /* 7F74 80017774 00008294 */  lhu        $v0, 0x0($a0)
    /* 7F78 80017778 0380033C */  lui        $v1, %hi(g_CdVolume)
    /* 7F7C 8001777C 00140200 */  sll        $v0, $v0, 16
    /* 7F80 80017780 4D64000C */  jal        UpdateCdVolume
    /* 7F84 80017784 E07862AC */   sw        $v0, %lo(g_CdVolume)($v1)
    /* 7F88 80017788 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7F8C 8001778C 00000000 */  nop
    /* 7F90 80017790 0800E003 */  jr         $ra
    /* 7F94 80017794 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_C8_unk
