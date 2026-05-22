nonmatching DS_system_status, 0x18

glabel DS_system_status
    /* 150F8 800248F8 80200400 */  sll        $a0, $a0, 2
    /* 150FC 800248FC 0380023C */  lui        $v0, %hi(D_8003269C)
    /* 15100 80024900 21104400 */  addu       $v0, $v0, $a0
    /* 15104 80024904 9C26428C */  lw         $v0, %lo(D_8003269C)($v0)
    /* 15108 80024908 0800E003 */  jr         $ra
    /* 1510C 8002490C 00000000 */   nop
endlabel DS_system_status
