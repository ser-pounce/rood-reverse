nonmatching func_8002B1DC, 0x24

glabel func_8002B1DC
    /* 1B9DC 8002B1DC 0600C010 */  beqz       $a2, .L8002B1F8
    /* 1B9E0 8002B1E0 FFFFC224 */   addiu     $v0, $a2, -0x1
    /* 1B9E4 8002B1E4 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L8002B1E8:
    /* 1B9E8 8002B1E8 000085A0 */  sb         $a1, 0x0($a0)
    /* 1B9EC 8002B1EC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1B9F0 8002B1F0 FDFF4314 */  bne        $v0, $v1, .L8002B1E8
    /* 1B9F4 8002B1F4 01008424 */   addiu     $a0, $a0, 0x1
  .L8002B1F8:
    /* 1B9F8 8002B1F8 0800E003 */  jr         $ra
    /* 1B9FC 8002B1FC 00000000 */   nop
endlabel func_8002B1DC
    /* 1BA00 8002B200 00000000 */  nop
