nonmatching SoundVM_FE1D_MarkVoicesKeyed, 0x20

glabel SoundVM_FE1D_MarkVoicesKeyed
    /* D4C8 8001CCC8 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* D4CC 8001CCCC 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* D4D0 8001CCD0 00000000 */  nop
    /* D4D4 8001CCD4 0800628C */  lw         $v0, 0x8($v1)
    /* D4D8 8001CCD8 00000000 */  nop
    /* D4DC 8001CCDC 25104500 */  or         $v0, $v0, $a1
    /* D4E0 8001CCE0 0800E003 */  jr         $ra
    /* D4E4 8001CCE4 080062AC */   sw        $v0, 0x8($v1)
endlabel SoundVM_FE1D_MarkVoicesKeyed
