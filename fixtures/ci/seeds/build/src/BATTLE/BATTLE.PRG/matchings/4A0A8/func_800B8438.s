nonmatching func_800B8438, 0x64

glabel func_800B8438
    /* 4FC38 800B8438 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4FC3C 800B843C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4FC40 800B8440 21808000 */  addu       $s0, $a0, $zero
    /* 4FC44 800B8444 1400BFAF */  sw         $ra, 0x14($sp)
    /* 4FC48 800B8448 80FF020C */  jal        vs_battle_getShort
    /* 4FC4C 800B844C 01000426 */   addiu     $a0, $s0, 0x1
    /* 4FC50 800B8450 94FF020C */  jal        func_800BFE50
    /* 4FC54 800B8454 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4FC58 800B8458 0F80043C */  lui        $a0, %hi(D_800E9B58)
    /* 4FC5C 800B845C 589B8424 */  addiu      $a0, $a0, %lo(D_800E9B58)
    /* 4FC60 800B8460 06000692 */  lbu        $a2, 0x6($s0)
    /* 4FC64 800B8464 03000592 */  lbu        $a1, 0x3($s0)
    /* 4FC68 800B8468 04000792 */  lbu        $a3, 0x4($s0)
    /* 4FC6C 800B846C 82190600 */  srl        $v1, $a2, 6
    /* 4FC70 800B8470 21186400 */  addu       $v1, $v1, $a0
    /* 4FC74 800B8474 21204000 */  addu       $a0, $v0, $zero
    /* 4FC78 800B8478 00006390 */  lbu        $v1, 0x0($v1)
    /* 4FC7C 800B847C 3F00C630 */  andi       $a2, $a2, 0x3F
    /* 4FC80 800B8480 7280020C */  jal        func_800A01C8
    /* 4FC84 800B8484 21286500 */   addu      $a1, $v1, $a1
    /* 4FC88 800B8488 1400BF8F */  lw         $ra, 0x14($sp)
    /* 4FC8C 800B848C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4FC90 800B8490 21100000 */  addu       $v0, $zero, $zero
    /* 4FC94 800B8494 0800E003 */  jr         $ra
    /* 4FC98 800B8498 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B8438
