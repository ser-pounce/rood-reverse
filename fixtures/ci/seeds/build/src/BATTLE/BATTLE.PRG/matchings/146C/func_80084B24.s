nonmatching func_80084B24, 0x4C

glabel func_80084B24
    /* 1C324 80084B24 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1C328 80084B28 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C32C 80084B2C 2180C000 */  addu       $s0, $a2, $zero
    /* 1C330 80084B30 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1C334 80084B34 EA09010C */  jal        vs_main_getRand
    /* 1C338 80084B38 04000424 */   addiu     $a0, $zero, 0x4
    /* 1C33C 80084B3C FFF30324 */  addiu      $v1, $zero, -0xC01
    /* 1C340 80084B40 1C00048E */  lw         $a0, 0x1C($s0)
    /* 1C344 80084B44 01004224 */  addiu      $v0, $v0, 0x1
    /* 1C348 80084B48 24208300 */  and        $a0, $a0, $v1
    /* 1C34C 80084B4C 0E000396 */  lhu        $v1, 0xE($s0)
    /* 1C350 80084B50 00048434 */  ori        $a0, $a0, 0x400
    /* 1C354 80084B54 1C0004AE */  sw         $a0, 0x1C($s0)
    /* 1C358 80084B58 21186200 */  addu       $v1, $v1, $v0
    /* 1C35C 80084B5C 0E0003A6 */  sh         $v1, 0xE($s0)
    /* 1C360 80084B60 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1C364 80084B64 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C368 80084B68 0800E003 */  jr         $ra
    /* 1C36C 80084B6C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80084B24
