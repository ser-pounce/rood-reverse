nonmatching func_8004552C, 0x48

glabel func_8004552C
    /* 35D2C 8004552C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 35D30 80045530 2138A000 */  addu       $a3, $a1, $zero
    /* 35D34 80045534 2128C000 */  addu       $a1, $a2, $zero
    /* 35D38 80045538 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* 35D3C 8004553C 38E0438C */  lw         $v1, %lo(vs_main_soundData)($v0)
    /* 35D40 80045540 38E04224 */  addiu      $v0, $v0, %lo(vs_main_soundData)
    /* 35D44 80045544 03006410 */  beq        $v1, $a0, .L80045554
    /* 35D48 80045548 1000BFAF */   sw        $ra, 0x10($sp)
    /* 35D4C 8004554C 59150108 */  j          .L80045564
    /* 35D50 80045550 21100000 */   addu      $v0, $zero, $zero
  .L80045554:
    /* 35D54 80045554 0400448C */  lw         $a0, 0x4($v0)
    /* 35D58 80045558 284A000C */  jal        func_800128A0
    /* 35D5C 8004555C 2130E000 */   addu      $a2, $a3, $zero
    /* 35D60 80045560 01000224 */  addiu      $v0, $zero, 0x1
  .L80045564:
    /* 35D64 80045564 1000BF8F */  lw         $ra, 0x10($sp)
    /* 35D68 80045568 00000000 */  nop
    /* 35D6C 8004556C 0800E003 */  jr         $ra
    /* 35D70 80045570 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004552C
