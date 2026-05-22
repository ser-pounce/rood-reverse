nonmatching func_80012080, 0x38

glabel func_80012080
    /* 2880 80012080 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2884 80012084 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2888 80012088 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 288C 8001208C C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 2890 80012090 7F00C630 */  andi       $a2, $a2, 0x7F
    /* 2894 80012094 1A000424 */  addiu      $a0, $zero, 0x1A
    /* 2898 80012098 1000BFAF */  sw         $ra, 0x10($sp)
    /* 289C 8001209C 040045AC */  sw         $a1, 0x4($v0)
    /* 28A0 800120A0 0C63000C */  jal        func_80018C30
    /* 28A4 800120A4 080046AC */   sw        $a2, 0x8($v0)
    /* 28A8 800120A8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 28AC 800120AC 00000000 */  nop
    /* 28B0 800120B0 0800E003 */  jr         $ra
    /* 28B4 800120B4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012080
