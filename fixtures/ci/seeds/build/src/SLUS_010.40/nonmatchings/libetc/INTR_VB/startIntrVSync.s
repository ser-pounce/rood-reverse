nonmatching startIntrVSync, 0x58

glabel startIntrVSync
    /* 10794 8001FF94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 10798 8001FF98 0380043C */  lui        $a0, %hi(D_800320F4)
    /* 1079C 8001FF9C F4208424 */  addiu      $a0, $a0, %lo(D_800320F4)
    /* 107A0 8001FFA0 0380033C */  lui        $v1, %hi(D_80032118)
    /* 107A4 8001FFA4 1821638C */  lw         $v1, %lo(D_80032118)($v1)
    /* 107A8 8001FFA8 00010224 */  addiu      $v0, $zero, 0x100
    /* 107AC 8001FFAC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 107B0 8001FFB0 000062AC */  sw         $v0, 0x0($v1)
    /* 107B4 8001FFB4 0380013C */  lui        $at, %hi(D_80032114)
    /* 107B8 8001FFB8 142120AC */  sw         $zero, %lo(D_80032114)($at)
    /* 107BC 8001FFBC 2180000C */  jal        func_80020084
    /* 107C0 8001FFC0 08000524 */   addiu     $a1, $zero, 0x8
    /* 107C4 8001FFC4 0280053C */  lui        $a1, %hi(func_8001FFEC)
    /* 107C8 8001FFC8 ECFFA524 */  addiu      $a1, $a1, %lo(func_8001FFEC)
    /* 107CC 8001FFCC 417E000C */  jal        InterruptCallback
    /* 107D0 8001FFD0 21200000 */   addu      $a0, $zero, $zero
    /* 107D4 8001FFD4 0280023C */  lui        $v0, %hi(func_80020058)
    /* 107D8 8001FFD8 58004224 */  addiu      $v0, $v0, %lo(func_80020058)
    /* 107DC 8001FFDC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 107E0 8001FFE0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 107E4 8001FFE4 0800E003 */  jr         $ra
    /* 107E8 8001FFE8 00000000 */   nop
endlabel startIntrVSync
