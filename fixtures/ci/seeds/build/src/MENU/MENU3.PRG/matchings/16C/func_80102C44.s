nonmatching func_80102C44, 0x50

glabel func_80102C44
    /* 444 80102C44 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 448 80102C48 1000B0AF */  sw         $s0, 0x10($sp)
    /* 44C 80102C4C 2180A000 */  addu       $s0, $a1, $zero
    /* 450 80102C50 1180033C */  lui        $v1, %hi(D_80109568)
    /* 454 80102C54 01000224 */  addiu      $v0, $zero, 0x1
    /* 458 80102C58 689562AC */  sw         $v0, %lo(D_80109568)($v1)
    /* 45C 80102C5C 1180023C */  lui        $v0, %hi(D_80109712)
    /* 460 80102C60 129740A0 */  sb         $zero, %lo(D_80109712)($v0)
    /* 464 80102C64 1180023C */  lui        $v0, %hi(D_80109713)
    /* 468 80102C68 1400BFAF */  sw         $ra, 0x14($sp)
    /* 46C 80102C6C F90A040C */  jal        func_80102BE4
    /* 470 80102C70 139740A0 */   sb        $zero, %lo(D_80109713)($v0)
    /* 474 80102C74 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 478 80102C78 21200002 */   addu      $a0, $s0, $zero
    /* 47C 80102C7C A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 480 80102C80 01000424 */   addiu     $a0, $zero, 0x1
    /* 484 80102C84 1400BF8F */  lw         $ra, 0x14($sp)
    /* 488 80102C88 1000B08F */  lw         $s0, 0x10($sp)
    /* 48C 80102C8C 0800E003 */  jr         $ra
    /* 490 80102C90 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80102C44
