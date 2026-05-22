nonmatching func_8001852C, 0x74

glabel func_8001852C
    /* 8D2C 8001852C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8D30 80018530 0380053C */  lui        $a1, %hi(g_ActiveMusicChannels)
    /* 8D34 80018534 9036A524 */  addiu      $a1, $a1, %lo(g_ActiveMusicChannels)
    /* 8D38 80018538 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8D3C 8001853C 0380103C */  lui        $s0, %hi(g_pActiveMusicConfig)
    /* 8D40 80018540 2078048E */  lw         $a0, %lo(g_pActiveMusicConfig)($s0)
    /* 8D44 80018544 1400BFAF */  sw         $ra, 0x14($sp)
    /* 8D48 80018548 3C58000C */  jal        Sound_KillMusicConfig
    /* 8D4C 8001854C 21300000 */   addu      $a2, $zero, $zero
    /* 8D50 80018550 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 8D54 80018554 2866448C */  lw         $a0, %lo(g_pSavedMousicConfig)($v0)
    /* 8D58 80018558 00000000 */  nop
    /* 8D5C 8001855C 04008010 */  beqz       $a0, .L80018570
    /* 8D60 80018560 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 8D64 80018564 D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
    /* 8D68 80018568 3C58000C */  jal        Sound_KillMusicConfig
    /* 8D6C 8001856C 21300000 */   addu      $a2, $zero, $zero
  .L80018570:
    /* 8D70 80018570 2078048E */  lw         $a0, %lo(g_pActiveMusicConfig)($s0)
    /* 8D74 80018574 FEFF053C */  lui        $a1, (0xFFFEFFFF >> 16)
    /* 8D78 80018578 0000828C */  lw         $v0, 0x0($a0)
    /* 8D7C 8001857C FFFFA534 */  ori        $a1, $a1, (0xFFFEFFFF & 0xFFFF)
    /* 8D80 80018580 24104500 */  and        $v0, $v0, $a1
    /* 8D84 80018584 000082AC */  sw         $v0, 0x0($a0)
    /* 8D88 80018588 1400BF8F */  lw         $ra, 0x14($sp)
    /* 8D8C 8001858C 1000B08F */  lw         $s0, 0x10($sp)
    /* 8D90 80018590 0380033C */  lui        $v1, %hi(D_80037788)
    /* 8D94 80018594 887760AC */  sw         $zero, %lo(D_80037788)($v1)
    /* 8D98 80018598 0800E003 */  jr         $ra
    /* 8D9C 8001859C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001852C
