nonmatching func_80012288, 0x3C

glabel func_80012288
    /* 2A88 80012288 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A8C 8001228C FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 2A90 80012290 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 2A94 80012294 0380033C */  lui        $v1, %hi(D_800378C0)
    /* 2A98 80012298 C07864AC */  sw         $a0, %lo(D_800378C0)($v1)
    /* 2A9C 8001229C C0786324 */  addiu      $v1, $v1, %lo(D_800378C0)
    /* 2AA0 800122A0 2428A200 */  and        $a1, $a1, $v0
    /* 2AA4 800122A4 21000424 */  addiu      $a0, $zero, 0x21
    /* 2AA8 800122A8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2AAC 800122AC 0C63000C */  jal        func_80018C30
    /* 2AB0 800122B0 040065AC */   sw        $a1, 0x4($v1)
    /* 2AB4 800122B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 2AB8 800122B8 00000000 */  nop
    /* 2ABC 800122BC 0800E003 */  jr         $ra
    /* 2AC0 800122C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012288
