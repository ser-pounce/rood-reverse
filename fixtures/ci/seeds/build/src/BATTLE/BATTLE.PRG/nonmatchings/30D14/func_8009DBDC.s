nonmatching func_8009DBDC, 0x5C

glabel func_8009DBDC
    /* 353DC 8009DBDC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 353E0 8009DBE0 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 353E4 8009DBE4 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 353E8 8009DBE8 80200400 */  sll        $a0, $a0, 2
    /* 353EC 8009DBEC 21208200 */  addu       $a0, $a0, $v0
    /* 353F0 8009DBF0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 353F4 8009DBF4 0000848C */  lw         $a0, 0x0($a0)
    /* 353F8 8009DBF8 00000000 */  nop
    /* 353FC 8009DBFC 0A008010 */  beqz       $a0, .L8009DC28
    /* 35400 8009DC00 2130A000 */   addu      $a2, $a1, $zero
    /* 35404 8009DC04 0F80023C */  lui        $v0, %hi(D_800E9090)
    /* 35408 8009DC08 B1058390 */  lbu        $v1, 0x5B1($a0)
    /* 3540C 8009DC0C 90904224 */  addiu      $v0, $v0, %lo(D_800E9090)
    /* 35410 8009DC10 21186200 */  addu       $v1, $v1, $v0
    /* 35414 8009DC14 00006590 */  lbu        $a1, 0x0($v1)
    /* 35418 8009DC18 00000000 */  nop
    /* 3541C 8009DC1C 2128A600 */  addu       $a1, $a1, $a2
    /* 35420 8009DC20 B0B9020C */  jal        func_800AE6C0
    /* 35424 8009DC24 21300000 */   addu      $a2, $zero, $zero
  .L8009DC28:
    /* 35428 8009DC28 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3542C 8009DC2C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 35430 8009DC30 0800E003 */  jr         $ra
    /* 35434 8009DC34 00000000 */   nop
endlabel func_8009DBDC
