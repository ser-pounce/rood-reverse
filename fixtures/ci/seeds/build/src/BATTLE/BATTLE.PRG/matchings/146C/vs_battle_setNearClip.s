nonmatching vs_battle_setNearClip, 0x24

glabel vs_battle_setNearClip
    /* 144CC 8007CCCC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 144D0 8007CCD0 0680023C */  lui        $v0, %hi(vs_main_nearClip)
    /* 144D4 8007CCD4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 144D8 8007CCD8 5860020C */  jal        func_80098160
    /* 144DC 8007CCDC C8E044AC */   sw        $a0, %lo(vs_main_nearClip)($v0)
    /* 144E0 8007CCE0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 144E4 8007CCE4 00000000 */  nop
    /* 144E8 8007CCE8 0800E003 */  jr         $ra
    /* 144EC 8007CCEC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_setNearClip
