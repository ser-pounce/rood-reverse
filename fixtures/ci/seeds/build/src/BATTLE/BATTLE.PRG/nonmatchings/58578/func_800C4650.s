nonmatching func_800C4650, 0xB8

glabel func_800C4650
    /* 5BE50 800C4650 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 5BE54 800C4654 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 5BE58 800C4658 21988000 */  addu       $s3, $a0, $zero
    /* 5BE5C 800C465C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 5BE60 800C4660 21A0A000 */  addu       $s4, $a1, $zero
    /* 5BE64 800C4664 1800B2AF */  sw         $s2, 0x18($sp)
    /* 5BE68 800C4668 21900000 */  addu       $s2, $zero, $zero
    /* 5BE6C 800C466C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 5BE70 800C4670 2400B5AF */  sw         $s5, 0x24($sp)
    /* 5BE74 800C4674 1400B1AF */  sw         $s1, 0x14($sp)
    /* 5BE78 800C4678 1A00801A */  blez       $s4, .L800C46E4
    /* 5BE7C 800C467C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 5BE80 800C4680 0F80153C */  lui        $s5, %hi(D_800EB9B8)
    /* 5BE84 800C4684 0A009124 */  addiu      $s1, $a0, 0xA
  .L800C4688:
    /* 5BE88 800C4688 FFFF3092 */  lbu        $s0, -0x1($s1)
    /* 5BE8C 800C468C 00000000 */  nop
    /* 5BE90 800C4690 03111000 */  sra        $v0, $s0, 4
    /* 5BE94 800C4694 0E004014 */  bnez       $v0, .L800C46D0
    /* 5BE98 800C4698 21286002 */   addu      $a1, $s3, $zero
    /* 5BE9C 800C469C B8B9A48E */  lw         $a0, %lo(D_800EB9B8)($s5)
    /* 5BEA0 800C46A0 5905030C */  jal        func_800C1564
    /* 5BEA4 800C46A4 10008424 */   addiu     $a0, $a0, 0x10
    /* 5BEA8 800C46A8 06004010 */  beqz       $v0, .L800C46C4
    /* 5BEAC 800C46AC 21200002 */   addu      $a0, $s0, $zero
    /* 5BEB0 800C46B0 00002682 */  lb         $a2, 0x0($s1)
    /* 5BEB4 800C46B4 577F020C */  jal        func_8009FD5C
    /* 5BEB8 800C46B8 21280000 */   addu      $a1, $zero, $zero
    /* 5BEBC 800C46BC B5110308 */  j          .L800C46D4
    /* 5BEC0 800C46C0 01005226 */   addiu     $s2, $s2, 0x1
  .L800C46C4:
    /* 5BEC4 800C46C4 00002582 */  lb         $a1, 0x0($s1)
    /* 5BEC8 800C46C8 9D7F020C */  jal        func_8009FE74
    /* 5BECC 800C46CC 21200002 */   addu      $a0, $s0, $zero
  .L800C46D0:
    /* 5BED0 800C46D0 01005226 */  addiu      $s2, $s2, 0x1
  .L800C46D4:
    /* 5BED4 800C46D4 18003126 */  addiu      $s1, $s1, 0x18
    /* 5BED8 800C46D8 2A105402 */  slt        $v0, $s2, $s4
    /* 5BEDC 800C46DC EAFF4014 */  bnez       $v0, .L800C4688
    /* 5BEE0 800C46E0 18007326 */   addiu     $s3, $s3, 0x18
  .L800C46E4:
    /* 5BEE4 800C46E4 2800BF8F */  lw         $ra, 0x28($sp)
    /* 5BEE8 800C46E8 2400B58F */  lw         $s5, 0x24($sp)
    /* 5BEEC 800C46EC 2000B48F */  lw         $s4, 0x20($sp)
    /* 5BEF0 800C46F0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 5BEF4 800C46F4 1800B28F */  lw         $s2, 0x18($sp)
    /* 5BEF8 800C46F8 1400B18F */  lw         $s1, 0x14($sp)
    /* 5BEFC 800C46FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 5BF00 800C4700 0800E003 */  jr         $ra
    /* 5BF04 800C4704 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_800C4650
