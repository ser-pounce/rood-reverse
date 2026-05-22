nonmatching _inverseDistanceFromScreencenter, 0x3C

glabel _inverseDistanceFromScreencenter
    /* B4C 8006934C 60FF8424 */  addiu      $a0, $a0, -0xA0
    /* B50 80069350 18008400 */  mult       $a0, $a0
    /* B54 80069354 12100000 */  mflo       $v0
    /* B58 80069358 90FFA524 */  addiu      $a1, $a1, -0x70
    /* B5C 8006935C 00000000 */  nop
    /* B60 80069360 1800A500 */  mult       $a1, $a1
    /* B64 80069364 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* B68 80069368 1000BFAF */  sw         $ra, 0x10($sp)
    /* B6C 8006936C 12300000 */  mflo       $a2
    /* B70 80069370 E506010C */  jal        vs_gte_rsqrt
    /* B74 80069374 21204600 */   addu      $a0, $v0, $a2
    /* B78 80069378 1000BF8F */  lw         $ra, 0x10($sp)
    /* B7C 8006937C 00000000 */  nop
    /* B80 80069380 0800E003 */  jr         $ra
    /* B84 80069384 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _inverseDistanceFromScreencenter
