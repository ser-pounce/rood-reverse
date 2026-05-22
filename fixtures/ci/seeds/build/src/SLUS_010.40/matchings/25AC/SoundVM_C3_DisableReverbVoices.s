nonmatching SoundVM_C3_DisableReverbVoices, 0x60

glabel SoundVM_C3_DisableReverbVoices
    /* CB0C 8001C30C 64008294 */  lhu        $v0, 0x64($a0)
    /* CB10 8001C310 00000000 */  nop
    /* CB14 8001C314 09004014 */  bnez       $v0, .L8001C33C
    /* CB18 8001C318 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* CB1C 8001C31C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* CB20 8001C320 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* CB24 8001C324 00000000 */  nop
    /* CB28 8001C328 5000828C */  lw         $v0, 0x50($a0)
    /* CB2C 8001C32C 27180500 */  nor        $v1, $zero, $a1
    /* CB30 8001C330 24104300 */  and        $v0, $v0, $v1
    /* CB34 8001C334 D4700008 */  j          .L8001C350
    /* CB38 8001C338 500082AC */   sw        $v0, 0x50($a0)
  .L8001C33C:
    /* CB3C 8001C33C 90784224 */  addiu      $v0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* CB40 8001C340 2000438C */  lw         $v1, 0x20($v0)
    /* CB44 8001C344 27200500 */  nor        $a0, $zero, $a1
    /* CB48 8001C348 24186400 */  and        $v1, $v1, $a0
    /* CB4C 8001C34C 200043AC */  sw         $v1, 0x20($v0)
  .L8001C350:
    /* CB50 8001C350 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* CB54 8001C354 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* CB58 8001C358 0800628C */  lw         $v0, 0x8($v1)
    /* CB5C 8001C35C 00000000 */  nop
    /* CB60 8001C360 00014234 */  ori        $v0, $v0, 0x100
    /* CB64 8001C364 0800E003 */  jr         $ra
    /* CB68 8001C368 080062AC */   sw        $v0, 0x8($v1)
endlabel SoundVM_C3_DisableReverbVoices
