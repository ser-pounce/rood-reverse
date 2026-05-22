nonmatching func_8008B2E0, 0x40

glabel func_8008B2E0
    /* 22AE0 8008B2E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 22AE4 8008B2E4 21188000 */  addu       $v1, $a0, $zero
    /* 22AE8 8008B2E8 0F80023C */  lui        $v0, %hi(D_800F1BA8)
    /* 22AEC 8008B2EC 002A0500 */  sll        $a1, $a1, 8
    /* 22AF0 8008B2F0 2128A600 */  addu       $a1, $a1, $a2
    /* 22AF4 8008B2F4 40280500 */  sll        $a1, $a1, 1
    /* 22AF8 8008B2F8 A81B448C */  lw         $a0, %lo(D_800F1BA8)($v0)
    /* 22AFC 8008B2FC 40300700 */  sll        $a2, $a3, 1
    /* 22B00 8008B300 1000BFAF */  sw         $ra, 0x10($sp)
    /* 22B04 8008B304 21208500 */  addu       $a0, $a0, $a1
    /* 22B08 8008B308 2C24010C */  jal        vs_main_memcpy
    /* 22B0C 8008B30C 21286000 */   addu      $a1, $v1, $zero
    /* 22B10 8008B310 1000BF8F */  lw         $ra, 0x10($sp)
    /* 22B14 8008B314 00000000 */  nop
    /* 22B18 8008B318 0800E003 */  jr         $ra
    /* 22B1C 8008B31C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008B2E0
