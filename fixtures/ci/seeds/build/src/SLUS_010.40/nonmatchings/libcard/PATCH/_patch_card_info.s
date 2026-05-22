/* Handwritten function */
nonmatching _patch_card_info, 0x44

glabel _patch_card_info
    /* 1F6B4 8002EEB4 0480013C */  lui        $at, %hi(D_8003FED8)
    /* 1F6B8 8002EEB8 D8FE3FAC */  sw         $ra, %lo(D_8003FED8)($at)
    /* 1F6BC 8002EEBC 57000924 */  addiu      $t1, $zero, 0x57
    /* 1F6C0 8002EEC0 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F6C4 8002EEC4 09F84001 */  jalr       $t2
    /* 1F6C8 8002EEC8 00000000 */   nop
    /* 1F6CC 8002EECC 09000A24 */  addiu      $t2, $zero, 0x9
    /* 1F6D0 8002EED0 6C01428C */  lw         $v0, 0x16C($v0)
    /* 1F6D4 8002EED4 00000000 */  nop
    /* 1F6D8 8002EED8 88194320 */  addi       $v1, $v0, 0x1988 /* handwritten instruction */
    /* 1F6DC 8002EEDC 1D9A000C */  jal        FlushCache
    /* 1F6E0 8002EEE0 000060AC */   sw        $zero, 0x0($v1)
    /* 1F6E4 8002EEE4 04801F3C */  lui        $ra, %hi(D_8003FED8)
    /* 1F6E8 8002EEE8 D8FEFF8F */  lw         $ra, %lo(D_8003FED8)($ra)
    /* 1F6EC 8002EEEC 00000000 */  nop
    /* 1F6F0 8002EEF0 0800E003 */  jr         $ra
    /* 1F6F4 8002EEF4 00000000 */   nop
endlabel _patch_card_info
