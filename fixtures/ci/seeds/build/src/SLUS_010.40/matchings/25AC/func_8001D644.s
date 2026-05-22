nonmatching func_8001D644, 0x54

glabel func_8001D644
    /* DE44 8001D644 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DE48 8001D648 1000B0AF */  sw         $s0, 0x10($sp)
    /* DE4C 8001D64C 1400BFAF */  sw         $ra, 0x14($sp)
    /* DE50 8001D650 5373000C */  jal        IRQCallbackProc
    /* DE54 8001D654 21808000 */   addu      $s0, $a0, $zero
    /* DE58 8001D658 0000048E */  lw         $a0, 0x0($s0)
    /* DE5C 8001D65C 0400058E */  lw         $a1, 0x4($s0)
    /* DE60 8001D660 0800068E */  lw         $a2, 0x8($s0)
    /* DE64 8001D664 AA73000C */  jal        Sound_Cutscene_StartStream
    /* DE68 8001D668 00000000 */   nop
    /* DE6C 8001D66C 0380043C */  lui        $a0, %hi(g_Sound_VoiceSchedulerState)
    /* DE70 8001D670 0480023C */  lui        $v0, %hi(D_80039B14)
    /* DE74 8001D674 149B428C */  lw         $v0, %lo(D_80039B14)($v0)
    /* DE78 8001D678 9078838C */  lw         $v1, %lo(g_Sound_VoiceSchedulerState)($a0)
    /* DE7C 8001D67C 1400BF8F */  lw         $ra, 0x14($sp)
    /* DE80 8001D680 1000B08F */  lw         $s0, 0x10($sp)
    /* DE84 8001D684 27100200 */  nor        $v0, $zero, $v0
    /* DE88 8001D688 24186200 */  and        $v1, $v1, $v0
    /* DE8C 8001D68C 907883AC */  sw         $v1, %lo(g_Sound_VoiceSchedulerState)($a0)
    /* DE90 8001D690 0800E003 */  jr         $ra
    /* DE94 8001D694 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001D644
