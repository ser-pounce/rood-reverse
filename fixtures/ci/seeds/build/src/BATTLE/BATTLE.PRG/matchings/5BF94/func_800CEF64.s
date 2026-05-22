nonmatching func_800CEF64, 0x10

glabel func_800CEF64
    /* 66764 800CEF64 0F80023C */  lui        $v0, %hi(D_800F54A8)
    /* 66768 800CEF68 A8544290 */  lbu        $v0, %lo(D_800F54A8)($v0)
    /* 6676C 800CEF6C 0800E003 */  jr         $ra
    /* 66770 800CEF70 2B100200 */   sltu      $v0, $zero, $v0
endlabel func_800CEF64
