nonmatching func_800D6574, 0x34

glabel func_800D6574
    /* 6DD74 800D6574 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DD78 800D6578 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DD7C 800D657C 1C0D8394 */  lhu        $v1, 0xD1C($a0)
    /* 6DD80 800D6580 04000224 */  addiu      $v0, $zero, 0x4
    /* 6DD84 800D6584 04006214 */  bne        $v1, $v0, .L800D6598
    /* 6DD88 800D6588 00000000 */   nop
    /* 6DD8C 800D658C 200D8490 */  lbu        $a0, 0xD20($a0)
    /* 6DD90 800D6590 6EB3010C */  jal        func_8006CDB8
    /* 6DD94 800D6594 00000000 */   nop
  .L800D6598:
    /* 6DD98 800D6598 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DD9C 800D659C 00000000 */  nop
    /* 6DDA0 800D65A0 0800E003 */  jr         $ra
    /* 6DDA4 800D65A4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800D6574
