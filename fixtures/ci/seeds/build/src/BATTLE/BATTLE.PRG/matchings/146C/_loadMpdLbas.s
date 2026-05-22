nonmatching _loadMpdLbas, 0x5C

glabel _loadMpdLbas
    /* 204E4 80088CE4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 204E8 80088CE8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 204EC 80088CEC 21888000 */  addu       $s1, $a0, $zero
    /* 204F0 80088CF0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 204F4 80088CF4 2180A000 */  addu       $s0, $a1, $zero
    /* 204F8 80088CF8 04000016 */  bnez       $s0, .L80088D0C
    /* 204FC 80088CFC 1800BFAF */   sw        $ra, 0x18($sp)
    /* 20500 80088D00 8B000424 */  addiu      $a0, $zero, 0x8B
    /* 20504 80088D04 2624010C */  jal        vs_main_nop9
    /* 20508 80088D08 21280000 */   addu      $a1, $zero, $zero
  .L80088D0C:
    /* 2050C 80088D0C B10F010C */  jal        vs_main_allocHeap
    /* 20510 80088D10 21200002 */   addu      $a0, $s0, $zero
    /* 20514 80088D14 0F80033C */  lui        $v1, %hi(D_800F1884)
    /* 20518 80088D18 21204000 */  addu       $a0, $v0, $zero
    /* 2051C 80088D1C 21282002 */  addu       $a1, $s1, $zero
    /* 20520 80088D20 21300002 */  addu       $a2, $s0, $zero
    /* 20524 80088D24 2C24010C */  jal        vs_main_memcpy
    /* 20528 80088D28 841862AC */   sw        $v0, %lo(D_800F1884)($v1)
    /* 2052C 80088D2C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 20530 80088D30 1400B18F */  lw         $s1, 0x14($sp)
    /* 20534 80088D34 1000B08F */  lw         $s0, 0x10($sp)
    /* 20538 80088D38 0800E003 */  jr         $ra
    /* 2053C 80088D3C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel _loadMpdLbas
