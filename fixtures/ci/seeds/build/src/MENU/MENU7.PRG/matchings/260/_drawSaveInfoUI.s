nonmatching _drawSaveInfoUI, 0x44

glabel _drawSaveInfoUI
    /* 1F64 80104764 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1F68 80104768 1180023C */  lui        $v0, %hi(_saveInfoUVClut)
    /* 1F6C 8010476C E4A24224 */  addiu      $v0, $v0, %lo(_saveInfoUVClut)
    /* 1F70 80104770 80300500 */  sll        $a2, $a1, 2
    /* 1F74 80104774 2110C200 */  addu       $v0, $a2, $v0
    /* 1F78 80104778 1180033C */  lui        $v1, %hi(_saveInfoWh)
    /* 1F7C 8010477C 0CA36324 */  addiu      $v1, $v1, %lo(_saveInfoWh)
    /* 1F80 80104780 2130C300 */  addu       $a2, $a2, $v1
    /* 1F84 80104784 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1F88 80104788 0000458C */  lw         $a1, 0x0($v0)
    /* 1F8C 8010478C 0000C68C */  lw         $a2, 0x0($a2)
    /* 1F90 80104790 B011040C */  jal        _drawSprt
    /* 1F94 80104794 0C000724 */   addiu     $a3, $zero, 0xC
    /* 1F98 80104798 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1F9C 8010479C 00000000 */  nop
    /* 1FA0 801047A0 0800E003 */  jr         $ra
    /* 1FA4 801047A4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _drawSaveInfoUI
