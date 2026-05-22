nonmatching func_801059FC, 0x134

glabel func_801059FC
    /* 31FC 801059FC C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 3200 80105A00 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 3204 80105A04 21A88000 */  addu       $s5, $a0, $zero
    /* 3208 80105A08 2000B2AF */  sw         $s2, 0x20($sp)
    /* 320C 80105A0C 2190C000 */  addu       $s2, $a2, $zero
    /* 3210 80105A10 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 3214 80105A14 3800BEAF */  sw         $fp, 0x38($sp)
    /* 3218 80105A18 3400B7AF */  sw         $s7, 0x34($sp)
    /* 321C 80105A1C 3000B6AF */  sw         $s6, 0x30($sp)
    /* 3220 80105A20 2800B4AF */  sw         $s4, 0x28($sp)
    /* 3224 80105A24 2400B3AF */  sw         $s3, 0x24($sp)
    /* 3228 80105A28 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 322C 80105A2C 02004106 */  bgez       $s2, .L80105A38
    /* 3230 80105A30 1800B0AF */   sw        $s0, 0x18($sp)
    /* 3234 80105A34 21900000 */  addu       $s2, $zero, $zero
  .L80105A38:
    /* 3238 80105A38 4100422A */  slti       $v0, $s2, 0x41
    /* 323C 80105A3C 02004014 */  bnez       $v0, .L80105A48
    /* 3240 80105A40 21800000 */   addu      $s0, $zero, $zero
    /* 3244 80105A44 40001224 */  addiu      $s2, $zero, 0x40
  .L80105A48:
    /* 3248 80105A48 0680023C */  lui        $v0, %hi(vs_main_scoredata)
    /* 324C 80105A4C A0FE5E24 */  addiu      $fp, $v0, %lo(vs_main_scoredata)
    /* 3250 80105A50 0680023C */  lui        $v0, %hi(vs_main_stateFlags)
    /* 3254 80105A54 98155724 */  addiu      $s7, $v0, %lo(vs_main_stateFlags)
    /* 3258 80105A58 1180023C */  lui        $v0, %hi(D_801091D8)
    /* 325C 80105A5C D8915624 */  addiu      $s6, $v0, %lo(D_801091D8)
    /* 3260 80105A60 58021424 */  addiu      $s4, $zero, 0x258
    /* 3264 80105A64 2188A000 */  addu       $s1, $a1, $zero
  .L80105A68:
    /* 3268 80105A68 1180023C */  lui        $v0, %hi(D_801098A4)
    /* 326C 80105A6C A498428C */  lw         $v0, %lo(D_801098A4)($v0)
    /* 3270 80105A70 F27F1324 */  addiu      $s3, $zero, 0x7FF2
    /* 3274 80105A74 26105000 */  xor        $v0, $v0, $s0
    /* 3278 80105A78 0100422C */  sltiu      $v0, $v0, 0x1
    /* 327C 80105A7C 02004010 */  beqz       $v0, .L80105A88
    /* 3280 80105A80 21484000 */   addu      $t1, $v0, $zero
    /* 3284 80105A84 F87F1324 */  addiu      $s3, $zero, 0x7FF8
  .L80105A88:
    /* 3288 80105A88 FF00083C */  lui        $t0, (0xFFFFFF >> 16)
    /* 328C 80105A8C FFFF0835 */  ori        $t0, $t0, (0xFFFFFF & 0xFFFF)
    /* 3290 80105A90 ACFFA426 */  addiu      $a0, $s5, -0x54
    /* 3294 80105A94 C400E392 */  lbu        $v1, 0xC4($s7)
    /* 3298 80105A98 02002526 */  addiu      $a1, $s1, 0x2
    /* 329C 80105A9C 40100300 */  sll        $v0, $v1, 1
    /* 32A0 80105AA0 21104300 */  addu       $v0, $v0, $v1
    /* 32A4 80105AA4 21105000 */  addu       $v0, $v0, $s0
    /* 32A8 80105AA8 80100200 */  sll        $v0, $v0, 2
    /* 32AC 80105AAC 21105E00 */  addu       $v0, $v0, $fp
    /* 32B0 80105AB0 2800478C */  lw         $a3, 0x28($v0)
    /* 32B4 80105AB4 21304002 */  addu       $a2, $s2, $zero
    /* 32B8 80105AB8 1000A9AF */  sw         $t1, 0x10($sp)
    /* 32BC 80105ABC DB17040C */  jal        func_80105F6C
    /* 32C0 80105AC0 2438E800 */   and       $a3, $a3, $t0
    /* 32C4 80105AC4 21282002 */  addu       $a1, $s1, $zero
    /* 32C8 80105AC8 4B000626 */  addiu      $a2, $s0, 0x4B
    /* 32CC 80105ACC 21384002 */  addu       $a3, $s2, $zero
    /* 32D0 80105AD0 21109602 */  addu       $v0, $s4, $s6
    /* 32D4 80105AD4 08009426 */  addiu      $s4, $s4, 0x8
    /* 32D8 80105AD8 14003126 */  addiu      $s1, $s1, 0x14
    /* 32DC 80105ADC 02004490 */  lbu        $a0, 0x2($v0)
    /* 32E0 80105AE0 01001026 */  addiu      $s0, $s0, 0x1
    /* 32E4 80105AE4 1000B3AF */  sw         $s3, 0x10($sp)
    /* 32E8 80105AE8 2320A402 */  subu       $a0, $s5, $a0
    /* 32EC 80105AEC 7617040C */  jal        func_80105DD8
    /* 32F0 80105AF0 A8FF8424 */   addiu     $a0, $a0, -0x58
    /* 32F4 80105AF4 0300022A */  slti       $v0, $s0, 0x3
    /* 32F8 80105AF8 DBFF4014 */  bnez       $v0, .L80105A68
    /* 32FC 80105AFC 00000000 */   nop
    /* 3300 80105B00 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 3304 80105B04 3800BE8F */  lw         $fp, 0x38($sp)
    /* 3308 80105B08 3400B78F */  lw         $s7, 0x34($sp)
    /* 330C 80105B0C 3000B68F */  lw         $s6, 0x30($sp)
    /* 3310 80105B10 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 3314 80105B14 2800B48F */  lw         $s4, 0x28($sp)
    /* 3318 80105B18 2400B38F */  lw         $s3, 0x24($sp)
    /* 331C 80105B1C 2000B28F */  lw         $s2, 0x20($sp)
    /* 3320 80105B20 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 3324 80105B24 1800B08F */  lw         $s0, 0x18($sp)
    /* 3328 80105B28 0800E003 */  jr         $ra
    /* 332C 80105B2C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_801059FC
