nonmatching Sound_Cmd_C0_unk, 0xB4

glabel Sound_Cmd_C0_unk
    /* 7C98 80017498 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7C9C 8001749C 21308000 */  addu       $a2, $a0, $zero
    /* 7CA0 800174A0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7CA4 800174A4 0000C38C */  lw         $v1, 0x0($a2)
    /* 7CA8 800174A8 00000000 */  nop
    /* 7CAC 800174AC 07006010 */  beqz       $v1, .L800174CC
    /* 7CB0 800174B0 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* 7CB4 800174B4 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 7CB8 800174B8 00000000 */  nop
    /* 7CBC 800174BC 6E004294 */  lhu        $v0, 0x6E($v0)
    /* 7CC0 800174C0 00000000 */  nop
    /* 7CC4 800174C4 0B006214 */  bne        $v1, $v0, .L800174F4
    /* 7CC8 800174C8 0380023C */   lui       $v0, %hi(g_pSavedMousicConfig)
  .L800174CC:
    /* 7CCC 800174CC 0380053C */  lui        $a1, %hi(g_ActiveMusicChannels)
    /* 7CD0 800174D0 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 7CD4 800174D4 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* 7CD8 800174D8 0400C28C */  lw         $v0, 0x4($a2)
    /* 7CDC 800174DC 9036A524 */  addiu      $a1, $a1, %lo(g_ActiveMusicChannels)
    /* 7CE0 800174E0 7F004230 */  andi       $v0, $v0, 0x7F
    /* 7CE4 800174E4 00140200 */  sll        $v0, $v0, 16
    /* 7CE8 800174E8 600082AC */  sw         $v0, 0x60($a0)
    /* 7CEC 800174EC 4D5D0008 */  j          .L80017534
    /* 7CF0 800174F0 680080A4 */   sh        $zero, 0x68($a0)
  .L800174F4:
    /* 7CF4 800174F4 2866448C */  lw         $a0, %lo(g_pSavedMousicConfig)($v0)
    /* 7CF8 800174F8 00000000 */  nop
    /* 7CFC 800174FC 0F008010 */  beqz       $a0, .L8001753C
    /* 7D00 80017500 00000000 */   nop
    /* 7D04 80017504 0D006010 */  beqz       $v1, .L8001753C
    /* 7D08 80017508 00000000 */   nop
    /* 7D0C 8001750C 6E008294 */  lhu        $v0, 0x6E($a0)
    /* 7D10 80017510 00000000 */  nop
    /* 7D14 80017514 09006214 */  bne        $v1, $v0, .L8001753C
    /* 7D18 80017518 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 7D1C 8001751C D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
    /* 7D20 80017520 0400C28C */  lw         $v0, 0x4($a2)
    /* 7D24 80017524 680080A4 */  sh         $zero, 0x68($a0)
    /* 7D28 80017528 7F004230 */  andi       $v0, $v0, 0x7F
    /* 7D2C 8001752C 00140200 */  sll        $v0, $v0, 16
    /* 7D30 80017530 600082AC */  sw         $v0, 0x60($a0)
  .L80017534:
    /* 7D34 80017534 595A000C */  jal        Sound_MarkActiveChannelsVolumeDirty
    /* 7D38 80017538 00000000 */   nop
  .L8001753C:
    /* 7D3C 8001753C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7D40 80017540 00000000 */  nop
    /* 7D44 80017544 0800E003 */  jr         $ra
    /* 7D48 80017548 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_C0_unk
