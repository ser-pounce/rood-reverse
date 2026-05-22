nonmatching func_800F9A24, 0x54

glabel func_800F9A24
    /* 224 800F9A24 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 228 800F9A28 1000BFAF */  sw         $ra, 0x10($sp)
    /* 22C 800F9A2C 9EE6030C */  jal        func_800F9A78
    /* 230 800F9A30 00000000 */   nop
    /* 234 800F9A34 2CE7030C */  jal        func_800F9CB0
    /* 238 800F9A38 00000000 */   nop
    /* 23C 800F9A3C 0F80023C */  lui        $v0, %hi(D_800F453C)
    /* 240 800F9A40 01000424 */  addiu      $a0, $zero, 0x1
    /* 244 800F9A44 8000033C */  lui        $v1, (0x800000 >> 16)
    /* 248 800F9A48 3C45458C */  lw         $a1, %lo(D_800F453C)($v0)
    /* 24C 800F9A4C 21300000 */  addu       $a2, $zero, $zero
    /* 250 800F9A50 0800A28C */  lw         $v0, 0x8($a1)
    /* 254 800F9A54 2138C000 */  addu       $a3, $a2, $zero
    /* 258 800F9A58 25104300 */  or         $v0, $v0, $v1
    /* 25C 800F9A5C 0800A2AC */  sw         $v0, 0x8($a1)
    /* 260 800F9A60 8180020C */  jal        func_800A0204
    /* 264 800F9A64 21288000 */   addu      $a1, $a0, $zero
    /* 268 800F9A68 1000BF8F */  lw         $ra, 0x10($sp)
    /* 26C 800F9A6C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 270 800F9A70 0800E003 */  jr         $ra
    /* 274 800F9A74 00000000 */   nop
endlabel func_800F9A24
