nonmatching SoundVM_C4_EnableNoiseVoices, 0x60

glabel SoundVM_C4_EnableNoiseVoices
    /* C908 8001C108 64008294 */  lhu        $v0, 0x64($a0)
    /* C90C 8001C10C 00000000 */  nop
    /* C910 8001C110 09004014 */  bnez       $v0, .L8001C138
    /* C914 8001C114 0380033C */   lui       $v1, %hi(g_Sound_VoiceSchedulerState)
    /* C918 8001C118 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* C91C 8001C11C 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* C920 8001C120 00000000 */  nop
    /* C924 8001C124 4C00628C */  lw         $v0, 0x4C($v1)
    /* C928 8001C128 00000000 */  nop
    /* C92C 8001C12C 25104500 */  or         $v0, $v0, $a1
    /* C930 8001C130 53700008 */  j          .L8001C14C
    /* C934 8001C134 4C0062AC */   sw        $v0, 0x4C($v1)
  .L8001C138:
    /* C938 8001C138 90786324 */  addiu      $v1, $v1, %lo(g_Sound_VoiceSchedulerState)
    /* C93C 8001C13C 1C00628C */  lw         $v0, 0x1C($v1)
    /* C940 8001C140 00000000 */  nop
    /* C944 8001C144 25104500 */  or         $v0, $v0, $a1
    /* C948 8001C148 1C0062AC */  sw         $v0, 0x1C($v1)
  .L8001C14C:
    /* C94C 8001C14C 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* C950 8001C150 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* C954 8001C154 0800628C */  lw         $v0, 0x8($v1)
    /* C958 8001C158 00000000 */  nop
    /* C95C 8001C15C 10014234 */  ori        $v0, $v0, 0x110
    /* C960 8001C160 0800E003 */  jr         $ra
    /* C964 8001C164 080062AC */   sw        $v0, 0x8($v1)
endlabel SoundVM_C4_EnableNoiseVoices
