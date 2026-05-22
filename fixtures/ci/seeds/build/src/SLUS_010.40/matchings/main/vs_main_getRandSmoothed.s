nonmatching vs_main_getRandSmoothed, 0x138

glabel vs_main_getRandSmoothed
    /* 33060 80042860 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 33064 80042864 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 33068 80042868 21888000 */  addu       $s1, $a0, $zero
    /* 3306C 8004286C 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 33070 80042870 3800BEAF */  sw         $fp, 0x38($sp)
    /* 33074 80042874 3400B7AF */  sw         $s7, 0x34($sp)
    /* 33078 80042878 3000B6AF */  sw         $s6, 0x30($sp)
    /* 3307C 8004287C 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 33080 80042880 2800B4AF */  sw         $s4, 0x28($sp)
    /* 33084 80042884 2400B3AF */  sw         $s3, 0x24($sp)
    /* 33088 80042888 2000B2AF */  sw         $s2, 0x20($sp)
    /* 3308C 8004288C EA09010C */  jal        vs_main_getRand
    /* 33090 80042890 1800B0AF */   sw        $s0, 0x18($sp)
    /* 33094 80042894 21202002 */  addu       $a0, $s1, $zero
    /* 33098 80042898 EA09010C */  jal        vs_main_getRand
    /* 3309C 8004289C 21804000 */   addu      $s0, $v0, $zero
    /* 330A0 800428A0 21202002 */  addu       $a0, $s1, $zero
    /* 330A4 800428A4 EA09010C */  jal        vs_main_getRand
    /* 330A8 800428A8 1000A2AF */   sw        $v0, 0x10($sp)
    /* 330AC 800428AC 21202002 */  addu       $a0, $s1, $zero
    /* 330B0 800428B0 EA09010C */  jal        vs_main_getRand
    /* 330B4 800428B4 1400A2AF */   sw        $v0, 0x14($sp)
    /* 330B8 800428B8 21202002 */  addu       $a0, $s1, $zero
    /* 330BC 800428BC EA09010C */  jal        vs_main_getRand
    /* 330C0 800428C0 21F04000 */   addu      $fp, $v0, $zero
    /* 330C4 800428C4 21202002 */  addu       $a0, $s1, $zero
    /* 330C8 800428C8 EA09010C */  jal        vs_main_getRand
    /* 330CC 800428CC 21B84000 */   addu      $s7, $v0, $zero
    /* 330D0 800428D0 21202002 */  addu       $a0, $s1, $zero
    /* 330D4 800428D4 EA09010C */  jal        vs_main_getRand
    /* 330D8 800428D8 21B04000 */   addu      $s6, $v0, $zero
    /* 330DC 800428DC 21202002 */  addu       $a0, $s1, $zero
    /* 330E0 800428E0 EA09010C */  jal        vs_main_getRand
    /* 330E4 800428E4 21A84000 */   addu      $s5, $v0, $zero
    /* 330E8 800428E8 21202002 */  addu       $a0, $s1, $zero
    /* 330EC 800428EC EA09010C */  jal        vs_main_getRand
    /* 330F0 800428F0 21A04000 */   addu      $s4, $v0, $zero
    /* 330F4 800428F4 21202002 */  addu       $a0, $s1, $zero
    /* 330F8 800428F8 EA09010C */  jal        vs_main_getRand
    /* 330FC 800428FC 21984000 */   addu      $s3, $v0, $zero
    /* 33100 80042900 21202002 */  addu       $a0, $s1, $zero
    /* 33104 80042904 EA09010C */  jal        vs_main_getRand
    /* 33108 80042908 21904000 */   addu      $s2, $v0, $zero
    /* 3310C 8004290C 21202002 */  addu       $a0, $s1, $zero
    /* 33110 80042910 EA09010C */  jal        vs_main_getRand
    /* 33114 80042914 21884000 */   addu      $s1, $v0, $zero
    /* 33118 80042918 1000A58F */  lw         $a1, 0x10($sp)
    /* 3311C 8004291C AA2A033C */  lui        $v1, (0x2AAAAAAB >> 16)
    /* 33120 80042920 21800502 */  addu       $s0, $s0, $a1
    /* 33124 80042924 1400A58F */  lw         $a1, 0x14($sp)
    /* 33128 80042928 ABAA6334 */  ori        $v1, $v1, (0x2AAAAAAB & 0xFFFF)
    /* 3312C 8004292C 21800502 */  addu       $s0, $s0, $a1
    /* 33130 80042930 21801E02 */  addu       $s0, $s0, $fp
    /* 33134 80042934 21801702 */  addu       $s0, $s0, $s7
    /* 33138 80042938 21801602 */  addu       $s0, $s0, $s6
    /* 3313C 8004293C 21801502 */  addu       $s0, $s0, $s5
    /* 33140 80042940 21801402 */  addu       $s0, $s0, $s4
    /* 33144 80042944 21801302 */  addu       $s0, $s0, $s3
    /* 33148 80042948 21801202 */  addu       $s0, $s0, $s2
    /* 3314C 8004294C 21801102 */  addu       $s0, $s0, $s1
    /* 33150 80042950 21800202 */  addu       $s0, $s0, $v0
    /* 33154 80042954 18000302 */  mult       $s0, $v1
    /* 33158 80042958 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 3315C 8004295C C3871000 */  sra        $s0, $s0, 31
    /* 33160 80042960 3800BE8F */  lw         $fp, 0x38($sp)
    /* 33164 80042964 3400B78F */  lw         $s7, 0x34($sp)
    /* 33168 80042968 3000B68F */  lw         $s6, 0x30($sp)
    /* 3316C 8004296C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 33170 80042970 2800B48F */  lw         $s4, 0x28($sp)
    /* 33174 80042974 2400B38F */  lw         $s3, 0x24($sp)
    /* 33178 80042978 2000B28F */  lw         $s2, 0x20($sp)
    /* 3317C 8004297C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 33180 80042980 10280000 */  mfhi       $a1
    /* 33184 80042984 43100500 */  sra        $v0, $a1, 1
    /* 33188 80042988 23105000 */  subu       $v0, $v0, $s0
    /* 3318C 8004298C 1800B08F */  lw         $s0, 0x18($sp)
    /* 33190 80042990 0800E003 */  jr         $ra
    /* 33194 80042994 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel vs_main_getRandSmoothed
