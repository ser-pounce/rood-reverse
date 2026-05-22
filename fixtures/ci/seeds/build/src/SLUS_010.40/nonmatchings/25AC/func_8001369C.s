nonmatching func_8001369C, 0x29C

glabel func_8001369C
    /* 3E9C 8001369C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3EA0 800136A0 801F063C */  lui        $a2, (0x1F801DAA >> 16)
    /* 3EA4 800136A4 AA1DC634 */  ori        $a2, $a2, (0x1F801DAA & 0xFFFF)
    /* 3EA8 800136A8 18000824 */  addiu      $t0, $zero, 0x18
    /* 3EAC 800136AC 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 3EB0 800136B0 0380033C */  lui        $v1, %hi(D_800366F0)
    /* 3EB4 800136B4 F0666324 */  addiu      $v1, $v1, %lo(D_800366F0)
    /* 3EB8 800136B8 207843AC */  sw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 3EBC 800136BC 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 3EC0 800136C0 286640AC */  sw         $zero, %lo(g_pSavedMousicConfig)($v0)
    /* 3EC4 800136C4 0380023C */  lui        $v0, %hi(D_800377FC)
    /* 3EC8 800136C8 0380073C */  lui        $a3, %hi(g_ActiveMusicChannels)
    /* 3ECC 800136CC 9036E724 */  addiu      $a3, $a3, %lo(g_ActiveMusicChannels)
    /* 3ED0 800136D0 FC7747AC */  sw         $a3, %lo(D_800377FC)($v0)
    /* 3ED4 800136D4 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* 3ED8 800136D8 0480053C */  lui        $a1, %hi(g_Sound_GlobalFlags)
    /* 3EDC 800136DC D46540AC */  sw         $zero, %lo(g_pSecondaryMusicChannels)($v0)
    /* 3EE0 800136E0 0480023C */  lui        $v0, %hi(g_Sound_LfoPhase)
    /* 3EE4 800136E4 E89A40AC */  sw         $zero, %lo(g_Sound_LfoPhase)($v0)
    /* 3EE8 800136E8 0380023C */  lui        $v0, %hi(D_80037788)
    /* 3EEC 800136EC 0380043C */  lui        $a0, %hi(D_80036770)
    /* 3EF0 800136F0 887740AC */  sw         $zero, %lo(D_80037788)($v0)
    /* 3EF4 800136F4 70678224 */  addiu      $v0, $a0, %lo(D_80036770)
    /* 3EF8 800136F8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3EFC 800136FC F89AA0AC */  sw         $zero, %lo(g_Sound_GlobalFlags)($a1)
    /* 3F00 80013700 040040AC */  sw         $zero, 0x4($v0)
    /* 3F04 80013704 706780AC */  sw         $zero, %lo(D_80036770)($a0)
    /* 3F08 80013708 0380043C */  lui        $a0, %hi(D_800377E0)
    /* 3F0C 8001370C E0778224 */  addiu      $v0, $a0, %lo(D_800377E0)
    /* 3F10 80013710 F89AA524 */  addiu      $a1, $a1, %lo(g_Sound_GlobalFlags)
    /* 3F14 80013714 080040AC */  sw         $zero, 0x8($v0)
    /* 3F18 80013718 040040AC */  sw         $zero, 0x4($v0)
    /* 3F1C 8001371C 01000224 */  addiu      $v0, $zero, 0x1
    /* 3F20 80013720 E07780AC */  sw         $zero, %lo(D_800377E0)($a0)
    /* 3F24 80013724 0400A2AC */  sw         $v0, 0x4($a1)
    /* 3F28 80013728 0380053C */  lui        $a1, %hi(g_Sound_VoiceSchedulerState)
    /* 3F2C 8001372C 9078A0AC */  sw         $zero, %lo(g_Sound_VoiceSchedulerState)($a1)
    /* 3F30 80013730 9078A524 */  addiu      $a1, $a1, %lo(g_Sound_VoiceSchedulerState)
    /* 3F34 80013734 0380023C */  lui        $v0, %hi(g_PushedMusicConfig)
    /* 3F38 80013738 90584224 */  addiu      $v0, $v0, %lo(g_PushedMusicConfig)
    /* 3F3C 8001373C 040060AC */  sw         $zero, 0x4($v1)
    /* 3F40 80013740 080060AC */  sw         $zero, 0x8($v1)
    /* 3F44 80013744 6E0060A4 */  sh         $zero, 0x6E($v1)
    /* 3F48 80013748 1000A0AC */  sw         $zero, 0x10($a1)
    /* 3F4C 8001374C 1C0060AC */  sw         $zero, 0x1C($v1)
    /* 3F50 80013750 6E0040A4 */  sh         $zero, 0x6E($v0)
    /* 3F54 80013754 040040AC */  sw         $zero, 0x4($v0)
    /* 3F58 80013758 7F00023C */  lui        $v0, (0x7F0000 >> 16)
    /* 3F5C 8001375C 0380043C */  lui        $a0, %hi(g_CdVolume)
    /* 3F60 80013760 600062AC */  sw         $v0, 0x60($v1)
    /* 3F64 80013764 FF7F023C */  lui        $v0, (0x7FFF0000 >> 16)
    /* 3F68 80013768 E07882AC */  sw         $v0, %lo(g_CdVolume)($a0)
    /* 3F6C 8001376C 0380023C */  lui        $v0, %hi(D_80036780)
    /* 3F70 80013770 806740A4 */  sh         $zero, %lo(D_80036780)($v0)
    /* 3F74 80013774 0480023C */  lui        $v0, %hi(g_Sound_MasterPitchScaleQ16_16)
    /* 3F78 80013778 EC9A40AC */  sw         $zero, %lo(g_Sound_MasterPitchScaleQ16_16)($v0)
    /* 3F7C 8001377C 0380023C */  lui        $v0, %hi(D_80036782)
    /* 3F80 80013780 826740A4 */  sh         $zero, %lo(D_80036782)($v0)
    /* 3F84 80013784 0480023C */  lui        $v0, %hi(g_Sound_TempoMultiplier)
    /* 3F88 80013788 F09A40AC */  sw         $zero, %lo(g_Sound_TempoMultiplier)($v0)
    /* 3F8C 8001378C 0380023C */  lui        $v0, %hi(g_Sound_CdVolumeFadeLength)
    /* 3F90 80013790 5800E724 */  addiu      $a3, $a3, 0x58
    /* 3F94 80013794 680060A4 */  sh         $zero, 0x68($v1)
    /* 3F98 80013798 4C7840A4 */  sh         $zero, %lo(g_Sound_CdVolumeFadeLength)($v0)
    /* 3F9C 8001379C 1C00A0AC */  sw         $zero, 0x1C($a1)
    /* 3FA0 800137A0 4C0060AC */  sw         $zero, 0x4C($v1)
    /* 3FA4 800137A4 2000A0AC */  sw         $zero, 0x20($a1)
    /* 3FA8 800137A8 500060AC */  sw         $zero, 0x50($v1)
    /* 3FAC 800137AC 2400A0AC */  sw         $zero, 0x24($a1)
    /* 3FB0 800137B0 0000C494 */  lhu        $a0, 0x0($a2)
    /* 3FB4 800137B4 FF3F0224 */  addiu      $v0, $zero, 0x3FFF
    /* 3FB8 800137B8 801F013C */  lui        $at, (0x1F801D80 >> 16)
    /* 3FBC 800137BC 801D22A4 */  sh         $v0, (0x1F801D80 & 0xFFFF)($at)
    /* 3FC0 800137C0 801F013C */  lui        $at, (0x1F801D82 >> 16)
    /* 3FC4 800137C4 821D22A4 */  sh         $v0, (0x1F801D82 & 0xFFFF)($at)
    /* 3FC8 800137C8 FF7F0224 */  addiu      $v0, $zero, 0x7FFF
    /* 3FCC 800137CC 801F013C */  lui        $at, (0x1F801DB0 >> 16)
    /* 3FD0 800137D0 B01D22A4 */  sh         $v0, (0x1F801DB0 & 0xFFFF)($at)
    /* 3FD4 800137D4 801F013C */  lui        $at, (0x1F801DB2 >> 16)
    /* 3FD8 800137D8 B21D22A4 */  sh         $v0, (0x1F801DB2 & 0xFFFF)($at)
    /* 3FDC 800137DC 0380023C */  lui        $v0, %hi(g_Music_LoopCounter)
    /* 3FE0 800137E0 D87740AC */  sw         $zero, %lo(g_Music_LoopCounter)($v0)
    /* 3FE4 800137E4 0380023C */  lui        $v0, %hi(D_800378E4)
    /* 3FE8 800137E8 E47840AC */  sw         $zero, %lo(D_800378E4)($v0)
    /* 3FEC 800137EC 0480023C */  lui        $v0, %hi(D_80039B64)
    /* 3FF0 800137F0 649B40AC */  sw         $zero, %lo(D_80039B64)($v0)
    /* 3FF4 800137F4 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* 3FF8 800137F8 089B4224 */  addiu      $v0, $v0, %lo(g_Sound_Cutscene_StreamState)
    /* 3FFC 800137FC 540060AC */  sw         $zero, 0x54($v1)
    /* 4000 80013800 780060A4 */  sh         $zero, 0x78($v1)
    /* 4004 80013804 760060A4 */  sh         $zero, 0x76($v1)
    /* 4008 80013808 740060A4 */  sh         $zero, 0x74($v1)
    /* 400C 8001380C 7C0060A4 */  sh         $zero, 0x7C($v1)
    /* 4010 80013810 007F0324 */  addiu      $v1, $zero, 0x7F00
    /* 4014 80013814 400043AC */  sw         $v1, 0x40($v0)
    /* 4018 80013818 0480033C */  lui        $v1, %hi(g_Sound_VoiceModeFlags)
    /* 401C 8001381C 480040AC */  sw         $zero, 0x48($v0)
    /* 4020 80013820 D89B6224 */  addiu      $v0, $v1, %lo(g_Sound_VoiceModeFlags)
    /* 4024 80013824 080040AC */  sw         $zero, 0x8($v0)
    /* 4028 80013828 040040AC */  sw         $zero, 0x4($v0)
    /* 402C 8001382C D89B60AC */  sw         $zero, %lo(g_Sound_VoiceModeFlags)($v1)
    /* 4030 80013830 FAFF8230 */  andi       $v0, $a0, 0xFFFA
    /* 4034 80013834 21200000 */  addu       $a0, $zero, $zero
    /* 4038 80013838 01004234 */  ori        $v0, $v0, 0x1
    /* 403C 8001383C 0000C2A4 */  sh         $v0, 0x0($a2)
  .L80013840:
    /* 4040 80013840 01008424 */  addiu      $a0, $a0, 0x1
    /* 4044 80013844 DCFFE0AC */  sw         $zero, -0x24($a3)
    /* 4048 80013848 9C00E8AC */  sw         $t0, 0x9C($a3)
    /* 404C 8001384C 0C00E0A4 */  sh         $zero, 0xC($a3)
    /* 4050 80013850 0000E0AC */  sw         $zero, 0x0($a3)
    /* 4054 80013854 FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 4058 80013858 2000422C */  sltiu      $v0, $v0, 0x20
    /* 405C 8001385C F8FF4014 */  bnez       $v0, .L80013840
    /* 4060 80013860 1001E724 */   addiu     $a3, $a3, 0x110
    /* 4064 80013864 0C000424 */  addiu      $a0, $zero, 0xC
    /* 4068 80013868 01000624 */  addiu      $a2, $zero, 0x1
    /* 406C 8001386C 007F0524 */  addiu      $a1, $zero, 0x7F00
    /* 4070 80013870 0380023C */  lui        $v0, %hi(D_80035910)
    /* 4074 80013874 10594224 */  addiu      $v0, $v0, %lo(D_80035910)
    /* 4078 80013878 8A004324 */  addiu      $v1, $v0, 0x8A
  .L8001387C:
    /* 407C 8001387C FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 4080 80013880 01008424 */  addiu      $a0, $a0, 0x1
    /* 4084 80013884 AAFF60AC */  sw         $zero, -0x56($v1)
    /* 4088 80013888 6A0062AC */  sw         $v0, 0x6A($v1)
    /* 408C 8001388C DAFF66A4 */  sh         $a2, -0x26($v1)
    /* 4090 80013890 CEFF60AC */  sw         $zero, -0x32($v1)
    /* 4094 80013894 520065A4 */  sh         $a1, 0x52($v1)
    /* 4098 80013898 020060A4 */  sh         $zero, 0x2($v1)
    /* 409C 8001389C FCFF60A4 */  sh         $zero, -0x4($v1)
    /* 40A0 800138A0 B6FF60AC */  sw         $zero, -0x4A($v1)
    /* 40A4 800138A4 000060A4 */  sh         $zero, 0x0($v1)
    /* 40A8 800138A8 FFFF8230 */  andi       $v0, $a0, 0xFFFF
    /* 40AC 800138AC 1800422C */  sltiu      $v0, $v0, 0x18
    /* 40B0 800138B0 F2FF4014 */  bnez       $v0, .L8001387C
    /* 40B4 800138B4 10016324 */   addiu     $v1, $v1, 0x110
    /* 40B8 800138B8 FF03053C */  lui        $a1, (0x3FFF000 >> 16)
    /* 40BC 800138BC 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 40C0 800138C0 00F0A534 */  ori        $a1, $a1, (0x3FFF000 & 0xFFFF)
    /* 40C4 800138C4 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* 40C8 800138C8 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 40CC 800138CC 90784224 */  addiu      $v0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* 40D0 800138D0 01000324 */  addiu      $v1, $zero, 0x1
    /* 40D4 800138D4 180080AC */  sw         $zero, 0x18($a0)
    /* 40D8 800138D8 140080AC */  sw         $zero, 0x14($a0)
    /* 40DC 800138DC 100080AC */  sw         $zero, 0x10($a0)
    /* 40E0 800138E0 180043AC */  sw         $v1, 0x18($v0)
    /* 40E4 800138E4 A866033C */  lui        $v1, (0x66A80000 >> 16)
    /* 40E8 800138E8 140043AC */  sw         $v1, 0x14($v0)
    /* 40EC 800138EC 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* 40F0 800138F0 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 40F4 800138F4 0C0040AC */  sw         $zero, 0xC($v0)
    /* 40F8 800138F8 080040AC */  sw         $zero, 0x8($v0)
    /* 40FC 800138FC 040040AC */  sw         $zero, 0x4($v0)
    /* 4100 80013900 580085AC */  sw         $a1, 0x58($a0)
    /* 4104 80013904 5C0080AC */  sw         $zero, 0x5C($a0)
    /* 4108 80013908 6A0080A4 */  sh         $zero, 0x6A($a0)
    /* 410C 8001390C 0800628C */  lw         $v0, 0x8($v1)
    /* 4110 80013910 04000424 */  addiu      $a0, $zero, 0x4
    /* 4114 80013914 80004234 */  ori        $v0, $v0, 0x80
    /* 4118 80013918 F862000C */  jal        Sound_SetReverbMode
    /* 411C 8001391C 080062AC */   sw        $v0, 0x8($v1)
    /* 4120 80013920 CD79000C */  jal        SpuSetReverb
    /* 4124 80013924 01000424 */   addiu     $a0, $zero, 0x1
    /* 4128 80013928 1000BF8F */  lw         $ra, 0x10($sp)
    /* 412C 8001392C 00000000 */  nop
    /* 4130 80013930 0800E003 */  jr         $ra
    /* 4134 80013934 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001369C
