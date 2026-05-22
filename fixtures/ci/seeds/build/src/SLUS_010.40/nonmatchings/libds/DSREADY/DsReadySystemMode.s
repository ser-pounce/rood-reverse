nonmatching DsReadySystemMode, 0x14

glabel DsReadySystemMode
    /* 16B4C 8002634C 0380033C */  lui        $v1, %hi(D_80032820)
    /* 16B50 80026350 20286324 */  addiu      $v1, $v1, %lo(D_80032820)
    /* 16B54 80026354 0000628C */  lw         $v0, 0x0($v1)
    /* 16B58 80026358 0800E003 */  jr         $ra
    /* 16B5C 8002635C 000064AC */   sw        $a0, 0x0($v1)
endlabel DsReadySystemMode
