nonmatching func_8008A6FC, 0x48

glabel func_8008A6FC
    /* 21EFC 8008A6FC 0F80023C */  lui        $v0, %hi(_lootListHead)
    /* 21F00 8008A700 0019448C */  lw         $a0, %lo(_lootListHead)($v0)
    /* 21F04 8008A704 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21F08 8008A708 1400BFAF */  sw         $ra, 0x14($sp)
    /* 21F0C 8008A70C 07008010 */  beqz       $a0, .L8008A72C
    /* 21F10 8008A710 1000B0AF */   sw        $s0, 0x10($sp)
  .L8008A714:
    /* 21F14 8008A714 0000908C */  lw         $s0, 0x0($a0)
    /* 21F18 8008A718 180F010C */  jal        vs_main_freeHeapR
    /* 21F1C 8008A71C 00000000 */   nop
    /* 21F20 8008A720 21200002 */  addu       $a0, $s0, $zero
    /* 21F24 8008A724 FBFF8014 */  bnez       $a0, .L8008A714
    /* 21F28 8008A728 00000000 */   nop
  .L8008A72C:
    /* 21F2C 8008A72C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 21F30 8008A730 1000B08F */  lw         $s0, 0x10($sp)
    /* 21F34 8008A734 0F80023C */  lui        $v0, %hi(_lootListHead)
    /* 21F38 8008A738 001940AC */  sw         $zero, %lo(_lootListHead)($v0)
    /* 21F3C 8008A73C 0800E003 */  jr         $ra
    /* 21F40 8008A740 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008A6FC
