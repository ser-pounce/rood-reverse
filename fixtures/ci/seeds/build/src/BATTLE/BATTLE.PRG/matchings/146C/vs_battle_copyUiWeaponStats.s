nonmatching vs_battle_copyUiWeaponStats, 0x120

glabel vs_battle_copyUiWeaponStats
    /* 30C0 8006B8C0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 30C4 8006B8C4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 30C8 8006B8C8 2198A000 */  addu       $s3, $a1, $zero
    /* 30CC 8006B8CC 2800BFAF */  sw         $ra, 0x28($sp)
    /* 30D0 8006B8D0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 30D4 8006B8D4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 30D8 8006B8D8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 30DC 8006B8DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 30E0 8006B8E0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 30E4 8006B8E4 18006296 */  lhu        $v0, 0x18($s3)
    /* 30E8 8006B8E8 00000000 */  nop
    /* 30EC 8006B8EC 33004010 */  beqz       $v0, .L8006B9BC
    /* 30F0 8006B8F0 21A08000 */   addu      $s4, $a0, $zero
    /* 30F4 8006B8F4 18006526 */  addiu      $a1, $s3, 0x18
    /* 30F8 8006B8F8 21880000 */  addu       $s1, $zero, $zero
    /* 30FC 8006B8FC 0680103C */  lui        $s0, %hi(D_800603BC)
    /* 3100 8006B900 BC031026 */  addiu      $s0, $s0, %lo(D_800603BC)
    /* 3104 8006B904 14016296 */  lhu        $v0, 0x114($s3)
    /* 3108 8006B908 10016396 */  lhu        $v1, 0x110($s3)
    /* 310C 8006B90C 50061526 */  addiu      $s5, $s0, 0x650
    /* 3110 8006B910 200062A6 */  sh         $v0, 0x20($s3)
    /* 3114 8006B914 240063A6 */  sh         $v1, 0x24($s3)
    /* 3118 8006B918 01008292 */  lbu        $v0, 0x1($s4)
    /* 311C 8006B91C 78001224 */  addiu      $s2, $zero, 0x78
    /* 3120 8006B920 40200200 */  sll        $a0, $v0, 1
    /* 3124 8006B924 21208200 */  addu       $a0, $a0, $v0
    /* 3128 8006B928 80200400 */  sll        $a0, $a0, 2
    /* 312C 8006B92C 23208200 */  subu       $a0, $a0, $v0
    /* 3130 8006B930 80200400 */  sll        $a0, $a0, 2
    /* 3134 8006B934 5FAD010C */  jal        vs_battle_copyUiBladeStats
    /* 3138 8006B938 21209000 */   addu      $a0, $a0, $s0
    /* 313C 8006B93C 48006526 */  addiu      $a1, $s3, 0x48
    /* 3140 8006B940 02008492 */  lbu        $a0, 0x2($s4)
    /* 3144 8006B944 DC021026 */  addiu      $s0, $s0, 0x2DC
    /* 3148 8006B948 00210400 */  sll        $a0, $a0, 4
    /* 314C 8006B94C ABAD010C */  jal        vs_battle_copyUiGripStats
    /* 3150 8006B950 21209000 */   addu      $a0, $a0, $s0
    /* 3154 8006B954 21806002 */  addu       $s0, $s3, $zero
  .L8006B958:
    /* 3158 8006B958 78000296 */  lhu        $v0, 0x78($s0)
    /* 315C 8006B95C 00000000 */  nop
    /* 3160 8006B960 08004010 */  beqz       $v0, .L8006B984
    /* 3164 8006B964 21109102 */   addu      $v0, $s4, $s1
    /* 3168 8006B968 04004290 */  lbu        $v0, 0x4($v0)
    /* 316C 8006B96C 21287202 */  addu       $a1, $s3, $s2
    /* 3170 8006B970 C0200200 */  sll        $a0, $v0, 3
    /* 3174 8006B974 23208200 */  subu       $a0, $a0, $v0
    /* 3178 8006B978 80200400 */  sll        $a0, $a0, 2
    /* 317C 8006B97C CAAD010C */  jal        vs_battle_copyUiGemStats
    /* 3180 8006B980 21209500 */   addu      $a0, $a0, $s5
  .L8006B984:
    /* 3184 8006B984 30005226 */  addiu      $s2, $s2, 0x30
    /* 3188 8006B988 01003126 */  addiu      $s1, $s1, 0x1
    /* 318C 8006B98C 0300222A */  slti       $v0, $s1, 0x3
    /* 3190 8006B990 F1FF4014 */  bnez       $v0, .L8006B958
    /* 3194 8006B994 30001026 */   addiu     $s0, $s0, 0x30
    /* 3198 8006B998 21880000 */  addu       $s1, $zero, $zero
    /* 319C 8006B99C 21189102 */  addu       $v1, $s4, $s1
  .L8006B9A0:
    /* 31A0 8006B9A0 21107102 */  addu       $v0, $s3, $s1
    /* 31A4 8006B9A4 00004290 */  lbu        $v0, 0x0($v0)
    /* 31A8 8006B9A8 01003126 */  addiu      $s1, $s1, 0x1
    /* 31AC 8006B9AC 080062A0 */  sb         $v0, 0x8($v1)
    /* 31B0 8006B9B0 1800222A */  slti       $v0, $s1, 0x18
    /* 31B4 8006B9B4 FAFF4014 */  bnez       $v0, .L8006B9A0
    /* 31B8 8006B9B8 21189102 */   addu      $v1, $s4, $s1
  .L8006B9BC:
    /* 31BC 8006B9BC 2800BF8F */  lw         $ra, 0x28($sp)
    /* 31C0 8006B9C0 2400B58F */  lw         $s5, 0x24($sp)
    /* 31C4 8006B9C4 2000B48F */  lw         $s4, 0x20($sp)
    /* 31C8 8006B9C8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 31CC 8006B9CC 1800B28F */  lw         $s2, 0x18($sp)
    /* 31D0 8006B9D0 1400B18F */  lw         $s1, 0x14($sp)
    /* 31D4 8006B9D4 1000B08F */  lw         $s0, 0x10($sp)
    /* 31D8 8006B9D8 0800E003 */  jr         $ra
    /* 31DC 8006B9DC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel vs_battle_copyUiWeaponStats
