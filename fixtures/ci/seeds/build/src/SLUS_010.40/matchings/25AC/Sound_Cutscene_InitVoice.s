nonmatching Sound_Cutscene_InitVoice, 0x1BC

glabel Sound_Cutscene_InitVoice
    /* D8E4 8001D0E4 0480023C */  lui        $v0, %hi(D_80039AFC)
    /* D8E8 8001D0E8 FC9A428C */  lw         $v0, %lo(D_80039AFC)($v0)
    /* D8EC 8001D0EC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* D8F0 8001D0F0 1000B0AF */  sw         $s0, 0x10($sp)
    /* D8F4 8001D0F4 21808000 */  addu       $s0, $a0, $zero
    /* D8F8 8001D0F8 1400B1AF */  sw         $s1, 0x14($sp)
    /* D8FC 8001D0FC 2188C000 */  addu       $s1, $a2, $zero
    /* D900 8001D100 1800B2AF */  sw         $s2, 0x18($sp)
    /* D904 8001D104 2190E000 */  addu       $s2, $a3, $zero
    /* D908 8001D108 02004230 */  andi       $v0, $v0, 0x2
    /* D90C 8001D10C 0C004010 */  beqz       $v0, .L8001D140
    /* D910 8001D110 1C00BFAF */   sw        $ra, 0x1C($sp)
    /* D914 8001D114 0480043C */  lui        $a0, %hi(D_80039B48)
    /* D918 8001D118 0380023C */  lui        $v0, %hi(D_8002F89C)
    /* D91C 8001D11C 9CF84384 */  lh         $v1, %lo(D_8002F89C)($v0)
    /* D920 8001D120 489B828C */  lw         $v0, %lo(D_80039B48)($a0)
    /* D924 8001D124 00000000 */  nop
    /* D928 8001D128 18004300 */  mult       $v0, $v1
    /* D92C 8001D12C 12400000 */  mflo       $t0
    /* D930 8001D130 03140800 */  sra        $v0, $t0, 16
    /* D934 8001D134 21304000 */  addu       $a2, $v0, $zero
    /* D938 8001D138 7F740008 */  j          .L8001D1FC
    /* D93C 8001D13C 21184000 */   addu      $v1, $v0, $zero
  .L8001D140:
    /* D940 8001D140 01000224 */  addiu      $v0, $zero, 0x1
    /* D944 8001D144 0600A214 */  bne        $a1, $v0, .L8001D160
    /* D948 8001D148 02000224 */   addiu     $v0, $zero, 0x2
    /* D94C 8001D14C 0480023C */  lui        $v0, %hi(D_80039B48)
    /* D950 8001D150 489B428C */  lw         $v0, %lo(D_80039B48)($v0)
    /* D954 8001D154 21300000 */  addu       $a2, $zero, $zero
    /* D958 8001D158 7F740008 */  j          .L8001D1FC
    /* D95C 8001D15C 42180200 */   srl       $v1, $v0, 1
  .L8001D160:
    /* D960 8001D160 0600A214 */  bne        $a1, $v0, .L8001D17C
    /* D964 8001D164 03000224 */   addiu     $v0, $zero, 0x3
    /* D968 8001D168 0480023C */  lui        $v0, %hi(D_80039B48)
    /* D96C 8001D16C 489B428C */  lw         $v0, %lo(D_80039B48)($v0)
    /* D970 8001D170 21180000 */  addu       $v1, $zero, $zero
    /* D974 8001D174 7F740008 */  j          .L8001D1FC
    /* D978 8001D178 42300200 */   srl       $a2, $v0, 1
  .L8001D17C:
    /* D97C 8001D17C 0A00A214 */  bne        $a1, $v0, .L8001D1A8
    /* D980 8001D180 0480023C */   lui       $v0, %hi(D_80039B48)
    /* D984 8001D184 489B428C */  lw         $v0, %lo(D_80039B48)($v0)
    /* D988 8001D188 00000000 */  nop
    /* D98C 8001D18C 43100200 */  sra        $v0, $v0, 1
    /* D990 8001D190 00140200 */  sll        $v0, $v0, 16
    /* D994 8001D194 431C0200 */  sra        $v1, $v0, 17
    /* D998 8001D198 83140200 */  sra        $v0, $v0, 18
    /* D99C 8001D19C 21186200 */  addu       $v1, $v1, $v0
    /* D9A0 8001D1A0 7F740008 */  j          .L8001D1FC
    /* D9A4 8001D1A4 21306000 */   addu      $a2, $v1, $zero
  .L8001D1A8:
    /* D9A8 8001D1A8 0480043C */  lui        $a0, %hi(g_Sound_Cutscene_StreamState)
    /* D9AC 8001D1AC 089B8424 */  addiu      $a0, $a0, %lo(g_Sound_Cutscene_StreamState)
    /* D9B0 8001D1B0 0380053C */  lui        $a1, %hi(g_Sound_StereoPanGainTableQ15)
    /* D9B4 8001D1B4 9CF7A524 */  addiu      $a1, $a1, %lo(g_Sound_StereoPanGainTableQ15)
    /* D9B8 8001D1B8 4D008390 */  lbu        $v1, 0x4D($a0)
    /* D9BC 8001D1BC 4000848C */  lw         $a0, 0x40($a0)
    /* D9C0 8001D1C0 40100300 */  sll        $v0, $v1, 1
    /* D9C4 8001D1C4 21104500 */  addu       $v0, $v0, $a1
    /* D9C8 8001D1C8 00004284 */  lh         $v0, 0x0($v0)
    /* D9CC 8001D1CC 00000000 */  nop
    /* D9D0 8001D1D0 18008200 */  mult       $a0, $v0
    /* D9D4 8001D1D4 FF006338 */  xori       $v1, $v1, 0xFF
    /* D9D8 8001D1D8 40180300 */  sll        $v1, $v1, 1
    /* D9DC 8001D1DC 21186500 */  addu       $v1, $v1, $a1
    /* D9E0 8001D1E0 12300000 */  mflo       $a2
    /* D9E4 8001D1E4 00006284 */  lh         $v0, 0x0($v1)
    /* D9E8 8001D1E8 00000000 */  nop
    /* D9EC 8001D1EC 18008200 */  mult       $a0, $v0
    /* D9F0 8001D1F0 021C0600 */  srl        $v1, $a2, 16
    /* D9F4 8001D1F4 12100000 */  mflo       $v0
    /* D9F8 8001D1F8 02340200 */  srl        $a2, $v0, 16
  .L8001D1FC:
    /* D9FC 8001D1FC 21200002 */  addu       $a0, $s0, $zero
    /* DA00 8001D200 002C0300 */  sll        $a1, $v1, 16
    /* DA04 8001D204 032C0500 */  sra        $a1, $a1, 16
    /* DA08 8001D208 00340600 */  sll        $a2, $a2, 16
    /* DA0C 8001D20C 03340600 */  sra        $a2, $a2, 16
    /* DA10 8001D210 D64E000C */  jal        SetVoiceVolume
    /* DA14 8001D214 21380000 */   addu      $a3, $zero, $zero
    /* DA18 8001D218 0480023C */  lui        $v0, %hi(D_80039B60)
    /* DA1C 8001D21C 609B458C */  lw         $a1, %lo(D_80039B60)($v0)
    /* DA20 8001D220 E84E000C */  jal        SetVoiceSampleRate
    /* DA24 8001D224 21200002 */   addu      $a0, $s0, $zero
    /* DA28 8001D228 21200002 */  addu       $a0, $s0, $zero
    /* DA2C 8001D22C EE4E000C */  jal        SetVoiceStartAddr
    /* DA30 8001D230 21282002 */   addu      $a1, $s1, $zero
    /* DA34 8001D234 21200002 */  addu       $a0, $s0, $zero
    /* DA38 8001D238 F54E000C */  jal        SetVoiceRepeatAddr
    /* DA3C 8001D23C 21284002 */   addu      $a1, $s2, $zero
    /* DA40 8001D240 21200002 */  addu       $a0, $s0, $zero
    /* DA44 8001D244 21280000 */  addu       $a1, $zero, $zero
    /* DA48 8001D248 084F000C */  jal        SetVoiceAdsrAttackRateAndMode
    /* DA4C 8001D24C 01000624 */   addiu     $a2, $zero, 0x1
    /* DA50 8001D250 21200002 */  addu       $a0, $s0, $zero
    /* DA54 8001D254 144F000C */  jal        SetVoiceAdsrDecayRate
    /* DA58 8001D258 0F000524 */   addiu     $a1, $zero, 0xF
    /* DA5C 8001D25C 21200002 */  addu       $a0, $s0, $zero
    /* DA60 8001D260 1E4F000C */  jal        SetVoiceAdsrSustainLevel
    /* DA64 8001D264 0F000524 */   addiu     $a1, $zero, 0xF
    /* DA68 8001D268 21200002 */  addu       $a0, $s0, $zero
    /* DA6C 8001D26C 7F000524 */  addiu      $a1, $zero, 0x7F
    /* DA70 8001D270 284F000C */  jal        SetVoiceAdsrSustainRateAndDirection
    /* DA74 8001D274 03000624 */   addiu     $a2, $zero, 0x3
    /* DA78 8001D278 21200002 */  addu       $a0, $s0, $zero
    /* DA7C 8001D27C 06000524 */  addiu      $a1, $zero, 0x6
    /* DA80 8001D280 354F000C */  jal        SetVoiceAdsrReleaseRateAndMode
    /* DA84 8001D284 03000624 */   addiu     $a2, $zero, 0x3
    /* DA88 8001D288 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* DA8C 8001D28C 1800B28F */  lw         $s2, 0x18($sp)
    /* DA90 8001D290 1400B18F */  lw         $s1, 0x14($sp)
    /* DA94 8001D294 1000B08F */  lw         $s0, 0x10($sp)
    /* DA98 8001D298 0800E003 */  jr         $ra
    /* DA9C 8001D29C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Sound_Cutscene_InitVoice
