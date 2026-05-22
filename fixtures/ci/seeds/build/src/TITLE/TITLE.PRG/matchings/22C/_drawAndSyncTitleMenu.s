nonmatching _drawAndSyncTitleMenu, 0x30

glabel _drawAndSyncTitleMenu
    /* 8258 80070A58 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 825C 80070A5C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 8260 80070A60 4FC2010C */  jal        _drawTitleMenu
    /* 8264 80070A64 00000000 */   nop
    /* 8268 80070A68 B17D000C */  jal        VSync
    /* 826C 80070A6C 21200000 */   addu      $a0, $zero, $zero
    /* 8270 80070A70 500E010C */  jal        vs_main_processPadState
    /* 8274 80070A74 00000000 */   nop
    /* 8278 80070A78 1000BF8F */  lw         $ra, 0x10($sp)
    /* 827C 80070A7C 00000000 */  nop
    /* 8280 80070A80 0800E003 */  jr         $ra
    /* 8284 80070A84 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _drawAndSyncTitleMenu
