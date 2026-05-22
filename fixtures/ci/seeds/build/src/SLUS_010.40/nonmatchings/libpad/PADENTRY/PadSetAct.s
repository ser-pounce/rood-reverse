nonmatching PadSetAct, 0x48

glabel PadSetAct
    /* 1C450 8002BC50 0380023C */  lui        $v0, %hi(D_800335B0)
    /* 1C454 8002BC54 B035428C */  lw         $v0, %lo(D_800335B0)($v0)
    /* 1C458 8002BC58 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C45C 8002BC5C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C460 8002BC60 2180A000 */  addu       $s0, $a1, $zero
    /* 1C464 8002BC64 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C468 8002BC68 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1C46C 8002BC6C 09F84000 */  jalr       $v0
    /* 1C470 8002BC70 2188C000 */   addu      $s1, $a2, $zero
    /* 1C474 8002BC74 21204000 */  addu       $a0, $v0, $zero
    /* 1C478 8002BC78 21280002 */  addu       $a1, $s0, $zero
    /* 1C47C 8002BC7C A5B2000C */  jal        _padSetAct
    /* 1C480 8002BC80 21302002 */   addu      $a2, $s1, $zero
    /* 1C484 8002BC84 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1C488 8002BC88 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C48C 8002BC8C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C490 8002BC90 0800E003 */  jr         $ra
    /* 1C494 8002BC94 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel PadSetAct
    /* 1C498 8002BC98 00000000 */  nop
    /* 1C49C 8002BC9C 00000000 */  nop
    /* 1C4A0 8002BCA0 00000000 */  nop
