nonmatching func_80019A58, 0x56C

glabel func_80019A58
    /* A258 80019A58 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* A25C 80019A5C 00F2043C */  lui        $a0, (0xF2000002 >> 16)
    /* A260 80019A60 02008434 */  ori        $a0, $a0, (0xF2000002 & 0xFFFF)
    /* A264 80019A64 2800BFAF */  sw         $ra, 0x28($sp)
    /* A268 80019A68 2400B5AF */  sw         $s5, 0x24($sp)
    /* A26C 80019A6C 2000B4AF */  sw         $s4, 0x20($sp)
    /* A270 80019A70 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* A274 80019A74 1800B2AF */  sw         $s2, 0x18($sp)
    /* A278 80019A78 1400B1AF */  sw         $s1, 0x14($sp)
    /* A27C 80019A7C B09A000C */  jal        GetRCnt
    /* A280 80019A80 1000B0AF */   sw        $s0, 0x10($sp)
    /* A284 80019A84 21A84000 */  addu       $s5, $v0, $zero
    /* A288 80019A88 0380043C */  lui        $a0, %hi(D_8002F54C)
    /* A28C 80019A8C 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* A290 80019A90 4CF58294 */  lhu        $v0, %lo(D_8002F54C)($a0)
    /* A294 80019A94 F89A638C */  lw         $v1, %lo(g_Sound_GlobalFlags)($v1)
    /* A298 80019A98 01004224 */  addiu      $v0, $v0, 0x1
    /* A29C 80019A9C 4CF582A4 */  sh         $v0, %lo(D_8002F54C)($a0)
    /* A2A0 80019AA0 00116230 */  andi       $v0, $v1, 0x1100
    /* A2A4 80019AA4 40004010 */  beqz       $v0, .L80019BA8
    /* A2A8 80019AA8 00016230 */   andi      $v0, $v1, 0x100
    /* A2AC 80019AAC 16004010 */  beqz       $v0, .L80019B08
    /* A2B0 80019AB0 00606230 */   andi      $v0, $v1, 0x6000
    /* A2B4 80019AB4 0C004010 */  beqz       $v0, .L80019AE8
    /* A2B8 80019AB8 0380023C */   lui       $v0, %hi(g_pSavedMousicConfig)
    /* A2BC 80019ABC 2866428C */  lw         $v0, %lo(g_pSavedMousicConfig)($v0)
    /* A2C0 80019AC0 00000000 */  nop
    /* A2C4 80019AC4 1000438C */  lw         $v1, 0x10($v0)
    /* A2C8 80019AC8 2C00458C */  lw         $a1, 0x2C($v0)
    /* A2CC 80019ACC 1400448C */  lw         $a0, 0x14($v0)
    /* A2D0 80019AD0 2130A000 */  addu       $a2, $a1, $zero
    /* A2D4 80019AD4 24186500 */  and        $v1, $v1, $a1
    /* A2D8 80019AD8 24208600 */  and        $a0, $a0, $a2
    /* A2DC 80019ADC 100043AC */  sw         $v1, 0x10($v0)
    /* A2E0 80019AE0 BE660008 */  j          .L80019AF8
    /* A2E4 80019AE4 140044AC */   sw        $a0, 0x14($v0)
  .L80019AE8:
    /* A2E8 80019AE8 2866428C */  lw         $v0, %lo(g_pSavedMousicConfig)($v0)
    /* A2EC 80019AEC 00000000 */  nop
    /* A2F0 80019AF0 100040AC */  sw         $zero, 0x10($v0)
    /* A2F4 80019AF4 140040AC */  sw         $zero, 0x14($v0)
  .L80019AF8:
    /* A2F8 80019AF8 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* A2FC 80019AFC 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* A300 80019B00 DF660008 */  j          .L80019B7C
    /* A304 80019B04 00000000 */   nop
  .L80019B08:
    /* A308 80019B08 00066230 */  andi       $v0, $v1, 0x600
    /* A30C 80019B0C 0F004010 */  beqz       $v0, .L80019B4C
    /* A310 80019B10 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* A314 80019B14 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* A318 80019B18 00000000 */  nop
    /* A31C 80019B1C 2C00648C */  lw         $a0, 0x2C($v1)
    /* A320 80019B20 3000658C */  lw         $a1, 0x30($v1)
    /* A324 80019B24 1000628C */  lw         $v0, 0x10($v1)
    /* A328 80019B28 25208500 */  or         $a0, $a0, $a1
    /* A32C 80019B2C 24104400 */  and        $v0, $v0, $a0
    /* A330 80019B30 2C00648C */  lw         $a0, 0x2C($v1)
    /* A334 80019B34 100062AC */  sw         $v0, 0x10($v1)
    /* A338 80019B38 1400628C */  lw         $v0, 0x14($v1)
    /* A33C 80019B3C 25208500 */  or         $a0, $a0, $a1
    /* A340 80019B40 24104400 */  and        $v0, $v0, $a0
    /* A344 80019B44 DD660008 */  j          .L80019B74
    /* A348 80019B48 140062AC */   sw        $v0, 0x14($v1)
  .L80019B4C:
    /* A34C 80019B4C 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* A350 80019B50 00000000 */  nop
    /* A354 80019B54 1000438C */  lw         $v1, 0x10($v0)
    /* A358 80019B58 3000458C */  lw         $a1, 0x30($v0)
    /* A35C 80019B5C 1400448C */  lw         $a0, 0x14($v0)
    /* A360 80019B60 2130A000 */  addu       $a2, $a1, $zero
    /* A364 80019B64 24186500 */  and        $v1, $v1, $a1
    /* A368 80019B68 24208600 */  and        $a0, $a0, $a2
    /* A36C 80019B6C 100043AC */  sw         $v1, 0x10($v0)
    /* A370 80019B70 140044AC */  sw         $a0, 0x14($v0)
  .L80019B74:
    /* A374 80019B74 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* A378 80019B78 2866448C */  lw         $a0, %lo(g_pSavedMousicConfig)($v0)
  .L80019B7C:
    /* A37C 80019B7C 00000000 */  nop
    /* A380 80019B80 2C00828C */  lw         $v0, 0x2C($a0)
    /* A384 80019B84 1000838C */  lw         $v1, 0x10($a0)
    /* A388 80019B88 27100200 */  nor        $v0, $zero, $v0
    /* A38C 80019B8C 24186200 */  and        $v1, $v1, $v0
    /* A390 80019B90 2C00828C */  lw         $v0, 0x2C($a0)
    /* A394 80019B94 100083AC */  sw         $v1, 0x10($a0)
    /* A398 80019B98 1400838C */  lw         $v1, 0x14($a0)
    /* A39C 80019B9C 27100200 */  nor        $v0, $zero, $v0
    /* A3A0 80019BA0 24186200 */  and        $v1, $v1, $v0
    /* A3A4 80019BA4 140083AC */  sw         $v1, 0x14($a0)
  .L80019BA8:
    /* A3A8 80019BA8 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* A3AC 80019BAC 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* A3B0 80019BB0 00000000 */  nop
    /* A3B4 80019BB4 1800428C */  lw         $v0, 0x18($v0)
    /* A3B8 80019BB8 00000000 */  nop
    /* A3BC 80019BBC 0D004014 */  bnez       $v0, .L80019BF4
    /* A3C0 80019BC0 0380023C */   lui       $v0, %hi(D_8003789C)
    /* A3C4 80019BC4 9C78428C */  lw         $v0, %lo(D_8003789C)($v0)
    /* A3C8 80019BC8 00000000 */  nop
    /* A3CC 80019BCC 09004014 */  bnez       $v0, .L80019BF4
    /* A3D0 80019BD0 0380023C */   lui       $v0, %hi(g_pSavedMousicConfig)
    /* A3D4 80019BD4 2866428C */  lw         $v0, %lo(g_pSavedMousicConfig)($v0)
    /* A3D8 80019BD8 00000000 */  nop
    /* A3DC 80019BDC 25004010 */  beqz       $v0, .L80019C74
    /* A3E0 80019BE0 00000000 */   nop
    /* A3E4 80019BE4 1800428C */  lw         $v0, 0x18($v0)
    /* A3E8 80019BE8 00000000 */  nop
    /* A3EC 80019BEC 03004010 */  beqz       $v0, .L80019BFC
    /* A3F0 80019BF0 0380103C */   lui       $s0, %hi(g_pSavedMousicConfig)
  .L80019BF4:
    /* A3F4 80019BF4 F155000C */  jal        Sound_ProcessKeyOffRequests
    /* A3F8 80019BF8 0380103C */   lui       $s0, %hi(g_pSavedMousicConfig)
  .L80019BFC:
    /* A3FC 80019BFC 2866048E */  lw         $a0, %lo(g_pSavedMousicConfig)($s0)
    /* A400 80019C00 00000000 */  nop
    /* A404 80019C04 1C008010 */  beqz       $a0, .L80019C78
    /* A408 80019C08 0380023C */   lui       $v0, %hi(D_80037788)
    /* A40C 80019C0C 0400828C */  lw         $v0, 0x4($a0)
    /* A410 80019C10 00000000 */  nop
    /* A414 80019C14 03004014 */  bnez       $v0, .L80019C24
    /* A418 80019C18 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* A41C 80019C1C 1D670008 */  j          .L80019C74
    /* A420 80019C20 286600AE */   sw        $zero, %lo(g_pSavedMousicConfig)($s0)
  .L80019C24:
    /* A424 80019C24 2078458C */  lw         $a1, %lo(g_pActiveMusicConfig)($v0)
    /* A428 80019C28 00000000 */  nop
    /* A42C 80019C2C 0400A28C */  lw         $v0, 0x4($a1)
    /* A430 80019C30 1C00A38C */  lw         $v1, 0x1C($a1)
    /* A434 80019C34 00000000 */  nop
    /* A438 80019C38 25104300 */  or         $v0, $v0, $v1
    /* A43C 80019C3C 0E004014 */  bnez       $v0, .L80019C78
    /* A440 80019C40 0380023C */   lui       $v0, %hi(D_80037788)
    /* A444 80019C44 5564000C */  jal        Sound_memcpy32
    /* A448 80019C48 80000624 */   addiu     $a2, $zero, 0x80
    /* A44C 80019C4C 0380053C */  lui        $a1, %hi(g_ActiveMusicChannels)
    /* A450 80019C50 9036A524 */  addiu      $a1, $a1, %lo(g_ActiveMusicChannels)
    /* A454 80019C54 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* A458 80019C58 D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* A45C 80019C5C 5564000C */  jal        Sound_memcpy32
    /* A460 80019C60 00220624 */   addiu     $a2, $zero, 0x2200
    /* A464 80019C64 2866028E */  lw         $v0, %lo(g_pSavedMousicConfig)($s0)
    /* A468 80019C68 286600AE */  sw         $zero, %lo(g_pSavedMousicConfig)($s0)
    /* A46C 80019C6C 6E0040A4 */  sh         $zero, 0x6E($v0)
    /* A470 80019C70 040040AC */  sw         $zero, 0x4($v0)
  .L80019C74:
    /* A474 80019C74 0380023C */  lui        $v0, %hi(D_80037788)
  .L80019C78:
    /* A478 80019C78 8877438C */  lw         $v1, %lo(D_80037788)($v0)
    /* A47C 80019C7C 00000000 */  nop
    /* A480 80019C80 17006010 */  beqz       $v1, .L80019CE0
    /* A484 80019C84 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* A488 80019C88 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* A48C 80019C8C 00000000 */  nop
    /* A490 80019C90 0400428C */  lw         $v0, 0x4($v0)
    /* A494 80019C94 00000000 */  nop
    /* A498 80019C98 12004014 */  bnez       $v0, .L80019CE4
    /* A49C 80019C9C 0480043C */   lui       $a0, %hi(D_80039B00)
    /* A4A0 80019CA0 0380023C */  lui        $v0, %hi(D_80037800)
    /* A4A4 80019CA4 00784424 */  addiu      $a0, $v0, %lo(D_80037800)
    /* A4A8 80019CA8 007843AC */  sw         $v1, %lo(D_80037800)($v0)
    /* A4AC 80019CAC 04006294 */  lhu        $v0, 0x4($v1)
    /* A4B0 80019CB0 20001324 */  addiu      $s3, $zero, 0x20
    /* A4B4 80019CB4 7E5B000C */  jal        Sound_Cmd_10_StartFieldMusic
    /* A4B8 80019CB8 080082AC */   sw        $v0, 0x8($a0)
    /* A4BC 80019CBC 0380023C */  lui        $v0, %hi(g_ActiveMusicChannels)
    /* A4C0 80019CC0 90365224 */  addiu      $s2, $v0, %lo(g_ActiveMusicChannels)
    /* A4C4 80019CC4 01000224 */  addiu      $v0, $zero, 0x1
  .L80019CC8:
    /* A4C8 80019CC8 660042A6 */  sh         $v0, 0x66($s2)
    /* A4CC 80019CCC FFFF7326 */  addiu      $s3, $s3, -0x1
    /* A4D0 80019CD0 FDFF6016 */  bnez       $s3, .L80019CC8
    /* A4D4 80019CD4 10015226 */   addiu     $s2, $s2, 0x110
    /* A4D8 80019CD8 0380023C */  lui        $v0, %hi(D_80037788)
    /* A4DC 80019CDC 887740AC */  sw         $zero, %lo(D_80037788)($v0)
  .L80019CE0:
    /* A4E0 80019CE0 0480043C */  lui        $a0, %hi(D_80039B00)
  .L80019CE4:
    /* A4E4 80019CE4 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* A4E8 80019CE8 0380053C */  lui        $a1, %hi(D_80037898)
    /* A4EC 80019CEC 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* A4F0 80019CF0 009B828C */  lw         $v0, %lo(D_80039B00)($a0)
    /* A4F4 80019CF4 1400638C */  lw         $v1, 0x14($v1)
    /* A4F8 80019CF8 9878A48C */  lw         $a0, %lo(D_80037898)($a1)
    /* A4FC 80019CFC 25104300 */  or         $v0, $v0, $v1
    /* A500 80019D00 25104400 */  or         $v0, $v0, $a0
    /* A504 80019D04 09004014 */  bnez       $v0, .L80019D2C
    /* A508 80019D08 0380023C */   lui       $v0, %hi(g_pSavedMousicConfig)
    /* A50C 80019D0C 2866428C */  lw         $v0, %lo(g_pSavedMousicConfig)($v0)
    /* A510 80019D10 00000000 */  nop
    /* A514 80019D14 07004010 */  beqz       $v0, .L80019D34
    /* A518 80019D18 0380103C */   lui       $s0, %hi(g_pActiveMusicConfig)
    /* A51C 80019D1C 1400428C */  lw         $v0, 0x14($v0)
    /* A520 80019D20 00000000 */  nop
    /* A524 80019D24 03004010 */  beqz       $v0, .L80019D34
    /* A528 80019D28 00000000 */   nop
  .L80019D2C:
    /* A52C 80019D2C 8854000C */  jal        func_80015220
    /* A530 80019D30 0380103C */   lui       $s0, %hi(g_pActiveMusicConfig)
  .L80019D34:
    /* A534 80019D34 2078028E */  lw         $v0, %lo(g_pActiveMusicConfig)($s0)
    /* A538 80019D38 00000000 */  nop
    /* A53C 80019D3C 0400428C */  lw         $v0, 0x4($v0)
    /* A540 80019D40 00000000 */  nop
    /* A544 80019D44 04004010 */  beqz       $v0, .L80019D58
    /* A548 80019D48 0380043C */   lui       $a0, %hi(g_ActiveMusicChannels)
    /* A54C 80019D4C 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* A550 80019D50 C165000C */  jal        func_80019704
    /* A554 80019D54 21280000 */   addu      $a1, $zero, $zero
  .L80019D58:
    /* A558 80019D58 0380113C */  lui        $s1, %hi(g_pSavedMousicConfig)
    /* A55C 80019D5C 2866238E */  lw         $v1, %lo(g_pSavedMousicConfig)($s1)
    /* A560 80019D60 00000000 */  nop
    /* A564 80019D64 28006010 */  beqz       $v1, .L80019E08
    /* A568 80019D68 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* A56C 80019D6C 0400628C */  lw         $v0, 0x4($v1)
    /* A570 80019D70 00000000 */  nop
    /* A574 80019D74 08004010 */  beqz       $v0, .L80019D98
    /* A578 80019D78 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* A57C 80019D7C D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* A580 80019D80 01000524 */  addiu      $a1, $zero, 0x1
    /* A584 80019D84 C165000C */  jal        func_80019704
    /* A588 80019D88 207803AE */   sw        $v1, %lo(g_pActiveMusicConfig)($s0)
    /* A58C 80019D8C 0380023C */  lui        $v0, %hi(D_800366F0)
    /* A590 80019D90 F0664224 */  addiu      $v0, $v0, %lo(D_800366F0)
    /* A594 80019D94 207802AE */  sw         $v0, %lo(g_pActiveMusicConfig)($s0)
  .L80019D98:
    /* A598 80019D98 0480023C */  lui        $v0, %hi(g_Sound_GlobalFlags)
    /* A59C 80019D9C F89A5024 */  addiu      $s0, $v0, %lo(g_Sound_GlobalFlags)
    /* A5A0 80019DA0 0400028E */  lw         $v0, 0x4($s0)
    /* A5A4 80019DA4 00000000 */  nop
    /* A5A8 80019DA8 00014230 */  andi       $v0, $v0, 0x100
    /* A5AC 80019DAC 15004010 */  beqz       $v0, .L80019E04
    /* A5B0 80019DB0 0380023C */   lui       $v0, %hi(D_8002F54C)
    /* A5B4 80019DB4 4CF54294 */  lhu        $v0, %lo(D_8002F54C)($v0)
    /* A5B8 80019DB8 00000000 */  nop
    /* A5BC 80019DBC 03004230 */  andi       $v0, $v0, 0x3
    /* A5C0 80019DC0 11004014 */  bnez       $v0, .L80019E08
    /* A5C4 80019DC4 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* A5C8 80019DC8 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* A5CC 80019DCC 2866248E */  lw         $a0, %lo(g_pSavedMousicConfig)($s1)
    /* A5D0 80019DD0 D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
    /* A5D4 80019DD4 7166000C */  jal        func_800199C4
    /* A5D8 80019DD8 00000000 */   nop
    /* A5DC 80019DDC 2866228E */  lw         $v0, %lo(g_pSavedMousicConfig)($s1)
    /* A5E0 80019DE0 00000000 */  nop
    /* A5E4 80019DE4 0400428C */  lw         $v0, 0x4($v0)
    /* A5E8 80019DE8 00000000 */  nop
    /* A5EC 80019DEC 06004014 */  bnez       $v0, .L80019E08
    /* A5F0 80019DF0 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* A5F4 80019DF4 0400028E */  lw         $v0, 0x4($s0)
    /* A5F8 80019DF8 FFFE0324 */  addiu      $v1, $zero, -0x101
    /* A5FC 80019DFC 24104300 */  and        $v0, $v0, $v1
    /* A600 80019E00 040002AE */  sw         $v0, 0x4($s0)
  .L80019E04:
    /* A604 80019E04 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
  .L80019E08:
    /* A608 80019E08 9078448C */  lw         $a0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* A60C 80019E0C 00000000 */  nop
    /* A610 80019E10 46008010 */  beqz       $a0, .L80019F2C
    /* A614 80019E14 90784524 */   addiu     $a1, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* A618 80019E18 1600A394 */  lhu        $v1, 0x16($a1)
    /* A61C 80019E1C 1800A28C */  lw         $v0, 0x18($a1)
    /* A620 80019E20 21988000 */  addu       $s3, $a0, $zero
    /* A624 80019E24 21184300 */  addu       $v1, $v0, $v1
    /* A628 80019E28 FFFF023C */  lui        $v0, (0xFFFF0000 >> 16)
    /* A62C 80019E2C 24106200 */  and        $v0, $v1, $v0
    /* A630 80019E30 07004014 */  bnez       $v0, .L80019E50
    /* A634 80019E34 1800A3AC */   sw        $v1, 0x18($a1)
    /* A638 80019E38 0480023C */  lui        $v0, %hi(D_80039B64)
    /* A63C 80019E3C 649B428C */  lw         $v0, %lo(D_80039B64)($v0)
    /* A640 80019E40 00000000 */  nop
    /* A644 80019E44 04004230 */  andi       $v0, $v0, 0x4
    /* A648 80019E48 39004010 */  beqz       $v0, .L80019F30
    /* A64C 80019E4C 0380023C */   lui       $v0, %hi(D_8002F54C)
  .L80019E50:
    /* A650 80019E50 FFFF6230 */  andi       $v0, $v1, 0xFFFF
    /* A654 80019E54 1800A2AC */  sw         $v0, 0x18($a1)
    /* A658 80019E58 00101124 */  addiu      $s1, $zero, 0x1000
    /* A65C 80019E5C 0380023C */  lui        $v0, %hi(D_80035910)
    /* A660 80019E60 10595224 */  addiu      $s2, $v0, %lo(D_80035910)
    /* A664 80019E64 21A0A000 */  addu       $s4, $a1, $zero
    /* A668 80019E68 66005026 */  addiu      $s0, $s2, 0x66
  .L80019E6C:
    /* A66C 80019E6C 24107102 */  and        $v0, $s3, $s1
    /* A670 80019E70 2A004010 */  beqz       $v0, .L80019F1C
    /* A674 80019E74 0480023C */   lui       $v0, %hi(D_80039B64)
    /* A678 80019E78 649B428C */  lw         $v0, %lo(D_80039B64)($v0)
    /* A67C 80019E7C 00000000 */  nop
    /* A680 80019E80 02004230 */  andi       $v0, $v0, 0x2
    /* A684 80019E84 06004010 */  beqz       $v0, .L80019EA0
    /* A688 80019E88 0002033C */   lui       $v1, (0x2000000 >> 16)
    /* A68C 80019E8C C2FF028E */  lw         $v0, -0x3E($s0)
    /* A690 80019E90 00000000 */  nop
    /* A694 80019E94 24104300 */  and        $v0, $v0, $v1
    /* A698 80019E98 1F004010 */  beqz       $v0, .L80019F18
    /* A69C 80019E9C 00000000 */   nop
  .L80019EA0:
    /* A6A0 80019EA0 F2FF028E */  lw         $v0, -0xE($s0)
    /* A6A4 80019EA4 00000396 */  lhu        $v1, 0x0($s0)
    /* A6A8 80019EA8 01004224 */  addiu      $v0, $v0, 0x1
    /* A6AC 80019EAC F2FF02AE */  sw         $v0, -0xE($s0)
    /* A6B0 80019EB0 02000296 */  lhu        $v0, 0x2($s0)
    /* A6B4 80019EB4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* A6B8 80019EB8 000003A6 */  sh         $v1, 0x0($s0)
    /* A6BC 80019EBC FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* A6C0 80019EC0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* A6C4 80019EC4 06006014 */  bnez       $v1, .L80019EE0
    /* A6C8 80019EC8 020002A6 */   sh        $v0, 0x2($s0)
    /* A6CC 80019ECC 21204002 */  addu       $a0, $s2, $zero
    /* A6D0 80019ED0 366A000C */  jal        func_8001A8D8
    /* A6D4 80019ED4 21282002 */   addu      $a1, $s1, $zero
    /* A6D8 80019ED8 C3670008 */  j          .L80019F0C
    /* A6DC 80019EDC 21204002 */   addu      $a0, $s2, $zero
  .L80019EE0:
    /* A6E0 80019EE0 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* A6E4 80019EE4 09004014 */  bnez       $v0, .L80019F0C
    /* A6E8 80019EE8 21204002 */   addu      $a0, $s2, $zero
    /* A6EC 80019EEC 0C00828E */  lw         $v0, 0xC($s4)
    /* A6F0 80019EF0 00000000 */  nop
    /* A6F4 80019EF4 25105100 */  or         $v0, $v0, $s1
    /* A6F8 80019EF8 0C0082AE */  sw         $v0, 0xC($s4)
    /* A6FC 80019EFC 0800828E */  lw         $v0, 0x8($s4)
    /* A700 80019F00 27181100 */  nor        $v1, $zero, $s1
    /* A704 80019F04 24104300 */  and        $v0, $v0, $v1
    /* A708 80019F08 080082AE */  sw         $v0, 0x8($s4)
  .L80019F0C:
    /* A70C 80019F0C 21282002 */  addu       $a1, $s1, $zero
    /* A710 80019F10 B34F000C */  jal        Sound_UpdateSlidesAndDelays
    /* A714 80019F14 01000624 */   addiu     $a2, $zero, 0x1
  .L80019F18:
    /* A718 80019F18 26987102 */  xor        $s3, $s3, $s1
  .L80019F1C:
    /* A71C 80019F1C 10011026 */  addiu      $s0, $s0, 0x110
    /* A720 80019F20 10015226 */  addiu      $s2, $s2, 0x110
    /* A724 80019F24 D1FF6016 */  bnez       $s3, .L80019E6C
    /* A728 80019F28 40881100 */   sll       $s1, $s1, 1
  .L80019F2C:
    /* A72C 80019F2C 0380023C */  lui        $v0, %hi(D_8002F54C)
  .L80019F30:
    /* A730 80019F30 4CF54294 */  lhu        $v0, %lo(D_8002F54C)($v0)
    /* A734 80019F34 00000000 */  nop
    /* A738 80019F38 03004230 */  andi       $v0, $v0, 0x3
    /* A73C 80019F3C 03004014 */  bnez       $v0, .L80019F4C
    /* A740 80019F40 00000000 */   nop
    /* A744 80019F44 9364000C */  jal        func_8001924C
    /* A748 80019F48 00000000 */   nop
  .L80019F4C:
    /* A74C 80019F4C 00F2043C */  lui        $a0, (0xF2000002 >> 16)
    /* A750 80019F50 B09A000C */  jal        GetRCnt
    /* A754 80019F54 02008434 */   ori       $a0, $a0, (0xF2000002 & 0xFFFF)
    /* A758 80019F58 23A85500 */  subu       $s5, $v0, $s5
    /* A75C 80019F5C 0200A01E */  bgtz       $s5, .L80019F68
    /* A760 80019F60 0380053C */   lui       $a1, %hi(D_8002F550)
    /* A764 80019F64 E844B526 */  addiu      $s5, $s5, 0x44E8
  .L80019F68:
    /* A768 80019F68 50F5A424 */  addiu      $a0, $a1, %lo(D_8002F550)
    /* A76C 80019F6C 0400838C */  lw         $v1, 0x4($a0)
    /* A770 80019F70 0800868C */  lw         $a2, 0x8($a0)
    /* A774 80019F74 0C00878C */  lw         $a3, 0xC($a0)
    /* A778 80019F78 2110A002 */  addu       $v0, $s5, $zero
    /* A77C 80019F7C 0C0082AC */  sw         $v0, 0xC($a0)
    /* A780 80019F80 50F5A3AC */  sw         $v1, %lo(D_8002F550)($a1)
    /* A784 80019F84 040086AC */  sw         $a2, 0x4($a0)
    /* A788 80019F88 080087AC */  sw         $a3, 0x8($a0)
    /* A78C 80019F8C 0380043C */  lui        $a0, %hi(D_8002F548)
    /* A790 80019F90 21186600 */  addu       $v1, $v1, $a2
    /* A794 80019F94 21186700 */  addu       $v1, $v1, $a3
    /* A798 80019F98 2800BF8F */  lw         $ra, 0x28($sp)
    /* A79C 80019F9C 2400B58F */  lw         $s5, 0x24($sp)
    /* A7A0 80019FA0 2000B48F */  lw         $s4, 0x20($sp)
    /* A7A4 80019FA4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* A7A8 80019FA8 1800B28F */  lw         $s2, 0x18($sp)
    /* A7AC 80019FAC 1400B18F */  lw         $s1, 0x14($sp)
    /* A7B0 80019FB0 1000B08F */  lw         $s0, 0x10($sp)
    /* A7B4 80019FB4 21186200 */  addu       $v1, $v1, $v0
    /* A7B8 80019FB8 48F583AC */  sw         $v1, %lo(D_8002F548)($a0)
    /* A7BC 80019FBC 0800E003 */  jr         $ra
    /* A7C0 80019FC0 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80019A58
