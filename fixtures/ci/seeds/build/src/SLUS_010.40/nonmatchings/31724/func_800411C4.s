nonmatching func_800411C4, 0x1C

glabel func_800411C4
    /* 319C4 800411C4 2148D800 */  addu       $t1, $a2, $t8
    /* 319C8 800411C8 0000288D */  lw         $t0, 0x0($t1)
    /* 319CC 800411CC 20003927 */  addiu      $t9, $t9, 0x20
    /* 319D0 800411D0 FFFF0931 */  andi       $t1, $t0, 0xFFFF
    /* 319D4 800411D4 02440800 */  srl        $t0, $t0, 16
    /* 319D8 800411D8 08002003 */  jr         $t9
    /* 319DC 800411DC 23400800 */   negu      $t0, $t0
endlabel func_800411C4
    /* 319E0 800411E0 00000000 */  nop
