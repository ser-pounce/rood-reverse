nonmatching func_80013348, 0x30

glabel func_80013348
    /* 3B48 80013348 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3B4C 8001334C 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 3B50 80013350 7F008430 */  andi       $a0, $a0, 0x7F
    /* 3B54 80013354 00220400 */  sll        $a0, $a0, 8
    /* 3B58 80013358 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 3B5C 8001335C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3B60 80013360 0C63000C */  jal        func_80018C30
    /* 3B64 80013364 E4000424 */   addiu     $a0, $zero, 0xE4
    /* 3B68 80013368 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3B6C 8001336C 00000000 */  nop
    /* 3B70 80013370 0800E003 */  jr         $ra
    /* 3B74 80013374 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80013348
