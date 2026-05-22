nonmatching _padWaitRXready, 0x28

glabel _padWaitRXready
    /* 1D240 8002CA40 0380033C */  lui        $v1, %hi(D_80033600)
    /* 1D244 8002CA44 0036638C */  lw         $v1, %lo(D_80033600)($v1)
    /* 1D248 8002CA48 00000000 */  nop
  .L8002CA4C:
    /* 1D24C 8002CA4C 04006294 */  lhu        $v0, 0x4($v1)
    /* 1D250 8002CA50 00000000 */  nop
    /* 1D254 8002CA54 02004230 */  andi       $v0, $v0, 0x2
    /* 1D258 8002CA58 FCFF4010 */  beqz       $v0, .L8002CA4C
    /* 1D25C 8002CA5C 00000000 */   nop
    /* 1D260 8002CA60 0800E003 */  jr         $ra
    /* 1D264 8002CA64 00000000 */   nop
endlabel _padWaitRXready
    /* 1D268 8002CA68 00000000 */  nop
    /* 1D26C 8002CA6C 00000000 */  nop
    /* 1D270 8002CA70 00000000 */  nop
