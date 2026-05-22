nonmatching func_8006D028, 0x3C

glabel func_8006D028
    /* 4828 8006D028 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 482C 8006D02C 21308000 */  addu       $a2, $a0, $zero
    /* 4830 8006D030 0F80023C */  lui        $v0, %hi(D_800F185C)
    /* 4834 8006D034 0E000424 */  addiu      $a0, $zero, 0xE
    /* 4838 8006D038 08000524 */  addiu      $a1, $zero, 0x8
    /* 483C 8006D03C 10000724 */  addiu      $a3, $zero, 0x10
    /* 4840 8006D040 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4844 8006D044 5C1846AC */  sw         $a2, %lo(D_800F185C)($v0)
    /* 4848 8006D048 1000A0AF */  sw         $zero, 0x10($sp)
    /* 484C 8006D04C A7EC010C */  jal        func_8007B29C
    /* 4850 8006D050 1400A0AF */   sw        $zero, 0x14($sp)
    /* 4854 8006D054 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4858 8006D058 00000000 */  nop
    /* 485C 8006D05C 0800E003 */  jr         $ra
    /* 4860 8006D060 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8006D028
