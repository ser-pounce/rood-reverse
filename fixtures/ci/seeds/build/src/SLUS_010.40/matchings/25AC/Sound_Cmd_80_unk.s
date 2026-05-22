nonmatching Sound_Cmd_80_unk, 0x60

glabel Sound_Cmd_80_unk
    /* 8EE4 800186E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8EE8 800186E8 0380053C */  lui        $a1, %hi(g_ActiveMusicChannels)
    /* 8EEC 800186EC 9036A524 */  addiu      $a1, $a1, %lo(g_ActiveMusicChannels)
    /* 8EF0 800186F0 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 8EF4 800186F4 0480033C */  lui        $v1, %hi(D_80039AFC)
    /* 8EF8 800186F8 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* 8EFC 800186FC 01000224 */  addiu      $v0, $zero, 0x1
    /* 8F00 80018700 1000BFAF */  sw         $ra, 0x10($sp)
    /* 8F04 80018704 595A000C */  jal        Sound_MarkActiveChannelsVolumeDirty
    /* 8F08 80018708 FC9A62AC */   sw        $v0, %lo(D_80039AFC)($v1)
    /* 8F0C 8001870C 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 8F10 80018710 2866448C */  lw         $a0, %lo(g_pSavedMousicConfig)($v0)
    /* 8F14 80018714 00000000 */  nop
    /* 8F18 80018718 04008010 */  beqz       $a0, .L8001872C
    /* 8F1C 8001871C 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 8F20 80018720 D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
    /* 8F24 80018724 595A000C */  jal        Sound_MarkActiveChannelsVolumeDirty
    /* 8F28 80018728 00000000 */   nop
  .L8001872C:
    /* 8F2C 8001872C 6B5A000C */  jal        Sound_MarkScheduledSfxChannelsVolumeDirty
    /* 8F30 80018730 00000000 */   nop
    /* 8F34 80018734 1000BF8F */  lw         $ra, 0x10($sp)
    /* 8F38 80018738 00000000 */  nop
    /* 8F3C 8001873C 0800E003 */  jr         $ra
    /* 8F40 80018740 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_80_unk
