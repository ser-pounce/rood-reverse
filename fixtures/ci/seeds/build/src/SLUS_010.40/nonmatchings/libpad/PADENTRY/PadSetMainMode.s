nonmatching PadSetMainMode, 0x48

glabel PadSetMainMode
    /* 1C408 8002BC08 0380023C */  lui        $v0, %hi(D_800335B0)
    /* 1C40C 8002BC0C B035428C */  lw         $v0, %lo(D_800335B0)($v0)
    /* 1C410 8002BC10 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C414 8002BC14 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1C418 8002BC18 2180A000 */  addu       $s0, $a1, $zero
    /* 1C41C 8002BC1C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C420 8002BC20 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1C424 8002BC24 09F84000 */  jalr       $v0
    /* 1C428 8002BC28 2188C000 */   addu      $s1, $a2, $zero
    /* 1C42C 8002BC2C 21204000 */  addu       $a0, $v0, $zero
    /* 1C430 8002BC30 FF000532 */  andi       $a1, $s0, 0xFF
    /* 1C434 8002BC34 27B5000C */  jal        _padSetMainMode
    /* 1C438 8002BC38 FF002632 */   andi      $a2, $s1, 0xFF
    /* 1C43C 8002BC3C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1C440 8002BC40 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C444 8002BC44 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C448 8002BC48 0800E003 */  jr         $ra
    /* 1C44C 8002BC4C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel PadSetMainMode
