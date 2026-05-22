nonmatching func_80104868, 0x30

glabel func_80104868
    /* 2068 80104868 1180023C */  lui        $v0, %hi(_combiningItem)
    /* 206C 8010486C 81BC4490 */  lbu        $a0, %lo(_combiningItem)($v0)
    /* 2070 80104870 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2074 80104874 1000BFAF */  sw         $ra, 0x10($sp)
    /* 2078 80104878 1B0C040C */  jal        _disassembleWeapon
    /* 207C 8010487C 00000000 */   nop
    /* 2080 80104880 E00C040C */  jal        func_80103380
    /* 2084 80104884 01000424 */   addiu     $a0, $zero, 0x1
    /* 2088 80104888 1000BF8F */  lw         $ra, 0x10($sp)
    /* 208C 8010488C 00000000 */  nop
    /* 2090 80104890 0800E003 */  jr         $ra
    /* 2094 80104894 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80104868
