nonmatching func_800B6F8C, 0x24

glabel func_800B6F8C
    /* 4E78C 800B6F8C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4E790 800B6F90 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4E794 800B6F94 01008490 */  lbu        $a0, 0x1($a0)
    /* 4E798 800B6F98 1934030C */  jal        vs_battle_dismissTextBox
    /* 4E79C 800B6F9C 00000000 */   nop
    /* 4E7A0 800B6FA0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4E7A4 800B6FA4 2B100200 */  sltu       $v0, $zero, $v0
    /* 4E7A8 800B6FA8 0800E003 */  jr         $ra
    /* 4E7AC 800B6FAC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B6F8C
