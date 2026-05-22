nonmatching func_800129A4, 0x2C

glabel func_800129A4
    /* 31A4 800129A4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 31A8 800129A8 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 31AC 800129AC FF008430 */  andi       $a0, $a0, 0xFF
    /* 31B0 800129B0 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 31B4 800129B4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 31B8 800129B8 0C63000C */  jal        func_80018C30
    /* 31BC 800129BC D0000424 */   addiu     $a0, $zero, 0xD0
    /* 31C0 800129C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 31C4 800129C4 00000000 */  nop
    /* 31C8 800129C8 0800E003 */  jr         $ra
    /* 31CC 800129CC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800129A4
