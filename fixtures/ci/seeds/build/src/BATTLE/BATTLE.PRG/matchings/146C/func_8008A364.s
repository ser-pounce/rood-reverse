nonmatching func_8008A364, 0x3C

glabel func_8008A364
    /* 21B64 8008A364 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21B68 8008A368 1000B0AF */  sw         $s0, 0x10($sp)
    /* 21B6C 8008A36C 02001024 */  addiu      $s0, $zero, 0x2
    /* 21B70 8008A370 1400BFAF */  sw         $ra, 0x14($sp)
    /* 21B74 8008A374 21200002 */  addu       $a0, $s0, $zero
  .L8008A378:
    /* 21B78 8008A378 8AA8010C */  jal        _removeActorAtIndex
    /* 21B7C 8008A37C 21280000 */   addu      $a1, $zero, $zero
    /* 21B80 8008A380 01001026 */  addiu      $s0, $s0, 0x1
    /* 21B84 8008A384 1000022A */  slti       $v0, $s0, 0x10
    /* 21B88 8008A388 FBFF4014 */  bnez       $v0, .L8008A378
    /* 21B8C 8008A38C 21200002 */   addu      $a0, $s0, $zero
    /* 21B90 8008A390 1400BF8F */  lw         $ra, 0x14($sp)
    /* 21B94 8008A394 1000B08F */  lw         $s0, 0x10($sp)
    /* 21B98 8008A398 0800E003 */  jr         $ra
    /* 21B9C 8008A39C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008A364
