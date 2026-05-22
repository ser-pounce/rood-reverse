nonmatching func_80012608, 0x44

glabel func_80012608
    /* 2E08 80012608 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2E0C 8001260C FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 2E10 80012610 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 2E14 80012614 0380023C */  lui        $v0, %hi(D_800378C0)
    /* 2E18 80012618 C07844AC */  sw         $a0, %lo(D_800378C0)($v0)
    /* 2E1C 8001261C C0784224 */  addiu      $v0, $v0, %lo(D_800378C0)
    /* 2E20 80012620 2428A300 */  and        $a1, $a1, $v1
    /* 2E24 80012624 7F00C630 */  andi       $a2, $a2, 0x7F
    /* 2E28 80012628 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 2E2C 8001262C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2E30 80012630 040045AC */  sw         $a1, 0x4($v0)
    /* 2E34 80012634 0C63000C */  jal        func_80018C30
    /* 2E38 80012638 080046AC */   sw        $a2, 0x8($v0)
    /* 2E3C 8001263C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2E40 80012640 00000000 */  nop
    /* 2E44 80012644 0800E003 */  jr         $ra
    /* 2E48 80012648 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012608
