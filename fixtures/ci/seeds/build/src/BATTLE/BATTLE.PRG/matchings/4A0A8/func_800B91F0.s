nonmatching func_800B91F0, 0x40

glabel func_800B91F0
    /* 509F0 800B91F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 509F4 800B91F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 509F8 800B91F8 21808000 */  addu       $s0, $a0, $zero
    /* 509FC 800B91FC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 50A00 800B9200 80FF020C */  jal        vs_battle_getShort
    /* 50A04 800B9204 01000426 */   addiu     $a0, $s0, 0x1
    /* 50A08 800B9208 94FF020C */  jal        func_800BFE50
    /* 50A0C 800B920C FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 50A10 800B9210 03000592 */  lbu        $a1, 0x3($s0)
    /* 50A14 800B9214 F776020C */  jal        func_8009DBDC
    /* 50A18 800B9218 21204000 */   addu      $a0, $v0, $zero
    /* 50A1C 800B921C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 50A20 800B9220 1000B08F */  lw         $s0, 0x10($sp)
    /* 50A24 800B9224 21100000 */  addu       $v0, $zero, $zero
    /* 50A28 800B9228 0800E003 */  jr         $ra
    /* 50A2C 800B922C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800B91F0
