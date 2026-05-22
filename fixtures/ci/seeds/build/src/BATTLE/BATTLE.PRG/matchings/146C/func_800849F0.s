nonmatching func_800849F0, 0x4C

glabel func_800849F0
    /* 1C1F0 800849F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C1F4 800849F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C1F8 800849F8 2180C000 */  addu       $s0, $a2, $zero
    /* 1C1FC 800849FC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C200 80084A00 EA09010C */  jal        vs_main_getRand
    /* 1C204 80084A04 04000424 */   addiu     $a0, $zero, 0x4
    /* 1C208 80084A08 FFCF0324 */  addiu      $v1, $zero, -0x3001
    /* 1C20C 80084A0C 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C210 80084A10 01004224 */  addiu      $v0, $v0, 0x1
    /* 1C214 80084A14 24208300 */  and        $a0, $a0, $v1
    /* 1C218 80084A18 10000396 */  lhu        $v1, 0x10($s0)
    /* 1C21C 80084A1C 00208434 */  ori        $a0, $a0, 0x2000
    /* 1C220 80084A20 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C224 80084A24 21186200 */  addu       $v1, $v1, $v0
    /* 1C228 80084A28 100003A6 */  sh         $v1, 0x10($s0)
    /* 1C22C 80084A2C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C230 80084A30 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C234 80084A34 0800E003 */  jr         $ra
    /* 1C238 80084A38 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800849F0
