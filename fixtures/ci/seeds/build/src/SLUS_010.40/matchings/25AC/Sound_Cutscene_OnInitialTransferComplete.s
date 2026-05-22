nonmatching Sound_Cutscene_OnInitialTransferComplete, 0x64

glabel Sound_Cutscene_OnInitialTransferComplete
    /* DB70 8001D370 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DB74 8001D374 21280000 */  addu       $a1, $zero, $zero
    /* DB78 8001D378 00110624 */  addiu      $a2, $zero, 0x1100
    /* DB7C 8001D37C 1000B0AF */  sw         $s0, 0x10($sp)
    /* DB80 8001D380 0480103C */  lui        $s0, %hi(g_Sound_Cutscene_StreamState)
    /* DB84 8001D384 089B1026 */  addiu      $s0, $s0, %lo(g_Sound_Cutscene_StreamState)
    /* DB88 8001D388 1400BFAF */  sw         $ra, 0x14($sp)
    /* DB8C 8001D38C 1000048E */  lw         $a0, 0x10($s0)
    /* DB90 8001D390 3974000C */  jal        Sound_Cutscene_InitVoice
    /* DB94 8001D394 00210724 */   addiu     $a3, $zero, 0x2100
    /* DB98 8001D398 21280000 */  addu       $a1, $zero, $zero
    /* DB9C 8001D39C 00110624 */  addiu      $a2, $zero, 0x1100
    /* DBA0 8001D3A0 1000048E */  lw         $a0, 0x10($s0)
    /* DBA4 8001D3A4 00210724 */  addiu      $a3, $zero, 0x2100
    /* DBA8 8001D3A8 3974000C */  jal        Sound_Cutscene_InitVoice
    /* DBAC 8001D3AC 01008424 */   addiu     $a0, $a0, 0x1
    /* DBB0 8001D3B0 00100424 */  addiu      $a0, $zero, 0x1000
    /* DBB4 8001D3B4 00210524 */  addiu      $a1, $zero, 0x2100
    /* DBB8 8001D3B8 0280063C */  lui        $a2, %hi(Sound_Cutscene_OnBufferAComplete)
    /* DBBC 8001D3BC A874000C */  jal        Sound_Cutscene_BeginPlayback
    /* DBC0 8001D3C0 84D5C624 */   addiu     $a2, $a2, %lo(Sound_Cutscene_OnBufferAComplete)
    /* DBC4 8001D3C4 1400BF8F */  lw         $ra, 0x14($sp)
    /* DBC8 8001D3C8 1000B08F */  lw         $s0, 0x10($sp)
    /* DBCC 8001D3CC 0800E003 */  jr         $ra
    /* DBD0 8001D3D0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cutscene_OnInitialTransferComplete
