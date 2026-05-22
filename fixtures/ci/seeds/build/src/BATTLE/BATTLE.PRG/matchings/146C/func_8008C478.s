nonmatching func_8008C478, 0x24

glabel func_8008C478
    /* 23C78 8008C478 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x7C)
    /* 23C7C 8008C47C 741C438C */  lw         $v1, %lo(vs_battle_roomData + 0x7C)($v0)
    /* 23C80 8008C480 00000000 */  nop
    /* 23C84 8008C484 03006014 */  bnez       $v1, .L8008C494
    /* 23C88 8008C488 C0100400 */   sll       $v0, $a0, 3
    /* 23C8C 8008C48C 0800E003 */  jr         $ra
    /* 23C90 8008C490 21100000 */   addu      $v0, $zero, $zero
  .L8008C494:
    /* 23C94 8008C494 0800E003 */  jr         $ra
    /* 23C98 8008C498 21106200 */   addu      $v0, $v1, $v0
endlabel func_8008C478
