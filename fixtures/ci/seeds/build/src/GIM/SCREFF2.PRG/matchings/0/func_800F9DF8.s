nonmatching func_800F9DF8, 0xC4

glabel func_800F9DF8
    /* 5F8 800F9DF8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 5FC 800F9DFC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 600 800F9E00 2190A000 */  addu       $s2, $a1, $zero
    /* 604 800F9E04 08008224 */  addiu      $v0, $a0, 0x8
    /* 608 800F9E08 0F004230 */  andi       $v0, $v0, 0xF
    /* 60C 800F9E0C 08000324 */  addiu      $v1, $zero, 0x8
    /* 610 800F9E10 1400B1AF */  sw         $s1, 0x14($sp)
    /* 614 800F9E14 23886200 */  subu       $s1, $v1, $v0
    /* 618 800F9E18 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 61C 800F9E1C 02002106 */  bgez       $s1, .L800F9E28
    /* 620 800F9E20 1000B0AF */   sw        $s0, 0x10($sp)
    /* 624 800F9E24 23881100 */  negu       $s1, $s1
  .L800F9E28:
    /* 628 800F9E28 80810400 */  sll        $s0, $a0, 6
    /* 62C 800F9E2C C903010C */  jal        rcos
    /* 630 800F9E30 21200002 */   addu      $a0, $s0, $zero
    /* 634 800F9E34 21200002 */  addu       $a0, $s0, $zero
    /* 638 800F9E38 CA03010C */  jal        rsin
    /* 63C 800F9E3C 21804000 */   addu      $s0, $v0, $zero
    /* 640 800F9E40 18001202 */  mult       $s0, $s2
    /* 644 800F9E44 12800000 */  mflo       $s0
    /* 648 800F9E48 00000000 */  nop
    /* 64C 800F9E4C 00000000 */  nop
    /* 650 800F9E50 18005200 */  mult       $v0, $s2
    /* 654 800F9E54 40003126 */  addiu      $s1, $s1, 0x40
    /* 658 800F9E58 40101000 */  sll        $v0, $s0, 1
    /* 65C 800F9E5C 21105000 */  addu       $v0, $v0, $s0
    /* 660 800F9E60 80100200 */  sll        $v0, $v0, 2
    /* 664 800F9E64 12180000 */  mflo       $v1
    /* 668 800F9E68 23105000 */  subu       $v0, $v0, $s0
    /* 66C 800F9E6C C3130200 */  sra        $v0, $v0, 15
    /* 670 800F9E70 18005100 */  mult       $v0, $s1
    /* 674 800F9E74 12380000 */  mflo       $a3
    /* 678 800F9E78 03130300 */  sra        $v0, $v1, 12
    /* 67C 800F9E7C 00000000 */  nop
    /* 680 800F9E80 18005100 */  mult       $v0, $s1
    /* 684 800F9E84 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 688 800F9E88 1800B28F */  lw         $s2, 0x18($sp)
    /* 68C 800F9E8C 1000B08F */  lw         $s0, 0x10($sp)
    /* 690 800F9E90 83190700 */  sra        $v1, $a3, 6
    /* 694 800F9E94 A0006324 */  addiu      $v1, $v1, 0xA0
    /* 698 800F9E98 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 69C 800F9E9C 1400B18F */  lw         $s1, 0x14($sp)
    /* 6A0 800F9EA0 12100000 */  mflo       $v0
    /* 6A4 800F9EA4 83110200 */  sra        $v0, $v0, 6
    /* 6A8 800F9EA8 70004224 */  addiu      $v0, $v0, 0x70
    /* 6AC 800F9EAC 00140200 */  sll        $v0, $v0, 16
    /* 6B0 800F9EB0 25106200 */  or         $v0, $v1, $v0
    /* 6B4 800F9EB4 0800E003 */  jr         $ra
    /* 6B8 800F9EB8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800F9DF8
