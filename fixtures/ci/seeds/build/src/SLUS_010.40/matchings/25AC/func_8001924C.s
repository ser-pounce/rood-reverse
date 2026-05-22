nonmatching func_8001924C, 0x3C8

glabel func_8001924C
    /* 9A4C 8001924C 0480023C */  lui        $v0, %hi(g_Sound_LfoPhase)
    /* 9A50 80019250 0380073C */  lui        $a3, %hi(g_Sound_CdVolumeFadeLength)
    /* 9A54 80019254 E89A438C */  lw         $v1, %lo(g_Sound_LfoPhase)($v0)
    /* 9A58 80019258 4C78E694 */  lhu        $a2, %lo(g_Sound_CdVolumeFadeLength)($a3)
    /* 9A5C 8001925C 01006324 */  addiu      $v1, $v1, 0x1
    /* 9A60 80019260 FF006330 */  andi       $v1, $v1, 0xFF
    /* 9A64 80019264 E89A43AC */  sw         $v1, %lo(g_Sound_LfoPhase)($v0)
    /* 9A68 80019268 4C78E284 */  lh         $v0, %lo(g_Sound_CdVolumeFadeLength)($a3)
    /* 9A6C 8001926C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 9A70 80019270 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 9A74 80019274 1800B2AF */  sw         $s2, 0x18($sp)
    /* 9A78 80019278 1400B1AF */  sw         $s1, 0x14($sp)
    /* 9A7C 8001927C 0A004010 */  beqz       $v0, .L800192A8
    /* 9A80 80019280 1000B0AF */   sw        $s0, 0x10($sp)
    /* 9A84 80019284 0380053C */  lui        $a1, %hi(g_CdVolume)
    /* 9A88 80019288 0380023C */  lui        $v0, %hi(g_Sound_CdVolumeFadeStep)
    /* 9A8C 8001928C E078A38C */  lw         $v1, %lo(g_CdVolume)($a1)
    /* 9A90 80019290 4878448C */  lw         $a0, %lo(g_Sound_CdVolumeFadeStep)($v0)
    /* 9A94 80019294 FFFFC224 */  addiu      $v0, $a2, -0x1
    /* 9A98 80019298 4C78E2A4 */  sh         $v0, %lo(g_Sound_CdVolumeFadeLength)($a3)
    /* 9A9C 8001929C 21186400 */  addu       $v1, $v1, $a0
    /* 9AA0 800192A0 4D64000C */  jal        UpdateCdVolume
    /* 9AA4 800192A4 E078A3AC */   sw        $v1, %lo(g_CdVolume)($a1)
  .L800192A8:
    /* 9AA8 800192A8 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* 9AAC 800192AC 089B5224 */  addiu      $s2, $v0, %lo(g_Sound_Cutscene_StreamState)
    /* 9AB0 800192B0 0C00428E */  lw         $v0, 0xC($s2)
    /* 9AB4 800192B4 00000000 */  nop
    /* 9AB8 800192B8 30004010 */  beqz       $v0, .L8001937C
    /* 9ABC 800192BC 0380073C */   lui       $a3, %hi(D_80036782)
    /* 9AC0 800192C0 4800428E */  lw         $v0, 0x48($s2)
    /* 9AC4 800192C4 00000000 */  nop
    /* 9AC8 800192C8 2C004010 */  beqz       $v0, .L8001937C
    /* 9ACC 800192CC FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 9AD0 800192D0 4000508E */  lw         $s0, 0x40($s2)
    /* 9AD4 800192D4 4400438E */  lw         $v1, 0x44($s2)
    /* 9AD8 800192D8 480042AE */  sw         $v0, 0x48($s2)
    /* 9ADC 800192DC 21880302 */  addu       $s1, $s0, $v1
    /* 9AE0 800192E0 00FF2332 */  andi       $v1, $s1, 0xFF00
    /* 9AE4 800192E4 00FF0232 */  andi       $v0, $s0, 0xFF00
    /* 9AE8 800192E8 20006210 */  beq        $v1, $v0, .L8001936C
    /* 9AEC 800192EC 0480023C */   lui       $v0, %hi(D_80039AFC)
    /* 9AF0 800192F0 FC9A428C */  lw         $v0, %lo(D_80039AFC)($v0)
    /* 9AF4 800192F4 00000000 */  nop
    /* 9AF8 800192F8 02004230 */  andi       $v0, $v0, 0x2
    /* 9AFC 800192FC 0E004010 */  beqz       $v0, .L80019338
    /* 9B00 80019300 0380023C */   lui       $v0, %hi(D_8002F89C)
    /* 9B04 80019304 9CF84284 */  lh         $v0, %lo(D_8002F89C)($v0)
    /* 9B08 80019308 00000000 */  nop
    /* 9B0C 8001930C 18000202 */  mult       $s0, $v0
    /* 9B10 80019310 21380000 */  addu       $a3, $zero, $zero
    /* 9B14 80019314 1000448E */  lw         $a0, 0x10($s2)
    /* 9B18 80019318 12400000 */  mflo       $t0
    /* 9B1C 8001931C 03840800 */  sra        $s0, $t0, 16
    /* 9B20 80019320 21280002 */  addu       $a1, $s0, $zero
    /* 9B24 80019324 D64E000C */  jal        SetVoiceVolume
    /* 9B28 80019328 21300002 */   addu      $a2, $s0, $zero
    /* 9B2C 8001932C 21280002 */  addu       $a1, $s0, $zero
    /* 9B30 80019330 D7640008 */  j          .L8001935C
    /* 9B34 80019334 2130A000 */   addu      $a2, $a1, $zero
  .L80019338:
    /* 9B38 80019338 C0831100 */  sll        $s0, $s1, 15
    /* 9B3C 8001933C 03841000 */  sra        $s0, $s0, 16
    /* 9B40 80019340 21280002 */  addu       $a1, $s0, $zero
    /* 9B44 80019344 21300000 */  addu       $a2, $zero, $zero
    /* 9B48 80019348 1000448E */  lw         $a0, 0x10($s2)
    /* 9B4C 8001934C D64E000C */  jal        SetVoiceVolume
    /* 9B50 80019350 2138C000 */   addu      $a3, $a2, $zero
    /* 9B54 80019354 21280000 */  addu       $a1, $zero, $zero
    /* 9B58 80019358 21300002 */  addu       $a2, $s0, $zero
  .L8001935C:
    /* 9B5C 8001935C 1000448E */  lw         $a0, 0x10($s2)
    /* 9B60 80019360 21380000 */  addu       $a3, $zero, $zero
    /* 9B64 80019364 D64E000C */  jal        SetVoiceVolume
    /* 9B68 80019368 01008424 */   addiu     $a0, $a0, 0x1
  .L8001936C:
    /* 9B6C 8001936C 0480033C */  lui        $v1, %hi(D_80039B48)
    /* 9B70 80019370 FFFF2232 */  andi       $v0, $s1, 0xFFFF
    /* 9B74 80019374 489B62AC */  sw         $v0, %lo(D_80039B48)($v1)
    /* 9B78 80019378 0380073C */  lui        $a3, %hi(D_80036782)
  .L8001937C:
    /* 9B7C 8001937C 8267E284 */  lh         $v0, %lo(D_80036782)($a3)
    /* 9B80 80019380 8267E694 */  lhu        $a2, %lo(D_80036782)($a3)
    /* 9B84 80019384 08004010 */  beqz       $v0, .L800193A8
    /* 9B88 80019388 0480053C */   lui       $a1, %hi(g_Sound_TempoMultiplier)
    /* 9B8C 8001938C 0380023C */  lui        $v0, %hi(D_8003677C)
    /* 9B90 80019390 F09AA38C */  lw         $v1, %lo(g_Sound_TempoMultiplier)($a1)
    /* 9B94 80019394 7C67448C */  lw         $a0, %lo(D_8003677C)($v0)
    /* 9B98 80019398 FFFFC224 */  addiu      $v0, $a2, -0x1
    /* 9B9C 8001939C 8267E2A4 */  sh         $v0, %lo(D_80036782)($a3)
    /* 9BA0 800193A0 21186400 */  addu       $v1, $v1, $a0
    /* 9BA4 800193A4 F09AA3AC */  sw         $v1, %lo(g_Sound_TempoMultiplier)($a1)
  .L800193A8:
    /* 9BA8 800193A8 0380063C */  lui        $a2, %hi(D_80036780)
    /* 9BAC 800193AC 8067C284 */  lh         $v0, %lo(D_80036780)($a2)
    /* 9BB0 800193B0 8067C594 */  lhu        $a1, %lo(D_80036780)($a2)
    /* 9BB4 800193B4 17004010 */  beqz       $v0, .L80019414
    /* 9BB8 800193B8 0480023C */   lui       $v0, %hi(g_Sound_MasterPitchScaleQ16_16)
    /* 9BBC 800193BC 0380043C */  lui        $a0, %hi(D_80036778)
    /* 9BC0 800193C0 EC9A438C */  lw         $v1, %lo(g_Sound_MasterPitchScaleQ16_16)($v0)
    /* 9BC4 800193C4 7867848C */  lw         $a0, %lo(D_80036778)($a0)
    /* 9BC8 800193C8 FFFFA224 */  addiu      $v0, $a1, -0x1
    /* 9BCC 800193CC 8067C2A4 */  sh         $v0, %lo(D_80036780)($a2)
    /* 9BD0 800193D0 FF00023C */  lui        $v0, (0xFF0000 >> 16)
    /* 9BD4 800193D4 21886400 */  addu       $s1, $v1, $a0
    /* 9BD8 800193D8 24202202 */  and        $a0, $s1, $v0
    /* 9BDC 800193DC 24186200 */  and        $v1, $v1, $v0
    /* 9BE0 800193E0 0A008310 */  beq        $a0, $v1, .L8001940C
    /* 9BE4 800193E4 20000624 */   addiu     $a2, $zero, 0x20
    /* 9BE8 800193E8 0380023C */  lui        $v0, %hi(g_ActiveMusicChannels)
    /* 9BEC 800193EC 90364224 */  addiu      $v0, $v0, %lo(g_ActiveMusicChannels)
    /* 9BF0 800193F0 F8004324 */  addiu      $v1, $v0, 0xF8
  .L800193F4:
    /* 9BF4 800193F4 0000628C */  lw         $v0, 0x0($v1)
    /* 9BF8 800193F8 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 9BFC 800193FC 10004234 */  ori        $v0, $v0, 0x10
    /* 9C00 80019400 000062AC */  sw         $v0, 0x0($v1)
    /* 9C04 80019404 FBFFC014 */  bnez       $a2, .L800193F4
    /* 9C08 80019408 10016324 */   addiu     $v1, $v1, 0x110
  .L8001940C:
    /* 9C0C 8001940C 0480023C */  lui        $v0, %hi(g_Sound_MasterPitchScaleQ16_16)
    /* 9C10 80019410 EC9A51AC */  sw         $s1, %lo(g_Sound_MasterPitchScaleQ16_16)($v0)
  .L80019414:
    /* 9C14 80019414 0380103C */  lui        $s0, %hi(g_pActiveMusicConfig)
    /* 9C18 80019418 2078058E */  lw         $a1, %lo(g_pActiveMusicConfig)($s0)
    /* 9C1C 8001941C 00000000 */  nop
    /* 9C20 80019420 0400A28C */  lw         $v0, 0x4($a1)
    /* 9C24 80019424 00000000 */  nop
    /* 9C28 80019428 14004010 */  beqz       $v0, .L8001947C
    /* 9C2C 8001942C 00000000 */   nop
    /* 9C30 80019430 6800A284 */  lh         $v0, 0x68($a1)
    /* 9C34 80019434 6800A694 */  lhu        $a2, 0x68($a1)
    /* 9C38 80019438 10004010 */  beqz       $v0, .L8001947C
    /* 9C3C 8001943C FFFFC224 */   addiu     $v0, $a2, -0x1
    /* 9C40 80019440 6000A38C */  lw         $v1, 0x60($a1)
    /* 9C44 80019444 6400A48C */  lw         $a0, 0x64($a1)
    /* 9C48 80019448 6800A2A4 */  sh         $v0, 0x68($a1)
    /* 9C4C 8001944C 7F00023C */  lui        $v0, (0x7F0000 >> 16)
    /* 9C50 80019450 21886400 */  addu       $s1, $v1, $a0
    /* 9C54 80019454 24202202 */  and        $a0, $s1, $v0
    /* 9C58 80019458 24186200 */  and        $v1, $v1, $v0
    /* 9C5C 8001945C 04008310 */  beq        $a0, $v1, .L80019470
    /* 9C60 80019460 2120A000 */   addu      $a0, $a1, $zero
    /* 9C64 80019464 0380053C */  lui        $a1, %hi(g_ActiveMusicChannels)
    /* 9C68 80019468 595A000C */  jal        Sound_MarkActiveChannelsVolumeDirty
    /* 9C6C 8001946C 9036A524 */   addiu     $a1, $a1, %lo(g_ActiveMusicChannels)
  .L80019470:
    /* 9C70 80019470 2078028E */  lw         $v0, %lo(g_pActiveMusicConfig)($s0)
    /* 9C74 80019474 00000000 */  nop
    /* 9C78 80019478 600051AC */  sw         $s1, 0x60($v0)
  .L8001947C:
    /* 9C7C 8001947C 0380103C */  lui        $s0, %hi(g_pSavedMousicConfig)
    /* 9C80 80019480 2866068E */  lw         $a2, %lo(g_pSavedMousicConfig)($s0)
    /* 9C84 80019484 00000000 */  nop
    /* 9C88 80019488 1900C010 */  beqz       $a2, .L800194F0
    /* 9C8C 8001948C 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 9C90 80019490 0400C28C */  lw         $v0, 0x4($a2)
    /* 9C94 80019494 00000000 */  nop
    /* 9C98 80019498 15004010 */  beqz       $v0, .L800194F0
    /* 9C9C 8001949C 0380023C */   lui       $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 9CA0 800194A0 6800C284 */  lh         $v0, 0x68($a2)
    /* 9CA4 800194A4 6800C594 */  lhu        $a1, 0x68($a2)
    /* 9CA8 800194A8 10004010 */  beqz       $v0, .L800194EC
    /* 9CAC 800194AC FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 9CB0 800194B0 6000C38C */  lw         $v1, 0x60($a2)
    /* 9CB4 800194B4 6400C48C */  lw         $a0, 0x64($a2)
    /* 9CB8 800194B8 6800C2A4 */  sh         $v0, 0x68($a2)
    /* 9CBC 800194BC 7F00023C */  lui        $v0, (0x7F0000 >> 16)
    /* 9CC0 800194C0 21886400 */  addu       $s1, $v1, $a0
    /* 9CC4 800194C4 24202202 */  and        $a0, $s1, $v0
    /* 9CC8 800194C8 24186200 */  and        $v1, $v1, $v0
    /* 9CCC 800194CC 04008310 */  beq        $a0, $v1, .L800194E0
    /* 9CD0 800194D0 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 9CD4 800194D4 D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
    /* 9CD8 800194D8 595A000C */  jal        Sound_MarkActiveChannelsVolumeDirty
    /* 9CDC 800194DC 2120C000 */   addu      $a0, $a2, $zero
  .L800194E0:
    /* 9CE0 800194E0 2866028E */  lw         $v0, %lo(g_pSavedMousicConfig)($s0)
    /* 9CE4 800194E4 00000000 */  nop
    /* 9CE8 800194E8 600051AC */  sw         $s1, 0x60($v0)
  .L800194EC:
    /* 9CEC 800194EC 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
  .L800194F0:
    /* 9CF0 800194F0 9078428C */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 9CF4 800194F4 00000000 */  nop
    /* 9CF8 800194F8 40004010 */  beqz       $v0, .L800195FC
    /* 9CFC 800194FC 00000000 */   nop
    /* 9D00 80019500 21384000 */  addu       $a3, $v0, $zero
    /* 9D04 80019504 0380023C */  lui        $v0, %hi(D_80035910)
    /* 9D08 80019508 10594224 */  addiu      $v0, $v0, %lo(D_80035910)
    /* 9D0C 8001950C 00100624 */  addiu      $a2, $zero, 0x1000
    /* 9D10 80019510 40004524 */  addiu      $a1, $v0, 0x40
  .L80019514:
    /* 9D14 80019514 2410E600 */  and        $v0, $a3, $a2
    /* 9D18 80019518 35004010 */  beqz       $v0, .L800195F0
    /* 9D1C 8001951C 00000000 */   nop
    /* 9D20 80019520 4C00A294 */  lhu        $v0, 0x4C($a1)
    /* 9D24 80019524 00000000 */  nop
    /* 9D28 80019528 0E004010 */  beqz       $v0, .L80019564
    /* 9D2C 8001952C FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 9D30 80019530 9C00A384 */  lh         $v1, 0x9C($a1)
    /* 9D34 80019534 9E00A484 */  lh         $a0, 0x9E($a1)
    /* 9D38 80019538 4C00A2A4 */  sh         $v0, 0x4C($a1)
    /* 9D3C 8001953C 21886400 */  addu       $s1, $v1, $a0
    /* 9D40 80019540 00FF2232 */  andi       $v0, $s1, 0xFF00
    /* 9D44 80019544 00FF6330 */  andi       $v1, $v1, 0xFF00
    /* 9D48 80019548 05004310 */  beq        $v0, $v1, .L80019560
    /* 9D4C 8001954C 00000000 */   nop
    /* 9D50 80019550 B800A28C */  lw         $v0, 0xB8($a1)
    /* 9D54 80019554 00000000 */  nop
    /* 9D58 80019558 03004234 */  ori        $v0, $v0, 0x3
    /* 9D5C 8001955C B800A2AC */  sw         $v0, 0xB8($a1)
  .L80019560:
    /* 9D60 80019560 9C00B1A4 */  sh         $s1, 0x9C($a1)
  .L80019564:
    /* 9D64 80019564 2E00A294 */  lhu        $v0, 0x2E($a1)
    /* 9D68 80019568 00000000 */  nop
    /* 9D6C 8001956C 0E004010 */  beqz       $v0, .L800195A8
    /* 9D70 80019570 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 9D74 80019574 2C00A394 */  lhu        $v1, 0x2C($a1)
    /* 9D78 80019578 9A00A484 */  lh         $a0, 0x9A($a1)
    /* 9D7C 8001957C 2E00A2A4 */  sh         $v0, 0x2E($a1)
    /* 9D80 80019580 21886400 */  addu       $s1, $v1, $a0
    /* 9D84 80019584 00FF2232 */  andi       $v0, $s1, 0xFF00
    /* 9D88 80019588 00FF6330 */  andi       $v1, $v1, 0xFF00
    /* 9D8C 8001958C 05004310 */  beq        $v0, $v1, .L800195A4
    /* 9D90 80019590 00000000 */   nop
    /* 9D94 80019594 B800A28C */  lw         $v0, 0xB8($a1)
    /* 9D98 80019598 00000000 */  nop
    /* 9D9C 8001959C 03004234 */  ori        $v0, $v0, 0x3
    /* 9DA0 800195A0 B800A2AC */  sw         $v0, 0xB8($a1)
  .L800195A4:
    /* 9DA4 800195A4 2C00B1A4 */  sh         $s1, 0x2C($a1)
  .L800195A8:
    /* 9DA8 800195A8 4600A294 */  lhu        $v0, 0x46($a1)
    /* 9DAC 800195AC 00000000 */  nop
    /* 9DB0 800195B0 0E004010 */  beqz       $v0, .L800195EC
    /* 9DB4 800195B4 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 9DB8 800195B8 0000A38C */  lw         $v1, 0x0($a1)
    /* 9DBC 800195BC 0400A48C */  lw         $a0, 0x4($a1)
    /* 9DC0 800195C0 4600A2A4 */  sh         $v0, 0x46($a1)
    /* 9DC4 800195C4 21886400 */  addu       $s1, $v1, $a0
    /* 9DC8 800195C8 00FF2232 */  andi       $v0, $s1, 0xFF00
    /* 9DCC 800195CC 00FF6330 */  andi       $v1, $v1, 0xFF00
    /* 9DD0 800195D0 05004310 */  beq        $v0, $v1, .L800195E8
    /* 9DD4 800195D4 00000000 */   nop
    /* 9DD8 800195D8 B800A28C */  lw         $v0, 0xB8($a1)
    /* 9DDC 800195DC 00000000 */  nop
    /* 9DE0 800195E0 10004234 */  ori        $v0, $v0, 0x10
    /* 9DE4 800195E4 B800A2AC */  sw         $v0, 0xB8($a1)
  .L800195E8:
    /* 9DE8 800195E8 0000B1AC */  sw         $s1, 0x0($a1)
  .L800195EC:
    /* 9DEC 800195EC 2638E600 */  xor        $a3, $a3, $a2
  .L800195F0:
    /* 9DF0 800195F0 40300600 */  sll        $a2, $a2, 1
    /* 9DF4 800195F4 C7FFE014 */  bnez       $a3, .L80019514
    /* 9DF8 800195F8 1001A524 */   addiu     $a1, $a1, 0x110
  .L800195FC:
    /* 9DFC 800195FC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 9E00 80019600 1800B28F */  lw         $s2, 0x18($sp)
    /* 9E04 80019604 1400B18F */  lw         $s1, 0x14($sp)
    /* 9E08 80019608 1000B08F */  lw         $s0, 0x10($sp)
    /* 9E0C 8001960C 0800E003 */  jr         $ra
    /* 9E10 80019610 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001924C
