nonmatching func_800B97E4, 0x14

glabel func_800B97E4
    /* 50FE4 800B97E4 01008390 */  lbu        $v1, 0x1($a0)
    /* 50FE8 800B97E8 0F80023C */  lui        $v0, %hi(D_800F19C8)
    /* 50FEC 800B97EC C81943AC */  sw         $v1, %lo(D_800F19C8)($v0)
    /* 50FF0 800B97F0 0800E003 */  jr         $ra
    /* 50FF4 800B97F4 21100000 */   addu      $v0, $zero, $zero
endlabel func_800B97E4
