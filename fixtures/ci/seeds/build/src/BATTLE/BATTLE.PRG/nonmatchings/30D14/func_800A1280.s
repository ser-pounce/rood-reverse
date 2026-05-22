nonmatching func_800A1280, 0x16C

glabel func_800A1280
    /* 38A80 800A1280 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 38A84 800A1284 2000B0AF */  sw         $s0, 0x20($sp)
    /* 38A88 800A1288 21808000 */  addu       $s0, $a0, $zero
    /* 38A8C 800A128C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 38A90 800A1290 2188C000 */  addu       $s1, $a2, $zero
    /* 38A94 800A1294 2800B2AF */  sw         $s2, 0x28($sp)
    /* 38A98 800A1298 2190E000 */  addu       $s2, $a3, $zero
    /* 38A9C 800A129C FB000224 */  addiu      $v0, $zero, 0xFB
    /* 38AA0 800A12A0 3D00A214 */  bne        $a1, $v0, .L800A1398
    /* 38AA4 800A12A4 2C00BFAF */   sw        $ra, 0x2C($sp)
    /* 38AA8 800A12A8 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 38AAC 800A12AC 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 38AB0 800A12B0 80201000 */  sll        $a0, $s0, 2
    /* 38AB4 800A12B4 21108200 */  addu       $v0, $a0, $v0
    /* 38AB8 800A12B8 0000458C */  lw         $a1, 0x0($v0)
    /* 38ABC 800A12BC 00000000 */  nop
    /* 38AC0 800A12C0 1100A014 */  bnez       $a1, .L800A1308
    /* 38AC4 800A12C4 000F033C */   lui       $v1, (0xF000000 >> 16)
    /* 38AC8 800A12C8 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 38ACC 800A12CC E0454224 */  addiu      $v0, $v0, %lo(D_800F45E0)
    /* 38AD0 800A12D0 21108200 */  addu       $v0, $a0, $v0
    /* 38AD4 800A12D4 0000438C */  lw         $v1, 0x0($v0)
    /* 38AD8 800A12D8 00000000 */  nop
    /* 38ADC 800A12DC 0F006010 */  beqz       $v1, .L800A131C
    /* 38AE0 800A12E0 00000000 */   nop
    /* 38AE4 800A12E4 1C006294 */  lhu        $v0, 0x1C($v1)
    /* 38AE8 800A12E8 00000000 */  nop
    /* 38AEC 800A12EC 000022A6 */  sh         $v0, 0x0($s1)
    /* 38AF0 800A12F0 20006294 */  lhu        $v0, 0x20($v1)
    /* 38AF4 800A12F4 00000000 */  nop
    /* 38AF8 800A12F8 040022A6 */  sh         $v0, 0x4($s1)
    /* 38AFC 800A12FC 1E006294 */  lhu        $v0, 0x1E($v1)
    /* 38B00 800A1300 D3840208 */  j          .L800A134C
    /* 38B04 800A1304 40FF4224 */   addiu     $v0, $v0, -0xC0
  .L800A1308:
    /* 38B08 800A1308 0800A28C */  lw         $v0, 0x8($a1)
    /* 38B0C 800A130C 00000000 */  nop
    /* 38B10 800A1310 24104300 */  and        $v0, $v0, $v1
    /* 38B14 800A1314 03004010 */  beqz       $v0, .L800A1324
    /* 38B18 800A1318 00000000 */   nop
  .L800A131C:
    /* 38B1C 800A131C F4840208 */  j          .L800A13D0
    /* 38B20 800A1320 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L800A1324:
    /* 38B24 800A1324 1C00A294 */  lhu        $v0, 0x1C($a1)
    /* 38B28 800A1328 00000000 */  nop
    /* 38B2C 800A132C 000022A6 */  sh         $v0, 0x0($s1)
    /* 38B30 800A1330 2000A294 */  lhu        $v0, 0x20($a1)
    /* 38B34 800A1334 00000000 */  nop
    /* 38B38 800A1338 040022A6 */  sh         $v0, 0x4($s1)
    /* 38B3C 800A133C 1E00A294 */  lhu        $v0, 0x1E($a1)
    /* 38B40 800A1340 4606A394 */  lhu        $v1, 0x646($a1)
    /* 38B44 800A1344 00000000 */  nop
    /* 38B48 800A1348 23104300 */  subu       $v0, $v0, $v1
  .L800A134C:
    /* 38B4C 800A134C 020022A6 */  sh         $v0, 0x2($s1)
    /* 38B50 800A1350 801F043C */  lui        $a0, (0x1F800014 >> 16)
    /* 38B54 800A1354 6605010C */  jal        SetRotMatrix
    /* 38B58 800A1358 14008434 */   ori       $a0, $a0, (0x1F800014 & 0xFFFF)
    /* 38B5C 800A135C 801F043C */  lui        $a0, (0x1F800014 >> 16)
    /* 38B60 800A1360 5E05010C */  jal        SetTransMatrix
    /* 38B64 800A1364 14008434 */   ori       $a0, $a0, (0x1F800014 & 0xFFFF)
    /* 38B68 800A1368 21202002 */  addu       $a0, $s1, $zero
    /* 38B6C 800A136C 1000A527 */  addiu      $a1, $sp, 0x10
    /* 38B70 800A1370 1400A627 */  addiu      $a2, $sp, 0x14
    /* 38B74 800A1374 0506010C */  jal        RotTransPers
    /* 38B78 800A1378 1800A727 */   addiu     $a3, $sp, 0x18
    /* 38B7C 800A137C 040022A6 */  sh         $v0, 0x4($s1)
    /* 38B80 800A1380 1000A397 */  lhu        $v1, 0x10($sp)
    /* 38B84 800A1384 1200A487 */  lh         $a0, 0x12($sp)
    /* 38B88 800A1388 21100000 */  addu       $v0, $zero, $zero
    /* 38B8C 800A138C 000023A6 */  sh         $v1, 0x0($s1)
    /* 38B90 800A1390 F4840208 */  j          .L800A13D0
    /* 38B94 800A1394 020024A6 */   sh        $a0, 0x2($s1)
  .L800A1398:
    /* 38B98 800A1398 21200002 */  addu       $a0, $s0, $zero
    /* 38B9C 800A139C 4B85020C */  jal        func_800A152C
    /* 38BA0 800A13A0 21300000 */   addu      $a2, $zero, $zero
    /* 38BA4 800A13A4 0A004004 */  bltz       $v0, .L800A13D0
    /* 38BA8 800A13A8 1400A2AF */   sw        $v0, 0x14($sp)
    /* 38BAC 800A13AC 21200002 */  addu       $a0, $s0, $zero
    /* 38BB0 800A13B0 21284000 */  addu       $a1, $v0, $zero
    /* 38BB4 800A13B4 21302002 */  addu       $a2, $s1, $zero
    /* 38BB8 800A13B8 0785020C */  jal        func_800A141C
    /* 38BBC 800A13BC 21384002 */   addu      $a3, $s2, $zero
    /* 38BC0 800A13C0 21184000 */  addu       $v1, $v0, $zero
    /* 38BC4 800A13C4 02006004 */  bltz       $v1, .L800A13D0
    /* 38BC8 800A13C8 1400A3AF */   sw        $v1, 0x14($sp)
    /* 38BCC 800A13CC 21100000 */  addu       $v0, $zero, $zero
  .L800A13D0:
    /* 38BD0 800A13D0 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 38BD4 800A13D4 2800B28F */  lw         $s2, 0x28($sp)
    /* 38BD8 800A13D8 2400B18F */  lw         $s1, 0x24($sp)
    /* 38BDC 800A13DC 2000B08F */  lw         $s0, 0x20($sp)
    /* 38BE0 800A13E0 3000BD27 */  addiu      $sp, $sp, 0x30
    /* 38BE4 800A13E4 0800E003 */  jr         $ra
    /* 38BE8 800A13E8 00000000 */   nop
endlabel func_800A1280
