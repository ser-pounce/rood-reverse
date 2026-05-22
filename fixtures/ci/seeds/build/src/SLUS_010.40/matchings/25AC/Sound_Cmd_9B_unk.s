nonmatching Sound_Cmd_9B_unk, 0xF0

glabel Sound_Cmd_9B_unk
    /* 8FF8 800187F8 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 8FFC 800187FC 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 9000 80018800 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 9004 80018804 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 9008 80018808 1800B2AF */  sw         $s2, 0x18($sp)
    /* 900C 8001880C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 9010 80018810 1000B0AF */  sw         $s0, 0x10($sp)
    /* 9014 80018814 0400428C */  lw         $v0, 0x4($v0)
    /* 9018 80018818 00000000 */  nop
    /* 901C 8001881C 28004010 */  beqz       $v0, .L800188C0
    /* 9020 80018820 FF00053C */   lui       $a1, (0xFFFFFF >> 16)
    /* 9024 80018824 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 9028 80018828 0480033C */  lui        $v1, %hi(D_80039B14)
    /* 902C 8001882C 9078448C */  lw         $a0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 9030 80018830 149B628C */  lw         $v0, %lo(D_80039B14)($v1)
    /* 9034 80018834 FFFFA534 */  ori        $a1, $a1, (0xFFFFFF & 0xFFFF)
    /* 9038 80018838 27104400 */  nor        $v0, $v0, $a0
    /* 903C 8001883C 24884500 */  and        $s1, $v0, $a1
    /* 9040 80018840 19002012 */  beqz       $s1, .L800188A8
    /* 9044 80018844 01001224 */   addiu     $s2, $zero, 0x1
    /* 9048 80018848 21800000 */  addu       $s0, $zero, $zero
  .L8001884C:
    /* 904C 8001884C 24103202 */  and        $v0, $s1, $s2
    /* 9050 80018850 12004010 */  beqz       $v0, .L8001889C
    /* 9054 80018854 21200002 */   addu      $a0, $s0, $zero
    /* 9058 80018858 21280000 */  addu       $a1, $zero, $zero
    /* 905C 8001885C 2130A000 */  addu       $a2, $a1, $zero
    /* 9060 80018860 D64E000C */  jal        SetVoiceVolume
    /* 9064 80018864 2138A000 */   addu      $a3, $a1, $zero
    /* 9068 80018868 21200002 */  addu       $a0, $s0, $zero
    /* 906C 8001886C E84E000C */  jal        SetVoiceSampleRate
    /* 9070 80018870 21280000 */   addu      $a1, $zero, $zero
    /* 9074 80018874 21200002 */  addu       $a0, $s0, $zero
    /* 9078 80018878 7F000524 */  addiu      $a1, $zero, 0x7F
    /* 907C 8001887C 084F000C */  jal        SetVoiceAdsrAttackRateAndMode
    /* 9080 80018880 01000624 */   addiu     $a2, $zero, 0x1
    /* 9084 80018884 21200002 */  addu       $a0, $s0, $zero
    /* 9088 80018888 7F000524 */  addiu      $a1, $zero, 0x7F
    /* 908C 8001888C 284F000C */  jal        SetVoiceAdsrSustainRateAndDirection
    /* 9090 80018890 03000624 */   addiu     $a2, $zero, 0x3
    /* 9094 80018894 27101200 */  nor        $v0, $zero, $s2
    /* 9098 80018898 24882202 */  and        $s1, $s1, $v0
  .L8001889C:
    /* 909C 8001889C 40901200 */  sll        $s2, $s2, 1
    /* 90A0 800188A0 EAFF2016 */  bnez       $s1, .L8001884C
    /* 90A4 800188A4 01001026 */   addiu     $s0, $s0, 0x1
  .L800188A8:
    /* 90A8 800188A8 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 90AC 800188AC 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 90B0 800188B0 00000000 */  nop
    /* 90B4 800188B4 0400438C */  lw         $v1, 0x4($v0)
    /* 90B8 800188B8 040040AC */  sw         $zero, 0x4($v0)
    /* 90BC 800188BC 1C0043AC */  sw         $v1, 0x1C($v0)
  .L800188C0:
    /* 90C0 800188C0 0480033C */  lui        $v1, %hi(D_80039B64)
    /* 90C4 800188C4 649B628C */  lw         $v0, %lo(D_80039B64)($v1)
    /* 90C8 800188C8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 90CC 800188CC 1800B28F */  lw         $s2, 0x18($sp)
    /* 90D0 800188D0 1400B18F */  lw         $s1, 0x14($sp)
    /* 90D4 800188D4 1000B08F */  lw         $s0, 0x10($sp)
    /* 90D8 800188D8 01004234 */  ori        $v0, $v0, 0x1
    /* 90DC 800188DC 649B62AC */  sw         $v0, %lo(D_80039B64)($v1)
    /* 90E0 800188E0 0800E003 */  jr         $ra
    /* 90E4 800188E4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Sound_Cmd_9B_unk
