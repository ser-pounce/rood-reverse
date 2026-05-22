nonmatching func_8002480C, 0x40

glabel func_8002480C
    /* 1500C 8002480C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 15010 80024810 1000BFAF */  sw         $ra, 0x10($sp)
    /* 15014 80024814 0380013C */  lui        $at, %hi(D_8003267C)
    /* 15018 80024818 4186000C */  jal        CD_flush
    /* 1501C 8002481C 7C2620AC */   sw        $zero, %lo(D_8003267C)($at)
    /* 15020 80024820 21200000 */  addu       $a0, $zero, $zero
    /* 15024 80024824 0380013C */  lui        $at, %hi(D_800321FC)
    /* 15028 80024828 FC2120AC */  sw         $zero, %lo(D_800321FC)($at)
    /* 1502C 8002482C 0380013C */  lui        $at, %hi(D_80032200)
    /* 15030 80024830 002220AC */  sw         $zero, %lo(D_80032200)($at)
    /* 15034 80024834 667E000C */  jal        VSyncCallbacks
    /* 15038 80024838 21280000 */   addu      $a1, $zero, $zero
    /* 1503C 8002483C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 15040 80024840 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 15044 80024844 0800E003 */  jr         $ra
    /* 15048 80024848 00000000 */   nop
endlabel func_8002480C
