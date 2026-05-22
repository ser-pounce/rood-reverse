nonmatching SoundVM_FE1E_ClearVoicesKeyed, 0x20

glabel SoundVM_FE1E_ClearVoicesKeyed
    /* D4E8 8001CCE8 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* D4EC 8001CCEC 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* D4F0 8001CCF0 00000000 */  nop
    /* D4F4 8001CCF4 0800628C */  lw         $v0, 0x8($v1)
    /* D4F8 8001CCF8 27280500 */  nor        $a1, $zero, $a1
    /* D4FC 8001CCFC 24104500 */  and        $v0, $v0, $a1
    /* D500 8001CD00 0800E003 */  jr         $ra
    /* D504 8001CD04 080062AC */   sw        $v0, 0x8($v1)
endlabel SoundVM_FE1E_ClearVoicesKeyed
