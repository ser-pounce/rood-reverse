nonmatching func_8007E1C0, 0x40

glabel func_8007E1C0
    /* 159C0 8007E1C0 0F80033C */  lui        $v1, %hi(D_800F18F8)
    /* 159C4 8007E1C4 F8186290 */  lbu        $v0, %lo(D_800F18F8)($v1)
    /* 159C8 8007E1C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 159CC 8007E1CC 06004410 */  beq        $v0, $a0, .L8007E1E8
    /* 159D0 8007E1D0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 159D4 8007E1D4 67000424 */  addiu      $a0, $zero, 0x67
    /* 159D8 8007E1D8 2624010C */  jal        vs_main_nop9
    /* 159DC 8007E1DC 21280000 */   addu      $a1, $zero, $zero
    /* 159E0 8007E1E0 7CF80108 */  j          .L8007E1F0
    /* 159E4 8007E1E4 21100000 */   addu      $v0, $zero, $zero
  .L8007E1E8:
    /* 159E8 8007E1E8 F81860A0 */  sb         $zero, %lo(D_800F18F8)($v1)
    /* 159EC 8007E1EC 01000224 */  addiu      $v0, $zero, 0x1
  .L8007E1F0:
    /* 159F0 8007E1F0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 159F4 8007E1F4 00000000 */  nop
    /* 159F8 8007E1F8 0800E003 */  jr         $ra
    /* 159FC 8007E1FC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007E1C0
