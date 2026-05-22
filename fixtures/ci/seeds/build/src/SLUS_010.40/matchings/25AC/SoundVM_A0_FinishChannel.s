nonmatching SoundVM_A0_FinishChannel, 0xD4

glabel SoundVM_A0_FinishChannel
    /* B938 8001B138 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B93C 8001B13C 1000B0AF */  sw         $s0, 0x10($sp)
    /* B940 8001B140 21808000 */  addu       $s0, $a0, $zero
    /* B944 8001B144 1400BFAF */  sw         $ra, 0x14($sp)
    /* B948 8001B148 64000296 */  lhu        $v0, 0x64($s0)
    /* B94C 8001B14C 00000000 */  nop
    /* B950 8001B150 21004014 */  bnez       $v0, .L8001B1D8
    /* B954 8001B154 0380043C */   lui       $a0, %hi(g_pActiveMusicConfig)
    /* B958 8001B158 2078838C */  lw         $v1, %lo(g_pActiveMusicConfig)($a0)
    /* B95C 8001B15C 00000000 */  nop
    /* B960 8001B160 0400628C */  lw         $v0, 0x4($v1)
    /* B964 8001B164 27280500 */  nor        $a1, $zero, $a1
    /* B968 8001B168 24104500 */  and        $v0, $v0, $a1
    /* B96C 8001B16C 05004014 */  bnez       $v0, .L8001B184
    /* B970 8001B170 040062AC */   sw        $v0, 0x4($v1)
    /* B974 8001B174 0380023C */  lui        $v0, %hi(g_Music_LoopCounter)
    /* B978 8001B178 D87740AC */  sw         $zero, %lo(g_Music_LoopCounter)($v0)
    /* B97C 8001B17C 6E0060A4 */  sh         $zero, 0x6E($v1)
    /* B980 8001B180 000060AC */  sw         $zero, 0x0($v1)
  .L8001B184:
    /* B984 8001B184 2078838C */  lw         $v1, %lo(g_pActiveMusicConfig)($a0)
    /* B988 8001B188 00000000 */  nop
    /* B98C 8001B18C 1400628C */  lw         $v0, 0x14($v1)
    /* B990 8001B190 0800648C */  lw         $a0, 0x8($v1)
    /* B994 8001B194 24104500 */  and        $v0, $v0, $a1
    /* B998 8001B198 140062AC */  sw         $v0, 0x14($v1)
    /* B99C 8001B19C 0C00628C */  lw         $v0, 0xC($v1)
    /* B9A0 8001B1A0 24208500 */  and        $a0, $a0, $a1
    /* B9A4 8001B1A4 080064AC */  sw         $a0, 0x8($v1)
    /* B9A8 8001B1A8 4C00648C */  lw         $a0, 0x4C($v1)
    /* B9AC 8001B1AC 24104500 */  and        $v0, $v0, $a1
    /* B9B0 8001B1B0 0C0062AC */  sw         $v0, 0xC($v1)
    /* B9B4 8001B1B4 5000628C */  lw         $v0, 0x50($v1)
    /* B9B8 8001B1B8 24208500 */  and        $a0, $a0, $a1
    /* B9BC 8001B1BC 4C0064AC */  sw         $a0, 0x4C($v1)
    /* B9C0 8001B1C0 5400648C */  lw         $a0, 0x54($v1)
    /* B9C4 8001B1C4 24104500 */  and        $v0, $v0, $a1
    /* B9C8 8001B1C8 24208500 */  and        $a0, $a0, $a1
    /* B9CC 8001B1CC 500062AC */  sw         $v0, 0x50($v1)
    /* B9D0 8001B1D0 786C0008 */  j          .L8001B1E0
    /* B9D4 8001B1D4 540064AC */   sw        $a0, 0x54($v1)
  .L8001B1D8:
    /* B9D8 8001B1D8 336C000C */  jal        Sound_ClearVoiceFromSchedulerState
    /* B9DC 8001B1DC 21200002 */   addu      $a0, $s0, $zero
  .L8001B1E0:
    /* B9E0 8001B1E0 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* B9E4 8001B1E4 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* B9E8 8001B1E8 340000AE */  sw         $zero, 0x34($s0)
    /* B9EC 8001B1EC 0800628C */  lw         $v0, 0x8($v1)
    /* B9F0 8001B1F0 00000000 */  nop
    /* B9F4 8001B1F4 10014234 */  ori        $v0, $v0, 0x110
    /* B9F8 8001B1F8 080062AC */  sw         $v0, 0x8($v1)
    /* B9FC 8001B1FC 1400BF8F */  lw         $ra, 0x14($sp)
    /* BA00 8001B200 1000B08F */  lw         $s0, 0x10($sp)
    /* BA04 8001B204 0800E003 */  jr         $ra
    /* BA08 8001B208 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel SoundVM_A0_FinishChannel
