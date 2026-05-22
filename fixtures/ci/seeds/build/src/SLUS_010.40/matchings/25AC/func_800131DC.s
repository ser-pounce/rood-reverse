nonmatching func_800131DC, 0x54

glabel func_800131DC
    /* 39DC 800131DC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 39E0 800131E0 1800B0AF */  sw         $s0, 0x18($sp)
    /* 39E4 800131E4 21808000 */  addu       $s0, $a0, $zero
    /* 39E8 800131E8 2138A000 */  addu       $a3, $a1, $zero
    /* 39EC 800131EC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 39F0 800131F0 2188C000 */  addu       $s1, $a2, $zero
    /* 39F4 800131F4 1000A527 */  addiu      $a1, $sp, 0x10
    /* 39F8 800131F8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 39FC 800131FC 674B000C */  jal        func_80012D9C
    /* 3A00 80013200 1400A627 */   addiu     $a2, $sp, 0x14
    /* 3A04 80013204 21200002 */  addu       $a0, $s0, $zero
    /* 3A08 80013208 1000A68F */  lw         $a2, 0x10($sp)
    /* 3A0C 8001320C 1400A78F */  lw         $a3, 0x14($sp)
    /* 3A10 80013210 764D000C */  jal        func_800135D8
    /* 3A14 80013214 21282002 */   addu      $a1, $s1, $zero
    /* 3A18 80013218 2000BF8F */  lw         $ra, 0x20($sp)
    /* 3A1C 8001321C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 3A20 80013220 1800B08F */  lw         $s0, 0x18($sp)
    /* 3A24 80013224 21100000 */  addu       $v0, $zero, $zero
    /* 3A28 80013228 0800E003 */  jr         $ra
    /* 3A2C 8001322C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800131DC
