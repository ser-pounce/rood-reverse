nonmatching Sound_Cutscene_OnBufferBComplete, 0x30

glabel Sound_Cutscene_OnBufferBComplete
    /* DDB4 8001D5B4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DDB8 8001D5B8 0280073C */  lui        $a3, %hi(Sound_Cutscene_OnBufferAComplete)
    /* DDBC 8001D5BC 00210424 */  addiu      $a0, $zero, 0x2100
    /* DDC0 8001D5C0 21288000 */  addu       $a1, $a0, $zero
    /* DDC4 8001D5C4 00080624 */  addiu      $a2, $zero, 0x800
    /* DDC8 8001D5C8 1000BFAF */  sw         $ra, 0x10($sp)
    /* DDCC 8001D5CC 0E75000C */  jal        Sound_Cutscene_LoadNextBuffer
    /* DDD0 8001D5D0 84D5E724 */   addiu     $a3, $a3, %lo(Sound_Cutscene_OnBufferAComplete)
    /* DDD4 8001D5D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* DDD8 8001D5D8 00000000 */  nop
    /* DDDC 8001D5DC 0800E003 */  jr         $ra
    /* DDE0 8001D5E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cutscene_OnBufferBComplete
