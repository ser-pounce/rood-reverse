nonmatching FreeVoiceChannels, 0x5C

glabel FreeVoiceChannels
    /* 6EE8 800166E8 1800A22C */  sltiu      $v0, $a1, 0x18
    /* 6EEC 800166EC 13004010 */  beqz       $v0, .L8001673C
    /* 6EF0 800166F0 21300000 */   addu      $a2, $zero, $zero
    /* 6EF4 800166F4 18000924 */  addiu      $t1, $zero, 0x18
    /* 6EF8 800166F8 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 6EFC 800166FC 2078478C */  lw         $a3, %lo(g_pActiveMusicConfig)($v0)
    /* 6F00 80016700 01000824 */  addiu      $t0, $zero, 0x1
    /* 6F04 80016704 F4008424 */  addiu      $a0, $a0, 0xF4
  .L80016708:
    /* 6F08 80016708 0000828C */  lw         $v0, 0x0($a0)
    /* 6F0C 8001670C 00000000 */  nop
    /* 6F10 80016710 06004514 */  bne        $v0, $a1, .L8001672C
    /* 6F14 80016714 0410C800 */   sllv      $v0, $t0, $a2
    /* 6F18 80016718 000089AC */  sw         $t1, 0x0($a0)
    /* 6F1C 8001671C 1400E38C */  lw         $v1, 0x14($a3)
    /* 6F20 80016720 27100200 */  nor        $v0, $zero, $v0
    /* 6F24 80016724 24186200 */  and        $v1, $v1, $v0
    /* 6F28 80016728 1400E3AC */  sw         $v1, 0x14($a3)
  .L8001672C:
    /* 6F2C 8001672C 0100C624 */  addiu      $a2, $a2, 0x1
    /* 6F30 80016730 2000C22C */  sltiu      $v0, $a2, 0x20
    /* 6F34 80016734 F4FF4014 */  bnez       $v0, .L80016708
    /* 6F38 80016738 10018424 */   addiu     $a0, $a0, 0x110
  .L8001673C:
    /* 6F3C 8001673C 0800E003 */  jr         $ra
    /* 6F40 80016740 00000000 */   nop
endlabel FreeVoiceChannels
