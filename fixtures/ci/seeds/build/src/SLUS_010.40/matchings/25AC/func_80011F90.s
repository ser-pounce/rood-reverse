nonmatching func_80011F90, 0x24

glabel func_80011F90
    /* 2790 80011F90 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 2794 80011F94 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 2798 80011F98 00000000 */  nop
    /* 279C 80011F9C 7C006294 */  lhu        $v0, 0x7C($v1)
    /* 27A0 80011FA0 76006394 */  lhu        $v1, 0x76($v1)
    /* 27A4 80011FA4 00140200 */  sll        $v0, $v0, 16
    /* 27A8 80011FA8 01006324 */  addiu      $v1, $v1, 0x1
    /* 27AC 80011FAC 0800E003 */  jr         $ra
    /* 27B0 80011FB0 25104300 */   or        $v0, $v0, $v1
endlabel func_80011F90
