nonmatching vs_battle_getMenuItem, 0x14

glabel vs_battle_getMenuItem
    /* 60648 800C8E48 0F80023C */  lui        $v0, %hi(vs_battle_menuItems)
    /* 6064C 800C8E4C C0B9428C */  lw         $v0, %lo(vs_battle_menuItems)($v0)
    /* 60650 800C8E50 80210400 */  sll        $a0, $a0, 6
    /* 60654 800C8E54 0800E003 */  jr         $ra
    /* 60658 800C8E58 21104400 */   addu      $v0, $v0, $a0
endlabel vs_battle_getMenuItem
