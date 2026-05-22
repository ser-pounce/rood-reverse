nonmatching func_800CB18C, 0x34

glabel func_800CB18C
    /* 6298C 800CB18C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62990 800CB190 0F80023C */  lui        $v0, %hi(D_800EB9C8)
    /* 62994 800CB194 C8B944AC */  sw         $a0, %lo(D_800EB9C8)($v0)
    /* 62998 800CB198 0F80023C */  lui        $v0, %hi(D_800EB9C4)
    /* 6299C 800CB19C 0C000424 */  addiu      $a0, $zero, 0xC
    /* 629A0 800CB1A0 02000524 */  addiu      $a1, $zero, 0x2
    /* 629A4 800CB1A4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 629A8 800CB1A8 342B030C */  jal        func_800CACD0
    /* 629AC 800CB1AC C4B940AC */   sw        $zero, %lo(D_800EB9C4)($v0)
    /* 629B0 800CB1B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 629B4 800CB1B4 00000000 */  nop
    /* 629B8 800CB1B8 0800E003 */  jr         $ra
    /* 629BC 800CB1BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800CB18C
