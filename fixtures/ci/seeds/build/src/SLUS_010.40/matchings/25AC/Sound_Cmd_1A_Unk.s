nonmatching Sound_Cmd_1A_Unk, 0x1D4

glabel Sound_Cmd_1A_Unk
    /* 77F4 80016FF4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 77F8 80016FF8 0380023C */  lui        $v0, %hi(g_PushedMusicConfig)
    /* 77FC 80016FFC 90584624 */  addiu      $a2, $v0, %lo(g_PushedMusicConfig)
    /* 7800 80017000 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7804 80017004 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7808 80017008 1000B0AF */  sw         $s0, 0x10($sp)
    /* 780C 8001700C 6E00C294 */  lhu        $v0, 0x6E($a2)
    /* 7810 80017010 00000000 */  nop
    /* 7814 80017014 11004010 */  beqz       $v0, .L8001705C
    /* 7818 80017018 21888000 */   addu      $s1, $a0, $zero
    /* 781C 8001701C 21184000 */  addu       $v1, $v0, $zero
    /* 7820 80017020 0800228E */  lw         $v0, 0x8($s1)
    /* 7824 80017024 00000000 */  nop
    /* 7828 80017028 0D006214 */  bne        $v1, $v0, .L80017060
    /* 782C 8001702C 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* 7830 80017030 01000524 */  addiu      $a1, $zero, 0x1
    /* 7834 80017034 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 7838 80017038 0380033C */  lui        $v1, %hi(g_pSecondaryMusicChannels)
    /* 783C 8001703C 286646AC */  sw         $a2, %lo(g_pSavedMousicConfig)($v0)
    /* 7840 80017040 0380023C */  lui        $v0, %hi(D_800378E8)
    /* 7844 80017044 0000248E */  lw         $a0, 0x0($s1)
    /* 7848 80017048 E8784224 */  addiu      $v0, $v0, %lo(D_800378E8)
    /* 784C 8001704C 805A000C */  jal        Sound_SetMusicSequence
    /* 7850 80017050 D46562AC */   sw        $v0, %lo(g_pSecondaryMusicChannels)($v1)
    /* 7854 80017054 3E5C0008 */  j          .L800170F8
    /* 7858 80017058 0480023C */   lui       $v0, %hi(g_Sound_GlobalFlags)
  .L8001705C:
    /* 785C 8001705C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
  .L80017060:
    /* 7860 80017060 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 7864 80017064 00000000 */  nop
    /* 7868 80017068 0400428C */  lw         $v0, 0x4($v0)
    /* 786C 8001706C 00000000 */  nop
    /* 7870 80017070 18004010 */  beqz       $v0, .L800170D4
    /* 7874 80017074 0380033C */   lui       $v1, %hi(g_pSavedMousicConfig)
    /* 7878 80017078 2866628C */  lw         $v0, %lo(g_pSavedMousicConfig)($v1)
    /* 787C 8001707C 00000000 */  nop
    /* 7880 80017080 05004010 */  beqz       $v0, .L80017098
    /* 7884 80017084 0380043C */   lui       $a0, %hi(D_800366F0)
    /* 7888 80017088 6E004294 */  lhu        $v0, 0x6E($v0)
    /* 788C 8001708C 00000000 */  nop
    /* 7890 80017090 10004014 */  bnez       $v0, .L800170D4
    /* 7894 80017094 00000000 */   nop
  .L80017098:
    /* 7898 80017098 F0668424 */  addiu      $a0, $a0, %lo(D_800366F0)
    /* 789C 8001709C 0380053C */  lui        $a1, %hi(g_PushedMusicConfig)
    /* 78A0 800170A0 9058A524 */  addiu      $a1, $a1, %lo(g_PushedMusicConfig)
    /* 78A4 800170A4 80000624 */  addiu      $a2, $zero, 0x80
    /* 78A8 800170A8 0380103C */  lui        $s0, %hi(g_pSecondaryMusicChannels)
    /* 78AC 800170AC 0380023C */  lui        $v0, %hi(D_800378E8)
    /* 78B0 800170B0 E8784224 */  addiu      $v0, $v0, %lo(D_800378E8)
    /* 78B4 800170B4 286665AC */  sw         $a1, %lo(g_pSavedMousicConfig)($v1)
    /* 78B8 800170B8 5564000C */  jal        Sound_memcpy32
    /* 78BC 800170BC D46502AE */   sw        $v0, %lo(g_pSecondaryMusicChannels)($s0)
    /* 78C0 800170C0 0380043C */  lui        $a0, %hi(g_ActiveMusicChannels)
    /* 78C4 800170C4 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 78C8 800170C8 D465058E */  lw         $a1, %lo(g_pSecondaryMusicChannels)($s0)
    /* 78CC 800170CC 5564000C */  jal        Sound_memcpy32
    /* 78D0 800170D0 00220624 */   addiu     $a2, $zero, 0x2200
  .L800170D4:
    /* 78D4 800170D4 0000248E */  lw         $a0, 0x0($s1)
    /* 78D8 800170D8 6157000C */  jal        Sound_LoadAkaoSequence
    /* 78DC 800170DC 00000000 */   nop
    /* 78E0 800170E0 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 78E4 800170E4 2078438C */  lw         $v1, %lo(g_pActiveMusicConfig)($v0)
    /* 78E8 800170E8 08002296 */  lhu        $v0, 0x8($s1)
    /* 78EC 800170EC 00000000 */  nop
    /* 78F0 800170F0 6E0062A4 */  sh         $v0, 0x6E($v1)
    /* 78F4 800170F4 0480023C */  lui        $v0, %hi(g_Sound_GlobalFlags)
  .L800170F8:
    /* 78F8 800170F8 F89A4724 */  addiu      $a3, $v0, %lo(g_Sound_GlobalFlags)
    /* 78FC 800170FC FFFE0424 */  addiu      $a0, $zero, -0x101
    /* 7900 80017100 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 7904 80017104 0400E38C */  lw         $v1, 0x4($a3)
    /* 7908 80017108 2866428C */  lw         $v0, %lo(g_pSavedMousicConfig)($v0)
    /* 790C 8001710C 24306400 */  and        $a2, $v1, $a0
    /* 7910 80017110 16004010 */  beqz       $v0, .L8001716C
    /* 7914 80017114 0400E6AC */   sw        $a2, 0x4($a3)
    /* 7918 80017118 1000258E */  lw         $a1, 0x10($s1)
    /* 791C 8001711C 81FF043C */  lui        $a0, (0xFF810000 >> 16)
    /* 7920 80017120 1A008500 */  div        $zero, $a0, $a1
    /* 7924 80017124 0200A014 */  bnez       $a1, .L80017130
    /* 7928 80017128 00000000 */   nop
    /* 792C 8001712C 0D000700 */  break      7
  .L80017130:
    /* 7930 80017130 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 7934 80017134 0400A114 */  bne        $a1, $at, .L80017148
    /* 7938 80017138 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 793C 8001713C 02008114 */  bne        $a0, $at, .L80017148
    /* 7940 80017140 00000000 */   nop
    /* 7944 80017144 0D000600 */  break      6
  .L80017148:
    /* 7948 80017148 12200000 */  mflo       $a0
    /* 794C 8001714C 0380033C */  lui        $v1, %hi(g_Sound_MasterFadeTimer)
    /* 7950 80017150 7F00023C */  lui        $v0, (0x7F0000 >> 16)
    /* 7954 80017154 387862AC */  sw         $v0, %lo(g_Sound_MasterFadeTimer)($v1)
    /* 7958 80017158 0001C234 */  ori        $v0, $a2, 0x100
    /* 795C 8001715C 38786324 */  addiu      $v1, $v1, %lo(g_Sound_MasterFadeTimer)
    /* 7960 80017160 0400E2AC */  sw         $v0, 0x4($a3)
    /* 7964 80017164 080065AC */  sw         $a1, 0x8($v1)
    /* 7968 80017168 040064AC */  sw         $a0, 0x4($v1)
  .L8001716C:
    /* 796C 8001716C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 7970 80017170 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* 7974 80017174 00000000 */  nop
    /* 7978 80017178 600080AC */  sw         $zero, 0x60($a0)
    /* 797C 8001717C 10002296 */  lhu        $v0, 0x10($s1)
    /* 7980 80017180 00000000 */  nop
    /* 7984 80017184 680082A4 */  sh         $v0, 0x68($a0)
    /* 7988 80017188 1400228E */  lw         $v0, 0x14($s1)
    /* 798C 8001718C 1000238E */  lw         $v1, 0x10($s1)
    /* 7990 80017190 7F004230 */  andi       $v0, $v0, 0x7F
    /* 7994 80017194 00140200 */  sll        $v0, $v0, 16
    /* 7998 80017198 1B004300 */  divu       $zero, $v0, $v1
    /* 799C 8001719C 02006014 */  bnez       $v1, .L800171A8
    /* 79A0 800171A0 00000000 */   nop
    /* 79A4 800171A4 0D000700 */  break      7
  .L800171A8:
    /* 79A8 800171A8 12100000 */  mflo       $v0
    /* 79AC 800171AC EB56000C */  jal        func_80015BAC
    /* 79B0 800171B0 640082AC */   sw        $v0, 0x64($a0)
    /* 79B4 800171B4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 79B8 800171B8 1400B18F */  lw         $s1, 0x14($sp)
    /* 79BC 800171BC 1000B08F */  lw         $s0, 0x10($sp)
    /* 79C0 800171C0 0800E003 */  jr         $ra
    /* 79C4 800171C4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Sound_Cmd_1A_Unk
