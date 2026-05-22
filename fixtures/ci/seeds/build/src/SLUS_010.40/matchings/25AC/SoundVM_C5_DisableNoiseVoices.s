nonmatching SoundVM_C5_DisableNoiseVoices, 0x68

glabel SoundVM_C5_DisableNoiseVoices
    /* C968 8001C168 21308000 */  addu       $a2, $a0, $zero
    /* C96C 8001C16C 6400C294 */  lhu        $v0, 0x64($a2)
    /* C970 8001C170 00000000 */  nop
    /* C974 8001C174 09004014 */  bnez       $v0, .L8001C19C
    /* C978 8001C178 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* C97C 8001C17C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* C980 8001C180 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* C984 8001C184 00000000 */  nop
    /* C988 8001C188 4C00828C */  lw         $v0, 0x4C($a0)
    /* C98C 8001C18C 27180500 */  nor        $v1, $zero, $a1
    /* C990 8001C190 24104300 */  and        $v0, $v0, $v1
    /* C994 8001C194 6C700008 */  j          .L8001C1B0
    /* C998 8001C198 4C0082AC */   sw        $v0, 0x4C($a0)
  .L8001C19C:
    /* C99C 8001C19C 90784224 */  addiu      $v0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* C9A0 8001C1A0 1C00438C */  lw         $v1, 0x1C($v0)
    /* C9A4 8001C1A4 27200500 */  nor        $a0, $zero, $a1
    /* C9A8 8001C1A8 24186400 */  and        $v1, $v1, $a0
    /* C9AC 8001C1AC 1C0043AC */  sw         $v1, 0x1C($v0)
  .L8001C1B0:
    /* C9B0 8001C1B0 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* C9B4 8001C1B4 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* C9B8 8001C1B8 0800628C */  lw         $v0, 0x8($v1)
    /* C9BC 8001C1BC 00000000 */  nop
    /* C9C0 8001C1C0 10014234 */  ori        $v0, $v0, 0x110
    /* C9C4 8001C1C4 080062AC */  sw         $v0, 0x8($v1)
    /* C9C8 8001C1C8 0800E003 */  jr         $ra
    /* C9CC 8001C1CC CC00C0A4 */   sh        $zero, 0xCC($a2)
endlabel SoundVM_C5_DisableNoiseVoices
