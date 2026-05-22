nonmatching func_8007B344, 0x34

glabel func_8007B344
    /* 12B44 8007B344 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 12B48 8007B348 00340600 */  sll        $a2, $a2, 16
    /* 12B4C 8007B34C 003C0700 */  sll        $a3, $a3, 16
    /* 12B50 8007B350 03340600 */  sra        $a2, $a2, 16
    /* 12B54 8007B354 3000A287 */  lh         $v0, 0x30($sp)
    /* 12B58 8007B358 033C0700 */  sra        $a3, $a3, 16
    /* 12B5C 8007B35C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 12B60 8007B360 381E010C */  jal        func_800478E0
    /* 12B64 8007B364 1000A2AF */   sw        $v0, 0x10($sp)
    /* 12B68 8007B368 1800BF8F */  lw         $ra, 0x18($sp)
    /* 12B6C 8007B36C 00000000 */  nop
    /* 12B70 8007B370 0800E003 */  jr         $ra
    /* 12B74 8007B374 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007B344
