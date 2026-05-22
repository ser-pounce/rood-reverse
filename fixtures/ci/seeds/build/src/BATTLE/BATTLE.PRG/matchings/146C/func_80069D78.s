nonmatching func_80069D78, 0x44

glabel func_80069D78
    /* 1578 80069D78 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 157C 80069D7C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1580 80069D80 14EA010C */  jal        vs_battle_syncCameraAnglesFromPosition
    /* 1584 80069D84 21200000 */   addu      $a0, $zero, $zero
    /* 1588 80069D88 801F043C */  lui        $a0, %hi(D_1F800000)
    /* 158C 80069D8C 00008424 */  addiu      $a0, $a0, %lo(D_1F800000)
    /* 1590 80069D90 0F80023C */  lui        $v0, %hi(_firstPersonViewEnabled)
    /* 1594 80069D94 1000838C */  lw         $v1, 0x10($a0)
    /* 1598 80069D98 6C18428C */  lw         $v0, %lo(_firstPersonViewEnabled)($v0)
    /* 159C 80069D9C FF7F6330 */  andi       $v1, $v1, 0x7FFF
    /* 15A0 80069DA0 00140200 */  sll        $v0, $v0, 16
    /* 15A4 80069DA4 25186200 */  or         $v1, $v1, $v0
    /* 15A8 80069DA8 100083AC */  sw         $v1, 0x10($a0)
    /* 15AC 80069DAC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 15B0 80069DB0 00000000 */  nop
    /* 15B4 80069DB4 0800E003 */  jr         $ra
    /* 15B8 80069DB8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80069D78
