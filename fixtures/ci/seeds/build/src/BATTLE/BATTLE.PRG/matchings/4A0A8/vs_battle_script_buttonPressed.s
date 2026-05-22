nonmatching vs_battle_script_buttonPressed, 0x28

glabel vs_battle_script_buttonPressed
    /* 4E7B0 800B6FB0 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 4E7B4 800B6FB4 01008490 */  lbu        $a0, 0x1($a0)
    /* 4E7B8 800B6FB8 D0E1438C */  lw         $v1, %lo(vs_main_buttonsPressed)($v0)
    /* 4E7BC 800B6FBC 00000000 */  nop
    /* 4E7C0 800B6FC0 24186400 */  and        $v1, $v1, $a0
    /* 4E7C4 800B6FC4 02006014 */  bnez       $v1, .L800B6FD0
    /* 4E7C8 800B6FC8 04000224 */   addiu     $v0, $zero, 0x4
    /* 4E7CC 800B6FCC 01000224 */  addiu      $v0, $zero, 0x1
  .L800B6FD0:
    /* 4E7D0 800B6FD0 0800E003 */  jr         $ra
    /* 4E7D4 800B6FD4 00000000 */   nop
endlabel vs_battle_script_buttonPressed
