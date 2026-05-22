nonmatching _ExitCard, 0x70

glabel _ExitCard
    /* 1F8D4 8002F0D4 0480013C */  lui        $at, %hi(D_8003FEE8)
    /* 1F8D8 8002F0D8 E8FE3FAC */  sw         $ra, %lo(D_8003FEE8)($at)
    /* 1F8DC 8002F0DC 5D9A000C */  jal        EnterCriticalSection
    /* 1F8E0 8002F0E0 00000000 */   nop
    /* 1F8E4 8002F0E4 56000924 */  addiu      $t1, $zero, 0x56
    /* 1F8E8 8002F0E8 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 1F8EC 8002F0EC 09F84001 */  jalr       $t2
    /* 1F8F0 8002F0F0 00000000 */   nop
    /* 1F8F4 8002F0F4 1800428C */  lw         $v0, 0x18($v0)
    /* 1F8F8 8002F0F8 03800A3C */  lui        $t2, %hi(D_8002F144)
    /* 1F8FC 8002F0FC 44F14A25 */  addiu      $t2, $t2, %lo(D_8002F144)
    /* 1F900 8002F100 0380093C */  lui        $t1, %hi(D_8002F150)
    /* 1F904 8002F104 50F12925 */  addiu      $t1, $t1, %lo(D_8002F150)
  .L8002F108:
    /* 1F908 8002F108 0000438D */  lw         $v1, 0x0($t2)
    /* 1F90C 8002F10C 00000000 */  nop
    /* 1F910 8002F110 700043AC */  sw         $v1, 0x70($v0)
    /* 1F914 8002F114 04004A25 */  addiu      $t2, $t2, 0x4
    /* 1F918 8002F118 FBFF4915 */  bne        $t2, $t1, .L8002F108
    /* 1F91C 8002F11C 04004224 */   addiu     $v0, $v0, 0x4
    /* 1F920 8002F120 1D9A000C */  jal        FlushCache
    /* 1F924 8002F124 00000000 */   nop
    /* 1F928 8002F128 619A000C */  jal        ExitCriticalSection
    /* 1F92C 8002F12C 00000000 */   nop
    /* 1F930 8002F130 04801F3C */  lui        $ra, %hi(D_8003FEE8)
    /* 1F934 8002F134 E8FEFF8F */  lw         $ra, %lo(D_8003FEE8)($ra)
    /* 1F938 8002F138 00000000 */  nop
    /* 1F93C 8002F13C 0800E003 */  jr         $ra
    /* 1F940 8002F140 00000000 */   nop
endlabel _ExitCard
  alabel D_8002F144
    /* 1F944 8002F144 00000000 */  nop
    /* 1F948 8002F148 00000000 */  nop
    /* 1F94C 8002F14C 00000000 */  nop
  alabel D_8002F150
    /* 1F950 8002F150 00000000 */  nop
