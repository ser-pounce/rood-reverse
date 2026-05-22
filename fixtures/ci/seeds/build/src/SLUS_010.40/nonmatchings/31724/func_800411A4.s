nonmatching func_800411A4, 0x20

glabel func_800411A4
    /* 319A4 800411A4 2348F800 */  subu       $t1, $a3, $t8
    /* 319A8 800411A8 0000288D */  lw         $t0, 0x0($t1)
    /* 319AC 800411AC 20003927 */  addiu      $t9, $t9, 0x20
    /* 319B0 800411B0 FFFF0931 */  andi       $t1, $t0, 0xFFFF
    /* 319B4 800411B4 23480900 */  negu       $t1, $t1
    /* 319B8 800411B8 02440800 */  srl        $t0, $t0, 16
    /* 319BC 800411BC 08002003 */  jr         $t9
    /* 319C0 800411C0 23400800 */   negu      $t0, $t0
endlabel func_800411A4
