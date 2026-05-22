nonmatching DsReadMode, 0x1C

glabel DsReadMode
    /* 16944 80026144 0200822C */  sltiu      $v0, $a0, 0x2
    /* 16948 80026148 03004010 */  beqz       $v0, .L80026158
    /* 1694C 8002614C 00000000 */   nop
    /* 16950 80026150 0380013C */  lui        $at, %hi(D_800327E0)
    /* 16954 80026154 E02724AC */  sw         $a0, %lo(D_800327E0)($at)
  .L80026158:
    /* 16958 80026158 0800E003 */  jr         $ra
    /* 1695C 8002615C 00000000 */   nop
endlabel DsReadMode
    /* 16960 80026160 00000000 */  nop
