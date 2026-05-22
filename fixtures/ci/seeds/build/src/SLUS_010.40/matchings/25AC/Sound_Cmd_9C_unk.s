nonmatching Sound_Cmd_9C_unk, 0x94

glabel Sound_Cmd_9C_unk
    /* 92A0 80018AA0 0380023C */  lui        $v0, %hi(D_800378A0)
    /* 92A4 80018AA4 A078428C */  lw         $v0, %lo(D_800378A0)($v0)
    /* 92A8 80018AA8 00000000 */  nop
    /* 92AC 80018AAC 1B004010 */  beqz       $v0, .L80018B1C
    /* 92B0 80018AB0 21304000 */   addu      $a2, $v0, $zero
    /* 92B4 80018AB4 00100524 */  addiu      $a1, $zero, 0x1000
    /* 92B8 80018AB8 0380023C */  lui        $v0, %hi(D_80035910)
    /* 92BC 80018ABC 10594224 */  addiu      $v0, $v0, %lo(D_80035910)
    /* 92C0 80018AC0 F8004424 */  addiu      $a0, $v0, 0xF8
  .L80018AC4:
    /* 92C4 80018AC4 2410C500 */  and        $v0, $a2, $a1
    /* 92C8 80018AC8 05004010 */  beqz       $v0, .L80018AE0
    /* 92CC 80018ACC 27180500 */   nor       $v1, $zero, $a1
    /* 92D0 80018AD0 0000828C */  lw         $v0, 0x0($a0)
    /* 92D4 80018AD4 2430C300 */  and        $a2, $a2, $v1
    /* 92D8 80018AD8 132B4234 */  ori        $v0, $v0, 0x2B13
    /* 92DC 80018ADC 000082AC */  sw         $v0, 0x0($a0)
  .L80018AE0:
    /* 92E0 80018AE0 40280500 */  sll        $a1, $a1, 1
    /* 92E4 80018AE4 F7FFC014 */  bnez       $a2, .L80018AC4
    /* 92E8 80018AE8 10018424 */   addiu     $a0, $a0, 0x110
    /* 92EC 80018AEC 0380053C */  lui        $a1, %hi(g_Sound_VoiceSchedulerState)
    /* 92F0 80018AF0 9078A224 */  addiu      $v0, $a1, %lo(g_Sound_VoiceSchedulerState)
    /* 92F4 80018AF4 0480043C */  lui        $a0, %hi(g_Sound_GlobalFlags)
    /* 92F8 80018AF8 1000468C */  lw         $a2, 0x10($v0)
    /* 92FC 80018AFC F89A8424 */  addiu      $a0, $a0, %lo(g_Sound_GlobalFlags)
    /* 9300 80018B00 100040AC */  sw         $zero, 0x10($v0)
    /* 9304 80018B04 9078A28C */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($a1)
    /* 9308 80018B08 0800838C */  lw         $v1, 0x8($a0)
    /* 930C 80018B0C 25104600 */  or         $v0, $v0, $a2
    /* 9310 80018B10 00016334 */  ori        $v1, $v1, 0x100
    /* 9314 80018B14 9078A2AC */  sw         $v0, %lo(g_Sound_VoiceSchedulerState)($a1)
    /* 9318 80018B18 080083AC */  sw         $v1, 0x8($a0)
  .L80018B1C:
    /* 931C 80018B1C 0480023C */  lui        $v0, %hi(D_80039B64)
    /* 9320 80018B20 649B438C */  lw         $v1, %lo(D_80039B64)($v0)
    /* 9324 80018B24 FDFF0424 */  addiu      $a0, $zero, -0x3
    /* 9328 80018B28 24186400 */  and        $v1, $v1, $a0
    /* 932C 80018B2C 0800E003 */  jr         $ra
    /* 9330 80018B30 649B43AC */   sw        $v1, %lo(D_80039B64)($v0)
endlabel Sound_Cmd_9C_unk
