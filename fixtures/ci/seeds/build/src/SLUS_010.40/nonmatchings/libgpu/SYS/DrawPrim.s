nonmatching DrawPrim, 0x5C

glabel DrawPrim
    /* 193E8 80028BE8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 193EC 80028BEC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 193F0 80028BF0 21808000 */  addu       $s0, $a0, $zero
    /* 193F4 80028BF4 0380023C */  lui        $v0, %hi(D_8003343C)
    /* 193F8 80028BF8 3C34428C */  lw         $v0, %lo(D_8003343C)($v0)
    /* 193FC 80028BFC 1800BFAF */  sw         $ra, 0x18($sp)
    /* 19400 80028C00 1400B1AF */  sw         $s1, 0x14($sp)
    /* 19404 80028C04 3C00428C */  lw         $v0, 0x3C($v0)
    /* 19408 80028C08 03001192 */  lbu        $s1, 0x3($s0)
    /* 1940C 80028C0C 09F84000 */  jalr       $v0
    /* 19410 80028C10 21200000 */   addu      $a0, $zero, $zero
    /* 19414 80028C14 0380023C */  lui        $v0, %hi(D_8003343C)
    /* 19418 80028C18 3C34428C */  lw         $v0, %lo(D_8003343C)($v0)
    /* 1941C 80028C1C 04000426 */  addiu      $a0, $s0, 0x4
    /* 19420 80028C20 1400428C */  lw         $v0, 0x14($v0)
    /* 19424 80028C24 00000000 */  nop
    /* 19428 80028C28 09F84000 */  jalr       $v0
    /* 1942C 80028C2C 21282002 */   addu      $a1, $s1, $zero
    /* 19430 80028C30 1800BF8F */  lw         $ra, 0x18($sp)
    /* 19434 80028C34 1400B18F */  lw         $s1, 0x14($sp)
    /* 19438 80028C38 1000B08F */  lw         $s0, 0x10($sp)
    /* 1943C 80028C3C 0800E003 */  jr         $ra
    /* 19440 80028C40 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel DrawPrim
