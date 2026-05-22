nonmatching vs_mainMenu_getSelectedItemAction, 0x28

glabel vs_mainMenu_getSelectedItemAction
    /* 5B60 800FF360 1080023C */  lui        $v0, %hi(D_801022C8)
    /* 5B64 800FF364 C822428C */  lw         $v0, %lo(D_801022C8)($v0)
    /* 5B68 800FF368 00000000 */  nop
    /* 5B6C 800FF36C 04004014 */  bnez       $v0, .L800FF380
    /* 5B70 800FF370 1080023C */   lui       $v0, %hi(D_801022CC)
    /* 5B74 800FF374 CC22428C */  lw         $v0, %lo(D_801022CC)($v0)
    /* 5B78 800FF378 0800E003 */  jr         $ra
    /* 5B7C 800FF37C 00000000 */   nop
  .L800FF380:
    /* 5B80 800FF380 0800E003 */  jr         $ra
    /* 5B84 800FF384 FFFF0224 */   addiu     $v0, $zero, -0x1
endlabel vs_mainMenu_getSelectedItemAction
