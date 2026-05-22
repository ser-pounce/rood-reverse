nonmatching func_8006C2FC, 0x54

glabel func_8006C2FC
    /* 3AFC 8006C2FC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3B00 8006C300 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3B04 8006C304 01001024 */  addiu      $s0, $zero, 0x1
    /* 3B08 8006C308 1400BFAF */  sw         $ra, 0x14($sp)
  .L8006C30C:
    /* 3B0C 8006C30C 7179020C */  jal        func_8009E5C4
    /* 3B10 8006C310 21200002 */   addu      $a0, $s0, $zero
    /* 3B14 8006C314 01001026 */  addiu      $s0, $s0, 0x1
    /* 3B18 8006C318 1000022A */  slti       $v0, $s0, 0x10
    /* 3B1C 8006C31C FBFF4014 */  bnez       $v0, .L8006C30C
    /* 3B20 8006C320 00000000 */   nop
    /* 3B24 8006C324 322D020C */  jal        func_8008B4C8
    /* 3B28 8006C328 21200000 */   addu      $a0, $zero, $zero
    /* 3B2C 8006C32C DC56020C */  jal        func_80095B70
    /* 3B30 8006C330 01000424 */   addiu     $a0, $zero, 0x1
    /* 3B34 8006C334 0F80033C */  lui        $v1, %hi(D_800F1968)
    /* 3B38 8006C338 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3B3C 8006C33C 1000B08F */  lw         $s0, 0x10($sp)
    /* 3B40 8006C340 01000224 */  addiu      $v0, $zero, 0x1
    /* 3B44 8006C344 681962AC */  sw         $v0, %lo(D_800F1968)($v1)
    /* 3B48 8006C348 0800E003 */  jr         $ra
    /* 3B4C 8006C34C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006C2FC
