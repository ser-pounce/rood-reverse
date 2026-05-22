nonmatching func_800A2FBC, 0x98

glabel func_800A2FBC
    /* 3A7BC 800A2FBC 34008584 */  lh         $a1, 0x34($a0)
    /* 3A7C0 800A2FC0 CA058294 */  lhu        $v0, 0x5CA($a0)
    /* 3A7C4 800A2FC4 00000000 */  nop
    /* 3A7C8 800A2FC8 1A00A200 */  div        $zero, $a1, $v0
    /* 3A7CC 800A2FCC 12280000 */  mflo       $a1
    /* 3A7D0 800A2FD0 36008684 */  lh         $a2, 0x36($a0)
    /* 3A7D4 800A2FD4 CA058294 */  lhu        $v0, 0x5CA($a0)
    /* 3A7D8 800A2FD8 00000000 */  nop
    /* 3A7DC 800A2FDC 1A00C200 */  div        $zero, $a2, $v0
    /* 3A7E0 800A2FE0 12300000 */  mflo       $a2
    /* 3A7E4 800A2FE4 38008784 */  lh         $a3, 0x38($a0)
    /* 3A7E8 800A2FE8 CA058294 */  lhu        $v0, 0x5CA($a0)
    /* 3A7EC 800A2FEC 00000000 */  nop
    /* 3A7F0 800A2FF0 1A00E200 */  div        $zero, $a3, $v0
    /* 3A7F4 800A2FF4 12380000 */  mflo       $a3
    /* 3A7F8 800A2FF8 CA058294 */  lhu        $v0, 0x5CA($a0)
    /* 3A7FC 800A2FFC 00000000 */  nop
    /* 3A800 800A3000 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 3A804 800A3004 CA0582A4 */  sh         $v0, 0x5CA($a0)
    /* 3A808 800A3008 34008294 */  lhu        $v0, 0x34($a0)
    /* 3A80C 800A300C 1C008394 */  lhu        $v1, 0x1C($a0)
    /* 3A810 800A3010 23104500 */  subu       $v0, $v0, $a1
    /* 3A814 800A3014 340082A4 */  sh         $v0, 0x34($a0)
    /* 3A818 800A3018 36008294 */  lhu        $v0, 0x36($a0)
    /* 3A81C 800A301C 21186500 */  addu       $v1, $v1, $a1
    /* 3A820 800A3020 1C0083A4 */  sh         $v1, 0x1C($a0)
    /* 3A824 800A3024 1E008394 */  lhu        $v1, 0x1E($a0)
    /* 3A828 800A3028 23104600 */  subu       $v0, $v0, $a2
    /* 3A82C 800A302C 360082A4 */  sh         $v0, 0x36($a0)
    /* 3A830 800A3030 38008294 */  lhu        $v0, 0x38($a0)
    /* 3A834 800A3034 21186600 */  addu       $v1, $v1, $a2
    /* 3A838 800A3038 1E0083A4 */  sh         $v1, 0x1E($a0)
    /* 3A83C 800A303C 20008394 */  lhu        $v1, 0x20($a0)
    /* 3A840 800A3040 23104700 */  subu       $v0, $v0, $a3
    /* 3A844 800A3044 21186700 */  addu       $v1, $v1, $a3
    /* 3A848 800A3048 380082A4 */  sh         $v0, 0x38($a0)
    /* 3A84C 800A304C 0800E003 */  jr         $ra
    /* 3A850 800A3050 200083A4 */   sh        $v1, 0x20($a0)
endlabel func_800A2FBC
