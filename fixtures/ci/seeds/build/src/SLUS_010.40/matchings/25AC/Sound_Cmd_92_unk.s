nonmatching Sound_Cmd_92_unk, 0x14

glabel Sound_Cmd_92_unk
    /* 8FE4 800187E4 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 8FE8 800187E8 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 8FEC 800187EC 00008294 */  lhu        $v0, 0x0($a0)
    /* 8FF0 800187F0 0800E003 */  jr         $ra
    /* 8FF4 800187F4 700062A4 */   sh        $v0, 0x70($v1)
endlabel Sound_Cmd_92_unk
