nonmatching func_80104C0C, 0x34

glabel func_80104C0C
    /* 240C 80104C0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2410 80104C10 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2414 80104C14 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2418 80104C18 CE12040C */  jal        func_80104B38
    /* 241C 80104C1C 2180A000 */   addu      $s0, $a1, $zero
    /* 2420 80104C20 F5EE030C */  jal        vs_mainMenu_drawClassAffinityType
    /* 2424 80104C24 21200002 */   addu      $a0, $s0, $zero
    /* 2428 80104C28 A9EF030C */  jal        vs_mainMenu_renderEquipStats
    /* 242C 80104C2C 01000424 */   addiu     $a0, $zero, 0x1
    /* 2430 80104C30 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2434 80104C34 1000B08F */  lw         $s0, 0x10($sp)
    /* 2438 80104C38 0800E003 */  jr         $ra
    /* 243C 80104C3C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80104C0C
