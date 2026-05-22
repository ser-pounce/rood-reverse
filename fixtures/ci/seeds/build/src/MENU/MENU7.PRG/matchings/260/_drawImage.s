nonmatching _drawImage, 0x30

glabel _drawImage
    /* 33C 80102B3C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 340 80102B40 1000A4AF */  sw         $a0, 0x10($sp)
    /* 344 80102B44 1000A427 */  addiu      $a0, $sp, 0x10
    /* 348 80102B48 1800BFAF */  sw         $ra, 0x18($sp)
    /* 34C 80102B4C 3FA2000C */  jal        LoadImage
    /* 350 80102B50 1400A6AF */   sw        $a2, 0x14($sp)
    /* 354 80102B54 94A1000C */  jal        DrawSync
    /* 358 80102B58 21200000 */   addu      $a0, $zero, $zero
    /* 35C 80102B5C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 360 80102B60 00000000 */  nop
    /* 364 80102B64 0800E003 */  jr         $ra
    /* 368 80102B68 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _drawImage
