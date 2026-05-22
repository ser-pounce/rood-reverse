nonmatching func_80012A04, 0x3C

glabel func_80012A04
    /* 3204 80012A04 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3208 80012A08 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 320C 80012A0C C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 3210 80012A10 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 3214 80012A14 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 3218 80012A18 FF00C630 */  andi       $a2, $a2, 0xFF
    /* 321C 80012A1C D2000424 */  addiu      $a0, $zero, 0xD2
    /* 3220 80012A20 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3224 80012A24 040045AC */  sw         $a1, 0x4($v0)
    /* 3228 80012A28 0C63000C */  jal        func_80018C30
    /* 322C 80012A2C 080046AC */   sw        $a2, 0x8($v0)
    /* 3230 80012A30 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3234 80012A34 00000000 */  nop
    /* 3238 80012A38 0800E003 */  jr         $ra
    /* 323C 80012A3C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012A04
