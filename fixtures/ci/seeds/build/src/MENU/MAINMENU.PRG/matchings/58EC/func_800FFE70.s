nonmatching func_800FFE70, 0x28

glabel func_800FFE70
    /* 6670 800FFE70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6674 800FFE74 2138C000 */  addu       $a3, $a2, $zero
    /* 6678 800FFE78 8000063C */  lui        $a2, (0x808080 >> 16)
    /* 667C 800FFE7C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6680 800FFE80 59FF030C */  jal        vs_mainMenu_renderIntColor
    /* 6684 800FFE84 8080C634 */   ori       $a2, $a2, (0x808080 & 0xFFFF)
    /* 6688 800FFE88 1000BF8F */  lw         $ra, 0x10($sp)
    /* 668C 800FFE8C 00000000 */  nop
    /* 6690 800FFE90 0800E003 */  jr         $ra
    /* 6694 800FFE94 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800FFE70
