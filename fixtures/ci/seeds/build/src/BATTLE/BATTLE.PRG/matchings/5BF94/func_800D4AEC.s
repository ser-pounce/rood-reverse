nonmatching func_800D4AEC, 0x48

glabel func_800D4AEC
    /* 6C2EC 800D4AEC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6C2F0 800D4AF0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6C2F4 800D4AF4 21888000 */  addu       $s1, $a0, $zero
    /* 6C2F8 800D4AF8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6C2FC 800D4AFC 5C54030C */  jal        func_800D5170
    /* 6C300 800D4B00 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6C304 800D4B04 21202002 */  addu       $a0, $s1, $zero
    /* 6C308 800D4B08 6654030C */  jal        func_800D5198
    /* 6C30C 800D4B0C 21804000 */   addu      $s0, $v0, $zero
    /* 6C310 800D4B10 FF001032 */  andi       $s0, $s0, 0xFF
    /* 6C314 800D4B14 21883002 */  addu       $s1, $s1, $s0
    /* 6C318 800D4B18 100022A2 */  sb         $v0, 0x10($s1)
    /* 6C31C 800D4B1C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6C320 800D4B20 1400B18F */  lw         $s1, 0x14($sp)
    /* 6C324 800D4B24 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C328 800D4B28 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C32C 800D4B2C 0800E003 */  jr         $ra
    /* 6C330 800D4B30 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800D4AEC
