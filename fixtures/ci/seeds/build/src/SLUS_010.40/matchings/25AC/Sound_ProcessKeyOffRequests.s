nonmatching Sound_ProcessKeyOffRequests, 0x1AC

glabel Sound_ProcessKeyOffRequests
    /* 5FC4 800157C4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5FC8 800157C8 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 5FCC 800157CC 9078448C */  lw         $a0, %lo(g_Sound_VoiceSchedulerState)($v0)
    /* 5FD0 800157D0 90784324 */  addiu      $v1, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* 5FD4 800157D4 1800B0AF */  sw         $s0, 0x18($sp)
    /* 5FD8 800157D8 0380103C */  lui        $s0, %hi(g_pSavedMousicConfig)
    /* 5FDC 800157DC 2800BFAF */  sw         $ra, 0x28($sp)
    /* 5FE0 800157E0 2400B3AF */  sw         $s3, 0x24($sp)
    /* 5FE4 800157E4 2000B2AF */  sw         $s2, 0x20($sp)
    /* 5FE8 800157E8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 5FEC 800157EC 1000628C */  lw         $v0, 0x10($v1)
    /* 5FF0 800157F0 2866038E */  lw         $v1, %lo(g_pSavedMousicConfig)($s0)
    /* 5FF4 800157F4 25208200 */  or         $a0, $a0, $v0
    /* 5FF8 800157F8 0480023C */  lui        $v0, %hi(D_80039B14)
    /* 5FFC 800157FC 149B428C */  lw         $v0, %lo(D_80039B14)($v0)
    /* 6000 80015800 21880000 */  addu       $s1, $zero, $zero
    /* 6004 80015804 1000A0AF */  sw         $zero, 0x10($sp)
    /* 6008 80015808 16006010 */  beqz       $v1, .L80015864
    /* 600C 8001580C 27904400 */   nor       $s2, $v0, $a0
    /* 6010 80015810 1800718C */  lw         $s1, 0x18($v1)
    /* 6014 80015814 0800628C */  lw         $v0, 0x8($v1)
    /* 6018 80015818 00000000 */  nop
    /* 601C 8001581C 24302202 */  and        $a2, $s1, $v0
    /* 6020 80015820 1000C010 */  beqz       $a2, .L80015864
    /* 6024 80015824 1000A527 */   addiu     $a1, $sp, 0x10
    /* 6028 80015828 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* 602C 8001582C D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* 6030 80015830 D955000C */  jal        ChannelMaskToVoiceMaskFiltered
    /* 6034 80015834 21384002 */   addu      $a3, $s2, $zero
    /* 6038 80015838 2866048E */  lw         $a0, %lo(g_pSavedMousicConfig)($s0)
    /* 603C 8001583C 00000000 */  nop
    /* 6040 80015840 0800828C */  lw         $v0, 0x8($a0)
    /* 6044 80015844 00000000 */  nop
    /* 6048 80015848 27100200 */  nor        $v0, $zero, $v0
    /* 604C 8001584C 24882202 */  and        $s1, $s1, $v0
    /* 6050 80015850 0800828C */  lw         $v0, 0x8($a0)
    /* 6054 80015854 1800838C */  lw         $v1, 0x18($a0)
    /* 6058 80015858 27100200 */  nor        $v0, $zero, $v0
    /* 605C 8001585C 24186200 */  and        $v1, $v1, $v0
    /* 6060 80015860 180083AC */  sw         $v1, 0x18($a0)
  .L80015864:
    /* 6064 80015864 0380133C */  lui        $s3, %hi(g_pActiveMusicConfig)
    /* 6068 80015868 2078628E */  lw         $v0, %lo(g_pActiveMusicConfig)($s3)
    /* 606C 8001586C 00000000 */  nop
    /* 6070 80015870 1800508C */  lw         $s0, 0x18($v0)
    /* 6074 80015874 0800428C */  lw         $v0, 0x8($v0)
    /* 6078 80015878 00000000 */  nop
    /* 607C 8001587C 24300202 */  and        $a2, $s0, $v0
    /* 6080 80015880 1000C010 */  beqz       $a2, .L800158C4
    /* 6084 80015884 0380043C */   lui       $a0, %hi(g_ActiveMusicChannels)
    /* 6088 80015888 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 608C 8001588C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6090 80015890 D955000C */  jal        ChannelMaskToVoiceMaskFiltered
    /* 6094 80015894 21384002 */   addu      $a3, $s2, $zero
    /* 6098 80015898 2078648E */  lw         $a0, %lo(g_pActiveMusicConfig)($s3)
    /* 609C 8001589C 00000000 */  nop
    /* 60A0 800158A0 0800828C */  lw         $v0, 0x8($a0)
    /* 60A4 800158A4 00000000 */  nop
    /* 60A8 800158A8 27100200 */  nor        $v0, $zero, $v0
    /* 60AC 800158AC 24800202 */  and        $s0, $s0, $v0
    /* 60B0 800158B0 0800828C */  lw         $v0, 0x8($a0)
    /* 60B4 800158B4 1800838C */  lw         $v1, 0x18($a0)
    /* 60B8 800158B8 27100200 */  nor        $v0, $zero, $v0
    /* 60BC 800158BC 24186200 */  and        $v1, $v1, $v0
    /* 60C0 800158C0 180083AC */  sw         $v1, 0x18($a0)
  .L800158C4:
    /* 60C4 800158C4 0380133C */  lui        $s3, %hi(g_pSavedMousicConfig)
    /* 60C8 800158C8 2866628E */  lw         $v0, %lo(g_pSavedMousicConfig)($s3)
    /* 60CC 800158CC 00000000 */  nop
    /* 60D0 800158D0 0B004010 */  beqz       $v0, .L80015900
    /* 60D4 800158D4 00000000 */   nop
    /* 60D8 800158D8 09002012 */  beqz       $s1, .L80015900
    /* 60DC 800158DC 1000A527 */   addiu     $a1, $sp, 0x10
    /* 60E0 800158E0 21302002 */  addu       $a2, $s1, $zero
    /* 60E4 800158E4 0380023C */  lui        $v0, %hi(g_pSecondaryMusicChannels)
    /* 60E8 800158E8 D465448C */  lw         $a0, %lo(g_pSecondaryMusicChannels)($v0)
    /* 60EC 800158EC D955000C */  jal        ChannelMaskToVoiceMaskFiltered
    /* 60F0 800158F0 21384002 */   addu      $a3, $s2, $zero
    /* 60F4 800158F4 2866628E */  lw         $v0, %lo(g_pSavedMousicConfig)($s3)
    /* 60F8 800158F8 00000000 */  nop
    /* 60FC 800158FC 180040AC */  sw         $zero, 0x18($v0)
  .L80015900:
    /* 6100 80015900 0A000012 */  beqz       $s0, .L8001592C
    /* 6104 80015904 0380043C */   lui       $a0, %hi(g_ActiveMusicChannels)
    /* 6108 80015908 90368424 */  addiu      $a0, $a0, %lo(g_ActiveMusicChannels)
    /* 610C 8001590C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 6110 80015910 21300002 */  addu       $a2, $s0, $zero
    /* 6114 80015914 D955000C */  jal        ChannelMaskToVoiceMaskFiltered
    /* 6118 80015918 21384002 */   addu      $a3, $s2, $zero
    /* 611C 8001591C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 6120 80015920 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 6124 80015924 00000000 */  nop
    /* 6128 80015928 180040AC */  sw         $zero, 0x18($v0)
  .L8001592C:
    /* 612C 8001592C 0380023C */  lui        $v0, %hi(g_Sound_VoiceSchedulerState)
    /* 6130 80015930 90784224 */  addiu      $v0, $v0, %lo(g_Sound_VoiceSchedulerState)
    /* 6134 80015934 1000A48F */  lw         $a0, 0x10($sp)
    /* 6138 80015938 0C00438C */  lw         $v1, 0xC($v0)
    /* 613C 8001593C 0C0040AC */  sw         $zero, 0xC($v0)
    /* 6140 80015940 25208300 */  or         $a0, $a0, $v1
    /* 6144 80015944 03008010 */  beqz       $a0, .L80015954
    /* 6148 80015948 1000A4AF */   sw        $a0, 0x10($sp)
    /* 614C 8001594C BA4E000C */  jal        SetVoiceKeyOff
    /* 6150 80015950 00000000 */   nop
  .L80015954:
    /* 6154 80015954 2800BF8F */  lw         $ra, 0x28($sp)
    /* 6158 80015958 2400B38F */  lw         $s3, 0x24($sp)
    /* 615C 8001595C 2000B28F */  lw         $s2, 0x20($sp)
    /* 6160 80015960 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6164 80015964 1800B08F */  lw         $s0, 0x18($sp)
    /* 6168 80015968 0800E003 */  jr         $ra
    /* 616C 8001596C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel Sound_ProcessKeyOffRequests
