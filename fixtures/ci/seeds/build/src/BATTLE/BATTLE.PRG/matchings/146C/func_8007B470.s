nonmatching func_8007B470, 0x54

glabel func_8007B470
    /* 12C70 8007B470 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 12C74 8007B474 1800BFAF */  sw         $ra, 0x18($sp)
    /* 12C78 8007B478 FB23010C */  jal        vs_main_setClutState
    /* 12C7C 8007B47C 01000424 */   addiu     $a0, $zero, 0x1
    /* 12C80 8007B480 08000424 */  addiu      $a0, $zero, 0x8
    /* 12C84 8007B484 04000524 */  addiu      $a1, $zero, 0x4
    /* 12C88 8007B488 21300000 */  addu       $a2, $zero, $zero
    /* 12C8C 8007B48C 2138C000 */  addu       $a3, $a2, $zero
    /* 12C90 8007B490 6EEC010C */  jal        func_8007B1B8
    /* 12C94 8007B494 1000A0AF */   sw        $zero, 0x10($sp)
    /* 12C98 8007B498 94B0010C */  jal        func_8006C250
    /* 12C9C 8007B49C 00000000 */   nop
    /* 12CA0 8007B4A0 2F2D020C */  jal        func_8008B4BC
    /* 12CA4 8007B4A4 21200000 */   addu      $a0, $zero, $zero
    /* 12CA8 8007B4A8 2039020C */  jal        func_8008E480
    /* 12CAC 8007B4AC 21200000 */   addu      $a0, $zero, $zero
    /* 12CB0 8007B4B0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 12CB4 8007B4B4 0F80023C */  lui        $v0, %hi(D_800F1968)
    /* 12CB8 8007B4B8 681940AC */  sw         $zero, %lo(D_800F1968)($v0)
    /* 12CBC 8007B4BC 0800E003 */  jr         $ra
    /* 12CC0 8007B4C0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007B470
