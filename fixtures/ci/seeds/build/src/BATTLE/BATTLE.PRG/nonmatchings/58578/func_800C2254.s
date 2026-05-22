nonmatching func_800C2254, 0x114

glabel func_800C2254
    /* 59A54 800C2254 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 59A58 800C2258 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 59A5C 800C225C 21B8A000 */  addu       $s7, $a1, $zero
    /* 59A60 800C2260 3000BEAF */  sw         $fp, 0x30($sp)
    /* 59A64 800C2264 801F1E3C */  lui        $fp, (0x1F800398 >> 16)
    /* 59A68 800C2268 9803DE37 */  ori        $fp, $fp, (0x1F800398 & 0xFFFF)
    /* 59A6C 800C226C 2800B6AF */  sw         $s6, 0x28($sp)
    /* 59A70 800C2270 21B00000 */  addu       $s6, $zero, $zero
    /* 59A74 800C2274 2000B4AF */  sw         $s4, 0x20($sp)
    /* 59A78 800C2278 21A08000 */  addu       $s4, $a0, $zero
    /* 59A7C 800C227C 0F80023C */  lui        $v0, %hi(D_800EB9B8)
    /* 59A80 800C2280 C0181700 */  sll        $v1, $s7, 3
    /* 59A84 800C2284 B8B9428C */  lw         $v0, %lo(D_800EB9B8)($v0)
    /* 59A88 800C2288 48006324 */  addiu      $v1, $v1, 0x48
    /* 59A8C 800C228C 3400BFAF */  sw         $ra, 0x34($sp)
    /* 59A90 800C2290 2400B5AF */  sw         $s5, 0x24($sp)
    /* 59A94 800C2294 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 59A98 800C2298 1800B2AF */  sw         $s2, 0x18($sp)
    /* 59A9C 800C229C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 59AA0 800C22A0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 59AA4 800C22A4 21A84300 */  addu       $s5, $v0, $v1
  .L800C22A8:
    /* 59AA8 800C22A8 21900000 */  addu       $s2, $zero, $zero
    /* 59AAC 800C22AC 2198A002 */  addu       $s3, $s5, $zero
    /* 59AB0 800C22B0 2188C003 */  addu       $s1, $fp, $zero
  .L800C22B4:
    /* 59AB4 800C22B4 C903010C */  jal        rcos
    /* 59AB8 800C22B8 21208002 */   addu      $a0, $s4, $zero
    /* 59ABC 800C22BC 21208002 */  addu       $a0, $s4, $zero
    /* 59AC0 800C22C0 CA03010C */  jal        rsin
    /* 59AC4 800C22C4 21804000 */   addu      $s0, $v0, $zero
    /* 59AC8 800C22C8 06002386 */  lh         $v1, 0x6($s1)
    /* 59ACC 800C22CC 00000000 */  nop
    /* 59AD0 800C22D0 18007000 */  mult       $v1, $s0
    /* 59AD4 800C22D4 12380000 */  mflo       $a3
    /* 59AD8 800C22D8 0C002386 */  lh         $v1, 0xC($s1)
    /* 59ADC 800C22DC 00000000 */  nop
    /* 59AE0 800C22E0 18006200 */  mult       $v1, $v0
    /* 59AE4 800C22E4 01005226 */  addiu      $s2, $s2, 0x1
    /* 59AE8 800C22E8 00002396 */  lhu        $v1, 0x0($s1)
    /* 59AEC 800C22EC 02003126 */  addiu      $s1, $s1, 0x2
    /* 59AF0 800C22F0 03130700 */  sra        $v0, $a3, 12
    /* 59AF4 800C22F4 21186200 */  addu       $v1, $v1, $v0
    /* 59AF8 800C22F8 12200000 */  mflo       $a0
    /* 59AFC 800C22FC 03130400 */  sra        $v0, $a0, 12
    /* 59B00 800C2300 21186200 */  addu       $v1, $v1, $v0
    /* 59B04 800C2304 000063A6 */  sh         $v1, 0x0($s3)
    /* 59B08 800C2308 0300422A */  slti       $v0, $s2, 0x3
    /* 59B0C 800C230C E9FF4014 */  bnez       $v0, .L800C22B4
    /* 59B10 800C2310 02007326 */   addiu     $s3, $s3, 0x2
    /* 59B14 800C2314 2B901600 */  sltu       $s2, $zero, $s6
    /* 59B18 800C2318 0600B2A6 */  sh         $s2, 0x6($s5)
    /* 59B1C 800C231C 0100F726 */  addiu      $s7, $s7, 0x1
    /* 59B20 800C2320 80009426 */  addiu      $s4, $s4, 0x80
    /* 59B24 800C2324 0100D626 */  addiu      $s6, $s6, 0x1
    /* 59B28 800C2328 2100C22A */  slti       $v0, $s6, 0x21
    /* 59B2C 800C232C DEFF4014 */  bnez       $v0, .L800C22A8
    /* 59B30 800C2330 0800B526 */   addiu     $s5, $s5, 0x8
    /* 59B34 800C2334 2110E002 */  addu       $v0, $s7, $zero
    /* 59B38 800C2338 3400BF8F */  lw         $ra, 0x34($sp)
    /* 59B3C 800C233C 3000BE8F */  lw         $fp, 0x30($sp)
    /* 59B40 800C2340 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 59B44 800C2344 2800B68F */  lw         $s6, 0x28($sp)
    /* 59B48 800C2348 2400B58F */  lw         $s5, 0x24($sp)
    /* 59B4C 800C234C 2000B48F */  lw         $s4, 0x20($sp)
    /* 59B50 800C2350 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 59B54 800C2354 1800B28F */  lw         $s2, 0x18($sp)
    /* 59B58 800C2358 1400B18F */  lw         $s1, 0x14($sp)
    /* 59B5C 800C235C 1000B08F */  lw         $s0, 0x10($sp)
    /* 59B60 800C2360 0800E003 */  jr         $ra
    /* 59B64 800C2364 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_800C2254
