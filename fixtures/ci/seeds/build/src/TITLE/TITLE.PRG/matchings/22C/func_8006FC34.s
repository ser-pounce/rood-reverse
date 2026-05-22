nonmatching func_8006FC34, 0x38

glabel func_8006FC34
    /* 7434 8006FC34 0F80023C */  lui        $v0, %hi(_menuItemStates)
    /* 7438 8006FC38 F8FD4224 */  addiu      $v0, $v0, %lo(_menuItemStates)
    /* 743C 8006FC3C C0200400 */  sll        $a0, $a0, 3
    /* 7440 8006FC40 21208200 */  addu       $a0, $a0, $v0
    /* 7444 8006FC44 01000224 */  addiu      $v0, $zero, 0x1
    /* 7448 8006FC48 000082A0 */  sb         $v0, 0x0($a0)
    /* 744C 8006FC4C 010080A0 */  sb         $zero, 0x1($a0)
    /* 7450 8006FC50 020080A0 */  sb         $zero, 0x2($a0)
    /* 7454 8006FC54 030080A0 */  sb         $zero, 0x3($a0)
    /* 7458 8006FC58 040085A0 */  sb         $a1, 0x4($a0)
    /* 745C 8006FC5C 050085A0 */  sb         $a1, 0x5($a0)
    /* 7460 8006FC60 060085A0 */  sb         $a1, 0x6($a0)
    /* 7464 8006FC64 0800E003 */  jr         $ra
    /* 7468 8006FC68 070080A0 */   sb        $zero, 0x7($a0)
endlabel func_8006FC34
