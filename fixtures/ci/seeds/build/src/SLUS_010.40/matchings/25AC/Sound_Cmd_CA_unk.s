nonmatching Sound_Cmd_CA_unk, 0x70

glabel Sound_Cmd_CA_unk
    /* 8000 80017800 0000828C */  lw         $v0, 0x0($a0)
    /* 8004 80017804 00000000 */  nop
    /* 8008 80017808 02004010 */  beqz       $v0, .L80017814
    /* 800C 8001780C 01000524 */   addiu     $a1, $zero, 0x1
    /* 8010 80017810 21284000 */  addu       $a1, $v0, $zero
  .L80017814:
    /* 8014 80017814 08008294 */  lhu        $v0, 0x8($a0)
    /* 8018 80017818 04008494 */  lhu        $a0, 0x4($a0)
    /* 801C 8001781C 00140200 */  sll        $v0, $v0, 16
    /* 8020 80017820 00240400 */  sll        $a0, $a0, 16
    /* 8024 80017824 23104400 */  subu       $v0, $v0, $a0
    /* 8028 80017828 1A004500 */  div        $zero, $v0, $a1
    /* 802C 8001782C 0200A014 */  bnez       $a1, .L80017838
    /* 8030 80017830 00000000 */   nop
    /* 8034 80017834 0D000700 */  break      7
  .L80017838:
    /* 8038 80017838 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 803C 8001783C 0400A114 */  bne        $a1, $at, .L80017850
    /* 8040 80017840 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 8044 80017844 02004114 */  bne        $v0, $at, .L80017850
    /* 8048 80017848 00000000 */   nop
    /* 804C 8001784C 0D000600 */  break      6
  .L80017850:
    /* 8050 80017850 12100000 */  mflo       $v0
    /* 8054 80017854 0380033C */  lui        $v1, %hi(g_Sound_CdVolumeFadeLength)
    /* 8058 80017858 4C7865A4 */  sh         $a1, %lo(g_Sound_CdVolumeFadeLength)($v1)
    /* 805C 8001785C 0380033C */  lui        $v1, %hi(g_CdVolume)
    /* 8060 80017860 E07864AC */  sw         $a0, %lo(g_CdVolume)($v1)
    /* 8064 80017864 0380033C */  lui        $v1, %hi(g_Sound_CdVolumeFadeStep)
    /* 8068 80017868 0800E003 */  jr         $ra
    /* 806C 8001786C 487862AC */   sw        $v0, %lo(g_Sound_CdVolumeFadeStep)($v1)
endlabel Sound_Cmd_CA_unk
