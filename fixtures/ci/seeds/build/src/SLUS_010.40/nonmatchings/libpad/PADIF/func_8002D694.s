nonmatching func_8002D694, 0x48

glabel func_8002D694
    /* 1DE94 8002D694 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1DE98 8002D698 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1DE9C 8002D69C 0380023C */  lui        $v0, %hi(D_800335B4)
    /* 1DEA0 8002D6A0 B435428C */  lw         $v0, %lo(D_800335B4)($v0)
    /* 1DEA4 8002D6A4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1DEA8 8002D6A8 09F84000 */  jalr       $v0
    /* 1DEAC 8002D6AC 21808000 */   addu      $s0, $a0, $zero
    /* 1DEB0 8002D6B0 21200002 */  addu       $a0, $s0, $zero
    /* 1DEB4 8002D6B4 3C00038E */  lw         $v1, 0x3C($s0)
    /* 1DEB8 8002D6B8 FEFF0524 */  addiu      $a1, $zero, -0x2
    /* 1DEBC 8002D6BC 0380013C */  lui        $at, %hi(D_8003361C)
    /* 1DEC0 8002D6C0 1C3622AC */  sw         $v0, %lo(D_8003361C)($at)
    /* 1DEC4 8002D6C4 4AB1000C */  jal        _padSioRW
    /* 1DEC8 8002D6C8 000060A0 */   sb        $zero, 0x0($v1)
    /* 1DECC 8002D6CC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1DED0 8002D6D0 1000B08F */  lw         $s0, 0x10($sp)
    /* 1DED4 8002D6D4 0800E003 */  jr         $ra
    /* 1DED8 8002D6D8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D694
