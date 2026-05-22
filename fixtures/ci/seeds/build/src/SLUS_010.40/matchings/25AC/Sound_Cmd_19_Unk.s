nonmatching Sound_Cmd_19_Unk, 0xE8

glabel Sound_Cmd_19_Unk
    /* 770C 80016F0C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 7710 80016F10 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 7714 80016F14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7718 80016F18 1800BFAF */  sw         $ra, 0x18($sp)
    /* 771C 80016F1C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7720 80016F20 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7724 80016F24 0400428C */  lw         $v0, 0x4($v0)
    /* 7728 80016F28 00000000 */  nop
    /* 772C 80016F2C 19004010 */  beqz       $v0, .L80016F94
    /* 7730 80016F30 21888000 */   addu      $s1, $a0, $zero
    /* 7734 80016F34 0380033C */  lui        $v1, %hi(g_pSavedMousicConfig)
    /* 7738 80016F38 2866628C */  lw         $v0, %lo(g_pSavedMousicConfig)($v1)
    /* 773C 80016F3C 00000000 */  nop
    /* 7740 80016F40 05004010 */  beqz       $v0, .L80016F58
    /* 7744 80016F44 0380043C */   lui       $a0, %hi(D_800366F0)
    /* 7748 80016F48 6E004294 */  lhu        $v0, 0x6E($v0)
    /* 774C 80016F4C 00000000 */  nop
    /* 7750 80016F50 10004014 */  bnez       $v0, .L80016F94
    /* 7754 80016F54 00000000 */   nop
  .L80016F58:
    /* 7758 80016F58 F0668424 */  addiu      $a0, $a0, %lo(D_800366F0)
    /* 775C 80016F5C 0380053C */  lui        $a1, %hi(g_PushedMusicConfig)
    /* 7760 80016F60 9058A524 */  addiu      $a1, $a1, %lo(g_PushedMusicConfig)
    /* 7764 80016F64 80000624 */  addiu      $a2, $zero, 0x80
    /* 7768 80016F68 0380103C */  lui        $s0, %hi(g_pSecondaryMusicChannels)
    /* 776C 80016F6C 0380023C */  lui        $v0, %hi(D_800378E8)
    /* 7770 80016F70 E8784224 */  addiu      $v0, $v0, %lo(D_800378E8)
    /* 7774 80016F74 286665AC */  sw         $a1, %lo(g_pSavedMousicConfig)($v1)
    /* 7778 80016F78 5564000C */  jal        Sound_memcpy32
    /* 777C 80016F7C D46502AE */   sw        $v0, %lo(g_pSecondaryMusicChannels)($s0)
    /* 7780 80016F80 0380043C */  lui        $a0, %hi(g_ActiveMusicChannels)
    /* 7784 80016F84 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 7788 80016F88 D465058E */  lw         $a1, %lo(g_pSecondaryMusicChannels)($s0)
    /* 778C 80016F8C 5564000C */  jal        Sound_memcpy32
    /* 7790 80016F90 00220624 */   addiu     $a2, $zero, 0x2200
  .L80016F94:
    /* 7794 80016F94 0000248E */  lw         $a0, 0x0($s1)
    /* 7798 80016F98 6157000C */  jal        Sound_LoadAkaoSequence
    /* 779C 80016F9C 00000000 */   nop
    /* 77A0 80016FA0 0380033C */  lui        $v1, %hi(g_pActiveMusicConfig)
    /* 77A4 80016FA4 1000228E */  lw         $v0, 0x10($s1)
    /* 77A8 80016FA8 2078638C */  lw         $v1, %lo(g_pActiveMusicConfig)($v1)
    /* 77AC 80016FAC 7F004230 */  andi       $v0, $v0, 0x7F
    /* 77B0 80016FB0 00140200 */  sll        $v0, $v0, 16
    /* 77B4 80016FB4 600062AC */  sw         $v0, 0x60($v1)
    /* 77B8 80016FB8 680060A4 */  sh         $zero, 0x68($v1)
    /* 77BC 80016FBC 08002296 */  lhu        $v0, 0x8($s1)
    /* 77C0 80016FC0 EB56000C */  jal        func_80015BAC
    /* 77C4 80016FC4 6E0062A4 */   sh        $v0, 0x6E($v1)
    /* 77C8 80016FC8 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* 77CC 80016FCC F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 77D0 80016FD0 0400628C */  lw         $v0, 0x4($v1)
    /* 77D4 80016FD4 FFFE0424 */  addiu      $a0, $zero, -0x101
    /* 77D8 80016FD8 24104400 */  and        $v0, $v0, $a0
    /* 77DC 80016FDC 040062AC */  sw         $v0, 0x4($v1)
    /* 77E0 80016FE0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 77E4 80016FE4 1400B18F */  lw         $s1, 0x14($sp)
    /* 77E8 80016FE8 1000B08F */  lw         $s0, 0x10($sp)
    /* 77EC 80016FEC 0800E003 */  jr         $ra
    /* 77F0 80016FF0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Sound_Cmd_19_Unk
