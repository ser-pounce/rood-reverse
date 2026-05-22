nonmatching func_800B71F4, 0x24

glabel func_800B71F4
    /* 4E9F4 800B71F4 0F80023C */  lui        $v0, %hi(D_800F4B30)
    /* 4E9F8 800B71F8 304B4224 */  addiu      $v0, $v0, %lo(D_800F4B30)
    /* 4E9FC 800B71FC 03004390 */  lbu        $v1, 0x3($v0)
    /* 4EA00 800B7200 17004490 */  lbu        $a0, 0x17($v0)
    /* 4EA04 800B7204 2B004290 */  lbu        $v0, 0x2B($v0)
    /* 4EA08 800B7208 25186400 */  or         $v1, $v1, $a0
    /* 4EA0C 800B720C 25104300 */  or         $v0, $v0, $v1
    /* 4EA10 800B7210 0800E003 */  jr         $ra
    /* 4EA14 800B7214 2B100200 */   sltu      $v0, $zero, $v0
endlabel func_800B71F4
