nonmatching _readSpu, 0x3C

glabel _readSpu
    /* 3D20 80013520 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3D24 80013524 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3D28 80013528 21808000 */  addu       $s0, $a0, $zero
    /* 3D2C 8001352C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3D30 80013530 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3D34 80013534 284D000C */  jal        spuSetTransferCallback
    /* 3D38 80013538 2188A000 */   addu      $s1, $a1, $zero
    /* 3D3C 8001353C 21200002 */  addu       $a0, $s0, $zero
    /* 3D40 80013540 C17A000C */  jal        SpuRead
    /* 3D44 80013544 21282002 */   addu      $a1, $s1, $zero
    /* 3D48 80013548 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3D4C 8001354C 1400B18F */  lw         $s1, 0x14($sp)
    /* 3D50 80013550 1000B08F */  lw         $s0, 0x10($sp)
    /* 3D54 80013554 0800E003 */  jr         $ra
    /* 3D58 80013558 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _readSpu
