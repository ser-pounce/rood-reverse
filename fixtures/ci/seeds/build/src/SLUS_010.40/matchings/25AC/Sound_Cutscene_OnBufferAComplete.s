nonmatching Sound_Cutscene_OnBufferAComplete, 0x30

glabel Sound_Cutscene_OnBufferAComplete
    /* DD84 8001D584 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DD88 8001D588 0280073C */  lui        $a3, %hi(Sound_Cutscene_OnBufferBComplete)
    /* DD8C 8001D58C 00110424 */  addiu      $a0, $zero, 0x1100
    /* DD90 8001D590 21288000 */  addu       $a1, $a0, $zero
    /* DD94 8001D594 00080624 */  addiu      $a2, $zero, 0x800
    /* DD98 8001D598 1000BFAF */  sw         $ra, 0x10($sp)
    /* DD9C 8001D59C 0E75000C */  jal        Sound_Cutscene_LoadNextBuffer
    /* DDA0 8001D5A0 B4D5E724 */   addiu     $a3, $a3, %lo(Sound_Cutscene_OnBufferBComplete)
    /* DDA4 8001D5A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* DDA8 8001D5A8 00000000 */  nop
    /* DDAC 8001D5AC 0800E003 */  jr         $ra
    /* DDB0 8001D5B0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cutscene_OnBufferAComplete
