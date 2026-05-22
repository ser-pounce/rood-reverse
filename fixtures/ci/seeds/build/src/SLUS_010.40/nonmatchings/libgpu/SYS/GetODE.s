nonmatching GetODE, 0x30

glabel GetODE
    /* 19BAC 800293AC 0380023C */  lui        $v0, %hi(D_8003343C)
    /* 19BB0 800293B0 3C34428C */  lw         $v0, %lo(D_8003343C)($v0)
    /* 19BB4 800293B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 19BB8 800293B8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 19BBC 800293BC 3800428C */  lw         $v0, 0x38($v0)
    /* 19BC0 800293C0 00000000 */  nop
    /* 19BC4 800293C4 09F84000 */  jalr       $v0
    /* 19BC8 800293C8 00000000 */   nop
    /* 19BCC 800293CC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 19BD0 800293D0 C2170200 */  srl        $v0, $v0, 31
    /* 19BD4 800293D4 0800E003 */  jr         $ra
    /* 19BD8 800293D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel GetODE
