nonmatching func_800128A0, 0x38

glabel func_800128A0
    /* 30A0 800128A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 30A4 800128A4 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 30A8 800128A8 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 30AC 800128AC C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 30B0 800128B0 7F00C630 */  andi       $a2, $a2, 0x7F
    /* 30B4 800128B4 C1000424 */  addiu      $a0, $zero, 0xC1
    /* 30B8 800128B8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 30BC 800128BC 040045AC */  sw         $a1, 0x4($v0)
    /* 30C0 800128C0 0C63000C */  jal        func_80018C30
    /* 30C4 800128C4 080046AC */   sw        $a2, 0x8($v0)
    /* 30C8 800128C8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 30CC 800128CC 00000000 */  nop
    /* 30D0 800128D0 0800E003 */  jr         $ra
    /* 30D4 800128D4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800128A0
