nonmatching func_8001D3D4, 0x64

glabel func_8001D3D4
    /* DBD4 8001D3D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DBD8 8001D3D8 01000524 */  addiu      $a1, $zero, 0x1
    /* DBDC 8001D3DC 00110624 */  addiu      $a2, $zero, 0x1100
    /* DBE0 8001D3E0 1000B0AF */  sw         $s0, 0x10($sp)
    /* DBE4 8001D3E4 0480103C */  lui        $s0, %hi(g_Sound_Cutscene_StreamState)
    /* DBE8 8001D3E8 089B1026 */  addiu      $s0, $s0, %lo(g_Sound_Cutscene_StreamState)
    /* DBEC 8001D3EC 1400BFAF */  sw         $ra, 0x14($sp)
    /* DBF0 8001D3F0 1000048E */  lw         $a0, 0x10($s0)
    /* DBF4 8001D3F4 3974000C */  jal        Sound_Cutscene_InitVoice
    /* DBF8 8001D3F8 00210724 */   addiu     $a3, $zero, 0x2100
    /* DBFC 8001D3FC 02000524 */  addiu      $a1, $zero, 0x2
    /* DC00 8001D400 00190624 */  addiu      $a2, $zero, 0x1900
    /* DC04 8001D404 1000048E */  lw         $a0, 0x10($s0)
    /* DC08 8001D408 00290724 */  addiu      $a3, $zero, 0x2900
    /* DC0C 8001D40C 3974000C */  jal        Sound_Cutscene_InitVoice
    /* DC10 8001D410 01008424 */   addiu     $a0, $a0, 0x1
    /* DC14 8001D414 00200424 */  addiu      $a0, $zero, 0x2000
    /* DC18 8001D418 00210524 */  addiu      $a1, $zero, 0x2100
    /* DC1C 8001D41C 0280063C */  lui        $a2, %hi(func_8001D5E4)
    /* DC20 8001D420 A874000C */  jal        Sound_Cutscene_BeginPlayback
    /* DC24 8001D424 E4D5C624 */   addiu     $a2, $a2, %lo(func_8001D5E4)
    /* DC28 8001D428 1400BF8F */  lw         $ra, 0x14($sp)
    /* DC2C 8001D42C 1000B08F */  lw         $s0, 0x10($sp)
    /* DC30 8001D430 0800E003 */  jr         $ra
    /* DC34 8001D434 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001D3D4
