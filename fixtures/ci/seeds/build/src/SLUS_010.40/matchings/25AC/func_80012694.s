nonmatching func_80012694, 0x2C

glabel func_80012694
    /* 2E94 80012694 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E98 80012698 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2E9C 8001269C FF008430 */  andi       $a0, $a0, 0xFF
    /* 2EA0 800126A0 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2EA4 800126A4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2EA8 800126A8 0C63000C */  jal        func_80018C30
    /* 2EAC 800126AC AA000424 */   addiu     $a0, $zero, 0xAA
    /* 2EB0 800126B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2EB4 800126B4 00000000 */  nop
    /* 2EB8 800126B8 0800E003 */  jr         $ra
    /* 2EBC 800126BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012694
