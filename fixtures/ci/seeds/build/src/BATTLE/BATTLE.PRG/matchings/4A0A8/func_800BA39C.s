nonmatching func_800BA39C, 0x48

glabel func_800BA39C
    /* 51B9C 800BA39C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 51BA0 800BA3A0 21388000 */  addu       $a3, $a0, $zero
    /* 51BA4 800BA3A4 0F80033C */  lui        $v1, %hi(D_800E9B34)
    /* 51BA8 800BA3A8 349B6324 */  addiu      $v1, $v1, %lo(D_800E9B34)
    /* 51BAC 800BA3AC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 51BB0 800BA3B0 0100E290 */  lbu        $v0, 0x1($a3)
    /* 51BB4 800BA3B4 0200E590 */  lbu        $a1, 0x2($a3)
    /* 51BB8 800BA3B8 0300E690 */  lbu        $a2, 0x3($a3)
    /* 51BBC 800BA3BC 0400E790 */  lbu        $a3, 0x4($a3)
    /* 51BC0 800BA3C0 80100200 */  sll        $v0, $v0, 2
    /* 51BC4 800BA3C4 21104300 */  addu       $v0, $v0, $v1
    /* 51BC8 800BA3C8 0000448C */  lw         $a0, 0x0($v0)
    /* 51BCC 800BA3CC FF16010C */  jal        func_80045BFC
    /* 51BD0 800BA3D0 00000000 */   nop
    /* 51BD4 800BA3D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 51BD8 800BA3D8 21100000 */  addu       $v0, $zero, $zero
    /* 51BDC 800BA3DC 0800E003 */  jr         $ra
    /* 51BE0 800BA3E0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BA39C
