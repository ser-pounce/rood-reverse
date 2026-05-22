nonmatching func_800BB5AC, 0x58

glabel func_800BB5AC
    /* 52DAC 800BB5AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 52DB0 800BB5B0 01008424 */  addiu      $a0, $a0, 0x1
    /* 52DB4 800BB5B4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 52DB8 800BB5B8 80FF020C */  jal        vs_battle_getShort
    /* 52DBC 800BB5BC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 52DC0 800BB5C0 00180424 */  addiu      $a0, $zero, 0x1800
    /* 52DC4 800BB5C4 0F80103C */  lui        $s0, %hi(_evtFile)
    /* 52DC8 800BB5C8 8F0F010C */  jal        vs_main_allocHeapR
    /* 52DCC 800BB5CC 524C02A6 */   sh        $v0, %lo(_evtFile)($s0)
    /* 52DD0 800BB5D0 0F80033C */  lui        $v1, %hi(D_800F4C24)
    /* 52DD4 800BB5D4 524C0486 */  lh         $a0, %lo(_evtFile)($s0)
    /* 52DD8 800BB5D8 21284000 */  addu       $a1, $v0, $zero
    /* 52DDC 800BB5DC 3A00030C */  jal        func_800C00E8
    /* 52DE0 800BB5E0 244C62AC */   sw        $v0, %lo(D_800F4C24)($v1)
    /* 52DE4 800BB5E4 21100000 */  addu       $v0, $zero, $zero
    /* 52DE8 800BB5E8 0F80043C */  lui        $a0, %hi(D_800F4C54)
    /* 52DEC 800BB5EC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 52DF0 800BB5F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 52DF4 800BB5F4 01000324 */  addiu      $v1, $zero, 0x1
    /* 52DF8 800BB5F8 544C83A4 */  sh         $v1, %lo(D_800F4C54)($a0)
    /* 52DFC 800BB5FC 0800E003 */  jr         $ra
    /* 52E00 800BB600 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800BB5AC
