nonmatching func_8010455C, 0x5C

glabel func_8010455C
    /* 1D5C 8010455C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D60 80104560 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1D64 80104564 1180103C */  lui        $s0, %hi(D_801080A8)
    /* 1D68 80104568 A880048E */  lw         $a0, %lo(D_801080A8)($s0)
    /* 1D6C 8010456C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1D70 80104570 4511040C */  jal        func_80104514
    /* 1D74 80104574 FFFF8424 */   addiu     $a0, $a0, -0x1
    /* 1D78 80104578 0F80043C */  lui        $a0, %hi(vs_battle_actors)
    /* 1D7C 8010457C A880038E */  lw         $v1, %lo(D_801080A8)($s0)
    /* 1D80 80104580 28198424 */  addiu      $a0, $a0, %lo(vs_battle_actors)
    /* 1D84 80104584 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1D88 80104588 80180300 */  sll        $v1, $v1, 2
    /* 1D8C 8010458C 21186400 */  addu       $v1, $v1, $a0
    /* 1D90 80104590 0000638C */  lw         $v1, 0x0($v1)
    /* 1D94 80104594 02004224 */  addiu      $v0, $v0, 0x2
    /* 1D98 80104598 3C00638C */  lw         $v1, 0x3C($v1)
    /* 1D9C 8010459C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1DA0 801045A0 38036394 */  lhu        $v1, 0x338($v1)
    /* 1DA4 801045A4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1DA8 801045A8 2B180300 */  sltu       $v1, $zero, $v1
    /* 1DAC 801045AC 21104300 */  addu       $v0, $v0, $v1
    /* 1DB0 801045B0 0800E003 */  jr         $ra
    /* 1DB4 801045B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8010455C
