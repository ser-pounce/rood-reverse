nonmatching func_800BEC30, 0x28

glabel func_800BEC30
    /* 56430 800BEC30 0F80023C */  lui        $v0, %hi(D_800F4C34)
    /* 56434 800BEC34 344C4390 */  lbu        $v1, %lo(D_800F4C34)($v0)
    /* 56438 800BEC38 01000224 */  addiu      $v0, $zero, 0x1
    /* 5643C 800BEC3C 04006214 */  bne        $v1, $v0, .L800BEC50
    /* 56440 800BEC40 00000000 */   nop
    /* 56444 800BEC44 0F80023C */  lui        $v0, %hi(D_800F4BB8)
    /* 56448 800BEC48 B84B43A0 */  sb         $v1, %lo(D_800F4BB8)($v0)
    /* 5644C 800BEC4C 01000224 */  addiu      $v0, $zero, 0x1
  .L800BEC50:
    /* 56450 800BEC50 0800E003 */  jr         $ra
    /* 56454 800BEC54 00000000 */   nop
endlabel func_800BEC30
