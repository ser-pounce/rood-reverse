nonmatching vs_battle_script_dismissTextBox, 0x24

glabel vs_battle_script_dismissTextBox
    /* 4E374 800B6B74 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4E378 800B6B78 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4E37C 800B6B7C 01008490 */  lbu        $a0, 0x1($a0)
    /* 4E380 800B6B80 1934030C */  jal        vs_battle_dismissTextBox
    /* 4E384 800B6B84 00000000 */   nop
    /* 4E388 800B6B88 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4E38C 800B6B8C 21100000 */  addu       $v0, $zero, $zero
    /* 4E390 800B6B90 0800E003 */  jr         $ra
    /* 4E394 800B6B94 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_script_dismissTextBox
