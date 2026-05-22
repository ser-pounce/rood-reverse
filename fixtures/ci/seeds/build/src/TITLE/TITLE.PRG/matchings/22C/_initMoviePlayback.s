nonmatching _initMoviePlayback, 0x6C

glabel _initMoviePlayback
    /* 6908 8006F108 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 690C 8006F10C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 6910 8006F110 21888000 */  addu       $s1, $a0, $zero
    /* 6914 8006F114 1800B0AF */  sw         $s0, 0x18($sp)
    /* 6918 8006F118 2180A000 */  addu       $s0, $a1, $zero
    /* 691C 8006F11C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 6920 8006F120 67C7010C */  jal        DecDCTReset
    /* 6924 8006F124 21200000 */   addu      $a0, $zero, $zero
    /* 6928 8006F128 0BC8010C */  jal        DecDCToutCallback
    /* 692C 8006F12C 21200002 */   addu      $a0, $s0, $zero
    /* 6930 8006F130 0E80023C */  lui        $v0, %hi(_movieRingBuf)
    /* 6934 8006F134 E0ED448C */  lw         $a0, %lo(_movieRingBuf)($v0)
    /* 6938 8006F138 E180000C */  jal        StSetRing
    /* 693C 8006F13C 40000524 */   addiu     $a1, $zero, 0x40
    /* 6940 8006F140 01000424 */  addiu      $a0, $zero, 0x1
    /* 6944 8006F144 21288000 */  addu       $a1, $a0, $zero
    /* 6948 8006F148 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 694C 8006F14C 21380000 */  addu       $a3, $zero, $zero
    /* 6950 8006F150 C188000C */  jal        StSetStream
    /* 6954 8006F154 1000A0AF */   sw        $zero, 0x10($sp)
    /* 6958 8006F158 30BD010C */  jal        _playMovie
    /* 695C 8006F15C 21202002 */   addu      $a0, $s1, $zero
    /* 6960 8006F160 2000BF8F */  lw         $ra, 0x20($sp)
    /* 6964 8006F164 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 6968 8006F168 1800B08F */  lw         $s0, 0x18($sp)
    /* 696C 8006F16C 0800E003 */  jr         $ra
    /* 6970 8006F170 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _initMoviePlayback
