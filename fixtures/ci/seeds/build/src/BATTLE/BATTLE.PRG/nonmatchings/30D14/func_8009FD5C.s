nonmatching func_8009FD5C, 0x118

glabel func_8009FD5C
    /* 3755C 8009FD5C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 37560 8009FD60 0F80023C */  lui        $v0, %hi(D_800F4538)
    /* 37564 8009FD64 38454224 */  addiu      $v0, $v0, %lo(D_800F4538)
    /* 37568 8009FD68 80200400 */  sll        $a0, $a0, 2
    /* 3756C 8009FD6C 21108200 */  addu       $v0, $a0, $v0
    /* 37570 8009FD70 2000BFAF */  sw         $ra, 0x20($sp)
    /* 37574 8009FD74 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 37578 8009FD78 1800B0AF */  sw         $s0, 0x18($sp)
    /* 3757C 8009FD7C 0000478C */  lw         $a3, 0x0($v0)
    /* 37580 8009FD80 00000000 */  nop
    /* 37584 8009FD84 0300E010 */  beqz       $a3, .L8009FD94
    /* 37588 8009FD88 2188C000 */   addu      $s1, $a2, $zero
    /* 3758C 8009FD8C 6E7F0208 */  j          .L8009FDB8
    /* 37590 8009FD90 6400F024 */   addiu     $s0, $a3, 0x64
  .L8009FD94:
    /* 37594 8009FD94 0F80023C */  lui        $v0, %hi(D_800F45E0)
    /* 37598 8009FD98 E0454224 */  addiu      $v0, $v0, %lo(D_800F45E0)
    /* 3759C 8009FD9C 21108200 */  addu       $v0, $a0, $v0
    /* 375A0 8009FDA0 0000488C */  lw         $t0, 0x0($v0)
    /* 375A4 8009FDA4 00000000 */  nop
    /* 375A8 8009FDA8 03000015 */  bnez       $t0, .L8009FDB8
    /* 375AC 8009FDAC 64001025 */   addiu     $s0, $t0, 0x64
    /* 375B0 8009FDB0 977F0208 */  j          .L8009FE5C
    /* 375B4 8009FDB4 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8009FDB8:
    /* 375B8 8009FDB8 00000292 */  lbu        $v0, 0x0($s0)
    /* 375BC 8009FDBC 00000000 */  nop
    /* 375C0 8009FDC0 16004014 */  bnez       $v0, .L8009FE1C
    /* 375C4 8009FDC4 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 375C8 8009FDC8 02000292 */  lbu        $v0, 0x2($s0)
    /* 375CC 8009FDCC 0100A330 */  andi       $v1, $a1, 0x1
    /* 375D0 8009FDD0 010000A2 */  sb         $zero, 0x1($s0)
    /* 375D4 8009FDD4 FC004230 */  andi       $v0, $v0, 0xFC
    /* 375D8 8009FDD8 25104300 */  or         $v0, $v0, $v1
    /* 375DC 8009FDDC 0700E010 */  beqz       $a3, .L8009FDFC
    /* 375E0 8009FDE0 020002A2 */   sb        $v0, 0x2($s0)
    /* 375E4 8009FDE4 2414E424 */  addiu      $a0, $a3, 0x1424
    /* 375E8 8009FDE8 21300000 */  addu       $a2, $zero, $zero
    /* 375EC 8009FDEC 0F00E590 */  lbu        $a1, 0xF($a3)
    /* 375F0 8009FDF0 A0000724 */  addiu      $a3, $zero, 0xA0
    /* 375F4 8009FDF4 847F0208 */  j          .L8009FE10
    /* 375F8 8009FDF8 1600A524 */   addiu     $a1, $a1, 0x16
  .L8009FDFC:
    /* 375FC 8009FDFC 2C010425 */  addiu      $a0, $t0, 0x12C
    /* 37600 8009FE00 1F000524 */  addiu      $a1, $zero, 0x1F
    /* 37604 8009FE04 0F000691 */  lbu        $a2, 0xF($t0)
    /* 37608 8009FE08 10000724 */  addiu      $a3, $zero, 0x10
    /* 3760C 8009FE0C 00310600 */  sll        $a2, $a2, 4
  .L8009FE10:
    /* 37610 8009FE10 9922010C */  jal        vs_main_loadClut
    /* 37614 8009FE14 00000000 */   nop
    /* 37618 8009FE18 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8009FE1C:
    /* 3761C 8009FE1C 04002216 */  bne        $s1, $v0, .L8009FE30
    /* 37620 8009FE20 0800222E */   sltiu     $v0, $s1, 0x8
    /* 37624 8009FE24 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 37628 8009FE28 967F0208 */  j          .L8009FE58
    /* 3762C 8009FE2C 000002A2 */   sb        $v0, 0x0($s0)
  .L8009FE30:
    /* 37630 8009FE30 03004014 */  bnez       $v0, .L8009FE40
    /* 37634 8009FE34 07000224 */   addiu     $v0, $zero, 0x7
    /* 37638 8009FE38 977F0208 */  j          .L8009FE5C
    /* 3763C 8009FE3C FEFF0224 */   addiu     $v0, $zero, -0x2
  .L8009FE40:
    /* 37640 8009FE40 23105100 */  subu       $v0, $v0, $s1
    /* 37644 8009FE44 01000324 */  addiu      $v1, $zero, 0x1
    /* 37648 8009FE48 00000492 */  lbu        $a0, 0x0($s0)
    /* 3764C 8009FE4C 04184300 */  sllv       $v1, $v1, $v0
    /* 37650 8009FE50 25208300 */  or         $a0, $a0, $v1
    /* 37654 8009FE54 000004A2 */  sb         $a0, 0x0($s0)
  .L8009FE58:
    /* 37658 8009FE58 21100000 */  addu       $v0, $zero, $zero
  .L8009FE5C:
    /* 3765C 8009FE5C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 37660 8009FE60 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 37664 8009FE64 1800B08F */  lw         $s0, 0x18($sp)
    /* 37668 8009FE68 2800BD27 */  addiu      $sp, $sp, 0x28
    /* 3766C 8009FE6C 0800E003 */  jr         $ra
    /* 37670 8009FE70 00000000 */   nop
endlabel func_8009FD5C
