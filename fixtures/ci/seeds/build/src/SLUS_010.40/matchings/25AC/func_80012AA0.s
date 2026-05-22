nonmatching func_80012AA0, 0x3C

glabel func_80012AA0
    /* 32A0 80012AA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 32A4 80012AA4 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 32A8 80012AA8 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 32AC 80012AAC C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 32B0 80012AB0 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 32B4 80012AB4 FF00C630 */  andi       $a2, $a2, 0xFF
    /* 32B8 80012AB8 D6000424 */  addiu      $a0, $zero, 0xD6
    /* 32BC 80012ABC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 32C0 80012AC0 040045AC */  sw         $a1, 0x4($v0)
    /* 32C4 80012AC4 0C63000C */  jal        func_80018C30
    /* 32C8 80012AC8 080046AC */   sw        $a2, 0x8($v0)
    /* 32CC 80012ACC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 32D0 80012AD0 00000000 */  nop
    /* 32D4 80012AD4 0800E003 */  jr         $ra
    /* 32D8 80012AD8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012AA0
