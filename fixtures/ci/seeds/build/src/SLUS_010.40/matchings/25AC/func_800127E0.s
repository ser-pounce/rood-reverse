nonmatching func_800127E0, 0x44

glabel func_800127E0
    /* 2FE0 800127E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2FE4 800127E4 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 2FE8 800127E8 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 2FEC 800127EC 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2FF0 800127F0 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2FF4 800127F4 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 2FF8 800127F8 2428A300 */  and        $a1, $a1, $v1
    /* 2FFC 800127FC FF00C630 */  andi       $a2, $a2, 0xFF
    /* 3000 80012800 A4000424 */  addiu      $a0, $zero, 0xA4
    /* 3004 80012804 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3008 80012808 040045AC */  sw         $a1, 0x4($v0)
    /* 300C 8001280C 0C63000C */  jal        func_80018C30
    /* 3010 80012810 080046AC */   sw        $a2, 0x8($v0)
    /* 3014 80012814 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3018 80012818 00000000 */  nop
    /* 301C 8001281C 0800E003 */  jr         $ra
    /* 3020 80012820 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800127E0
