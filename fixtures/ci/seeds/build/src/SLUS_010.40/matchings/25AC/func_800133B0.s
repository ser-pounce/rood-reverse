nonmatching func_800133B0, 0x30

glabel func_800133B0
    /* 3BB0 800133B0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3BB4 800133B4 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 3BB8 800133B8 FF008430 */  andi       $a0, $a0, 0xFF
    /* 3BBC 800133BC 00220400 */  sll        $a0, $a0, 8
    /* 3BC0 800133C0 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 3BC4 800133C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3BC8 800133C8 0C63000C */  jal        func_80018C30
    /* 3BCC 800133CC E6000424 */   addiu     $a0, $zero, 0xE6
    /* 3BD0 800133D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3BD4 800133D4 00000000 */  nop
    /* 3BD8 800133D8 0800E003 */  jr         $ra
    /* 3BDC 800133DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800133B0
