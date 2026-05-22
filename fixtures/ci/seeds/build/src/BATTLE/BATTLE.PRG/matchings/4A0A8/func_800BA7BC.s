nonmatching func_800BA7BC, 0x44

glabel func_800BA7BC
    /* 51FBC 800BA7BC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 51FC0 800BA7C0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 51FC4 800BA7C4 21808000 */  addu       $s0, $a0, $zero
    /* 51FC8 800BA7C8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 51FCC 800BA7CC 6513010C */  jal        func_80044D94
    /* 51FD0 800BA7D0 1400B1AF */   sw        $s1, 0x14($sp)
    /* 51FD4 800BA7D4 038C0200 */  sra        $s1, $v0, 16
    /* 51FD8 800BA7D8 80FF020C */  jal        vs_battle_getShort
    /* 51FDC 800BA7DC 01000426 */   addiu     $a0, $s0, 0x1
    /* 51FE0 800BA7E0 00140200 */  sll        $v0, $v0, 16
    /* 51FE4 800BA7E4 03140200 */  sra        $v0, $v0, 16
    /* 51FE8 800BA7E8 2A102202 */  slt        $v0, $s1, $v0
    /* 51FEC 800BA7EC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 51FF0 800BA7F0 1400B18F */  lw         $s1, 0x14($sp)
    /* 51FF4 800BA7F4 1000B08F */  lw         $s0, 0x10($sp)
    /* 51FF8 800BA7F8 0800E003 */  jr         $ra
    /* 51FFC 800BA7FC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800BA7BC
