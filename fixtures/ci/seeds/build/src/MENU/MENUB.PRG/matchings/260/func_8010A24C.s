nonmatching func_8010A24C, 0x34

glabel func_8010A24C
    /* 7A4C 8010A24C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7A50 8010A250 CA018228 */  slti       $v0, $a0, 0x1CA
    /* 7A54 8010A254 06004014 */  bnez       $v0, .L8010A270
    /* 7A58 8010A258 1000BFAF */   sw        $ra, 0x10($sp)
    /* 7A5C 8010A25C B6018424 */  addiu      $a0, $a0, 0x1B6
    /* 7A60 8010A260 00240400 */  sll        $a0, $a0, 16
    /* 7A64 8010A264 03240400 */  sra        $a0, $a0, 16
    /* 7A68 8010A268 05FB020C */  jal        vs_battle_setStateFlag
    /* 7A6C 8010A26C 01000524 */   addiu     $a1, $zero, 0x1
  .L8010A270:
    /* 7A70 8010A270 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7A74 8010A274 00000000 */  nop
    /* 7A78 8010A278 0800E003 */  jr         $ra
    /* 7A7C 8010A27C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8010A24C
