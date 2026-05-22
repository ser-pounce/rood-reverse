nonmatching func_8008EC48, 0x384

glabel func_8008EC48
    /* 26448 8008EC48 A8FFBD27 */  addiu      $sp, $sp, -0x58
    /* 2644C 8008EC4C 0F80023C */  lui        $v0, %hi(D_800F1DC9)
    /* 26450 8008EC50 C91D4290 */  lbu        $v0, %lo(D_800F1DC9)($v0)
    /* 26454 8008EC54 21288000 */  addu       $a1, $a0, $zero
    /* 26458 8008EC58 5000BFAF */  sw         $ra, 0x50($sp)
    /* 2645C 8008EC5C 4C00B3AF */  sw         $s3, 0x4C($sp)
    /* 26460 8008EC60 4800B2AF */  sw         $s2, 0x48($sp)
    /* 26464 8008EC64 4400B1AF */  sw         $s1, 0x44($sp)
    /* 26468 8008EC68 2F004010 */  beqz       $v0, .L8008ED28
    /* 2646C 8008EC6C 4000B0AF */   sw        $s0, 0x40($sp)
    /* 26470 8008EC70 0F80023C */  lui        $v0, %hi(D_800F1DCC)
    /* 26474 8008EC74 CC1D448C */  lw         $a0, %lo(D_800F1DCC)($v0)
    /* 26478 8008EC78 00000000 */  nop
    /* 2647C 8008EC7C 2B008010 */  beqz       $a0, .L8008ED2C
    /* 26480 8008EC80 0F80023C */   lui       $v0, %hi(D_800F1DC6)
    /* 26484 8008EC84 0000828C */  lw         $v0, 0x0($a0)
    /* 26488 8008EC88 00000000 */  nop
    /* 2648C 8008EC8C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 26490 8008EC90 1F00422C */  sltiu      $v0, $v0, 0x1F
    /* 26494 8008EC94 C6004010 */  beqz       $v0, .L8008EFB0
    /* 26498 8008EC98 00000000 */   nop
    /* 2649C 8008EC9C 0400828C */  lw         $v0, 0x4($a0)
    /* 264A0 8008ECA0 00000000 */  nop
    /* 264A4 8008ECA4 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 264A8 8008ECA8 1F00422C */  sltiu      $v0, $v0, 0x1F
    /* 264AC 8008ECAC C0004010 */  beqz       $v0, .L8008EFB0
    /* 264B0 8008ECB0 801F063C */   lui       $a2, (0x1F800054 >> 16)
    /* 264B4 8008ECB4 0F80023C */  lui        $v0, %hi(D_800F1DB8)
    /* 264B8 8008ECB8 B81D4384 */  lh         $v1, %lo(D_800F1DB8)($v0)
    /* 264BC 8008ECBC 5800C28C */  lw         $v0, (0x1F800058 & 0xFFFF)($a2)
    /* 264C0 8008ECC0 00000000 */  nop
    /* 264C4 8008ECC4 18004300 */  mult       $v0, $v1
    /* 264C8 8008ECC8 12280000 */  mflo       $a1
    /* 264CC 8008ECCC 0200A104 */  bgez       $a1, .L8008ECD8
    /* 264D0 8008ECD0 0F80023C */   lui       $v0, %hi(D_800F1DBA)
    /* 264D4 8008ECD4 FF0FA524 */  addiu      $a1, $a1, 0xFFF
  .L8008ECD8:
    /* 264D8 8008ECD8 BA1D4384 */  lh         $v1, %lo(D_800F1DBA)($v0)
    /* 264DC 8008ECDC 5400C28C */  lw         $v0, (0x1F800054 & 0xFFFF)($a2)
    /* 264E0 8008ECE0 00000000 */  nop
    /* 264E4 8008ECE4 18004300 */  mult       $v0, $v1
    /* 264E8 8008ECE8 0F80023C */  lui        $v0, %hi(D_800F1DB4)
    /* 264EC 8008ECEC B41D4384 */  lh         $v1, %lo(D_800F1DB4)($v0)
    /* 264F0 8008ECF0 03130500 */  sra        $v0, $a1, 12
    /* 264F4 8008ECF4 12300000 */  mflo       $a2
    /* 264F8 8008ECF8 0200C104 */  bgez       $a2, .L8008ED04
    /* 264FC 8008ECFC 23284300 */   subu      $a1, $v0, $v1
    /* 26500 8008ED00 FF0FC624 */  addiu      $a2, $a2, 0xFFF
  .L8008ED04:
    /* 26504 8008ED04 03330600 */  sra        $a2, $a2, 12
    /* 26508 8008ED08 0F80023C */  lui        $v0, %hi(D_800F1DB6)
    /* 2650C 8008ED0C 0F80033C */  lui        $v1, %hi(D_800F1DC8)
    /* 26510 8008ED10 B61D4284 */  lh         $v0, %lo(D_800F1DB6)($v0)
    /* 26514 8008ED14 C81D6790 */  lbu        $a3, %lo(D_800F1DC8)($v1)
    /* 26518 8008ED18 1F45020C */  jal        func_8009147C
    /* 2651C 8008ED1C 23304600 */   subu      $a2, $v0, $a2
    /* 26520 8008ED20 EC3B0208 */  j          .L8008EFB0
    /* 26524 8008ED24 00000000 */   nop
  .L8008ED28:
    /* 26528 8008ED28 0F80023C */  lui        $v0, %hi(D_800F1DC6)
  .L8008ED2C:
    /* 2652C 8008ED2C C61D4290 */  lbu        $v0, %lo(D_800F1DC6)($v0)
    /* 26530 8008ED30 00000000 */  nop
    /* 26534 8008ED34 4A004010 */  beqz       $v0, .L8008EE60
    /* 26538 8008ED38 09000224 */   addiu     $v0, $zero, 0x9
    /* 2653C 8008ED3C 40010324 */  addiu      $v1, $zero, 0x140
    /* 26540 8008ED40 801F123C */  lui        $s2, (0x1F800000 >> 16)
    /* 26544 8008ED44 0000528E */  lw         $s2, (0x1F800000 & 0xFFFF)($s2)
    /* 26548 8008ED48 0F80043C */  lui        $a0, %hi(D_800F1BB0)
    /* 2654C 8008ED4C 030042A2 */  sb         $v0, 0x3($s2)
    /* 26550 8008ED50 2C000224 */  addiu      $v0, $zero, 0x2C
    /* 26554 8008ED54 070042A2 */  sb         $v0, 0x7($s2)
    /* 26558 8008ED58 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 2655C 8008ED5C 1A0042A6 */  sh         $v0, 0x1A($s2)
    /* 26560 8008ED60 220042A6 */  sh         $v0, 0x22($s2)
    /* 26564 8008ED64 F8000224 */  addiu      $v0, $zero, 0xF8
    /* 26568 8008ED68 100043A6 */  sh         $v1, 0x10($s2)
    /* 2656C 8008ED6C 200043A6 */  sh         $v1, 0x20($s2)
    /* 26570 8008ED70 F9000324 */  addiu      $v1, $zero, 0xF9
    /* 26574 8008ED74 140043A2 */  sb         $v1, 0x14($s2)
    /* 26578 8008ED78 1D0043A2 */  sb         $v1, 0x1D($s2)
    /* 2657C 8008ED7C 240043A2 */  sb         $v1, 0x24($s2)
    /* 26580 8008ED80 250043A2 */  sb         $v1, 0x25($s2)
    /* 26584 8008ED84 B01B8324 */  addiu      $v1, $a0, %lo(D_800F1BB0)
    /* 26588 8008ED88 080040A6 */  sh         $zero, 0x8($s2)
    /* 2658C 8008ED8C 0A0040A6 */  sh         $zero, 0xA($s2)
    /* 26590 8008ED90 120040A6 */  sh         $zero, 0x12($s2)
    /* 26594 8008ED94 180040A6 */  sh         $zero, 0x18($s2)
    /* 26598 8008ED98 0C0042A2 */  sb         $v0, 0xC($s2)
    /* 2659C 8008ED9C 0D0042A2 */  sb         $v0, 0xD($s2)
    /* 265A0 8008EDA0 150042A2 */  sb         $v0, 0x15($s2)
    /* 265A4 8008EDA4 1C0042A2 */  sb         $v0, 0x1C($s2)
    /* 265A8 8008EDA8 06006284 */  lh         $v0, 0x6($v1)
    /* 265AC 8008EDAC 00000000 */  nop
    /* 265B0 8008EDB0 1B004010 */  beqz       $v0, .L8008EE20
    /* 265B4 8008EDB4 21280000 */   addu      $a1, $zero, $zero
    /* 265B8 8008EDB8 FF000624 */  addiu      $a2, $zero, 0xFF
    /* 265BC 8008EDBC 01006280 */  lb         $v0, 0x1($v1)
    /* 265C0 8008EDC0 B01B8480 */  lb         $a0, %lo(D_800F1BB0)($a0)
    /* 265C4 8008EDC4 02007080 */  lb         $s0, 0x2($v1)
    /* 265C8 8008EDC8 80100200 */  sll        $v0, $v0, 2
    /* 265CC 8008EDCC 80005324 */  addiu      $s3, $v0, 0x80
    /* 265D0 8008EDD0 80200400 */  sll        $a0, $a0, 2
    /* 265D4 8008EDD4 80008424 */  addiu      $a0, $a0, 0x80
    /* 265D8 8008EDD8 80801000 */  sll        $s0, $s0, 2
    /* 265DC 8008EDDC 6E44020C */  jal        vs_battle_clamp
    /* 265E0 8008EDE0 80001026 */   addiu     $s0, $s0, 0x80
    /* 265E4 8008EDE4 21206002 */  addu       $a0, $s3, $zero
    /* 265E8 8008EDE8 21280000 */  addu       $a1, $zero, $zero
    /* 265EC 8008EDEC FF000624 */  addiu      $a2, $zero, 0xFF
    /* 265F0 8008EDF0 008C0200 */  sll        $s1, $v0, 16
    /* 265F4 8008EDF4 6E44020C */  jal        vs_battle_clamp
    /* 265F8 8008EDF8 038C1100 */   sra       $s1, $s1, 16
    /* 265FC 8008EDFC 00140200 */  sll        $v0, $v0, 16
    /* 26600 8008EE00 039C0200 */  sra        $s3, $v0, 16
    /* 26604 8008EE04 21200002 */  addu       $a0, $s0, $zero
    /* 26608 8008EE08 21280000 */  addu       $a1, $zero, $zero
    /* 2660C 8008EE0C 6E44020C */  jal        vs_battle_clamp
    /* 26610 8008EE10 FF000624 */   addiu     $a2, $zero, 0xFF
    /* 26614 8008EE14 040051A2 */  sb         $s1, 0x4($s2)
    /* 26618 8008EE18 8B3B0208 */  j          .L8008EE2C
    /* 2661C 8008EE1C 050053A2 */   sb        $s3, 0x5($s2)
  .L8008EE20:
    /* 26620 8008EE20 80000224 */  addiu      $v0, $zero, 0x80
    /* 26624 8008EE24 040042A2 */  sb         $v0, 0x4($s2)
    /* 26628 8008EE28 050042A2 */  sb         $v0, 0x5($s2)
  .L8008EE2C:
    /* 2662C 8008EE2C 060042A2 */  sb         $v0, 0x6($s2)
    /* 26630 8008EE30 11000224 */  addiu      $v0, $zero, 0x11
    /* 26634 8008EE34 160042A6 */  sh         $v0, 0x16($s2)
    /* 26638 8008EE38 B1380224 */  addiu      $v0, $zero, 0x38B1
    /* 2663C 8008EE3C 21284002 */  addu       $a1, $s2, $zero
    /* 26640 8008EE40 801F103C */  lui        $s0, (0x1F800000 >> 16)
    /* 26644 8008EE44 0E0042A6 */  sh         $v0, 0xE($s2)
    /* 26648 8008EE48 0400048E */  lw         $a0, (0x1F800004 & 0xFFFF)($s0)
    /* 2664C 8008EE4C 28005226 */  addiu      $s2, $s2, 0x28
    /* 26650 8008EE50 35AD000C */  jal        AddPrim
    /* 26654 8008EE54 FC1F8424 */   addiu     $a0, $a0, 0x1FFC
    /* 26658 8008EE58 EC3B0208 */  j          .L8008EFB0
    /* 2665C 8008EE5C 000012AE */   sw        $s2, (0x1F800000 & 0xFFFF)($s0)
  .L8008EE60:
    /* 26660 8008EE60 2180A000 */  addu       $s0, $a1, $zero
    /* 26664 8008EE64 09000016 */  bnez       $s0, .L8008EE8C
    /* 26668 8008EE68 801F113C */   lui       $s1, (0x1F800064 >> 16)
    /* 2666C 8008EE6C 0F80023C */  lui        $v0, %hi(vs_battle_roomData + 0x8C)
    /* 26670 8008EE70 841C428C */  lw         $v0, %lo(vs_battle_roomData + 0x8C)($v0)
    /* 26674 8008EE74 00000000 */  nop
    /* 26678 8008EE78 04004014 */  bnez       $v0, .L8008EE8C
    /* 2667C 8008EE7C 14005024 */   addiu     $s0, $v0, 0x14
    /* 26680 8008EE80 0F80023C */  lui        $v0, %hi(D_800F1CE0)
    /* 26684 8008EE84 E01C5024 */  addiu      $s0, $v0, %lo(D_800F1CE0)
    /* 26688 8008EE88 801F113C */  lui        $s1, (0x1F800064 >> 16)
  .L8008EE8C:
    /* 2668C 8008EE8C 3400248E */  lw         $a0, (0x1F800034 & 0xFFFF)($s1)
    /* 26690 8008EE90 00000000 */  nop
    /* 26694 8008EE94 02008104 */  bgez       $a0, .L8008EEA0
    /* 26698 8008EE98 00000000 */   nop
    /* 2669C 8008EE9C FF0F8424 */  addiu      $a0, $a0, 0xFFF
  .L8008EEA0:
    /* 266A0 8008EEA0 3800228E */  lw         $v0, (0x1F800038 & 0xFFFF)($s1)
    /* 266A4 8008EEA4 03230400 */  sra        $a0, $a0, 12
    /* 266A8 8008EEA8 02004104 */  bgez       $v0, .L8008EEB4
    /* 266AC 8008EEAC 1000A4AF */   sw        $a0, 0x10($sp)
    /* 266B0 8008EEB0 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8008EEB4:
    /* 266B4 8008EEB4 3C00238E */  lw         $v1, (0x1F80003C & 0xFFFF)($s1)
    /* 266B8 8008EEB8 032B0200 */  sra        $a1, $v0, 12
    /* 266BC 8008EEBC 02006104 */  bgez       $v1, .L8008EEC8
    /* 266C0 8008EEC0 1400A5AF */   sw        $a1, 0x14($sp)
    /* 266C4 8008EEC4 FF0F6324 */  addiu      $v1, $v1, 0xFFF
  .L8008EEC8:
    /* 266C8 8008EEC8 6400228E */  lw         $v0, (0x1F800064 & 0xFFFF)($s1)
    /* 266CC 8008EECC 00000000 */  nop
    /* 266D0 8008EED0 18008200 */  mult       $a0, $v0
    /* 266D4 8008EED4 12200000 */  mflo       $a0
    /* 266D8 8008EED8 00000000 */  nop
    /* 266DC 8008EEDC 00000000 */  nop
    /* 266E0 8008EEE0 1800A200 */  mult       $a1, $v0
    /* 266E4 8008EEE4 12280000 */  mflo       $a1
    /* 266E8 8008EEE8 031B0300 */  sra        $v1, $v1, 12
    /* 266EC 8008EEEC 00000000 */  nop
    /* 266F0 8008EEF0 18006200 */  mult       $v1, $v0
    /* 266F4 8008EEF4 1800A3AF */  sw         $v1, 0x18($sp)
    /* 266F8 8008EEF8 1000A4AF */  sw         $a0, 0x10($sp)
    /* 266FC 8008EEFC 1400A5AF */  sw         $a1, 0x14($sp)
    /* 26700 8008EF00 12300000 */  mflo       $a2
    /* 26704 8008EF04 02008104 */  bgez       $a0, .L8008EF10
    /* 26708 8008EF08 1800A6AF */   sw        $a2, 0x18($sp)
    /* 2670C 8008EF0C FF0F8424 */  addiu      $a0, $a0, 0xFFF
  .L8008EF10:
    /* 26710 8008EF10 03130400 */  sra        $v0, $a0, 12
    /* 26714 8008EF14 1000A2AF */  sw         $v0, 0x10($sp)
    /* 26718 8008EF18 2110A000 */  addu       $v0, $a1, $zero
    /* 2671C 8008EF1C 02004104 */  bgez       $v0, .L8008EF28
    /* 26720 8008EF20 00000000 */   nop
    /* 26724 8008EF24 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8008EF28:
    /* 26728 8008EF28 03130200 */  sra        $v0, $v0, 12
    /* 2672C 8008EF2C 1400A2AF */  sw         $v0, 0x14($sp)
    /* 26730 8008EF30 2110C000 */  addu       $v0, $a2, $zero
    /* 26734 8008EF34 02004104 */  bgez       $v0, .L8008EF40
    /* 26738 8008EF38 00000000 */   nop
    /* 2673C 8008EF3C FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8008EF40:
    /* 26740 8008EF40 801F043C */  lui        $a0, (0x1F800014 >> 16)
    /* 26744 8008EF44 14008434 */  ori        $a0, $a0, (0x1F800014 & 0xFFFF)
    /* 26748 8008EF48 03130200 */  sra        $v0, $v0, 12
    /* 2674C 8008EF4C 6605010C */  jal        SetRotMatrix
    /* 26750 8008EF50 1800A2AF */   sw        $v0, 0x18($sp)
    /* 26754 8008EF54 801F043C */  lui        $a0, (0x1F800014 >> 16)
    /* 26758 8008EF58 5E05010C */  jal        SetTransMatrix
    /* 2675C 8008EF5C 14008434 */   ori       $a0, $a0, (0x1F800014 & 0xFFFF)
    /* 26760 8008EF60 6400238E */  lw         $v1, (0x1F800064 & 0xFFFF)($s1)
    /* 26764 8008EF64 00100224 */  addiu      $v0, $zero, 0x1000
    /* 26768 8008EF68 06006210 */  beq        $v1, $v0, .L8008EF84
    /* 2676C 8008EF6C 21280002 */   addu      $a1, $s0, $zero
    /* 26770 8008EF70 1000A427 */  addiu      $a0, $sp, 0x10
    /* 26774 8008EF74 9261020C */  jal        func_80098648
    /* 26778 8008EF78 2000A627 */   addiu     $a2, $sp, 0x20
    /* 2677C 8008EF7C E53B0208 */  j          .L8008EF94
    /* 26780 8008EF80 2000B027 */   addiu     $s0, $sp, 0x20
  .L8008EF84:
    /* 26784 8008EF84 1000A427 */  addiu      $a0, $sp, 0x10
    /* 26788 8008EF88 6B61020C */  jal        func_800985AC
    /* 2678C 8008EF8C 2000A627 */   addiu     $a2, $sp, 0x20
    /* 26790 8008EF90 2000B027 */  addiu      $s0, $sp, 0x20
  .L8008EF94:
    /* 26794 8008EF94 6605010C */  jal        SetRotMatrix
    /* 26798 8008EF98 21200002 */   addu      $a0, $s0, $zero
    /* 2679C 8008EF9C 5E05010C */  jal        SetTransMatrix
    /* 267A0 8008EFA0 21200002 */   addu      $a0, $s0, $zero
    /* 267A4 8008EFA4 0780043C */  lui        $a0, %hi(D_80068C1C)
    /* 267A8 8008EFA8 8360020C */  jal        func_8009820C
    /* 267AC 8008EFAC 1C8C8424 */   addiu     $a0, $a0, %lo(D_80068C1C)
  .L8008EFB0:
    /* 267B0 8008EFB0 5000BF8F */  lw         $ra, 0x50($sp)
    /* 267B4 8008EFB4 4C00B38F */  lw         $s3, 0x4C($sp)
    /* 267B8 8008EFB8 4800B28F */  lw         $s2, 0x48($sp)
    /* 267BC 8008EFBC 4400B18F */  lw         $s1, 0x44($sp)
    /* 267C0 8008EFC0 4000B08F */  lw         $s0, 0x40($sp)
    /* 267C4 8008EFC4 0800E003 */  jr         $ra
    /* 267C8 8008EFC8 5800BD27 */   addiu     $sp, $sp, 0x58
endlabel func_8008EC48
