nonmatching UnassignVoicesFromChannels, 0x80

glabel UnassignVoicesFromChannels
    /* 57BC 80014FBC 21300000 */  addu       $a2, $zero, $zero
    /* 57C0 80014FC0 18000324 */  addiu      $v1, $zero, 0x18
    /* 57C4 80014FC4 F4008424 */  addiu      $a0, $a0, 0xF4
  .L80014FC8:
    /* 57C8 80014FC8 0000828C */  lw         $v0, 0x0($a0)
    /* 57CC 80014FCC 00000000 */  nop
    /* 57D0 80014FD0 0200A214 */  bne        $a1, $v0, .L80014FDC
    /* 57D4 80014FD4 00000000 */   nop
    /* 57D8 80014FD8 000083AC */  sw         $v1, 0x0($a0)
  .L80014FDC:
    /* 57DC 80014FDC 0100C624 */  addiu      $a2, $a2, 0x1
    /* 57E0 80014FE0 2000C22C */  sltiu      $v0, $a2, 0x20
    /* 57E4 80014FE4 F8FF4014 */  bnez       $v0, .L80014FC8
    /* 57E8 80014FE8 10018424 */   addiu     $a0, $a0, 0x110
    /* 57EC 80014FEC 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 57F0 80014FF0 2866428C */  lw         $v0, %lo(g_pSavedMousicConfig)($v0)
    /* 57F4 80014FF4 00000000 */  nop
    /* 57F8 80014FF8 0E004010 */  beqz       $v0, .L80015034
    /* 57FC 80014FFC 21300000 */   addu      $a2, $zero, $zero
    /* 5800 80015000 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* 5804 80015004 D465428C */  lw         $v0, %lo(g_pSecondaryMusicChannels)($v0)
    /* 5808 80015008 18000424 */  addiu      $a0, $zero, 0x18
    /* 580C 8001500C F4004324 */  addiu      $v1, $v0, 0xF4
  .L80015010:
    /* 5810 80015010 0000628C */  lw         $v0, 0x0($v1)
    /* 5814 80015014 00000000 */  nop
    /* 5818 80015018 0200A214 */  bne        $a1, $v0, .L80015024
    /* 581C 8001501C 00000000 */   nop
    /* 5820 80015020 000064AC */  sw         $a0, 0x0($v1)
  .L80015024:
    /* 5824 80015024 0100C624 */  addiu      $a2, $a2, 0x1
    /* 5828 80015028 2000C22C */  sltiu      $v0, $a2, 0x20
    /* 582C 8001502C F8FF4014 */  bnez       $v0, .L80015010
    /* 5830 80015030 10016324 */   addiu     $v1, $v1, 0x110
  .L80015034:
    /* 5834 80015034 0800E003 */  jr         $ra
    /* 5838 80015038 00000000 */   nop
endlabel UnassignVoicesFromChannels
