nonmatching _fileProcessingAnim, 0x120

glabel _fileProcessingAnim
    /* 23B8 8006ABB8 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 23BC 8006ABBC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 23C0 8006ABC0 21888000 */  addu       $s1, $a0, $zero
    /* 23C4 8006ABC4 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 23C8 8006ABC8 21B8A000 */  addu       $s7, $a1, $zero
    /* 23CC 8006ABCC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 23D0 8006ABD0 D0FF3326 */  addiu      $s3, $s1, -0x30
    /* 23D4 8006ABD4 4000622E */  sltiu      $v0, $s3, 0x40
    /* 23D8 8006ABD8 3400BFAF */  sw         $ra, 0x34($sp)
    /* 23DC 8006ABDC 3000BEAF */  sw         $fp, 0x30($sp)
    /* 23E0 8006ABE0 2800B6AF */  sw         $s6, 0x28($sp)
    /* 23E4 8006ABE4 2400B5AF */  sw         $s5, 0x24($sp)
    /* 23E8 8006ABE8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 23EC 8006ABEC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 23F0 8006ABF0 02004010 */  beqz       $v0, .L8006ABFC
    /* 23F4 8006ABF4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 23F8 8006ABF8 40001324 */  addiu      $s3, $zero, 0x40
  .L8006ABFC:
    /* 23FC 8006ABFC 21A00000 */  addu       $s4, $zero, $zero
    /* 2400 8006AC00 0E80023C */  lui        $v0, %hi(_isSaving)
    /* 2404 8006AC04 70ED4290 */  lbu        $v0, %lo(_isSaving)($v0)
    /* 2408 8006AC08 00000000 */  nop
    /* 240C 8006AC0C 03004010 */  beqz       $v0, .L8006AC1C
    /* 2410 8006AC10 E0FF1234 */   ori       $s2, $zero, 0xFFE0
    /* 2414 8006AC14 7F00123C */  lui        $s2, (0x7F00FF >> 16)
    /* 2418 8006AC18 FF005236 */  ori        $s2, $s2, (0x7F00FF & 0xFFFF)
  .L8006AC1C:
    /* 241C 8006AC1C 21A80000 */  addu       $s5, $zero, $zero
    /* 2420 8006AC20 0E801E3C */  lui        $fp, %hi(_primBuf)
    /* 2424 8006AC24 28EDD027 */  addiu      $s0, $fp, %lo(_primBuf)
    /* 2428 8006AC28 2000023C */  lui        $v0, (0x200000 >> 16)
    /* 242C 8006AC2C 21B0E202 */  addu       $s6, $s7, $v0
  .L8006AC30:
    /* 2430 8006AC30 94A1000C */  jal        DrawSync
    /* 2434 8006AC34 21200000 */   addu      $a0, $zero, $zero
    /* 2438 8006AC38 00E1033C */  lui        $v1, (0xE1000220 >> 16)
    /* 243C 8006AC3C 20026334 */  ori        $v1, $v1, (0xE1000220 & 0xFFFF)
    /* 2440 8006AC40 21200002 */  addu       $a0, $s0, $zero
    /* 2444 8006AC44 0009023C */  lui        $v0, (0x9000000 >> 16)
    /* 2448 8006AC48 28EDC2AF */  sw         $v0, %lo(_primBuf)($fp)
    /* 244C 8006AC4C 003A023C */  lui        $v0, (0x3A000000 >> 16)
    /* 2450 8006AC50 25108202 */  or         $v0, $s4, $v0
    /* 2454 8006AC54 080002AE */  sw         $v0, 0x8($s0)
    /* 2458 8006AC58 25107702 */  or         $v0, $s3, $s7
    /* 245C 8006AC5C 0C0002AE */  sw         $v0, 0xC($s0)
    /* 2460 8006AC60 25103702 */  or         $v0, $s1, $s7
    /* 2464 8006AC64 140002AE */  sw         $v0, 0x14($s0)
    /* 2468 8006AC68 25107602 */  or         $v0, $s3, $s6
    /* 246C 8006AC6C 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2470 8006AC70 25103602 */  or         $v0, $s1, $s6
    /* 2474 8006AC74 040003AE */  sw         $v1, 0x4($s0)
    /* 2478 8006AC78 100012AE */  sw         $s2, 0x10($s0)
    /* 247C 8006AC7C 180014AE */  sw         $s4, 0x18($s0)
    /* 2480 8006AC80 200012AE */  sw         $s2, 0x20($s0)
    /* 2484 8006AC84 FAA2000C */  jal        DrawPrim
    /* 2488 8006AC88 240002AE */   sw        $v0, 0x24($s0)
    /* 248C 8006AC8C 21982002 */  addu       $s3, $s1, $zero
    /* 2490 8006AC90 10003126 */  addiu      $s1, $s1, 0x10
    /* 2494 8006AC94 21A04002 */  addu       $s4, $s2, $zero
    /* 2498 8006AC98 0100B526 */  addiu      $s5, $s5, 0x1
    /* 249C 8006AC9C 0200A22E */  sltiu      $v0, $s5, 0x2
    /* 24A0 8006ACA0 E3FF4014 */  bnez       $v0, .L8006AC30
    /* 24A4 8006ACA4 21900000 */   addu      $s2, $zero, $zero
    /* 24A8 8006ACA8 3400BF8F */  lw         $ra, 0x34($sp)
    /* 24AC 8006ACAC 3000BE8F */  lw         $fp, 0x30($sp)
    /* 24B0 8006ACB0 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 24B4 8006ACB4 2800B68F */  lw         $s6, 0x28($sp)
    /* 24B8 8006ACB8 2400B58F */  lw         $s5, 0x24($sp)
    /* 24BC 8006ACBC 2000B48F */  lw         $s4, 0x20($sp)
    /* 24C0 8006ACC0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 24C4 8006ACC4 1800B28F */  lw         $s2, 0x18($sp)
    /* 24C8 8006ACC8 1400B18F */  lw         $s1, 0x14($sp)
    /* 24CC 8006ACCC 1000B08F */  lw         $s0, 0x10($sp)
    /* 24D0 8006ACD0 0800E003 */  jr         $ra
    /* 24D4 8006ACD4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel _fileProcessingAnim
