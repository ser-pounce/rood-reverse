nonmatching func_800BC1CC, 0x11C

glabel func_800BC1CC
    /* 539CC 800BC1CC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 539D0 800BC1D0 21308000 */  addu       $a2, $a0, $zero
    /* 539D4 800BC1D4 0F80033C */  lui        $v1, %hi(D_800F4BA0)
    /* 539D8 800BC1D8 A04B6290 */  lbu        $v0, %lo(D_800F4BA0)($v1)
    /* 539DC 800BC1DC 2138A000 */  addu       $a3, $a1, $zero
    /* 539E0 800BC1E0 3800BFAF */  sw         $ra, 0x38($sp)
    /* 539E4 800BC1E4 3400B1AF */  sw         $s1, 0x34($sp)
    /* 539E8 800BC1E8 03004010 */  beqz       $v0, .L800BC1F8
    /* 539EC 800BC1EC 3000B0AF */   sw        $s0, 0x30($sp)
    /* 539F0 800BC1F0 B5F00208 */  j          .L800BC2D4
    /* 539F4 800BC1F4 A04B60A0 */   sb        $zero, %lo(D_800F4BA0)($v1)
  .L800BC1F8:
    /* 539F8 800BC1F8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 539FC 800BC1FC 2000B127 */  addiu      $s1, $sp, 0x20
    /* 53A00 800BC200 21282002 */  addu       $a1, $s1, $zero
    /* 53A04 800BC204 00340600 */  sll        $a2, $a2, 16
    /* 53A08 800BC208 03340600 */  sra        $a2, $a2, 16
    /* 53A0C 800BC20C 003C0700 */  sll        $a3, $a3, 16
    /* 53A10 800BC210 5CF3010C */  jal        vs_battle_initialiseCameraFromSpherical
    /* 53A14 800BC214 033C0700 */   sra       $a3, $a3, 16
    /* 53A18 800BC218 0F80103C */  lui        $s0, %hi(D_800F4BA4)
    /* 53A1C 800BC21C A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 53A20 800BC220 1000A527 */  addiu      $a1, $sp, 0x10
    /* 53A24 800BC224 C7F9020C */  jal        _copyVector
    /* 53A28 800BC228 D8008424 */   addiu     $a0, $a0, 0xD8
    /* 53A2C 800BC22C A44B048E */  lw         $a0, %lo(D_800F4BA4)($s0)
    /* 53A30 800BC230 21282002 */  addu       $a1, $s1, $zero
    /* 53A34 800BC234 C7F9020C */  jal        _copyVector
    /* 53A38 800BC238 24008424 */   addiu     $a0, $a0, 0x24
    /* 53A3C 800BC23C 801F043C */  lui        $a0, (0x1F800098 >> 16)
    /* 53A40 800BC240 A44B068E */  lw         $a2, %lo(D_800F4BA4)($s0)
    /* 53A44 800BC244 98008434 */  ori        $a0, $a0, (0x1F800098 & 0xFFFF)
    /* 53A48 800BC248 4801C524 */  addiu      $a1, $a2, 0x148
    /* 53A4C 800BC24C 9BF9020C */  jal        _vectorSubtract
    /* 53A50 800BC250 D800C624 */   addiu     $a2, $a2, 0xD8
    /* 53A54 800BC254 D0F9020C */  jal        _vectorMagnitude
    /* 53A58 800BC258 21204000 */   addu      $a0, $v0, $zero
    /* 53A5C 800BC25C 801F043C */  lui        $a0, (0x1F800098 >> 16)
    /* 53A60 800BC260 98008434 */  ori        $a0, $a0, (0x1F800098 & 0xFFFF)
    /* 53A64 800BC264 A44B068E */  lw         $a2, %lo(D_800F4BA4)($s0)
    /* 53A68 800BC268 21804000 */  addu       $s0, $v0, $zero
    /* 53A6C 800BC26C 9400C524 */  addiu      $a1, $a2, 0x94
    /* 53A70 800BC270 9BF9020C */  jal        _vectorSubtract
    /* 53A74 800BC274 2400C624 */   addiu     $a2, $a2, 0x24
    /* 53A78 800BC278 D0F9020C */  jal        _vectorMagnitude
    /* 53A7C 800BC27C 21204000 */   addu      $a0, $v0, $zero
    /* 53A80 800BC280 6666033C */  lui        $v1, (0x66666667 >> 16)
    /* 53A84 800BC284 67666334 */  ori        $v1, $v1, (0x66666667 & 0xFFFF)
    /* 53A88 800BC288 21800202 */  addu       $s0, $s0, $v0
    /* 53A8C 800BC28C 18000302 */  mult       $s0, $v1
    /* 53A90 800BC290 C3871000 */  sra        $s0, $s0, 31
    /* 53A94 800BC294 10400000 */  mfhi       $t0
    /* 53A98 800BC298 03140800 */  sra        $v0, $t0, 16
    /* 53A9C 800BC29C 23105000 */  subu       $v0, $v0, $s0
    /* 53AA0 800BC2A0 21184000 */  addu       $v1, $v0, $zero
    /* 53AA4 800BC2A4 00140200 */  sll        $v0, $v0, 16
    /* 53AA8 800BC2A8 0A004010 */  beqz       $v0, .L800BC2D4
    /* 53AAC 800BC2AC 0F80103C */   lui       $s0, %hi(D_800E9C1C)
    /* 53AB0 800BC2B0 1C9C1026 */  addiu      $s0, $s0, %lo(D_800E9C1C)
    /* 53AB4 800BC2B4 21200002 */  addu       $a0, $s0, $zero
    /* 53AB8 800BC2B8 21280000 */  addu       $a1, $zero, $zero
    /* 53ABC 800BC2BC 060003A2 */  sb         $v1, 0x6($s0)
    /* 53AC0 800BC2C0 BAF0020C */  jal        func_800BC2E8
    /* 53AC4 800BC2C4 020003A2 */   sb        $v1, 0x2($s0)
    /* 53AC8 800BC2C8 03000426 */  addiu      $a0, $s0, 0x3
    /* 53ACC 800BC2CC BAF0020C */  jal        func_800BC2E8
    /* 53AD0 800BC2D0 21280000 */   addu      $a1, $zero, $zero
  .L800BC2D4:
    /* 53AD4 800BC2D4 3800BF8F */  lw         $ra, 0x38($sp)
    /* 53AD8 800BC2D8 3400B18F */  lw         $s1, 0x34($sp)
    /* 53ADC 800BC2DC 3000B08F */  lw         $s0, 0x30($sp)
    /* 53AE0 800BC2E0 0800E003 */  jr         $ra
    /* 53AE4 800BC2E4 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_800BC1CC
