nonmatching func_8002E7BC, 0x2C

glabel func_8002E7BC
    /* 1EFBC 8002E7BC E6008294 */  lhu        $v0, 0xE6($a0)
    /* 1EFC0 8002E7C0 00000000 */  nop
    /* 1EFC4 8002E7C4 05004010 */  beqz       $v0, .L8002E7DC
    /* 1EFC8 8002E7C8 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 1EFCC 8002E7CC 46008390 */  lbu        $v1, 0x46($a0)
    /* 1EFD0 8002E7D0 00000000 */  nop
    /* 1EFD4 8002E7D4 02006210 */  beq        $v1, $v0, .L8002E7E0
    /* 1EFD8 8002E7D8 21100000 */   addu      $v0, $zero, $zero
  .L8002E7DC:
    /* 1EFDC 8002E7DC 01000224 */  addiu      $v0, $zero, 0x1
  .L8002E7E0:
    /* 1EFE0 8002E7E0 0800E003 */  jr         $ra
    /* 1EFE4 8002E7E4 00000000 */   nop
endlabel func_8002E7BC
    /* 1EFE8 8002E7E8 00000000 */  nop
    /* 1EFEC 8002E7EC 00000000 */  nop
    /* 1EFF0 8002E7F0 00000000 */  nop
