nonmatching _readImage, 0x30

glabel _readImage
    /* 36C 80102B6C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 370 80102B70 1000A4AF */  sw         $a0, 0x10($sp)
    /* 374 80102B74 1000A427 */  addiu      $a0, $sp, 0x10
    /* 378 80102B78 1800BFAF */  sw         $ra, 0x18($sp)
    /* 37C 80102B7C 57A2000C */  jal        StoreImage
    /* 380 80102B80 1400A6AF */   sw        $a2, 0x14($sp)
    /* 384 80102B84 94A1000C */  jal        DrawSync
    /* 388 80102B88 21200000 */   addu      $a0, $zero, $zero
    /* 38C 80102B8C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 390 80102B90 00000000 */  nop
    /* 394 80102B94 0800E003 */  jr         $ra
    /* 398 80102B98 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _readImage
