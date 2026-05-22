nonmatching Sound_Cmd_E4_SetCutsceneVolume, 0x70

glabel Sound_Cmd_E4_SetCutsceneVolume
    /* DEB8 8001D6B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DEBC 8001D6BC 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* DEC0 8001D6C0 1000B0AF */  sw         $s0, 0x10($sp)
    /* DEC4 8001D6C4 089B5024 */  addiu      $s0, $v0, %lo(g_Sound_Cutscene_StreamState)
    /* DEC8 8001D6C8 1400BFAF */  sw         $ra, 0x14($sp)
    /* DECC 8001D6CC 0000848C */  lw         $a0, 0x0($a0)
    /* DED0 8001D6D0 0C00028E */  lw         $v0, 0xC($s0)
    /* DED4 8001D6D4 480000AE */  sw         $zero, 0x48($s0)
    /* DED8 8001D6D8 0F004010 */  beqz       $v0, .L8001D718
    /* DEDC 8001D6DC 400004AE */   sw        $a0, 0x40($s0)
    /* DEE0 8001D6E0 C02B0400 */  sll        $a1, $a0, 15
    /* DEE4 8001D6E4 032C0500 */  sra        $a1, $a1, 16
    /* DEE8 8001D6E8 21300000 */  addu       $a2, $zero, $zero
    /* DEEC 8001D6EC 1000048E */  lw         $a0, 0x10($s0)
    /* DEF0 8001D6F0 D64E000C */  jal        SetVoiceVolume
    /* DEF4 8001D6F4 2138C000 */   addu      $a3, $a2, $zero
    /* DEF8 8001D6F8 21280000 */  addu       $a1, $zero, $zero
    /* DEFC 8001D6FC 2138A000 */  addu       $a3, $a1, $zero
    /* DF00 8001D700 1000048E */  lw         $a0, 0x10($s0)
    /* DF04 8001D704 4000068E */  lw         $a2, 0x40($s0)
    /* DF08 8001D708 01008424 */  addiu      $a0, $a0, 0x1
    /* DF0C 8001D70C C0330600 */  sll        $a2, $a2, 15
    /* DF10 8001D710 D64E000C */  jal        SetVoiceVolume
    /* DF14 8001D714 03340600 */   sra       $a2, $a2, 16
  .L8001D718:
    /* DF18 8001D718 1400BF8F */  lw         $ra, 0x14($sp)
    /* DF1C 8001D71C 1000B08F */  lw         $s0, 0x10($sp)
    /* DF20 8001D720 0800E003 */  jr         $ra
    /* DF24 8001D724 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_E4_SetCutsceneVolume
