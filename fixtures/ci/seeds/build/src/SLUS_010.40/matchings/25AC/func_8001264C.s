nonmatching func_8001264C, 0x48

glabel func_8001264C
    /* 2E4C 8001264C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E50 80012650 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 2E54 80012654 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 2E58 80012658 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2E5C 8001265C C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2E60 80012660 C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 2E64 80012664 2428A300 */  and        $a1, $a1, $v1
    /* 2E68 80012668 7F00E730 */  andi       $a3, $a3, 0x7F
    /* 2E6C 8001266C A1000424 */  addiu      $a0, $zero, 0xA1
    /* 2E70 80012670 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2E74 80012674 040045AC */  sw         $a1, 0x4($v0)
    /* 2E78 80012678 080046AC */  sw         $a2, 0x8($v0)
    /* 2E7C 8001267C 0C63000C */  jal        func_80018C30
    /* 2E80 80012680 0C0047AC */   sw        $a3, 0xC($v0)
    /* 2E84 80012684 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2E88 80012688 00000000 */  nop
    /* 2E8C 8001268C 0800E003 */  jr         $ra
    /* 2E90 80012690 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001264C
