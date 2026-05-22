nonmatching Sound_Cmd_E5_FadeOutCutscene, 0x80

glabel Sound_Cmd_E5_FadeOutCutscene
    /* DF28 8001D728 21188000 */  addu       $v1, $a0, $zero
    /* DF2C 8001D72C 0000628C */  lw         $v0, 0x0($v1)
    /* DF30 8001D730 00000000 */  nop
    /* DF34 8001D734 02004010 */  beqz       $v0, .L8001D740
    /* DF38 8001D738 01000524 */   addiu     $a1, $zero, 0x1
    /* DF3C 8001D73C 00006594 */  lhu        $a1, 0x0($v1)
  .L8001D740:
    /* DF40 8001D740 0480043C */  lui        $a0, %hi(g_Sound_Cutscene_StreamState)
    /* DF44 8001D744 089B8424 */  addiu      $a0, $a0, %lo(g_Sound_Cutscene_StreamState)
    /* DF48 8001D748 04006294 */  lhu        $v0, 0x4($v1)
    /* DF4C 8001D74C 40008394 */  lhu        $v1, 0x40($a0)
    /* DF50 8001D750 00000000 */  nop
    /* DF54 8001D754 23104300 */  subu       $v0, $v0, $v1
    /* DF58 8001D758 00140200 */  sll        $v0, $v0, 16
    /* DF5C 8001D75C 03140200 */  sra        $v0, $v0, 16
    /* DF60 8001D760 001C0500 */  sll        $v1, $a1, 16
    /* DF64 8001D764 031C0300 */  sra        $v1, $v1, 16
    /* DF68 8001D768 1A004300 */  div        $zero, $v0, $v1
    /* DF6C 8001D76C 02006014 */  bnez       $v1, .L8001D778
    /* DF70 8001D770 00000000 */   nop
    /* DF74 8001D774 0D000700 */  break      7
  .L8001D778:
    /* DF78 8001D778 FFFF0124 */  addiu      $at, $zero, -0x1
    /* DF7C 8001D77C 04006114 */  bne        $v1, $at, .L8001D790
    /* DF80 8001D780 0080013C */   lui       $at, (0x80000000 >> 16)
    /* DF84 8001D784 02004114 */  bne        $v0, $at, .L8001D790
    /* DF88 8001D788 00000000 */   nop
    /* DF8C 8001D78C 0D000600 */  break      6
  .L8001D790:
    /* DF90 8001D790 12100000 */  mflo       $v0
    /* DF94 8001D794 480083AC */  sw         $v1, 0x48($a0)
    /* DF98 8001D798 00140200 */  sll        $v0, $v0, 16
    /* DF9C 8001D79C 03140200 */  sra        $v0, $v0, 16
    /* DFA0 8001D7A0 0800E003 */  jr         $ra
    /* DFA4 8001D7A4 440082AC */   sw        $v0, 0x44($a0)
endlabel Sound_Cmd_E5_FadeOutCutscene
