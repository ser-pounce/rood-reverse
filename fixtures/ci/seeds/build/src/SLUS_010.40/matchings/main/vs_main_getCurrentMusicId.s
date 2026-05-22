nonmatching vs_main_getCurrentMusicId, 0x2C

glabel vs_main_getCurrentMusicId
    /* 358E4 800450E4 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 358E8 800450E8 38E0438C */  lw         $v1, %lo(vs_main_soundData)($v0)
    /* 358EC 800450EC 00000000 */  nop
    /* 358F0 800450F0 03006014 */  bnez       $v1, .L80045100
    /* 358F4 800450F4 38E04224 */   addiu     $v0, $v0, %lo(vs_main_soundData)
    /* 358F8 800450F8 0800E003 */  jr         $ra
    /* 358FC 800450FC 21100000 */   addu      $v0, $zero, $zero
  .L80045100:
    /* 35900 80045100 21106200 */  addu       $v0, $v1, $v0
    /* 35904 80045104 0F004290 */  lbu        $v0, 0xF($v0)
    /* 35908 80045108 0800E003 */  jr         $ra
    /* 3590C 8004510C 00000000 */   nop
endlabel vs_main_getCurrentMusicId
