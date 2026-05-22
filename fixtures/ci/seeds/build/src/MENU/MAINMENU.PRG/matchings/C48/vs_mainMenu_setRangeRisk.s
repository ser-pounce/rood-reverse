nonmatching vs_mainMenu_setRangeRisk, 0x1C

glabel vs_mainMenu_setRangeRisk
    /* 250C 800FBD0C 1080023C */  lui        $v0, %hi(D_80102480)
    /* 2510 800FBD10 802444A0 */  sb         $a0, %lo(D_80102480)($v0)
    /* 2514 800FBD14 80244224 */  addiu      $v0, $v0, %lo(D_80102480)
    /* 2518 800FBD18 010045A0 */  sb         $a1, 0x1($v0)
    /* 251C 800FBD1C 020046A0 */  sb         $a2, 0x2($v0)
    /* 2520 800FBD20 0800E003 */  jr         $ra
    /* 2524 800FBD24 030047A0 */   sb        $a3, 0x3($v0)
endlabel vs_mainMenu_setRangeRisk
