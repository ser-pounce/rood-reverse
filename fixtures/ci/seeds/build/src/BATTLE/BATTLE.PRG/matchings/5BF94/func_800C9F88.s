nonmatching func_800C9F88, 0x10

glabel func_800C9F88
    /* 61788 800C9F88 0F80033C */  lui        $v1, %hi(D_800EBC78)
    /* 6178C 800C9F8C 01000224 */  addiu      $v0, $zero, 0x1
    /* 61790 800C9F90 0800E003 */  jr         $ra
    /* 61794 800C9F94 78BC62A0 */   sb        $v0, %lo(D_800EBC78)($v1)
endlabel func_800C9F88
