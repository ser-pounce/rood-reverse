nonmatching func_800BE3A0, 0x30

glabel func_800BE3A0
    /* 55BA0 800BE3A0 0F80043C */  lui        $a0, %hi(D_800F4BA4)
    /* 55BA4 800BE3A4 A44B838C */  lw         $v1, %lo(D_800F4BA4)($a0)
    /* 55BA8 800BE3A8 0F000224 */  addiu      $v0, $zero, 0xF
    /* 55BAC 800BE3AC B40062A0 */  sb         $v0, 0xB4($v1)
    /* 55BB0 800BE3B0 000062A0 */  sb         $v0, 0x0($v1)
    /* 55BB4 800BE3B4 A44B828C */  lw         $v0, %lo(D_800F4BA4)($a0)
    /* 55BB8 800BE3B8 00000000 */  nop
    /* 55BBC 800BE3BC BB0040A0 */  sb         $zero, 0xBB($v0)
    /* 55BC0 800BE3C0 BA0040A0 */  sb         $zero, 0xBA($v0)
    /* 55BC4 800BE3C4 070040A0 */  sb         $zero, 0x7($v0)
    /* 55BC8 800BE3C8 0800E003 */  jr         $ra
    /* 55BCC 800BE3CC 060040A0 */   sb        $zero, 0x6($v0)
endlabel func_800BE3A0
