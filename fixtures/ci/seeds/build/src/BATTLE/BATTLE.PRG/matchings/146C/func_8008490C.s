nonmatching func_8008490C, 0x4C

glabel func_8008490C
    /* 1C10C 8008490C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C110 80084910 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C114 80084914 2180C000 */  addu       $s0, $a2, $zero
    /* 1C118 80084918 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C11C 8008491C EA09010C */  jal        vs_main_getRand
    /* 1C120 80084920 04000424 */   addiu     $a0, $zero, 0x4
    /* 1C124 80084924 3FFF0324 */  addiu      $v1, $zero, -0xC1
    /* 1C128 80084928 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C12C 8008492C 01004224 */  addiu      $v0, $v0, 0x1
    /* 1C130 80084930 24208300 */  and        $a0, $a0, $v1
    /* 1C134 80084934 0A000396 */  lhu        $v1, 0xA($s0)
    /* 1C138 80084938 80008434 */  ori        $a0, $a0, 0x80
    /* 1C13C 8008493C 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C140 80084940 21186200 */  addu       $v1, $v1, $v0
    /* 1C144 80084944 0A0003A6 */  sh         $v1, 0xA($s0)
    /* 1C148 80084948 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C14C 8008494C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C150 80084950 0800E003 */  jr         $ra
    /* 1C154 80084954 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008490C
