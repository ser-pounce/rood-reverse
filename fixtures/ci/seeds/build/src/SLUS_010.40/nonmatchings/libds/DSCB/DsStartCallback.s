nonmatching DsStartCallback, 0x14

glabel DsStartCallback
    /* 1702C 8002682C 0480033C */  lui        $v1, %hi(D_80039E68)
    /* 17030 80026830 689E6324 */  addiu      $v1, $v1, %lo(D_80039E68)
    /* 17034 80026834 0000628C */  lw         $v0, 0x0($v1)
    /* 17038 80026838 0800E003 */  jr         $ra
    /* 1703C 8002683C 000064AC */   sw        $a0, 0x0($v1)
endlabel DsStartCallback
