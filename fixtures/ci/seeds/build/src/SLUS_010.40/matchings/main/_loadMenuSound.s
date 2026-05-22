nonmatching _loadMenuSound, 0x13C

glabel _loadMenuSound
    /* 370FC 800468FC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37100 80046900 1400BFAF */  sw         $ra, 0x14($sp)
    /* 37104 80046904 6B47000C */  jal        InitSound
    /* 37108 80046908 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3710C 8004690C 8C4C000C */  jal        vs_sound_setCdVol
    /* 37110 80046910 7F000424 */   addiu     $a0, $zero, 0x7F
    /* 37114 80046914 8F0F010C */  jal        vs_main_allocHeapR
    /* 37118 80046918 00880434 */   ori       $a0, $zero, 0x8800
    /* 3711C 8004691C 21804000 */  addu       $s0, $v0, $zero
    /* 37120 80046920 18F60434 */  ori        $a0, $zero, 0xF618
    /* 37124 80046924 00880534 */  ori        $a1, $zero, 0x8800
    /* 37128 80046928 4F12010C */  jal        vs_main_diskLoadFile
    /* 3712C 8004692C 21300002 */   addu      $a2, $s0, $zero
    /* 37130 80046930 21200002 */  addu       $a0, $s0, $zero
    /* 37134 80046934 EE4A000C */  jal        func_80012BB8
    /* 37138 80046938 01000524 */   addiu     $a1, $zero, 0x1
    /* 3713C 8004693C 180F010C */  jal        vs_main_freeHeapR
    /* 37140 80046940 21200002 */   addu      $a0, $s0, $zero
    /* 37144 80046944 0100043C */  lui        $a0, (0x12000 >> 16)
    /* 37148 80046948 8F0F010C */  jal        vs_main_allocHeapR
    /* 3714C 8004694C 00208434 */   ori       $a0, $a0, (0x12000 & 0xFFFF)
    /* 37150 80046950 21804000 */  addu       $s0, $v0, $zero
    /* 37154 80046954 2DF60434 */  ori        $a0, $zero, 0xF62D
    /* 37158 80046958 0100053C */  lui        $a1, (0x12000 >> 16)
    /* 3715C 8004695C 0020A534 */  ori        $a1, $a1, (0x12000 & 0xFFFF)
    /* 37160 80046960 4F12010C */  jal        vs_main_diskLoadFile
    /* 37164 80046964 21300002 */   addu      $a2, $s0, $zero
    /* 37168 80046968 21200002 */  addu       $a0, $s0, $zero
    /* 3716C 8004696C EE4A000C */  jal        func_80012BB8
    /* 37170 80046970 01000524 */   addiu     $a1, $zero, 0x1
    /* 37174 80046974 180F010C */  jal        vs_main_freeHeapR
    /* 37178 80046978 21200002 */   addu      $a0, $s0, $zero
    /* 3717C 8004697C 0100043C */  lui        $a0, (0x18800 >> 16)
    /* 37180 80046980 8F0F010C */  jal        vs_main_allocHeapR
    /* 37184 80046984 00888434 */   ori       $a0, $a0, (0x18800 & 0xFFFF)
    /* 37188 80046988 21804000 */  addu       $s0, $v0, $zero
    /* 3718C 8004698C 0100043C */  lui        $a0, (0x10C65 >> 16)
    /* 37190 80046990 650C8434 */  ori        $a0, $a0, (0x10C65 & 0xFFFF)
    /* 37194 80046994 0100053C */  lui        $a1, (0x18800 >> 16)
    /* 37198 80046998 0088A534 */  ori        $a1, $a1, (0x18800 & 0xFFFF)
    /* 3719C 8004699C 4F12010C */  jal        vs_main_diskLoadFile
    /* 371A0 800469A0 21300002 */   addu      $a2, $s0, $zero
    /* 371A4 800469A4 21200002 */  addu       $a0, $s0, $zero
    /* 371A8 800469A8 21280000 */  addu       $a1, $zero, $zero
    /* 371AC 800469AC 774C000C */  jal        func_800131DC
    /* 371B0 800469B0 01000624 */   addiu     $a2, $zero, 0x1
    /* 371B4 800469B4 180F010C */  jal        vs_main_freeHeapR
    /* 371B8 800469B8 21200002 */   addu      $a0, $s0, $zero
    /* 371BC 800469BC 0100043C */  lui        $a0, (0x128E0 >> 16)
    /* 371C0 800469C0 E0288434 */  ori        $a0, $a0, (0x128E0 & 0xFFFF)
    /* 371C4 800469C4 00580524 */  addiu      $a1, $zero, 0x5800
    /* 371C8 800469C8 0580103C */  lui        $s0, %hi(_sfxData)
    /* 371CC 800469CC 78041026 */  addiu      $s0, $s0, %lo(_sfxData)
    /* 371D0 800469D0 4F12010C */  jal        vs_main_diskLoadFile
    /* 371D4 800469D4 21300002 */   addu      $a2, $s0, $zero
    /* 371D8 800469D8 7B47000C */  jal        Sound_BindAkaoSfxBlob
    /* 371DC 800469DC 21200002 */   addu      $a0, $s0, $zero
    /* 371E0 800469E0 0680033C */  lui        $v1, %hi(D_8005FE70)
    /* 371E4 800469E4 01000224 */  addiu      $v0, $zero, 0x1
    /* 371E8 800469E8 70FE62AC */  sw         $v0, %lo(D_8005FE70)($v1)
    /* 371EC 800469EC 0680033C */  lui        $v1, %hi(D_8005FE74)
    /* 371F0 800469F0 02000224 */  addiu      $v0, $zero, 0x2
    /* 371F4 800469F4 74FE62AC */  sw         $v0, %lo(D_8005FE74)($v1)
    /* 371F8 800469F8 0680033C */  lui        $v1, %hi(D_8005FE78)
    /* 371FC 800469FC 80000224 */  addiu      $v0, $zero, 0x80
    /* 37200 80046A00 78FE62AC */  sw         $v0, %lo(D_8005FE78)($v1)
    /* 37204 80046A04 0680033C */  lui        $v1, %hi(D_8005FE7C)
    /* 37208 80046A08 00020224 */  addiu      $v0, $zero, 0x200
    /* 3720C 80046A0C 7CFE62AC */  sw         $v0, %lo(D_8005FE7C)($v1)
    /* 37210 80046A10 0680033C */  lui        $v1, %hi(D_8005FE80)
    /* 37214 80046A14 00100224 */  addiu      $v0, $zero, 0x1000
    /* 37218 80046A18 80FE62AC */  sw         $v0, %lo(D_8005FE80)($v1)
    /* 3721C 80046A1C 0680033C */  lui        $v1, %hi(D_8005FE84)
    /* 37220 80046A20 1400BF8F */  lw         $ra, 0x14($sp)
    /* 37224 80046A24 1000B08F */  lw         $s0, 0x10($sp)
    /* 37228 80046A28 1000023C */  lui        $v0, (0x100000 >> 16)
    /* 3722C 80046A2C 84FE62AC */  sw         $v0, %lo(D_8005FE84)($v1)
    /* 37230 80046A30 0800E003 */  jr         $ra
    /* 37234 80046A34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _loadMenuSound
