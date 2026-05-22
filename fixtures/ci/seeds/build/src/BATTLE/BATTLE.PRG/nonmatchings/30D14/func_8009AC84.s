nonmatching func_8009AC84, 0x21C

glabel func_8009AC84
    /* 32484 8009AC84 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 32488 8009AC88 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3248C 8009AC8C 21888000 */  addu       $s1, $a0, $zero
    /* 32490 8009AC90 0F80023C */  lui        $v0, %hi(D_800E8F2A)
    /* 32494 8009AC94 2A8F4390 */  lbu        $v1, %lo(D_800E8F2A)($v0)
    /* 32498 8009AC98 01000224 */  addiu      $v0, $zero, 0x1
    /* 3249C 8009AC9C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 324A0 8009ACA0 59006210 */  beq        $v1, $v0, .L8009AE08
    /* 324A4 8009ACA4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 324A8 8009ACA8 02006228 */  slti       $v0, $v1, 0x2
    /* 324AC 8009ACAC 05004010 */  beqz       $v0, .L8009ACC4
    /* 324B0 8009ACB0 02000224 */   addiu     $v0, $zero, 0x2
    /* 324B4 8009ACB4 07006010 */  beqz       $v1, .L8009ACD4
    /* 324B8 8009ACB8 0F80043C */   lui       $a0, %hi(D_800E8860)
    /* 324BC 8009ACBC 596B0208 */  j          .L8009AD64
    /* 324C0 8009ACC0 00000000 */   nop
  .L8009ACC4:
    /* 324C4 8009ACC4 60006210 */  beq        $v1, $v0, .L8009AE48
    /* 324C8 8009ACC8 0F80043C */   lui       $a0, %hi(D_800E8860)
    /* 324CC 8009ACCC 596B0208 */  j          .L8009AD64
    /* 324D0 8009ACD0 00000000 */   nop
  .L8009ACD4:
    /* 324D4 8009ACD4 02002386 */  lh         $v1, 0x2($s1)
    /* 324D8 8009ACD8 7F000224 */  addiu      $v0, $zero, 0x7F
    /* 324DC 8009ACDC 06006214 */  bne        $v1, $v0, .L8009ACF8
    /* 324E0 8009ACE0 21200000 */   addu      $a0, $zero, $zero
    /* 324E4 8009ACE4 536B0208 */  j          .L8009AD4C
    /* 324E8 8009ACE8 0F80023C */   lui       $v0, %hi(D_800F22A4)
  .L8009ACEC:
    /* 324EC 8009ACEC 080024AE */  sw         $a0, 0x8($s1)
    /* 324F0 8009ACF0 516B0208 */  j          .L8009AD44
    /* 324F4 8009ACF4 01000224 */   addiu     $v0, $zero, 0x1
  .L8009ACF8:
    /* 324F8 8009ACF8 01002682 */  lb         $a2, 0x1($s1)
    /* 324FC 8009ACFC 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 32500 8009AD00 38454524 */  addiu      $a1, $v0, %lo(D_800F4538)
  .L8009AD04:
    /* 32504 8009AD04 0A008610 */  beq        $a0, $a2, .L8009AD30
    /* 32508 8009AD08 00000000 */   nop
    /* 3250C 8009AD0C 0000A28C */  lw         $v0, 0x0($a1)
    /* 32510 8009AD10 00000000 */  nop
    /* 32514 8009AD14 06004010 */  beqz       $v0, .L8009AD30
    /* 32518 8009AD18 00000000 */   nop
    /* 3251C 8009AD1C E6064394 */  lhu        $v1, 0x6E6($v0)
    /* 32520 8009AD20 02002286 */  lh         $v0, 0x2($s1)
    /* 32524 8009AD24 00000000 */  nop
    /* 32528 8009AD28 F0FF6210 */  beq        $v1, $v0, .L8009ACEC
    /* 3252C 8009AD2C 00000000 */   nop
  .L8009AD30:
    /* 32530 8009AD30 01008424 */  addiu      $a0, $a0, 0x1
    /* 32534 8009AD34 11008228 */  slti       $v0, $a0, 0x11
    /* 32538 8009AD38 F2FF4014 */  bnez       $v0, .L8009AD04
    /* 3253C 8009AD3C 0400A524 */   addiu     $a1, $a1, 0x4
    /* 32540 8009AD40 21100000 */  addu       $v0, $zero, $zero
  .L8009AD44:
    /* 32544 8009AD44 03004010 */  beqz       $v0, .L8009AD54
    /* 32548 8009AD48 0F80023C */   lui       $v0, %hi(D_800F22A4)
  .L8009AD4C:
    /* 3254C 8009AD4C 926B0208 */  j          .L8009AE48
    /* 32550 8009AD50 A42240AC */   sw        $zero, %lo(D_800F22A4)($v0)
  .L8009AD54:
    /* 32554 8009AD54 0F80033C */  lui        $v1, %hi(D_800F22A4)
    /* 32558 8009AD58 01000224 */  addiu      $v0, $zero, 0x1
    /* 3255C 8009AD5C A42262AC */  sw         $v0, %lo(D_800F22A4)($v1)
    /* 32560 8009AD60 0F80043C */  lui        $a0, %hi(D_800E8860)
  .L8009AD64:
    /* 32564 8009AD64 02002286 */  lh         $v0, 0x2($s1)
    /* 32568 8009AD68 60888324 */  addiu      $v1, $a0, %lo(D_800E8860)
    /* 3256C 8009AD6C 21104300 */  addu       $v0, $v0, $v1
    /* 32570 8009AD70 00005090 */  lbu        $s0, 0x0($v0)
    /* 32574 8009AD74 00000000 */  nop
    /* 32578 8009AD78 05000016 */  bnez       $s0, .L8009AD90
    /* 3257C 8009AD7C C0821000 */   sll       $s0, $s0, 11
    /* 32580 8009AD80 020020A6 */  sh         $zero, 0x2($s1)
    /* 32584 8009AD84 60889090 */  lbu        $s0, %lo(D_800E8860)($a0)
    /* 32588 8009AD88 00000000 */  nop
    /* 3258C 8009AD8C C0821000 */  sll        $s0, $s0, 11
  .L8009AD90:
    /* 32590 8009AD90 8F0F010C */  jal        vs_main_allocHeapR
    /* 32594 8009AD94 21200002 */   addu      $a0, $s0, $zero
    /* 32598 8009AD98 0F80033C */  lui        $v1, %hi(D_800F22A0)
    /* 3259C 8009AD9C A02262AC */  sw         $v0, %lo(D_800F22A0)($v1)
    /* 325A0 8009ADA0 03004014 */  bnez       $v0, .L8009ADB0
    /* 325A4 8009ADA4 080022AE */   sw        $v0, 0x8($s1)
    /* 325A8 8009ADA8 A26B0208 */  j          .L8009AE88
    /* 325AC 8009ADAC FEFF0224 */   addiu     $v0, $zero, -0x2
  .L8009ADB0:
    /* 325B0 8009ADB0 0100073C */  lui        $a3, (0x17318 >> 16)
    /* 325B4 8009ADB4 1873E734 */  ori        $a3, $a3, (0x17318 & 0xFFFF)
    /* 325B8 8009ADB8 0F80063C */  lui        $a2, %hi(D_800F22A8)
    /* 325BC 8009ADBC A822C424 */  addiu      $a0, $a2, %lo(D_800F22A8)
    /* 325C0 8009ADC0 0F80053C */  lui        $a1, %hi(D_800E8F2A)
    /* 325C4 8009ADC4 0F80033C */  lui        $v1, %hi(D_800E8660)
    /* 325C8 8009ADC8 02002286 */  lh         $v0, 0x2($s1)
    /* 325CC 8009ADCC 60866324 */  addiu      $v1, $v1, %lo(D_800E8660)
    /* 325D0 8009ADD0 40100200 */  sll        $v0, $v0, 1
    /* 325D4 8009ADD4 21104300 */  addu       $v0, $v0, $v1
    /* 325D8 8009ADD8 00004394 */  lhu        $v1, 0x0($v0)
    /* 325DC 8009ADDC 01000224 */  addiu      $v0, $zero, 0x1
    /* 325E0 8009ADE0 2A8FA2A0 */  sb         $v0, %lo(D_800E8F2A)($a1)
    /* 325E4 8009ADE4 040090AC */  sw         $s0, 0x4($a0)
    /* 325E8 8009ADE8 21186700 */  addu       $v1, $v1, $a3
    /* 325EC 8009ADEC C412010C */  jal        vs_main_allocateCdQueueSlot
    /* 325F0 8009ADF0 A822C3AC */   sw        $v1, %lo(D_800F22A8)($a2)
    /* 325F4 8009ADF4 21204000 */  addu       $a0, $v0, $zero
    /* 325F8 8009ADF8 0800258E */  lw         $a1, 0x8($s1)
    /* 325FC 8009ADFC 0F80023C */  lui        $v0, %hi(D_800F22B0)
    /* 32600 8009AE00 F112010C */  jal        vs_main_cdEnqueue
    /* 32604 8009AE04 B02244AC */   sw        $a0, %lo(D_800F22B0)($v0)
  .L8009AE08:
    /* 32608 8009AE08 0F80023C */  lui        $v0, %hi(D_800F22B0)
    /* 3260C 8009AE0C B022448C */  lw         $a0, %lo(D_800F22B0)($v0)
    /* 32610 8009AE10 00000000 */  nop
    /* 32614 8009AE14 00008384 */  lh         $v1, 0x0($a0)
    /* 32618 8009AE18 04000224 */  addiu      $v0, $zero, 0x4
    /* 3261C 8009AE1C 03006210 */  beq        $v1, $v0, .L8009AE2C
    /* 32620 8009AE20 00000000 */   nop
    /* 32624 8009AE24 A26B0208 */  j          .L8009AE88
    /* 32628 8009AE28 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8009AE2C:
    /* 3262C 8009AE2C E012010C */  jal        vs_main_freeCdQueueSlot
    /* 32630 8009AE30 00000000 */   nop
    /* 32634 8009AE34 0F80033C */  lui        $v1, %hi(D_800E8F2A)
    /* 32638 8009AE38 02000224 */  addiu      $v0, $zero, 0x2
    /* 3263C 8009AE3C 2A8F62A0 */  sb         $v0, %lo(D_800E8F2A)($v1)
    /* 32640 8009AE40 A26B0208 */  j          .L8009AE88
    /* 32644 8009AE44 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8009AE48:
    /* 32648 8009AE48 A86B020C */  jal        _loadShp
    /* 3264C 8009AE4C 21202002 */   addu      $a0, $s1, $zero
    /* 32650 8009AE50 21804000 */  addu       $s0, $v0, $zero
    /* 32654 8009AE54 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 32658 8009AE58 0B000212 */  beq        $s0, $v0, .L8009AE88
    /* 3265C 8009AE5C 0F80033C */   lui       $v1, %hi(D_800F22A4)
    /* 32660 8009AE60 A422628C */  lw         $v0, %lo(D_800F22A4)($v1)
    /* 32664 8009AE64 00000000 */  nop
    /* 32668 8009AE68 04004010 */  beqz       $v0, .L8009AE7C
    /* 3266C 8009AE6C 0F80023C */   lui       $v0, %hi(D_800F22A0)
    /* 32670 8009AE70 A022448C */  lw         $a0, %lo(D_800F22A0)($v0)
    /* 32674 8009AE74 180F010C */  jal        vs_main_freeHeapR
    /* 32678 8009AE78 A42260AC */   sw        $zero, %lo(D_800F22A4)($v1)
  .L8009AE7C:
    /* 3267C 8009AE7C 0F80023C */  lui        $v0, %hi(D_800E8F2A)
    /* 32680 8009AE80 2A8F40A0 */  sb         $zero, %lo(D_800E8F2A)($v0)
    /* 32684 8009AE84 21100002 */  addu       $v0, $s0, $zero
  .L8009AE88:
    /* 32688 8009AE88 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3268C 8009AE8C 1400B18F */  lw         $s1, 0x14($sp)
    /* 32690 8009AE90 1000B08F */  lw         $s0, 0x10($sp)
    /* 32694 8009AE94 2000BD27 */  addiu      $sp, $sp, 0x20
    /* 32698 8009AE98 0800E003 */  jr         $ra
    /* 3269C 8009AE9C 00000000 */   nop
endlabel func_8009AC84
