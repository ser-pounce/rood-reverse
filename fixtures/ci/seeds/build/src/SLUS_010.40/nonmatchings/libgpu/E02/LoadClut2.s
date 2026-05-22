nonmatching LoadClut2, 0x64

glabel LoadClut2
    /* 1BB04 8002B304 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1BB08 8002B308 21108000 */  addu       $v0, $a0, $zero
    /* 1BB0C 8002B30C 1800B0AF */  sw         $s0, 0x18($sp)
    /* 1BB10 8002B310 2180A000 */  addu       $s0, $a1, $zero
    /* 1BB14 8002B314 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1BB18 8002B318 2188C000 */  addu       $s1, $a2, $zero
    /* 1BB1C 8002B31C 1000A427 */  addiu      $a0, $sp, 0x10
    /* 1BB20 8002B320 21284000 */  addu       $a1, $v0, $zero
    /* 1BB24 8002B324 10000224 */  addiu      $v0, $zero, 0x10
    /* 1BB28 8002B328 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 1BB2C 8002B32C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1BB30 8002B330 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1BB34 8002B334 1000B0A7 */  sh         $s0, 0x10($sp)
    /* 1BB38 8002B338 1200B1A7 */  sh         $s1, 0x12($sp)
    /* 1BB3C 8002B33C 3FA2000C */  jal        LoadImage
    /* 1BB40 8002B340 1600A2A7 */   sh        $v0, 0x16($sp)
    /* 1BB44 8002B344 21200002 */  addu       $a0, $s0, $zero
    /* 1BB48 8002B348 2DAD000C */  jal        GetClut
    /* 1BB4C 8002B34C 21282002 */   addu      $a1, $s1, $zero
    /* 1BB50 8002B350 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 1BB54 8002B354 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1BB58 8002B358 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1BB5C 8002B35C 1800B08F */  lw         $s0, 0x18($sp)
    /* 1BB60 8002B360 0800E003 */  jr         $ra
    /* 1BB64 8002B364 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel LoadClut2
    /* 1BB68 8002B368 00000000 */  nop
    /* 1BB6C 8002B36C 00000000 */  nop
    /* 1BB70 8002B370 00000000 */  nop
