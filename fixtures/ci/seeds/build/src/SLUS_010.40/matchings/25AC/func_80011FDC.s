nonmatching func_80011FDC, 0x28

glabel func_80011FDC
    /* 27DC 80011FDC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 27E0 80011FE0 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 27E4 80011FE4 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 27E8 80011FE8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 27EC 80011FEC 0C63000C */  jal        func_80018C30
    /* 27F0 80011FF0 11000424 */   addiu     $a0, $zero, 0x11
    /* 27F4 80011FF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 27F8 80011FF8 00000000 */  nop
    /* 27FC 80011FFC 0800E003 */  jr         $ra
    /* 2800 80012000 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80011FDC
