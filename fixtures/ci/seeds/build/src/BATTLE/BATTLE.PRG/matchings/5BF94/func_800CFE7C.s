nonmatching func_800CFE7C, 0x1C

glabel func_800CFE7C
    /* 6767C 800CFE7C 00100224 */  addiu      $v0, $zero, 0x1000
    /* 67680 800CFE80 100082AC */  sw         $v0, 0x10($a0)
    /* 67684 800CFE84 080082AC */  sw         $v0, 0x8($a0)
    /* 67688 800CFE88 000082AC */  sw         $v0, 0x0($a0)
    /* 6768C 800CFE8C 0C0080AC */  sw         $zero, 0xC($a0)
    /* 67690 800CFE90 0800E003 */  jr         $ra
    /* 67694 800CFE94 040080AC */   sw        $zero, 0x4($a0)
endlabel func_800CFE7C
