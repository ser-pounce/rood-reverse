nonmatching DsShellOpen, 0x20

glabel DsShellOpen
    /* 14CAC 800244AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 14CB0 800244B0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 14CB4 800244B4 6D92000C */  jal        DS_shell_open
    /* 14CB8 800244B8 00000000 */   nop
    /* 14CBC 800244BC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14CC0 800244C0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 14CC4 800244C4 0800E003 */  jr         $ra
    /* 14CC8 800244C8 00000000 */   nop
endlabel DsShellOpen
