nonmatching Sound_Cmd_11_StopAllMusic, 0x68

glabel Sound_Cmd_11_StopAllMusic
    /* 8DA0 800185A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8DA4 800185A4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 8DA8 800185A8 21808000 */  addu       $s0, $a0, $zero
    /* 8DAC 800185AC 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 8DB0 800185B0 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* 8DB4 800185B4 0380053C */  lui        $a1, %hi(g_ActiveMusicChannels)
    /* 8DB8 800185B8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 8DBC 800185BC 0000068E */  lw         $a2, 0x0($s0)
    /* 8DC0 800185C0 3C58000C */  jal        Sound_KillMusicConfig
    /* 8DC4 800185C4 9036A524 */   addiu     $a1, $a1, %lo(g_ActiveMusicChannels)
    /* 8DC8 800185C8 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 8DCC 800185CC 2866448C */  lw         $a0, %lo(g_pSavedMousicConfig)($v0)
    /* 8DD0 800185D0 00000000 */  nop
    /* 8DD4 800185D4 08008010 */  beqz       $a0, .L800185F8
    /* 8DD8 800185D8 00000000 */   nop
    /* 8DDC 800185DC 0000068E */  lw         $a2, 0x0($s0)
    /* 8DE0 800185E0 00000000 */  nop
    /* 8DE4 800185E4 0400C010 */  beqz       $a2, .L800185F8
    /* 8DE8 800185E8 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 8DEC 800185EC D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
    /* 8DF0 800185F0 3C58000C */  jal        Sound_KillMusicConfig
    /* 8DF4 800185F4 00000000 */   nop
  .L800185F8:
    /* 8DF8 800185F8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 8DFC 800185FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 8E00 80018600 0800E003 */  jr         $ra
    /* 8E04 80018604 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_11_StopAllMusic
