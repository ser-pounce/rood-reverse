nonmatching Sound_KillMusicConfig, 0xD4

glabel Sound_KillMusicConfig
    /* 68F0 800160F0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 68F4 800160F4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 68F8 800160F8 21908000 */  addu       $s2, $a0, $zero
    /* 68FC 800160FC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6900 80016100 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6904 80016104 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6908 80016108 0400428E */  lw         $v0, 0x4($s2)
    /* 690C 8001610C 00000000 */  nop
    /* 6910 80016110 26004010 */  beqz       $v0, .L800161AC
    /* 6914 80016114 00000000 */   nop
    /* 6918 80016118 0500C010 */  beqz       $a2, .L80016130
    /* 691C 8001611C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6920 80016120 6E004296 */  lhu        $v0, 0x6E($s2)
    /* 6924 80016124 00000000 */  nop
    /* 6928 80016128 2000C214 */  bne        $a2, $v0, .L800161AC
    /* 692C 8001612C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L80016130:
    /* 6930 80016130 180042AE */  sw         $v0, 0x18($s2)
    /* 6934 80016134 20001024 */  addiu      $s0, $zero, 0x20
    /* 6938 80016138 03000624 */  addiu      $a2, $zero, 0x3
    /* 693C 8001613C 01000424 */  addiu      $a0, $zero, 0x1
    /* 6940 80016140 0380023C */  lui        $v0, %hi(g_Sound_ProgramCounter)
    /* 6944 80016144 38F64224 */  addiu      $v0, $v0, %lo(g_Sound_ProgramCounter)
    /* 6948 80016148 6800A324 */  addiu      $v1, $a1, 0x68
  .L8001614C:
    /* 694C 8001614C FEFF66A4 */  sh         $a2, -0x2($v1)
    /* 6950 80016150 000064A4 */  sh         $a0, 0x0($v1)
    /* 6954 80016154 10016324 */  addiu      $v1, $v1, 0x110
    /* 6958 80016158 0000A2AC */  sw         $v0, 0x0($a1)
    /* 695C 8001615C FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 6960 80016160 FAFF0016 */  bnez       $s0, .L8001614C
    /* 6964 80016164 1001A524 */   addiu     $a1, $a1, 0x110
    /* 6968 80016168 0480023C */  lui        $v0, %hi(g_Sound_VoiceChannelConfigs)
    /* 696C 8001616C 689B5124 */  addiu      $s1, $v0, %lo(g_Sound_VoiceChannelConfigs)
    /* 6970 80016170 6E0040A6 */  sh         $zero, 0x6E($s2)
    /* 6974 80016174 140040AE */  sw         $zero, 0x14($s2)
    /* 6978 80016178 100040AE */  sw         $zero, 0x10($s2)
  .L8001617C:
    /* 697C 8001617C 0000228E */  lw         $v0, 0x0($s1)
    /* 6980 80016180 00000000 */  nop
    /* 6984 80016184 05005214 */  bne        $v0, $s2, .L8001619C
    /* 6988 80016188 21200002 */   addu      $a0, $s0, $zero
    /* 698C 8001618C 000020AE */  sw         $zero, 0x0($s1)
    /* 6990 80016190 05000524 */  addiu      $a1, $zero, 0x5
    /* 6994 80016194 354F000C */  jal        SetVoiceAdsrReleaseRateAndMode
    /* 6998 80016198 03000624 */   addiu     $a2, $zero, 0x3
  .L8001619C:
    /* 699C 8001619C 01001026 */  addiu      $s0, $s0, 0x1
    /* 69A0 800161A0 1800022E */  sltiu      $v0, $s0, 0x18
    /* 69A4 800161A4 F5FF4014 */  bnez       $v0, .L8001617C
    /* 69A8 800161A8 04003126 */   addiu     $s1, $s1, 0x4
  .L800161AC:
    /* 69AC 800161AC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 69B0 800161B0 1800B28F */  lw         $s2, 0x18($sp)
    /* 69B4 800161B4 1400B18F */  lw         $s1, 0x14($sp)
    /* 69B8 800161B8 1000B08F */  lw         $s0, 0x10($sp)
    /* 69BC 800161BC 0800E003 */  jr         $ra
    /* 69C0 800161C0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Sound_KillMusicConfig
