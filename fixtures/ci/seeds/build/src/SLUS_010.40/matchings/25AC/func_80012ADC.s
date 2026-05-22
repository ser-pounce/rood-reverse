nonmatching func_80012ADC, 0x2C

glabel func_80012ADC
    /* 32DC 80012ADC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 32E0 80012AE0 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 32E4 80012AE4 FF008430 */  andi       $a0, $a0, 0xFF
    /* 32E8 80012AE8 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 32EC 80012AEC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 32F0 80012AF0 0C63000C */  jal        func_80018C30
    /* 32F4 80012AF4 D8000424 */   addiu     $a0, $zero, 0xD8
    /* 32F8 80012AF8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 32FC 80012AFC 00000000 */  nop
    /* 3300 80012B00 0800E003 */  jr         $ra
    /* 3304 80012B04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012ADC
