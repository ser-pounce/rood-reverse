nonmatching _initAndPlayIntroMovie, 0x138

glabel _initAndPlayIntroMovie
    /* 701C 8006F81C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 7020 8006F820 0300043C */  lui        $a0, (0x3EBE8 >> 16)
    /* 7024 8006F824 E8EB8434 */  ori        $a0, $a0, (0x3EBE8 & 0xFFFF)
    /* 7028 8006F828 2800B2AF */  sw         $s2, 0x28($sp)
    /* 702C 8006F82C 0E80123C */  lui        $s2, %hi(_introMovieLoc)
    /* 7030 8006F830 2400B1AF */  sw         $s1, 0x24($sp)
    /* 7034 8006F834 88ED5126 */  addiu      $s1, $s2, %lo(_introMovieLoc)
    /* 7038 8006F838 21282002 */  addu       $a1, $s1, $zero
    /* 703C 8006F83C 0E80033C */  lui        $v1, %hi(_dslMode)
    /* 7040 8006F840 E0010224 */  addiu      $v0, $zero, 0x1E0
    /* 7044 8006F844 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 7048 8006F848 2000B0AF */  sw         $s0, 0x20($sp)
    /* 704C 8006F84C 5996000C */  jal        DsIntToPos
    /* 7050 8006F850 80ED62AC */   sw        $v0, %lo(_dslMode)($v1)
    /* 7054 8006F854 B10F010C */  jal        vs_main_allocHeap
    /* 7058 8006F858 0200043C */   lui       $a0, (0x20000 >> 16)
    /* 705C 8006F85C 0200043C */  lui        $a0, (0x23000 >> 16)
    /* 7060 8006F860 00308434 */  ori        $a0, $a0, (0x23000 & 0xFFFF)
    /* 7064 8006F864 0E80033C */  lui        $v1, %hi(_movieRingBuf)
    /* 7068 8006F868 B10F010C */  jal        vs_main_allocHeap
    /* 706C 8006F86C E0ED62AC */   sw        $v0, %lo(_movieRingBuf)($v1)
    /* 7070 8006F870 0200043C */  lui        $a0, (0x23000 >> 16)
    /* 7074 8006F874 00308434 */  ori        $a0, $a0, (0x23000 & 0xFFFF)
    /* 7078 8006F878 0F80033C */  lui        $v1, %hi(_encodedDataBuf0)
    /* 707C 8006F87C B10F010C */  jal        vs_main_allocHeap
    /* 7080 8006F880 E8FD62AC */   sw        $v0, %lo(_encodedDataBuf0)($v1)
    /* 7084 8006F884 002A0424 */  addiu      $a0, $zero, 0x2A00
    /* 7088 8006F888 0F80033C */  lui        $v1, %hi(_encodedDataBuf1)
    /* 708C 8006F88C B10F010C */  jal        vs_main_allocHeap
    /* 7090 8006F890 ECFD62AC */   sw        $v0, %lo(_encodedDataBuf1)($v1)
    /* 7094 8006F894 002A0424 */  addiu      $a0, $zero, 0x2A00
    /* 7098 8006F898 0F80033C */  lui        $v1, %hi(_decodedDataBuf0)
    /* 709C 8006F89C B10F010C */  jal        vs_main_allocHeap
    /* 70A0 8006F8A0 F0FD62AC */   sw        $v0, %lo(_decodedDataBuf0)($v1)
    /* 70A4 8006F8A4 0E80103C */  lui        $s0, %hi(_movieData)
    /* 70A8 8006F8A8 A8ED0426 */  addiu      $a0, $s0, %lo(_movieData)
    /* 70AC 8006F8AC 21280000 */  addu       $a1, $zero, $zero
    /* 70B0 8006F8B0 0F80033C */  lui        $v1, %hi(_decodedDataBuf1)
    /* 70B4 8006F8B4 F4FD62AC */  sw         $v0, %lo(_decodedDataBuf1)($v1)
    /* 70B8 8006F8B8 E0000224 */  addiu      $v0, $zero, 0xE0
    /* 70BC 8006F8BC 2130A000 */  addu       $a2, $a1, $zero
    /* 70C0 8006F8C0 2138A000 */  addu       $a3, $a1, $zero
    /* 70C4 8006F8C4 28BC010C */  jal        _initMovieData
    /* 70C8 8006F8C8 1000A2AF */   sw        $v0, 0x10($sp)
    /* 70CC 8006F8CC 21202002 */  addu       $a0, $s1, $zero
    /* 70D0 8006F8D0 0780053C */  lui        $a1, %hi(_decDCToutCallback)
    /* 70D4 8006F8D4 42BC010C */  jal        _initMoviePlayback
    /* 70D8 8006F8D8 74F1A524 */   addiu     $a1, $a1, %lo(_decDCToutCallback)
    /* 70DC 8006F8DC 0E80043C */  lui        $a0, %hi(_vlcTable)
    /* 70E0 8006F8E0 E7C9010C */  jal        DecDCTvlcBuild
    /* 70E4 8006F8E4 E8ED8424 */   addiu     $a0, $a0, %lo(_vlcTable)
    /* 70E8 8006F8E8 FFFF1124 */  addiu      $s1, $zero, -0x1
  .L8006F8EC:
    /* 70EC 8006F8EC A8BC010C */  jal        _decodeNextMovieFrame
    /* 70F0 8006F8F0 A8ED0426 */   addiu     $a0, $s0, %lo(_movieData)
    /* 70F4 8006F8F4 0B005114 */  bne        $v0, $s1, .L8006F924
    /* 70F8 8006F8F8 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 70FC 8006F8FC 88ED4B26 */  addiu      $t3, $s2, %lo(_introMovieLoc)
    /* 7100 8006F900 03006889 */  lwl        $t0, 0x3($t3)
    /* 7104 8006F904 00006899 */  lwr        $t0, 0x0($t3)
    /* 7108 8006F908 00000000 */  nop
    /* 710C 8006F90C 1B00A8AB */  swl        $t0, 0x1B($sp)
    /* 7110 8006F910 1800A8BB */  swr        $t0, 0x18($sp)
    /* 7114 8006F914 30BD010C */  jal        _playMovie
    /* 7118 8006F918 1800A427 */   addiu     $a0, $sp, 0x18
    /* 711C 8006F91C 3BBE0108 */  j          .L8006F8EC
    /* 7120 8006F920 00000000 */   nop
  .L8006F924:
    /* 7124 8006F924 0E80023C */  lui        $v0, %hi(_introMoviePlaying)
    /* 7128 8006F928 01000324 */  addiu      $v1, $zero, 0x1
    /* 712C 8006F92C B17D000C */  jal        VSync
    /* 7130 8006F930 7CED43AC */   sw        $v1, %lo(_introMoviePlaying)($v0)
    /* 7134 8006F934 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 7138 8006F938 2800B28F */  lw         $s2, 0x28($sp)
    /* 713C 8006F93C 2400B18F */  lw         $s1, 0x24($sp)
    /* 7140 8006F940 2000B08F */  lw         $s0, 0x20($sp)
    /* 7144 8006F944 0E80033C */  lui        $v1, %hi(_introMovieDisplayedAt)
    /* 7148 8006F948 78ED62AC */  sw         $v0, %lo(_introMovieDisplayedAt)($v1)
    /* 714C 8006F94C 0800E003 */  jr         $ra
    /* 7150 8006F950 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel _initAndPlayIntroMovie
