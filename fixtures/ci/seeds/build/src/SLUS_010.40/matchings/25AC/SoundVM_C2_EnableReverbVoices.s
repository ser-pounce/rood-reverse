nonmatching SoundVM_C2_EnableReverbVoices, 0x60

glabel SoundVM_C2_EnableReverbVoices
    /* CAAC 8001C2AC 64008294 */  lhu        $v0, 0x64($a0)
    /* CAB0 8001C2B0 00000000 */  nop
    /* CAB4 8001C2B4 09004014 */  bnez       $v0, .L8001C2DC
    /* CAB8 8001C2B8 0380033C */   lui       $v1, %hi(g_Sound_VoiceSchedulerState)
    /* CABC 8001C2BC 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* CAC0 8001C2C0 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* CAC4 8001C2C4 00000000 */  nop
    /* CAC8 8001C2C8 5000628C */  lw         $v0, 0x50($v1)
    /* CACC 8001C2CC 00000000 */  nop
    /* CAD0 8001C2D0 25104500 */  or         $v0, $v0, $a1
    /* CAD4 8001C2D4 BC700008 */  j          .L8001C2F0
    /* CAD8 8001C2D8 500062AC */   sw        $v0, 0x50($v1)
  .L8001C2DC:
    /* CADC 8001C2DC 90786324 */  addiu      $v1, $v1, %lo(g_Sound_VoiceSchedulerState)
    /* CAE0 8001C2E0 2000628C */  lw         $v0, 0x20($v1)
    /* CAE4 8001C2E4 00000000 */  nop
    /* CAE8 8001C2E8 25104500 */  or         $v0, $v0, $a1
    /* CAEC 8001C2EC 200062AC */  sw         $v0, 0x20($v1)
  .L8001C2F0:
    /* CAF0 8001C2F0 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* CAF4 8001C2F4 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* CAF8 8001C2F8 0800628C */  lw         $v0, 0x8($v1)
    /* CAFC 8001C2FC 00000000 */  nop
    /* CB00 8001C300 00014234 */  ori        $v0, $v0, 0x100
    /* CB04 8001C304 0800E003 */  jr         $ra
    /* CB08 8001C308 080062AC */   sw        $v0, 0x8($v1)
endlabel SoundVM_C2_EnableReverbVoices
