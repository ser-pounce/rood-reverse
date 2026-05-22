nonmatching func_800738E4, 0x1C0

glabel func_800738E4
    /* B0E4 800738E4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* B0E8 800738E8 21200000 */  addu       $a0, $zero, $zero
    /* B0EC 800738EC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* B0F0 800738F0 6535020C */  jal        func_8008D594
    /* B0F4 800738F4 1800B0AF */   sw        $s0, 0x18($sp)
    /* B0F8 800738F8 DC56020C */  jal        func_80095B70
    /* B0FC 800738FC 21200000 */   addu      $a0, $zero, $zero
    /* B100 80073900 0F80023C */  lui        $v0, %hi(_firstPersonViewEnabled)
    /* B104 80073904 21800000 */  addu       $s0, $zero, $zero
    /* B108 80073908 10000624 */  addiu      $a2, $zero, 0x10
    /* B10C 8007390C 40000524 */  addiu      $a1, $zero, 0x40
    /* B110 80073910 6C1840AC */  sw         $zero, %lo(_firstPersonViewEnabled)($v0)
    /* B114 80073914 0F80023C */  lui        $v0, %hi(vs_battle_actors)
    /* B118 80073918 28194424 */  addiu      $a0, $v0, %lo(vs_battle_actors)
  .L8007391C:
    /* B11C 8007391C 0000838C */  lw         $v1, 0x0($a0)
    /* B120 80073920 00000000 */  nop
    /* B124 80073924 06006010 */  beqz       $v1, .L80073940
    /* B128 80073928 00000000 */   nop
    /* B12C 8007392C 08006290 */  lbu        $v0, 0x8($v1)
    /* B130 80073930 00000000 */  nop
    /* B134 80073934 02004614 */  bne        $v0, $a2, .L80073940
    /* B138 80073938 00000000 */   nop
    /* B13C 8007393C 080065A0 */  sb         $a1, 0x8($v1)
  .L80073940:
    /* B140 80073940 01001026 */  addiu      $s0, $s0, 0x1
    /* B144 80073944 1000022A */  slti       $v0, $s0, 0x10
    /* B148 80073948 F4FF4014 */  bnez       $v0, .L8007391C
    /* B14C 8007394C 04008424 */   addiu     $a0, $a0, 0x4
    /* B150 80073950 227B030C */  jal        func_800DEC88
    /* B154 80073954 21200000 */   addu      $a0, $zero, $zero
    /* B158 80073958 8E71030C */  jal        func_800DC638
    /* B15C 8007395C 01001024 */   addiu     $s0, $zero, 0x1
    /* B160 80073960 0A000424 */  addiu      $a0, $zero, 0xA
    /* B164 80073964 21280000 */  addu       $a1, $zero, $zero
    /* B168 80073968 2130A000 */  addu       $a2, $a1, $zero
    /* B16C 8007396C 16FB020C */  jal        func_800BEC58
    /* B170 80073970 2138A000 */   addu      $a3, $a1, $zero
    /* B174 80073974 00140200 */  sll        $v0, $v0, 16
    /* B178 80073978 03140200 */  sra        $v0, $v0, 16
    /* B17C 8007397C 0D005010 */  beq        $v0, $s0, .L800739B4
    /* B180 80073980 0580023C */   lui       $v0, %hi(D_80050468)
    /* B184 80073984 68044290 */  lbu        $v0, %lo(D_80050468)($v0)
    /* B188 80073988 00000000 */  nop
    /* B18C 8007398C 0D004010 */  beqz       $v0, .L800739C4
    /* B190 80073990 10000424 */   addiu     $a0, $zero, 0x10
    /* B194 80073994 21280000 */  addu       $a1, $zero, $zero
    /* B198 80073998 2130A000 */  addu       $a2, $a1, $zero
    /* B19C 8007399C 16FB020C */  jal        func_800BEC58
    /* B1A0 800739A0 2138A000 */   addu      $a3, $a1, $zero
    /* B1A4 800739A4 00140200 */  sll        $v0, $v0, 16
    /* B1A8 800739A8 03140200 */  sra        $v0, $v0, 16
    /* B1AC 800739AC 05005014 */  bne        $v0, $s0, .L800739C4
    /* B1B0 800739B0 00000000 */   nop
  .L800739B4:
    /* B1B4 800739B4 1CCE010C */  jal        func_80073870
    /* B1B8 800739B8 00000000 */   nop
    /* B1BC 800739BC A5CE0108 */  j          .L80073A94
    /* B1C0 800739C0 00000000 */   nop
  .L800739C4:
    /* B1C4 800739C4 1000A0A3 */  sb         $zero, 0x10($sp)
    /* B1C8 800739C8 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* B1CC 800739CC 647E020C */  jal        func_8009F990
    /* B1D0 800739D0 1000A527 */   addiu     $a1, $sp, 0x10
    /* B1D4 800739D4 21800000 */  addu       $s0, $zero, $zero
  .L800739D8:
    /* B1D8 800739D8 21200002 */  addu       $a0, $s0, $zero
    /* B1DC 800739DC FA75020C */  jal        func_8009D7E8
    /* B1E0 800739E0 21280000 */   addu      $a1, $zero, $zero
    /* B1E4 800739E4 21200002 */  addu       $a0, $s0, $zero
    /* B1E8 800739E8 FF81020C */  jal        func_800A07FC
    /* B1EC 800739EC 21280000 */   addu      $a1, $zero, $zero
    /* B1F0 800739F0 01001026 */  addiu      $s0, $s0, 0x1
    /* B1F4 800739F4 1000022A */  slti       $v0, $s0, 0x10
    /* B1F8 800739F8 F7FF4014 */  bnez       $v0, .L800739D8
    /* B1FC 800739FC 00000000 */   nop
    /* B200 80073A00 854E020C */  jal        func_80093A14
    /* B204 80073A04 00000000 */   nop
    /* B208 80073A08 00100424 */  addiu      $a0, $zero, 0x1000
    /* B20C 80073A0C 45F3010C */  jal        vs_battle_setFarClip
    /* B210 80073A10 01000524 */   addiu     $a1, $zero, 0x1
    /* B214 80073A14 25EB010C */  jal        func_8007AC94
    /* B218 80073A18 21200000 */   addu      $a0, $zero, $zero
    /* B21C 80073A1C 63EF010C */  jal        func_8007BD8C
    /* B220 80073A20 21200000 */   addu      $a0, $zero, $zero
    /* B224 80073A24 0680023C */  lui        $v0, %hi(vs_main_soundData)
    /* B228 80073A28 38E04524 */  addiu      $a1, $v0, %lo(vs_main_soundData)
    /* B22C 80073A2C 0400A38C */  lw         $v1, 0x4($a1)
    /* B230 80073A30 FFFF0234 */  ori        $v0, $zero, 0xFFFF
    /* B234 80073A34 09006214 */  bne        $v1, $v0, .L80073A5C
    /* B238 80073A38 0F80023C */   lui       $v0, %hi(D_800F18AC)
    /* B23C 80073A3C AC18448C */  lw         $a0, %lo(D_800F18AC)($v0)
    /* B240 80073A40 00000000 */  nop
    /* B244 80073A44 11008010 */  beqz       $a0, .L80073A8C
    /* B248 80073A48 7F000524 */   addiu     $a1, $zero, 0x7F
    /* B24C 80073A4C 0014010C */  jal        func_80045000
    /* B250 80073A50 21300000 */   addu      $a2, $zero, $zero
    /* B254 80073A54 A3CE0108 */  j          .L80073A8C
    /* B258 80073A58 00000000 */   nop
  .L80073A5C:
    /* B25C 80073A5C AC18448C */  lw         $a0, %lo(D_800F18AC)($v0)
    /* B260 80073A60 00000000 */  nop
    /* B264 80073A64 09008010 */  beqz       $a0, .L80073A8C
    /* B268 80073A68 FFFF8224 */   addiu     $v0, $a0, -0x1
    /* B26C 80073A6C 80100200 */  sll        $v0, $v0, 2
    /* B270 80073A70 21104500 */  addu       $v0, $v0, $a1
    /* B274 80073A74 1400428C */  lw         $v0, 0x14($v0)
    /* B278 80073A78 00000000 */  nop
    /* B27C 80073A7C 03006214 */  bne        $v1, $v0, .L80073A8C
    /* B280 80073A80 7F000524 */   addiu     $a1, $zero, 0x7F
    /* B284 80073A84 4B15010C */  jal        func_8004552C
    /* B288 80073A88 3C000624 */   addiu     $a2, $zero, 0x3C
  .L80073A8C:
    /* B28C 80073A8C 73BD010C */  jal        func_8006F5CC
    /* B290 80073A90 00000000 */   nop
  .L80073A94:
    /* B294 80073A94 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* B298 80073A98 1800B08F */  lw         $s0, 0x18($sp)
    /* B29C 80073A9C 0800E003 */  jr         $ra
    /* B2A0 80073AA0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800738E4
