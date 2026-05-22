nonmatching func_8006F5FC, 0x34

glabel func_8006F5FC
    /* 6DFC 8006F5FC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6E00 8006F600 0F80023C */  lui        $v0, %hi(D_800F196C)
    /* 6E04 8006F604 0C000324 */  addiu      $v1, $zero, 0xC
    /* 6E08 8006F608 6C1943AC */  sw         $v1, %lo(D_800F196C)($v0)
    /* 6E0C 8006F60C 0F80023C */  lui        $v0, %hi(_cameraMode)
    /* 6E10 8006F610 21200000 */  addu       $a0, $zero, $zero
    /* 6E14 8006F614 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6E18 8006F618 7179020C */  jal        func_8009E5C4
    /* 6E1C 8006F61C F01840AC */   sw        $zero, %lo(_cameraMode)($v0)
    /* 6E20 8006F620 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6E24 8006F624 00000000 */  nop
    /* 6E28 8006F628 0800E003 */  jr         $ra
    /* 6E2C 8006F62C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8006F5FC
