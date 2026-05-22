nonmatching Sound_Cmd_C1_unk, 0x120

glabel Sound_Cmd_C1_unk
    /* 7D4C 8001754C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7D50 80017550 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7D54 80017554 0400828C */  lw         $v0, 0x4($a0)
    /* 7D58 80017558 00000000 */  nop
    /* 7D5C 8001755C 02004010 */  beqz       $v0, .L80017568
    /* 7D60 80017560 01000624 */   addiu     $a2, $zero, 0x1
    /* 7D64 80017564 21304000 */  addu       $a2, $v0, $zero
  .L80017568:
    /* 7D68 80017568 0800828C */  lw         $v0, 0x8($a0)
    /* 7D6C 8001756C 0000858C */  lw         $a1, 0x0($a0)
    /* 7D70 80017570 7F004230 */  andi       $v0, $v0, 0x7F
    /* 7D74 80017574 0800A010 */  beqz       $a1, .L80017598
    /* 7D78 80017578 001C0200 */   sll       $v1, $v0, 16
    /* 7D7C 8001757C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 7D80 80017580 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 7D84 80017584 00000000 */  nop
    /* 7D88 80017588 6E004294 */  lhu        $v0, 0x6E($v0)
    /* 7D8C 8001758C 00000000 */  nop
    /* 7D90 80017590 1500A214 */  bne        $a1, $v0, .L800175E8
    /* 7D94 80017594 0380023C */   lui       $v0, %hi(g_pSavedMousicConfig)
  .L80017598:
    /* 7D98 80017598 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 7D9C 8001759C 2078448C */  lw         $a0, %lo(g_pActiveMusicConfig)($v0)
    /* 7DA0 800175A0 00000000 */  nop
    /* 7DA4 800175A4 6000828C */  lw         $v0, 0x60($a0)
    /* 7DA8 800175A8 00000000 */  nop
    /* 7DAC 800175AC 23186200 */  subu       $v1, $v1, $v0
    /* 7DB0 800175B0 1A006600 */  div        $zero, $v1, $a2
    /* 7DB4 800175B4 0200C014 */  bnez       $a2, .L800175C0
    /* 7DB8 800175B8 00000000 */   nop
    /* 7DBC 800175BC 0D000700 */  break      7
  .L800175C0:
    /* 7DC0 800175C0 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 7DC4 800175C4 0400C114 */  bne        $a2, $at, .L800175D8
    /* 7DC8 800175C8 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 7DCC 800175CC 02006114 */  bne        $v1, $at, .L800175D8
    /* 7DD0 800175D0 00000000 */   nop
    /* 7DD4 800175D4 0D000600 */  break      6
  .L800175D8:
    /* 7DD8 800175D8 12180000 */  mflo       $v1
    /* 7DDC 800175DC 0380053C */  lui        $a1, %hi(g_ActiveMusicChannels)
    /* 7DE0 800175E0 945D0008 */  j          .L80017650
    /* 7DE4 800175E4 9036A524 */   addiu     $a1, $a1, %lo(g_ActiveMusicChannels)
  .L800175E8:
    /* 7DE8 800175E8 2866448C */  lw         $a0, %lo(g_pSavedMousicConfig)($v0)
    /* 7DEC 800175EC 00000000 */  nop
    /* 7DF0 800175F0 1A008010 */  beqz       $a0, .L8001765C
    /* 7DF4 800175F4 00000000 */   nop
    /* 7DF8 800175F8 1800A010 */  beqz       $a1, .L8001765C
    /* 7DFC 800175FC 00000000 */   nop
    /* 7E00 80017600 6E008294 */  lhu        $v0, 0x6E($a0)
    /* 7E04 80017604 00000000 */  nop
    /* 7E08 80017608 1400A214 */  bne        $a1, $v0, .L8001765C
    /* 7E0C 8001760C 00000000 */   nop
    /* 7E10 80017610 6000828C */  lw         $v0, 0x60($a0)
    /* 7E14 80017614 00000000 */  nop
    /* 7E18 80017618 23186200 */  subu       $v1, $v1, $v0
    /* 7E1C 8001761C 1A006600 */  div        $zero, $v1, $a2
    /* 7E20 80017620 0200C014 */  bnez       $a2, .L8001762C
    /* 7E24 80017624 00000000 */   nop
    /* 7E28 80017628 0D000700 */  break      7
  .L8001762C:
    /* 7E2C 8001762C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 7E30 80017630 0400C114 */  bne        $a2, $at, .L80017644
    /* 7E34 80017634 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 7E38 80017638 02006114 */  bne        $v1, $at, .L80017644
    /* 7E3C 8001763C 00000000 */   nop
    /* 7E40 80017640 0D000600 */  break      6
  .L80017644:
    /* 7E44 80017644 12180000 */  mflo       $v1
    /* 7E48 80017648 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* 7E4C 8001764C D465458C */  lw         $a1, %lo(g_pSecondaryMusicChannels)($v0)
  .L80017650:
    /* 7E50 80017650 680086A4 */  sh         $a2, 0x68($a0)
    /* 7E54 80017654 595A000C */  jal        Sound_MarkActiveChannelsVolumeDirty
    /* 7E58 80017658 640083AC */   sw        $v1, 0x64($a0)
  .L8001765C:
    /* 7E5C 8001765C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7E60 80017660 00000000 */  nop
    /* 7E64 80017664 0800E003 */  jr         $ra
    /* 7E68 80017668 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel Sound_Cmd_C1_unk
