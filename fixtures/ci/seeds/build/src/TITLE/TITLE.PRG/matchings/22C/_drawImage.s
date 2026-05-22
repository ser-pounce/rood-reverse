nonmatching _drawImage, 0x30

glabel _drawImage
    /* 3DC 80068BDC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3E0 80068BE0 1000A4AF */  sw         $a0, 0x10($sp)
    /* 3E4 80068BE4 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3E8 80068BE8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3EC 80068BEC 3FA2000C */  jal        LoadImage
    /* 3F0 80068BF0 1400A6AF */   sw        $a2, 0x14($sp)
    /* 3F4 80068BF4 94A1000C */  jal        DrawSync
    /* 3F8 80068BF8 21200000 */   addu      $a0, $zero, $zero
    /* 3FC 80068BFC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 400 80068C00 00000000 */  nop
    /* 404 80068C04 0800E003 */  jr         $ra
    /* 408 80068C08 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _drawImage
