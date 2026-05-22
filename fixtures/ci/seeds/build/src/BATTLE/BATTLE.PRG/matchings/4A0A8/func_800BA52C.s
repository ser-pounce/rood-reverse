nonmatching func_800BA52C, 0x5C

glabel func_800BA52C
    /* 51D2C 800BA52C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 51D30 800BA530 1000B0AF */  sw         $s0, 0x10($sp)
    /* 51D34 800BA534 21808000 */  addu       $s0, $a0, $zero
    /* 51D38 800BA538 1400B1AF */  sw         $s1, 0x14($sp)
    /* 51D3C 800BA53C 0F80113C */  lui        $s1, %hi(D_800F4C69)
    /* 51D40 800BA540 694C2492 */  lbu        $a0, %lo(D_800F4C69)($s1)
    /* 51D44 800BA544 1800BFAF */  sw         $ra, 0x18($sp)
    /* 51D48 800BA548 04000692 */  lbu        $a2, 0x4($s0)
    /* 51D4C 800BA54C 4B15010C */  jal        func_8004552C
    /* 51D50 800BA550 21280000 */   addu      $a1, $zero, $zero
    /* 51D54 800BA554 01000492 */  lbu        $a0, 0x1($s0)
    /* 51D58 800BA558 00000000 */  nop
    /* 51D5C 800BA55C 694C24A2 */  sb         $a0, %lo(D_800F4C69)($s1)
    /* 51D60 800BA560 02000592 */  lbu        $a1, 0x2($s0)
    /* 51D64 800BA564 03000692 */  lbu        $a2, 0x3($s0)
    /* 51D68 800BA568 D813010C */  jal        func_80044F60
    /* 51D6C 800BA56C FF008430 */   andi      $a0, $a0, 0xFF
    /* 51D70 800BA570 1800BF8F */  lw         $ra, 0x18($sp)
    /* 51D74 800BA574 1400B18F */  lw         $s1, 0x14($sp)
    /* 51D78 800BA578 1000B08F */  lw         $s0, 0x10($sp)
    /* 51D7C 800BA57C 21100000 */  addu       $v0, $zero, $zero
    /* 51D80 800BA580 0800E003 */  jr         $ra
    /* 51D84 800BA584 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BA52C
