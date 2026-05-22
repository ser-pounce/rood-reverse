nonmatching func_800B75F4, 0xB4

glabel func_800B75F4
    /* 4EDF4 800B75F4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4EDF8 800B75F8 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4EDFC 800B75FC 21808000 */  addu       $s0, $a0, $zero
    /* 4EE00 800B7600 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 4EE04 800B7604 80FF020C */  jal        vs_battle_getShort
    /* 4EE08 800B7608 01000426 */   addiu     $a0, $s0, 0x1
    /* 4EE0C 800B760C 94FF020C */  jal        func_800BFE50
    /* 4EE10 800B7610 FFFF4430 */   andi      $a0, $v0, 0xFFFF
    /* 4EE14 800B7614 03000392 */  lbu        $v1, 0x3($s0)
    /* 4EE18 800B7618 1200A0A7 */  sh         $zero, 0x12($sp)
    /* 4EE1C 800B761C C0190300 */  sll        $v1, $v1, 7
    /* 4EE20 800B7620 40006324 */  addiu      $v1, $v1, 0x40
    /* 4EE24 800B7624 1000A3A7 */  sh         $v1, 0x10($sp)
    /* 4EE28 800B7628 05000392 */  lbu        $v1, 0x5($s0)
    /* 4EE2C 800B762C 21804000 */  addu       $s0, $v0, $zero
    /* 4EE30 800B7630 0F80023C */  lui        $v0, %hi(D_800F4C2C)
    /* 4EE34 800B7634 C0190300 */  sll        $v1, $v1, 7
    /* 4EE38 800B7638 40006324 */  addiu      $v1, $v1, 0x40
    /* 4EE3C 800B763C 1400A3A7 */  sh         $v1, 0x14($sp)
    /* 4EE40 800B7640 2C4C4390 */  lbu        $v1, %lo(D_800F4C2C)($v0)
    /* 4EE44 800B7644 02000224 */  addiu      $v0, $zero, 0x2
    /* 4EE48 800B7648 08006214 */  bne        $v1, $v0, .L800B766C
    /* 4EE4C 800B764C FFFF0432 */   andi      $a0, $s0, 0xFFFF
    /* 4EE50 800B7650 00800224 */  addiu      $v0, $zero, -0x8000
    /* 4EE54 800B7654 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 4EE58 800B7658 1000A527 */  addiu      $a1, $sp, 0x10
    /* 4EE5C 800B765C 64A7020C */  jal        func_800A9D90
    /* 4EE60 800B7660 21300000 */   addu      $a2, $zero, $zero
    /* 4EE64 800B7664 9EDD0208 */  j          .L800B7678
    /* 4EE68 800B7668 FFFF1032 */   andi      $s0, $s0, 0xFFFF
  .L800B766C:
    /* 4EE6C 800B766C FEF3010C */  jal        func_8007CFF8
    /* 4EE70 800B7670 1000A527 */   addiu     $a1, $sp, 0x10
    /* 4EE74 800B7674 FFFF1032 */  andi       $s0, $s0, 0xFFFF
  .L800B7678:
    /* 4EE78 800B7678 2377020C */  jal        func_8009DC8C
    /* 4EE7C 800B767C 21200002 */   addu      $a0, $s0, $zero
    /* 4EE80 800B7680 0F80023C */  lui        $v0, %hi(D_800F4B70)
    /* 4EE84 800B7684 704B4224 */  addiu      $v0, $v0, %lo(D_800F4B70)
    /* 4EE88 800B7688 21800202 */  addu       $s0, $s0, $v0
    /* 4EE8C 800B768C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4EE90 800B7690 000002A2 */  sb         $v0, 0x0($s0)
    /* 4EE94 800B7694 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 4EE98 800B7698 1800B08F */  lw         $s0, 0x18($sp)
    /* 4EE9C 800B769C 21100000 */  addu       $v0, $zero, $zero
    /* 4EEA0 800B76A0 0800E003 */  jr         $ra
    /* 4EEA4 800B76A4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800B75F4
