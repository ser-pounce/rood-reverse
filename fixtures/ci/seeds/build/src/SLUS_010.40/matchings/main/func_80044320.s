nonmatching func_80044320, 0x20

glabel func_80044320
    /* 34B20 80044320 0580043C */  lui        $a0, %hi(vs_main_disk)
    /* 34B24 80044324 105D8390 */  lbu        $v1, %lo(vs_main_disk)($a0)
    /* 34B28 80044328 04000224 */  addiu      $v0, $zero, 0x4
    /* 34B2C 8004432C 02006214 */  bne        $v1, $v0, .L80044338
    /* 34B30 80044330 00000000 */   nop
    /* 34B34 80044334 105D80A0 */  sb         $zero, %lo(vs_main_disk)($a0)
  .L80044338:
    /* 34B38 80044338 0800E003 */  jr         $ra
    /* 34B3C 8004433C 00000000 */   nop
endlabel func_80044320
