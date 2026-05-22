nonmatching vs_mainMenu_initSortUi, 0x25C

glabel vs_mainMenu_initSortUi
    /* 58EC 800FF0EC C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 58F0 800FF0F0 2400B5AF */  sw         $s5, 0x24($sp)
    /* 58F4 800FF0F4 21A88000 */  addu       $s5, $a0, $zero
    /* 58F8 800FF0F8 1800B2AF */  sw         $s2, 0x18($sp)
    /* 58FC 800FF0FC 2190C000 */  addu       $s2, $a2, $zero
    /* 5900 800FF100 2000B4AF */  sw         $s4, 0x20($sp)
    /* 5904 800FF104 21A0E000 */  addu       $s4, $a3, $zero
    /* 5908 800FF108 1400B1AF */  sw         $s1, 0x14($sp)
    /* 590C 800FF10C 21880000 */  addu       $s1, $zero, $zero
    /* 5910 800FF110 21302002 */  addu       $a2, $s1, $zero
    /* 5914 800FF114 1080043C */  lui        $a0, %hi(D_801024A0)
    /* 5918 800FF118 03121500 */  sra        $v0, $s5, 8
    /* 591C 800FF11C FF00B532 */  andi       $s5, $s5, 0xFF
    /* 5920 800FF120 A02482A0 */  sb         $v0, %lo(D_801024A0)($a0)
    /* 5924 800FF124 FF004230 */  andi       $v0, $v0, 0xFF
    /* 5928 800FF128 3000BFAF */  sw         $ra, 0x30($sp)
    /* 592C 800FF12C 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 5930 800FF130 2800B6AF */  sw         $s6, 0x28($sp)
    /* 5934 800FF134 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5938 800FF138 08004014 */  bnez       $v0, .L800FF15C
    /* 593C 800FF13C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 5940 800FF140 0700A22A */  slti       $v0, $s5, 0x7
    /* 5944 800FF144 03004010 */  beqz       $v0, .L800FF154
    /* 5948 800FF148 0A000224 */   addiu     $v0, $zero, 0xA
    /* 594C 800FF14C 56FC0308 */  j          .L800FF158
    /* 5950 800FF150 23105500 */   subu      $v0, $v0, $s5
  .L800FF154:
    /* 5954 800FF154 03000224 */  addiu      $v0, $zero, 0x3
  .L800FF158:
    /* 5958 800FF158 A02482A0 */  sb         $v0, %lo(D_801024A0)($a0)
  .L800FF15C:
    /* 595C 800FF15C 1080023C */  lui        $v0, %hi(D_801022D0)
    /* 5960 800FF160 D02245A0 */  sb         $a1, %lo(D_801022D0)($v0)
    /* 5964 800FF164 04000224 */  addiu      $v0, $zero, 0x4
    /* 5968 800FF168 0300A214 */  bne        $a1, $v0, .L800FF178
    /* 596C 800FF16C 0680023C */   lui       $v0, %hi(D_80060021)
    /* 5970 800FF170 6BFC0308 */  j          .L800FF1AC
    /* 5974 800FF174 01001124 */   addiu     $s1, $zero, 0x1
  .L800FF178:
    /* 5978 800FF178 21004290 */  lbu        $v0, %lo(D_80060021)($v0)
    /* 597C 800FF17C 00000000 */  nop
    /* 5980 800FF180 0A004010 */  beqz       $v0, .L800FF1AC
    /* 5984 800FF184 03000224 */   addiu     $v0, $zero, 0x3
    /* 5988 800FF188 0800A210 */  beq        $a1, $v0, .L800FF1AC
    /* 598C 800FF18C 0F80023C */   lui       $v0, %hi(D_800F4EE8)
    /* 5990 800FF190 E84E4224 */  addiu      $v0, $v0, %lo(D_800F4EE8)
    /* 5994 800FF194 40180500 */  sll        $v1, $a1, 1
    /* 5998 800FF198 21206200 */  addu       $a0, $v1, $v0
    /* 599C 800FF19C 01006324 */  addiu      $v1, $v1, 0x1
    /* 59A0 800FF1A0 21186200 */  addu       $v1, $v1, $v0
    /* 59A4 800FF1A4 00009190 */  lbu        $s1, 0x0($a0)
    /* 59A8 800FF1A8 00006690 */  lbu        $a2, 0x0($v1)
  .L800FF1AC:
    /* 59AC 800FF1AC F9FFA326 */  addiu      $v1, $s5, -0x7
    /* 59B0 800FF1B0 07006104 */  bgez       $v1, .L800FF1D0
    /* 59B4 800FF1B4 2A106600 */   slt       $v0, $v1, $a2
    /* 59B8 800FF1B8 21882602 */  addu       $s1, $s1, $a2
    /* 59BC 800FF1BC 2A103502 */  slt        $v0, $s1, $s5
    /* 59C0 800FF1C0 0D004014 */  bnez       $v0, .L800FF1F8
    /* 59C4 800FF1C4 21300000 */   addu      $a2, $zero, $zero
    /* 59C8 800FF1C8 7EFC0308 */  j          .L800FF1F8
    /* 59CC 800FF1CC 2188C000 */   addu      $s1, $a2, $zero
  .L800FF1D0:
    /* 59D0 800FF1D0 09004010 */  beqz       $v0, .L800FF1F8
    /* 59D4 800FF1D4 21102602 */   addu      $v0, $s1, $a2
    /* 59D8 800FF1D8 2A105500 */  slt        $v0, $v0, $s5
    /* 59DC 800FF1DC 04004014 */  bnez       $v0, .L800FF1F0
    /* 59E0 800FF1E0 2310C300 */   subu      $v0, $a2, $v1
    /* 59E4 800FF1E4 21880000 */  addu       $s1, $zero, $zero
    /* 59E8 800FF1E8 7EFC0308 */  j          .L800FF1F8
    /* 59EC 800FF1EC 21302002 */   addu      $a2, $s1, $zero
  .L800FF1F0:
    /* 59F0 800FF1F0 21882202 */  addu       $s1, $s1, $v0
    /* 59F4 800FF1F4 21306000 */  addu       $a2, $v1, $zero
  .L800FF1F8:
    /* 59F8 800FF1F8 0600C018 */  blez       $a2, .L800FF214
    /* 59FC 800FF1FC 2A10C300 */   slt       $v0, $a2, $v1
    /* 5A00 800FF200 04002016 */  bnez       $s1, .L800FF214
    /* 5A04 800FF204 00000000 */   nop
    /* 5A08 800FF208 01001124 */  addiu      $s1, $zero, 0x1
    /* 5A0C 800FF20C FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 5A10 800FF210 2A10C300 */  slt        $v0, $a2, $v1
  .L800FF214:
    /* 5A14 800FF214 05004010 */  beqz       $v0, .L800FF22C
    /* 5A18 800FF218 06000224 */   addiu     $v0, $zero, 0x6
    /* 5A1C 800FF21C 04002216 */  bne        $s1, $v0, .L800FF230
    /* 5A20 800FF220 C0211500 */   sll       $a0, $s5, 7
    /* 5A24 800FF224 05001124 */  addiu      $s1, $zero, 0x5
    /* 5A28 800FF228 0100C624 */  addiu      $a2, $a2, 0x1
  .L800FF22C:
    /* 5A2C 800FF22C C0211500 */  sll        $a0, $s5, 7
  .L800FF230:
    /* 5A30 800FF230 1080023C */  lui        $v0, %hi(D_801022CC)
    /* 5A34 800FF234 CC2251AC */  sw         $s1, %lo(D_801022CC)($v0)
    /* 5A38 800FF238 21880000 */  addu       $s1, $zero, $zero
    /* 5A3C 800FF23C 1080023C */  lui        $v0, %hi(D_801022D2)
    /* 5A40 800FF240 D22246A0 */  sb         $a2, %lo(D_801022D2)($v0)
    /* 5A44 800FF244 1080023C */  lui        $v0, %hi(D_801022D1)
    /* 5A48 800FF248 D12255A0 */  sb         $s5, %lo(D_801022D1)($v0)
    /* 5A4C 800FF24C 1080023C */  lui        $v0, %hi(D_801022C4)
    /* 5A50 800FF250 1080103C */  lui        $s0, %hi(D_801022C8)
    /* 5A54 800FF254 8F0F010C */  jal        vs_main_allocHeapR
    /* 5A58 800FF258 C42240A0 */   sb        $zero, %lo(D_801022C4)($v0)
    /* 5A5C 800FF25C 2F00A01A */  blez       $s5, .L800FF31C
    /* 5A60 800FF260 C82202AE */   sw        $v0, %lo(D_801022C8)($s0)
    /* 5A64 800FF264 21980002 */  addu       $s3, $s0, $zero
    /* 5A68 800FF268 E7E71734 */  ori        $s7, $zero, 0xE7E7
    /* 5A6C 800FF26C 21802002 */  addu       $s0, $s1, $zero
    /* 5A70 800FF270 22001624 */  addiu      $s6, $zero, 0x22
  .L800FF274:
    /* 5A74 800FF274 C822628E */  lw         $v0, %lo(D_801022C8)($s3)
    /* 5A78 800FF278 0000838E */  lw         $v1, 0x0($s4)
    /* 5A7C 800FF27C 21200202 */  addu       $a0, $s0, $v0
    /* 5A80 800FF280 1C0083AC */  sw         $v1, 0x1C($a0)
    /* 5A84 800FF284 0000458E */  lw         $a1, 0x0($s2)
    /* 5A88 800FF288 00000000 */  nop
    /* 5A8C 800FF28C 0800A010 */  beqz       $a1, .L800FF2B0
    /* 5A90 800FF290 00000000 */   nop
    /* 5A94 800FF294 7000030C */  jal        vs_battle_copyAligned
    /* 5A98 800FF298 1A000624 */   addiu     $a2, $zero, 0x1A
    /* 5A9C 800FF29C C822628E */  lw         $v0, %lo(D_801022C8)($s3)
    /* 5AA0 800FF2A0 00000000 */  nop
    /* 5AA4 800FF2A4 21100202 */  addu       $v0, $s0, $v0
    /* 5AA8 800FF2A8 ADFC0308 */  j          .L800FF2B4
    /* 5AAC 800FF2AC 1A0057A4 */   sh        $s7, 0x1A($v0)
  .L800FF2B0:
    /* 5AB0 800FF2B0 000097A4 */  sh         $s7, 0x0($a0)
  .L800FF2B4:
    /* 5AB4 800FF2B4 0400458E */  lw         $a1, 0x4($s2)
    /* 5AB8 800FF2B8 00000000 */  nop
    /* 5ABC 800FF2BC 0C00A010 */  beqz       $a1, .L800FF2F0
    /* 5AC0 800FF2C0 5C000624 */   addiu     $a2, $zero, 0x5C
    /* 5AC4 800FF2C4 C822638E */  lw         $v1, %lo(D_801022C8)($s3)
    /* 5AC8 800FF2C8 F8000224 */  addiu      $v0, $zero, 0xF8
    /* 5ACC 800FF2CC 21207600 */  addu       $a0, $v1, $s6
    /* 5AD0 800FF2D0 21180302 */  addu       $v1, $s0, $v1
    /* 5AD4 800FF2D4 7000030C */  jal        vs_battle_copyAligned
    /* 5AD8 800FF2D8 200062A4 */   sh        $v0, 0x20($v1)
    /* 5ADC 800FF2DC C822628E */  lw         $v0, %lo(D_801022C8)($s3)
    /* 5AE0 800FF2E0 00000000 */  nop
    /* 5AE4 800FF2E4 21100202 */  addu       $v0, $s0, $v0
    /* 5AE8 800FF2E8 C0FC0308 */  j          .L800FF300
    /* 5AEC 800FF2EC 7E0057A4 */   sh        $s7, 0x7E($v0)
  .L800FF2F0:
    /* 5AF0 800FF2F0 C822628E */  lw         $v0, %lo(D_801022C8)($s3)
    /* 5AF4 800FF2F4 00000000 */  nop
    /* 5AF8 800FF2F8 21100202 */  addu       $v0, $s0, $v0
    /* 5AFC 800FF2FC 200057A4 */  sh         $s7, 0x20($v0)
  .L800FF300:
    /* 5B00 800FF300 80001026 */  addiu      $s0, $s0, 0x80
    /* 5B04 800FF304 8000D626 */  addiu      $s6, $s6, 0x80
    /* 5B08 800FF308 08005226 */  addiu      $s2, $s2, 0x8
    /* 5B0C 800FF30C 01003126 */  addiu      $s1, $s1, 0x1
    /* 5B10 800FF310 2A103502 */  slt        $v0, $s1, $s5
    /* 5B14 800FF314 D7FF4014 */  bnez       $v0, .L800FF274
    /* 5B18 800FF318 04009426 */   addiu     $s4, $s4, 0x4
  .L800FF31C:
    /* 5B1C 800FF31C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 5B20 800FF320 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 5B24 800FF324 2800B68F */  lw         $s6, 0x28($sp)
    /* 5B28 800FF328 2400B58F */  lw         $s5, 0x24($sp)
    /* 5B2C 800FF32C 2000B48F */  lw         $s4, 0x20($sp)
    /* 5B30 800FF330 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5B34 800FF334 1800B28F */  lw         $s2, 0x18($sp)
    /* 5B38 800FF338 1400B18F */  lw         $s1, 0x14($sp)
    /* 5B3C 800FF33C 1000B08F */  lw         $s0, 0x10($sp)
    /* 5B40 800FF340 0800E003 */  jr         $ra
    /* 5B44 800FF344 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel vs_mainMenu_initSortUi
