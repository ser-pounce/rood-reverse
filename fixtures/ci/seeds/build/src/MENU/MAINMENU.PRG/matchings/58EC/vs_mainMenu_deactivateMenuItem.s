nonmatching vs_mainMenu_deactivateMenuItem, 0x18

glabel vs_mainMenu_deactivateMenuItem
    /* 6390 800FFB90 0F80023C */  lui        $v0, %hi(vs_battle_menuItems)
    /* 6394 800FFB94 C0B9428C */  lw         $v0, %lo(vs_battle_menuItems)($v0)
    /* 6398 800FFB98 80210400 */  sll        $a0, $a0, 6
    /* 639C 800FFB9C 21104400 */  addu       $v0, $v0, $a0
    /* 63A0 800FFBA0 0800E003 */  jr         $ra
    /* 63A4 800FFBA4 000040A0 */   sb        $zero, 0x0($v0)
endlabel vs_mainMenu_deactivateMenuItem
