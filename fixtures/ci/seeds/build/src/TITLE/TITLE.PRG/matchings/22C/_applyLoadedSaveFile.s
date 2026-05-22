nonmatching _applyLoadedSaveFile, 0x1B8

glabel _applyLoadedSaveFile
    /* ED0 800696D0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* ED4 800696D4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* ED8 800696D8 21988000 */  addu       $s3, $a0, $zero
    /* EDC 800696DC 0E80023C */  lui        $v0, %hi(_spmcimg)
    /* EE0 800696E0 1400B1AF */  sw         $s1, 0x14($sp)
    /* EE4 800696E4 B8EA518C */  lw         $s1, %lo(_spmcimg)($v0)
    /* EE8 800696E8 7C5A0624 */  addiu      $a2, $zero, 0x5A7C
    /* EEC 800696EC 2400BFAF */  sw         $ra, 0x24($sp)
    /* EF0 800696F0 2000B4AF */  sw         $s4, 0x20($sp)
    /* EF4 800696F4 1800B2AF */  sw         $s2, 0x18($sp)
    /* EF8 800696F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* EFC 800696FC 805D248E */  lw         $a0, 0x5D80($s1)
    /* F00 80069700 D7A3010C */  jal        _decode
    /* F04 80069704 845D2526 */   addiu     $a1, $s1, 0x5D84
    /* F08 80069708 5C000524 */  addiu      $a1, $zero, 0x5C
    /* F0C 8006970C 005C3026 */  addiu      $s0, $s1, 0x5C00
    /* F10 80069710 21A00002 */  addu       $s4, $s0, $zero
    /* F14 80069714 02006012 */  beqz       $s3, .L80069720
    /* F18 80069718 805D3226 */   addiu     $s2, $s1, 0x5D80
    /* F1C 8006971C 20000524 */  addiu      $a1, $zero, 0x20
  .L80069720:
    /* F20 80069720 B2A3010C */  jal        _verifySaveChecksums
    /* F24 80069724 21200002 */   addu      $a0, $s0, $zero
    /* F28 80069728 4F004014 */  bnez       $v0, .L80069868
    /* F2C 8006972C 01000224 */   addiu     $v0, $zero, 0x1
    /* F30 80069730 0020033C */  lui        $v1, (0x20000107 >> 16)
    /* F34 80069734 0C00428E */  lw         $v0, 0xC($s2)
    /* F38 80069738 07016334 */  ori        $v1, $v1, (0x20000107 & 0xFFFF)
    /* F3C 8006973C 4A004314 */  bne        $v0, $v1, .L80069868
    /* F40 80069740 01000224 */   addiu     $v0, $zero, 0x1
    /* F44 80069744 47006012 */  beqz       $s3, .L80069864
    /* F48 80069748 0680043C */   lui       $a0, %hi(vs_main_stateFlags)
    /* F4C 8006974C 98158424 */  addiu      $a0, $a0, %lo(vs_main_stateFlags)
    /* F50 80069750 005E2526 */  addiu      $a1, $s1, 0x5E00
    /* F54 80069754 0FA3010C */  jal        _rMemcpy
    /* F58 80069758 40040624 */   addiu     $a2, $zero, 0x440
    /* F5C 8006975C 0680043C */  lui        $a0, %hi(vs_main_skillsLearned)
    /* F60 80069760 B8FF8424 */  addiu      $a0, $a0, %lo(vs_main_skillsLearned)
    /* F64 80069764 40622526 */  addiu      $a1, $s1, 0x6240
    /* F68 80069768 0FA3010C */  jal        _rMemcpy
    /* F6C 8006976C 20000624 */   addiu     $a2, $zero, 0x20
    /* F70 80069770 0680043C */  lui        $a0, %hi(vs_main_mapStatus)
    /* F74 80069774 D8FF8424 */  addiu      $a0, $a0, %lo(vs_main_mapStatus)
    /* F78 80069778 60622526 */  addiu      $a1, $s1, 0x6260
    /* F7C 8006977C 0FA3010C */  jal        _rMemcpy
    /* F80 80069780 48000624 */   addiu     $a2, $zero, 0x48
    /* F84 80069784 0680103C */  lui        $s0, %hi(vs_main_settings)
    /* F88 80069788 20001026 */  addiu      $s0, $s0, %lo(vs_main_settings)
    /* F8C 8006978C 21200002 */  addu       $a0, $s0, $zero
    /* F90 80069790 A8622526 */  addiu      $a1, $s1, 0x62A8
    /* F94 80069794 0FA3010C */  jal        _rMemcpy
    /* F98 80069798 20000624 */   addiu     $a2, $zero, 0x20
    /* F9C 8006979C 0680043C */  lui        $a0, %hi(D_80060068)
    /* FA0 800697A0 68008424 */  addiu      $a0, $a0, %lo(D_80060068)
    /* FA4 800697A4 C8622526 */  addiu      $a1, $s1, 0x62C8
    /* FA8 800697A8 0FA3010C */  jal        _rMemcpy
    /* FAC 800697AC 00010624 */   addiu     $a2, $zero, 0x100
    /* FB0 800697B0 0680043C */  lui        $a0, %hi(vs_battle_inventory)
    /* FB4 800697B4 68018424 */  addiu      $a0, $a0, %lo(vs_battle_inventory)
    /* FB8 800697B8 C8632526 */  addiu      $a1, $s1, 0x63C8
    /* FBC 800697BC 0FA3010C */  jal        _rMemcpy
    /* FC0 800697C0 000F0624 */   addiu     $a2, $zero, 0xF00
    /* FC4 800697C4 0680043C */  lui        $a0, %hi(vs_main_inventoryIndices)
    /* FC8 800697C8 D8198424 */  addiu      $a0, $a0, %lo(vs_main_inventoryIndices)
    /* FCC 800697CC C8722526 */  addiu      $a1, $s1, 0x72C8
    /* FD0 800697D0 0FA3010C */  jal        _rMemcpy
    /* FD4 800697D4 B0000624 */   addiu     $a2, $zero, 0xB0
    /* FD8 800697D8 0680043C */  lui        $a0, %hi(D_80061068)
    /* FDC 800697DC 68108424 */  addiu      $a0, $a0, %lo(D_80061068)
    /* FE0 800697E0 78732526 */  addiu      $a1, $s1, 0x7378
    /* FE4 800697E4 0FA3010C */  jal        _rMemcpy
    /* FE8 800697E8 0C000624 */   addiu     $a2, $zero, 0xC
    /* FEC 800697EC 0680043C */  lui        $a0, %hi(vs_main_scoredata)
    /* FF0 800697F0 A0FE8424 */  addiu      $a0, $a0, %lo(vs_main_scoredata)
    /* FF4 800697F4 84732526 */  addiu      $a1, $s1, 0x7384
    /* FF8 800697F8 0FA3010C */  jal        _rMemcpy
    /* FFC 800697FC 14010624 */   addiu     $a2, $zero, 0x114
    /* 1000 80069800 0680043C */  lui        $a0, %hi(D_80061078)
    /* 1004 80069804 78108424 */  addiu      $a0, $a0, %lo(D_80061078)
    /* 1008 80069808 9C742526 */  addiu      $a1, $s1, 0x749C
    /* 100C 8006980C 20050624 */  addiu      $a2, $zero, 0x520
    /* 1010 80069810 9818838E */  lw         $v1, 0x1898($s4)
    /* 1014 80069814 0680023C */  lui        $v0, %hi(D_80060064)
    /* 1018 80069818 0FA3010C */  jal        _rMemcpy
    /* 101C 8006981C 640043AC */   sw        $v1, %lo(D_80060064)($v0)
    /* 1020 80069820 0680043C */  lui        $a0, %hi(vs_main_artsStatus)
    /* 1024 80069824 40008424 */  addiu      $a0, $a0, %lo(vs_main_artsStatus)
    /* 1028 80069828 BC792526 */  addiu      $a1, $s1, 0x79BC
    /* 102C 8006982C 0FA3010C */  jal        _rMemcpy
    /* 1030 80069830 24000624 */   addiu     $a2, $zero, 0x24
    /* 1034 80069834 0680023C */  lui        $v0, %hi(vs_main_gametime)
    /* 1038 80069838 74104A24 */  addiu      $t2, $v0, %lo(vs_main_gametime)
    /* 103C 8006983C 935D278A */  lwl        $a3, 0x5D93($s1)
    /* 1040 80069840 905D279A */  lwr        $a3, 0x5D90($s1)
    /* 1044 80069844 00000000 */  nop
    /* 1048 80069848 030047A9 */  swl        $a3, 0x3($t2)
    /* 104C 8006984C 000047B9 */  swr        $a3, 0x0($t2)
    /* 1050 80069850 280B010C */  jal        func_80042CA0
    /* 1054 80069854 00000000 */   nop
    /* 1058 80069858 0A000492 */  lbu        $a0, 0xA($s0)
    /* 105C 8006985C 2F1A010C */  jal        vs_main_setMonoSound
    /* 1060 80069860 00000000 */   nop
  .L80069864:
    /* 1064 80069864 21100000 */  addu       $v0, $zero, $zero
  .L80069868:
    /* 1068 80069868 2400BF8F */  lw         $ra, 0x24($sp)
    /* 106C 8006986C 2000B48F */  lw         $s4, 0x20($sp)
    /* 1070 80069870 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1074 80069874 1800B28F */  lw         $s2, 0x18($sp)
    /* 1078 80069878 1400B18F */  lw         $s1, 0x14($sp)
    /* 107C 8006987C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1080 80069880 0800E003 */  jr         $ra
    /* 1084 80069884 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel _applyLoadedSaveFile
