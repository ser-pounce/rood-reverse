nonmatching func_8007BA98, 0x120

glabel func_8007BA98
    /* 13298 8007BA98 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1329C 8007BA9C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 132A0 8007BAA0 21888000 */  addu       $s1, $a0, $zero
    /* 132A4 8007BAA4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 132A8 8007BAA8 2190A000 */  addu       $s2, $a1, $zero
    /* 132AC 8007BAAC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 132B0 8007BAB0 2198C000 */  addu       $s3, $a2, $zero
    /* 132B4 8007BAB4 2000B4AF */  sw         $s4, 0x20($sp)
    /* 132B8 8007BAB8 21A0E000 */  addu       $s4, $a3, $zero
    /* 132BC 8007BABC 28020424 */  addiu      $a0, $zero, 0x228
    /* 132C0 8007BAC0 2400BFAF */  sw         $ra, 0x24($sp)
    /* 132C4 8007BAC4 8F0F010C */  jal        vs_main_allocHeapR
    /* 132C8 8007BAC8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 132CC 8007BACC 21804000 */  addu       $s0, $v0, $zero
    /* 132D0 8007BAD0 21000012 */  beqz       $s0, .L8007BB58
    /* 132D4 8007BAD4 21200002 */   addu      $a0, $s0, $zero
    /* 132D8 8007BAD8 4424010C */  jal        vs_main_bzero
    /* 132DC 8007BADC 28020524 */   addiu     $a1, $zero, 0x228
    /* 132E0 8007BAE0 FFFF2232 */  andi       $v0, $s1, 0xFFFF
    /* 132E4 8007BAE4 07004010 */  beqz       $v0, .L8007BB04
    /* 132E8 8007BAE8 1C0211A6 */   sh        $s1, 0x21C($s0)
    /* 132EC 8007BAEC 0400028E */  lw         $v0, 0x4($s0)
    /* 132F0 8007BAF0 03000324 */  addiu      $v1, $zero, 0x3
    /* 132F4 8007BAF4 1F0212A2 */  sb         $s2, 0x21F($s0)
    /* 132F8 8007BAF8 1E0203A2 */  sb         $v1, 0x21E($s0)
    /* 132FC 8007BAFC 01004234 */  ori        $v0, $v0, 0x1
    /* 13300 8007BB00 040002AE */  sw         $v0, 0x4($s0)
  .L8007BB04:
    /* 13304 8007BB04 FFFF6232 */  andi       $v0, $s3, 0xFFFF
    /* 13308 8007BB08 07004010 */  beqz       $v0, .L8007BB28
    /* 1330C 8007BB0C 200213A6 */   sh        $s3, 0x220($s0)
    /* 13310 8007BB10 0400028E */  lw         $v0, 0x4($s0)
    /* 13314 8007BB14 03000324 */  addiu      $v1, $zero, 0x3
    /* 13318 8007BB18 230214A2 */  sb         $s4, 0x223($s0)
    /* 1331C 8007BB1C 220203A2 */  sb         $v1, 0x222($s0)
    /* 13320 8007BB20 01004234 */  ori        $v0, $v0, 0x1
    /* 13324 8007BB24 040002AE */  sw         $v0, 0x4($s0)
  .L8007BB28:
    /* 13328 8007BB28 0400028E */  lw         $v0, 0x4($s0)
    /* 1332C 8007BB2C 00000000 */  nop
    /* 13330 8007BB30 07004010 */  beqz       $v0, .L8007BB50
    /* 13334 8007BB34 0F80023C */   lui       $v0, %hi(_lootListHead)
    /* 13338 8007BB38 0019448C */  lw         $a0, %lo(_lootListHead)($v0)
    /* 1333C 8007BB3C FF000324 */  addiu      $v1, $zero, 0xFF
    /* 13340 8007BB40 040003AE */  sw         $v1, 0x4($s0)
    /* 13344 8007BB44 001950AC */  sw         $s0, %lo(_lootListHead)($v0)
    /* 13348 8007BB48 D7EE0108 */  j          .L8007BB5C
    /* 1334C 8007BB4C 000004AE */   sw        $a0, 0x0($s0)
  .L8007BB50:
    /* 13350 8007BB50 180F010C */  jal        vs_main_freeHeapR
    /* 13354 8007BB54 21200002 */   addu      $a0, $s0, $zero
  .L8007BB58:
    /* 13358 8007BB58 0F80023C */  lui        $v0, %hi(_lootListHead)
  .L8007BB5C:
    /* 1335C 8007BB5C 0019448C */  lw         $a0, %lo(_lootListHead)($v0)
    /* 13360 8007BB60 00000000 */  nop
    /* 13364 8007BB64 0A008010 */  beqz       $a0, .L8007BB90
    /* 13368 8007BB68 0F80033C */   lui       $v1, %hi(D_800F1860)
    /* 1336C 8007BB6C 01000224 */  addiu      $v0, $zero, 0x1
    /* 13370 8007BB70 562C030C */  jal        func_800CB158
    /* 13374 8007BB74 601862AC */   sw        $v0, %lo(D_800F1860)($v1)
    /* 13378 8007BB78 0F80033C */  lui        $v1, %hi(_cameraMode)
    /* 1337C 8007BB7C 04000224 */  addiu      $v0, $zero, 0x4
    /* 13380 8007BB80 04ED010C */  jal        func_8007B410
    /* 13384 8007BB84 F01862AC */   sw        $v0, %lo(_cameraMode)($v1)
    /* 13388 8007BB88 E6EE0108 */  j          .L8007BB98
    /* 1338C 8007BB8C 00000000 */   nop
  .L8007BB90:
    /* 13390 8007BB90 31ED010C */  jal        func_8007B4C4
    /* 13394 8007BB94 00000000 */   nop
  .L8007BB98:
    /* 13398 8007BB98 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1339C 8007BB9C 2000B48F */  lw         $s4, 0x20($sp)
    /* 133A0 8007BBA0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 133A4 8007BBA4 1800B28F */  lw         $s2, 0x18($sp)
    /* 133A8 8007BBA8 1400B18F */  lw         $s1, 0x14($sp)
    /* 133AC 8007BBAC 1000B08F */  lw         $s0, 0x10($sp)
    /* 133B0 8007BBB0 0800E003 */  jr         $ra
    /* 133B4 8007BBB4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007BA98
