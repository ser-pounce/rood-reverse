nonmatching DS_lastpos, 0xC

glabel DS_lastpos
    /* 15130 80024930 0380023C */  lui        $v0, %hi(D_800326AA)
    /* 15134 80024934 0800E003 */  jr         $ra
    /* 15138 80024938 AA264224 */   addiu     $v0, $v0, %lo(D_800326AA)
endlabel DS_lastpos
