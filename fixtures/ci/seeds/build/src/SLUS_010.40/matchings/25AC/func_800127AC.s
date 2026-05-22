nonmatching func_800127AC, 0x34

glabel func_800127AC
    /* 2FAC 800127AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2FB0 800127B0 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2FB4 800127B4 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2FB8 800127B8 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 2FBC 800127BC FF00A530 */  andi       $a1, $a1, 0xFF
    /* 2FC0 800127C0 AD000424 */  addiu      $a0, $zero, 0xAD
    /* 2FC4 800127C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2FC8 800127C8 0C63000C */  jal        func_80018C30
    /* 2FCC 800127CC 040045AC */   sw        $a1, 0x4($v0)
    /* 2FD0 800127D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2FD4 800127D4 00000000 */  nop
    /* 2FD8 800127D8 0800E003 */  jr         $ra
    /* 2FDC 800127DC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800127AC
