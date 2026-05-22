nonmatching func_8002A30C, 0x40

glabel func_8002A30C
    /* 1AB0C 8002A30C FFFFA624 */  addiu      $a2, $a1, -0x1
    /* 1AB10 8002A310 0380033C */  lui        $v1, %hi(D_8003354C)
    /* 1AB14 8002A314 4C35638C */  lw         $v1, %lo(D_8003354C)($v1)
    /* 1AB18 8002A318 0004023C */  lui        $v0, (0x4000000 >> 16)
    /* 1AB1C 8002A31C 0900A010 */  beqz       $a1, .L8002A344
    /* 1AB20 8002A320 000062AC */   sw        $v0, 0x0($v1)
    /* 1AB24 8002A324 FFFF0524 */  addiu      $a1, $zero, -0x1
  .L8002A328:
    /* 1AB28 8002A328 0000838C */  lw         $v1, 0x0($a0)
    /* 1AB2C 8002A32C 04008424 */  addiu      $a0, $a0, 0x4
    /* 1AB30 8002A330 0380023C */  lui        $v0, %hi(D_80033548)
    /* 1AB34 8002A334 4835428C */  lw         $v0, %lo(D_80033548)($v0)
    /* 1AB38 8002A338 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 1AB3C 8002A33C FAFFC514 */  bne        $a2, $a1, .L8002A328
    /* 1AB40 8002A340 000043AC */   sw        $v1, 0x0($v0)
  .L8002A344:
    /* 1AB44 8002A344 0800E003 */  jr         $ra
    /* 1AB48 8002A348 21100000 */   addu      $v0, $zero, $zero
endlabel func_8002A30C
