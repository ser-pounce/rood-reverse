nonmatching func_8006C350, 0x4C

glabel func_8006C350
    /* 3B50 8006C350 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3B54 8006C354 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3B58 8006C358 01001024 */  addiu      $s0, $zero, 0x1
    /* 3B5C 8006C35C 1400BFAF */  sw         $ra, 0x14($sp)
  .L8006C360:
    /* 3B60 8006C360 7179020C */  jal        func_8009E5C4
    /* 3B64 8006C364 21200002 */   addu      $a0, $s0, $zero
    /* 3B68 8006C368 01001026 */  addiu      $s0, $s0, 0x1
    /* 3B6C 8006C36C 1000022A */  slti       $v0, $s0, 0x10
    /* 3B70 8006C370 FBFF4014 */  bnez       $v0, .L8006C360
    /* 3B74 8006C374 00000000 */   nop
    /* 3B78 8006C378 DC56020C */  jal        func_80095B70
    /* 3B7C 8006C37C 01000424 */   addiu     $a0, $zero, 0x1
    /* 3B80 8006C380 0F80033C */  lui        $v1, %hi(D_800F1968)
    /* 3B84 8006C384 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3B88 8006C388 1000B08F */  lw         $s0, 0x10($sp)
    /* 3B8C 8006C38C 01000224 */  addiu      $v0, $zero, 0x1
    /* 3B90 8006C390 681962AC */  sw         $v0, %lo(D_800F1968)($v1)
    /* 3B94 8006C394 0800E003 */  jr         $ra
    /* 3B98 8006C398 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006C350
