nonmatching func_800BE180, 0x1EC

glabel func_800BE180
    /* 55980 800BE180 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 55984 800BE184 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 55988 800BE188 21980000 */  addu       $s3, $zero, $zero
    /* 5598C 800BE18C 801F023C */  lui        $v0, (0x1F800088 >> 16)
    /* 55990 800BE190 88004234 */  ori        $v0, $v0, (0x1F800088 & 0xFFFF)
    /* 55994 800BE194 2000B4AF */  sw         $s4, 0x20($sp)
    /* 55998 800BE198 21A06002 */  addu       $s4, $s3, $zero
    /* 5599C 800BE19C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 559A0 800BE1A0 801F103C */  lui        $s0, (0x1F800088 >> 16)
    /* 559A4 800BE1A4 0F80033C */  lui        $v1, %hi(D_800F4BA4)
    /* 559A8 800BE1A8 A44B638C */  lw         $v1, %lo(D_800F4BA4)($v1)
    /* 559AC 800BE1AC 88001036 */  ori        $s0, $s0, (0x1F800088 & 0xFFFF)
    /* 559B0 800BE1B0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 559B4 800BE1B4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 559B8 800BE1B8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 559BC 800BE1BC 5C0040A4 */  sh         $zero, 0x5C($v0)
    /* 559C0 800BE1C0 5A0040A4 */  sh         $zero, 0x5A($v0)
    /* 559C4 800BE1C4 580040A4 */  sh         $zero, 0x58($v0)
    /* 559C8 800BE1C8 540040A4 */  sh         $zero, 0x54($v0)
    /* 559CC 800BE1CC 520040A4 */  sh         $zero, 0x52($v0)
    /* 559D0 800BE1D0 500040A4 */  sh         $zero, 0x50($v0)
    /* 559D4 800BE1D4 A6017224 */  addiu      $s2, $v1, 0x1A6
    /* 559D8 800BE1D8 B0017124 */  addiu      $s1, $v1, 0x1B0
  .L800BE1DC:
    /* 559DC 800BE1DC 07F8020C */  jal        func_800BE01C
    /* 559E0 800BE1E0 21204002 */   addu      $a0, $s2, $zero
    /* 559E4 800BE1E4 38004010 */  beqz       $v0, .L800BE2C8
    /* 559E8 800BE1E8 00000000 */   nop
    /* 559EC 800BE1EC 00002292 */  lbu        $v0, 0x0($s1)
    /* 559F0 800BE1F0 F8FF2386 */  lh         $v1, -0x8($s1)
    /* 559F4 800BE1F4 82100200 */  srl        $v0, $v0, 2
    /* 559F8 800BE1F8 03004230 */  andi       $v0, $v0, 0x3
    /* 559FC 800BE1FC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 55A00 800BE200 18006200 */  mult       $v1, $v0
    /* 55A04 800BE204 12300000 */  mflo       $a2
    /* 55A08 800BE208 600006A6 */  sh         $a2, 0x60($s0)
    /* 55A0C 800BE20C 00002292 */  lbu        $v0, 0x0($s1)
    /* 55A10 800BE210 F8FF2386 */  lh         $v1, -0x8($s1)
    /* 55A14 800BE214 02110200 */  srl        $v0, $v0, 4
    /* 55A18 800BE218 03004230 */  andi       $v0, $v0, 0x3
    /* 55A1C 800BE21C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 55A20 800BE220 18006200 */  mult       $v1, $v0
    /* 55A24 800BE224 12280000 */  mflo       $a1
    /* 55A28 800BE228 620005A6 */  sh         $a1, 0x62($s0)
    /* 55A2C 800BE22C 00002292 */  lbu        $v0, 0x0($s1)
    /* 55A30 800BE230 F8FF2386 */  lh         $v1, -0x8($s1)
    /* 55A34 800BE234 82110200 */  srl        $v0, $v0, 6
    /* 55A38 800BE238 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 55A3C 800BE23C 18006200 */  mult       $v1, $v0
    /* 55A40 800BE240 12200000 */  mflo       $a0
    /* 55A44 800BE244 640004A6 */  sh         $a0, 0x64($s0)
    /* 55A48 800BE248 00002292 */  lbu        $v0, 0x0($s1)
    /* 55A4C 800BE24C 00000000 */  nop
    /* 55A50 800BE250 01004230 */  andi       $v0, $v0, 0x1
    /* 55A54 800BE254 0A004010 */  beqz       $v0, .L800BE280
    /* 55A58 800BE258 00000000 */   nop
    /* 55A5C 800BE25C 50000296 */  lhu        $v0, 0x50($s0)
    /* 55A60 800BE260 54000396 */  lhu        $v1, 0x54($s0)
    /* 55A64 800BE264 21104600 */  addu       $v0, $v0, $a2
    /* 55A68 800BE268 500002A6 */  sh         $v0, 0x50($s0)
    /* 55A6C 800BE26C 52000296 */  lhu        $v0, 0x52($s0)
    /* 55A70 800BE270 21186400 */  addu       $v1, $v1, $a0
    /* 55A74 800BE274 540003A6 */  sh         $v1, 0x54($s0)
    /* 55A78 800BE278 21104500 */  addu       $v0, $v0, $a1
    /* 55A7C 800BE27C 520002A6 */  sh         $v0, 0x52($s0)
  .L800BE280:
    /* 55A80 800BE280 00002292 */  lbu        $v0, 0x0($s1)
    /* 55A84 800BE284 00000000 */  nop
    /* 55A88 800BE288 02004230 */  andi       $v0, $v0, 0x2
    /* 55A8C 800BE28C 0D004010 */  beqz       $v0, .L800BE2C4
    /* 55A90 800BE290 00000000 */   nop
    /* 55A94 800BE294 58000296 */  lhu        $v0, 0x58($s0)
    /* 55A98 800BE298 60000396 */  lhu        $v1, 0x60($s0)
    /* 55A9C 800BE29C 62000496 */  lhu        $a0, 0x62($s0)
    /* 55AA0 800BE2A0 64000596 */  lhu        $a1, 0x64($s0)
    /* 55AA4 800BE2A4 21104300 */  addu       $v0, $v0, $v1
    /* 55AA8 800BE2A8 580002A6 */  sh         $v0, 0x58($s0)
    /* 55AAC 800BE2AC 5A000296 */  lhu        $v0, 0x5A($s0)
    /* 55AB0 800BE2B0 5C000396 */  lhu        $v1, 0x5C($s0)
    /* 55AB4 800BE2B4 21104400 */  addu       $v0, $v0, $a0
    /* 55AB8 800BE2B8 21186500 */  addu       $v1, $v1, $a1
    /* 55ABC 800BE2BC 5A0002A6 */  sh         $v0, 0x5A($s0)
    /* 55AC0 800BE2C0 5C0003A6 */  sh         $v1, 0x5C($s0)
  .L800BE2C4:
    /* 55AC4 800BE2C4 01007326 */  addiu      $s3, $s3, 0x1
  .L800BE2C8:
    /* 55AC8 800BE2C8 0C003126 */  addiu      $s1, $s1, 0xC
    /* 55ACC 800BE2CC 01008226 */  addiu      $v0, $s4, 0x1
    /* 55AD0 800BE2D0 21A04000 */  addu       $s4, $v0, $zero
    /* 55AD4 800BE2D4 00140200 */  sll        $v0, $v0, 16
    /* 55AD8 800BE2D8 03140200 */  sra        $v0, $v0, 16
    /* 55ADC 800BE2DC 02004228 */  slti       $v0, $v0, 0x2
    /* 55AE0 800BE2E0 BEFF4014 */  bnez       $v0, .L800BE1DC
    /* 55AE4 800BE2E4 0C005226 */   addiu     $s2, $s2, 0xC
    /* 55AE8 800BE2E8 0F80023C */  lui        $v0, %hi(D_800F4BA4)
    /* 55AEC 800BE2EC A44B458C */  lw         $a1, %lo(D_800F4BA4)($v0)
    /* 55AF0 800BE2F0 00141300 */  sll        $v0, $s3, 16
    /* 55AF4 800BE2F4 15004010 */  beqz       $v0, .L800BE34C
    /* 55AF8 800BE2F8 A401B3A4 */   sh        $s3, 0x1A4($a1)
    /* 55AFC 800BE2FC 801F033C */  lui        $v1, (0x1F8000D8 >> 16)
    /* 55B00 800BE300 D8006334 */  ori        $v1, $v1, (0x1F8000D8 & 0xFFFF)
    /* 55B04 800BE304 00006294 */  lhu        $v0, 0x0($v1)
    /* 55B08 800BE308 00000000 */  nop
    /* 55B0C 800BE30C BE01A2A4 */  sh         $v0, 0x1BE($a1)
    /* 55B10 800BE310 02006294 */  lhu        $v0, 0x2($v1)
    /* 55B14 800BE314 801F043C */  lui        $a0, (0x1F8000E0 >> 16)
    /* 55B18 800BE318 C001A2A4 */  sh         $v0, 0x1C0($a1)
    /* 55B1C 800BE31C 04006294 */  lhu        $v0, 0x4($v1)
    /* 55B20 800BE320 E0008434 */  ori        $a0, $a0, (0x1F8000E0 & 0xFFFF)
    /* 55B24 800BE324 C201A2A4 */  sh         $v0, 0x1C2($a1)
    /* 55B28 800BE328 00008294 */  lhu        $v0, 0x0($a0)
    /* 55B2C 800BE32C 00000000 */  nop
    /* 55B30 800BE330 C601A2A4 */  sh         $v0, 0x1C6($a1)
    /* 55B34 800BE334 02008294 */  lhu        $v0, 0x2($a0)
    /* 55B38 800BE338 00000000 */  nop
    /* 55B3C 800BE33C C801A2A4 */  sh         $v0, 0x1C8($a1)
    /* 55B40 800BE340 04008294 */  lhu        $v0, 0x4($a0)
    /* 55B44 800BE344 00000000 */  nop
    /* 55B48 800BE348 CA01A2A4 */  sh         $v0, 0x1CA($a1)
  .L800BE34C:
    /* 55B4C 800BE34C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 55B50 800BE350 2000B48F */  lw         $s4, 0x20($sp)
    /* 55B54 800BE354 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 55B58 800BE358 1800B28F */  lw         $s2, 0x18($sp)
    /* 55B5C 800BE35C 1400B18F */  lw         $s1, 0x14($sp)
    /* 55B60 800BE360 1000B08F */  lw         $s0, 0x10($sp)
    /* 55B64 800BE364 0800E003 */  jr         $ra
    /* 55B68 800BE368 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_800BE180
