nonmatching Sound_Cmd_40_PushMusicState, 0x98

glabel Sound_Cmd_40_PushMusicState
    /* 7674 80016E74 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 7678 80016E78 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 767C 80016E7C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7680 80016E80 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 7684 80016E84 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7688 80016E88 1400B1AF */  sw         $s1, 0x14($sp)
    /* 768C 80016E8C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7690 80016E90 0400428C */  lw         $v0, 0x4($v0)
    /* 7694 80016E94 00000000 */  nop
    /* 7698 80016E98 16004010 */  beqz       $v0, .L80016EF4
    /* 769C 80016E9C 0380043C */   lui       $a0, %hi(D_800366F0)
    /* 76A0 80016EA0 F0668424 */  addiu      $a0, $a0, %lo(D_800366F0)
    /* 76A4 80016EA4 0380113C */  lui        $s1, %hi(g_PushedMusicConfig)
    /* 76A8 80016EA8 90582526 */  addiu      $a1, $s1, %lo(g_PushedMusicConfig)
    /* 76AC 80016EAC 5564000C */  jal        Sound_memcpy32
    /* 76B0 80016EB0 80000624 */   addiu     $a2, $zero, 0x80
    /* 76B4 80016EB4 0380043C */  lui        $a0, %hi(g_ActiveMusicChannels)
    /* 76B8 80016EB8 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 76BC 80016EBC 0380103C */  lui        $s0, %hi(D_800378E8)
    /* 76C0 80016EC0 E8781026 */  addiu      $s0, $s0, %lo(D_800378E8)
    /* 76C4 80016EC4 21280002 */  addu       $a1, $s0, $zero
    /* 76C8 80016EC8 5564000C */  jal        Sound_memcpy32
    /* 76CC 80016ECC 00220624 */   addiu     $a2, $zero, 0x2200
    /* 76D0 80016ED0 21900000 */  addu       $s2, $zero, $zero
  .L80016ED4:
    /* 76D4 80016ED4 9058248E */  lw         $a0, %lo(g_PushedMusicConfig)($s1)
    /* 76D8 80016ED8 21280002 */  addu       $a1, $s0, $zero
    /* 76DC 80016EDC 01005226 */  addiu      $s2, $s2, 0x1
    /* 76E0 80016EE0 D556000C */  jal        Sound_MapInstrumentToBaseSampleBank
    /* 76E4 80016EE4 10011026 */   addiu     $s0, $s0, 0x110
    /* 76E8 80016EE8 2000422E */  sltiu      $v0, $s2, 0x20
    /* 76EC 80016EEC F9FF4014 */  bnez       $v0, .L80016ED4
    /* 76F0 80016EF0 00000000 */   nop
  .L80016EF4:
    /* 76F4 80016EF4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 76F8 80016EF8 1800B28F */  lw         $s2, 0x18($sp)
    /* 76FC 80016EFC 1400B18F */  lw         $s1, 0x14($sp)
    /* 7700 80016F00 1000B08F */  lw         $s0, 0x10($sp)
    /* 7704 80016F04 0800E003 */  jr         $ra
    /* 7708 80016F08 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel Sound_Cmd_40_PushMusicState
