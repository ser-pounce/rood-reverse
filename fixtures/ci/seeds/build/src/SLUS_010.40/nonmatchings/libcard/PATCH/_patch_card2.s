nonmatching _patch_card2, 0x70

glabel _patch_card2
    /* 1F824 8002F024 0480013C */  lui        $at, %hi(D_8003FED8)
    /* 1F828 8002F028 D8FE3FAC */  sw         $ra, %lo(D_8003FED8)($at)
    /* 1F82C 8002F02C 5D9A000C */  jal        EnterCriticalSection
    /* 1F830 8002F030 00000000 */   nop
    /* 1F834 8002F034 57000924 */  addiu      $t1, $zero, 0x57
    /* 1F838 8002F038 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F83C 8002F03C 09F84001 */  jalr       $t2
    /* 1F840 8002F040 00000000 */   nop
    /* 1F844 8002F044 6C01428C */  lw         $v0, 0x16C($v0)
    /* 1F848 8002F048 00000000 */  nop
    /* 1F84C 8002F04C C809438C */  lw         $v1, 0x9C8($v0)
    /* 1F850 8002F050 03800A3C */  lui        $t2, %hi(func_8002EF68 + 0x14)
    /* 1F854 8002F054 7CEF4A25 */  addiu      $t2, $t2, %lo(func_8002EF68 + 0x14)
    /* 1F858 8002F058 0380093C */  lui        $t1, %hi(_patch_card)
    /* 1F85C 8002F05C 90EF2925 */  addiu      $t1, $t1, %lo(_patch_card)
  .L8002F060:
    /* 1F860 8002F060 0000488D */  lw         $t0, 0x0($t2)
    /* 1F864 8002F064 00000000 */  nop
    /* 1F868 8002F068 C80948AC */  sw         $t0, 0x9C8($v0)
    /* 1F86C 8002F06C 04004A25 */  addiu      $t2, $t2, 0x4
    /* 1F870 8002F070 FBFF4915 */  bne        $t2, $t1, .L8002F060
    /* 1F874 8002F074 04004224 */   addiu     $v0, $v0, 0x4
    /* 1F878 8002F078 1D9A000C */  jal        FlushCache
    /* 1F87C 8002F07C 00000000 */   nop
    /* 1F880 8002F080 04801F3C */  lui        $ra, %hi(D_8003FED8)
    /* 1F884 8002F084 D8FEFF8F */  lw         $ra, %lo(D_8003FED8)($ra)
    /* 1F888 8002F088 00000000 */  nop
    /* 1F88C 8002F08C 0800E003 */  jr         $ra
    /* 1F890 8002F090 00000000 */   nop
endlabel _patch_card2
