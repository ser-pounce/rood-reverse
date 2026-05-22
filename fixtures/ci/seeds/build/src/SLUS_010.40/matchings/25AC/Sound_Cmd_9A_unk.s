nonmatching Sound_Cmd_9A_unk, 0x9C

glabel Sound_Cmd_9A_unk
    /* 90E8 800188E8 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 90EC 800188EC 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 90F0 800188F0 00000000 */  nop
    /* 90F4 800188F4 1C00428C */  lw         $v0, 0x1C($v0)
    /* 90F8 800188F8 00000000 */  nop
    /* 90FC 800188FC 1B004010 */  beqz       $v0, .L8001896C
    /* 9100 80018900 21304000 */   addu      $a2, $v0, $zero
    /* 9104 80018904 01000524 */  addiu      $a1, $zero, 0x1
    /* 9108 80018908 0380023C */  lui        $v0, %hi(g_ActiveMusicChannels)
    /* 910C 8001890C 90364224 */  addiu      $v0, $v0, %lo(g_ActiveMusicChannels)
    /* 9110 80018910 F8004424 */  addiu      $a0, $v0, 0xF8
  .L80018914:
    /* 9114 80018914 2410C500 */  and        $v0, $a2, $a1
    /* 9118 80018918 05004010 */  beqz       $v0, .L80018930
    /* 911C 8001891C 27180500 */   nor       $v1, $zero, $a1
    /* 9120 80018920 0000828C */  lw         $v0, 0x0($a0)
    /* 9124 80018924 2430C300 */  and        $a2, $a2, $v1
    /* 9128 80018928 132B4234 */  ori        $v0, $v0, 0x2B13
    /* 912C 8001892C 000082AC */  sw         $v0, 0x0($a0)
  .L80018930:
    /* 9130 80018930 40280500 */  sll        $a1, $a1, 1
    /* 9134 80018934 F7FFC014 */  bnez       $a2, .L80018914
    /* 9138 80018938 10018424 */   addiu     $a0, $a0, 0x110
    /* 913C 8001893C 0380023C */  lui        $v0, %hi(g_pActiveMusicConfig)
    /* 9140 80018940 2078428C */  lw         $v0, %lo(g_pActiveMusicConfig)($v0)
    /* 9144 80018944 00000000 */  nop
    /* 9148 80018948 1C00438C */  lw         $v1, 0x1C($v0)
    /* 914C 8001894C 1C0040AC */  sw         $zero, 0x1C($v0)
    /* 9150 80018950 040043AC */  sw         $v1, 0x4($v0)
    /* 9154 80018954 0480033C */  lui        $v1, %hi(g_Sound_GlobalFlags)
    /* 9158 80018958 F89A6324 */  addiu      $v1, $v1, %lo(g_Sound_GlobalFlags)
    /* 915C 8001895C 0800628C */  lw         $v0, 0x8($v1)
    /* 9160 80018960 00000000 */  nop
    /* 9164 80018964 00014234 */  ori        $v0, $v0, 0x100
    /* 9168 80018968 080062AC */  sw         $v0, 0x8($v1)
  .L8001896C:
    /* 916C 8001896C 0480023C */  lui        $v0, %hi(D_80039B64)
    /* 9170 80018970 649B438C */  lw         $v1, %lo(D_80039B64)($v0)
    /* 9174 80018974 FEFF0424 */  addiu      $a0, $zero, -0x2
    /* 9178 80018978 24186400 */  and        $v1, $v1, $a0
    /* 917C 8001897C 0800E003 */  jr         $ra
    /* 9180 80018980 649B43AC */   sw        $v1, %lo(D_80039B64)($v0)
endlabel Sound_Cmd_9A_unk
