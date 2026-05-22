nonmatching func_8006ABF0, 0x264

glabel func_8006ABF0
    /* 23F0 8006ABF0 0E80033C */  lui        $v1, %hi(D_800DC190)
    /* 23F4 8006ABF4 90C1628C */  lw         $v0, %lo(D_800DC190)($v1)
    /* 23F8 8006ABF8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 23FC 8006ABFC 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2400 8006AC00 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2404 8006AC04 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2408 8006AC08 1400B1AF */  sw         $s1, 0x14($sp)
    /* 240C 8006AC0C 04004010 */  beqz       $v0, .L8006AC20
    /* 2410 8006AC10 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2414 8006AC14 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2418 8006AC18 8EAB0108 */  j          .L8006AE38
    /* 241C 8006AC1C 90C162AC */   sw        $v0, %lo(D_800DC190)($v1)
  .L8006AC20:
    /* 2420 8006AC20 0E80103C */  lui        $s0, %hi(D_800DC194)
    /* 2424 8006AC24 02001324 */  addiu      $s3, $zero, 0x2
    /* 2428 8006AC28 01001124 */  addiu      $s1, $zero, 0x1
    /* 242C 8006AC2C 03001224 */  addiu      $s2, $zero, 0x3
  .L8006AC30:
    /* 2430 8006AC30 94C1068E */  lw         $a2, %lo(D_800DC194)($s0)
    /* 2434 8006AC34 00000000 */  nop
    /* 2438 8006AC38 0000C390 */  lbu        $v1, 0x0($a2)
    /* 243C 8006AC3C 05000224 */  addiu      $v0, $zero, 0x5
    /* 2440 8006AC40 5C006210 */  beq        $v1, $v0, .L8006ADB4
    /* 2444 8006AC44 06006228 */   slti      $v0, $v1, 0x6
    /* 2448 8006AC48 0F004010 */  beqz       $v0, .L8006AC88
    /* 244C 8006AC4C 07000224 */   addiu     $v0, $zero, 0x7
    /* 2450 8006AC50 20007310 */  beq        $v1, $s3, .L8006ACD4
    /* 2454 8006AC54 03006228 */   slti      $v0, $v1, 0x3
    /* 2458 8006AC58 05004010 */  beqz       $v0, .L8006AC70
    /* 245C 8006AC5C 00000000 */   nop
    /* 2460 8006AC60 14007110 */  beq        $v1, $s1, .L8006ACB4
    /* 2464 8006AC64 0100C224 */   addiu     $v0, $a2, 0x1
    /* 2468 8006AC68 8EAB0108 */  j          .L8006AE38
    /* 246C 8006AC6C 00000000 */   nop
  .L8006AC70:
    /* 2470 8006AC70 26007210 */  beq        $v1, $s2, .L8006AD0C
    /* 2474 8006AC74 04000224 */   addiu     $v0, $zero, 0x4
    /* 2478 8006AC78 2B006210 */  beq        $v1, $v0, .L8006AD28
    /* 247C 8006AC7C 0100C224 */   addiu     $v0, $a2, 0x1
    /* 2480 8006AC80 8EAB0108 */  j          .L8006AE38
    /* 2484 8006AC84 00000000 */   nop
  .L8006AC88:
    /* 2488 8006AC88 57006210 */  beq        $v1, $v0, .L8006ADE8
    /* 248C 8006AC8C 2A106200 */   slt       $v0, $v1, $v0
    /* 2490 8006AC90 4F004014 */  bnez       $v0, .L8006ADD0
    /* 2494 8006AC94 0780043C */   lui       $a0, %hi(func_8006A438)
    /* 2498 8006AC98 08000224 */  addiu      $v0, $zero, 0x8
    /* 249C 8006AC9C 57006210 */  beq        $v1, $v0, .L8006ADFC
    /* 24A0 8006ACA0 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 24A4 8006ACA4 63006210 */  beq        $v1, $v0, .L8006AE34
    /* 24A8 8006ACA8 0E80023C */   lui       $v0, %hi(D_800DC188)
    /* 24AC 8006ACAC 8EAB0108 */  j          .L8006AE38
    /* 24B0 8006ACB0 00000000 */   nop
  .L8006ACB4:
    /* 24B4 8006ACB4 94C102AE */  sw         $v0, %lo(D_800DC194)($s0)
    /* 24B8 8006ACB8 0100C390 */  lbu        $v1, 0x1($a2)
    /* 24BC 8006ACBC 0200C224 */  addiu      $v0, $a2, 0x2
    /* 24C0 8006ACC0 94C102AE */  sw         $v0, %lo(D_800DC194)($s0)
    /* 24C4 8006ACC4 0E80023C */  lui        $v0, %hi(D_800DC190)
    /* 24C8 8006ACC8 40180300 */  sll        $v1, $v1, 1
    /* 24CC 8006ACCC 8EAB0108 */  j          .L8006AE38
    /* 24D0 8006ACD0 90C143AC */   sw        $v1, %lo(D_800DC190)($v0)
  .L8006ACD4:
    /* 24D4 8006ACD4 0780043C */  lui        $a0, %hi(func_80069BC0)
    /* 24D8 8006ACD8 C09B8424 */  addiu      $a0, $a0, %lo(func_80069BC0)
    /* 24DC 8006ACDC 0100C224 */  addiu      $v0, $a2, 0x1
    /* 24E0 8006ACE0 D1AA010C */  jal        func_8006AB44
    /* 24E4 8006ACE4 94C102AE */   sw        $v0, %lo(D_800DC194)($s0)
    /* 24E8 8006ACE8 94C1038E */  lw         $v1, %lo(D_800DC194)($s0)
    /* 24EC 8006ACEC 00000000 */  nop
    /* 24F0 8006ACF0 040043AC */  sw         $v1, 0x4($v0)
    /* 24F4 8006ACF4 00006290 */  lbu        $v0, 0x0($v1)
    /* 24F8 8006ACF8 00000000 */  nop
    /* 24FC 8006ACFC 01004224 */  addiu      $v0, $v0, 0x1
    /* 2500 8006AD00 21186200 */  addu       $v1, $v1, $v0
    /* 2504 8006AD04 0CAB0108 */  j          .L8006AC30
    /* 2508 8006AD08 94C103AE */   sw        $v1, %lo(D_800DC194)($s0)
  .L8006AD0C:
    /* 250C 8006AD0C 0780043C */  lui        $a0, %hi(func_80069730)
    /* 2510 8006AD10 30978424 */  addiu      $a0, $a0, %lo(func_80069730)
    /* 2514 8006AD14 0100C224 */  addiu      $v0, $a2, 0x1
    /* 2518 8006AD18 D1AA010C */  jal        func_8006AB44
    /* 251C 8006AD1C 94C102AE */   sw        $v0, %lo(D_800DC194)($s0)
    /* 2520 8006AD20 0CAB0108 */  j          .L8006AC30
    /* 2524 8006AD24 0C0040A4 */   sh        $zero, 0xC($v0)
  .L8006AD28:
    /* 2528 8006AD28 94C102AE */  sw         $v0, %lo(D_800DC194)($s0)
    /* 252C 8006AD2C 0100C390 */  lbu        $v1, 0x1($a2)
    /* 2530 8006AD30 0200C224 */  addiu      $v0, $a2, 0x2
    /* 2534 8006AD34 12007110 */  beq        $v1, $s1, .L8006AD80
    /* 2538 8006AD38 94C102AE */   sw        $v0, %lo(D_800DC194)($s0)
    /* 253C 8006AD3C 02006228 */  slti       $v0, $v1, 0x2
    /* 2540 8006AD40 05004010 */  beqz       $v0, .L8006AD58
    /* 2544 8006AD44 00000000 */   nop
    /* 2548 8006AD48 09006010 */  beqz       $v1, .L8006AD70
    /* 254C 8006AD4C 0780043C */   lui       $a0, %hi(func_80069F9C)
    /* 2550 8006AD50 0CAB0108 */  j          .L8006AC30
    /* 2554 8006AD54 00000000 */   nop
  .L8006AD58:
    /* 2558 8006AD58 0E007310 */  beq        $v1, $s3, .L8006AD94
    /* 255C 8006AD5C 0780043C */   lui       $a0, %hi(func_80068EBC)
    /* 2560 8006AD60 10007210 */  beq        $v1, $s2, .L8006ADA4
    /* 2564 8006AD64 0780043C */   lui       $a0, %hi(func_80068938)
    /* 2568 8006AD68 0CAB0108 */  j          .L8006AC30
    /* 256C 8006AD6C 00000000 */   nop
  .L8006AD70:
    /* 2570 8006AD70 D1AA010C */  jal        func_8006AB44
    /* 2574 8006AD74 9C9F8424 */   addiu     $a0, $a0, %lo(func_80069F9C)
    /* 2578 8006AD78 0CAB0108 */  j          .L8006AC30
    /* 257C 8006AD7C 00000000 */   nop
  .L8006AD80:
    /* 2580 8006AD80 0780043C */  lui        $a0, %hi(func_80069088)
    /* 2584 8006AD84 D1AA010C */  jal        func_8006AB44
    /* 2588 8006AD88 88908424 */   addiu     $a0, $a0, %lo(func_80069088)
    /* 258C 8006AD8C 0CAB0108 */  j          .L8006AC30
    /* 2590 8006AD90 00000000 */   nop
  .L8006AD94:
    /* 2594 8006AD94 D1AA010C */  jal        func_8006AB44
    /* 2598 8006AD98 BC8E8424 */   addiu     $a0, $a0, %lo(func_80068EBC)
    /* 259C 8006AD9C 0CAB0108 */  j          .L8006AC30
    /* 25A0 8006ADA0 00000000 */   nop
  .L8006ADA4:
    /* 25A4 8006ADA4 D1AA010C */  jal        func_8006AB44
    /* 25A8 8006ADA8 38898424 */   addiu     $a0, $a0, %lo(func_80068938)
    /* 25AC 8006ADAC 0CAB0108 */  j          .L8006AC30
    /* 25B0 8006ADB0 00000000 */   nop
  .L8006ADB4:
    /* 25B4 8006ADB4 0100C224 */  addiu      $v0, $a2, 0x1
    /* 25B8 8006ADB8 94C102AE */  sw         $v0, %lo(D_800DC194)($s0)
    /* 25BC 8006ADBC 0780043C */  lui        $a0, %hi(func_8006A3BC)
    /* 25C0 8006ADC0 EFAA010C */  jal        func_8006ABBC
    /* 25C4 8006ADC4 BCA38424 */   addiu     $a0, $a0, %lo(func_8006A3BC)
    /* 25C8 8006ADC8 0CAB0108 */  j          .L8006AC30
    /* 25CC 8006ADCC 00000000 */   nop
  .L8006ADD0:
    /* 25D0 8006ADD0 38A48424 */  addiu      $a0, $a0, %lo(func_8006A438)
    /* 25D4 8006ADD4 0100C224 */  addiu      $v0, $a2, 0x1
    /* 25D8 8006ADD8 EFAA010C */  jal        func_8006ABBC
    /* 25DC 8006ADDC 94C102AE */   sw        $v0, %lo(D_800DC194)($s0)
    /* 25E0 8006ADE0 0CAB0108 */  j          .L8006AC30
    /* 25E4 8006ADE4 0E0040A4 */   sh        $zero, 0xE($v0)
  .L8006ADE8:
    /* 25E8 8006ADE8 0100C224 */  addiu      $v0, $a2, 0x1
    /* 25EC 8006ADEC 94C102AE */  sw         $v0, %lo(D_800DC194)($s0)
    /* 25F0 8006ADF0 0E80023C */  lui        $v0, %hi(D_800DC198)
    /* 25F4 8006ADF4 0CAB0108 */  j          .L8006AC30
    /* 25F8 8006ADF8 98C140A4 */   sh        $zero, %lo(D_800DC198)($v0)
  .L8006ADFC:
    /* 25FC 8006ADFC 0100C490 */  lbu        $a0, 0x1($a2)
    /* 2600 8006AE00 0200C390 */  lbu        $v1, 0x2($a2)
    /* 2604 8006AE04 0300C590 */  lbu        $a1, 0x3($a2)
    /* 2608 8006AE08 0400C224 */  addiu      $v0, $a2, 0x4
    /* 260C 8006AE0C 94C102AE */  sw         $v0, %lo(D_800DC194)($s0)
    /* 2610 8006AE10 0E80023C */  lui        $v0, %hi(D_800DB7B4)
    /* 2614 8006AE14 B4B74224 */  addiu      $v0, $v0, %lo(D_800DB7B4)
    /* 2618 8006AE18 40200400 */  sll        $a0, $a0, 1
    /* 261C 8006AE1C 21208200 */  addu       $a0, $a0, $v0
    /* 2620 8006AE20 002A0500 */  sll        $a1, $a1, 8
    /* 2624 8006AE24 21186500 */  addu       $v1, $v1, $a1
    /* 2628 8006AE28 60FF6324 */  addiu      $v1, $v1, -0xA0
    /* 262C 8006AE2C 0CAB0108 */  j          .L8006AC30
    /* 2630 8006AE30 000083A4 */   sh        $v1, 0x0($a0)
  .L8006AE34:
    /* 2634 8006AE34 88C151A0 */  sb         $s1, %lo(D_800DC188)($v0)
  .L8006AE38:
    /* 2638 8006AE38 2000BF8F */  lw         $ra, 0x20($sp)
    /* 263C 8006AE3C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2640 8006AE40 1800B28F */  lw         $s2, 0x18($sp)
    /* 2644 8006AE44 1400B18F */  lw         $s1, 0x14($sp)
    /* 2648 8006AE48 1000B08F */  lw         $s0, 0x10($sp)
    /* 264C 8006AE4C 0800E003 */  jr         $ra
    /* 2650 8006AE50 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8006ABF0
