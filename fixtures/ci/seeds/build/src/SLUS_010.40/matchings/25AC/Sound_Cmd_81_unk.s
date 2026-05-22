nonmatching Sound_Cmd_81_unk, 0x60

glabel Sound_Cmd_81_unk
    /* 8F44 80018744 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 8F48 80018748 0380053C */  lui        $a1, %hi(g_ActiveMusicChannels)
    /* 8F4C 8001874C 9036A524 */  addiu      $a1, $a1, %lo(g_ActiveMusicChannels)
    /* 8F50 80018750 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 8F54 80018754 0480033C */  lui        $v1, %hi(D_80039AFC)
    /* 8F58 80018758 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* 8F5C 8001875C 02000224 */  addiu      $v0, $zero, 0x2
    /* 8F60 80018760 1000BFAF */  sw         $ra, 0x10($sp)
    /* 8F64 80018764 595A000C */  jal        Sound_MarkActiveChannelsVolumeDirty
    /* 8F68 80018768 FC9A62AC */   sw        $v0, %lo(D_80039AFC)($v1)
    /* 8F6C 8001876C 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 8F70 80018770 2866448C */  lw         $a0, %lo(g_pSavedMousicConfig)($v0)
    /* 8F74 80018774 00000000 */  nop
    /* 8F78 80018778 04008010 */  beqz       $a0, .L8001878C
    /* 8F7C 8001877C 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 8F80 80018780 D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
    /* 8F84 80018784 595A000C */  jal        Sound_MarkActiveChannelsVolumeDirty
    /* 8F88 80018788 00000000 */   nop
  .L8001878C:
    /* 8F8C 8001878C 6B5A000C */  jal        Sound_MarkScheduledSfxChannelsVolumeDirty
    /* 8F90 80018790 00000000 */   nop
    /* 8F94 80018794 1000BF8F */  lw         $ra, 0x10($sp)
    /* 8F98 80018798 00000000 */  nop
    /* 8F9C 8001879C 0800E003 */  jr         $ra
    /* 8FA0 800187A0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_81_unk
