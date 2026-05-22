nonmatching Sound_Cmd_90_unk, 0x40

glabel Sound_Cmd_90_unk
    /* 8FA4 800187A4 21300000 */  addu       $a2, $zero, $zero
    /* 8FA8 800187A8 0380023C */  lui        $v0, %hi(g_ActiveMusicChannels)
    /* 8FAC 800187AC 90364224 */  addiu      $v0, $v0, %lo(g_ActiveMusicChannels)
    /* 8FB0 800187B0 F8004524 */  addiu      $a1, $v0, 0xF8
    /* 8FB4 800187B4 0000838C */  lw         $v1, 0x0($a0)
    /* 8FB8 800187B8 0380023C */  lui        $v0, %hi(D_800378E4)
    /* 8FBC 800187BC E47843AC */  sw         $v1, %lo(D_800378E4)($v0)
  .L800187C0:
    /* 8FC0 800187C0 0000A28C */  lw         $v0, 0x0($a1)
    /* 8FC4 800187C4 0100C624 */  addiu      $a2, $a2, 0x1
    /* 8FC8 800187C8 03004234 */  ori        $v0, $v0, 0x3
    /* 8FCC 800187CC 0000A2AC */  sw         $v0, 0x0($a1)
    /* 8FD0 800187D0 2000C22C */  sltiu      $v0, $a2, 0x20
    /* 8FD4 800187D4 FAFF4014 */  bnez       $v0, .L800187C0
    /* 8FD8 800187D8 1001A524 */   addiu     $a1, $a1, 0x110
    /* 8FDC 800187DC 0800E003 */  jr         $ra
    /* 8FE0 800187E0 00000000 */   nop
endlabel Sound_Cmd_90_unk
