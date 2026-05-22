nonmatching func_800CF218, 0x1E0

glabel func_800CF218
    /* 66A18 800CF218 90FFBD27 */  addiu      $sp, $sp, -0x70
    /* 66A1C 800CF21C 4C00B1AF */  sw         $s1, 0x4C($sp)
    /* 66A20 800CF220 21888000 */  addu       $s1, $a0, $zero
    /* 66A24 800CF224 6400B7AF */  sw         $s7, 0x64($sp)
    /* 66A28 800CF228 21B8C000 */  addu       $s7, $a2, $zero
    /* 66A2C 800CF22C 6800BFAF */  sw         $ra, 0x68($sp)
    /* 66A30 800CF230 6000B6AF */  sw         $s6, 0x60($sp)
    /* 66A34 800CF234 5C00B5AF */  sw         $s5, 0x5C($sp)
    /* 66A38 800CF238 5800B4AF */  sw         $s4, 0x58($sp)
    /* 66A3C 800CF23C 5400B3AF */  sw         $s3, 0x54($sp)
    /* 66A40 800CF240 5000B2AF */  sw         $s2, 0x50($sp)
    /* 66A44 800CF244 273D030C */  jal        func_800CF49C
    /* 66A48 800CF248 4800B0AF */   sw        $s0, 0x48($sp)
    /* 66A4C 800CF24C 21B04000 */  addu       $s6, $v0, $zero
    /* 66A50 800CF250 0F80033C */  lui        $v1, %hi(D_800F53C0)
    /* 66A54 800CF254 C0536524 */  addiu      $a1, $v1, %lo(D_800F53C0)
    /* 66A58 800CF258 0F80033C */  lui        $v1, %hi(D_800F569C)
    /* 66A5C 800CF25C 9C56648C */  lw         $a0, %lo(D_800F569C)($v1)
    /* 66A60 800CF260 04002326 */  addiu      $v1, $s1, 0x4
    /* 66A64 800CF264 1000A3AF */  sw         $v1, 0x10($sp)
    /* 66A68 800CF268 9000838C */  lw         $v1, 0x90($a0)
    /* 66A6C 800CF26C E0002626 */  addiu      $a2, $s1, 0xE0
    /* 66A70 800CF270 2400A3AF */  sw         $v1, 0x24($sp)
    /* 66A74 800CF274 00002396 */  lhu        $v1, 0x0($s1)
    /* 66A78 800CF278 21202002 */  addu       $a0, $s1, $zero
    /* 66A7C 800CF27C 2C00A0AF */  sw         $zero, 0x2C($sp)
    /* 66A80 800CF280 3000A2A3 */  sb         $v0, 0x30($sp)
    /* 66A84 800CF284 40100300 */  sll        $v0, $v1, 1
    /* 66A88 800CF288 21104300 */  addu       $v0, $v0, $v1
    /* 66A8C 800CF28C 2800A2AF */  sw         $v0, 0x28($sp)
  .L800CF290:
    /* 66A90 800CF290 0000878C */  lw         $a3, 0x0($a0)
    /* 66A94 800CF294 0400888C */  lw         $t0, 0x4($a0)
    /* 66A98 800CF298 0800898C */  lw         $t1, 0x8($a0)
    /* 66A9C 800CF29C 0C008A8C */  lw         $t2, 0xC($a0)
    /* 66AA0 800CF2A0 0000A7AC */  sw         $a3, 0x0($a1)
    /* 66AA4 800CF2A4 0400A8AC */  sw         $t0, 0x4($a1)
    /* 66AA8 800CF2A8 0800A9AC */  sw         $t1, 0x8($a1)
    /* 66AAC 800CF2AC 0C00AAAC */  sw         $t2, 0xC($a1)
    /* 66AB0 800CF2B0 10008424 */  addiu      $a0, $a0, 0x10
    /* 66AB4 800CF2B4 F6FF8614 */  bne        $a0, $a2, .L800CF290
    /* 66AB8 800CF2B8 1000A524 */   addiu     $a1, $a1, 0x10
    /* 66ABC 800CF2BC 0000878C */  lw         $a3, 0x0($a0)
    /* 66AC0 800CF2C0 0400888C */  lw         $t0, 0x4($a0)
    /* 66AC4 800CF2C4 0000A7AC */  sw         $a3, 0x0($a1)
    /* 66AC8 800CF2C8 0400A8AC */  sw         $t0, 0x4($a1)
    /* 66ACC 800CF2CC 02002292 */  lbu        $v0, 0x2($s1)
    /* 66AD0 800CF2D0 00000000 */  nop
    /* 66AD4 800CF2D4 3C004010 */  beqz       $v0, .L800CF3C8
    /* 66AD8 800CF2D8 21900000 */   addu      $s2, $zero, $zero
    /* 66ADC 800CF2DC 04003426 */  addiu      $s4, $s1, 0x4
    /* 66AE0 800CF2E0 FFF81524 */  addiu      $s5, $zero, -0x701
    /* 66AE4 800CF2E4 21982002 */  addu       $s3, $s1, $zero
    /* 66AE8 800CF2E8 10001024 */  addiu      $s0, $zero, 0x10
  .L800CF2EC:
    /* 66AEC 800CF2EC 00002396 */  lhu        $v1, 0x0($s1)
    /* 66AF0 800CF2F0 00000000 */  nop
    /* 66AF4 800CF2F4 D8FF6224 */  addiu      $v0, $v1, -0x28
    /* 66AF8 800CF2F8 0200422C */  sltiu      $v0, $v0, 0x2
    /* 66AFC 800CF2FC 0C004014 */  bnez       $v0, .L800CF330
    /* 66B00 800CF300 21103002 */   addu      $v0, $s1, $s0
    /* 66B04 800CF304 D4FF6224 */  addiu      $v0, $v1, -0x2C
    /* 66B08 800CF308 0A00422C */  sltiu      $v0, $v0, 0xA
    /* 66B0C 800CF30C 08004014 */  bnez       $v0, .L800CF330
    /* 66B10 800CF310 21103002 */   addu      $v0, $s1, $s0
    /* 66B14 800CF314 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 66B18 800CF318 17000224 */  addiu      $v0, $zero, 0x17
    /* 66B1C 800CF31C 03006210 */  beq        $v1, $v0, .L800CF32C
    /* 66B20 800CF320 19000224 */   addiu     $v0, $zero, 0x19
    /* 66B24 800CF324 05006214 */  bne        $v1, $v0, .L800CF33C
    /* 66B28 800CF328 21103002 */   addu      $v0, $s1, $s0
  .L800CF32C:
    /* 66B2C 800CF32C 21103002 */  addu       $v0, $s1, $s0
  .L800CF330:
    /* 66B30 800CF330 1400A2AF */  sw         $v0, 0x14($sp)
    /* 66B34 800CF334 D13C0308 */  j          .L800CF344
    /* 66B38 800CF338 1C00B4AF */   sw        $s4, 0x1C($sp)
  .L800CF33C:
    /* 66B3C 800CF33C 1400B4AF */  sw         $s4, 0x14($sp)
    /* 66B40 800CF340 1C00A2AF */  sw         $v0, 0x1C($sp)
  .L800CF344:
    /* 66B44 800CF344 21103002 */  addu       $v0, $s1, $s0
    /* 66B48 800CF348 1800A2AF */  sw         $v0, 0x18($sp)
    /* 66B4C 800CF34C 10006296 */  lhu        $v0, 0x10($s3)
    /* 66B50 800CF350 1000A427 */  addiu      $a0, $sp, 0x10
    /* 66B54 800CF354 573D030C */  jal        func_800CF55C
    /* 66B58 800CF358 2000A2AF */   sw        $v0, 0x20($sp)
    /* 66B5C 800CF35C 21284000 */  addu       $a1, $v0, $zero
    /* 66B60 800CF360 580DB7AC */  sw         $s7, 0xD58($a1)
    /* 66B64 800CF364 00002296 */  lhu        $v0, 0x0($s1)
    /* 66B68 800CF368 00000000 */  nop
    /* 66B6C 800CF36C 540DA2A4 */  sh         $v0, 0xD54($a1)
    /* 66B70 800CF370 00002396 */  lhu        $v1, 0x0($s1)
    /* 66B74 800CF374 36000224 */  addiu      $v0, $zero, 0x36
    /* 66B78 800CF378 06006214 */  bne        $v1, $v0, .L800CF394
    /* 66B7C 800CF37C 00000000 */   nop
    /* 66B80 800CF380 1400A28C */  lw         $v0, 0x14($a1)
    /* 66B84 800CF384 00000000 */  nop
    /* 66B88 800CF388 24105500 */  and        $v0, $v0, $s5
    /* 66B8C 800CF38C E93C0308 */  j          .L800CF3A4
    /* 66B90 800CF390 00044234 */   ori       $v0, $v0, 0x400
  .L800CF394:
    /* 66B94 800CF394 1400A28C */  lw         $v0, 0x14($a1)
    /* 66B98 800CF398 00000000 */  nop
    /* 66B9C 800CF39C 24105500 */  and        $v0, $v0, $s5
    /* 66BA0 800CF3A0 00024234 */  ori        $v0, $v0, 0x200
  .L800CF3A4:
    /* 66BA4 800CF3A4 1400A2AC */  sw         $v0, 0x14($a1)
    /* 66BA8 800CF3A8 213D030C */  jal        func_800CF484
    /* 66BAC 800CF3AC 03000424 */   addiu     $a0, $zero, 0x3
    /* 66BB0 800CF3B0 0C007326 */  addiu      $s3, $s3, 0xC
    /* 66BB4 800CF3B4 02002292 */  lbu        $v0, 0x2($s1)
    /* 66BB8 800CF3B8 01005226 */  addiu      $s2, $s2, 0x1
    /* 66BBC 800CF3BC 2A104202 */  slt        $v0, $s2, $v0
    /* 66BC0 800CF3C0 CAFF4014 */  bnez       $v0, .L800CF2EC
    /* 66BC4 800CF3C4 0C001026 */   addiu     $s0, $s0, 0xC
  .L800CF3C8:
    /* 66BC8 800CF3C8 FF00C232 */  andi       $v0, $s6, 0xFF
    /* 66BCC 800CF3CC 6800BF8F */  lw         $ra, 0x68($sp)
    /* 66BD0 800CF3D0 6400B78F */  lw         $s7, 0x64($sp)
    /* 66BD4 800CF3D4 6000B68F */  lw         $s6, 0x60($sp)
    /* 66BD8 800CF3D8 5C00B58F */  lw         $s5, 0x5C($sp)
    /* 66BDC 800CF3DC 5800B48F */  lw         $s4, 0x58($sp)
    /* 66BE0 800CF3E0 5400B38F */  lw         $s3, 0x54($sp)
    /* 66BE4 800CF3E4 5000B28F */  lw         $s2, 0x50($sp)
    /* 66BE8 800CF3E8 4C00B18F */  lw         $s1, 0x4C($sp)
    /* 66BEC 800CF3EC 4800B08F */  lw         $s0, 0x48($sp)
    /* 66BF0 800CF3F0 0800E003 */  jr         $ra
    /* 66BF4 800CF3F4 7000BD27 */   addiu     $sp, $sp, 0x70
endlabel func_800CF218
