nonmatching func_800126F4, 0x44

glabel func_800126F4
    /* 2EF4 800126F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2EF8 800126F8 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 2EFC 800126FC FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 2F00 80012700 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2F04 80012704 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2F08 80012708 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 2F0C 8001270C 2428A300 */  and        $a1, $a1, $v1
    /* 2F10 80012710 FF00C630 */  andi       $a2, $a2, 0xFF
    /* 2F14 80012714 A2000424 */  addiu      $a0, $zero, 0xA2
    /* 2F18 80012718 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2F1C 8001271C 040045AC */  sw         $a1, 0x4($v0)
    /* 2F20 80012720 0C63000C */  jal        func_80018C30
    /* 2F24 80012724 080046AC */   sw        $a2, 0x8($v0)
    /* 2F28 80012728 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2F2C 8001272C 00000000 */  nop
    /* 2F30 80012730 0800E003 */  jr         $ra
    /* 2F34 80012734 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800126F4
