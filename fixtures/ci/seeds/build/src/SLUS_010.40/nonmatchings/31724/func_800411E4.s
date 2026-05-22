nonmatching func_800411E4, 0x1C

glabel func_800411E4
    /* 319E4 800411E4 2348F800 */  subu       $t1, $a3, $t8
    /* 319E8 800411E8 0000288D */  lw         $t0, 0x0($t1)
    /* 319EC 800411EC 20003927 */  addiu      $t9, $t9, 0x20
    /* 319F0 800411F0 024C0800 */  srl        $t1, $t0, 16
    /* 319F4 800411F4 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 319F8 800411F8 08002003 */  jr         $t9
    /* 319FC 800411FC 23400800 */   negu      $t0, $t0
endlabel func_800411E4
