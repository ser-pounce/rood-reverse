nonmatching Sound_Cmd_9E_unk, 0x54

glabel Sound_Cmd_9E_unk
    /* 9384 80018B84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 9388 80018B88 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* 938C 80018B8C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 9390 80018B90 089B5024 */  addiu      $s0, $v0, %lo(g_Sound_Cutscene_StreamState)
    /* 9394 80018B94 1400BFAF */  sw         $ra, 0x14($sp)
    /* 9398 80018B98 0C00028E */  lw         $v0, 0xC($s0)
    /* 939C 80018B9C 00000000 */  nop
    /* 93A0 80018BA0 09004010 */  beqz       $v0, .L80018BC8
    /* 93A4 80018BA4 00000000 */   nop
    /* 93A8 80018BA8 1000048E */  lw         $a0, 0x10($s0)
    /* 93AC 80018BAC 5800058E */  lw         $a1, 0x58($s0)
    /* 93B0 80018BB0 E84E000C */  jal        SetVoiceSampleRate
    /* 93B4 80018BB4 00000000 */   nop
    /* 93B8 80018BB8 1000048E */  lw         $a0, 0x10($s0)
    /* 93BC 80018BBC 5800058E */  lw         $a1, 0x58($s0)
    /* 93C0 80018BC0 E84E000C */  jal        SetVoiceSampleRate
    /* 93C4 80018BC4 01008424 */   addiu     $a0, $a0, 0x1
  .L80018BC8:
    /* 93C8 80018BC8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 93CC 80018BCC 1000B08F */  lw         $s0, 0x10($sp)
    /* 93D0 80018BD0 0800E003 */  jr         $ra
    /* 93D4 80018BD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_9E_unk
