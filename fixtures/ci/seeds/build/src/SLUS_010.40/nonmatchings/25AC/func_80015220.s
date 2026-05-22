nonmatching func_80015220, 0x544

glabel func_80015220
    /* 5A20 80015220 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 5A24 80015224 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 5A28 80015228 90784324 */  addiu      $v1, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* 5A2C 8001522C 9078448C */  lw         $a0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 5A30 80015230 0480053C */  lui        $a1, %hi(D_80039B14)
    /* 5A34 80015234 3800BFAF */  sw         $ra, 0x38($sp)
    /* 5A38 80015238 3400B7AF */  sw         $s7, 0x34($sp)
    /* 5A3C 8001523C 3000B6AF */  sw         $s6, 0x30($sp)
    /* 5A40 80015240 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 5A44 80015244 2800B4AF */  sw         $s4, 0x28($sp)
    /* 5A48 80015248 2400B3AF */  sw         $s3, 0x24($sp)
    /* 5A4C 8001524C 2000B2AF */  sw         $s2, 0x20($sp)
    /* 5A50 80015250 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 5A54 80015254 1800B0AF */  sw         $s0, 0x18($sp)
    /* 5A58 80015258 1000628C */  lw         $v0, 0x10($v1)
    /* 5A5C 8001525C 149BA58C */  lw         $a1, %lo(D_80039B14)($a1)
    /* 5A60 80015260 25208200 */  or         $a0, $a0, $v0
    /* 5A64 80015264 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 5A68 80015268 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 5A6C 8001526C 1000A0AF */  sw         $zero, 0x10($sp)
    /* 5A70 80015270 0400628C */  lw         $v0, 0x4($v1)
    /* 5A74 80015274 1000638C */  lw         $v1, 0x10($v1)
    /* 5A78 80015278 00000000 */  nop
    /* 5A7C 8001527C 24104300 */  and        $v0, $v0, $v1
    /* 5A80 80015280 0C004014 */  bnez       $v0, .L800152B4
    /* 5A84 80015284 25908500 */   or        $s2, $a0, $a1
    /* 5A88 80015288 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 5A8C 8001528C 2866438C */  lw         $v1, %lo(g_pSavedMousicConfig)($v0)
    /* 5A90 80015290 00000000 */  nop
    /* 5A94 80015294 7E006010 */  beqz       $v1, .L80015490
    /* 5A98 80015298 0380103C */   lui       $s0, %hi(g_pActiveMusicConfig)
    /* 5A9C 8001529C 0400628C */  lw         $v0, 0x4($v1)
    /* 5AA0 800152A0 1000638C */  lw         $v1, 0x10($v1)
    /* 5AA4 800152A4 00000000 */  nop
    /* 5AA8 800152A8 24104300 */  and        $v0, $v0, $v1
    /* 5AAC 800152AC 04004010 */  beqz       $v0, .L800152C0
    /* 5AB0 800152B0 0380163C */   lui       $s6, %hi(g_pSavedMousicConfig)
  .L800152B4:
    /* 5AB4 800152B4 2054000C */  jal        func_80015080
    /* 5AB8 800152B8 21204002 */   addu      $a0, $s2, $zero
    /* 5ABC 800152BC 0380163C */  lui        $s6, %hi(g_pSavedMousicConfig)
  .L800152C0:
    /* 5AC0 800152C0 2866C48E */  lw         $a0, %lo(g_pSavedMousicConfig)($s6)
    /* 5AC4 800152C4 00000000 */  nop
    /* 5AC8 800152C8 70008010 */  beqz       $a0, .L8001548C
    /* 5ACC 800152CC 0480023C */   lui       $v0, %hi(g_Sound_GlobalFlags)
    /* 5AD0 800152D0 F89A5724 */  addiu      $s7, $v0, %lo(g_Sound_GlobalFlags)
    /* 5AD4 800152D4 0400E28E */  lw         $v0, 0x4($s7)
    /* 5AD8 800152D8 00000000 */  nop
    /* 5ADC 800152DC 00014230 */  andi       $v0, $v0, 0x100
    /* 5AE0 800152E0 04004010 */  beqz       $v0, .L800152F4
    /* 5AE4 800152E4 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 5AE8 800152E8 D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
    /* 5AEC 800152EC 7054000C */  jal        Sound_ApplyMasterFadeToChannelVolume
    /* 5AF0 800152F0 00000000 */   nop
  .L800152F4:
    /* 5AF4 800152F4 2866C58E */  lw         $a1, %lo(g_pSavedMousicConfig)($s6)
    /* 5AF8 800152F8 00000000 */  nop
    /* 5AFC 800152FC 0400A38C */  lw         $v1, 0x4($a1)
    /* 5B00 80015300 1400A28C */  lw         $v0, 0x14($a1)
    /* 5B04 80015304 0C00A48C */  lw         $a0, 0xC($a1)
    /* 5B08 80015308 0380153C */  lui        $s5, %hi(g_pActiveMusicConfig)
    /* 5B0C 8001530C 2078A5AE */  sw         $a1, %lo(g_pActiveMusicConfig)($s5)
    /* 5B10 80015310 24186200 */  and        $v1, $v1, $v0
    /* 5B14 80015314 24109200 */  and        $v0, $a0, $s2
    /* 5B18 80015318 27100200 */  nor        $v0, $zero, $v0
    /* 5B1C 8001531C 24806200 */  and        $s0, $v1, $v0
    /* 5B20 80015320 24200402 */  and        $a0, $s0, $a0
    /* 5B24 80015324 27101200 */  nor        $v0, $zero, $s2
    /* 5B28 80015328 0800A38C */  lw         $v1, 0x8($a1)
    /* 5B2C 8001532C 00000000 */  nop
    /* 5B30 80015330 24280302 */  and        $a1, $s0, $v1
    /* 5B34 80015334 1100A010 */  beqz       $a1, .L8001537C
    /* 5B38 80015338 24888200 */   and       $s1, $a0, $v0
    /* 5B3C 8001533C 21302002 */  addu       $a2, $s1, $zero
    /* 5B40 80015340 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* 5B44 80015344 D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* 5B48 80015348 5C53000C */  jal        func_80014D70
    /* 5B4C 8001534C 1000A727 */   addiu     $a3, $sp, 0x10
    /* 5B50 80015350 2078A48E */  lw         $a0, %lo(g_pActiveMusicConfig)($s5)
    /* 5B54 80015354 00000000 */  nop
    /* 5B58 80015358 0800828C */  lw         $v0, 0x8($a0)
    /* 5B5C 8001535C 00000000 */  nop
    /* 5B60 80015360 27100200 */  nor        $v0, $zero, $v0
    /* 5B64 80015364 24800202 */  and        $s0, $s0, $v0
    /* 5B68 80015368 0800828C */  lw         $v0, 0x8($a0)
    /* 5B6C 8001536C 1000838C */  lw         $v1, 0x10($a0)
    /* 5B70 80015370 27100200 */  nor        $v0, $zero, $v0
    /* 5B74 80015374 24186200 */  and        $v1, $v1, $v0
    /* 5B78 80015378 100083AC */  sw         $v1, 0x10($a0)
  .L8001537C:
    /* 5B7C 8001537C 0380023C */  lui        $v0, %hi(D_800366F0)
    /* 5B80 80015380 F0665424 */  addiu      $s4, $v0, %lo(D_800366F0)
    /* 5B84 80015384 0400858E */  lw         $a1, 0x4($s4)
    /* 5B88 80015388 1400828E */  lw         $v0, 0x14($s4)
    /* 5B8C 8001538C 0C00848E */  lw         $a0, 0xC($s4)
    /* 5B90 80015390 25183202 */  or         $v1, $s1, $s2
    /* 5B94 80015394 2078B4AE */  sw         $s4, %lo(g_pActiveMusicConfig)($s5)
    /* 5B98 80015398 2428A200 */  and        $a1, $a1, $v0
    /* 5B9C 8001539C 24108300 */  and        $v0, $a0, $v1
    /* 5BA0 800153A0 27100200 */  nor        $v0, $zero, $v0
    /* 5BA4 800153A4 2498A200 */  and        $s3, $a1, $v0
    /* 5BA8 800153A8 24206402 */  and        $a0, $s3, $a0
    /* 5BAC 800153AC 27180300 */  nor        $v1, $zero, $v1
    /* 5BB0 800153B0 0800828E */  lw         $v0, 0x8($s4)
    /* 5BB4 800153B4 00000000 */  nop
    /* 5BB8 800153B8 24286202 */  and        $a1, $s3, $v0
    /* 5BBC 800153BC 1100A010 */  beqz       $a1, .L80015404
    /* 5BC0 800153C0 24908300 */   and       $s2, $a0, $v1
    /* 5BC4 800153C4 0380043C */  lui        $a0, %hi(g_ActiveMusicChannels)
    /* 5BC8 800153C8 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 5BCC 800153CC 21304002 */  addu       $a2, $s2, $zero
    /* 5BD0 800153D0 5C53000C */  jal        func_80014D70
    /* 5BD4 800153D4 1000A727 */   addiu     $a3, $sp, 0x10
    /* 5BD8 800153D8 2078A48E */  lw         $a0, %lo(g_pActiveMusicConfig)($s5)
    /* 5BDC 800153DC 00000000 */  nop
    /* 5BE0 800153E0 0800828C */  lw         $v0, 0x8($a0)
    /* 5BE4 800153E4 00000000 */  nop
    /* 5BE8 800153E8 27100200 */  nor        $v0, $zero, $v0
    /* 5BEC 800153EC 24986202 */  and        $s3, $s3, $v0
    /* 5BF0 800153F0 0800828C */  lw         $v0, 0x8($a0)
    /* 5BF4 800153F4 1000838C */  lw         $v1, 0x10($a0)
    /* 5BF8 800153F8 27100200 */  nor        $v0, $zero, $v0
    /* 5BFC 800153FC 24186200 */  and        $v1, $v1, $v0
    /* 5C00 80015400 100083AC */  sw         $v1, 0x10($a0)
  .L80015404:
    /* 5C04 80015404 0C000012 */  beqz       $s0, .L80015438
    /* 5C08 80015408 21280002 */   addu      $a1, $s0, $zero
    /* 5C0C 8001540C 27301200 */  nor        $a2, $zero, $s2
    /* 5C10 80015410 24302602 */  and        $a2, $s1, $a2
    /* 5C14 80015414 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* 5C18 80015418 D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* 5C1C 8001541C 2866C28E */  lw         $v0, %lo(g_pSavedMousicConfig)($s6)
    /* 5C20 80015420 1000A727 */  addiu      $a3, $sp, 0x10
    /* 5C24 80015424 5C53000C */  jal        func_80014D70
    /* 5C28 80015428 2078A2AE */   sw        $v0, %lo(g_pActiveMusicConfig)($s5)
    /* 5C2C 8001542C 2078A28E */  lw         $v0, %lo(g_pActiveMusicConfig)($s5)
    /* 5C30 80015430 2078B4AE */  sw         $s4, %lo(g_pActiveMusicConfig)($s5)
    /* 5C34 80015434 100040AC */  sw         $zero, 0x10($v0)
  .L80015438:
    /* 5C38 80015438 09006012 */  beqz       $s3, .L80015460
    /* 5C3C 8001543C 0380043C */   lui       $a0, %hi(g_ActiveMusicChannels)
    /* 5C40 80015440 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 5C44 80015444 21286002 */  addu       $a1, $s3, $zero
    /* 5C48 80015448 21304002 */  addu       $a2, $s2, $zero
    /* 5C4C 8001544C 5C53000C */  jal        func_80014D70
    /* 5C50 80015450 1000A727 */   addiu     $a3, $sp, 0x10
    /* 5C54 80015454 2078A28E */  lw         $v0, %lo(g_pActiveMusicConfig)($s5)
    /* 5C58 80015458 00000000 */  nop
    /* 5C5C 8001545C 100040AC */  sw         $zero, 0x10($v0)
  .L80015460:
    /* 5C60 80015460 0400E28E */  lw         $v0, 0x4($s7)
    /* 5C64 80015464 00000000 */  nop
    /* 5C68 80015468 00014230 */  andi       $v0, $v0, 0x100
    /* 5C6C 8001546C 32004010 */  beqz       $v0, .L80015538
    /* 5C70 80015470 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 5C74 80015474 2866C48E */  lw         $a0, %lo(g_pSavedMousicConfig)($s6)
    /* 5C78 80015478 D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
    /* 5C7C 8001547C 8454000C */  jal        Sound_RestoreChannelVolumeFromMasterFade
    /* 5C80 80015480 00000000 */   nop
    /* 5C84 80015484 4F550008 */  j          .L8001553C
    /* 5C88 80015488 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
  .L8001548C:
    /* 5C8C 8001548C 0380103C */  lui        $s0, %hi(g_pActiveMusicConfig)
  .L80015490:
    /* 5C90 80015490 2078058E */  lw         $a1, %lo(g_pActiveMusicConfig)($s0)
    /* 5C94 80015494 00000000 */  nop
    /* 5C98 80015498 0400A38C */  lw         $v1, 0x4($a1)
    /* 5C9C 8001549C 1400A28C */  lw         $v0, 0x14($a1)
    /* 5CA0 800154A0 0C00A48C */  lw         $a0, 0xC($a1)
    /* 5CA4 800154A4 24186200 */  and        $v1, $v1, $v0
    /* 5CA8 800154A8 24109200 */  and        $v0, $a0, $s2
    /* 5CAC 800154AC 27100200 */  nor        $v0, $zero, $v0
    /* 5CB0 800154B0 24986200 */  and        $s3, $v1, $v0
    /* 5CB4 800154B4 24206402 */  and        $a0, $s3, $a0
    /* 5CB8 800154B8 27101200 */  nor        $v0, $zero, $s2
    /* 5CBC 800154BC 0800A38C */  lw         $v1, 0x8($a1)
    /* 5CC0 800154C0 00000000 */  nop
    /* 5CC4 800154C4 24286302 */  and        $a1, $s3, $v1
    /* 5CC8 800154C8 1100A010 */  beqz       $a1, .L80015510
    /* 5CCC 800154CC 24908200 */   and       $s2, $a0, $v0
    /* 5CD0 800154D0 0380043C */  lui        $a0, %hi(g_ActiveMusicChannels)
    /* 5CD4 800154D4 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 5CD8 800154D8 21304002 */  addu       $a2, $s2, $zero
    /* 5CDC 800154DC 5C53000C */  jal        func_80014D70
    /* 5CE0 800154E0 1000A727 */   addiu     $a3, $sp, 0x10
    /* 5CE4 800154E4 2078048E */  lw         $a0, %lo(g_pActiveMusicConfig)($s0)
    /* 5CE8 800154E8 00000000 */  nop
    /* 5CEC 800154EC 0800828C */  lw         $v0, 0x8($a0)
    /* 5CF0 800154F0 00000000 */  nop
    /* 5CF4 800154F4 27100200 */  nor        $v0, $zero, $v0
    /* 5CF8 800154F8 24986202 */  and        $s3, $s3, $v0
    /* 5CFC 800154FC 0800828C */  lw         $v0, 0x8($a0)
    /* 5D00 80015500 1000838C */  lw         $v1, 0x10($a0)
    /* 5D04 80015504 27100200 */  nor        $v0, $zero, $v0
    /* 5D08 80015508 24186200 */  and        $v1, $v1, $v0
    /* 5D0C 8001550C 100083AC */  sw         $v1, 0x10($a0)
  .L80015510:
    /* 5D10 80015510 09006012 */  beqz       $s3, .L80015538
    /* 5D14 80015514 0380043C */   lui       $a0, %hi(g_ActiveMusicChannels)
    /* 5D18 80015518 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 5D1C 8001551C 21286002 */  addu       $a1, $s3, $zero
    /* 5D20 80015520 21304002 */  addu       $a2, $s2, $zero
    /* 5D24 80015524 5C53000C */  jal        func_80014D70
    /* 5D28 80015528 1000A727 */   addiu     $a3, $sp, 0x10
    /* 5D2C 8001552C 2078028E */  lw         $v0, %lo(g_pActiveMusicConfig)($s0)
    /* 5D30 80015530 00000000 */  nop
    /* 5D34 80015534 100040AC */  sw         $zero, 0x10($v0)
  .L80015538:
    /* 5D38 80015538 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
  .L8001553C:
    /* 5D3C 8001553C 90784424 */  addiu      $a0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* 5D40 80015540 9078438C */  lw         $v1, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 5D44 80015544 0800828C */  lw         $v0, 0x8($a0)
    /* 5D48 80015548 00000000 */  nop
    /* 5D4C 8001554C 24986200 */  and        $s3, $v1, $v0
    /* 5D50 80015550 1D006012 */  beqz       $s3, .L800155C8
    /* 5D54 80015554 0380023C */   lui       $v0, %hi(D_80035910)
    /* 5D58 80015558 00101224 */  addiu      $s2, $zero, 0x1000
    /* 5D5C 8001555C 10595124 */  addiu      $s1, $v0, %lo(D_80035910)
    /* 5D60 80015560 1000A28F */  lw         $v0, 0x10($sp)
    /* 5D64 80015564 0400838C */  lw         $v1, 0x4($a0)
    /* 5D68 80015568 34003026 */  addiu      $s0, $s1, 0x34
    /* 5D6C 8001556C 25104300 */  or         $v0, $v0, $v1
    /* 5D70 80015570 1000A2AF */  sw         $v0, 0x10($sp)
  .L80015574:
    /* 5D74 80015574 24107202 */  and        $v0, $s3, $s2
    /* 5D78 80015578 0D004010 */  beqz       $v0, .L800155B0
    /* 5D7C 8001557C 21202002 */   addu      $a0, $s1, $zero
    /* 5D80 80015580 F351000C */  jal        func_800147CC
    /* 5D84 80015584 21284002 */   addu      $a1, $s2, $zero
    /* 5D88 80015588 C400028E */  lw         $v0, 0xC4($s0)
    /* 5D8C 8001558C 00000000 */  nop
    /* 5D90 80015590 06004010 */  beqz       $v0, .L800155AC
    /* 5D94 80015594 27101200 */   nor       $v0, $zero, $s2
    /* 5D98 80015598 C000048E */  lw         $a0, 0xC0($s0)
    /* 5D9C 8001559C 0000068E */  lw         $a2, 0x0($s0)
    /* 5DA0 800155A0 6C4F000C */  jal        SetVoiceParamsByFlags
    /* 5DA4 800155A4 F4002526 */   addiu     $a1, $s1, 0xF4
    /* 5DA8 800155A8 27101200 */  nor        $v0, $zero, $s2
  .L800155AC:
    /* 5DAC 800155AC 24986202 */  and        $s3, $s3, $v0
  .L800155B0:
    /* 5DB0 800155B0 40901200 */  sll        $s2, $s2, 1
    /* 5DB4 800155B4 10011026 */  addiu      $s0, $s0, 0x110
    /* 5DB8 800155B8 EEFF6016 */  bnez       $s3, .L80015574
    /* 5DBC 800155BC 10013126 */   addiu     $s1, $s1, 0x110
    /* 5DC0 800155C0 0380023C */  lui        $v0, %hi(D_80037894)
    /* 5DC4 800155C4 947840AC */  sw         $zero, %lo(D_80037894)($v0)
  .L800155C8:
    /* 5DC8 800155C8 0480023C */  lui        $v0, %hi(g_Sound_GlobalFlags)
    /* 5DCC 800155CC F89A5024 */  addiu      $s0, $v0, %lo(g_Sound_GlobalFlags)
    /* 5DD0 800155D0 0800138E */  lw         $s3, 0x8($s0)
    /* 5DD4 800155D4 00000000 */  nop
    /* 5DD8 800155D8 80006232 */  andi       $v0, $s3, 0x80
    /* 5DDC 800155DC 0D004010 */  beqz       $v0, .L80015614
    /* 5DE0 800155E0 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* 5DE4 800155E4 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 5DE8 800155E8 00000000 */  nop
    /* 5DEC 800155EC 5800448C */  lw         $a0, 0x58($v0)
    /* 5DF0 800155F0 00000000 */  nop
    /* 5DF4 800155F4 00210400 */  sll        $a0, $a0, 4
    /* 5DF8 800155F8 03240400 */  sra        $a0, $a0, 16
    /* 5DFC 800155FC 417D000C */  jal        SpuSetReverbModeDepth
    /* 5E00 80015600 21288000 */   addu      $a1, $a0, $zero
    /* 5E04 80015604 0800028E */  lw         $v0, 0x8($s0)
    /* 5E08 80015608 7FFF0324 */  addiu      $v1, $zero, -0x81
    /* 5E0C 8001560C 24104300 */  and        $v0, $v0, $v1
    /* 5E10 80015610 080002AE */  sw         $v0, 0x8($s0)
  .L80015614:
    /* 5E14 80015614 10006232 */  andi       $v0, $s3, 0x10
    /* 5E18 80015618 14004010 */  beqz       $v0, .L8001566C
    /* 5E1C 8001561C 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 5E20 80015620 9078438C */  lw         $v1, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 5E24 80015624 00000000 */  nop
    /* 5E28 80015628 04006010 */  beqz       $v1, .L8001563C
    /* 5E2C 8001562C 90784224 */   addiu     $v0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* 5E30 80015630 28004494 */  lhu        $a0, 0x28($v0)
    /* 5E34 80015634 93550008 */  j          .L8001564C
    /* 5E38 80015638 00000000 */   nop
  .L8001563C:
    /* 5E3C 8001563C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 5E40 80015640 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 5E44 80015644 00000000 */  nop
    /* 5E48 80015648 72004494 */  lhu        $a0, 0x72($v0)
  .L8001564C:
    /* 5E4C 8001564C B979000C */  jal        SpuSetNoiseClock
    /* 5E50 80015650 00000000 */   nop
    /* 5E54 80015654 0480023C */  lui        $v0, %hi(g_Sound_GlobalFlags)
    /* 5E58 80015658 F89A4224 */  addiu      $v0, $v0, %lo(g_Sound_GlobalFlags)
    /* 5E5C 8001565C 0800438C */  lw         $v1, 0x8($v0)
    /* 5E60 80015660 EFFF0424 */  addiu      $a0, $zero, -0x11
    /* 5E64 80015664 24186400 */  and        $v1, $v1, $a0
    /* 5E68 80015668 080043AC */  sw         $v1, 0x8($v0)
  .L8001566C:
    /* 5E6C 8001566C 00016232 */  andi       $v0, $s3, 0x100
    /* 5E70 80015670 2B004010 */  beqz       $v0, .L80015720
    /* 5E74 80015674 0380113C */   lui       $s1, %hi(g_Sound_VoiceSchedulerState)
    /* 5E78 80015678 90783126 */  addiu      $s1, $s1, %lo(g_Sound_VoiceSchedulerState)
    /* 5E7C 8001567C 0380133C */  lui        $s3, %hi(g_pSavedMousicConfig)
    /* 5E80 80015680 0380143C */  lui        $s4, %hi(g_pActiveMusicConfig)
    /* 5E84 80015684 0480103C */  lui        $s0, %hi(g_Sound_VoiceModeFlags + 0x4)
    /* 5E88 80015688 DC9B1026 */  addiu      $s0, $s0, %lo(g_Sound_VoiceModeFlags + 0x4)
    /* 5E8C 8001568C 1C00278E */  lw         $a3, 0x1C($s1)
    /* 5E90 80015690 2866628E */  lw         $v0, %lo(g_pSavedMousicConfig)($s3)
    /* 5E94 80015694 2078838E */  lw         $v1, %lo(g_pActiveMusicConfig)($s4)
    /* 5E98 80015698 4C00458C */  lw         $a1, 0x4C($v0)
    /* 5E9C 8001569C 4C00668C */  lw         $a2, 0x4C($v1)
    /* 5EA0 800156A0 5C56000C */  jal        func_80015970
    /* 5EA4 800156A4 21200002 */   addu      $a0, $s0, $zero
    /* 5EA8 800156A8 FCFF1226 */  addiu      $s2, $s0, -0x4
    /* 5EAC 800156AC 2000278E */  lw         $a3, 0x20($s1)
    /* 5EB0 800156B0 2866628E */  lw         $v0, %lo(g_pSavedMousicConfig)($s3)
    /* 5EB4 800156B4 2078838E */  lw         $v1, %lo(g_pActiveMusicConfig)($s4)
    /* 5EB8 800156B8 5000458C */  lw         $a1, 0x50($v0)
    /* 5EBC 800156BC 5000668C */  lw         $a2, 0x50($v1)
    /* 5EC0 800156C0 5C56000C */  jal        func_80015970
    /* 5EC4 800156C4 21204002 */   addu      $a0, $s2, $zero
    /* 5EC8 800156C8 2400278E */  lw         $a3, 0x24($s1)
    /* 5ECC 800156CC 2866628E */  lw         $v0, %lo(g_pSavedMousicConfig)($s3)
    /* 5ED0 800156D0 2078838E */  lw         $v1, %lo(g_pActiveMusicConfig)($s4)
    /* 5ED4 800156D4 5400458C */  lw         $a1, 0x54($v0)
    /* 5ED8 800156D8 5400668C */  lw         $a2, 0x54($v1)
    /* 5EDC 800156DC 5C56000C */  jal        func_80015970
    /* 5EE0 800156E0 04000426 */   addiu     $a0, $s0, 0x4
    /* 5EE4 800156E4 FCFF048E */  lw         $a0, -0x4($s0)
    /* 5EE8 800156E8 C14E000C */  jal        SetVoiceReverbMode
    /* 5EEC 800156EC 00000000 */   nop
    /* 5EF0 800156F0 0400448E */  lw         $a0, 0x4($s2)
    /* 5EF4 800156F4 C84E000C */  jal        SetVoiceNoiseMode
    /* 5EF8 800156F8 00000000 */   nop
    /* 5EFC 800156FC 0800448E */  lw         $a0, 0x8($s2)
    /* 5F00 80015700 CF4E000C */  jal        SetVoiceFmMode
    /* 5F04 80015704 00000000 */   nop
    /* 5F08 80015708 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* 5F0C 8001570C F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 5F10 80015710 0800628C */  lw         $v0, 0x8($v1)
    /* 5F14 80015714 FFFE0424 */  addiu      $a0, $zero, -0x101
    /* 5F18 80015718 24104400 */  and        $v0, $v0, $a0
    /* 5F1C 8001571C 080062AC */  sw         $v0, 0x8($v1)
  .L80015720:
    /* 5F20 80015720 1000A48F */  lw         $a0, 0x10($sp)
    /* 5F24 80015724 00000000 */  nop
    /* 5F28 80015728 03008010 */  beqz       $a0, .L80015738
    /* 5F2C 8001572C 00000000 */   nop
    /* 5F30 80015730 B34E000C */  jal        SetVoiceKeyOn
    /* 5F34 80015734 00000000 */   nop
  .L80015738:
    /* 5F38 80015738 3800BF8F */  lw         $ra, 0x38($sp)
    /* 5F3C 8001573C 3400B78F */  lw         $s7, 0x34($sp)
    /* 5F40 80015740 3000B68F */  lw         $s6, 0x30($sp)
    /* 5F44 80015744 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 5F48 80015748 2800B48F */  lw         $s4, 0x28($sp)
    /* 5F4C 8001574C 2400B38F */  lw         $s3, 0x24($sp)
    /* 5F50 80015750 2000B28F */  lw         $s2, 0x20($sp)
    /* 5F54 80015754 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 5F58 80015758 1800B08F */  lw         $s0, 0x18($sp)
    /* 5F5C 8001575C 0800E003 */  jr         $ra
    /* 5F60 80015760 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_80015220
