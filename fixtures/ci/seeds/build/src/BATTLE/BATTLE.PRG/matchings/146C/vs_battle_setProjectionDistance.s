nonmatching vs_battle_setProjectionDistance, 0x24

glabel vs_battle_setProjectionDistance
    /* 144F0 8007CCF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 144F4 8007CCF4 0680023C */  lui        $v0, %hi(vs_main_projectionDistance)
    /* 144F8 8007CCF8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 144FC 8007CCFC 4D05010C */  jal        SetGeomScreen
    /* 14500 8007CD00 48E244AC */   sw        $a0, %lo(vs_main_projectionDistance)($v0)
    /* 14504 8007CD04 1000BF8F */  lw         $ra, 0x10($sp)
    /* 14508 8007CD08 00000000 */  nop
    /* 1450C 8007CD0C 0800E003 */  jr         $ra
    /* 14510 8007CD10 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel vs_battle_setProjectionDistance
