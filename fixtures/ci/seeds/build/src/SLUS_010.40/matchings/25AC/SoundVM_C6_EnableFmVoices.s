nonmatching SoundVM_C6_EnableFmVoices, 0x74

glabel SoundVM_C6_EnableFmVoices
    /* C9D0 8001C1D0 64008294 */  lhu        $v0, 0x64($a0)
    /* C9D4 8001C1D4 00000000 */  nop
    /* C9D8 8001C1D8 09004014 */  bnez       $v0, .L8001C200
    /* C9DC 8001C1DC 0100033C */   lui       $v1, (0x10000 >> 16)
    /* C9E0 8001C1E0 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* C9E4 8001C1E4 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* C9E8 8001C1E8 00000000 */  nop
    /* C9EC 8001C1EC 5400628C */  lw         $v0, 0x54($v1)
    /* C9F0 8001C1F0 00000000 */  nop
    /* C9F4 8001C1F4 25104500 */  or         $v0, $v0, $a1
    /* C9F8 8001C1F8 8A700008 */  j          .L8001C228
    /* C9FC 8001C1FC 540062AC */   sw        $v0, 0x54($v1)
  .L8001C200:
    /* CA00 8001C200 3400828C */  lw         $v0, 0x34($a0)
    /* CA04 8001C204 00000000 */  nop
    /* CA08 8001C208 24104300 */  and        $v0, $v0, $v1
    /* CA0C 8001C20C 06004010 */  beqz       $v0, .L8001C228
    /* CA10 8001C210 0380033C */   lui       $v1, %hi(g_Sound_VoiceSchedulerState)
    /* CA14 8001C214 90786324 */  addiu      $v1, $v1, %lo(g_Sound_VoiceSchedulerState)
    /* CA18 8001C218 2400628C */  lw         $v0, 0x24($v1)
    /* CA1C 8001C21C 00000000 */  nop
    /* CA20 8001C220 25104500 */  or         $v0, $v0, $a1
    /* CA24 8001C224 240062AC */  sw         $v0, 0x24($v1)
  .L8001C228:
    /* CA28 8001C228 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* CA2C 8001C22C F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* CA30 8001C230 0800628C */  lw         $v0, 0x8($v1)
    /* CA34 8001C234 00000000 */  nop
    /* CA38 8001C238 00014234 */  ori        $v0, $v0, 0x100
    /* CA3C 8001C23C 0800E003 */  jr         $ra
    /* CA40 8001C240 080062AC */   sw        $v0, 0x8($v1)
endlabel SoundVM_C6_EnableFmVoices
