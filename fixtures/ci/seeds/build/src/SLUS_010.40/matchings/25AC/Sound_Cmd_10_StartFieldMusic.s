nonmatching Sound_Cmd_10_StartFieldMusic, 0x7C

glabel Sound_Cmd_10_StartFieldMusic
    /* 75F8 80016DF8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 75FC 80016DFC 0380023C */  lui        $v0, %hi(g_PushedMusicConfig)
    /* 7600 80016E00 90584324 */  addiu      $v1, $v0, %lo(g_PushedMusicConfig)
    /* 7604 80016E04 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7608 80016E08 1000B0AF */  sw         $s0, 0x10($sp)
    /* 760C 80016E0C 6E006294 */  lhu        $v0, 0x6E($v1)
    /* 7610 80016E10 00000000 */  nop
    /* 7614 80016E14 0B004010 */  beqz       $v0, .L80016E44
    /* 7618 80016E18 21808000 */   addu      $s0, $a0, $zero
    /* 761C 80016E1C 21184000 */  addu       $v1, $v0, $zero
    /* 7620 80016E20 0800028E */  lw         $v0, 0x8($s0)
    /* 7624 80016E24 00000000 */  nop
    /* 7628 80016E28 06006214 */  bne        $v1, $v0, .L80016E44
    /* 762C 80016E2C 00000000 */   nop
    /* 7630 80016E30 0000048E */  lw         $a0, 0x0($s0)
    /* 7634 80016E34 805A000C */  jal        Sound_SetMusicSequence
    /* 7638 80016E38 21280000 */   addu      $a1, $zero, $zero
    /* 763C 80016E3C 995B0008 */  j          .L80016E64
    /* 7640 80016E40 00000000 */   nop
  .L80016E44:
    /* 7644 80016E44 0000048E */  lw         $a0, 0x0($s0)
    /* 7648 80016E48 6157000C */  jal        Sound_LoadAkaoSequence
    /* 764C 80016E4C 00000000 */   nop
    /* 7650 80016E50 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 7654 80016E54 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 7658 80016E58 08000296 */  lhu        $v0, 0x8($s0)
    /* 765C 80016E5C 00000000 */  nop
    /* 7660 80016E60 6E0062A4 */  sh         $v0, 0x6E($v1)
  .L80016E64:
    /* 7664 80016E64 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7668 80016E68 1000B08F */  lw         $s0, 0x10($sp)
    /* 766C 80016E6C 0800E003 */  jr         $ra
    /* 7670 80016E70 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_10_StartFieldMusic
