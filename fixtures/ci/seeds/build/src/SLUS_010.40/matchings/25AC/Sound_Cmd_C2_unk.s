nonmatching Sound_Cmd_C2_unk, 0xF8

glabel Sound_Cmd_C2_unk
    /* 7E6C 8001766C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7E70 80017670 21388000 */  addu       $a3, $a0, $zero
    /* 7E74 80017674 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7E78 80017678 0400E28C */  lw         $v0, 0x4($a3)
    /* 7E7C 8001767C 00000000 */  nop
    /* 7E80 80017680 02004010 */  beqz       $v0, .L8001768C
    /* 7E84 80017684 01000624 */   addiu     $a2, $zero, 0x1
    /* 7E88 80017688 21304000 */  addu       $a2, $v0, $zero
  .L8001768C:
    /* 7E8C 8001768C 0000E38C */  lw         $v1, 0x0($a3)
    /* 7E90 80017690 00000000 */  nop
    /* 7E94 80017694 07006010 */  beqz       $v1, .L800176B4
    /* 7E98 80017698 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* 7E9C 8001769C 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 7EA0 800176A0 00000000 */  nop
    /* 7EA4 800176A4 6E004294 */  lhu        $v0, 0x6E($v0)
    /* 7EA8 800176A8 00000000 */  nop
    /* 7EAC 800176AC 06006214 */  bne        $v1, $v0, .L800176C8
    /* 7EB0 800176B0 0380023C */   lui       $v0, %hi(g_pSavedMousicConfig)
  .L800176B4:
    /* 7EB4 800176B4 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 7EB8 800176B8 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* 7EBC 800176BC 0380023C */  lui        $v0, %hi(g_ActiveMusicChannels)
    /* 7EC0 800176C0 BD5D0008 */  j          .L800176F4
    /* 7EC4 800176C4 90364524 */   addiu     $a1, $v0, %lo(g_ActiveMusicChannels)
  .L800176C8:
    /* 7EC8 800176C8 2866448C */  lw         $a0, %lo(g_pSavedMousicConfig)($v0)
    /* 7ECC 800176CC 00000000 */  nop
    /* 7ED0 800176D0 20008010 */  beqz       $a0, .L80017754
    /* 7ED4 800176D4 00000000 */   nop
    /* 7ED8 800176D8 1E006010 */  beqz       $v1, .L80017754
    /* 7EDC 800176DC 00000000 */   nop
    /* 7EE0 800176E0 6E008294 */  lhu        $v0, 0x6E($a0)
    /* 7EE4 800176E4 00000000 */  nop
    /* 7EE8 800176E8 1A006214 */  bne        $v1, $v0, .L80017754
    /* 7EEC 800176EC 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 7EF0 800176F0 D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
  .L800176F4:
    /* 7EF4 800176F4 0800E38C */  lw         $v1, 0x8($a3)
    /* 7EF8 800176F8 00000000 */  nop
    /* 7EFC 800176FC 7F006330 */  andi       $v1, $v1, 0x7F
    /* 7F00 80017700 001C0300 */  sll        $v1, $v1, 16
    /* 7F04 80017704 600083AC */  sw         $v1, 0x60($a0)
    /* 7F08 80017708 0C00E28C */  lw         $v0, 0xC($a3)
    /* 7F0C 8001770C 00000000 */  nop
    /* 7F10 80017710 7F004230 */  andi       $v0, $v0, 0x7F
    /* 7F14 80017714 00140200 */  sll        $v0, $v0, 16
    /* 7F18 80017718 23104300 */  subu       $v0, $v0, $v1
    /* 7F1C 8001771C 1A004600 */  div        $zero, $v0, $a2
    /* 7F20 80017720 0200C014 */  bnez       $a2, .L8001772C
    /* 7F24 80017724 00000000 */   nop
    /* 7F28 80017728 0D000700 */  break      7
  .L8001772C:
    /* 7F2C 8001772C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 7F30 80017730 0400C114 */  bne        $a2, $at, .L80017744
    /* 7F34 80017734 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 7F38 80017738 02004114 */  bne        $v0, $at, .L80017744
    /* 7F3C 8001773C 00000000 */   nop
    /* 7F40 80017740 0D000600 */  break      6
  .L80017744:
    /* 7F44 80017744 12100000 */  mflo       $v0
    /* 7F48 80017748 680086A4 */  sh         $a2, 0x68($a0)
    /* 7F4C 8001774C 595A000C */  jal        Sound_MarkActiveChannelsVolumeDirty
    /* 7F50 80017750 640082AC */   sw        $v0, 0x64($a0)
  .L80017754:
    /* 7F54 80017754 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7F58 80017758 00000000 */  nop
    /* 7F5C 8001775C 0800E003 */  jr         $ra
    /* 7F60 80017760 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_C2_unk
