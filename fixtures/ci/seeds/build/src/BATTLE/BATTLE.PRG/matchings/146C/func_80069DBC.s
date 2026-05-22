nonmatching func_80069DBC, 0x30

glabel func_80069DBC
    /* 15BC 80069DBC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 15C0 80069DC0 0680023C */  lui        $v0, %hi(D_80060064)
    /* 15C4 80069DC4 0680043C */  lui        $a0, %hi(D_80061078)
    /* 15C8 80069DC8 78108424 */  addiu      $a0, $a0, %lo(D_80061078)
    /* 15CC 80069DCC 20050524 */  addiu      $a1, $zero, 0x520
    /* 15D0 80069DD0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 15D4 80069DD4 4424010C */  jal        vs_main_bzero
    /* 15D8 80069DD8 640040AC */   sw        $zero, %lo(D_80060064)($v0)
    /* 15DC 80069DDC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 15E0 80069DE0 00000000 */  nop
    /* 15E4 80069DE4 0800E003 */  jr         $ra
    /* 15E8 80069DE8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80069DBC
