nonmatching _readImage, 0x30

glabel _readImage
    /* 40C 80068C0C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 410 80068C10 1000A4AF */  sw         $a0, 0x10($sp)
    /* 414 80068C14 1000A427 */  addiu      $a0, $sp, 0x10
    /* 418 80068C18 1800BFAF */  sw         $ra, 0x18($sp)
    /* 41C 80068C1C 57A2000C */  jal        StoreImage
    /* 420 80068C20 1400A6AF */   sw        $a2, 0x14($sp)
    /* 424 80068C24 94A1000C */  jal        DrawSync
    /* 428 80068C28 21200000 */   addu      $a0, $zero, $zero
    /* 42C 80068C2C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 430 80068C30 00000000 */  nop
    /* 434 80068C34 0800E003 */  jr         $ra
    /* 438 80068C38 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _readImage
