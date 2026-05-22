nonmatching func_8006CD60, 0x58

glabel func_8006CD60
    /* 4560 8006CD60 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4564 8006CD64 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4568 8006CD68 21808000 */  addu       $s0, $a0, $zero
    /* 456C 8006CD6C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 4570 8006CD70 2190A000 */  addu       $s2, $a1, $zero
    /* 4574 8006CD74 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 4578 8006CD78 2188C000 */  addu       $s1, $a2, $zero
    /* 457C 8006CD7C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 4580 8006CD80 EA09010C */  jal        vs_main_getRand
    /* 4584 8006CD84 03000424 */   addiu     $a0, $zero, 0x3
    /* 4588 8006CD88 7E000424 */  addiu      $a0, $zero, 0x7E
    /* 458C 8006CD8C 21280002 */  addu       $a1, $s0, $zero
    /* 4590 8006CD90 08004624 */  addiu      $a2, $v0, 0x8
    /* 4594 8006CD94 21384002 */  addu       $a3, $s2, $zero
    /* 4598 8006CD98 7318010C */  jal        func_800461CC
    /* 459C 8006CD9C 1000B1AF */   sw        $s1, 0x10($sp)
    /* 45A0 8006CDA0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 45A4 8006CDA4 2000B28F */  lw         $s2, 0x20($sp)
    /* 45A8 8006CDA8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 45AC 8006CDAC 1800B08F */  lw         $s0, 0x18($sp)
    /* 45B0 8006CDB0 0800E003 */  jr         $ra
    /* 45B4 8006CDB4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006CD60
