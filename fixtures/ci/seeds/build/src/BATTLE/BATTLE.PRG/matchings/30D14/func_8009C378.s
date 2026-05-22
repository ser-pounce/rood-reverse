nonmatching func_8009C378, 0x60

glabel func_8009C378
    /* 33B78 8009C378 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 33B7C 8009C37C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 33B80 8009C380 21808000 */  addu       $s0, $a0, $zero
    /* 33B84 8009C384 1400B1AF */  sw         $s1, 0x14($sp)
    /* 33B88 8009C388 2188A000 */  addu       $s1, $a1, $zero
    /* 33B8C 8009C38C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 33B90 8009C390 2C24010C */  jal        vs_main_memcpy
    /* 33B94 8009C394 00780624 */   addiu     $a2, $zero, 0x7800
    /* 33B98 8009C398 0000028E */  lw         $v0, 0x0($s0)
    /* 33B9C 8009C39C 0400038E */  lw         $v1, 0x4($s0)
    /* 33BA0 8009C3A0 23105100 */  subu       $v0, $v0, $s1
    /* 33BA4 8009C3A4 23187100 */  subu       $v1, $v1, $s1
    /* 33BA8 8009C3A8 000002AE */  sw         $v0, 0x0($s0)
    /* 33BAC 8009C3AC 21105000 */  addu       $v0, $v0, $s0
    /* 33BB0 8009C3B0 040003AE */  sw         $v1, 0x4($s0)
    /* 33BB4 8009C3B4 21187000 */  addu       $v1, $v1, $s0
    /* 33BB8 8009C3B8 000002AE */  sw         $v0, 0x0($s0)
    /* 33BBC 8009C3BC 040003AE */  sw         $v1, 0x4($s0)
    /* 33BC0 8009C3C0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 33BC4 8009C3C4 1400B18F */  lw         $s1, 0x14($sp)
    /* 33BC8 8009C3C8 1000B08F */  lw         $s0, 0x10($sp)
    /* 33BCC 8009C3CC 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 33BD0 8009C3D0 0800E003 */  jr         $ra
    /* 33BD4 8009C3D4 00000000 */   nop
endlabel func_8009C378
