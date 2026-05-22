nonmatching func_80012738, 0x48

glabel func_80012738
    /* 2F38 80012738 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2F3C 8001273C FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 2F40 80012740 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 2F44 80012744 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2F48 80012748 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2F4C 8001274C C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 2F50 80012750 2428A300 */  and        $a1, $a1, $v1
    /* 2F54 80012754 FF00E730 */  andi       $a3, $a3, 0xFF
    /* 2F58 80012758 A3000424 */  addiu      $a0, $zero, 0xA3
    /* 2F5C 8001275C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2F60 80012760 040045AC */  sw         $a1, 0x4($v0)
    /* 2F64 80012764 080046AC */  sw         $a2, 0x8($v0)
    /* 2F68 80012768 0C63000C */  jal        func_80018C30
    /* 2F6C 8001276C 0C0047AC */   sw        $a3, 0xC($v0)
    /* 2F70 80012770 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2F74 80012774 00000000 */  nop
    /* 2F78 80012778 0800E003 */  jr         $ra
    /* 2F7C 8001277C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012738
