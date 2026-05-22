nonmatching _setCameraPositionFromAngles, 0x2C

glabel _setCameraPositionFromAngles
    /* 122CC 8007AACC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 122D0 8007AAD0 21308000 */  addu       $a2, $a0, $zero
    /* 122D4 8007AAD4 801F043C */  lui        $a0, %hi(D_1F800034)
    /* 122D8 8007AAD8 34008424 */  addiu      $a0, $a0, %lo(D_1F800034)
    /* 122DC 8007AADC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 122E0 8007AAE0 77EA010C */  jal        _computeSphericalOffset
    /* 122E4 8007AAE4 10008524 */   addiu     $a1, $a0, 0x10
    /* 122E8 8007AAE8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 122EC 8007AAEC 00000000 */  nop
    /* 122F0 8007AAF0 0800E003 */  jr         $ra
    /* 122F4 8007AAF4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel _setCameraPositionFromAngles
