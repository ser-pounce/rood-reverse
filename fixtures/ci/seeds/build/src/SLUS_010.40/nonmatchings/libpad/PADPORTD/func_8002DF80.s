nonmatching func_8002DF80, 0x10

glabel func_8002DF80
    /* 1E780 8002DF80 37008290 */  lbu        $v0, 0x37($a0)
    /* 1E784 8002DF84 370080A0 */  sb         $zero, 0x37($a0)
    /* 1E788 8002DF88 0800E003 */  jr         $ra
    /* 1E78C 8002DF8C 380082A0 */   sb        $v0, 0x38($a0)
endlabel func_8002DF80
