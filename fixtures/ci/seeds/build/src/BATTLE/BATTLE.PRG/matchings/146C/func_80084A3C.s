nonmatching func_80084A3C, 0x50

glabel func_80084A3C
    /* 1C23C 80084A3C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C240 80084A40 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C244 80084A44 2180C000 */  addu       $s0, $a2, $zero
    /* 1C248 80084A48 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C24C 80084A4C EA09010C */  jal        vs_main_getRand
    /* 1C250 80084A50 04000424 */   addiu     $a0, $zero, 0x4
    /* 1C254 80084A54 FFFF033C */  lui        $v1, (0xFFFF3FFF >> 16)
    /* 1C258 80084A58 FF3F6334 */  ori        $v1, $v1, (0xFFFF3FFF & 0xFFFF)
    /* 1C25C 80084A5C 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C260 80084A60 01004224 */  addiu      $v0, $v0, 0x1
    /* 1C264 80084A64 24208300 */  and        $a0, $a0, $v1
    /* 1C268 80084A68 12000396 */  lhu        $v1, 0x12($s0)
    /* 1C26C 80084A6C 00808434 */  ori        $a0, $a0, 0x8000
    /* 1C270 80084A70 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C274 80084A74 21186200 */  addu       $v1, $v1, $v0
    /* 1C278 80084A78 120003A6 */  sh         $v1, 0x12($s0)
    /* 1C27C 80084A7C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C280 80084A80 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C284 80084A84 0800E003 */  jr         $ra
    /* 1C288 80084A88 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80084A3C
