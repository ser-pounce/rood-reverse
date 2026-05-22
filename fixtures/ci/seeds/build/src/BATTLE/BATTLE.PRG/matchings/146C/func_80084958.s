nonmatching func_80084958, 0x4C

glabel func_80084958
    /* 1C158 80084958 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C15C 8008495C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C160 80084960 2180C000 */  addu       $s0, $a2, $zero
    /* 1C164 80084964 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C168 80084968 EA09010C */  jal        vs_main_getRand
    /* 1C16C 8008496C 04000424 */   addiu     $a0, $zero, 0x4
    /* 1C170 80084970 FFFC0324 */  addiu      $v1, $zero, -0x301
    /* 1C174 80084974 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C178 80084978 01004224 */  addiu      $v0, $v0, 0x1
    /* 1C17C 8008497C 24208300 */  and        $a0, $a0, $v1
    /* 1C180 80084980 0C000396 */  lhu        $v1, 0xC($s0)
    /* 1C184 80084984 00028434 */  ori        $a0, $a0, 0x200
    /* 1C188 80084988 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C18C 8008498C 21186200 */  addu       $v1, $v1, $v0
    /* 1C190 80084990 0C0003A6 */  sh         $v1, 0xC($s0)
    /* 1C194 80084994 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C198 80084998 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C19C 8008499C 0800E003 */  jr         $ra
    /* 1C1A0 800849A0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80084958
