nonmatching func_80084AD8, 0x4C

glabel func_80084AD8
    /* 1C2D8 80084AD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C2DC 80084ADC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C2E0 80084AE0 2180C000 */  addu       $s0, $a2, $zero
    /* 1C2E4 80084AE4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C2E8 80084AE8 EA09010C */  jal        vs_main_getRand
    /* 1C2EC 80084AEC 04000424 */   addiu     $a0, $zero, 0x4
    /* 1C2F0 80084AF0 FFFC0324 */  addiu      $v1, $zero, -0x301
    /* 1C2F4 80084AF4 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C2F8 80084AF8 01004224 */  addiu      $v0, $v0, 0x1
    /* 1C2FC 80084AFC 24208300 */  and        $a0, $a0, $v1
    /* 1C300 80084B00 0C000396 */  lhu        $v1, 0xC($s0)
    /* 1C304 80084B04 00018434 */  ori        $a0, $a0, 0x100
    /* 1C308 80084B08 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C30C 80084B0C 21186200 */  addu       $v1, $v1, $v0
    /* 1C310 80084B10 0C0003A6 */  sh         $v1, 0xC($s0)
    /* 1C314 80084B14 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C318 80084B18 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C31C 80084B1C 0800E003 */  jr         $ra
    /* 1C320 80084B20 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80084AD8
