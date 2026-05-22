nonmatching DS_shell_open, 0x10

glabel DS_shell_open
    /* 151B4 800249B4 0380023C */  lui        $v0, %hi(D_800326B8)
    /* 151B8 800249B8 B826428C */  lw         $v0, %lo(D_800326B8)($v0)
    /* 151BC 800249BC 0800E003 */  jr         $ra
    /* 151C0 800249C0 00000000 */   nop
endlabel DS_shell_open
