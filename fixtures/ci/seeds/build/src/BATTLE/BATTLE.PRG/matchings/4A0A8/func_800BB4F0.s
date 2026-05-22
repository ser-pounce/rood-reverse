nonmatching func_800BB4F0, 0x14

glabel func_800BB4F0
    /* 52CF0 800BB4F0 01008390 */  lbu        $v1, 0x1($a0)
    /* 52CF4 800BB4F4 0F80023C */  lui        $v0, %hi(D_800F4BE4)
    /* 52CF8 800BB4F8 E44B43A0 */  sb         $v1, %lo(D_800F4BE4)($v0)
    /* 52CFC 800BB4FC 0800E003 */  jr         $ra
    /* 52D00 800BB500 21100000 */   addu      $v0, $zero, $zero
endlabel func_800BB4F0
