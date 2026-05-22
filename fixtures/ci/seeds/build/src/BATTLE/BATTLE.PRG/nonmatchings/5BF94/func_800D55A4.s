nonmatching func_800D55A4, 0x15C

glabel func_800D55A4
    /* 6CDA4 800D55A4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6CDA8 800D55A8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6CDAC 800D55AC 21888000 */  addu       $s1, $a0, $zero
    /* 6CDB0 800D55B0 2800B6AF */  sw         $s6, 0x28($sp)
    /* 6CDB4 800D55B4 21B0A000 */  addu       $s6, $a1, $zero
    /* 6CDB8 800D55B8 0F80023C */  lui        $v0, %hi(D_800F569C)
    /* 6CDBC 800D55BC 9C56428C */  lw         $v0, %lo(D_800F569C)($v0)
    /* 6CDC0 800D55C0 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 6CDC4 800D55C4 2400B5AF */  sw         $s5, 0x24($sp)
    /* 6CDC8 800D55C8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 6CDCC 800D55CC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6CDD0 800D55D0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6CDD4 800D55D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6CDD8 800D55D8 BC00448C */  lw         $a0, 0xBC($v0)
    /* 6CDDC 800D55DC 5455030C */  jal        func_800D5550
    /* 6CDE0 800D55E0 21A80000 */   addu      $s5, $zero, $zero
    /* 6CDE4 800D55E4 4C0D248E */  lw         $a0, 0xD4C($s1)
    /* 6CDE8 800D55E8 00000000 */  nop
    /* 6CDEC 800D55EC 03008010 */  beqz       $a0, .L800D55FC
    /* 6CDF0 800D55F0 21804000 */   addu      $s0, $v0, $zero
    /* 6CDF4 800D55F4 180F010C */  jal        vs_main_freeHeapR
    /* 6CDF8 800D55F8 00000000 */   nop
  .L800D55FC:
    /* 6CDFC 800D55FC 0000048E */  lw         $a0, 0x0($s0)
    /* 6CE00 800D5600 00000000 */  nop
    /* 6CE04 800D5604 00210400 */  sll        $a0, $a0, 4
    /* 6CE08 800D5608 8F0F010C */  jal        vs_main_allocHeapR
    /* 6CE0C 800D560C 08008434 */   ori       $a0, $a0, 0x8
    /* 6CE10 800D5610 4C0D22AE */  sw         $v0, 0xD4C($s1)
    /* 6CE14 800D5614 21884000 */  addu       $s1, $v0, $zero
    /* 6CE18 800D5618 00000392 */  lbu        $v1, 0x0($s0)
    /* 6CE1C 800D561C 21900000 */  addu       $s2, $zero, $zero
    /* 6CE20 800D5620 020020A6 */  sh         $zero, 0x2($s1)
    /* 6CE24 800D5624 040020AE */  sw         $zero, 0x4($s1)
    /* 6CE28 800D5628 FF006230 */  andi       $v0, $v1, 0xFF
    /* 6CE2C 800D562C 2A10A202 */  slt        $v0, $s5, $v0
    /* 6CE30 800D5630 24004010 */  beqz       $v0, .L800D56C4
    /* 6CE34 800D5634 000023A2 */   sb        $v1, 0x0($s1)
    /* 6CE38 800D5638 08001424 */  addiu      $s4, $zero, 0x8
    /* 6CE3C 800D563C 21980002 */  addu       $s3, $s0, $zero
    /* 6CE40 800D5640 21802002 */  addu       $s0, $s1, $zero
  .L800D5644:
    /* 6CE44 800D5644 0F80023C */  lui        $v0, %hi(D_800F569C)
    /* 6CE48 800D5648 9C56428C */  lw         $v0, %lo(D_800F569C)($v0)
    /* 6CE4C 800D564C 2128C002 */  addu       $a1, $s6, $zero
    /* 6CE50 800D5650 BC00448C */  lw         $a0, 0xBC($v0)
    /* 6CE54 800D5654 5955030C */  jal        func_800D5564
    /* 6CE58 800D5658 21304002 */   addu      $a2, $s2, $zero
    /* 6CE5C 800D565C 080002AE */  sw         $v0, 0x8($s0)
    /* 6CE60 800D5660 04006296 */  lhu        $v0, 0x4($s3)
    /* 6CE64 800D5664 00000000 */  nop
    /* 6CE68 800D5668 0C0002A6 */  sh         $v0, 0xC($s0)
    /* 6CE6C 800D566C 0C000392 */  lbu        $v1, 0xC($s0)
    /* 6CE70 800D5670 03000224 */  addiu      $v0, $zero, 0x3
    /* 6CE74 800D5674 02006214 */  bne        $v1, $v0, .L800D5680
    /* 6CE78 800D5678 21203402 */   addu      $a0, $s1, $s4
    /* 6CE7C 800D567C 0100B526 */  addiu      $s5, $s5, 0x1
  .L800D5680:
    /* 6CE80 800D5680 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 6CE84 800D5684 0E0002A6 */  sh         $v0, 0xE($s0)
    /* 6CE88 800D5688 100000AE */  sw         $zero, 0x10($s0)
    /* 6CE8C 800D568C E055030C */  jal        func_800D5780
    /* 6CE90 800D5690 140000AE */   sw        $zero, 0x14($s0)
    /* 6CE94 800D5694 10009426 */  addiu      $s4, $s4, 0x10
    /* 6CE98 800D5698 04007326 */  addiu      $s3, $s3, 0x4
    /* 6CE9C 800D569C 10001026 */  addiu      $s0, $s0, 0x10
    /* 6CEA0 800D56A0 01000424 */  addiu      $a0, $zero, 0x1
    /* 6CEA4 800D56A4 04204402 */  sllv       $a0, $a0, $s2
    /* 6CEA8 800D56A8 01005226 */  addiu      $s2, $s2, 0x1
    /* 6CEAC 800D56AC 0400228E */  lw         $v0, 0x4($s1)
    /* 6CEB0 800D56B0 00002392 */  lbu        $v1, 0x0($s1)
    /* 6CEB4 800D56B4 25104400 */  or         $v0, $v0, $a0
    /* 6CEB8 800D56B8 2A184302 */  slt        $v1, $s2, $v1
    /* 6CEBC 800D56BC E1FF6014 */  bnez       $v1, .L800D5644
    /* 6CEC0 800D56C0 040022AE */   sw        $v0, 0x4($s1)
  .L800D56C4:
    /* 6CEC4 800D56C4 0300A012 */  beqz       $s5, .L800D56D4
    /* 6CEC8 800D56C8 02000224 */   addiu     $v0, $zero, 0x2
    /* 6CECC 800D56CC B6550308 */  j          .L800D56D8
    /* 6CED0 800D56D0 010022A2 */   sb        $v0, 0x1($s1)
  .L800D56D4:
    /* 6CED4 800D56D4 010020A2 */  sb         $zero, 0x1($s1)
  .L800D56D8:
    /* 6CED8 800D56D8 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 6CEDC 800D56DC 2800B68F */  lw         $s6, 0x28($sp)
    /* 6CEE0 800D56E0 2400B58F */  lw         $s5, 0x24($sp)
    /* 6CEE4 800D56E4 2000B48F */  lw         $s4, 0x20($sp)
    /* 6CEE8 800D56E8 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6CEEC 800D56EC 1800B28F */  lw         $s2, 0x18($sp)
    /* 6CEF0 800D56F0 1400B18F */  lw         $s1, 0x14($sp)
    /* 6CEF4 800D56F4 1000B08F */  lw         $s0, 0x10($sp)
    /* 6CEF8 800D56F8 0800E003 */  jr         $ra
    /* 6CEFC 800D56FC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800D55A4
