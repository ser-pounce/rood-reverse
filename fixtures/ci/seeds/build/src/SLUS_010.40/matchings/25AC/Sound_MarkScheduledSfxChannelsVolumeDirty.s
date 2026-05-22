nonmatching Sound_MarkScheduledSfxChannelsVolumeDirty, 0x54

glabel Sound_MarkScheduledSfxChannelsVolumeDirty
    /* 71AC 800169AC 0380033C */  lui        $v1, %hi(D_80035910)
    /* 71B0 800169B0 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 71B4 800169B4 9078428C */  lw         $v0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 71B8 800169B8 00000000 */  nop
    /* 71BC 800169BC 0E004010 */  beqz       $v0, .L800169F8
    /* 71C0 800169C0 10596324 */   addiu     $v1, $v1, %lo(D_80035910)
    /* 71C4 800169C4 21284000 */  addu       $a1, $v0, $zero
    /* 71C8 800169C8 00100424 */  addiu      $a0, $zero, 0x1000
    /* 71CC 800169CC F8006324 */  addiu      $v1, $v1, 0xF8
  .L800169D0:
    /* 71D0 800169D0 2410A400 */  and        $v0, $a1, $a0
    /* 71D4 800169D4 05004010 */  beqz       $v0, .L800169EC
    /* 71D8 800169D8 00000000 */   nop
    /* 71DC 800169DC 0000628C */  lw         $v0, 0x0($v1)
    /* 71E0 800169E0 2628A400 */  xor        $a1, $a1, $a0
    /* 71E4 800169E4 03004234 */  ori        $v0, $v0, 0x3
    /* 71E8 800169E8 000062AC */  sw         $v0, 0x0($v1)
  .L800169EC:
    /* 71EC 800169EC 10016324 */  addiu      $v1, $v1, 0x110
    /* 71F0 800169F0 F7FFA014 */  bnez       $a1, .L800169D0
    /* 71F4 800169F4 40200400 */   sll       $a0, $a0, 1
  .L800169F8:
    /* 71F8 800169F8 0800E003 */  jr         $ra
    /* 71FC 800169FC 00000000 */   nop
endlabel Sound_MarkScheduledSfxChannelsVolumeDirty
