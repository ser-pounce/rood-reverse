nonmatching DsReadyCallback, 0x14

glabel DsReadyCallback
    /* 17018 80026818 0480033C */  lui        $v1, %hi(D_80039E64)
    /* 1701C 8002681C 649E6324 */  addiu      $v1, $v1, %lo(D_80039E64)
    /* 17020 80026820 0000628C */  lw         $v0, 0x0($v1)
    /* 17024 80026824 0800E003 */  jr         $ra
    /* 17028 80026828 000064AC */   sw        $a0, 0x0($v1)
endlabel DsReadyCallback
