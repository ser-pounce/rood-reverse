nonmatching func_800BE53C, 0x68

glabel func_800BE53C
    /* 55D3C 800BE53C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 55D40 800BE540 2000B0AF */  sw         $s0, 0x20($sp)
    /* 55D44 800BE544 21808000 */  addu       $s0, $a0, $zero
    /* 55D48 800BE548 1000A427 */  addiu      $a0, $sp, 0x10
    /* 55D4C 800BE54C 94000526 */  addiu      $a1, $s0, 0x94
    /* 55D50 800BE550 2400BFAF */  sw         $ra, 0x24($sp)
    /* 55D54 800BE554 9BF9020C */  jal        _vectorSubtract
    /* 55D58 800BE558 24000626 */   addiu     $a2, $s0, 0x24
    /* 55D5C 800BE55C D0F9020C */  jal        _vectorMagnitude
    /* 55D60 800BE560 1000A427 */   addiu     $a0, $sp, 0x10
    /* 55D64 800BE564 05000392 */  lbu        $v1, 0x5($s0)
    /* 55D68 800BE568 03130200 */  sra        $v0, $v0, 12
    /* 55D6C 800BE56C 18004300 */  mult       $v0, $v1
    /* 55D70 800BE570 12100000 */  mflo       $v0
    /* 55D74 800BE574 6210033C */  lui        $v1, (0x10624DD3 >> 16)
    /* 55D78 800BE578 D34D6334 */  ori        $v1, $v1, (0x10624DD3 & 0xFFFF)
    /* 55D7C 800BE57C 18004300 */  mult       $v0, $v1
    /* 55D80 800BE580 C3170200 */  sra        $v0, $v0, 31
    /* 55D84 800BE584 10180000 */  mfhi       $v1
    /* 55D88 800BE588 83190300 */  sra        $v1, $v1, 6
    /* 55D8C 800BE58C 23186200 */  subu       $v1, $v1, $v0
    /* 55D90 800BE590 050003A2 */  sb         $v1, 0x5($s0)
    /* 55D94 800BE594 2400BF8F */  lw         $ra, 0x24($sp)
    /* 55D98 800BE598 2000B08F */  lw         $s0, 0x20($sp)
    /* 55D9C 800BE59C 0800E003 */  jr         $ra
    /* 55DA0 800BE5A0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800BE53C
