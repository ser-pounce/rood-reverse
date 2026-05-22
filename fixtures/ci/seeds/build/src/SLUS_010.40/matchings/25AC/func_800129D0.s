nonmatching func_800129D0, 0x34

glabel func_800129D0
    /* 31D0 800129D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 31D4 800129D4 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 31D8 800129D8 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 31DC 800129DC C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 31E0 800129E0 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 31E4 800129E4 D1000424 */  addiu      $a0, $zero, 0xD1
    /* 31E8 800129E8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 31EC 800129EC 0C63000C */  jal        func_80018C30
    /* 31F0 800129F0 040045AC */   sw        $a1, 0x4($v0)
    /* 31F4 800129F4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 31F8 800129F8 00000000 */  nop
    /* 31FC 800129FC 0800E003 */  jr         $ra
    /* 3200 80012A00 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800129D0
