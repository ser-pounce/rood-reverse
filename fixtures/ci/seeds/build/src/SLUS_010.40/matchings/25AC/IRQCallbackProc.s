nonmatching IRQCallbackProc, 0x84

glabel IRQCallbackProc
    /* D54C 8001CD4C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* D550 8001CD50 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* D554 8001CD54 1000B0AF */  sw         $s0, 0x10($sp)
    /* D558 8001CD58 089B5024 */  addiu      $s0, $v0, %lo(g_Sound_Cutscene_StreamState)
    /* D55C 8001CD5C 1400BFAF */  sw         $ra, 0x14($sp)
    /* D560 8001CD60 0C00028E */  lw         $v0, 0xC($s0)
    /* D564 8001CD64 00000000 */  nop
    /* D568 8001CD68 15004010 */  beqz       $v0, .L8001CDC0
    /* D56C 8001CD6C 00000000 */   nop
    /* D570 8001CD70 457A000C */  jal        SpuSetIRQ
    /* D574 8001CD74 21200000 */   addu      $a0, $zero, $zero
    /* D578 8001CD78 A57A000C */  jal        SpuSetIRQCallback
    /* D57C 8001CD7C 21200000 */   addu      $a0, $zero, $zero
    /* D580 8001CD80 0C00048E */  lw         $a0, 0xC($s0)
    /* D584 8001CD84 BA4E000C */  jal        SetVoiceKeyOff
    /* D588 8001CD88 00000000 */   nop
    /* D58C 8001CD8C 0380053C */  lui        $a1, %hi(g_Sound_VoiceSchedulerState)
    /* D590 8001CD90 9078A524 */  addiu      $a1, $a1, %lo(g_Sound_VoiceSchedulerState)
    /* D594 8001CD94 0480043C */  lui        $a0, %hi(g_Sound_GlobalFlags)
    /* D598 8001CD98 0C00068E */  lw         $a2, 0xC($s0)
    /* D59C 8001CD9C F89A8424 */  addiu      $a0, $a0, %lo(g_Sound_GlobalFlags)
    /* D5A0 8001CDA0 0C0000AE */  sw         $zero, 0xC($s0)
    /* D5A4 8001CDA4 2000A28C */  lw         $v0, 0x20($a1)
    /* D5A8 8001CDA8 0800838C */  lw         $v1, 0x8($a0)
    /* D5AC 8001CDAC 27300600 */  nor        $a2, $zero, $a2
    /* D5B0 8001CDB0 24104600 */  and        $v0, $v0, $a2
    /* D5B4 8001CDB4 00016334 */  ori        $v1, $v1, 0x100
    /* D5B8 8001CDB8 2000A2AC */  sw         $v0, 0x20($a1)
    /* D5BC 8001CDBC 080083AC */  sw         $v1, 0x8($a0)
  .L8001CDC0:
    /* D5C0 8001CDC0 1400BF8F */  lw         $ra, 0x14($sp)
    /* D5C4 8001CDC4 1000B08F */  lw         $s0, 0x10($sp)
    /* D5C8 8001CDC8 0800E003 */  jr         $ra
    /* D5CC 8001CDCC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel IRQCallbackProc
