nonmatching func_80104034, 0x44

glabel func_80104034
    /* 1834 80104034 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1838 80104038 1000B0AF */  sw         $s0, 0x10($sp)
    /* 183C 8010403C 2180A000 */  addu       $s0, $a1, $zero
    /* 1840 80104040 1180023C */  lui        $v0, %hi(D_80109A7C)
    /* 1844 80104044 7C9A40A0 */  sb         $zero, %lo(D_80109A7C)($v0)
    /* 1848 80104048 1180023C */  lui        $v0, %hi(D_80109A7D)
    /* 184C 8010404C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1850 80104050 F50F040C */  jal        func_80103FD4
    /* 1854 80104054 7D9A40A0 */   sb        $zero, %lo(D_80109A7D)($v0)
    /* 1858 80104058 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 185C 8010405C 21200002 */   addu      $a0, $s0, $zero
    /* 1860 80104060 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 1864 80104064 01000424 */   addiu     $a0, $zero, 0x1
    /* 1868 80104068 1400BF8F */  lw         $ra, 0x14($sp)
    /* 186C 8010406C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1870 80104070 0800E003 */  jr         $ra
    /* 1874 80104074 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80104034
