nonmatching func_800B6744, 0x34

glabel func_800B6744
    /* 4DF44 800B6744 0F80033C */  lui        $v1, %hi(D_800F4C2C)
    /* 4DF48 800B6748 01000224 */  addiu      $v0, $zero, 0x1
    /* 4DF4C 800B674C 2C4C62A0 */  sb         $v0, %lo(D_800F4C2C)($v1)
    /* 4DF50 800B6750 01008390 */  lbu        $v1, 0x1($a0)
    /* 4DF54 800B6754 0F80043C */  lui        $a0, %hi(D_800F4C20)
    /* 4DF58 800B6758 0F80023C */  lui        $v0, %hi(D_800F4C68)
    /* 4DF5C 800B675C 684C4290 */  lbu        $v0, %lo(D_800F4C68)($v0)
    /* 4DF60 800B6760 01006338 */  xori       $v1, $v1, 0x1
    /* 4DF64 800B6764 01006330 */  andi       $v1, $v1, 0x1
    /* 4DF68 800B6768 2B100200 */  sltu       $v0, $zero, $v0
    /* 4DF6C 800B676C 80100200 */  sll        $v0, $v0, 2
    /* 4DF70 800B6770 0800E003 */  jr         $ra
    /* 4DF74 800B6774 204C83A0 */   sb        $v1, %lo(D_800F4C20)($a0)
endlabel func_800B6744
