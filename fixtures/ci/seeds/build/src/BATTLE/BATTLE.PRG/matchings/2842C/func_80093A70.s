nonmatching func_80093A70, 0x44

glabel func_80093A70
    /* 2B270 80093A70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2B274 80093A74 0F80023C */  lui        $v0, %hi(D_800F2258)
    /* 2B278 80093A78 58224684 */  lh         $a2, %lo(D_800F2258)($v0)
    /* 2B27C 80093A7C FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 2B280 80093A80 0800C210 */  beq        $a2, $v0, .L80093AA4
    /* 2B284 80093A84 1000BFAF */   sw        $ra, 0x10($sp)
    /* 2B288 80093A88 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0xB0)
    /* 2B28C 80093A8C A81C458C */  lw         $a1, %lo(vs_battle_roomData + 0xB0)($v0)
    /* 2B290 80093A90 00000000 */  nop
    /* 2B294 80093A94 0300A010 */  beqz       $a1, .L80093AA4
    /* 2B298 80093A98 00000000 */   nop
    /* 2B29C 80093A9C BA18010C */  jal        func_800462E8
    /* 2B2A0 80093AA0 00020424 */   addiu     $a0, $zero, 0x200
  .L80093AA4:
    /* 2B2A4 80093AA4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2B2A8 80093AA8 00000000 */  nop
    /* 2B2AC 80093AAC 0800E003 */  jr         $ra
    /* 2B2B0 80093AB0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80093A70
