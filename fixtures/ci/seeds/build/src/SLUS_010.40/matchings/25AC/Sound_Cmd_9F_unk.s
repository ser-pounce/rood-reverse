nonmatching Sound_Cmd_9F_unk, 0x50

glabel Sound_Cmd_9F_unk
    /* 9334 80018B34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9338 80018B38 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* 933C 80018B3C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 9340 80018B40 089B5024 */  addiu      $s0, $v0, %lo(g_Sound_Cutscene_StreamState)
    /* 9344 80018B44 1400BFAF */  sw         $ra, 0x14($sp)
    /* 9348 80018B48 0C00028E */  lw         $v0, 0xC($s0)
    /* 934C 80018B4C 00000000 */  nop
    /* 9350 80018B50 08004010 */  beqz       $v0, .L80018B74
    /* 9354 80018B54 00000000 */   nop
    /* 9358 80018B58 1000048E */  lw         $a0, 0x10($s0)
    /* 935C 80018B5C E84E000C */  jal        SetVoiceSampleRate
    /* 9360 80018B60 21280000 */   addu      $a1, $zero, $zero
    /* 9364 80018B64 1000048E */  lw         $a0, 0x10($s0)
    /* 9368 80018B68 21280000 */  addu       $a1, $zero, $zero
    /* 936C 80018B6C E84E000C */  jal        SetVoiceSampleRate
    /* 9370 80018B70 01008424 */   addiu     $a0, $a0, 0x1
  .L80018B74:
    /* 9374 80018B74 1400BF8F */  lw         $ra, 0x14($sp)
    /* 9378 80018B78 1000B08F */  lw         $s0, 0x10($sp)
    /* 937C 80018B7C 0800E003 */  jr         $ra
    /* 9380 80018B80 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_9F_unk
