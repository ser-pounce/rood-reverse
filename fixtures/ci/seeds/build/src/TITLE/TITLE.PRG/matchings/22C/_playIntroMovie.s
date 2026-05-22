nonmatching _playIntroMovie, 0x1E0

glabel _playIntroMovie
    /* 7254 8006FA54 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* 7258 8006FA58 4000B2AF */  sw         $s2, 0x40($sp)
    /* 725C 8006FA5C 21900000 */  addu       $s2, $zero, $zero
    /* 7260 8006FA60 4800B4AF */  sw         $s4, 0x48($sp)
    /* 7264 8006FA64 0E80143C */  lui        $s4, %hi(_movieData)
    /* 7268 8006FA68 3C00B1AF */  sw         $s1, 0x3C($sp)
    /* 726C 8006FA6C A8ED9126 */  addiu      $s1, $s4, %lo(_movieData)
    /* 7270 8006FA70 5000B6AF */  sw         $s6, 0x50($sp)
    /* 7274 8006FA74 FFFF1624 */  addiu      $s6, $zero, -0x1
    /* 7278 8006FA78 4C00B5AF */  sw         $s5, 0x4C($sp)
    /* 727C 8006FA7C 0E80153C */  lui        $s5, %hi(_introMovieLoc)
    /* 7280 8006FA80 4400B3AF */  sw         $s3, 0x44($sp)
    /* 7284 8006FA84 2000B327 */  addiu      $s3, $sp, 0x20
    /* 7288 8006FA88 5400BFAF */  sw         $ra, 0x54($sp)
    /* 728C 8006FA8C 3800B0AF */  sw         $s0, 0x38($sp)
  .L8006FA90:
    /* 7290 8006FA90 0800228E */  lw         $v0, 0x8($s1)
    /* 7294 8006FA94 00000000 */  nop
    /* 7298 8006FA98 80100200 */  sll        $v0, $v0, 2
    /* 729C 8006FA9C 21105100 */  addu       $v0, $v0, $s1
    /* 72A0 8006FAA0 0000448C */  lw         $a0, 0x0($v0)
    /* 72A4 8006FAA4 BDC7010C */  jal        DecDCTin
    /* 72A8 8006FAA8 03000524 */   addiu     $a1, $zero, 0x3
    /* 72AC 8006FAAC 30002586 */  lh         $a1, 0x30($s1)
    /* 72B0 8006FAB0 32002286 */  lh         $v0, 0x32($s1)
    /* 72B4 8006FAB4 00000000 */  nop
    /* 72B8 8006FAB8 1800A200 */  mult       $a1, $v0
    /* 72BC 8006FABC 1400228E */  lw         $v0, 0x14($s1)
    /* 72C0 8006FAC0 00000000 */  nop
    /* 72C4 8006FAC4 80100200 */  sll        $v0, $v0, 2
    /* 72C8 8006FAC8 21105100 */  addu       $v0, $v0, $s1
    /* 72CC 8006FACC 0C00448C */  lw         $a0, 0xC($v0)
    /* 72D0 8006FAD0 12280000 */  mflo       $a1
    /* 72D4 8006FAD4 C2170500 */  srl        $v0, $a1, 31
    /* 72D8 8006FAD8 2128A200 */  addu       $a1, $a1, $v0
    /* 72DC 8006FADC DCC7010C */  jal        DecDCTout
    /* 72E0 8006FAE0 43280500 */   sra       $a1, $a1, 1
  .L8006FAE4:
    /* 72E4 8006FAE4 A8BC010C */  jal        _decodeNextMovieFrame
    /* 72E8 8006FAE8 A8ED8426 */   addiu     $a0, $s4, %lo(_movieData)
    /* 72EC 8006FAEC 11005614 */  bne        $v0, $s6, .L8006FB34
    /* 72F0 8006FAF0 21202002 */   addu      $a0, $s1, $zero
    /* 72F4 8006FAF4 A888000C */  jal        StGetBackloc
    /* 72F8 8006FAF8 1800A427 */   addiu     $a0, $sp, 0x18
    /* 72FC 8006FAFC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 7300 8006FB00 4C04422C */  sltiu      $v0, $v0, 0x44C
    /* 7304 8006FB04 07004014 */  bnez       $v0, .L8006FB24
    /* 7308 8006FB08 00000000 */   nop
    /* 730C 8006FB0C 88EDAB26 */  addiu      $t3, $s5, %lo(_introMovieLoc)
    /* 7310 8006FB10 03006889 */  lwl        $t0, 0x3($t3)
    /* 7314 8006FB14 00006899 */  lwr        $t0, 0x0($t3)
    /* 7318 8006FB18 00000000 */  nop
    /* 731C 8006FB1C 1B00A8AB */  swl        $t0, 0x1B($sp)
    /* 7320 8006FB20 1800A8BB */  swr        $t0, 0x18($sp)
  .L8006FB24:
    /* 7324 8006FB24 30BD010C */  jal        _playMovie
    /* 7328 8006FB28 1800A427 */   addiu     $a0, $sp, 0x18
    /* 732C 8006FB2C B9BE0108 */  j          .L8006FAE4
    /* 7330 8006FB30 00000000 */   nop
  .L8006FB34:
    /* 7334 8006FB34 0BBD010C */  jal        _waitForFrame
    /* 7338 8006FB38 21280000 */   addu      $a1, $zero, $zero
    /* 733C 8006FB3C B17D000C */  jal        VSync
    /* 7340 8006FB40 21200000 */   addu      $a0, $zero, $zero
    /* 7344 8006FB44 500E010C */  jal        vs_main_processPadState
    /* 7348 8006FB48 00000000 */   nop
    /* 734C 8006FB4C B17D000C */  jal        VSync
    /* 7350 8006FB50 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 7354 8006FB54 0E80033C */  lui        $v1, %hi(_introMovieDisplayedAt)
    /* 7358 8006FB58 78ED638C */  lw         $v1, %lo(_introMovieDisplayedAt)($v1)
    /* 735C 8006FB5C 00000000 */  nop
    /* 7360 8006FB60 23104300 */  subu       $v0, $v0, $v1
    /* 7364 8006FB64 F508422C */  sltiu      $v0, $v0, 0x8F5
    /* 7368 8006FB68 28004010 */  beqz       $v0, .L8006FC0C
    /* 736C 8006FB6C 21100000 */   addu      $v0, $zero, $zero
    /* 7370 8006FB70 2800228E */  lw         $v0, 0x28($s1)
    /* 7374 8006FB74 00000000 */  nop
    /* 7378 8006FB78 02004014 */  bnez       $v0, .L8006FB84
    /* 737C 8006FB7C 21300000 */   addu      $a2, $zero, $zero
    /* 7380 8006FB80 E0000624 */  addiu      $a2, $zero, 0xE0
  .L8006FB84:
    /* 7384 8006FB84 21206002 */  addu       $a0, $s3, $zero
    /* 7388 8006FB88 21280000 */  addu       $a1, $zero, $zero
    /* 738C 8006FB8C E0001024 */  addiu      $s0, $zero, 0xE0
    /* 7390 8006FB90 E0010724 */  addiu      $a3, $zero, 0x1E0
    /* 7394 8006FB94 0DAD000C */  jal        SetDefDispEnv
    /* 7398 8006FB98 1000B0AF */   sw        $s0, 0x10($sp)
    /* 739C 8006FB9C 5555023C */  lui        $v0, (0x55555556 >> 16)
    /* 73A0 8006FBA0 2400A387 */  lh         $v1, 0x24($sp)
    /* 73A4 8006FBA4 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 73A8 8006FBA8 40180300 */  sll        $v1, $v1, 1
    /* 73AC 8006FBAC 18006200 */  mult       $v1, $v0
    /* 73B0 8006FBB0 21206002 */  addu       $a0, $s3, $zero
    /* 73B4 8006FBB4 01005226 */  addiu      $s2, $s2, 0x1
    /* 73B8 8006FBB8 2E00B0A7 */  sh         $s0, 0x2E($sp)
    /* 73BC 8006FBBC 08000224 */  addiu      $v0, $zero, 0x8
    /* 73C0 8006FBC0 2A00A2A7 */  sh         $v0, 0x2A($sp)
    /* 73C4 8006FBC4 01000224 */  addiu      $v0, $zero, 0x1
    /* 73C8 8006FBC8 C31F0300 */  sra        $v1, $v1, 31
    /* 73CC 8006FBCC 3100A2A3 */  sb         $v0, 0x31($sp)
    /* 73D0 8006FBD0 10400000 */  mfhi       $t0
    /* 73D4 8006FBD4 23180301 */  subu       $v1, $t0, $v1
    /* 73D8 8006FBD8 A0A3000C */  jal        PutDispEnv
    /* 73DC 8006FBDC 2400A3A7 */   sh        $v1, 0x24($sp)
    /* 73E0 8006FBE0 01000224 */  addiu      $v0, $zero, 0x1
    /* 73E4 8006FBE4 03004212 */  beq        $s2, $v0, .L8006FBF4
    /* 73E8 8006FBE8 00000000 */   nop
    /* 73EC 8006FBEC 6EA1000C */  jal        SetDispMask
    /* 73F0 8006FBF0 21204000 */   addu      $a0, $v0, $zero
  .L8006FBF4:
    /* 73F4 8006FBF4 0680023C */  lui        $v0, %hi(vs_main_buttonsPressed)
    /* 73F8 8006FBF8 D0E1428C */  lw         $v0, %lo(vs_main_buttonsPressed)($v0)
    /* 73FC 8006FBFC 00000000 */  nop
    /* 7400 8006FC00 20084230 */  andi       $v0, $v0, 0x820
    /* 7404 8006FC04 A2FF4010 */  beqz       $v0, .L8006FA90
    /* 7408 8006FC08 01000224 */   addiu     $v0, $zero, 0x1
  .L8006FC0C:
    /* 740C 8006FC0C 5400BF8F */  lw         $ra, 0x54($sp)
    /* 7410 8006FC10 5000B68F */  lw         $s6, 0x50($sp)
    /* 7414 8006FC14 4C00B58F */  lw         $s5, 0x4C($sp)
    /* 7418 8006FC18 4800B48F */  lw         $s4, 0x48($sp)
    /* 741C 8006FC1C 4400B38F */  lw         $s3, 0x44($sp)
    /* 7420 8006FC20 4000B28F */  lw         $s2, 0x40($sp)
    /* 7424 8006FC24 3C00B18F */  lw         $s1, 0x3C($sp)
    /* 7428 8006FC28 3800B08F */  lw         $s0, 0x38($sp)
    /* 742C 8006FC2C 0800E003 */  jr         $ra
    /* 7430 8006FC30 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel _playIntroMovie
