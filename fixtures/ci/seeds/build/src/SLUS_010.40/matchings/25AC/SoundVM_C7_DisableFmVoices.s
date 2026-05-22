nonmatching SoundVM_C7_DisableFmVoices, 0x68

glabel SoundVM_C7_DisableFmVoices
    /* CA44 8001C244 21308000 */  addu       $a2, $a0, $zero
    /* CA48 8001C248 6400C294 */  lhu        $v0, 0x64($a2)
    /* CA4C 8001C24C 00000000 */  nop
    /* CA50 8001C250 09004014 */  bnez       $v0, .L8001C278
    /* CA54 8001C254 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* CA58 8001C258 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* CA5C 8001C25C 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* CA60 8001C260 00000000 */  nop
    /* CA64 8001C264 5400828C */  lw         $v0, 0x54($a0)
    /* CA68 8001C268 27180500 */  nor        $v1, $zero, $a1
    /* CA6C 8001C26C 24104300 */  and        $v0, $v0, $v1
    /* CA70 8001C270 A3700008 */  j          .L8001C28C
    /* CA74 8001C274 540082AC */   sw        $v0, 0x54($a0)
  .L8001C278:
    /* CA78 8001C278 90784224 */  addiu      $v0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* CA7C 8001C27C 2400438C */  lw         $v1, 0x24($v0)
    /* CA80 8001C280 27200500 */  nor        $a0, $zero, $a1
    /* CA84 8001C284 24186400 */  and        $v1, $v1, $a0
    /* CA88 8001C288 240043AC */  sw         $v1, 0x24($v0)
  .L8001C28C:
    /* CA8C 8001C28C 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* CA90 8001C290 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* CA94 8001C294 0800628C */  lw         $v0, 0x8($v1)
    /* CA98 8001C298 00000000 */  nop
    /* CA9C 8001C29C 00014234 */  ori        $v0, $v0, 0x100
    /* CAA0 8001C2A0 080062AC */  sw         $v0, 0x8($v1)
    /* CAA4 8001C2A4 0800E003 */  jr         $ra
    /* CAA8 8001C2A8 CE00C0A4 */   sh        $zero, 0xCE($a2)
endlabel SoundVM_C7_DisableFmVoices
