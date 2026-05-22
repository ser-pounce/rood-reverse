nonmatching func_80013378, 0x38

glabel func_80013378
    /* 3B78 80013378 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3B7C 8001337C 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 3B80 80013380 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 3B84 80013384 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 3B88 80013388 7F00A530 */  andi       $a1, $a1, 0x7F
    /* 3B8C 8001338C 002A0500 */  sll        $a1, $a1, 8
    /* 3B90 80013390 E5000424 */  addiu      $a0, $zero, 0xE5
    /* 3B94 80013394 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3B98 80013398 0C63000C */  jal        func_80018C30
    /* 3B9C 8001339C 040045AC */   sw        $a1, 0x4($v0)
    /* 3BA0 800133A0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3BA4 800133A4 00000000 */  nop
    /* 3BA8 800133A8 0800E003 */  jr         $ra
    /* 3BAC 800133AC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80013378
