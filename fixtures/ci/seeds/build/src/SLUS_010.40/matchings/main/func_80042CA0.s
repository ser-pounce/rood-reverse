nonmatching func_80042CA0, 0x10

glabel func_80042CA0
    /* 334A0 80042CA0 0680033C */  lui        $v1, %hi(D_80060068)
    /* 334A4 80042CA4 01000224 */  addiu      $v0, $zero, 0x1
    /* 334A8 80042CA8 0800E003 */  jr         $ra
    /* 334AC 80042CAC 680062AC */   sw        $v0, %lo(D_80060068)($v1)
endlabel func_80042CA0
