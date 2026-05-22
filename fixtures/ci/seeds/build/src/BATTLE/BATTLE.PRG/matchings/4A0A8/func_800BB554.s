nonmatching func_800BB554, 0x50

glabel func_800BB554
    /* 52D54 800BB554 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52D58 800BB558 1000B0AF */  sw         $s0, 0x10($sp)
    /* 52D5C 800BB55C 21808000 */  addu       $s0, $a0, $zero
    /* 52D60 800BB560 0F80033C */  lui        $v1, %hi(D_800F4C38)
    /* 52D64 800BB564 384C6324 */  addiu      $v1, $v1, %lo(D_800F4C38)
    /* 52D68 800BB568 1400BFAF */  sw         $ra, 0x14($sp)
    /* 52D6C 800BB56C 01000292 */  lbu        $v0, 0x1($s0)
    /* 52D70 800BB570 02000426 */  addiu      $a0, $s0, 0x2
    /* 52D74 800BB574 80100200 */  sll        $v0, $v0, 2
    /* 52D78 800BB578 21104300 */  addu       $v0, $v0, $v1
    /* 52D7C 800BB57C 04000326 */  addiu      $v1, $s0, 0x4
    /* 52D80 800BB580 80FF020C */  jal        vs_battle_getShort
    /* 52D84 800BB584 000043AC */   sw        $v1, 0x0($v0)
    /* 52D88 800BB588 00140200 */  sll        $v0, $v0, 16
    /* 52D8C 800BB58C 03140200 */  sra        $v0, $v0, 16
    /* 52D90 800BB590 21100202 */  addu       $v0, $s0, $v0
    /* 52D94 800BB594 1400BF8F */  lw         $ra, 0x14($sp)
    /* 52D98 800BB598 1000B08F */  lw         $s0, 0x10($sp)
    /* 52D9C 800BB59C 0800E003 */  jr         $ra
    /* 52DA0 800BB5A0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB554
