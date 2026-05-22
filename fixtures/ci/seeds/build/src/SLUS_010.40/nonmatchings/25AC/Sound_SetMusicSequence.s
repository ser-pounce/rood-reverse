nonmatching Sound_SetMusicSequence, 0x3A8

glabel Sound_SetMusicSequence
    /* 7200 80016A00 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 7204 80016A04 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7208 80016A08 21888000 */  addu       $s1, $a0, $zero
    /* 720C 80016A0C 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 7210 80016A10 21B8A000 */  addu       $s7, $a1, $zero
    /* 7214 80016A14 3000BFAF */  sw         $ra, 0x30($sp)
    /* 7218 80016A18 2800B6AF */  sw         $s6, 0x28($sp)
    /* 721C 80016A1C 2400B5AF */  sw         $s5, 0x24($sp)
    /* 7220 80016A20 2000B4AF */  sw         $s4, 0x20($sp)
    /* 7224 80016A24 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7228 80016A28 1800B2AF */  sw         $s2, 0x18($sp)
    /* 722C 80016A2C 0F00E016 */  bnez       $s7, .L80016A6C
    /* 7230 80016A30 1000B0AF */   sw        $s0, 0x10($sp)
    /* 7234 80016A34 0380043C */  lui        $a0, %hi(g_PushedMusicConfig)
    /* 7238 80016A38 90588424 */  addiu      $a0, $a0, %lo(g_PushedMusicConfig)
    /* 723C 80016A3C 0380053C */  lui        $a1, %hi(D_800366F0)
    /* 7240 80016A40 F066A524 */  addiu      $a1, $a1, %lo(D_800366F0)
    /* 7244 80016A44 5564000C */  jal        Sound_memcpy32
    /* 7248 80016A48 80000624 */   addiu     $a2, $zero, 0x80
    /* 724C 80016A4C 0380043C */  lui        $a0, %hi(D_800378E8)
    /* 7250 80016A50 E8788424 */  addiu      $a0, $a0, %lo(D_800378E8)
    /* 7254 80016A54 0380053C */  lui        $a1, %hi(g_ActiveMusicChannels)
    /* 7258 80016A58 9036A524 */  addiu      $a1, $a1, %lo(g_ActiveMusicChannels)
    /* 725C 80016A5C 5564000C */  jal        Sound_memcpy32
    /* 7260 80016A60 00220624 */   addiu     $a2, $zero, 0x2200
    /* 7264 80016A64 A85A0008 */  j          .L80016AA0
    /* 7268 80016A68 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
  .L80016A6C:
    /* 726C 80016A6C 0380043C */  lui        $a0, %hi(g_PushedMusicConfig)
    /* 7270 80016A70 90588424 */  addiu      $a0, $a0, %lo(g_PushedMusicConfig)
    /* 7274 80016A74 0380053C */  lui        $a1, %hi(D_800366F0)
    /* 7278 80016A78 F066A524 */  addiu      $a1, $a1, %lo(D_800366F0)
    /* 727C 80016A7C 7564000C */  jal        Sound_memswp32
    /* 7280 80016A80 80000624 */   addiu     $a2, $zero, 0x80
    /* 7284 80016A84 0380043C */  lui        $a0, %hi(D_800378E8)
    /* 7288 80016A88 E8788424 */  addiu      $a0, $a0, %lo(D_800378E8)
    /* 728C 80016A8C 0380053C */  lui        $a1, %hi(g_ActiveMusicChannels)
    /* 7290 80016A90 9036A524 */  addiu      $a1, $a1, %lo(g_ActiveMusicChannels)
    /* 7294 80016A94 7564000C */  jal        Sound_memswp32
    /* 7298 80016A98 00220624 */   addiu     $a2, $zero, 0x2200
    /* 729C 80016A9C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
  .L80016AA0:
    /* 72A0 80016AA0 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 72A4 80016AA4 00000000 */  nop
    /* 72A8 80016AA8 0000648C */  lw         $a0, 0x0($v1)
    /* 72AC 80016AAC 9FFF0224 */  addiu      $v0, $zero, -0x61
    /* 72B0 80016AB0 24288200 */  and        $a1, $a0, $v0
    /* 72B4 80016AB4 0380023C */  lui        $v0, %hi(D_80036774)
    /* 72B8 80016AB8 000065AC */  sw         $a1, 0x0($v1)
    /* 72BC 80016ABC 1400248E */  lw         $a0, 0x14($s1)
    /* 72C0 80016AC0 7467428C */  lw         $v0, %lo(D_80036774)($v0)
    /* 72C4 80016AC4 00000000 */  nop
    /* 72C8 80016AC8 02008214 */  bne        $a0, $v0, .L80016AD4
    /* 72CC 80016ACC 2000A434 */   ori       $a0, $a1, 0x20
    /* 72D0 80016AD0 4000A434 */  ori        $a0, $a1, 0x40
  .L80016AD4:
    /* 72D4 80016AD4 0380023C */  lui        $v0, %hi(g_ActiveMusicChannels)
    /* 72D8 80016AD8 90365224 */  addiu      $s2, $v0, %lo(g_ActiveMusicChannels)
    /* 72DC 80016ADC 20001424 */  addiu      $s4, $zero, 0x20
    /* 72E0 80016AE0 01001324 */  addiu      $s3, $zero, 0x1
    /* 72E4 80016AE4 0380023C */  lui        $v0, %hi(g_Sound_ProgramCounter)
    /* 72E8 80016AE8 38F65624 */  addiu      $s6, $v0, %lo(g_Sound_ProgramCounter)
    /* 72EC 80016AEC 0380023C */  lui        $v0, %hi(D_80036728)
    /* 72F0 80016AF0 000064AC */  sw         $a0, 0x0($v1)
    /* 72F4 80016AF4 0380033C */  lui        $v1, %hi(g_pActiveMusicConfig)
    /* 72F8 80016AF8 2078648C */  lw         $a0, %lo(g_pActiveMusicConfig)($v1)
    /* 72FC 80016AFC 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* 7300 80016B00 2867458C */  lw         $a1, %lo(D_80036728)($v0)
    /* 7304 80016B04 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 7308 80016B08 380091AC */  sw         $s1, 0x38($a0)
    /* 730C 80016B0C 100080AC */  sw         $zero, 0x10($a0)
    /* 7310 80016B10 0800628C */  lw         $v0, 0x8($v1)
    /* 7314 80016B14 23882502 */  subu       $s1, $s1, $a1
    /* 7318 80016B18 90004234 */  ori        $v0, $v0, 0x90
    /* 731C 80016B1C 080062AC */  sw         $v0, 0x8($v1)
    /* 7320 80016B20 3C00828C */  lw         $v0, 0x3C($a0)
    /* 7324 80016B24 0400958C */  lw         $s5, 0x4($a0)
    /* 7328 80016B28 1400838C */  lw         $v1, 0x14($a0)
    /* 732C 80016B2C 21105100 */  addu       $v0, $v0, $s1
    /* 7330 80016B30 3C0082AC */  sw         $v0, 0x3C($a0)
    /* 7334 80016B34 4000828C */  lw         $v0, 0x40($a0)
    /* 7338 80016B38 F4005026 */  addiu      $s0, $s2, 0xF4
    /* 733C 80016B3C 100083AC */  sw         $v1, 0x10($a0)
    /* 7340 80016B40 21105100 */  addu       $v0, $v0, $s1
    /* 7344 80016B44 400082AC */  sw         $v0, 0x40($a0)
  .L80016B48:
    /* 7348 80016B48 2410B302 */  and        $v0, $s5, $s3
    /* 734C 80016B4C 24004010 */  beqz       $v0, .L80016BE0
    /* 7350 80016B50 0100043C */   lui       $a0, (0x1FF93 >> 16)
    /* 7354 80016B54 0000428E */  lw         $v0, 0x0($s2)
    /* 7358 80016B58 93FF8434 */  ori        $a0, $a0, (0x1FF93 & 0xFFFF)
    /* 735C 80016B5C 21105100 */  addu       $v0, $v0, $s1
    /* 7360 80016B60 000042AE */  sw         $v0, 0x0($s2)
    /* 7364 80016B64 24FF028E */  lw         $v0, -0xDC($s0)
    /* 7368 80016B68 14FF038E */  lw         $v1, -0xEC($s0)
    /* 736C 80016B6C 21105100 */  addu       $v0, $v0, $s1
    /* 7370 80016B70 24FF02AE */  sw         $v0, -0xDC($s0)
    /* 7374 80016B74 10FF028E */  lw         $v0, -0xF0($s0)
    /* 7378 80016B78 21187100 */  addu       $v1, $v1, $s1
    /* 737C 80016B7C 14FF03AE */  sw         $v1, -0xEC($s0)
    /* 7380 80016B80 1CFF038E */  lw         $v1, -0xE4($s0)
    /* 7384 80016B84 21105100 */  addu       $v0, $v0, $s1
    /* 7388 80016B88 10FF02AE */  sw         $v0, -0xF0($s0)
    /* 738C 80016B8C 18FF028E */  lw         $v0, -0xE8($s0)
    /* 7390 80016B90 21187100 */  addu       $v1, $v1, $s1
    /* 7394 80016B94 1CFF03AE */  sw         $v1, -0xE4($s0)
    /* 7398 80016B98 74FF0396 */  lhu        $v1, -0x8C($s0)
    /* 739C 80016B9C 21105100 */  addu       $v0, $v0, $s1
    /* 73A0 80016BA0 18FF02AE */  sw         $v0, -0xE8($s0)
    /* 73A4 80016BA4 72FF0296 */  lhu        $v0, -0x8E($s0)
    /* 73A8 80016BA8 02006324 */  addiu      $v1, $v1, 0x2
    /* 73AC 80016BAC 74FF03A6 */  sh         $v1, -0x8C($s0)
    /* 73B0 80016BB0 0380033C */  lui        $v1, %hi(g_pActiveMusicConfig)
    /* 73B4 80016BB4 02004224 */  addiu      $v0, $v0, 0x2
    /* 73B8 80016BB8 72FF02A6 */  sh         $v0, -0x8E($s0)
    /* 73BC 80016BBC 0400028E */  lw         $v0, 0x4($s0)
    /* 73C0 80016BC0 2078638C */  lw         $v1, %lo(g_pActiveMusicConfig)($v1)
    /* 73C4 80016BC4 25104400 */  or         $v0, $v0, $a0
    /* 73C8 80016BC8 040002AE */  sw         $v0, 0x4($s0)
    /* 73CC 80016BCC 0000648C */  lw         $a0, 0x0($v1)
    /* 73D0 80016BD0 BF56000C */  jal        Sound_MapInstrumentToAltSampleBank
    /* 73D4 80016BD4 21284002 */   addu      $a1, $s2, $zero
    /* 73D8 80016BD8 FE5A0008 */  j          .L80016BF8
    /* 73DC 80016BDC 18000224 */   addiu     $v0, $zero, 0x18
  .L80016BE0:
    /* 73E0 80016BE0 04000224 */  addiu      $v0, $zero, 0x4
    /* 73E4 80016BE4 72FF02A6 */  sh         $v0, -0x8E($s0)
    /* 73E8 80016BE8 02000224 */  addiu      $v0, $zero, 0x2
    /* 73EC 80016BEC 74FF02A6 */  sh         $v0, -0x8C($s0)
    /* 73F0 80016BF0 000056AE */  sw         $s6, 0x0($s2)
    /* 73F4 80016BF4 18000224 */  addiu      $v0, $zero, 0x18
  .L80016BF8:
    /* 73F8 80016BF8 000002AE */  sw         $v0, 0x0($s0)
    /* 73FC 80016BFC FFFF9426 */  addiu      $s4, $s4, -0x1
    /* 7400 80016C00 10011026 */  addiu      $s0, $s0, 0x110
    /* 7404 80016C04 10015226 */  addiu      $s2, $s2, 0x110
    /* 7408 80016C08 CFFF8016 */  bnez       $s4, .L80016B48
    /* 740C 80016C0C 40981300 */   sll       $s3, $s3, 1
    /* 7410 80016C10 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 7414 80016C14 2866438C */  lw         $v1, %lo(g_pSavedMousicConfig)($v0)
    /* 7418 80016C18 00000000 */  nop
    /* 741C 80016C1C 07006010 */  beqz       $v1, .L80016C3C
    /* 7420 80016C20 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 7424 80016C24 D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* 7428 80016C28 0400658C */  lw         $a1, 0x4($v1)
    /* 742C 80016C2C 4E57000C */  jal        func_80015D38
    /* 7430 80016C30 00000000 */   nop
    /* 7434 80016C34 105B0008 */  j          .L80016C40
    /* 7438 80016C38 21A84000 */   addu      $s5, $v0, $zero
  .L80016C3C:
    /* 743C 80016C3C 21A80000 */  addu       $s5, $zero, $zero
  .L80016C40:
    /* 7440 80016C40 FF00073C */  lui        $a3, (0xFFFFFF >> 16)
    /* 7444 80016C44 0380093C */  lui        $t1, %hi(g_pActiveMusicConfig)
    /* 7448 80016C48 FFFFE734 */  ori        $a3, $a3, (0xFFFFFF & 0xFFFF)
    /* 744C 80016C4C 0380023C */  lui        $v0, %hi(D_800358FE)
    /* 7450 80016C50 2078288D */  lw         $t0, %lo(g_pActiveMusicConfig)($t1)
    /* 7454 80016C54 0480033C */  lui        $v1, %hi(D_80039B14)
    /* 7458 80016C58 180000AD */  sw         $zero, 0x18($t0)
    /* 745C 80016C5C FE5840A4 */  sh         $zero, %lo(D_800358FE)($v0)
    /* 7460 80016C60 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 7464 80016C64 90784624 */  addiu      $a2, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* 7468 80016C68 9078448C */  lw         $a0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 746C 80016C6C 149B628C */  lw         $v0, %lo(D_80039B14)($v1)
    /* 7470 80016C70 27281500 */  nor        $a1, $zero, $s5
    /* 7474 80016C74 27104400 */  nor        $v0, $v0, $a0
    /* 7478 80016C78 24104700 */  and        $v0, $v0, $a3
    /* 747C 80016C7C 2428A200 */  and        $a1, $a1, $v0
    /* 7480 80016C80 0480043C */  lui        $a0, %hi(g_Sound_GlobalFlags)
    /* 7484 80016C84 F89A8424 */  addiu      $a0, $a0, %lo(g_Sound_GlobalFlags)
    /* 7488 80016C88 0C00C28C */  lw         $v0, 0xC($a2)
    /* 748C 80016C8C 0800838C */  lw         $v1, 0x8($a0)
    /* 7490 80016C90 25104500 */  or         $v0, $v0, $a1
    /* 7494 80016C94 00016334 */  ori        $v1, $v1, 0x100
    /* 7498 80016C98 0C00C2AC */  sw         $v0, 0xC($a2)
    /* 749C 80016C9C 2C00E012 */  beqz       $s7, .L80016D50
    /* 74A0 80016CA0 080083AC */   sw        $v1, 0x8($a0)
    /* 74A4 80016CA4 6A000385 */  lh         $v1, 0x6A($t0)
    /* 74A8 80016CA8 5C00028D */  lw         $v0, 0x5C($t0)
    /* 74AC 80016CAC 00000000 */  nop
    /* 74B0 80016CB0 18004300 */  mult       $v0, $v1
    /* 74B4 80016CB4 30001324 */  addiu      $s3, $zero, 0x30
    /* 74B8 80016CB8 00F00524 */  addiu      $a1, $zero, -0x1000
    /* 74BC 80016CBC 5800028D */  lw         $v0, 0x58($t0)
    /* 74C0 80016CC0 12500000 */  mflo       $t2
    /* 74C4 80016CC4 21884A00 */  addu       $s1, $v0, $t2
    /* 74C8 80016CC8 02006010 */  beqz       $v1, .L80016CD4
    /* 74CC 80016CCC 24882502 */   and       $s1, $s1, $a1
    /* 74D0 80016CD0 21986000 */  addu       $s3, $v1, $zero
  .L80016CD4:
    /* 74D4 80016CD4 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 74D8 80016CD8 2866428C */  lw         $v0, %lo(g_pSavedMousicConfig)($v0)
    /* 74DC 80016CDC 00000000 */  nop
    /* 74E0 80016CE0 04004010 */  beqz       $v0, .L80016CF4
    /* 74E4 80016CE4 00000000 */   nop
    /* 74E8 80016CE8 5800428C */  lw         $v0, 0x58($v0)
    /* 74EC 80016CEC 00000000 */  nop
    /* 74F0 80016CF0 580002AD */  sw         $v0, 0x58($t0)
  .L80016CF4:
    /* 74F4 80016CF4 2078248D */  lw         $a0, %lo(g_pActiveMusicConfig)($t1)
    /* 74F8 80016CF8 00000000 */  nop
    /* 74FC 80016CFC 5800828C */  lw         $v0, 0x58($a0)
    /* 7500 80016D00 00000000 */  nop
    /* 7504 80016D04 24104500 */  and        $v0, $v0, $a1
    /* 7508 80016D08 23882202 */  subu       $s1, $s1, $v0
    /* 750C 80016D0C 0F002012 */  beqz       $s1, .L80016D4C
    /* 7510 80016D10 580082AC */   sw        $v0, 0x58($a0)
    /* 7514 80016D14 1A003302 */  div        $zero, $s1, $s3
    /* 7518 80016D18 02006016 */  bnez       $s3, .L80016D24
    /* 751C 80016D1C 00000000 */   nop
    /* 7520 80016D20 0D000700 */  break      7
  .L80016D24:
    /* 7524 80016D24 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 7528 80016D28 04006116 */  bne        $s3, $at, .L80016D3C
    /* 752C 80016D2C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 7530 80016D30 02002116 */  bne        $s1, $at, .L80016D3C
    /* 7534 80016D34 00000000 */   nop
    /* 7538 80016D38 0D000600 */  break      6
  .L80016D3C:
    /* 753C 80016D3C 12100000 */  mflo       $v0
    /* 7540 80016D40 6A0093A4 */  sh         $s3, 0x6A($a0)
    /* 7544 80016D44 545B0008 */  j          .L80016D50
    /* 7548 80016D48 5C0082AC */   sw        $v0, 0x5C($a0)
  .L80016D4C:
    /* 754C 80016D4C 6A0080A4 */  sh         $zero, 0x6A($a0)
  .L80016D50:
    /* 7550 80016D50 0480023C */  lui        $v0, %hi(D_80039B64)
    /* 7554 80016D54 649B428C */  lw         $v0, %lo(D_80039B64)($v0)
    /* 7558 80016D58 00000000 */  nop
    /* 755C 80016D5C 01004230 */  andi       $v0, $v0, 0x1
    /* 7560 80016D60 06004010 */  beqz       $v0, .L80016D7C
    /* 7564 80016D64 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* 7568 80016D68 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 756C 80016D6C 00000000 */  nop
    /* 7570 80016D70 0400438C */  lw         $v1, 0x4($v0)
    /* 7574 80016D74 040040AC */  sw         $zero, 0x4($v0)
    /* 7578 80016D78 1C0043AC */  sw         $v1, 0x1C($v0)
  .L80016D7C:
    /* 757C 80016D7C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 7580 80016D80 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 7584 80016D84 2800B68F */  lw         $s6, 0x28($sp)
    /* 7588 80016D88 2400B58F */  lw         $s5, 0x24($sp)
    /* 758C 80016D8C 2000B48F */  lw         $s4, 0x20($sp)
    /* 7590 80016D90 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7594 80016D94 1800B28F */  lw         $s2, 0x18($sp)
    /* 7598 80016D98 1400B18F */  lw         $s1, 0x14($sp)
    /* 759C 80016D9C 1000B08F */  lw         $s0, 0x10($sp)
    /* 75A0 80016DA0 0800E003 */  jr         $ra
    /* 75A4 80016DA4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel Sound_SetMusicSequence
