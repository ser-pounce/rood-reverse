nonmatching func_80015080, 0x140

glabel func_80015080
    /* 5880 80015080 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 5884 80015084 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 5888 80015088 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 588C 8001508C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 5890 80015090 2000B4AF */  sw         $s4, 0x20($sp)
    /* 5894 80015094 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5898 80015098 1800B2AF */  sw         $s2, 0x18($sp)
    /* 589C 8001509C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 58A0 800150A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 58A4 800150A4 0400438C */  lw         $v1, 0x4($v0)
    /* 58A8 800150A8 0C00428C */  lw         $v0, 0xC($v0)
    /* 58AC 800150AC 00000000 */  nop
    /* 58B0 800150B0 24186200 */  and        $v1, $v1, $v0
    /* 58B4 800150B4 0380023C */  lui        $v0, %hi(g_pSavedMousicConfig)
    /* 58B8 800150B8 2866458C */  lw         $a1, %lo(g_pSavedMousicConfig)($v0)
    /* 58BC 800150BC 00000000 */  nop
    /* 58C0 800150C0 0600A010 */  beqz       $a1, .L800150DC
    /* 58C4 800150C4 25906400 */   or        $s2, $v1, $a0
    /* 58C8 800150C8 0400A28C */  lw         $v0, 0x4($a1)
    /* 58CC 800150CC 0C00A38C */  lw         $v1, 0xC($a1)
    /* 58D0 800150D0 00000000 */  nop
    /* 58D4 800150D4 24104300 */  and        $v0, $v0, $v1
    /* 58D8 800150D8 25904202 */  or         $s2, $s2, $v0
  .L800150DC:
    /* 58DC 800150DC 21800000 */  addu       $s0, $zero, $zero
    /* 58E0 800150E0 FF7F1324 */  addiu      $s3, $zero, 0x7FFF
    /* 58E4 800150E4 0380143C */  lui        $s4, %hi(g_ActiveMusicChannels)
    /* 58E8 800150E8 0380023C */  lui        $v0, %hi(g_SpuVoiceInfo)
    /* 58EC 800150EC 30664224 */  addiu      $v0, $v0, %lo(g_SpuVoiceInfo)
    /* 58F0 800150F0 04005124 */  addiu      $s1, $v0, 0x4
  .L800150F4:
    /* 58F4 800150F4 01000224 */  addiu      $v0, $zero, 0x1
    /* 58F8 800150F8 04100202 */  sllv       $v0, $v0, $s0
    /* 58FC 800150FC 24104202 */  and        $v0, $s2, $v0
    /* 5900 80015100 21004014 */  bnez       $v0, .L80015188
    /* 5904 80015104 21200002 */   addu      $a0, $s0, $zero
    /* 5908 80015108 217B000C */  jal        SpuGetVoiceEnvelope
    /* 590C 8001510C 21282002 */   addu      $a1, $s1, $zero
    /* 5910 80015110 00002286 */  lh         $v0, 0x0($s1)
    /* 5914 80015114 00000000 */  nop
    /* 5918 80015118 06004014 */  bnez       $v0, .L80015134
    /* 591C 8001511C 0380023C */   lui       $v0, %hi(g_pActiveMusicConfig)
    /* 5920 80015120 90368426 */  addiu      $a0, $s4, %lo(g_ActiveMusicChannels)
    /* 5924 80015124 EF53000C */  jal        UnassignVoicesFromChannels
    /* 5928 80015128 21280002 */   addu      $a1, $s0, $zero
    /* 592C 8001512C 64540008 */  j          .L80015190
    /* 5930 80015130 08003126 */   addiu     $s1, $s1, 0x8
  .L80015134:
    /* 5934 80015134 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 5938 80015138 00000000 */  nop
    /* 593C 8001513C 0800458C */  lw         $a1, 0x8($v0)
    /* 5940 80015140 00000000 */  nop
    /* 5944 80015144 1100A010 */  beqz       $a1, .L8001518C
    /* 5948 80015148 90368426 */   addiu     $a0, $s4, %lo(g_ActiveMusicChannels)
    /* 594C 8001514C 0F54000C */  jal        func_8001503C
    /* 5950 80015150 21300002 */   addu      $a2, $s0, $zero
    /* 5954 80015154 02004010 */  beqz       $v0, .L80015160
    /* 5958 80015158 0380023C */   lui       $v0, %hi(g_pSavedMousicConfig)
    /* 595C 8001515C 000033A6 */  sh         $s3, 0x0($s1)
  .L80015160:
    /* 5960 80015160 2866438C */  lw         $v1, %lo(g_pSavedMousicConfig)($v0)
    /* 5964 80015164 00000000 */  nop
    /* 5968 80015168 08006010 */  beqz       $v1, .L8001518C
    /* 596C 8001516C 0380023C */   lui       $v0, %hi(g_pSecondaryMusicChannels)
    /* 5970 80015170 D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* 5974 80015174 0800658C */  lw         $a1, 0x8($v1)
    /* 5978 80015178 0F54000C */  jal        func_8001503C
    /* 597C 8001517C 21300002 */   addu      $a2, $s0, $zero
    /* 5980 80015180 02004010 */  beqz       $v0, .L8001518C
    /* 5984 80015184 00000000 */   nop
  .L80015188:
    /* 5988 80015188 000033A6 */  sh         $s3, 0x0($s1)
  .L8001518C:
    /* 598C 8001518C 08003126 */  addiu      $s1, $s1, 0x8
  .L80015190:
    /* 5990 80015190 01001026 */  addiu      $s0, $s0, 0x1
    /* 5994 80015194 1800022E */  sltiu      $v0, $s0, 0x18
    /* 5998 80015198 D6FF4014 */  bnez       $v0, .L800150F4
    /* 599C 8001519C 00000000 */   nop
    /* 59A0 800151A0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 59A4 800151A4 2000B48F */  lw         $s4, 0x20($sp)
    /* 59A8 800151A8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 59AC 800151AC 1800B28F */  lw         $s2, 0x18($sp)
    /* 59B0 800151B0 1400B18F */  lw         $s1, 0x14($sp)
    /* 59B4 800151B4 1000B08F */  lw         $s0, 0x10($sp)
    /* 59B8 800151B8 0800E003 */  jr         $ra
    /* 59BC 800151BC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80015080
