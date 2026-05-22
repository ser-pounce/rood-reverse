nonmatching func_80015970, 0x18C

glabel func_80015970
    /* 6170 80015970 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 6174 80015974 3000B6AF */  sw         $s6, 0x30($sp)
    /* 6178 80015978 21B08000 */  addu       $s6, $a0, $zero
    /* 617C 8001597C 2800B4AF */  sw         $s4, 0x28($sp)
    /* 6180 80015980 21A0C000 */  addu       $s4, $a2, $zero
    /* 6184 80015984 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 6188 80015988 21A8E000 */  addu       $s5, $a3, $zero
    /* 618C 8001598C 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 6190 80015990 9078448C */  lw         $a0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 6194 80015994 90784324 */  addiu      $v1, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* 6198 80015998 1800B0AF */  sw         $s0, 0x18($sp)
    /* 619C 8001599C 0380103C */  lui        $s0, %hi(g_pSavedMousicConfig)
    /* 61A0 800159A0 3400BFAF */  sw         $ra, 0x34($sp)
    /* 61A4 800159A4 2400B3AF */  sw         $s3, 0x24($sp)
    /* 61A8 800159A8 2000B2AF */  sw         $s2, 0x20($sp)
    /* 61AC 800159AC 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 61B0 800159B0 1000628C */  lw         $v0, 0x10($v1)
    /* 61B4 800159B4 2866038E */  lw         $v1, %lo(g_pSavedMousicConfig)($s0)
    /* 61B8 800159B8 25208200 */  or         $a0, $a0, $v0
    /* 61BC 800159BC 0480023C */  lui        $v0, %hi(D_80039B14)
    /* 61C0 800159C0 149B428C */  lw         $v0, %lo(D_80039B14)($v0)
    /* 61C4 800159C4 21880000 */  addu       $s1, $zero, $zero
    /* 61C8 800159C8 1000A0AF */  sw         $zero, 0x10($sp)
    /* 61CC 800159CC 11006010 */  beqz       $v1, .L80015A14
    /* 61D0 800159D0 27904400 */   nor       $s2, $v0, $a0
    /* 61D4 800159D4 0400628C */  lw         $v0, 0x4($v1)
    /* 61D8 800159D8 0800638C */  lw         $v1, 0x8($v1)
    /* 61DC 800159DC 24884500 */  and        $s1, $v0, $a1
    /* 61E0 800159E0 24302302 */  and        $a2, $s1, $v1
    /* 61E4 800159E4 0B00C010 */  beqz       $a2, .L80015A14
    /* 61E8 800159E8 1000A527 */   addiu     $a1, $sp, 0x10
    /* 61EC 800159EC 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* 61F0 800159F0 D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* 61F4 800159F4 D955000C */  jal        ChannelMaskToVoiceMaskFiltered
    /* 61F8 800159F8 21384002 */   addu      $a3, $s2, $zero
    /* 61FC 800159FC 2866028E */  lw         $v0, %lo(g_pSavedMousicConfig)($s0)
    /* 6200 80015A00 00000000 */  nop
    /* 6204 80015A04 0800428C */  lw         $v0, 0x8($v0)
    /* 6208 80015A08 00000000 */  nop
    /* 620C 80015A0C 27100200 */  nor        $v0, $zero, $v0
    /* 6210 80015A10 24882202 */  and        $s1, $s1, $v0
  .L80015A14:
    /* 6214 80015A14 0380133C */  lui        $s3, %hi(g_pActiveMusicConfig)
    /* 6218 80015A18 2078628E */  lw         $v0, %lo(g_pActiveMusicConfig)($s3)
    /* 621C 80015A1C 00000000 */  nop
    /* 6220 80015A20 0400438C */  lw         $v1, 0x4($v0)
    /* 6224 80015A24 0800428C */  lw         $v0, 0x8($v0)
    /* 6228 80015A28 24807400 */  and        $s0, $v1, $s4
    /* 622C 80015A2C 24300202 */  and        $a2, $s0, $v0
    /* 6230 80015A30 0B00C010 */  beqz       $a2, .L80015A60
    /* 6234 80015A34 0380043C */   lui       $a0, %hi(g_ActiveMusicChannels)
    /* 6238 80015A38 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 623C 80015A3C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6240 80015A40 D955000C */  jal        ChannelMaskToVoiceMaskFiltered
    /* 6244 80015A44 21384002 */   addu      $a3, $s2, $zero
    /* 6248 80015A48 2078628E */  lw         $v0, %lo(g_pActiveMusicConfig)($s3)
    /* 624C 80015A4C 00000000 */  nop
    /* 6250 80015A50 0800428C */  lw         $v0, 0x8($v0)
    /* 6254 80015A54 00000000 */  nop
    /* 6258 80015A58 27100200 */  nor        $v0, $zero, $v0
    /* 625C 80015A5C 24800202 */  and        $s0, $s0, $v0
  .L80015A60:
    /* 6260 80015A60 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 6264 80015A64 2866428C */  lw         $v0, %lo(g_pSavedMousicConfig)($v0)
    /* 6268 80015A68 00000000 */  nop
    /* 626C 80015A6C 08004010 */  beqz       $v0, .L80015A90
    /* 6270 80015A70 00000000 */   nop
    /* 6274 80015A74 06002012 */  beqz       $s1, .L80015A90
    /* 6278 80015A78 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 627C 80015A7C D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* 6280 80015A80 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6284 80015A84 21302002 */  addu       $a2, $s1, $zero
    /* 6288 80015A88 D955000C */  jal        ChannelMaskToVoiceMaskFiltered
    /* 628C 80015A8C 21384002 */   addu      $a3, $s2, $zero
  .L80015A90:
    /* 6290 80015A90 06000012 */  beqz       $s0, .L80015AAC
    /* 6294 80015A94 0380043C */   lui       $a0, %hi(g_ActiveMusicChannels)
    /* 6298 80015A98 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 629C 80015A9C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 62A0 80015AA0 21300002 */  addu       $a2, $s0, $zero
    /* 62A4 80015AA4 D955000C */  jal        ChannelMaskToVoiceMaskFiltered
    /* 62A8 80015AA8 21384002 */   addu      $a3, $s2, $zero
  .L80015AAC:
    /* 62AC 80015AAC 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* 62B0 80015AB0 1000A28F */  lw         $v0, 0x10($sp)
    /* 62B4 80015AB4 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 62B8 80015AB8 25105500 */  or         $v0, $v0, $s5
    /* 62BC 80015ABC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 62C0 80015AC0 0000C2AE */  sw         $v0, 0x0($s6)
    /* 62C4 80015AC4 0800628C */  lw         $v0, 0x8($v1)
    /* 62C8 80015AC8 00000000 */  nop
    /* 62CC 80015ACC 00014234 */  ori        $v0, $v0, 0x100
    /* 62D0 80015AD0 080062AC */  sw         $v0, 0x8($v1)
    /* 62D4 80015AD4 3400BF8F */  lw         $ra, 0x34($sp)
    /* 62D8 80015AD8 3000B68F */  lw         $s6, 0x30($sp)
    /* 62DC 80015ADC 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 62E0 80015AE0 2800B48F */  lw         $s4, 0x28($sp)
    /* 62E4 80015AE4 2400B38F */  lw         $s3, 0x24($sp)
    /* 62E8 80015AE8 2000B28F */  lw         $s2, 0x20($sp)
    /* 62EC 80015AEC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 62F0 80015AF0 1800B08F */  lw         $s0, 0x18($sp)
    /* 62F4 80015AF4 0800E003 */  jr         $ra
    /* 62F8 80015AF8 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80015970
