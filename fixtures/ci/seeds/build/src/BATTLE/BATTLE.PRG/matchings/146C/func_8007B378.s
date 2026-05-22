nonmatching func_8007B378, 0x58

glabel func_8007B378
    /* 12B78 8007B378 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 12B7C 8007B37C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 12B80 8007B380 21808000 */  addu       $s0, $a0, $zero
    /* 12B84 8007B384 1400B1AF */  sw         $s1, 0x14($sp)
    /* 12B88 8007B388 2188A000 */  addu       $s1, $a1, $zero
    /* 12B8C 8007B38C 21280000 */  addu       $a1, $zero, $zero
    /* 12B90 8007B390 1800BFAF */  sw         $ra, 0x18($sp)
    /* 12B94 8007B394 201B010C */  jal        vs_main_loadClutTransition
    /* 12B98 8007B398 21302002 */   addu      $a2, $s1, $zero
    /* 12B9C 8007B39C 21200002 */  addu       $a0, $s0, $zero
    /* 12BA0 8007B3A0 01000524 */  addiu      $a1, $zero, 0x1
    /* 12BA4 8007B3A4 201B010C */  jal        vs_main_loadClutTransition
    /* 12BA8 8007B3A8 00022626 */   addiu     $a2, $s1, 0x200
    /* 12BAC 8007B3AC 21200002 */  addu       $a0, $s0, $zero
    /* 12BB0 8007B3B0 02000524 */  addiu      $a1, $zero, 0x2
    /* 12BB4 8007B3B4 201B010C */  jal        vs_main_loadClutTransition
    /* 12BB8 8007B3B8 00042626 */   addiu     $a2, $s1, 0x400
    /* 12BBC 8007B3BC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 12BC0 8007B3C0 1400B18F */  lw         $s1, 0x14($sp)
    /* 12BC4 8007B3C4 1000B08F */  lw         $s0, 0x10($sp)
    /* 12BC8 8007B3C8 0800E003 */  jr         $ra
    /* 12BCC 8007B3CC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007B378
