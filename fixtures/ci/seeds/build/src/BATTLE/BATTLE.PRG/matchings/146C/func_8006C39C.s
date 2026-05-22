nonmatching func_8006C39C, 0x70

glabel func_8006C39C
    /* 3B9C 8006C39C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3BA0 8006C3A0 0D000424 */  addiu      $a0, $zero, 0xD
    /* 3BA4 8006C3A4 04000524 */  addiu      $a1, $zero, 0x4
    /* 3BA8 8006C3A8 FCFF0624 */  addiu      $a2, $zero, -0x4
    /* 3BAC 8006C3AC 2138C000 */  addu       $a3, $a2, $zero
    /* 3BB0 8006C3B0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 3BB4 8006C3B4 43EC010C */  jal        func_8007B10C
    /* 3BB8 8006C3B8 1000A0AF */   sw        $zero, 0x10($sp)
    /* 3BBC 8006C3BC FB23010C */  jal        vs_main_setClutState
    /* 3BC0 8006C3C0 21200000 */   addu      $a0, $zero, $zero
    /* 3BC4 8006C3C4 A8B0010C */  jal        func_8006C2A0
    /* 3BC8 8006C3C8 00000000 */   nop
    /* 3BCC 8006C3CC 2F2D020C */  jal        func_8008B4BC
    /* 3BD0 8006C3D0 01000424 */   addiu     $a0, $zero, 0x1
    /* 3BD4 8006C3D4 6535020C */  jal        func_8008D594
    /* 3BD8 8006C3D8 01000424 */   addiu     $a0, $zero, 0x1
    /* 3BDC 8006C3DC 322D020C */  jal        func_8008B4C8
    /* 3BE0 8006C3E0 21200000 */   addu      $a0, $zero, $zero
    /* 3BE4 8006C3E4 2039020C */  jal        func_8008E480
    /* 3BE8 8006C3E8 01000424 */   addiu     $a0, $zero, 0x1
    /* 3BEC 8006C3EC DC56020C */  jal        func_80095B70
    /* 3BF0 8006C3F0 01000424 */   addiu     $a0, $zero, 0x1
    /* 3BF4 8006C3F4 0F80033C */  lui        $v1, %hi(D_800F1968)
    /* 3BF8 8006C3F8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3BFC 8006C3FC 01000224 */  addiu      $v0, $zero, 0x1
    /* 3C00 8006C400 681962AC */  sw         $v0, %lo(D_800F1968)($v1)
    /* 3C04 8006C404 0800E003 */  jr         $ra
    /* 3C08 8006C408 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006C39C
