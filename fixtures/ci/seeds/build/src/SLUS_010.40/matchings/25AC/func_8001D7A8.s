nonmatching func_8001D7A8, 0x14C

glabel func_8001D7A8
    /* DFA8 8001D7A8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* DFAC 8001D7AC 0480023C */  lui        $v0, %hi(g_Sound_Cutscene_StreamState)
    /* DFB0 8001D7B0 1800B2AF */  sw         $s2, 0x18($sp)
    /* DFB4 8001D7B4 089B5224 */  addiu      $s2, $v0, %lo(g_Sound_Cutscene_StreamState)
    /* DFB8 8001D7B8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* DFBC 8001D7BC 1400B1AF */  sw         $s1, 0x14($sp)
    /* DFC0 8001D7C0 1000B0AF */  sw         $s0, 0x10($sp)
    /* DFC4 8001D7C4 0000838C */  lw         $v1, 0x0($a0)
    /* DFC8 8001D7C8 0C00428E */  lw         $v0, 0xC($s2)
    /* DFCC 8001D7CC 00000000 */  nop
    /* DFD0 8001D7D0 42004010 */  beqz       $v0, .L8001D8DC
    /* DFD4 8001D7D4 4C0043AE */   sw        $v1, 0x4C($s2)
    /* DFD8 8001D7D8 0480023C */  lui        $v0, %hi(D_80039AFC)
    /* DFDC 8001D7DC FC9A428C */  lw         $v0, %lo(D_80039AFC)($v0)
    /* DFE0 8001D7E0 00000000 */  nop
    /* DFE4 8001D7E4 02004230 */  andi       $v0, $v0, 0x2
    /* DFE8 8001D7E8 0F004010 */  beqz       $v0, .L8001D828
    /* DFEC 8001D7EC 0380023C */   lui       $v0, %hi(D_8002F89C)
    /* DFF0 8001D7F0 9CF84384 */  lh         $v1, %lo(D_8002F89C)($v0)
    /* DFF4 8001D7F4 4000428E */  lw         $v0, 0x40($s2)
    /* DFF8 8001D7F8 00000000 */  nop
    /* DFFC 8001D7FC 18004300 */  mult       $v0, $v1
    /* E000 8001D800 21380000 */  addu       $a3, $zero, $zero
    /* E004 8001D804 1000448E */  lw         $a0, 0x10($s2)
    /* E008 8001D808 12400000 */  mflo       $t0
    /* E00C 8001D80C 03840800 */  sra        $s0, $t0, 16
    /* E010 8001D810 21280002 */  addu       $a1, $s0, $zero
    /* E014 8001D814 D64E000C */  jal        SetVoiceVolume
    /* E018 8001D818 21300002 */   addu      $a2, $s0, $zero
    /* E01C 8001D81C 21280002 */  addu       $a1, $s0, $zero
    /* E020 8001D820 33760008 */  j          .L8001D8CC
    /* E024 8001D824 2130A000 */   addu      $a2, $a1, $zero
  .L8001D828:
    /* E028 8001D828 0800428E */  lw         $v0, 0x8($s2)
    /* E02C 8001D82C 00000000 */  nop
    /* E030 8001D830 01004230 */  andi       $v0, $v0, 0x1
    /* E034 8001D834 0B004010 */  beqz       $v0, .L8001D864
    /* E038 8001D838 031A0300 */   sra       $v1, $v1, 8
    /* E03C 8001D83C 21300000 */  addu       $a2, $zero, $zero
    /* E040 8001D840 2138C000 */  addu       $a3, $a2, $zero
    /* E044 8001D844 4000508E */  lw         $s0, 0x40($s2)
    /* E048 8001D848 1000448E */  lw         $a0, 0x10($s2)
    /* E04C 8001D84C C0831000 */  sll        $s0, $s0, 15
    /* E050 8001D850 03841000 */  sra        $s0, $s0, 16
    /* E054 8001D854 D64E000C */  jal        SetVoiceVolume
    /* E058 8001D858 21280002 */   addu      $a1, $s0, $zero
    /* E05C 8001D85C 32760008 */  j          .L8001D8C8
    /* E060 8001D860 21280000 */   addu      $a1, $zero, $zero
  .L8001D864:
    /* E064 8001D864 FF006330 */  andi       $v1, $v1, 0xFF
    /* E068 8001D868 0380043C */  lui        $a0, %hi(g_Sound_StereoPanGainTableQ15)
    /* E06C 8001D86C 9CF78424 */  addiu      $a0, $a0, %lo(g_Sound_StereoPanGainTableQ15)
    /* E070 8001D870 40100300 */  sll        $v0, $v1, 1
    /* E074 8001D874 21104400 */  addu       $v0, $v0, $a0
    /* E078 8001D878 00004284 */  lh         $v0, 0x0($v0)
    /* E07C 8001D87C 4000458E */  lw         $a1, 0x40($s2)
    /* E080 8001D880 00000000 */  nop
    /* E084 8001D884 1800A200 */  mult       $a1, $v0
    /* E088 8001D888 FF006338 */  xori       $v1, $v1, 0xFF
    /* E08C 8001D88C 40180300 */  sll        $v1, $v1, 1
    /* E090 8001D890 21186400 */  addu       $v1, $v1, $a0
    /* E094 8001D894 12300000 */  mflo       $a2
    /* E098 8001D898 00006284 */  lh         $v0, 0x0($v1)
    /* E09C 8001D89C 00000000 */  nop
    /* E0A0 8001D8A0 1800A200 */  mult       $a1, $v0
    /* E0A4 8001D8A4 21380000 */  addu       $a3, $zero, $zero
    /* E0A8 8001D8A8 1000448E */  lw         $a0, 0x10($s2)
    /* E0AC 8001D8AC 038C0600 */  sra        $s1, $a2, 16
    /* E0B0 8001D8B0 21282002 */  addu       $a1, $s1, $zero
    /* E0B4 8001D8B4 12100000 */  mflo       $v0
    /* E0B8 8001D8B8 03840200 */  sra        $s0, $v0, 16
    /* E0BC 8001D8BC D64E000C */  jal        SetVoiceVolume
    /* E0C0 8001D8C0 21300002 */   addu      $a2, $s0, $zero
    /* E0C4 8001D8C4 21282002 */  addu       $a1, $s1, $zero
  .L8001D8C8:
    /* E0C8 8001D8C8 21300002 */  addu       $a2, $s0, $zero
  .L8001D8CC:
    /* E0CC 8001D8CC 1000448E */  lw         $a0, 0x10($s2)
    /* E0D0 8001D8D0 21380000 */  addu       $a3, $zero, $zero
    /* E0D4 8001D8D4 D64E000C */  jal        SetVoiceVolume
    /* E0D8 8001D8D8 01008424 */   addiu     $a0, $a0, 0x1
  .L8001D8DC:
    /* E0DC 8001D8DC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* E0E0 8001D8E0 1800B28F */  lw         $s2, 0x18($sp)
    /* E0E4 8001D8E4 1400B18F */  lw         $s1, 0x14($sp)
    /* E0E8 8001D8E8 1000B08F */  lw         $s0, 0x10($sp)
    /* E0EC 8001D8EC 0800E003 */  jr         $ra
    /* E0F0 8001D8F0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8001D7A8
