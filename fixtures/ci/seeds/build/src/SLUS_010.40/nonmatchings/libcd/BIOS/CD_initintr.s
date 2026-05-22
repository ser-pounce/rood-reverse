nonmatching CD_initintr, 0x4C

glabel CD_initintr
    /* 122C8 80021AC8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 122CC 80021ACC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 122D0 80021AD0 0380013C */  lui        $at, %hi(D_80032200)
    /* 122D4 80021AD4 002220AC */  sw         $zero, %lo(D_80032200)($at)
    /* 122D8 80021AD8 0380013C */  lui        $at, %hi(D_800321FC)
    /* 122DC 80021ADC FC2120AC */  sw         $zero, %lo(D_800321FC)($at)
    /* 122E0 80021AE0 0380013C */  lui        $at, %hi(D_8003220C)
    /* 122E4 80021AE4 0C2220AC */  sw         $zero, %lo(D_8003220C)($at)
    /* 122E8 80021AE8 0380013C */  lui        $at, %hi(D_80032208)
    /* 122EC 80021AEC 357E000C */  jal        ResetCallback
    /* 122F0 80021AF0 082220AC */   sw        $zero, %lo(D_80032208)($at)
    /* 122F4 80021AF4 0280053C */  lui        $a1, %hi(func_80022054)
    /* 122F8 80021AF8 5420A524 */  addiu      $a1, $a1, %lo(func_80022054)
    /* 122FC 80021AFC 417E000C */  jal        InterruptCallback
    /* 12300 80021B00 02000424 */   addiu     $a0, $zero, 0x2
    /* 12304 80021B04 1000BF8F */  lw         $ra, 0x10($sp)
    /* 12308 80021B08 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 1230C 80021B0C 0800E003 */  jr         $ra
    /* 12310 80021B10 00000000 */   nop
endlabel CD_initintr
