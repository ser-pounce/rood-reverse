nonmatching func_8008B28C, 0x34

glabel func_8008B28C
    /* 22A8C 8008B28C 0F80023C */  lui        $v0, %hi(D_800F1BA4)
    /* 22A90 8008B290 A41B4294 */  lhu        $v0, %lo(D_800F1BA4)($v0)
    /* 22A94 8008B294 00000000 */  nop
    /* 22A98 8008B298 07004014 */  bnez       $v0, .L8008B2B8
    /* 22A9C 8008B29C 0F80043C */   lui       $a0, %hi(D_800F1CDC)
    /* 22AA0 8008B2A0 0680033C */  lui        $v1, %hi(vs_gametime_tickspeed)
    /* 22AA4 8008B2A4 DC1C8294 */  lhu        $v0, %lo(D_800F1CDC)($a0)
    /* 22AA8 8008B2A8 4CE26394 */  lhu        $v1, %lo(vs_gametime_tickspeed)($v1)
    /* 22AAC 8008B2AC 00000000 */  nop
    /* 22AB0 8008B2B0 21104300 */  addu       $v0, $v0, $v1
    /* 22AB4 8008B2B4 DC1C82A4 */  sh         $v0, %lo(D_800F1CDC)($a0)
  .L8008B2B8:
    /* 22AB8 8008B2B8 0800E003 */  jr         $ra
    /* 22ABC 8008B2BC 00000000 */   nop
endlabel func_8008B28C
