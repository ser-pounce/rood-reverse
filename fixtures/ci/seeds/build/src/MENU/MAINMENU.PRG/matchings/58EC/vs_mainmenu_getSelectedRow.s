nonmatching vs_mainmenu_getSelectedRow, 0x28

glabel vs_mainmenu_getSelectedRow
    /* 70C8 801008C8 1080023C */  lui        $v0, %hi(D_801023D4)
    /* 70CC 801008CC D423428C */  lw         $v0, %lo(D_801023D4)($v0)
    /* 70D0 801008D0 00000000 */  nop
    /* 70D4 801008D4 04004014 */  bnez       $v0, .L801008E8
    /* 70D8 801008D8 1080023C */   lui       $v0, %hi(_selectedRow)
    /* 70DC 801008DC D823428C */  lw         $v0, %lo(_selectedRow)($v0)
    /* 70E0 801008E0 0800E003 */  jr         $ra
    /* 70E4 801008E4 00000000 */   nop
  .L801008E8:
    /* 70E8 801008E8 0800E003 */  jr         $ra
    /* 70EC 801008EC FFFF0224 */   addiu     $v0, $zero, -0x1
endlabel vs_mainmenu_getSelectedRow
