/* Handwritten function */
nonmatching _menuItemTextClut, 0x80

glabel _menuItemTextClut
    /* 8130 8010A930 00002184 */  lh         $at, 0x0($at)
    /* 8134 8010A934 218C2380 */  lb         $v1, -0x73DF($at)
    /* 8138 8010A938 01982684 */  lh         $a2, -0x67FF($at)
    /* 813C 8010A93C 4B80B080 */  lb         $s0, -0x7FB5($a1)
    /* 8140 8010A940 13815781 */  lb         $s7, -0x7EED($t2)
    /* 8144 8010A944 58817881 */  lb         $t8, -0x7EA8($t3)
    /* 8148 8010A948 7A81798D */  lw         $t9, -0x7E86($t3)
    /* 814C 8010A94C DB81BB89 */  lwl        $k1, -0x7E25($t5) /* handwritten instruction */
    /* 8150 8010A950 00002184 */  lh         $at, 0x0($at)
    /* 8154 8010A954 218C2380 */  lb         $v1, -0x73DF($at)
    /* 8158 8010A958 01982684 */  lh         $a2, -0x67FF($at)
    /* 815C 8010A95C 4B80B080 */  lb         $s0, -0x7FB5($a1)
    /* 8160 8010A960 13815781 */  lb         $s7, -0x7EED($t2)
    /* 8164 8010A964 58817881 */  lb         $t8, -0x7EA8($t3)
    /* 8168 8010A968 7A81798D */  lw         $t9, -0x7E86($t3)
    /* 816C 8010A96C DB81BB89 */  lwl        $k1, -0x7E25($t5) /* handwritten instruction */
    /* 8170 8010A970 00000088 */  lwl        $zero, 0x0($zero)
    /* 8174 8010A974 00900098 */  lwr        $zero, -0x7000($zero)
    /* 8178 8010A978 00A000A8 */  swl        $zero, -0x6000($zero)
    /* 817C 8010A97C 00B000B8 */  swr        $zero, -0x5000($zero)
    /* 8180 8010A980 00BC00C4 */  lwc1       $f0, -0x4400($zero)
    /* 8184 8010A984 00D000D8 */  ldc2       $0, -0x3000($zero)
    /* 8188 8010A988 00E000DC */  ld         $zero, -0x2000($zero)
    /* 818C 8010A98C 00F400FC */  sd         $zero, -0xC00($zero)
    /* 8190 8010A990 0000218C */  lw         $at, 0x0($at)
    /* 8194 8010A994 429C6488 */  lwl        $a0, -0x63BE($v1)
    /* 8198 8010A998 859CC898 */  lwr        $t0, -0x637B($a2)
    /* 819C 8010A99C 4DA5D3A9 */  swl        $s3, -0x5AB3($t6)
    /* 81A0 8010A9A0 57B2BBBA */  swr        $k1, -0x4DA9($s5) /* handwritten instruction */
    /* 81A4 8010A9A4 DDBEFFB6 */  sdr        $ra, -0x4123($s7)
    /* 81A8 8010A9A8 1FC33DD7 */  ldc1       $f29, -0x3CE1($t9)
    /* 81AC 8010A9AC 5FCB7FDB */  ldc2       $31, -0x34A1($k1) /* handwritten instruction */
endlabel _menuItemTextClut
