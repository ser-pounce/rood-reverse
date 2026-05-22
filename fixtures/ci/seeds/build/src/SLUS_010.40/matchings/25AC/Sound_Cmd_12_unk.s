nonmatching Sound_Cmd_12_unk, 0x40

glabel Sound_Cmd_12_unk
    /* 79C8 800171C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 79CC 800171CC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 79D0 800171D0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 79D4 800171D4 7E5B000C */  jal        Sound_Cmd_10_StartFieldMusic
    /* 79D8 800171D8 21808000 */   addu      $s0, $a0, $zero
    /* 79DC 800171DC 0C00028E */  lw         $v0, 0xC($s0)
    /* 79E0 800171E0 00000000 */  nop
    /* 79E4 800171E4 02004010 */  beqz       $v0, .L800171F0
    /* 79E8 800171E8 21180000 */   addu      $v1, $zero, $zero
    /* 79EC 800171EC FFFF4324 */  addiu      $v1, $v0, -0x1
  .L800171F0:
    /* 79F0 800171F0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 79F4 800171F4 1000B08F */  lw         $s0, 0x10($sp)
    /* 79F8 800171F8 0380023C */  lui        $v0, %hi(g_Music_LoopCounter)
    /* 79FC 800171FC D87743AC */  sw         $v1, %lo(g_Music_LoopCounter)($v0)
    /* 7A00 80017200 0800E003 */  jr         $ra
    /* 7A04 80017204 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_12_unk
