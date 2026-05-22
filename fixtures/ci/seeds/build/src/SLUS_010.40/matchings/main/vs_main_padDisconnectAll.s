nonmatching vs_main_padDisconnectAll, 0x14

glabel vs_main_padDisconnectAll
    /* 337DC 80042FDC 0580023C */  lui        $v0, %hi(_portInfo)
    /* 337E0 80042FE0 90014224 */  addiu      $v0, $v0, %lo(_portInfo)
    /* 337E4 80042FE4 0A0040A0 */  sb         $zero, 0xA($v0)
    /* 337E8 80042FE8 0800E003 */  jr         $ra
    /* 337EC 80042FEC 150040A0 */   sb        $zero, 0x15($v0)
endlabel vs_main_padDisconnectAll
