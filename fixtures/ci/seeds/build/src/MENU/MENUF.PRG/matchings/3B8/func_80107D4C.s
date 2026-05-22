nonmatching func_80107D4C, 0x4C

glabel func_80107D4C
    /* 554C 80107D4C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 5550 80107D50 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 5554 80107D54 98154324 */  addiu      $v1, $v0, %lo(vs_main_stateFlags)
    /* 5558 80107D58 1000BFAF */  sw         $ra, 0x10($sp)
    /* 555C 80107D5C A3006290 */  lbu        $v0, 0xA3($v1)
    /* 5560 80107D60 00000000 */  nop
    /* 5564 80107D64 06004010 */  beqz       $v0, .L80107D80
    /* 5568 80107D68 3B000224 */   addiu     $v0, $zero, 0x3B
    /* 556C 80107D6C A20062A0 */  sb         $v0, 0xA2($v1)
    /* 5570 80107D70 A10062A0 */  sb         $v0, 0xA1($v1)
    /* 5574 80107D74 63000224 */  addiu      $v0, $zero, 0x63
    /* 5578 80107D78 A30060A0 */  sb         $zero, 0xA3($v1)
    /* 557C 80107D7C A00062A0 */  sb         $v0, 0xA0($v1)
  .L80107D80:
    /* 5580 80107D80 A31E040C */  jal        _initCubePuzzleStart
    /* 5584 80107D84 00000000 */   nop
    /* 5588 80107D88 1000BF8F */  lw         $ra, 0x10($sp)
    /* 558C 80107D8C 00000000 */  nop
    /* 5590 80107D90 0800E003 */  jr         $ra
    /* 5594 80107D94 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80107D4C
