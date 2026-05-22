nonmatching func_8002032C, 0x24

glabel func_8002032C
    /* 10B2C 8002032C 0600A010 */  beqz       $a1, .L80020348
    /* 10B30 80020330 FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 10B34 80020334 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L80020338:
    /* 10B38 80020338 000080AC */  sw         $zero, 0x0($a0)
    /* 10B3C 8002033C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 10B40 80020340 FDFF4314 */  bne        $v0, $v1, .L80020338
    /* 10B44 80020344 04008424 */   addiu     $a0, $a0, 0x4
  .L80020348:
    /* 10B48 80020348 0800E003 */  jr         $ra
    /* 10B4C 8002034C 00000000 */   nop
endlabel func_8002032C
    /* 10B50 80020350 00000000 */  nop
