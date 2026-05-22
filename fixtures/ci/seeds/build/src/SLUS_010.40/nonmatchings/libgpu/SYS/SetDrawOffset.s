nonmatching SetDrawOffset, 0x40

glabel SetDrawOffset
    /* 19C5C 8002945C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 19C60 80029460 1000B0AF */  sw         $s0, 0x10($sp)
    /* 19C64 80029464 21808000 */  addu       $s0, $a0, $zero
    /* 19C68 80029468 02000224 */  addiu      $v0, $zero, 0x2
    /* 19C6C 8002946C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 19C70 80029470 030002A2 */  sb         $v0, 0x3($s0)
    /* 19C74 80029474 0000A484 */  lh         $a0, 0x0($a1)
    /* 19C78 80029478 0200A584 */  lh         $a1, 0x2($a1)
    /* 19C7C 8002947C 95A6000C */  jal        func_80029A54
    /* 19C80 80029480 00000000 */   nop
    /* 19C84 80029484 040002AE */  sw         $v0, 0x4($s0)
    /* 19C88 80029488 080000AE */  sw         $zero, 0x8($s0)
    /* 19C8C 8002948C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 19C90 80029490 1000B08F */  lw         $s0, 0x10($sp)
    /* 19C94 80029494 0800E003 */  jr         $ra
    /* 19C98 80029498 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SetDrawOffset
