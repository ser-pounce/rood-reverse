nonmatching func_800BA218, 0x4C

glabel func_800BA218
    /* 51A18 800BA218 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51A1C 800BA21C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 51A20 800BA220 21808000 */  addu       $s0, $a0, $zero
    /* 51A24 800BA224 1400BFAF */  sw         $ra, 0x14($sp)
    /* 51A28 800BA228 80FF020C */  jal        vs_battle_getShort
    /* 51A2C 800BA22C 01000426 */   addiu     $a0, $s0, 0x1
    /* 51A30 800BA230 03000426 */  addiu      $a0, $s0, 0x3
    /* 51A34 800BA234 00840200 */  sll        $s0, $v0, 16
    /* 51A38 800BA238 80FF020C */  jal        vs_battle_getShort
    /* 51A3C 800BA23C 03841000 */   sra       $s0, $s0, 16
    /* 51A40 800BA240 21200002 */  addu       $a0, $s0, $zero
    /* 51A44 800BA244 00140200 */  sll        $v0, $v0, 16
    /* 51A48 800BA248 1A45020C */  jal        func_80091468
    /* 51A4C 800BA24C 032C0200 */   sra       $a1, $v0, 16
    /* 51A50 800BA250 1400BF8F */  lw         $ra, 0x14($sp)
    /* 51A54 800BA254 1000B08F */  lw         $s0, 0x10($sp)
    /* 51A58 800BA258 21100000 */  addu       $v0, $zero, $zero
    /* 51A5C 800BA25C 0800E003 */  jr         $ra
    /* 51A60 800BA260 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA218
