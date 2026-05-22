nonmatching vs_battle_script_setFlagImmContext, 0x34

glabel vs_battle_script_setFlagImmContext
    /* 503C4 800B8BC4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 503C8 800B8BC8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 503CC 800B8BCC 80FF020C */  jal        vs_battle_getShort
    /* 503D0 800B8BD0 01008424 */   addiu     $a0, $a0, 0x1
    /* 503D4 800B8BD4 00140200 */  sll        $v0, $v0, 16
    /* 503D8 800B8BD8 FDFA020C */  jal        vs_battle_getStateFlag
    /* 503DC 800B8BDC 03240200 */   sra       $a0, $v0, 16
    /* 503E0 800B8BE0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 503E4 800B8BE4 0F80033C */  lui        $v1, %hi(D_800F4BB4)
    /* 503E8 800B8BE8 B44B62A0 */  sb         $v0, %lo(D_800F4BB4)($v1)
    /* 503EC 800B8BEC 21100000 */  addu       $v0, $zero, $zero
    /* 503F0 800B8BF0 0800E003 */  jr         $ra
    /* 503F4 800B8BF4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_setFlagImmContext
