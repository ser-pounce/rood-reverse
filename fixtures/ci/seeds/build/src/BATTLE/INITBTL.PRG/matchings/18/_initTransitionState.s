nonmatching _initTransitionState, 0x270

glabel _initTransitionState
    /* 8EC 800FA0EC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 8F0 800FA0F0 1800A427 */  addiu      $a0, $sp, 0x18
    /* 8F4 800FA0F4 21280000 */  addu       $a1, $zero, $zero
    /* 8F8 800FA0F8 08000624 */  addiu      $a2, $zero, 0x8
    /* 8FC 800FA0FC 3000BFAF */  sw         $ra, 0x30($sp)
    /* 900 800FA100 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 904 800FA104 2800B2AF */  sw         $s2, 0x28($sp)
    /* 908 800FA108 2400B1AF */  sw         $s1, 0x24($sp)
    /* 90C 800FA10C AD9B000C */  jal        memset
    /* 910 800FA110 2000B0AF */   sw        $s0, 0x20($sp)
    /* 914 800FA114 0F80133C */  lui        $s3, %hi(vs_battle_screenTransitionPolyF4)
    /* 918 800FA118 681B7126 */  addiu      $s1, $s3, %lo(vs_battle_screenTransitionPolyF4)
    /* 91C 800FA11C 69AD000C */  jal        SetPolyF4
    /* 920 800FA120 21202002 */   addu      $a0, $s1, $zero
    /* 924 800FA124 21202002 */  addu       $a0, $s1, $zero
    /* 928 800FA128 01000524 */  addiu      $a1, $zero, 0x1
    /* 92C 800FA12C 40010324 */  addiu      $v1, $zero, 0x140
    /* 930 800FA130 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 934 800FA134 040020A2 */  sb         $zero, 0x4($s1)
    /* 938 800FA138 050020A2 */  sb         $zero, 0x5($s1)
    /* 93C 800FA13C 060020A2 */  sb         $zero, 0x6($s1)
    /* 940 800FA140 080020A6 */  sh         $zero, 0x8($s1)
    /* 944 800FA144 0A0020A6 */  sh         $zero, 0xA($s1)
    /* 948 800FA148 0C0023A6 */  sh         $v1, 0xC($s1)
    /* 94C 800FA14C 0E0020A6 */  sh         $zero, 0xE($s1)
    /* 950 800FA150 100020A6 */  sh         $zero, 0x10($s1)
    /* 954 800FA154 120022A6 */  sh         $v0, 0x12($s1)
    /* 958 800FA158 140023A6 */  sh         $v1, 0x14($s1)
    /* 95C 800FA15C 5DAD000C */  jal        SetSemiTrans
    /* 960 800FA160 160022A6 */   sh        $v0, 0x16($s1)
    /* 964 800FA164 0F80123C */  lui        $s2, %hi(vs_battle_screenTransitionWipePolyF4)
    /* 968 800FA168 C01A5026 */  addiu      $s0, $s2, %lo(vs_battle_screenTransitionWipePolyF4)
    /* 96C 800FA16C 681B6B26 */  addiu      $t3, $s3, %lo(vs_battle_screenTransitionPolyF4)
    /* 970 800FA170 0000688D */  lw         $t0, 0x0($t3)
    /* 974 800FA174 0400698D */  lw         $t1, 0x4($t3)
    /* 978 800FA178 08006A8D */  lw         $t2, 0x8($t3)
    /* 97C 800FA17C 180028AE */  sw         $t0, 0x18($s1)
    /* 980 800FA180 1C0029AE */  sw         $t1, 0x1C($s1)
    /* 984 800FA184 20002AAE */  sw         $t2, 0x20($s1)
    /* 988 800FA188 0C00688D */  lw         $t0, 0xC($t3)
    /* 98C 800FA18C 1000698D */  lw         $t1, 0x10($t3)
    /* 990 800FA190 14006A8D */  lw         $t2, 0x14($t3)
    /* 994 800FA194 240028AE */  sw         $t0, 0x24($s1)
    /* 998 800FA198 280029AE */  sw         $t1, 0x28($s1)
    /* 99C 800FA19C 2C002AAE */  sw         $t2, 0x2C($s1)
    /* 9A0 800FA1A0 69AD000C */  jal        SetPolyF4
    /* 9A4 800FA1A4 21200002 */   addu      $a0, $s0, $zero
    /* 9A8 800FA1A8 21200002 */  addu       $a0, $s0, $zero
    /* 9AC 800FA1AC 21280000 */  addu       $a1, $zero, $zero
    /* 9B0 800FA1B0 040000A2 */  sb         $zero, 0x4($s0)
    /* 9B4 800FA1B4 050000A2 */  sb         $zero, 0x5($s0)
    /* 9B8 800FA1B8 5DAD000C */  jal        SetSemiTrans
    /* 9BC 800FA1BC 060000A2 */   sb        $zero, 0x6($s0)
    /* 9C0 800FA1C0 30000326 */  addiu      $v1, $s0, 0x30
    /* 9C4 800FA1C4 21206000 */  addu       $a0, $v1, $zero
    /* 9C8 800FA1C8 01000224 */  addiu      $v0, $zero, 0x1
    /* 9CC 800FA1CC 040000A2 */  sb         $zero, 0x4($s0)
    /* 9D0 800FA1D0 050000A2 */  sb         $zero, 0x5($s0)
    /* 9D4 800FA1D4 060002A2 */  sb         $v0, 0x6($s0)
    /* 9D8 800FA1D8 C01A4B26 */  addiu      $t3, $s2, %lo(vs_battle_screenTransitionWipePolyF4)
    /* 9DC 800FA1DC 0000688D */  lw         $t0, 0x0($t3)
    /* 9E0 800FA1E0 0400698D */  lw         $t1, 0x4($t3)
    /* 9E4 800FA1E4 08006A8D */  lw         $t2, 0x8($t3)
    /* 9E8 800FA1E8 180008AE */  sw         $t0, 0x18($s0)
    /* 9EC 800FA1EC 1C0009AE */  sw         $t1, 0x1C($s0)
    /* 9F0 800FA1F0 20000AAE */  sw         $t2, 0x20($s0)
    /* 9F4 800FA1F4 0C00688D */  lw         $t0, 0xC($t3)
    /* 9F8 800FA1F8 1000698D */  lw         $t1, 0x10($t3)
    /* 9FC 800FA1FC 14006A8D */  lw         $t2, 0x14($t3)
    /* A00 800FA200 240008AE */  sw         $t0, 0x24($s0)
    /* A04 800FA204 280009AE */  sw         $t1, 0x28($s0)
    /* A08 800FA208 2C000AAE */  sw         $t2, 0x2C($s0)
  .L800FA20C:
    /* A0C 800FA20C 0000088E */  lw         $t0, 0x0($s0)
    /* A10 800FA210 0400098E */  lw         $t1, 0x4($s0)
    /* A14 800FA214 08000A8E */  lw         $t2, 0x8($s0)
    /* A18 800FA218 0C000B8E */  lw         $t3, 0xC($s0)
    /* A1C 800FA21C 000068AC */  sw         $t0, 0x0($v1)
    /* A20 800FA220 040069AC */  sw         $t1, 0x4($v1)
    /* A24 800FA224 08006AAC */  sw         $t2, 0x8($v1)
    /* A28 800FA228 0C006BAC */  sw         $t3, 0xC($v1)
    /* A2C 800FA22C 10001026 */  addiu      $s0, $s0, 0x10
    /* A30 800FA230 F6FF0416 */  bne        $s0, $a0, .L800FA20C
    /* A34 800FA234 10006324 */   addiu     $v1, $v1, 0x10
    /* A38 800FA238 0F80103C */  lui        $s0, %hi(vs_battle_screenTransitionEdgePolyG4)
    /* A3C 800FA23C 201B1026 */  addiu      $s0, $s0, %lo(vs_battle_screenTransitionEdgePolyG4)
    /* A40 800FA240 79AD000C */  jal        SetPolyG4
    /* A44 800FA244 21200002 */   addu      $a0, $s0, $zero
    /* A48 800FA248 21200002 */  addu       $a0, $s0, $zero
    /* A4C 800FA24C 01000524 */  addiu      $a1, $zero, 0x1
    /* A50 800FA250 FF000224 */  addiu      $v0, $zero, 0xFF
    /* A54 800FA254 40010324 */  addiu      $v1, $zero, 0x140
    /* A58 800FA258 040002A2 */  sb         $v0, 0x4($s0)
    /* A5C 800FA25C 050002A2 */  sb         $v0, 0x5($s0)
    /* A60 800FA260 060002A2 */  sb         $v0, 0x6($s0)
    /* A64 800FA264 140002A2 */  sb         $v0, 0x14($s0)
    /* A68 800FA268 150002A2 */  sb         $v0, 0x15($s0)
    /* A6C 800FA26C 160002A2 */  sb         $v0, 0x16($s0)
    /* A70 800FA270 F0000224 */  addiu      $v0, $zero, 0xF0
    /* A74 800FA274 0C0000A2 */  sb         $zero, 0xC($s0)
    /* A78 800FA278 0D0000A2 */  sb         $zero, 0xD($s0)
    /* A7C 800FA27C 0E0000A2 */  sb         $zero, 0xE($s0)
    /* A80 800FA280 1C0000A2 */  sb         $zero, 0x1C($s0)
    /* A84 800FA284 1D0000A2 */  sb         $zero, 0x1D($s0)
    /* A88 800FA288 1E0000A2 */  sb         $zero, 0x1E($s0)
    /* A8C 800FA28C 080000A6 */  sh         $zero, 0x8($s0)
    /* A90 800FA290 0A0000A6 */  sh         $zero, 0xA($s0)
    /* A94 800FA294 100003A6 */  sh         $v1, 0x10($s0)
    /* A98 800FA298 120000A6 */  sh         $zero, 0x12($s0)
    /* A9C 800FA29C 180000A6 */  sh         $zero, 0x18($s0)
    /* AA0 800FA2A0 1A0002A6 */  sh         $v0, 0x1A($s0)
    /* AA4 800FA2A4 200003A6 */  sh         $v1, 0x20($s0)
    /* AA8 800FA2A8 5DAD000C */  jal        SetSemiTrans
    /* AAC 800FA2AC 220002A6 */   sh        $v0, 0x22($s0)
    /* AB0 800FA2B0 24000326 */  addiu      $v1, $s0, 0x24
    /* AB4 800FA2B4 21100002 */  addu       $v0, $s0, $zero
    /* AB8 800FA2B8 20004424 */  addiu      $a0, $v0, 0x20
  .L800FA2BC:
    /* ABC 800FA2BC 0000488C */  lw         $t0, 0x0($v0)
    /* AC0 800FA2C0 0400498C */  lw         $t1, 0x4($v0)
    /* AC4 800FA2C4 08004A8C */  lw         $t2, 0x8($v0)
    /* AC8 800FA2C8 0C004B8C */  lw         $t3, 0xC($v0)
    /* ACC 800FA2CC 000068AC */  sw         $t0, 0x0($v1)
    /* AD0 800FA2D0 040069AC */  sw         $t1, 0x4($v1)
    /* AD4 800FA2D4 08006AAC */  sw         $t2, 0x8($v1)
    /* AD8 800FA2D8 0C006BAC */  sw         $t3, 0xC($v1)
    /* ADC 800FA2DC 10004224 */  addiu      $v0, $v0, 0x10
    /* AE0 800FA2E0 F6FF4414 */  bne        $v0, $a0, .L800FA2BC
    /* AE4 800FA2E4 10006324 */   addiu     $v1, $v1, 0x10
    /* AE8 800FA2E8 0F80113C */  lui        $s1, %hi(vs_battle_screenTransitionDrMode)
    /* AEC 800FA2EC 801A3026 */  addiu      $s0, $s1, %lo(vs_battle_screenTransitionDrMode)
    /* AF0 800FA2F0 21200002 */  addu       $a0, $s0, $zero
    /* AF4 800FA2F4 21280000 */  addu       $a1, $zero, $zero
    /* AF8 800FA2F8 01000624 */  addiu      $a2, $zero, 0x1
    /* AFC 800FA2FC 0000488C */  lw         $t0, 0x0($v0)
    /* B00 800FA300 00000000 */  nop
    /* B04 800FA304 000068AC */  sw         $t0, 0x0($v1)
    /* B08 800FA308 1800A227 */  addiu      $v0, $sp, 0x18
    /* B0C 800FA30C 40000724 */  addiu      $a3, $zero, 0x40
    /* B10 800FA310 D1AD000C */  jal        SetDrawMode
    /* B14 800FA314 1000A2AF */   sw        $v0, 0x10($sp)
    /* B18 800FA318 0F80033C */  lui        $v1, %hi(vs_battle_screenTransitionAlpha)
    /* B1C 800FA31C 801A2B26 */  addiu      $t3, $s1, %lo(vs_battle_screenTransitionDrMode)
    /* B20 800FA320 0000688D */  lw         $t0, 0x0($t3)
    /* B24 800FA324 0400698D */  lw         $t1, 0x4($t3)
    /* B28 800FA328 08006A8D */  lw         $t2, 0x8($t3)
    /* B2C 800FA32C 0C0008AE */  sw         $t0, 0xC($s0)
    /* B30 800FA330 100009AE */  sw         $t1, 0x10($s0)
    /* B34 800FA334 14000AAE */  sw         $t2, 0x14($s0)
    /* B38 800FA338 3000BF8F */  lw         $ra, 0x30($sp)
    /* B3C 800FA33C 2C00B38F */  lw         $s3, 0x2C($sp)
    /* B40 800FA340 2800B28F */  lw         $s2, 0x28($sp)
    /* B44 800FA344 2400B18F */  lw         $s1, 0x24($sp)
    /* B48 800FA348 2000B08F */  lw         $s0, 0x20($sp)
    /* B4C 800FA34C FF000224 */  addiu      $v0, $zero, 0xFF
    /* B50 800FA350 A01A62AC */  sw         $v0, %lo(vs_battle_screenTransitionAlpha)($v1)
    /* B54 800FA354 0800E003 */  jr         $ra
    /* B58 800FA358 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _initTransitionState
