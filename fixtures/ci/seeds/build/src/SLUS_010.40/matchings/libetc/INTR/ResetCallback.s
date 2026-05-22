nonmatching ResetCallback, 0x30

glabel ResetCallback
    /* 100D4 8001F8D4 0380023C */  lui        $v0, %hi(D_800320D4)
    /* 100D8 8001F8D8 D420428C */  lw         $v0, %lo(D_800320D4)($v0)
    /* 100DC 8001F8DC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 100E0 8001F8E0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 100E4 8001F8E4 0C00428C */  lw         $v0, 0xC($v0)
    /* 100E8 8001F8E8 00000000 */  nop
    /* 100EC 8001F8EC 09F84000 */  jalr       $v0
    /* 100F0 8001F8F0 00000000 */   nop
    /* 100F4 8001F8F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 100F8 8001F8F8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 100FC 8001F8FC 0800E003 */  jr         $ra
    /* 10100 8001F900 00000000 */   nop
endlabel ResetCallback
